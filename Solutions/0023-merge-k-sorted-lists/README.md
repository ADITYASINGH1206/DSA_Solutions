# [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
**Difficulty:** `Hard` | **Tags:** `linked-list`, `divide-and-conquer`, `heap-priority-queue`, `merge-sort`, `tournament-sort`

---

## Problem Description
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*

**Example 1:**

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
```

**Example 2:**

```
Input: lists = []
Output: []
```

**Example 3:**

```
Input: lists = [[]]
Output: []
```

**Constraints:**

* `k == lists.length`
* `0 <= k <= 104`
* `0 <= lists[i].length <= 500`
* `-104 <= lists[i][j] <= 104`
* `lists[i]` is sorted in **ascending order**.
* The sum of `lists[i].length` will not exceed `104`.

---

## Solution & Editorial
# Intuition
By treating the merge process as a global collection of all node values followed by sorting, we can simplify the problem of merging $k$ sorted lists into standard sorting over a single dynamic array.

# Approach
1. Iterate through each linked list in the input vector `lists`. Traverse each individual list and push all node values (`list->val`) into a flat `vector<int> nums`.
2. Sort the `nums` vector in ascending order using `std::sort`.
3. Create a dummy sentinel node `ans` and a pointer `temp` to build the new merged linked list. Iterate through the sorted `nums` array, construct a new `ListNode` for each value, and attach it to `temp`.
4. Return `ans->next` as the head of the newly constructed sorted linked list.

### Visual Walkthrough (Example 1)
Input: `lists = [[1,4,5], [1,3,4], [2,6]]`

- **Traversal Phase:**
  - List 0 (`1 -> 4 -> 5`): `nums` becomes `[1, 4, 5]`
  - List 1 (`1 -> 3 -> 4`): `nums` becomes `[1, 4, 5, 1, 3, 4]`
  - List 2 (`2 -> 6`): `nums` becomes `[1, 4, 5, 1, 3, 4, 2, 6]`

- **Sorting Phase:**
  - `std::sort(nums.begin(), nums.end())` -> `nums = [1, 1, 2, 3, 4, 4, 5, 6]`

- **Reconstruction Phase:**
  - Construct nodes sequentially: `ans -> 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6`

# Complexity
- Time complexity: $$O(N \log N)$$ where $$N$$ is the total number of nodes across all linked lists. Traversing all lists takes $$O(N)$$ time, sorting the vector of size $$N$$ takes $$O(N \log N)$$ time, and reconstructing the linked list takes $$O(N)$$ time. The sorting step dominates.
- Space complexity: $$O(N)$$ to store all node values in the auxiliary `nums` vector and to allocate the new `ListNode` objects for the resulting linked list.

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> nums;
        for(auto list:lists){
            while(list){
                nums.push_back(list->val);
                list = list->next;
            }
        }
        sort(nums.begin(),nums.end());
        int n= nums.size();
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        for(int i = 0;i<n;i++){
            ListNode* node = new ListNode(nums[i]);
            temp->next = node;
            temp = temp->next;
        }

        return ans->next;
    }
};
```

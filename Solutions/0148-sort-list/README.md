# [148. Sort List](https://leetcode.com/problems/sort-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `two-pointers`, `divide-and-conquer`, `sorting`, `merge-sort`

---

## Problem Description
Given the `head` of a linked list, return *the list after sorting it in **ascending order***.

**Example 1:**

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Example 2:**

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

**Example 3:**

```
Input: head = []
Output: []
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 5 * 104]`.
* `-105 <= Node.val <= 105`

**Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

---

## Solution & Editorial
# Intuition
A linked list cannot be efficiently sorted in-place using comparison-based sorting algorithms like quicksort or heapsort due to lack of random access. However, we can extract the values from the linked list into a standard vector, sort the vector using introspective sort, and then reconstruct a new sorted linked list.

# Approach
1. Initialize a pointer `temp` to `head` and traverse the linked list. For each node encountered, push its `val` into a dynamic array `nums`.
2. Sort the `nums` vector in ascending order using C++'s standard `sort` function.
3. Create a dummy node `ans` to serve as the anchor for the newly constructed sorted linked list, and set `temp` to `ans`.
4. Iterate through each element in the sorted `nums` vector, create a new `ListNode` with the value, attach it to `temp->next`, and advance `temp`.
5. Return `ans->next`, which points to the head of the newly built sorted linked list.

### Visual Walkthrough (Example 1)
Input: `head = [4, 2, 1, 3]`

| Step | Action | `nums` State | `temp` / Linked List State |
| :--- | :--- | :--- | :--- |
| 1 | Traverse & Extract | `[4, 2, 1, 3]` | Nodes traversed: 4 -> 2 -> 1 -> 3 |
| 2 | Sort Vector | `[1, 2, 3, 4]` | Vector sorted via `std::sort` |
| 3 | Reconstruct List | `[1, 2, 3, 4]` | Dummy -> 1 -> 2 -> 3 -> 4 |
| 4 | Return Head | `[1, 2, 3, 4]` | Returns `ans->next` pointing to 1 |

# Complexity
- Time complexity: $$O(N \log N)$$ — Traversing the linked list takes $$O(N)$$ time, sorting the vector of size $$N$$ takes $$O(N \log N)$$ time, and reconstructing the linked list takes $$O(N)$$ time, giving a dominant $$O(N \log N)$$ runtime.
- Space complexity: $$O(N)$$ — The auxiliary vector `nums` stores $$N$$ integer values, and we allocate $$N$$ new nodes for the output linked list, requiring $$O(N)$$ auxiliary space.

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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        sort(nums.begin(),nums.end());
        ListNode* ans = new ListNode(0);
        temp = ans;
        for(int num:nums){
            ListNode* node = new ListNode(num);
            temp->next = node;
            temp = temp->next;
        }

        return ans->next;
    }
};
```

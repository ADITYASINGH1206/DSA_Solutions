# [3217. Delete Nodes From Linked List Present in Array](https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `linked-list`

---

## Problem Description
You are given an array of integers `nums` and the `head` of a linked list. Return the `head` of the modified linked list after **removing** all nodes from the linked list that have a value that exists in `nums`.

**Example 1:**

**Input:** nums = [1,2,3], head = [1,2,3,4,5]

**Output:** [4,5]

**Explanation:**

Remove the nodes with values 1, 2, and 3.

**Example 2:**

**Input:** nums = [1], head = [1,2,1,2,1,2]

**Output:** [2,2,2]

**Explanation:**

Remove the nodes with value 1.

**Example 3:**

**Input:** nums = [5], head = [1,2,3,4]

**Output:** [1,2,3,4]

**Explanation:**

No node has value 5.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`
* All elements in `nums` are unique.
* The number of nodes in the given list is in the range `[1, 105]`.
* `1 <= Node.val <= 105`
* The input is generated such that there is at least one node in the linked list that has a value not present in `nums`.

---

## Solution & Editorial
# Intuition
To efficiently remove nodes from the linked list based on values present in an array, we need a way to perform constant-time lookups. An `unordered_set` is the ideal data structure to store the values from `nums`, allowing us to check if a node's value should be deleted in $O(1)$ average time.

# Approach
1. **Preprocessing**: Insert all elements from `nums` into an `unordered_set<int> st` to enable $O(1)$ lookup complexity.
2. **Filtering**: Traverse the original linked list using a pointer `temp`. For every node, check if its value exists in `st`. If it does not, store the value in a temporary `vector<int> num`.
3. **Reconstruction**: Create a dummy node `ans` to serve as the head of the new list. Iterate through the `num` vector, creating new `ListNode` objects for each value and linking them sequentially.
4. **Return**: Return `ans->next`, which points to the start of the newly constructed list.

### Visual Trace (Example 1: nums=[1,2,3], head=[1,2,3,4,5])
| Step | Current Node Val | In Set? | Action | `num` Vector |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | Yes | Skip | [] |
| 2 | 2 | Yes | Skip | [] |
| 3 | 3 | Yes | Skip | [] |
| 4 | 4 | No | Keep | [4] |
| 5 | 5 | No | Keep | [4, 5] |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the number of nodes in the linked list and $$M$$ is the number of elements in `nums`. We iterate through the list once and the array once to build the set.
- Space complexity: $$O(M + K)$$, where $$M$$ is the space for the `unordered_set` and $$K$$ is the space for the `num` vector storing the kept values.

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = head;
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> num;
        while(temp){
            if(st.find(temp->val) == st.end()){
                num.push_back(temp->val);
            }
            temp = temp->next;
        }
        ListNode* ans = new ListNode(0);
        temp = ans;
        int n = num.size();
        for(int i = 0;i<n;i++){
            ListNode* node = new ListNode(num[i]);
            temp->next = node;
            temp = temp->next;
        }
        return ans->next;
    }
};
```

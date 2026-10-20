# [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
**Difficulty:** `Easy` | **Tags:** `linked-list`

---

## Problem Description
Given the `head` of a sorted linked list, *delete all duplicates such that each element appears only once*. Return *the linked list **sorted** as well*.

**Example 1:**

```
Input: head = [1,1,2]
Output: [1,2]
```

**Example 2:**

```
Input: head = [1,1,2,3,3]
Output: [1,2,3]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 300]`.
* `-100 <= Node.val <= 100`
* The list is guaranteed to be **sorted** in ascending order.

---

## Solution & Editorial
# Intuition
Since the linked list is already sorted in ascending order, any duplicate values must appear consecutively. This allows us to traverse the list with a single pointer and remove duplicates on the fly by adjusting pointer links.

# Approach
1. Check if the given `head` is `nullptr` or has only a single node (`head->next == nullptr`). If so, no duplicates are possible, so return `head` immediately.
2. Initialize a pointer `current` pointing to `head`.
3. Traverse the list using a `while` loop as long as `current` and `current->next` are not `nullptr`.
4. Inside the loop, compare `current->val` with `current->next->val`. If they are equal, bypass the duplicate node by setting `current->next = current->next->next`.
5. If they are not equal, advance the pointer by setting `current = current->next`.
6. Return the modified `head` upon completion.

### Visual Walkthrough for Example 1 (`head = [1, 1, 2]`)

| Step | `current` Val | `current->next` Val | Condition (`val == next->val`) | Action | List State After Action |
| :--- | :---: | :---: | :---: | :--- | :--- |
| 1 | `1` | `1` | True (`1 == 1`) | `current->next = current->next->next` | `[1, 2]` |
| 2 | `1` | `2` | False (`1 != 2`) | `current = current->next` | `[1, 2]` (current at `1`) |
| 3 | `2` | `nullptr` | Loop terminates | None | `[1, 2]` |

# Complexity
- Time complexity: $$O(N)$$ — We traverse each node of the linked list at most once, where $$N$$ is the number of nodes in the list.
- Space complexity: $$O(1)$$ — We only use a single pointer `current`, requiring no auxiliary data structures.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head;
        while(current != nullptr && current->next != nullptr){
            if(current->val == current->next->val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         set<int> nums;
//         ListNode* temp = head;
//         while(temp){
//             nums.insert(temp->val);
//             temp = temp->next;
//         }
//         ListNode* ans = new ListNode(0);
//         temp = ans;
//         for(auto num:nums){
//             ListNode* node = new ListNode(num);
//             temp->next = node;
//             temp = temp->next;
//         }

//         return ans->next;
//     }
// };
```

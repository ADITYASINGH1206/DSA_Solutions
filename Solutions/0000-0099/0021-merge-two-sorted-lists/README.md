# [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
**Difficulty:** `Easy` | **Tags:** `linked-list`, `recursion`

---

## Problem Description
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

**Example 1:**

```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

**Example 2:**

```
Input: list1 = [], list2 = []
Output: []
```

**Example 3:**

```
Input: list1 = [], list2 = [0]
Output: [0]
```

**Constraints:**

* The number of nodes in both lists is in the range `[0, 50]`.
* `-100 <= Node.val <= 100`
* Both `list1` and `list2` are sorted in **non-decreasing** order.

---

## Solution & Editorial
# Intuition
Since both input linked lists are already sorted in non-decreasing order, we can efficiently build a single merged sorted list by comparing the front elements of `list1` and `list2` at each step. Utilizing a dummy head node simplifies pointer manipulation and eliminates the need for edge-case checks when attaching the initial node.

# Approach
1. Initialize a dummy node `ans` with a value of `0` and a pointer `temp` pointing to `ans` to construct the resulting merged list.
2. Iterate through both `list1` and `list2` while neither is null. Compare the values `list1->val` and `list2->val`.
3. Attach the node with the smaller value to `temp->next`, advance the pointer of the chosen list (`list1` or `list2`), and move `temp` forward.
4. Once one of the lists becomes null, append the remaining nodes of the non-empty list directly to `temp->next`.
5. Return `ans->next` to skip the dummy node and return the head of the newly merged sorted list.

### Visual Trace (Example 1)
`list1` = [1, 2, 4], `list2` = [1, 3, 4]
- **Dummy Initialization**: `ans` -> [0], `temp` -> `ans`
- **Iteration 1**: `list1->val` (1) <= `list2->val` (1) -> attach `list1` node 1. `temp` -> [1], `list1` = [2, 4], `list2` = [1, 3, 4]
- **Iteration 2**: `list1->val` (2) > `list2->val` (1) -> attach `list2` node 1. `temp` -> [1 -> 1], `list1` = [2, 4], `list2` = [3, 4]
- **Iteration 3**: `list1->val` (2) < `list2->val` (3) -> attach `list1` node 2. `temp` -> [1 -> 1 -> 2], `list1` = [4], `list2` = [3, 4]
- **Iteration 4**: `list1->val` (4) > `list2->val` (3) -> attach `list2` node 3. `temp` -> [1 -> 1 -> 2 -> 3], `list1` = [4], `list2` = [4]
- **Iteration 5**: `list1->val` (4) <= `list2->val` (4) -> attach `list1` node 4. `temp` -> [1 -> 1 -> 2 -> 3 -> 4], `list1` = [], `list2` = [4]
- **Tail Attachment**: Append remaining `list2` node 4. Result list: [1 -> 1 -> 2 -> 3 -> 4 -> 4].

# Complexity
- Time complexity: $$O(N + M)$$ where $$N$$ and $$M$$ are the lengths of `list1` and `list2`. Each node from both lists is visited exactly once.
- Space complexity: $$O(1)$$ as only a constant amount of extra pointer memory (`ans` and `temp`) is used independently of the input size.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* temp= ans;
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else{
                temp->next = list2;
                list2= list2->next;
                temp = temp->next;
            }
        }
        while(list1){
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }
        while(list2){
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        return ans->next;
    }
};
```

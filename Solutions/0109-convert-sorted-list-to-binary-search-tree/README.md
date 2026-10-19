# [109. Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `divide-and-conquer`, `tree`, `binary-search-tree`, `binary-tree`

---

## Problem Description
Given the `head` of a singly linked list where elements are sorted in **ascending order**, convert *it to a* ***height-balanced*** *binary search tree*.

**Example 1:**

```
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
```

**Example 2:**

```
Input: head = []
Output: []
```

**Constraints:**

* The number of nodes in `head` is in the range `[0, 2 * 104]`.
* `-105 <= Node.val <= 105`

---

## Solution & Editorial
# Intuition
To convert a sorted singly linked list into a height-balanced binary search tree, the middle element of the list must be chosen as the root. This guarantees that the left and right subtrees have an approximately equal number of nodes, satisfying the height-balanced property.

# Approach
1. Check base cases: if the `head` is `nullptr`, return `nullptr`. If `head->next` is `nullptr`, return a new `TreeNode` containing `head->val`.
2. Use the classical slow and fast pointer technique to locate the middle element (`slow`) of the linked list along with its predecessor (`slow_prev`).
3. Create the `root` node with the value of `slow`.
4. Sever the left half of the list by setting `slow_prev->next = nullptr`.
5. Recursively call `sortedListToBST` on the left sublist starting at `head` and assign it to `root->left`.
6. Recursively call `sortedListToBST` on the right sublist starting at `slow->next` and assign it to `root->right`.
7. Return `root`.

### Visual Trace Walkthrough (Example 1: `[-10, -3, 0, 5, 9]`)
- Initial List: `-10 -> -3 -> 0 -> 5 -> 9 -> nullptr`
- `slow` lands at `0`, `slow_prev` points to `-3`.
- Root value = `0`.
- List split into `[-10, -3]` and `[5, 9]`.
- Left recursive call processes `[-10, -3]`, picking `-3` as root with left child `-10`.
- Right recursive call processes `[5, 9]`, picking `5` as root with right child `9`.

# Complexity
- Time complexity: $$O(N \log N)$$ — Finding the middle element takes linear time proportional to the length of the sublist, and the recursion depth is $$O(\log N)$$ for a balanced tree.
- Space complexity: $$O(\log N)$$ — The auxiliary stack space required for recursion depth in a balanced binary tree.

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);

        slow_prev->next = nullptr;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
```

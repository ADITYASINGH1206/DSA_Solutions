# [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
**Difficulty:** `Easy` | **Tags:** `linked-list`, `two-pointers`, `stack`, `recursion`

---

## Problem Description
Given the `head` of a singly linked list, return `true` *if it is a* *palindrome* *or* `false` *otherwise*.

**Example 1:**

```
Input: head = [1,2,2,1]
Output: true
```

**Example 2:**

```
Input: head = [1,2]
Output: false
```

**Constraints:**

* The number of nodes in the list is in the range `[1, 105]`.
* `0 <= Node.val <= 9`

**Follow up:** Could you do it in `O(n)` time and `O(1)` space?

---

## Solution & Editorial
# Intuition
A singly linked list does not permit efficient backward traversal. By copying the node values into a contiguous linear container such as a vector, we can directly employ bidirectional two-pointer scanning to verify palindrome symmetry.

# Approach
1. Initialize a dynamic array `nums` to store the node values.
2. Traverse the linked list starting from `head` using a pointer `temp`, pushing each node's `val` into `nums` until `temp` reaches `nullptr`.
3. Initialize two pointers `l = 0` and `r = nums.size() - 1` pointing to the start and end of the vector respectively.
4. Iterate while `l < r`, comparing elements at `nums[l]` and `nums[r]`. If a mismatch is found, immediately return `false`.
5. Increment `l` and decrement `r` on each successful match. If the pointers meet or cross without mismatch, return `true`.

### Visual Walkthrough (Example 1: head = [1,2,2,1])
- **Traversal Phase:** `nums` becomes `[1, 2, 2, 1]`. `l = 0`, `r = 3`.
- **Iteration 1:** `nums[0] == 1`, `nums[3] == 1` (Match). `l` becomes `1`, `r` becomes `2`.
- **Iteration 2:** `nums[1] == 2`, `nums[2] == 2` (Match). `l` becomes `2`, `r` becomes `1`.
- **Termination:** `l < r` condition (`2 < 1`) fails. Loop terminates. Returns `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. We perform one linear traversal to copy elements into the vector and at most $$N/2$$ comparisons during the two-pointer check.
- Space complexity: $$O(N)$$ auxiliary space to store the node values in the `nums` vector.

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
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            if(nums[l] != nums[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
```

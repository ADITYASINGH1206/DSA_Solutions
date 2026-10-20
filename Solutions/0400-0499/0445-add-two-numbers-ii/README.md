# [445. Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `math`, `stack`

---

## Problem Description
You are given two **non-empty** linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**

```
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
```

**Example 2:**

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
```

**Example 3:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Constraints:**

* The number of nodes in each linked list is in the range `[1, 100]`.
* `0 <= Node.val <= 9`
* It is guaranteed that the list represents a number that does not have leading zeros.

**Follow up:** Could you solve it without reversing the input lists?

---

## Solution & Editorial
# Intuition
To add two numbers represented by linked lists where the most significant digit comes first, we need to process digits starting from the least significant digit (i.e., from right to left). Since singly-linked lists only permit forward traversal, we can utilize auxiliary stacks to reverse the access order of the digits without modifying the original linked list structures.

# Approach
1. Traverse both linked lists `l1` and `l2` completely, pushing their respective node values onto `stk1` and `stk2`. This places the least significant digits at the top of the stacks.
2. Initialize a pointer `ans` to `nullptr` and an integer `carry` to `0` to keep track of the overflow during addition.
3. Enter a while loop that continues as long as `stk1`, `stk2`, or `carry` is non-zero.
   - Pop or fetch top elements `d1` and `d2` from `stk1` and `stk2` respectively if the stacks are not empty, defaulting to `0` otherwise.
   - Compute `sum = d1 + d2 + carry`, update `carry = sum / 10`, and keep the single digit `sum = sum % 10`.
   - Create a new `ListNode` with the value `sum` and prepend it to the `ans` list.
   - Pop the processed elements from `stk1` and `stk2` if they were not empty.
4. Return the constructed `ans` linked list.

### Visual Trace (Example 1: l1 = [7,2,4,3], l2 = [5,6,4])
- Initial Stacks:
  - `stk1`: bottom `[7, 2, 4, 3]` top
  - `stk2`: bottom `[5, 6, 4]` top
- Iteration 1:
  - `d1 = 3`, `d2 = 4`, `carry = 0` -> `sum = 7`, `carry = 0`, new node `7`, `ans = [7]`
- Iteration 2:
  - `d1 = 4`, `d2 = 6`, `carry = 0` -> `sum = 10`, `carry = 1`, new node `0`, `ans = [0, 7]`
- Iteration 3:
  - `d1 = 2`, `d2 = 5`, `carry = 1` -> `sum = 8`, `carry = 0`, new node `8`, `ans = [8, 0, 7]`
- Iteration 4:
  - `d1 = 7`, `d2 = 0`, `carry = 0` -> `sum = 7`, `carry = 0`, new node `7`, `ans = [7, 8, 0, 7]`

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of `l1` and `l2`. We iterate through both lists once to populate the stacks and once more during the addition phase.
- Space complexity: $$O(N + M)$$ due to the storage required for `stk1` and `stk2` containing up to $$N$$ and $$M$$ elements respectively.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1,stk2;

        while (l1 != nullptr) {
            stk1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            stk2.push(l2->val);
            l2 = l2->next;
        }


        ListNode* ans = nullptr;
        int carry = 0;

        while(!stk1.empty() || !stk2.empty()|| carry!=0){
            int d1 = !stk1.empty() ? stk1.top() : 0;
            int d2 = !stk2.empty() ? stk2.top() : 0;

            int sum = d1+d2+carry;
            carry = sum/10;
            sum = sum%10;

            ListNode* node = new ListNode(sum);
            node->next = ans;
            ans = node;

            if(!stk1.empty()) stk1.pop();
            if(!stk2.empty()) stk2.pop();

        }
        return ans;

    }
};
```

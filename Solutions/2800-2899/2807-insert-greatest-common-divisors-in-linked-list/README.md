# [2807. Insert Greatest Common Divisors in Linked List](https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `math`, `number-theory`

---

## Problem Description
Given the head of a linked list `head`, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the **greatest common divisor** of them.

Return *the linked list after insertion*.

The **greatest common divisor** of two numbers is the largest positive integer that evenly divides both numbers.

**Example 1:**

```
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.
```

**Example 2:**

```
Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.
```

**Constraints:**

* The number of nodes in the list is in the range `[1, 5000]`.
* `1 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
To solve this problem, we need to traverse the linked list and identify adjacent pairs of nodes. For every pair, we calculate the Greatest Common Divisor (GCD) and insert a new node containing this value between them. Since we are modifying the list in-place, we can maintain a pointer to the current node and perform the insertion by updating the `next` pointers.

# Approach
1. Initialize a pointer `temp` to the `head` of the linked list.
2. Iterate through the list using a `while` loop that continues as long as `temp->next` is not null.
3. Inside the loop, calculate the GCD of `temp->val` and `temp->next->val` using the built-in `std::gcd` function.
4. Create a new node `g1` with the calculated GCD value, setting its `next` pointer to the current `temp->next`.
5. Update `temp->next` to point to the new node `g1`.
6. Advance the `temp` pointer by two steps (to the original next node) to continue the process for the next pair.

### Visual Trace (Example 1: [18, 6, 10, 3])
| Iteration | `temp` val | `temp->next` val | GCD | Action | List State |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 18 | 6 | 6 | Insert 6 | [18, 6, 6, 10, 3] |
| 2 | 6 | 10 | 2 | Insert 2 | [18, 6, 6, 2, 10, 3] |
| 3 | 10 | 3 | 1 | Insert 1 | [18, 6, 6, 2, 10, 1, 3] |

# Complexity
- Time complexity: $$O(N \cdot \log(\min(A, B)))$$, where $$N$$ is the number of nodes and $$A, B$$ are node values. The traversal visits each node once, and the GCD calculation takes logarithmic time relative to the node values.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for pointers and variables, regardless of the input size.

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while (temp->next) {
            int g = gcd(temp->val,temp->next->val);
            ListNode* g1 = new ListNode(g,temp->next);
            temp->next = g1;
            temp = temp->next->next;
        }
        return head;
    }
};
```

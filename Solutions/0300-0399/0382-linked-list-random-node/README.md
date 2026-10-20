# [382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)
**Difficulty:** `Medium` | **Tags:** `linked-list`, `math`, `reservoir-sampling`, `randomized`

---

## Problem Description
Given a singly linked list, return a random node's value from the linked list. Each node must have the **same probability** of being chosen.

Implement the `Solution` class:

* `Solution(ListNode head)` Initializes the object with the head of the singly-linked list `head`.
* `int getRandom()` Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

**Example 1:**

```
Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
```

**Constraints:**

* The number of nodes in the linked list will be in the range `[1, 104]`.
* `-104 <= Node.val <= 104`
* At most `104` calls will be made to `getRandom`.

**Follow up:**

* What if the linked list is extremely large and its length is unknown to you?
* Could you solve this efficiently without using extra space?

---

## Solution & Editorial
# Intuition
To select a random node from a singly linked list with unknown or large length without using extra space, we can apply Reservoir Sampling (specifically, Algorithm R). As we stream through the list from the head to the tail, the $i$-th node is chosen as the candidate answer with probability $\frac{1}{i}$. This guarantees that when the traversal finishes, every node in the linked list has an identical probability of $\frac{1}{N}$ of being selected.

# Approach
1. In the `Solution` constructor, we store the reference to the `head` node of the linked list and initialize the random number generator seed using `srand(time(0))`. 
2. In the `getRandom()` function, we initialize an answer variable `ans = 0` and a counter `i = 1` starting from the first node.
3. We set a pointer `p` to `this->head` and iterate through the linked list while `p` is not null.
4. For each node, we generate a random integer and check the condition `rand() % i == 0`. If this condition evaluates to true, we update `ans = p->val`.
5. We increment `i` and advance `p` to `p->next` until the end of the list is reached.
6. Finally, we return `ans`.

### Visual Trace Walkthrough
Consider a linked list with values `[1, 2, 3]`. Calling `getRandom()`:

| Step | Pointer `p` | Node Value | Counter `i` | `rand() % i == 0` Condition | Resulting `ans` | Explanation |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | Node 1 | `1` | `1` | `rand() % 1 == 0` (Always True) | `1` | First element always selected with probability 1 |
| 2 | Node 2 | `2` | `2` | `rand() % 2 == 0` (50% chance) | `2` (or `1`) | Replaced with probability $1/2$ |
| 3 | Node 3 | `3` | `3` | `rand() % 3 == 0` (33% chance) | `3` (or previous) | Replaced with probability $1/3$ |

# Complexity
- Time complexity: $$O(N)$$ per `getRandom()` call, where $$N$$ is the number of nodes in the linked list. We traverse the list exactly once from the head to the tail.
- Space complexity: $$O(1)$$ auxiliary space, as no additional data structures or recursion stacks are used beyond a few scalar variables.

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
    ListNode *head = NULL;
    
    Solution(ListNode* head) {
        this->head = head;
        srand(time(0)); 
    }
    
    int getRandom() {
        int ans = 0;
        int i = 1;
        ListNode *p = this->head;
        
        while (p) {
            if (rand() % i == 0) {
                ans = p->val;
            }
            i++;
            p = p->next;
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
```

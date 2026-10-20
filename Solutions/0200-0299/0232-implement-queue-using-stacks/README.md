# [232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
**Difficulty:** `Easy` | **Tags:** `stack`, `design`, `queue`

---

## Problem Description
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:

* `void push(int x)` Pushes element x to the back of the queue.
* `int pop()` Removes the element from the front of the queue and returns it.
* `int peek()` Returns the element at the front of the queue.
* `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.

**Notes:**

* You must use **only** standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
* Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

**Example 1:**

```
Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

**Constraints:**

* `1 <= x <= 9`
* At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
* All the calls to `pop` and `peek` are valid.

**Follow-up:** Can you implement the queue such that each operation is **[amortized](https://en.wikipedia.org/wiki/Amortized_analysis)** `O(1)` time complexity? In other words, performing `n` operations will take overall `O(n)` time even if one of those operations may take longer.

---

## Solution & Editorial
# Intuition
To implement a First-In-First-Out (FIFO) queue using Last-In-First-Out (LIFO) stacks, we can maintain two separate stacks: `s1` for incoming elements and `s2` for outgoing elements. By reversing the order of elements through `s1` into `s2` only when `s2` is empty, we achieve an amortized $O(1)$ time complexity per operation.

# Approach
1. **`push(int x)`**: Simply push the new element `x` onto stack `s1`. This takes $O(1)$ time.
2. **`transfer()` helper**: Checks if `s2` is empty. If it is, pop all elements from `s1` and push them onto `s2`. This reverses their order, placing the oldest element at the top of `s2`.
3. **`peek()`**: Calls `transfer()` to ensure `s2` has the front of the queue ready at its top, then returns `s2.top()` in $O(1)$ amortized time.
4. **`pop()`**: Calls `peek()` to get the front element, pops it from `s2`, and returns the stored value.
5. **`empty()`**: Returns `true` if both `s1` and `s2` are empty; otherwise, `false`.

### Visual Trace Walkthrough (Example 1)

| Operation | `s1` (Bottom -> Top) | `s2` (Bottom -> Top) | Action / Output |
| :--- | :--- | :--- | :--- |
| `push(1)` | `[1]` | `[]` | Pushed `1` to `s1` |
| `push(2)` | `[1, 2]` | `[]` | Pushed `2` to `s1` |
| `peek()` | `[]` | `[2, 1]` | `s2` is empty, transferred all from `s1`. Returns `1`. |
| `pop()` | `[]` | `[2]` | Pops `1` from `s2`. Returns `1`. |
| `empty()` | `[]` | `[2]` | Returns `false`. |

# Complexity
- Time complexity: 
  - `push`: $$O(1)$$ 
  - `pop` / `peek`: Amortized $$O(1)$$ (each element is moved from `s1` to `s2` at most once).
  - `empty`: $$O(1)$$
- Space complexity: $$O(N)$$, where $N$ is the total number of elements stored across both stacks.

# Code
```cpp
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2; 

    void transfer() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int val = peek();
        s2.pop();
        return val;
    }

    int peek() {
        transfer();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
```

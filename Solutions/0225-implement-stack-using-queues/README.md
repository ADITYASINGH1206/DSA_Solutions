# [225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
**Difficulty:** `Easy` | **Tags:** `stack`, `design`, `queue`

---

## Problem Description
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:

* `void push(int x)` Pushes element x to the top of the stack.
* `int pop()` Removes the element on the top of the stack and returns it.
* `int top()` Returns the element on the top of the stack.
* `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.

**Notes:**

* You must use **only** standard operations of a queue, which means that only `push to back`, `peek/pop from front`, `size` and `is empty` operations are valid.
* Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

**Example 1:**

```
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

**Constraints:**

* `1 <= x <= 9`
* At most `100` calls will be made to `push`, `pop`, `top`, and `empty`.
* All the calls to `pop` and `top` are valid.

**Follow-up:** Can you implement the stack using only one queue?

---

## Solution & Editorial
# Intuition
A stack operates on a Last-In-First-Out (LIFO) basis, whereas a queue is First-In-First-Out (FIFO). By reordering elements immediately upon insertion using a single queue, we can maintain the newest element at the front of the queue, reducing pop and top operations to $$O(1)$$ time complexity.

# Approach
1. Maintain a single `std::queue<int> q` as the core data structure.
2. **`push(int x)`**: Capture the current queue size `s = q.size()`, push the new element `x` to the back, and then rotate the previous `s` elements from the front to the back so that the newly pushed element ends up at the front.
3. **`pop()`**: Simply remove and return the element at the front of the queue, which corresponds to the top of the stack in $$O(1)$$ time.
4. **`top()`**: Return the front element of the queue without removing it in $$O(1)$$ time.
5. **`empty()`**: Check if the queue is empty.

### Visual Trace Walkthrough (Example 1)

| Operation | Arguments | Queue State (Front -> Back) | Output |
| :--- | :--- | :--- | :--- |
| `MyStack` | `[]` | `[]` | `null` |
| `push` | `[1]` | `[1]` | `null` |
| `push` | `[2]` | `[2, 1]` | `null` |
| `top` | `[]` | `[2, 1]` | `2` |
| `pop` | `[]` | `[1]` | `2` |
| `empty` | `[]` | `[1]` | `false` |

# Complexity
- Time complexity:
  - `push(x)`: $$O(N)$$ where $$N$$ is the current number of elements in the stack, as it requires rotating all existing elements once.
  - `pop()`: $$O(1)$$ as it accesses the front directly.
  - `top()`: $$O(1)$$ as it peeks at the front directly.
  - `empty()`: $$O(1)$$.
- Space complexity: $$O(N)$$ auxiliary space to store elements in the single queue.

# Code
```cpp
class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i = 0; i < s; i++) {
            q.push(q.front()); 
            q.pop();
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty(); 
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

# [155. Min Stack](https://leetcode.com/problems/min-stack/)
**Difficulty:** `Medium` | **Tags:** `stack`, `design`

---

## Problem Description
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

* `MinStack()` initializes the stack object.
* `void push(int value)` pushes the element `value` onto the stack.
* `void pop()` removes the element on the top of the stack.
* `int top()` gets the top element of the stack.
* `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

**Example 1:**

```
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

**Constraints:**

* `-231 <= val <= 231 - 1`
* Methods `pop`, `top` and `getMin` operations will always be called on **non-empty** stacks.
* At most `3 * 104` calls will be made to `push`, `pop`, `top`, and `getMin`.

---

## Solution & Editorial
# Intuition
To retrieve the minimum element in constant time $$O(1)$$, we need to track the minimum value alongside every element inserted into the stack. By pairing each pushed value with the current minimum up to that point, we preserve historical minimums upon pop operations without extra traversal.

# Approach
1. Use a single stack `st` storing `std::pair<int, int>`, where the first element is the actual value `val` and the second element is the minimum value in the stack from this element down to the bottom.
2. In `push(val)`, if the stack is not empty, compute the new minimum as `min(val, st.top().second)` and push the pair `{val, new_min}`. If the stack is empty, push `{val, val}`.
3. In `pop()`, remove the top element from `st` using `st.pop()`.
4. In `top()`, return the first element of the top pair using `st.top().first`.
5. In `getMin()`, return the second element of the top pair using `st.top().second`.

### Visual Walkthrough (Example 1)

| Operation | Input Value | Stack State (`{val, min}`) | Output |
| :--- | :--- | :--- | :--- |
| `MinStack()` | - | `[]` | `-` |
| `push(-2)` | `-2` | `[{-2, -2}]` | `null` |
| `push(0)` | `0` | `[{-2, -2}, {0, -2}]` | `null` |
| `push(-3)` | `-3` | `[{-2, -2}, {0, -2}, {-3, -3}]` | `null` |
| `getMin()` | - | `[{-2, -2}, {0, -2}, {-3, -3}]` | `-3` |
| `pop()` | - | `[{-2, -2}, {0, -2}]` | `null` |
| `top()` | - | `[{-2, -2}, {0, -2}]` | `0` |
| `getMin()` | - | `[{-2, -2}, {0, -2}]` | `-2` |

# Complexity
- Time complexity: $$O(1)$$ for all operations (`push`, `pop`, `top`, `getMin`) as standard stack operations and comparisons take constant time.
- Space complexity: $$O(N)$$ where $$N$$ is the maximum number of elements in the stack, required to store the pair of values for each entry.

# Code
```cpp
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (!st.empty()) {
            st.push({val, min(val, st.top().second)});
        } else {
            st.push({val, val});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

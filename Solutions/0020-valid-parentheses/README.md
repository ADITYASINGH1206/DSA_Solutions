# [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
**Difficulty:** `Easy` | **Tags:** `string`, `stack`, `bracket-sequences`

---

## Problem Description
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

**Example 1:**

**Input:** s = "()"

**Output:** true

**Example 2:**

**Input:** s = "()[]{}"

**Output:** true

**Example 3:**

**Input:** s = "(]"

**Output:** false

**Example 4:**

**Input:** s = "([])"

**Output:** true

**Example 5:**

**Input:** s = "([)]"

**Output:** false

**Constraints:**

* `1 <= s.length <= 104`
* `s` consists of parentheses only `'()[]{}'`.

---

## Solution & Editorial
# Intuition
The problem requires validating whether every opening bracket has a corresponding closing bracket of the same type in the correct nested order. A Last-In-First-Out (LIFO) data structure like a stack naturally models this nesting property, where the most recently opened bracket must be closed first.

# Approach
1. Initialize an empty character stack `stk` and get the string length `n`.
2. Iterate through each character `s[i]` of the string from left to right.
3. If the stack is empty, push the current character `s[i]` onto the stack.
4. If the stack is not empty, check if the top of the stack forms a valid pair with `s[i]` (i.e., `()`, `[]`, or `{}`). If it does, pop the matching opening bracket from the stack.
5. Otherwise, push the current character `s[i]` onto the stack.
6. After the loop, return `true` if the stack is empty (all brackets successfully matched), otherwise return `false`.

### Visual Trace Walkthrough (Example 1: s = "()")

| Iteration | Character `s[i]` | Stack Before | Action | Stack After |
| :--- | :--- | :--- | :--- | :--- |
| 0 | `'('` | `[]` | Stack empty, push | `['(']` |
| 1 | `')'` | `['(']` | Top matches `')'`, pop | `[]` |

Result: Stack is empty, returns `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of string `s`. We traverse the string exactly once, performing constant time $$O(1)$$ stack operations ($	ext{push}$, $	ext{pop}$, $	ext{top}$) for each character.
- Space complexity: $$O(N)$$, required in the worst-case scenario (e.g., all opening brackets like `((((`) where all characters are pushed onto the stack.

# Code
```cpp
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stk;
        for(int i = 0;i<n;i++){
            if(stk.empty()){
                stk.push(s[i]);
            }else{
                if(stk.top() == '(' && s[i] == ')') stk.pop(); 
                else if(stk.top() == '[' && s[i] == ']') stk.pop(); 
                else if(stk.top() == '{' && s[i] == '}') stk.pop(); 
                else stk.push(s[i]);
            }
        }

        bool ans = stk.size() == 0 ? true : false;

        return ans;
    }
};
```

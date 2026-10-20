# [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `greedy`, `bracket-sequences`

---

## Problem Description
A parentheses string is valid if and only if:

* It is the empty string,
* It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
* It can be written as `(A)`, where `A` is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

* For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(()))"` or a closing parenthesis to be `"())))"`.

Return *the minimum number of moves required to make* `s` *valid*.

**Example 1:**

```
Input: s = "())"
Output: 1
```

**Example 2:**

```
Input: s = "((("
Output: 3
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s[i]` is either `'('` or `')'`.

---

## Solution & Editorial
# Intuition
To determine the minimum number of parentheses needed to make the string valid, we can simulate a stack-based bracket matching process. Any unmatched closing parenthesis requires an opening parenthesis, and any leftover opening parentheses in our stack at the end will each require a closing parenthesis.

# Approach
1. Initialize an empty character vector `stk` to act as our stack, along with string length `n = s.size()`.
2. Iterate through each character `s[i]` of the string from left to right.
3. If the stack is empty, push the current character `s[i]` onto `stk`.
4. If the stack is not empty, check if the top element `stk.back()` is `'('` and the current character `s[i]` is `')'`. If it forms a valid pair, pop the stack using `stk.pop_back()`. Otherwise, push `s[i]` onto the stack.
5. After the loop completes, the remaining elements in `stk` represent unmatched parentheses. The size of `stk` gives the required minimum additions.

### Visual Trace (Example 1: `s = "()) "`)

| Index `i` | Char `s[i]` | Stack Before | Action | Stack After |
| :---: | :---: | :---: | :--- | :--- |
| 0 | `'('` | `[]` | Push `'('` | `['(']` |
| 1 | `')'` | `['(']` | Match `()`, Pop | `[]` |
| 2 | `')'` | `[]` | Push `')'` | `[')']` |

Final stack size is `1`, which is returned as the answer.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string `s`. Each character is pushed and popped from the vector stack at most once.
- Space complexity: $$O(N)$$ to store the characters in the vector stack in the worst-case scenario (e.g., all opening or all closing parentheses).

# Code
```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int n = s.size();
        vector<char> stk;
        for(int i =0;i<n;i++){
            if(stk.empty()){
                stk.push_back(s[i]);
            }else{
                if(stk.back() == '(' && s[i] == ')') stk.pop_back();
                else stk.push_back(s[i]);
            }
        }
        ans = stk.size();
        return ans;
    }
};
```

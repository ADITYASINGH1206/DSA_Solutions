# [301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)
**Difficulty:** `Hard` | **Tags:** `string`, `backtracking`, `breadth-first-search`

---

## Problem Description
Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return *a list of **unique strings** that are valid with the minimum number of removals*. You may return the answer in **any order**.

**Example 1:**

```
Input: s = "()())()"
Output: ["(())()","()()()"]
```

**Example 2:**

```
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
```

**Example 3:**

```
Input: s = ")("
Output: [""]
```

**Constraints:**

* `1 <= s.length <= 25`
* `s` consists of lowercase English letters and parentheses `'('` and `')'`.
* There will be at most `20` parentheses in `s`.

---

## Solution & Editorial
# Intuition
The problem requires us to remove the minimum number of invalid parentheses to yield valid expressions. We can track the balance of opening and closing parentheses from left to right. When an invalid closing parenthesis is encountered (i.e., `balance < 0`), we branch out by deleting any preceding closing parenthesis that has not yet been tried, effectively pruning redundant states and avoiding duplicate outputs.

# Approach
1. Define a recursive helper function `remove` taking the current string `s`, `scanStart`, `deleteStart`, `open`, and `close` characters, and the `answers` vector.
2. Iterate through `s` starting from `scanStart`, updating `balance` (+1 for `open`, -1 for `close`).
3. If `balance < 0`, an excess `close` parenthesis is found at index `i`. Iterate `j` from `deleteStart` to `i` to try deleting a candidate `close` parenthesis. Skip consecutive identical characters to prune duplicates.
4. Recurse with the substring formed by omitting index `j`, passing `i` as the new `scanStart` and `j` as `deleteStart`. Return immediately to avoid continuing down the invalid branch.
5. Once a pass from left to right completes without violation, reverse the string and switch `open` and `close` roles to check from right to left. After the reverse pass is complete, push the final valid string into `answers`.

### Visual Trace Walkthrough (Example 1: `s = "()())()"`)
- **Initial Pass (`(` vs `)`):** At index 4, `balance` drops to `-1`. We try deleting closing parentheses at indices 1, 3, and 4.
- **Branch deletion at index 3:** Substring becomes `"()()()"`, which passes completely. Then we reverse it and run the reverse pass, yielding `"()()()"` in `answers`.
- **Branch deletion at index 4:** Substring becomes `"(())()"`, which passes completely. Reverse pass yields `"(())()"` in `answers`.

# Complexity
- Time complexity: $$O(2^N)$$ in the worst-case where $N$ is the length of the string, due to exploring combinations of removals, heavily optimized by pruning duplicate branches.
- Space complexity: $$O(N)$$ for the recursion call stack depth and substring allocations.

# Code
```cpp
class Solution {
    void remove(string s, int scanStart, int deleteStart, char open, char close,
                vector<string>& answers) {
        int balance = 0;

        for (int i = scanStart; i < (int)s.size(); i++) {
            if (s[i] == open) {
                balance++;
            } else if (s[i] == close) {
                balance--;
            }

            if (balance >= 0) {
                continue;
            }

            for (int j = deleteStart; j <= i; j++) {
                if (s[j] == close && (j == deleteStart || s[j - 1] != close)) {
                    remove(s.substr(0, j) + s.substr(j + 1), i, j, open, close,
                           answers);
                }
            }

            return;
        }

        reverse(s.begin(), s.end());

        if (open == '(') {
            remove(s, 0, 0, ')', '(', answers);
        } else {
            answers.push_back(s);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> answers;
        remove(s, 0, 0, '(', ')', answers);
        return answers;
    }
};
```

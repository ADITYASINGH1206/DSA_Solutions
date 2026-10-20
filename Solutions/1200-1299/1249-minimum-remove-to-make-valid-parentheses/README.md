# [1249. Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`

---

## Problem Description
Given a string s of `'('` , `')'` and lowercase English characters.

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting *parentheses string* is valid and return **any** valid string.

Formally, a *parentheses string* is valid if and only if:

* It is the empty string, contains only lowercase characters, or
* It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
* It can be written as `(A)`, where `A` is a valid string.

**Example 1:**

```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

**Example 2:**

```
Input: s = "a)b(c)d"
Output: "ab(c)d"
```

**Example 3:**

```
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
```

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is either `'('` , `')'`, or lowercase English letter.

---

## Solution & Editorial
# Intuition
To make a parenthesis string valid, we must ensure that every closing parenthesis has a corresponding opening parenthesis and vice versa. We can achieve this by performing two checks: filtering out invalid closing parentheses on the fly using a balance counter, and then filtering out excess opening parentheses from right to left using a stack.

# Approach
1. Initialize two integer counters, `left` and `right`, to track the balance of opening and closing parentheses, and a character stack `stk`.
2. Iterate through each character `ch` in the string `s`. If `ch` is `(`, increment `left`. If `ch` is `)`, increment `right`. If at any point `right > left`, it means we have an unmatched closing parenthesis. We discard it by decrementing `right` and skipping the push into `stk`. Otherwise, we push `ch` onto `stk`.
3. After the first pass, `stk` contains all characters except invalid closing parentheses. However, there might be excess opening parentheses (where `left > right`).
4. Pop elements from `stk` into a temporary string `ans`, decrementing `left` whenever we encounter an extra `(` until `left == right`. Any other characters are appended to `ans`.
5. Finally, reverse `ans` to restore the original relative order and return it.

### Visual Trace Walkthrough (Example 2: s = "a)b(c)d")
- **Pass 1 (Filtering `)`):**
  - `'a'`: pushed to `stk` (`left=0, right=0`)
  - `')'`: `right` becomes 1. Since `right > left` (1 > 0), decrement `right` to 0 and skip.
  - `'b'`: pushed to `stk`
  - `'('`: `left` becomes 1, pushed to `stk`
  - `')'`: `right` becomes 1 (`left=1, right=1`), pushed to `stk`
  - `'d'`: pushed to `stk`
- **Pass 2 (Filtering `(` from stack):**
  - Pop elements from stack: `'d'`, `')'`, `'('`, `'b'`, `'a'`. Since `left == right` (1 == 1), the `(` is kept. Resulting `ans` before reversal: `d)b(a`.
- **Final Reversal:** Reverse `ans` to get `ab(c)d`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string `s`. We traverse the string twice: once during the forward iteration and once during the stack extraction and reversal.
- Space complexity: $$O(N)$$ to store characters in the stack and the temporary result string.

# Code
```cpp
class Solution {
public:
    string minRemoveToMakeValid(std::string s) {
        int left = 0;
        int right = 0;
        stack<char> stk;

        for (char ch : s) {
            if (ch == '(') {
                left++;
            } else if (ch == ')') {
                right++;
            }
            if (right > left) {
                right--;
                continue;
            } else {
                stk.push(ch);
            }
        }

        string ans = "";
        
        while (!stk.empty()) {
            char curr = stk.top();
            stk.pop();
            if (left > right && curr == '(') {
                left--;
            } else {
                ans += curr;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

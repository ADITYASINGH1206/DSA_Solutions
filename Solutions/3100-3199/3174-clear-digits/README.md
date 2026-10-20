# [3174. Clear Digits](https://leetcode.com/problems/clear-digits/)
**Difficulty:** `Easy` | **Tags:** `string`, `stack`, `simulation`

---

## Problem Description
You are given a string `s`.

Your task is to remove **all** digits by doing this operation repeatedly:

* Delete the *first* digit and the **closest** **non-digit** character to its *left*.

Return the resulting string after removing all digits.

**Note** that the operation *cannot* be performed on a digit that does not have any non-digit character to its left.

**Example 1:**

**Input:** s = "abc"

**Output:** "abc"

**Explanation:**

There is no digit in the string.

**Example 2:**

**Input:** s = "cb34"

**Output:** ""

**Explanation:**

First, we apply the operation on `s[2]`, and `s` becomes `"c4"`.

Then we apply the operation on `s[1]`, and `s` becomes `""`.

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists only of lowercase English letters and digits.
* The input is generated such that it is possible to delete all digits.

---

## Solution & Editorial
# Intuition
The problem requires removing the closest non-digit character to the left of every digit. This LIFO (Last-In, First-Out) behavior is a classic indicator that a stack data structure is the optimal tool for the job.

# Approach
1. Initialize an empty string `ans` to act as our stack.
2. Iterate through each character `ch` in the input string `s`.
3. If `ch` is a digit, it signifies an operation: remove the most recently added non-digit character from `ans` using `pop_back()`.
4. If `ch` is a non-digit character, push it onto the `ans` stack.
5. After processing all characters, the remaining contents of `ans` represent the final string.

### Visual Trace (s = "cb34")
| Iteration | Char | Action | `ans` (Stack) |
| :--- | :--- | :--- | :--- |
| 1 | 'c' | Push | "c" |
| 2 | 'b' | Push | "cb" |
| 3 | '3' | Pop | "c" |
| 4 | '4' | Pop | "" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass over the input, and each character is pushed or popped from the stack at most once.
- Space complexity: $$O(N)$$ in the worst case (e.g., a string with no digits), where we store the characters in the result string.

# Code
```cpp
class Solution {
public:
    string clearDigits(string s) {
        string ans = ""; 
        
        for (char ch : s) {
            if (isdigit(ch)) {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};
```

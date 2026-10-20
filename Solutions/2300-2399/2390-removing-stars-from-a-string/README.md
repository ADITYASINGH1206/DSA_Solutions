# [2390. Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `simulation`

---

## Problem Description
You are given a string `s`, which contains stars `*`.

In one operation, you can:

* Choose a star in `s`.
* Remove the closest **non-star** character to its **left**, as well as remove the star itself.

Return *the string after **all** stars have been removed*.

**Note:**

* The input will be generated such that the operation is always possible.
* It can be shown that the resulting string will always be unique.

**Example 1:**

```
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
```

**Example 2:**

```
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of lowercase English letters and stars `*`.
* The operation above can be performed on `s`.

---

## Solution & Editorial
# Intuition
The problem requires removing the closest non-star character to the left of each star. This Last-In-First-Out (LIFO) behavior is a classic indicator that a stack data structure is the optimal tool for the job.

# Approach
1. Initialize an empty string `ans` to act as a stack.
2. Iterate through each character `s[i]` in the input string `s`.
3. If the character is not a star, push it onto the `ans` stack.
4. If the character is a star, pop the top element from `ans` (the most recently added non-star character).
5. Return the final `ans` string.

### Visual Trace: s = "leet**cod*e"
| Iteration | Char | Action | `ans` (Stack) |
| :--- | :--- | :--- | :--- |
| 0 | 'l' | Push | "l" |
| 1 | 'e' | Push | "le" |
| 2 | 'e' | Push | "lee" |
| 3 | 't' | Push | "leet" |
| 4 | '*' | Pop | "lee" |
| 5 | '*' | Pop | "le" |
| 6 | 'c' | Push | "lec" |
| 7 | 'o' | Push | "leco" |
| 8 | 'd' | Push | "lecod" |
| 9 | '*' | Pop | "leco" |
| 10 | 'e' | Push | "lecoe" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass over the input, and each character is pushed or popped from the stack at most once.
- Space complexity: $$O(N)$$ in the worst case (where there are no stars), as we store the result in a string that can grow up to the size of the input.

# Code
```cpp
class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            } else {
                if (!ans.empty()) {
                    ans.pop_back();
                } else {
                    ans.push_back(s[i]);
                }
            }
        }

        return ans;
    }
};
```

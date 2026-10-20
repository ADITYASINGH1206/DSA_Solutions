# [394. Decode String](https://leetcode.com/problems/decode-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `recursion`

---

## Problem Description
Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there will not be input like `3a` or `2[4]`.

The test cases are generated so that the length of the output will never exceed `105`.

**Example 1:**

```
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
```

**Example 2:**

```
Input: s = "3[a2[c]]"
Output: "accaccacc"
```

**Example 3:**

```
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

**Constraints:**

* `1 <= s.length <= 30`
* `s` consists of lowercase English letters, digits, and square brackets `'[]'`.
* `s` is guaranteed to be **a valid** input.
* All the integers in `s` are in the range `[1, 300]`.

---

## Solution & Editorial
# Intuition
The problem requires us to decode a nested string structure where segments are repeated based on preceding numbers. Because of the nested nature of brackets (`[...]`), a Last-In-First-Out (LIFO) data structure is naturally suited to preserve state when entering and exiting nested scopes.

# Approach
1. Maintain two stacks: `counts` to store the repetition multipliers (`k`), and `strs` to store the accumulated strings prior to encountering each opening bracket.
2. Maintain two working variables: `curr` to build the current string level, and `num` to parse potentially multi-digit integers.
3. Iterate through each character `c` in the string `s`:
   - If `c` is a digit, accumulate it into `num` using standard base-10 shifting (`num = num * 10 + (c - '0')`).
   - If `c` is `[`, push the current `num` onto `counts` and the current `curr` string onto `strs`, then reset both working variables.
   - If `c` is `]`, pop the top multiplier from `counts` and the previous string from `strs`. Append the current string `curr` to the previous string `repeat` times, and assign the result back to `curr`.
   - If `c` is a lowercase letter, append it directly to `curr`.
4. Return the fully resolved `curr` string.

### Visual Trace (Example 1: `s = "3[a]2[bc]"`)
| Character `c` | Action | `num` | `curr` | `counts` Stack | `strs` Stack |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `'3'` | `num = 3` | `3` | `""` | `[]` | `[]` |
| `'['` | Push state | `0` | `""` | `[3]` | `[""]` |
| `'a'` | Append to `curr` | `0` | `"a"` | `[3]` | `[""]` |
| `']'` | Pop & repeat | `0` | `"aaa"` | `[]` | `[]` |
| `'2'` | `num = 2` | `2` | `"aaa"` | `[]` | `[]` |
| `'['` | Push state | `0` | `""` | `[2]` | `["aaa"]` |
| `'b'` | Append to `curr` | `0` | `"b"` | `[2]` | `["aaa"]` |
| `'c'` | Append to `curr` | `0` | `"bc"` | `[2]` | `["aaa"]` |
| `']'` | Pop & repeat | `0` | `"aaabcbc"` | `[]` | `[]` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the output string. Each character in the decoded output is processed a constant number of times.
- Space complexity: $$O(M)$$, where $$M$$ is the maximum nesting depth or total number of bracketed segments occupying the stacks.

# Code
```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> strs;
        string curr = "";
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                counts.push(num);
                strs.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = counts.top();
                counts.pop();
                string prev = strs.top();
                strs.pop();
                while (repeat--) {
                    prev += curr;
                }
                curr = prev;
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};
```

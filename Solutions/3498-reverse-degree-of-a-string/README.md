# [3498. Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string/)
**Difficulty:** `Easy` | **Tags:** `string`, `simulation`

---

## Problem Description
Given a string `s`, calculate its **reverse degree**.

The **reverse degree** is calculated as follows:

1. For each character, multiply its position in the *reversed* alphabet (`'a'` = 26, `'b'` = 25, ..., `'z'` = 1) with its position in the string **(1-indexed)**.
2. Sum these products for all characters in the string.

Return the **reverse degree** of `s`.

**Example 1:**

**Input:** s = "abc"

**Output:** 148

**Explanation:**

| Letter | Index in Reversed Alphabet | Index in String | Product |
| --- | --- | --- | --- |
| `'a'` | 26 | 1 | 26 |
| `'b'` | 25 | 2 | 50 |
| `'c'` | 24 | 3 | 72 |

The reversed degree is `26 + 50 + 72 = 148`.

**Example 2:**

**Input:** s = "zaza"

**Output:** 160

**Explanation:**

| Letter | Index in Reversed Alphabet | Index in String | Product |
| --- | --- | --- | --- |
| `'z'` | 1 | 1 | 1 |
| `'a'` | 26 | 2 | 52 |
| `'z'` | 1 | 3 | 3 |
| `'a'` | 26 | 4 | 104 |

The reverse degree is `1 + 52 + 3 + 104 = 160`.

**Constraints:**

* `1 <= s.length <= 1000`
* `s` contains only lowercase English letters.

---

## Solution & Editorial
# Intuition
To calculate the reverse degree, we need to map each character to its reversed alphabet position and multiply it by its 1-indexed position in the string. Since the alphabet is fixed, we can derive the reversed position mathematically using the ASCII value of the character.

# Approach
1. Initialize a variable `ans` to 0 to store the cumulative sum.
2. Iterate through the string `s` using an index `i` from 0 to `s.size() - 1`.
3. For each character `s[i]`, calculate its reversed alphabet position: `26 - (s[i] - 'a')`. For example, if `s[i]` is 'a', the value is `26 - 0 = 26`. If `s[i]` is 'z', the value is `26 - 25 = 1`.
4. Multiply this value by the 1-indexed position `(i + 1)` and add the result to `ans`.
5. Return `ans` after the loop completes.

### Visual Trace (s = "abc")
| Iteration (i) | Char | Reversed Pos | 1-indexed Pos | Product | Total (ans) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 'a' | 26 | 1 | 26 | 26 |
| 1 | 'b' | 25 | 2 | 50 | 76 |
| 2 | 'c' | 24 | 3 | 72 | 148 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for the accumulator variable.

# Code
```cpp
class Solution {
public:
    int reverseDegree(string s) {
        int ans =0;
        for(int i =0;i<s.size();i++){
            int degree = (26-(s[i]-'a'))*(i+1);
            ans += degree;
        }
        return ans;
    }
};
```

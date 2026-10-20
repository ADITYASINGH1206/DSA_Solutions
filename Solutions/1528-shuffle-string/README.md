# [1528. Shuffle String](https://leetcode.com/problems/shuffle-string/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
You are given a string `s` and an integer array `indices` of the **same length**. The string `s` will be shuffled such that the character at the `ith` position moves to `indices[i]` in the shuffled string.

Return *the shuffled string*.

**Example 1:**

```
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
```

**Example 2:**

```
Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
```

**Constraints:**

* `s.length == indices.length == n`
* `1 <= n <= 100`
* `s` consists of only lowercase English letters.
* `0 <= indices[i] < n`
* All values of `indices` are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks us to rearrange characters of a string based on a provided permutation array. Since each index in the input string maps to exactly one unique position in the output string, we can construct the result by placing each character directly into its target index.

# Approach
1. Initialize a result string `ans` of the same length as the input string `s`.
2. Iterate through the input string using an index `i` from `0` to `n-1`.
3. For each character `s[i]`, place it into the `ans` string at the position specified by `indices[i]` (i.e., `ans[indices[i]] = s[i]`).
4. Return the fully populated `ans` string.

### Visual Trace (Example 1: s = "codeleet", indices = [4,5,6,7,0,2,1,3])
| Iteration (i) | s[i] | indices[i] | ans (state) |
| :--- | :--- | :--- | :--- |
| 0 | 'c' | 4 | "....c..." |
| 1 | 'o' | 5 | "....co.." |
| 2 | 'd' | 6 | "....cod." |
| 3 | 'e' | 7 | "....code" |
| 4 | 'l' | 0 | "l...code" |
| 5 | 'e' | 2 | "l.e.code" |
| 6 | 'e' | 1 | "lee.code" |
| 7 | 't' | 3 | "leetcode" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass over the input array to map characters to their new positions.
- Space complexity: $$O(N)$$ to store the resulting string `ans`.

# Code
```cpp
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        for(int i =0;i<s.size();i++){
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};
```

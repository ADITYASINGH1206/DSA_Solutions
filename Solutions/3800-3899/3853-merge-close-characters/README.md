# [3853. Merge Close Characters](https://leetcode.com/problems/merge-close-characters/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `simulation`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters and an integer `k`.

Two **equal** characters in the **current** string `s` are considered **close** if the distance between their indices is **at most** `k`.

When two characters are **close**, the right one merges into the left. Merges happen **one at a time**, and after each merge, the string updates until no more merges are possible.

Return the resulting string after performing all possible merges.

**Note**: If multiple merges are possible, always merge the pair with the **smallest left** index. If multiple pairs share the smallest left index, choose the pair with the **smallest right** index.

**Example 1:**

**Input:** s = "abca", k = 3

**Output:** "abc"

**Explanation:**

* **​​​​​​​**Characters `'a'` at indices `i = 0` and `i = 3` are close as `3 - 0 = 3 <= k`.
* Merge them into the left `'a'` and `s = "abc"`.
* No other equal characters are close, so no further merges occur.

**Example 2:**

**Input:** s = "aabca", k = 2

**Output:** "abca"

**Explanation:**

* Characters `'a'` at indices `i = 0` and `i = 1` are close as `1 - 0 = 1 <= k`.
* Merge them into the left `'a'` and `s = "abca"`.
* Now the remaining `'a'` characters at indices `i = 0` and `i = 3` are not close as `k < 3`, so no further merges occur.

**Example 3:**

**Input:** s = "yybyzybz", k = 2

**Output:** "ybzybz"

**Explanation:**

* Characters `'y'` at indices `i = 0` and `i = 1` are close as `1 - 0 = 1 <= k`.
* Merge them into the left `'y'` and `s = "ybyzybz"`.
* Now the characters `'y'` at indices `i = 0` and `i = 2` are close as `2 - 0 = 2 <= k`.
* Merge them into the left `'y'` and `s = "ybzybz"`.
* No other equal characters are close, so no further merges occur.

**Constraints:**

* `1 <= s.length <= 100`
* `1 <= k <= s.length`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem requires us to repeatedly find and merge the first available pair of identical characters that are within distance `k`. Since the constraints are small (string length up to 100), a direct simulation of the merge process is efficient enough to pass within time limits.

# Approach
1. Use a `while` loop to repeatedly scan the string for potential merges.
2. Inside, use nested loops: the outer loop `i` iterates through the string, and the inner loop `j` checks characters from `i + 1` up to `i + k`.
3. If `s[i] == s[j]`, we have found the first valid merge pair based on the problem's priority (smallest `i`, then smallest `j`).
4. Perform `s.erase(j, 1)` to remove the character at index `j`, set a flag `foundMerge` to `true`, and break out of the loops to restart the search on the updated string.
5. If no merges are found in a full pass, terminate the `while` loop.

### Visual Trace (Example 3: s = "yybyzybz", k = 2)
| Iteration | Current String | Pair Found (i, j) | Action |
| :--- | :--- | :--- | :--- |
| 1 | "yybyzybz" | (0, 1) | Erase index 1 |
| 2 | "ybyzybz" | (0, 2) | Erase index 2 |
| 3 | "ybzybz" | None | Terminate |

# Complexity
- Time complexity: $$O(N^3)$$, where $$N$$ is the length of the string. In each of the at most $$N$$ merge steps, we perform a scan of the string ($$O(N^2)$$) and an erasure ($$O(N)$$).
- Space complexity: $$O(N)$$ to store the modified string.

# Code
```cpp
class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool foundMerge = true;
        while (foundMerge) {
            foundMerge = false;
            for (int i = 0; i < s.length(); ++i) {
                for (int j = i + 1; j <= i + k && j < s.length(); ++j) {
                    if (s[i] == s[j]) {
                        s.erase(j, 1);
                        foundMerge = true;
                        break; 
                    }
                }
                if (foundMerge) {
                    break;
                }
            }
        }
        
        return s;
    }
};
```

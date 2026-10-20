# [1684. Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`, `bit-manipulation`, `counting`

---

## Problem Description
You are given a string `allowed` consisting of **distinct** characters and an array of strings `words`. A string is **consistent** if all characters in the string appear in the string `allowed`.

Return *the number of **consistent** strings in the array* `words`.

**Example 1:**

```
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
```

**Example 2:**

```
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
```

**Example 3:**

```
Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
```

**Constraints:**

* `1 <= words.length <= 104`
* `1 <= allowed.length <= 26`
* `1 <= words[i].length <= 10`
* The characters in `allowed` are **distinct**.
* `words[i]` and `allowed` contain only lowercase English letters.

---

## Solution & Editorial
# Intuition
To determine if a string is consistent, we need to check if every character in the string exists within the `allowed` set. Since the input consists only of lowercase English letters, a boolean array of size 26 provides an $O(1)$ lookup mechanism, making the verification process highly efficient.

# Approach
1. Initialize a boolean array `isAllowed` of size 26 to `false`. Iterate through the `allowed` string and mark the indices corresponding to each character (using `c - 'a'`) as `true`.
2. Initialize `count` to the total number of words in the input array. We assume all words are consistent initially.
3. Iterate through each `word` in `words`. For each character `c` in the `word`, check if `isAllowed[c - 'a']` is `false`.
4. If a character is not allowed, decrement the `count` and immediately `break` the inner loop to move to the next word.

### Visual Trace (Example 1: allowed = "ab", words = ["ad", "bd", "aaab"])
| Word | Char | Allowed? | Action |
| :--- | :--- | :--- | :--- |
| "ad" | 'a' | Yes | Continue |
| "ad" | 'd' | No | count--, break |
| "bd" | 'b' | Yes | Continue |
| "bd" | 'd' | No | count--, break |
| "aaab" | 'a', 'a', 'a', 'b' | All Yes | Keep count |

# Complexity
- Time complexity: $$O(N + M)$$, where $N$ is the length of `allowed` and $M$ is the total number of characters across all strings in `words`. We traverse `allowed` once and each character in `words` at most once.
- Space complexity: $$O(1)$$, as the boolean array `isAllowed` is fixed at size 26, regardless of the input size.

# Code
```cpp
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool isAllowed[26] = {false};
        for (char c : allowed) {
            isAllowed[c - 'a'] = true;
        }
        
        int count = words.size();
        
        for (const string& word : words) {
            for (char c : word) {
                if (!isAllowed[c - 'a']) {
                    count--; 
                    break;   
                }
            }
        }
        
        return count;
    }
};
```

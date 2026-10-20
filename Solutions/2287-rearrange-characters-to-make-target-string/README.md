# [2287. Rearrange Characters to Make Target String](https://leetcode.com/problems/rearrange-characters-to-make-target-string/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `counting`

---

## Problem Description
You are given two **0-indexed** strings `s` and `target`. You can take some letters from `s` and rearrange them to form new strings.

Return *the **maximum** number of copies of* `target` *that can be formed by taking letters from* `s` *and rearranging them.*

**Example 1:**

```
Input: s = "ilovecodingonleetcode", target = "code"
Output: 2
Explanation:
For the first copy of "code", take the letters at indices 4, 5, 6, and 7.
For the second copy of "code", take the letters at indices 17, 18, 19, and 20.
The strings that are formed are "ecod" and "code" which can both be rearranged into "code".
We can make at most two copies of "code", so we return 2.
```

**Example 2:**

```
Input: s = "abcba", target = "abc"
Output: 1
Explanation:
We can make one copy of "abc" by taking the letters at indices 0, 1, and 2.
We can make at most one copy of "abc", so we return 1.
Note that while there is an extra 'a' and 'b' at indices 3 and 4, we cannot reuse the letter 'c' at index 2, so we cannot make a second copy of "abc".
```

**Example 3:**

```
Input: s = "abbaccaddaeea", target = "aaaaa"
Output: 1
Explanation:
We can make one copy of "aaaaa" by taking the letters at indices 0, 3, 6, 9, and 12.
We can make at most one copy of "aaaaa", so we return 1.
```

**Constraints:**

* `1 <= s.length <= 100`
* `1 <= target.length <= 10`
* `s` and `target` consist of lowercase English letters.

**Note:** This question is the same as  [1189: Maximum Number of Balloons.](https://leetcode.com/problems/maximum-number-of-balloons/description/)

---

## Solution & Editorial
# Intuition
To form multiple copies of the `target` string, we must ensure that for every character present in `target`, the string `s` contains at least that many occurrences of that character. The bottleneck for the total number of copies is determined by the character that appears most frequently in `target` relative to its availability in `s`.

# Approach
1. Count the frequency of each character in `s` using an array `freq` of size 26.
2. Count the frequency of each character in `target` using an array `freq1` of size 26.
3. Iterate through all 26 possible lowercase English letters. For every character `i` that exists in `target` (`freq1[i] > 0`), calculate how many full copies of that specific character can be supported by `s` using integer division: `freq[i] / freq1[i]`.
4. The final answer is the minimum of these ratios across all characters present in `target`, as the limiting character dictates the maximum number of full `target` strings we can construct.

### Visual Trace (Example 1: s = "ilovecodingonleetcode", target = "code")
| Char | freq (s) | freq1 (target) | Ratio (freq/freq1) |
| :--- | :--- | :--- | :--- |
| c | 2 | 1 | 2/1 = 2 |
| o | 4 | 1 | 4/1 = 4 |
| d | 2 | 1 | 2/1 = 2 |
| e | 4 | 1 | 4/1 = 4 |

Result: min(2, 4, 2, 4) = 2.

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the length of `s` and $$M$$ is the length of `target`. We iterate through `s` once to populate `freq` and `target` once to populate `freq1`, followed by a constant time loop of size 26.
- Space complexity: $$O(1)$$, as we use two fixed-size arrays of length 26 regardless of the input size.

# Code
```cpp
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int freq[26] = {0};
        int freq1[26] = {0};
        int ans = INT_MAX;
    
        for(char ch : s) {
            freq[ch - 'a']++;
        }
    
        for(char ch : target) {
            freq1[ch - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(freq1[i] > 0) {
                ans = min(ans, freq[i] / freq1[i]);
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};
```

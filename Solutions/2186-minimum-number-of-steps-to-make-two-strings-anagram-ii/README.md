# [2186. Minimum Number of Steps to Make Two Strings Anagram II](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `counting`

---

## Problem Description
You are given two strings `s` and `t`. In one step, you can append **any character** to either `s` or `t`.

Return *the minimum number of steps to make* `s` *and* `t` ***anagrams** of each other.*

An **anagram** of a string is a string that contains the same characters with a different (or the same) ordering.

**Example 1:**

```
Input: s = "leetcode", t = "coats"
Output: 7
Explanation: 
- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcodeas".
- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coatsleede".
"leetcodeas" and "coatsleede" are now anagrams of each other.
We used a total of 2 + 5 = 7 steps.
It can be shown that there is no way to make them anagrams of each other with less than 7 steps.
```

**Example 2:**

```
Input: s = "night", t = "thing"
Output: 0
Explanation: The given strings are already anagrams of each other. Thus, we do not need any further steps.
```

**Constraints:**

* `1 <= s.length, t.length <= 2 * 105`
* `s` and `t` consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
To make two strings anagrams, they must have the exact same character counts. The minimum number of steps required is the sum of the absolute differences between the character frequencies of the two strings, as each difference represents a character that must be added to one string to match the count in the other.

# Approach
1. Initialize a frequency array `freq` of size 26 to store the net difference in character counts between string `s` and string `t`.
2. Iterate through string `s` and increment the corresponding index in `freq` for each character.
3. Iterate through string `t` and decrement the corresponding index in `freq` for each character.
4. The absolute value of `freq[i]` represents the number of characters of type `i` that are missing in either `s` or `t` to achieve parity.
5. Sum the absolute values of all elements in `freq` to get the total number of steps.

### Visual Trace (Example 1: s = "leetcode", t = "coats")
| Char | s count | t count | Net (s-t) | Abs Diff |
| :--- | :--- | :--- | :--- | :--- |
| a | 0 | 1 | -1 | 1 |
| c | 2 | 1 | 1 | 1 |
| d | 1 | 0 | 1 | 1 |
| e | 3 | 1 | 2 | 2 |
| l | 1 | 0 | 1 | 1 |
| o | 1 | 1 | 0 | 0 |
| s | 0 | 1 | -1 | 1 |
| t | 1 | 1 | 0 | 0 |
| **Total** | | | | **7** |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of strings `s` and `t` respectively. We traverse each string exactly once.
- Space complexity: $$O(1)$$, as the frequency array is fixed at size 26 regardless of the input string lengths.

# Code
```cpp
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(char ch:t){
            freq[ch-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=abs(freq[i]);
        }
        return ans;
    }
};
```

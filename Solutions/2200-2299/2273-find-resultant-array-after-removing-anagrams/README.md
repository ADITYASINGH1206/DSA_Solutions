# [2273. Find Resultant Array After Removing Anagrams](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`, `sorting`

---

## Problem Description
You are given a **0-indexed** string array `words`, where `words[i]` consists of lowercase English letters.

In one operation, select any index `i` such that `0 < i < words.length` and `words[i - 1]` and `words[i]` are **anagrams**, and **delete** `words[i]` from `words`. Keep performing this operation as long as you can select an index that satisfies the conditions.

Return `words` *after performing all operations*. It can be shown that selecting the indices for each operation in **any** arbitrary order will lead to the same result.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, `"dacb"` is an anagram of `"abdc"`.

**Example 1:**

```
Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
Explanation:
One of the ways we can obtain the resultant array is by using the following operations:
- Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","baba","cd","cd"].
- Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
  Now words = ["abba","cd","cd"].
- Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
  Now words = ["abba","cd"].
We can no longer perform any operations, so ["abba","cd"] is the final answer.
```

**Example 2:**

```
Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]
Explanation:
No two adjacent strings in words are anagrams of each other, so no operations are performed.
```

**Constraints:**

* `1 <= words.length <= 100`
* `1 <= words[i].length <= 10`
* `words[i]` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
Two strings are anagrams if and only if they have the exact same character frequency distribution. By pre-calculating the frequency map for every word in the input array, we can determine if two adjacent words are anagrams in constant time (relative to the number of words) by comparing their frequency maps.

# Approach
1. Initialize a vector of `unordered_map<char, int>` to store the character counts for each word in `words`.
2. Iterate through each string in `words` and populate the corresponding frequency map.
3. Create a result vector `ans` and initialize it with the first word, as it can never be removed.
4. Iterate from the second word to the end. Compare the current word's frequency map with the previous word's frequency map. If they are not equal, the current word is not an anagram of the last kept word, so append it to `ans`.

### Visual Trace (Example 1: ["abba", "baba", "bbaa", "cd", "cd"])
| Index | Word | Frequency Map | Keep? |
| :--- | :--- | :--- | :--- |
| 0 | "abba" | {a:2, b:2} | Yes (Initial) |
| 1 | "baba" | {a:2, b:2} | No (Matches index 0) |
| 2 | "bbaa" | {a:2, b:2} | No (Matches index 1) |
| 3 | "cd" | {c:1, d:1} | Yes (Differs from index 2) |
| 4 | "cd" | {c:1, d:1} | No (Matches index 3) |

# Complexity
- Time complexity: $$O(N \cdot L)$$, where $$N$$ is the number of words and $$L$$ is the maximum length of a word. We iterate through each character of every word once to build the maps, and then perform $$N-1$$ map comparisons.
- Space complexity: $$O(N \cdot L)$$, as we store a frequency map for each of the $$N$$ words, where each map contains at most $$L$$ unique characters.

# Code
```cpp
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<unordered_map<char, int>> freq(words.size());

        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i]) freq[i][ch]++;
        }

        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            if (freq[i] != freq[i - 1]) ans.push_back(words[i]);
        }
        return ans;
    }
};
```

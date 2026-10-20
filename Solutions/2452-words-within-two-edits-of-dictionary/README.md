# [2452. Words Within Two Edits of Dictionary](https://leetcode.com/problems/words-within-two-edits-of-dictionary/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `trie`

---

## Problem Description
You are given two string arrays, `queries` and `dictionary`. All words in each array comprise of lowercase English letters and have the same length.

In one **edit** you can take a word from `queries`, and change any letter in it to any other letter. Find all words from `queries` that, after a **maximum** of two edits, equal some word from `dictionary`.

Return *a list of all words from* `queries`*,* *that match with some word from* `dictionary` *after a maximum of **two edits***. Return the words in the **same order** they appear in `queries`.

**Example 1:**

```
Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
Output: ["word","note","wood"]
Explanation:
- Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood".
- Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
- It would take more than 2 edits for "ants" to equal a dictionary word.
- "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
Thus, we return ["word","note","wood"].
```

**Example 2:**

```
Input: queries = ["yes"], dictionary = ["not"]
Output: []
Explanation:
Applying any two edits to "yes" cannot make it equal to "not". Thus, we return an empty array.
```

**Constraints:**

* `1 <= queries.length, dictionary.length <= 100`
* `n == queries[i].length == dictionary[j].length`
* `1 <= n <= 100`
* All `queries[i]` and `dictionary[j]` are composed of lowercase English letters.

---

## Solution & Editorial
# Intuition
Since the constraints are small ($N, Q, D \le 100$), we can directly compare each query word against every word in the dictionary. The problem defines an "edit" as changing a character at a specific position. Thus, two words are within two edits if they differ in at most two positions.

# Approach
1. Iterate through each query word `s` in `queries`.
2. For each `s`, iterate through every word `t` in `dictionary`.
3. Calculate the Hamming distance between `s` and `t` by counting the number of indices `i` where `s[i] != t[i]`.
4. If the count is less than or equal to 2, the query word `s` satisfies the condition. Add it to the result list and immediately break the inner loop to avoid redundant checks for the same query.

### Visual Trace (Example 1)
`queries = ["word", "note"], dictionary = ["wood", "joke"]`

| Query | Dictionary Word | Mismatches | Valid? | Action |
| :--- | :--- | :--- | :--- | :--- |
| "word" | "wood" | 1 ('r' vs 'o') | Yes | Add "word", Break |
| "note" | "wood" | 4 | No | Continue |
| "note" | "joke" | 2 ('n' vs 'j', 't' vs 'k') | Yes | Add "note", Break |

# Complexity
- Time complexity: $$O(Q \cdot D \cdot N)$$, where $$Q$$ is the number of queries, $$D$$ is the number of dictionary words, and $$N$$ is the length of the words. Given the constraints ($100^3 = 10^6$), this is well within the time limit.
- Space complexity: $$O(1)$$ auxiliary space (excluding the output vector), as we only use a counter variable.

# Code
```cpp
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& s : queries) {
            for (auto& t : dictionary) {
                int cnt = 0;
                for (int i = 0; i < s.size(); ++i) {
                    cnt += s[i] != t[i];
                }
                if (cnt < 3) {
                    ans.emplace_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};
```

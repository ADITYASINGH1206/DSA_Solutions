# [3545. Minimum Deletions for At Most K Distinct Characters](https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `greedy`, `sorting`, `counting`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters, and an integer `k`.

Your task is to delete some (possibly none) of the characters in the string so that the number of **distinct** characters in the resulting string is **at most** `k`.

Return the **minimum** number of deletions required to achieve this.

**Example 1:**

**Input:** s = "abc", k = 2

**Output:** 1

**Explanation:**

* `s` has three distinct characters: `'a'`, `'b'` and `'c'`, each with a frequency of 1.
* Since we can have at most `k = 2` distinct characters, remove all occurrences of any one character from the string.
* For example, removing all occurrences of `'c'` results in at most `k` distinct characters. Thus, the answer is 1.

**Example 2:**

**Input:** s = "aabb", k = 2

**Output:** 0

**Explanation:**

* `s` has two distinct characters (`'a'` and `'b'`) with frequencies of 2 and 2, respectively.
* Since we can have at most `k = 2` distinct characters, no deletions are required. Thus, the answer is 0.

**Example 3:**

**Input:** s = "yyyzz", k = 1

**Output:** 2

**Explanation:**

* `s` has two distinct characters (`'y'` and `'z'`) with frequencies of 3 and 2, respectively.
* Since we can have at most `k = 1` distinct character, remove all occurrences of any one character from the string.
* Removing all `'z'` results in at most `k` distinct characters. Thus, the answer is 2.

**Constraints:**

* `1 <= s.length <= 16`
* `1 <= k <= 16`
* `s` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
To minimize the number of deletions required to keep at most `k` distinct characters, we should prioritize keeping the characters that appear most frequently. By removing the characters with the lowest frequencies first, we satisfy the constraint while minimizing the total count of deleted characters.

# Approach
1. Count the frequency of each character in the string `s` using a hash map (`unordered_map<char, int> mp`).
2. Extract all frequencies into a vector `freqs`.
3. Sort the `freqs` vector in descending order. This ensures that the most frequent characters appear at the beginning of the vector.
4. If the number of distinct characters (size of `freqs`) is greater than `k`, sum the frequencies of all characters from index `k` to the end of the vector. These are the characters we must delete.

### Visual Trace (s = "yyyzz", k = 1)
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Count Frequencies | {'y': 3, 'z': 2} |
| 2 | Extract Frequencies | [3, 2] |
| 3 | Sort Descending | [3, 2] |
| 4 | Sum from index k=1 | ans = 2 |

# Complexity
- Time complexity: $$O(N + D \log D)$$, where $$N$$ is the length of the string and $$D$$ is the number of distinct characters (at most 26). Since $$D$$ is constant, this is effectively $$O(N)$$.
- Space complexity: $$O(D)$$, which is constant space $$O(1)$$ as there are at most 26 lowercase English letters.

# Code
```cpp
class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }
        vector<int> freqs;
        for(auto& pair : mp) {
            freqs.push_back(pair.second);
        }
        sort(freqs.begin(), freqs.end(), greater<int>());
        int ans = 0;
        for(int i = k; i < freqs.size(); i++) {
            ans += freqs[i];
        }

        return ans;
    }
};
```

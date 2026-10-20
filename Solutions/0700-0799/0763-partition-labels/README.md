# [763. Partition Labels](https://leetcode.com/problems/partition-labels/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `two-pointers`, `string`, `greedy`

---

## Problem Description
You are given a string `s`. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string `"ababcc"` can be partitioned into `["abab", "cc"]`, but partitions such as `["aba", "bcc"]` or `["ab", "ab", "cc"]` are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be `s`.

Return *a list of integers representing the size of these parts*.

**Example 1:**

```
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
```

**Example 2:**

```
Input: s = "eccbbbbdec"
Output: [10]
```

**Constraints:**

* `1 <= s.length <= 500`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To partition the string such that each character appears in at most one part while maximizing the number of partitions, we need to know the furthest occurrence of each character. Once we start a partition containing a specific character, the partition cannot end until we have included all occurrences of every character currently seen. This naturally lends itself to a greedy approach using pre-calculated last positions.

# Approach
1. First, record the last occurrence index of each lowercase English letter by iterating through the string `s` and storing it in a fixed-size vector `last` of size 26.
2. Initialize two pointers, `start = 0` and `end = 0`, along with an empty result vector `ans`.
3. Iterate through the string `s` with index `i`. Update `end` to be the maximum of its current value and the last occurrence of the current character `s[i]`.
4. When the current index `i` matches `end`, we have reached the end of the current valid partition. Compute its size as `end - start + 1`, push it to `ans`, and set `start = i + 1` for the next partition.
5. Return `ans` once the loop completes.

### Visual Trace Walkthrough (Example 1: `s = "ababcbaca..."`)
- Precomputing `last` gives the final index for each character (e.g., `'a'` -> 8, `'b'` -> 5, `'c'` -> 7).
- `i = 0 ('a')`: `end = max(0, 8) = 8`. `i != end`.
- `i = 1 ('b')`: `end = max(8, 5) = 8`. `i != end`.
- ...
- `i = 8 ('a')`: `end = max(8, 8) = 8`. `i == end` is true! Push partition size `8 - 0 + 1 = 9` to `ans`. Set `start = 9`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of string `s`. We make two passes over the string: one to record the last indices and one to compute the partitions.
- Space complexity: $$O(1)$$, as the `last` array requires a constant auxiliary storage of size 26.

# Code
```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        vector<int> ans;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};
```

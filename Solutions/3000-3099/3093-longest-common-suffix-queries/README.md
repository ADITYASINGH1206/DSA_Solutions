# [3093. Longest Common Suffix Queries](https://leetcode.com/problems/longest-common-suffix-queries/)
**Difficulty:** `Hard` | **Tags:** `array`, `string`, `trie`

---

## Problem Description
You are given two arrays of strings `wordsContainer` and `wordsQuery`.

For each `wordsQuery[i]`, you need to find a string from `wordsContainer` that has the **longest common suffix** with `wordsQuery[i]`. If there are two or more strings in `wordsContainer` that share the longest common suffix, find the string that is the **smallest** in length. If there are two or more such strings that have the **same** smallest length, find the one that occurred **earlier** in `wordsContainer`.

Return *an array of integers* `ans`*, where* `ans[i]` *is the index of the string in* `wordsContainer` *that has the **longest common suffix** with* `wordsQuery[i]`*.*

**Example 1:**

**Input:** wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

**Output:** [1,1,1]

**Explanation:**

Let's look at each `wordsQuery[i]` separately:

* For `wordsQuery[0] = "cd"`, strings from `wordsContainer` that share the longest common suffix `"cd"` are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
* For `wordsQuery[1] = "bcd"`, strings from `wordsContainer` that share the longest common suffix `"bcd"` are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
* For `wordsQuery[2] = "xyz"`, there is no string from `wordsContainer` that shares a common suffix. Hence the longest common suffix is `""`, that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.

**Example 2:**

**Input:** wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]

**Output:** [2,0,2]

**Explanation:**

Let's look at each `wordsQuery[i]` separately:

* For `wordsQuery[0] = "gh"`, strings from `wordsContainer` that share the longest common suffix `"gh"` are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
* For `wordsQuery[1] = "acbfgh"`, only the string at index 0 shares the longest common suffix `"fgh"`. Hence it is the answer, even though the string at index 2 is shorter.
* For `wordsQuery[2] = "acbfegh"`, strings from `wordsContainer` that share the longest common suffix `"gh"` are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.

**Constraints:**

* `1 <= wordsContainer.length, wordsQuery.length <= 104`
* `1 <= wordsContainer[i].length <= 5 * 103`
* `1 <= wordsQuery[i].length <= 5 * 103`
* `wordsContainer[i]` consists only of lowercase English letters.
* `wordsQuery[i]` consists only of lowercase English letters.
* Sum of `wordsContainer[i].length` is at most `5 * 105`.
* Sum of `wordsQuery[i].length` is at most `5 * 105`.

---

## Solution & Editorial
# Intuition
To efficiently find the longest common suffix, we can treat the suffixes of all strings in `wordsContainer` as prefixes by reversing them. A Trie is the ideal data structure here, as it allows us to traverse the suffix character by character. By storing the index of the "best" string (shortest length, then earliest occurrence) at each node in the Trie, we can answer queries in time proportional to the length of the query string.

# Approach
1. **Trie Construction**: Define a `TrieNode` containing an array of 26 children and metadata (`bestLen`, `bestIdx`) to track the optimal string index for the path ending at that node.
2. **Insertion**: For each string in `wordsContainer`, traverse its characters in reverse order. At every node visited, update `bestLen` and `bestIdx` if the current string is shorter than the stored `bestLen`, or if lengths are equal and the current index is smaller.
3. **Querying**: For each `wordsQuery`, traverse the Trie in reverse order of the query string. Continue moving down the Trie as long as the current character exists as a child. The `bestIdx` stored at the last reachable node represents the optimal string index.

### Visual Trace (Example 1: `wordsContainer = ["abcd", "bcd", "xbcd"]`)
- Root node stores `bestIdx = 1` (length 3).
- Insert "abcd": Path `d -> c -> b -> a`. All nodes update `bestIdx` to 0.
- Insert "bcd": Path `d -> c -> b`. Nodes update `bestIdx` to 1 (length 3 < 4).
- Insert "xbcd": Path `d -> c -> b -> x`. Nodes update `bestIdx` to 1 (length 3 < 4).
- Query "cd": Traverse `d -> c`. Reach node `c`, which stores `bestIdx = 1`.

# Complexity
- Time complexity: $$O(\sum |wordsContainer_i| + \sum |wordsQuery_i|)$$. We process every character of every string in the container and every query exactly once.
- Space complexity: $$O(\sum |wordsContainer_i| \times 26)$$. In the worst case, every character in `wordsContainer` creates a new node in the Trie.

# Code
```cpp
class Solution {
    struct TrieNode {
        int children[26];
        int bestLen;
        int bestIdx;
        
        TrieNode() {
            fill(begin(children), end(children), -1);
            bestLen = 1e9;
            bestIdx = 1e9;
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<TrieNode> trie;
        trie.emplace_back();
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            int len = wordsContainer[i].length();
            int curr = 0;
            
            if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
                trie[curr].bestLen = len;
                trie[curr].bestIdx = i;
            }
            
            for (int j = len - 1; j >= 0; j--) {
                int charIdx = wordsContainer[i][j] - 'a';
                
                if (trie[curr].children[charIdx] == -1) {
                    trie[curr].children[charIdx] = trie.size();
                    trie.emplace_back();
                }
                
                curr = trie[curr].children[charIdx];
                
                if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
                    trie[curr].bestLen = len;
                    trie[curr].bestIdx = i;
                }
            }
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& query : wordsQuery) {
            int curr = 0;
            int len = query.length();
            
            for (int j = len - 1; j >= 0; j--) {
                int charIdx = query[j] - 'a';
                if (trie[curr].children[charIdx] == -1) {
                    break;
                }
                curr = trie[curr].children[charIdx];
            }
            ans.push_back(trie[curr].bestIdx);
        }
        
        return ans;
    }
};
```

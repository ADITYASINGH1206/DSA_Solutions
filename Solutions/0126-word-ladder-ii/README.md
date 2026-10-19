# [126. Word Ladder II](https://leetcode.com/problems/word-ladder-ii/)
**Difficulty:** `Hard` | **Tags:** `hash-table`, `string`, `backtracking`, `breadth-first-search`, `bidirectional-search`

---

## Problem Description
A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

* Every adjacent pair of words differs by a single letter.
* Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
* `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *all the **shortest transformation sequences** from* `beginWord` *to* `endWord`*, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words* `[beginWord, s1, s2, ..., sk]`.

**Example 1:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
```

**Example 2:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

**Constraints:**

* `1 <= beginWord.length <= 5`
* `endWord.length == beginWord.length`
* `1 <= wordList.length <= 500`
* `wordList[i].length == beginWord.length`
* `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
* `beginWord != endWord`
* All the words in `wordList` are **unique**.
* The **sum** of all shortest transformation sequences does not exceed `105`.

---

## Solution & Editorial
# Intuition
To find all shortest transformation sequences, we can first compute the shortest distance from the `beginWord` to every reachable word using Breadth-First Search (BFS). Once we record the minimum steps for each word in a hash map, we can backtrack using Depth-First Search (DFS) from the `endWord` back to the `beginWord` by strictly following decreasing step counts to reconstruct all valid paths.

# Approach
1. Store all words from `wordList` in a hash set `st` for $$O(1)$$ lookups. Initialize a queue `q` for BFS and a hash map `mpp` to store the shortest distance (number of steps) from `beginWord` to each visited word.
2. Push `beginWord` into `q`, set `mpp[beginWord] = 1`, and remove it from `st`. 
3. While `q` is not empty, pop the front word and generate all possible single-character mutations. If a mutated word exists in `st`, push it into the queue, remove it from `st`, and record its step count as `steps + 1`.
4. Stop BFS early or continue until `endWord` is processed. If `endWord` has an entry in `mpp`, invoke a DFS helper starting from `endWord` with a path sequence vector.
5. In the DFS function, if the current word matches `beginWord`, reverse the accumulated sequence and store it in the global `ans` matrix. Otherwise, try all single-character mutations of the current word and recurse into any neighbor whose step count in `mpp` is exactly `steps - 1`.

### Visual Walkthrough (Example 1)
- `beginWord = "hit"`, `endWord = "cog"`, `wordList = ["hot","dot","dog","lot","log","cog"]`
- **BFS Phase:**
  - Queue: `["hit"]`, `mpp`: `{"hit": 1}`
  - Pop `"hit"`: Generates `"hot"`. Queue: `["hot"]`, `mpp`: `{"hit": 1, "hot": 2}`
  - Pop `"hot"`: Generates `"dot"`, `"lot"`. Queue: `["dot", "lot"]`, `mpp`: `{"...", "dot": 3, "lot": 3}`
  - Pop `"dot"`: Generates `"dog"`. Queue: `["lot", "dog"]`, `mpp`: `{"...", "dog": 4}`
  - Pop `"lot"`: Generates `"log"`. Queue: `["dog", "log"]`, `mpp`: `{"...", "log": 4}`
  - Pop `"dog"`: Generates `"cog"`. Queue: `["log", "cog"]`, `mpp`: `{"...", "cog": 5}`
- **DFS Phase (Backtracking from `"cog"`):**
  - `"cog"` (step 5) -> looks for neighbors at step 4 (`"dog"`, `"log"`).
  - Path 1: `"cog" -> "dog" -> "dot" -> "hot" -> "hit"`. Reversed: `["hit", "hot", "dot", "dog", "cog"]`.
  - Path 2: `"cog" -> "log" -> "lot" -> "hot" -> "hit"`. Reversed: `["hit", "hot", "lot", "log", "cog"]`.

# Complexity
- Time complexity: $$O(N \cdot 26^L + K)$$, where $$N$$ is the number of words in `wordList`, $$L$$ is the length of each word, and $$K$$ is the total number of paths generated. The BFS explores each word and generates $$26 \times L$$ mutations. The DFS traverses valid paths backwards.
- Space complexity: $$O(N)$$ to store the hash set `st`, distance map `mpp`, BFS queue, and DFS recursion call stack.

# Code
```cpp
class Solution {
    unordered_map<string, int> mpp; 
    vector<vector<string>> ans;
    string beginW;

public:
    void dfs(string word, vector<string>& seq) {
        if (word == beginW) {
            vector<string> path = seq;
            reverse(path.begin(), path.end()); 
            ans.push_back(path);
            return;
        }
        
        int steps = mpp[word]; 
        
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); 
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        beginW = beginWord;
        
        q.push(beginWord);
        mpp[beginWord] = 1; 
        st.erase(beginWord);
        
        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            
            if (word == endWord) break;
            
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word); 
                        mpp[word] = steps + 1; 
                    }
                }
                word[i] = original;
            }
        }
        
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        
        return ans;
    }
};
```

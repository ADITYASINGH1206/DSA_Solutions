# [127. Word Ladder](https://leetcode.com/problems/word-ladder/)
**Difficulty:** `Hard` | **Tags:** `hash-table`, `string`, `breadth-first-search`, `bidirectional-search`

---

## Problem Description
A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

* Every adjacent pair of words differs by a single letter.
* Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
* `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *the **number of words** in the **shortest transformation sequence** from* `beginWord` *to* `endWord`*, or* `0` *if no such sequence exists.*

**Example 1:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

**Example 2:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

**Constraints:**

* `1 <= beginWord.length <= 10`
* `endWord.length == beginWord.length`
* `1 <= wordList.length <= 5000`
* `wordList[i].length == beginWord.length`
* `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.
* `beginWord != endWord`
* All the words in `wordList` are **unique**.

---

## Solution & Editorial
# Intuition
To find the shortest transformation sequence from `beginWord` to `endWord`, we can model the problem as an unweighted graph where each word represents a node and valid single-character transformations represent edges. Breadth-First Search (BFS) is optimal here because it guarantees the shortest path in an unweighted graph.

# Approach
1. Initialize a `queue<pair<string, int>> q` to store the current word and its transformation distance (starting with `{beginWord, 1}`).
2. Insert all words from `wordList` into an `unordered_set<string> st` for $$O(1)$$ average-time lookups and deletions.
3. While the queue is not empty, pop the front element containing `word` and its depth `ans`.
4. If `word` matches `endWord`, return `ans` immediately.
5. For each character position `i` in `word`, try replacing it with every letter from `'a'` to `'z'`.
6. If the newly formed word exists in `st`, erase it to prevent re-visiting and push `{word, ans + 1}` into the queue.
7. If the queue is exhausted without finding `endWord`, return `0`.

### Visual Walkthrough (Example 1)
`beginWord` = "hit", `endWord` = "cog", `wordList` = ["hot","dot","dog","lot","log","cog"]

| Queue State (Front) | Depth (`ans`) | Generated Neighbors Checked | Valid Neighbors Found & Pushed | Set (`st`) State |
| :--- | :--- | :--- | :--- | :--- |
| `("hit", 1)` | 1 | `"ait"`...`"hot"` | `"hot"` | `{"dot","dog","lot","log","cog"}` |
| `("hot", 2)` | 2 | `"hat"`...`"dot"`, `"lot"` | `"dot", "lot"` | `{"dog","log","cog"}` |
| `("dot", 3)` | 3 | `"dat"`...`"dog"` | `"dog"` | `{"log","cog"}` |
| `("lot", 3)` | 3 | `"lat"`...`"log"` | `"log"` | `{"cog"}` |
| `("dog", 4)` | 4 | `"dag"`...`"cog"` | `"cog"` | `{}` |
| `("cog", 5)` | 5 | Matches `endWord` | Return `5` | `{}` |

# Complexity
- Time complexity: $$O(M^2 \cdot N)$$, where $$N$$ is the number of words in `wordList` and $$M$$ is the length of each word. For each of the $$N$$ words, we iterate through its $$M$$ characters, and for each character, we test 26 possibilities. String construction and hash set lookup take $$O(M)$$ time.
- Space complexity: $$O(M \cdot N)$$, required by the `unordered_set` storing up to $$N$$ strings of length $$M$$, and the BFS queue in the worst-case scenario.

# Code
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        while(!q.empty()){
            string word = q.front().first;
            int ans = q.front().second;
            q.pop();
            if(word == endWord) return ans;
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                for(char c = 'a' ; c<='z';c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,ans+1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};
```

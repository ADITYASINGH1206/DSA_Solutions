# [1255. Maximum Score Words Formed by Letters](https://leetcode.com/problems/maximum-score-words-formed-by-letters/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `string`, `dynamic-programming`, `backtracking`, `bit-manipulation`, `counting`, `bitmask`

---

## Problem Description
Given a list of `words`, list of  single `letters` (might be repeating) and `score` of every character.

Return the maximum score of **any** valid set of words formed by using the given letters (`words[i]` cannot be used two or more times).

It is not necessary to use all characters in `letters` and each letter can only be used once. Score of letters `'a'`, `'b'`, `'c'`, ... ,`'z'` is given by `score[0]`, `score[1]`, ... , `score[25]` respectively.

**Example 1:**

```
Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.
```

**Example 2:**

```
Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.
```

**Example 3:**

```
Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
Output: 0
Explanation:
Letter "e" can only be used once.
```

**Constraints:**

* `1 <= words.length <= 14`
* `1 <= words[i].length <= 15`
* `1 <= letters.length <= 100`
* `letters[i].length == 1`
* `score.length == 26`
* `0 <= score[i] <= 10`
* `words[i]`, `letters[i]` contains only lower case English letters.

---

## Solution & Editorial
# Intuition
The problem asks us to find the maximum possible score by selecting a subset of words that can be formed using a given multiset of letters. Since the number of words $N$ is very small ($1 \le N \le 14$), an exponential-time backtracking approach that decides whether to include or exclude each word is extremely efficient and well within time limits.

# Approach
1. First, we precompute the frequency of each character in the given `letters` vector and store it in a frequency array `count` of size 26.
2. We define a recursive helper function `maxScore(words, count, score, idx)` that evaluates choices starting from index `idx`:
   - **Option 1 (Exclude word):** We skip the current word at index `idx` and recursively call `maxScore` for `idx + 1` with the same letter `count`.
   - **Option 2 (Include word):** We check if the current word can be formed using the available frequencies in `count`. We simulate taking the word by decrementing frequencies and accumulating its score. If valid, we recursively call `maxScore` for `idx + 1` with the updated frequency array and add the word's score.
3. The maximum between the excluded branch and the included branch (if valid) is returned at each step.

# Complexity
- Time complexity: $$O(2^N \cdot L)$$ where $$N$$ is the number of words ($$N \le 14$$) and $$L$$ is the maximum length of a word ($$L \le 15$$). In the worst case, every word generates two branches, and checking each word takes linear time with respect to its length.
- Space complexity: $$O(N + L)$$ corresponding to the recursion stack depth of $$N$$ and temporary frequency vector allocations of size 26 per recursive frame.

# Code
```cpp
class Solution {
public:
    int maxScore(vector<string>& words, vector<int>& count, vector<int>& score, int idx) {
        if (idx == words.size()) return 0;

        int res = maxScore(words, count, score, idx + 1);

        string& word = words[idx];
        bool canForm = true;
        int wordScore = 0;
        vector<int> tempCount = count;

        for (char c : word) {
            int charIdx = c - 'a';
            if (tempCount[charIdx] == 0) {
                canForm = false;
                break;
            }
            tempCount[charIdx]--;
            wordScore += score[charIdx];
        }

        if (canForm) {
            res = max(res, wordScore + maxScore(words, tempCount, score, idx + 1));
        }

        return res;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26, 0);
        for (char c : letters) count[c - 'a']++;
        return maxScore(words, count, score, 0);
    }
};
```

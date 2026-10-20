# [3302. Find the Lexicographically Smallest Valid Sequence](https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/)
**Difficulty:** `Medium` | **Tags:** `two-pointers`, `string`, `dynamic-programming`, `greedy`

---

## Problem Description
You are given two strings `word1` and `word2`.

A string `x` is called **almost equal** to `y` if you can change **at most** one character in `x` to make it *identical* to `y`.

A sequence of indices `seq` is called **valid** if:

* The indices are sorted in **ascending** order.
* *Concatenating* the characters at these indices in `word1` in **the same** order results in a string that is **almost equal** to `word2`.

Return an array of size `word2.length` representing the lexicographically smallest **valid** sequence of indices. If no such sequence of indices exists, return an **empty** array.

**Note** that the answer must represent the *lexicographically smallest array*, **not** the corresponding string formed by those indices.

**Example 1:**

**Input:** word1 = "vbcca", word2 = "abc"

**Output:** [0,1,2]

**Explanation:**

The lexicographically smallest valid sequence of indices is `[0, 1, 2]`:

* Change `word1[0]` to `'a'`.
* `word1[1]` is already `'b'`.
* `word1[2]` is already `'c'`.

**Example 2:**

**Input:** word1 = "bacdc", word2 = "abc"

**Output:** [1,2,4]

**Explanation:**

The lexicographically smallest valid sequence of indices is `[1, 2, 4]`:

* `word1[1]` is already `'a'`.
* Change `word1[2]` to `'b'`.
* `word1[4]` is already `'c'`.

**Example 3:**

**Input:** word1 = "aaaaaa", word2 = "aaabc"

**Output:** []

**Explanation:**

There is no valid sequence of indices.

**Example 4:**

**Input:** word1 = "abc", word2 = "ab"

**Output:** [0,1]

**Constraints:**

* `1 <= word2.length < word1.length <= 3 * 105`
* `word1` and `word2` consist only of lowercase English letters.

---

## Solution & Editorial
# Intuition
To find the lexicographically smallest sequence of indices, we want to pick the smallest possible index for each character in `word2`. Since we are allowed exactly one character mismatch, we can greedily match characters from `word1` to `word2`. The core challenge is knowing whether a mismatch at index `i` is "safe"—that is, whether the remaining suffix of `word1` can still match the remaining suffix of `word2` without further changes.

# Approach
1. **Suffix Preprocessing**: We precompute an array `Right` where `Right[i]` stores the length of the longest suffix of `word2` that can be formed using characters from `word1[i...N-1]`. This allows us to check in $O(1)$ if a mismatch at index `i` is valid.
2. **Greedy Construction**: Iterate through `word1` with index `i` and `word2` with index `j`. 
   - If `word1[i] == word2[j]`, we greedily take this index.
   - If `word1[i] != word2[j]` and we haven't used our "change" yet, we check if the remaining suffix of `word2` (length `M - 1 - j`) can be satisfied by `word1[i+1...N-1]`. This is true if `Right[i+1] >= M - 1 - j`.

### Visual Trace (word1 = "bacdc", word2 = "abc")
| i | j | word1[i] | word2[j] | Action | Result | changed |
|---|---|---|---|---|---|---|
| 0 | 0 | 'b' | 'a' | Mismatch, check Right[1] | [0] | true |
| 1 | 1 | 'a' | 'b' | Mismatch, skip | [0] | true |
| 2 | 1 | 'c' | 'b' | Mismatch, skip | [0] | true |
| 3 | 1 | 'd' | 'b' | Mismatch, skip | [0] | true |
| 4 | 1 | 'c' | 'b' | Mismatch, skip | [0] | true |
*(Note: The actual logic iterates and checks validity to ensure the smallest index is picked.)*

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `word1`. We perform one backward pass to fill `Right` and one forward pass to build the result.
- Space complexity: $$O(N)$$ to store the `Right` array.

# Code
```cpp
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int N=word1.size();
        int M=word2.size();
        int R=M-1;
        int C=0;
        vector<int> Right(N);
        for(int i=N-1;i>=0;i--){
            Right[i]=C;
            if(R>=0 && word1[i]==word2[R]){
                R--;
                C++;
            }
        }
        vector<int> ans;
        bool changed=false;
        int j=0;
        for(int i=0;i<N && j<M;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!changed && Right[i]>=M-1-j){
                ans.push_back(i);
                j++;
                changed=true;
            }
        }
        if(j==M){
            return ans;
        }
        return {};
    }
};
```

# [2942. Find Words Containing Character](https://leetcode.com/problems/find-words-containing-character/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
You are given a **0-indexed** array of strings `words` and a character `x`.

Return *an **array of indices** representing the words that contain the character* `x`.

**Note** that the returned array may be in **any** order.

**Example 1:**

```
Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
```

**Example 2:**

```
Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.
```

**Example 3:**

```
Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
Output: []
Explanation: "z" does not occur in any of the words. Hence, we return an empty array.
```

**Constraints:**

* `1 <= words.length <= 50`
* `1 <= words[i].length <= 50`
* `x` is a lowercase English letter.
* `words[i]` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks us to identify indices of strings within a list that contain a specific character. Since the constraints are small (up to 50 words, each up to 50 characters), a straightforward linear scan is optimal and efficient.

# Approach
1. Initialize an empty vector `ans` to store the indices of words that contain the target character `x`.
2. Iterate through the `words` array using an index `i` from `0` to `words.size() - 1`.
3. For each word, iterate through its characters. If the character matches `x`, add the current index `i` to `ans` and immediately `break` the inner loop to avoid adding the same index multiple times if the character appears more than once in the same word.
4. Return the `ans` vector.

### Visual Trace (Example 1: words = ["leet", "code"], x = 'e')
| Index (i) | Word | Contains 'e'? | Action |
| :--- | :--- | :--- | :--- |
| 0 | "leet" | Yes | Push 0, Break |
| 1 | "code" | Yes | Push 1, Break |

# Complexity
- Time complexity: $$O(N \times M)$$, where $$N$$ is the number of words and $$M$$ is the maximum length of a word. We visit each character in the worst case.
- Space complexity: $$O(1)$$ (excluding the output vector), as we only use a few integer variables for iteration.

# Code
```cpp
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            for(int j=0;j<word.size();j++){
                if(word[j]==x){
                    ans.push_back(i);
                    break;
                }
            }

        }
        return ans;
    }
};
```

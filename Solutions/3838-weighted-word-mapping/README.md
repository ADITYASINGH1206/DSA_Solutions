# [3838. Weighted Word Mapping](https://leetcode.com/problems/weighted-word-mapping/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`, `simulation`

---

## Problem Description
You are given an array of strings `words`, where each string represents a word containing lowercase English letters.

You are also given an integer array `weights` of length 26, where `weights[i]` represents the weight of the `ith` lowercase English letter.

The **weight** of a word is defined as the **sum** of the weights of its characters.

For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (`0 -> 'z', 1 -> 'y', ..., 25 -> 'a'`).

Return a string formed by concatenating the mapped characters for all words in order.

**Example 1:**

**Input:** words = ["abcd","def","xyz"], weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]

**Output:** "rij"

**Explanation:**

* The weight of `"abcd"` is `5 + 3 + 12 + 14 = 34`. The result modulo 26 is `34 % 26 = 8`, which maps to `'r'`.
* The weight of `"def"` is `14 + 1 + 2 = 17`. The result modulo 26 is `17 % 26 = 17`, which maps to `'i'`.
* The weight of `"xyz"` is `7 + 7 + 2 = 16`. The result modulo 26 is `16 % 26 = 16`, which maps to `'j'`.

Thus, the string formed by concatenating the mapped characters is `"rij"`.

**Example 2:**

**Input:** words = ["a","b","c"], weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

**Output:** "yyy"

**Explanation:**

Each word has weight 1. The result modulo 26 is `1 % 26 = 1`, which maps to `'y'`.

Thus, the string formed by concatenating the mapped characters is `"yyy"`.

**Example 3:**

**Input:** words = ["abcd"], weights = [7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5]

**Output:** "g"

**Explanation:​​​​​​​**

The weight of `"abcd"` is `7 + 5 + 3 + 4 = 19`. The result modulo 26 is `19 % 26 = 19`, which maps to `'g'`.

Thus, the string formed by concatenating the mapped characters is `"g"`.

**Constraints:**

* `1 <= words.length <= 100`
* `1 <= words[i].length <= 10`
* `weights.length == 26`
* `1 <= weights[i] <= 100`
* `words[i]` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem requires calculating the sum of character weights for each word and mapping the result to a character based on a reverse alphabetical offset. Since the constraints are small (100 words, max 10 characters each), a direct simulation is efficient and optimal.

# Approach
1. Initialize an empty string `ans` to store the result.
2. Iterate through each `word` in the `words` vector.
3. For each `word`, calculate the total weight by summing `weights[char - 'a']` for every character in the string.
4. Compute the remainder `r = total_weight % 26`.
5. Map the remainder to a character using the reverse alphabetical logic: `'z' - r`. For example, if `r=0`, the result is `'z'`; if `r=25`, the result is `'a'`.
6. Append the resulting character to `ans` and return it after processing all words.

### Visual Trace (Example 1: "abcd")
| Step | Variable | Value |
| :--- | :--- | :--- |
| 1 | `word` | "abcd" |
| 2 | `count` | 5+3+12+14 = 34 |
| 3 | `r` | 34 % 26 = 8 |
| 4 | `chrs` | 'z' - 8 = 'r' |

# Complexity
- Time complexity: $$O(N \times L)$$, where $$N$$ is the number of words and $$L$$ is the maximum length of a word. We iterate through every character of every word exactly once.
- Space complexity: $$O(N)$$ to store the resulting string, or $$O(1)$$ auxiliary space if we exclude the output string.

# Code
```cpp
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int count = 0; 
            for(int j = 0; j < word.size(); j++) {
                count += weights[word[j] - 'a'];
            }
            int r = count % 26;
            char chrs = 'z' - r;
            
            ans += chrs;
        }
        
        return ans;
    }
};
```

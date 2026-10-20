# [1832. Check if the Sentence Is Pangram](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`

---

## Problem Description
A **pangram** is a sentence where every letter of the English alphabet appears at least once.

Given a string `sentence` containing only lowercase English letters, return`true` *if* `sentence` *is a **pangram**, or* `false` *otherwise.*

**Example 1:**

```
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
```

**Example 2:**

```
Input: sentence = "leetcode"
Output: false
```

**Constraints:**

* `1 <= sentence.length <= 1000`
* `sentence` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To determine if a sentence is a pangram, we must verify that every letter from 'a' to 'z' appears at least once. Since the input is restricted to lowercase English letters, a fixed-size frequency array is the most efficient way to track occurrences.

# Approach
1. Initialize a frequency vector `ch` of size 26 with all zeros to represent the count of each letter.
2. Iterate through each character `c` in the input `sentence`. Calculate the index using `c - 'a'` and increment the corresponding count in `ch`.
3. After processing the string, iterate through the `ch` vector. If any index contains a value of 0, it means that letter was never encountered, so return `false`.
4. If the loop completes without finding any zeros, return `true`.

### Visual Trace (Example: "abc")
| Step | Char | ch['a'-'a'] | ch['b'-'a'] | ch['c'-'a'] | Others |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | 0 | 0 | 0 | 0 |
| Process 'a' | 'a' | 1 | 0 | 0 | 0 |
| Process 'b' | 'b' | 1 | 1 | 0 | 0 |
| Process 'c' | 'c' | 1 | 1 | 1 | 0 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the sentence. We perform a single pass over the string and a constant-time pass over the 26-element frequency array.
- Space complexity: $$O(1)$$, as the frequency array size is fixed at 26 regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> ch(26,0);
        int ans = true;
        for(char c:sentence){
            ch[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(!ch[i]){
                ans = false;
                break;
            }
        }
        return ans;
    }
};
```

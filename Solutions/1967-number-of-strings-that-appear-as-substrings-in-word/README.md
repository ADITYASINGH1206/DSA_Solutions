# [1967. Number of Strings That Appear as Substrings in Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
Given an array of strings `patterns` and a string `word`, return *the **number** of strings in* `patterns` *that exist as a **substring** in* `word`.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```
Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.
```

**Example 2:**

```
Input: patterns = ["a","b","c"], word = "aaaaabbbbb"
Output: 2
Explanation:
- "a" appears as a substring in "aaaaabbbbb".
- "b" appears as a substring in "aaaaabbbbb".
- "c" does not appear as a substring in "aaaaabbbbb".
2 of the strings in patterns appear as a substring in word.
```

**Example 3:**

```
Input: patterns = ["a","a","a"], word = "ab"
Output: 3
Explanation: Each of the patterns appears as a substring in word "ab".
```

**Constraints:**

* `1 <= patterns.length <= 100`
* `1 <= patterns[i].length <= 100`
* `1 <= word.length <= 100`
* `patterns[i]` and `word` consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
To determine if a pattern exists within a word, we can generate all possible contiguous substrings of the target `word` and store them in a collection. By iterating through each string in the `patterns` array, we can check if that pattern exists within our pre-generated collection of substrings.

# Approach
1. Initialize a vector `sub` to store all possible substrings of `word`.
2. Use nested loops to generate every substring by iterating through all start indices `i` and end indices `j` of `word`. The substring is extracted using `word.substr(i, j - i + 1)`.
3. Initialize a counter `ans` to 0.
4. Iterate through each string `temp` in the `patterns` array.
5. For each `temp`, perform a linear search through the `sub` vector. If a match is found, increment `ans` and break the inner loop to avoid double-counting the same pattern.

### Visual Trace (Example 1: patterns = ["a", "abc"], word = "abc")
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Generate Substrings | sub = {"a", "ab", "abc", "b", "bc", "c"} |
| 2 | Check "a" | Found in `sub`, ans = 1 |
| 3 | Check "abc" | Found in `sub`, ans = 2 |

# Complexity
- Time complexity: $$O(N^3 + M \cdot K)$$, where $$N$$ is the length of `word` (generating all substrings takes $$O(N^3)$$), $$M$$ is the number of patterns, and $$K$$ is the number of substrings ($$O(N^2)$$). Given the constraints ($N, M \le 100$), this is well within limits.
- Space complexity: $$O(N^2)$$ to store all generated substrings in the `sub` vector.

# Code
```cpp
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        vector<string> sub;
        int n = word.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                string subs = word.substr(i,j-i+1);
                sub.push_back(subs);
            }
        }
        int n2 = patterns.size();
        int ans = 0;
        for(int i =0 ;i<n2;i++){
            string temp = patterns[i];
            for(int j = 0;j<sub.size();j++){
                if(patterns[i] == sub[j]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
```

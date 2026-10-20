# [2185. Counting Words With a Given Prefix](https://leetcode.com/problems/counting-words-with-a-given-prefix/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`, `string-matching`

---

## Problem Description
You are given an array of strings `words` and a string `pref`.

Return *the number of strings in* `words` *that contain* `pref` *as a **prefix***.

A **prefix** of a string `s` is any leading contiguous substring of `s`.

**Example 1:**

```
Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
```

**Example 2:**

```
Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
```

**Constraints:**

* `1 <= words.length <= 100`
* `1 <= words[i].length, pref.length <= 100`
* `words[i]` and `pref` consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
To determine if a string starts with a specific prefix, we can extract the leading substring of the same length as the prefix and perform a direct equality comparison. Since the constraints are small (up to 100 words of length 100), this straightforward approach is highly efficient.

# Approach
1. Initialize a counter `ans` to 0.
2. Calculate the length `n` of the target prefix `pref`.
3. Iterate through each `word` in the `words` vector.
4. For each `word`, extract a substring `sub` starting at index 0 with length `n` using `word.substr(0, n)`.
5. Compare `sub` with `pref`. If they are equal, increment `ans`.
6. Return `ans` after processing all words.

### Visual Trace (Example 1: words = ["pay", "attention", "practice", "attend"], pref = "at")
| Word | n | sub (0, 2) | Match? | ans |
| :--- | :--- | :--- | :--- | :--- |
| "pay" | 2 | "pa" | No | 0 |
| "attention" | 2 | "at" | Yes | 1 |
| "practice" | 2 | "pr" | No | 1 |
| "attend" | 2 | "at" | Yes | 2 |

# Complexity
- Time complexity: $$O(N \times M)$$, where $$N$$ is the number of words and $$M$$ is the length of the prefix. We iterate through $$N$$ words and perform a substring extraction and comparison of length $$M$$.
- Space complexity: $$O(M)$$, as we create a temporary substring of length $$M$$ for each word comparison.

# Code
```cpp
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        int n = pref.size();
        for(auto& word:words){
            string sub = word.substr(0,n);
            if(sub == pref) ans++;
        }
        return ans;
    }
};
```

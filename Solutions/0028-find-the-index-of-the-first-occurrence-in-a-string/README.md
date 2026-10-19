# [28. Find the Index of the First Occurrence in a String](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)
**Difficulty:** `Easy` | **Tags:** `two-pointers`, `string`, `string-matching`, `z-algorithm`, `knuth-morris-pratt-algorithm`, `boyer-moore-string-search-algorithm`

---

## Problem Description
Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

**Example 1:**

```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

**Example 2:**

```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```

**Constraints:**

* `1 <= haystack.length, needle.length <= 104`
* `haystack` and `needle` consist of only lowercase English characters.

---

## Solution & Editorial
# Intuition
The problem requires us to find the starting index of the first occurrence of `needle` within `haystack`. A straightforward substring matching approach checks every possible starting position in `haystack` up to `n1 - n2` and compares characters sequentially until a mismatch is found or the entire `needle` is matched.

# Approach
1. Store the lengths of `haystack` and `needle` in `n1` and `n2` respectively.
2. Iterate through `haystack` using pointer `i` from `0` up to `n1 - n2` as potential starting indices.
3. For each starting index `start = i`, use pointer `j` to compare `needle[j]` with `haystack[i]` character by character.
4. If all characters match (`j == n2`), return `start` immediately.
5. If a mismatch occurs, set `notFound = true`, break out of the inner loop, and reset `i` to `start + 1` to check the next position.
6. If the outer loop completes without finding a match, return `-1`.

### Visual Dry Run (Example 1: haystack = "sadbutsad", needle = "sad")
- `i = 0`, `start = 0`:
  - `j = 0`: `haystack[0] ('s') == needle[0] ('s')` -> `i = 1`, `j = 1`
  - `j = 1`: `haystack[1] ('a') == needle[1] ('a')` -> `i = 2`, `j = 2`
  - `j = 2`: `haystack[2] ('d') == needle[2] ('d')` -> `i = 3`, `j = 3`
- Inner loop completes (`j == 3 == n2`). Returns `start = 0`.

# Complexity
- Time complexity: $$O((N - M + 1) 	imes M)$$ in the worst case, where $$N$$ is the length of `haystack` and $$M$$ is the length of `needle`. In practice, characters mismatch early resulting in extremely fast execution for random strings.
- Space complexity: $$O(1)$$ auxiliary space since only a few scalar index variables are maintained.

# Code
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size();
        int n2 = needle.size();
        int i = 0;
        while(i <= n1 - n2){ 
            int j = 0;
            bool notFound = false;
            int start = i; 
            while(j < n2){
                if(haystack[i] == needle[j]){
                    j++;
                    i++;
                }
                else{
                    notFound = true;
                    break;
                }
            }
            
            if(notFound) {
                i = start + 1; 
            } else {
                return start; 
            }
        }

        return -1;
    }
};
```

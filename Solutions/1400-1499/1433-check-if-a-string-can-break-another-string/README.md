# [1433. Check If a String Can Break Another String](https://leetcode.com/problems/check-if-a-string-can-break-another-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `greedy`, `sorting`

---

## Problem Description
Given two strings: `s1` and `s2` with the same size, check if some permutation of string `s1` can break some permutation of string `s2` or vice-versa. In other words `s2` can break `s1` or vice-versa.

A string `x` can break string `y` (both of size `n`) if `x[i] >= y[i]` (in alphabetical order) for all `i` between `0` and `n-1`.

**Example 1:**

```
Input: s1 = "abc", s2 = "xya"
Output: true
Explanation: "ayx" is a permutation of s2="xya" which can break to string "abc" which is a permutation of s1="abc".
```

**Example 2:**

```
Input: s1 = "abe", s2 = "acd"
Output: false 
Explanation: All permutations for s1="abe" are: "abe", "aeb", "bae", "bea", "eab" and "eba" and all permutation for s2="acd" are: "acd", "adc", "cad", "cda", "dac" and "dca". However, there is not any permutation from s1 which can break some permutation from s2 and vice-versa.
```

**Example 3:**

```
Input: s1 = "leetcodee", s2 = "interview"
Output: true
```

**Constraints:**

* `s1.length == n`
* `s2.length == n`
* `1 <= n <= 10^5`
* All strings consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
To determine if one string can "break" another, we need to compare their characters at every position after sorting. If we sort both strings, we align the smallest characters with the smallest, and the largest with the largest. If one sorted string is consistently greater than or equal to the other at every index, then a breaking condition exists.

# Approach
1. Sort both `s1` and `s2` in non-decreasing order. Sorting ensures that we are comparing the smallest possible character of one string against the smallest of the other, which is the optimal strategy to check for the breaking condition.
2. Initialize two boolean flags, `ans1` and `ans2`, as `true`.
3. Iterate through the sorted strings:
   - Check if `s1[i] > s2[i]` for any index `i`. If this occurs, `s1` cannot break `s2`, so set `ans1 = false`.
   - Check if `s1[i] < s2[i]` for any index `i`. If this occurs, `s2` cannot break `s1`, so set `ans2 = false`.
4. Return `ans1 || ans2`. If either flag remains `true`, it means one string can break the other.

### Visual Trace (Example 1: s1="abc", s2="xya")
- Sorted s1: "abc"
- Sorted s2: "axy"

| Index | s1[i] | s2[i] | s1 <= s2 | s1 >= s2 |
|-------|-------|-------|----------|----------|
| 0     | 'a'   | 'a'   | True     | True     |
| 1     | 'b'   | 'x'   | True     | False    |
| 2     | 'c'   | 'y'   | True     | False    |

- `ans1` (s1 breaks s2) remains `true`.
- `ans2` (s2 breaks s1) becomes `false`.
- Result: `true || false` = `true`.

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the length of the strings. This is dominated by the sorting operation on both strings.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation, typically $$O(\log N)$$ or $$O(N)$$).

# Code
```cpp
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end(),[](char& a,char& b){
            return a-'a'<b-'a';
        });
        sort(s2.begin(),s2.end(),[](char& a,char&b){
            return a-'a'<b-'a';
        });
        int n = s1.size();
        bool ans1 = true;
        bool ans2 = true;
        for(int i = 0;i<n;i++){
            if(s1[i]-'a'>s2[i]-'a'){
                ans1 = false;
                break;
            }
        }
        for(int i = 0;i<n;i++){
            if(s1[i]-'a'<s2[i]-'a'){
                ans2 = false;
                break;
            }
        }
        return ans1 || ans2;
    }
};
```

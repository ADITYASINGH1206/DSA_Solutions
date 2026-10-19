# [942. DI String Match](https://leetcode.com/problems/di-string-match/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`, `string`, `greedy`

---

## Problem Description
A permutation `perm` of `n + 1` integers of all the integers in the range `[0, n]` can be represented as a string `s` of length `n` where:

* `s[i] == 'I'` if `perm[i] < perm[i + 1]`, and
* `s[i] == 'D'` if `perm[i] > perm[i + 1]`.

Given a string `s`, reconstruct the permutation `perm` and return it. If there are multiple valid permutations perm, return **any of them**.

**Example 1:**

```
Input: s = "IDID"
Output: [0,4,1,3,2]
```

**Example 2:**

```
Input: s = "III"
Output: [0,1,2,3]
```

**Example 3:**

```
Input: s = "DDI"
Output: [3,2,0,1]
```

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is either `'I'` or `'D'`.

---

## Solution & Editorial
# Intuition
The problem requires constructing a permutation of integers from $0$ to $n$ satisfying the adjacency constraints defined by string $s$. Whenever we encounter 'I' (increasing), we want to pick the smallest available number to ensure we can still grow. Conversely, when we encounter 'D' (decreasing), we pick the largest available number. This greedy choice guarantees validity at each step using two pointers representing the remaining value range.

# Code
```cpp
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int n = s.size();
        
        int low = 0;
        int high = n;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'I') {
                ans.push_back(low);
                low++;
            } else {
                ans.push_back(high);
                high--; 
            }
        }
        ans.push_back(low); 
        
        return ans;
    }
};
```

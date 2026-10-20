# [3980. Minimum Operations to Transform Binary String](https://leetcode.com/problems/minimum-operations-to-transform-binary-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `greedy`

---

## Problem Description
You are given two binary strings `s1` and `s2` of the same length `n`.

You can perform the following operations on `s1` any number of times, in any order:

* Choose an index `i` such that `s1[i] == '0'`, and change it to `'1'`.
* Choose an index `i` such that `0 <= i < n - 1`, and both `s1[i]` and `s1[i + 1]` are `'1'`. Change both characters to `'0'`.

Return the **minimum** number of operations required to make `s1` equal to `s2`. If it is impossible, return -1.

**Example 1:**

**Input:** s1 = "11", s2 = "00"

**Output:** 1

**Explanation:**

Change indices 0 and 1 from `'1'` to `'0'` in one operation, so `"11"` becomes `"00"`. Thus, the answer is 1.

**Example 2:**

**Input:** s1 = "01", s2 = "10"

**Output:** 3

**Explanation:**

* Change index 0 from `'0'` to `'1'`, so `"01"` becomes `"11"`.
* Change indices 0 and 1 from `'1'` to `'0'`, so `"11"` becomes `"00"`.
* Change index 0 from `'0'` to `'1'`, so `"00"` becomes `"10"`.
* Thus, the answer is 3.

**Example 3:**

**Input:** s1 = "1", s2 = "0"

**Output:** -1

**Explanation:**

The first operation cannot change `'1'` to `'0'`, and the second operation requires two adjacent characters. Therefore, it is impossible.

**Constraints:**

* `1 <= n == s1.length == s2.length <= 105`
* `s1` and `s2` consist only of `'0'` and `'1'`.

---

## Solution & Editorial
# Intuition
The problem allows two operations: flipping '0' to '1' (cost 1) and flipping two adjacent '1's to '0's (cost 1). The key observation is that we can treat the transformation of each index independently while accounting for the adjacency constraint. When `s1[i]` needs to change to `s2[i]`, we either perform a direct flip or leverage the pair-flip operation to minimize total cost.

# Approach
1. Iterate through the string `s1` from index `0` to `n-1`.
2. If `s1[i] == '0'` and `s2[i] == '1'`, we must perform a '0' to '1' flip, incrementing `ans` by 1.
3. If `s1[i] == '1'` and `s2[i] == '0'`, we need to turn this '1' into a '0'. 
   - If the next character `s1[i+1]` is also '1' and `s2[i+1]` is '0', we can perform a single pair-flip operation on `(i, i+1)`, incrementing `ans` by 1 and skipping the next index.
   - Otherwise, we must perform a '1' to '0' transformation via an intermediate '1' to '0' flip (which requires two steps: flip to '1' then pair-flip, or similar logic depending on state), effectively costing 2.
4. Handle the edge case where `n=1` and `s1='1', s2='0'`, which is impossible.

### Visual Trace (Example 2: s1="01", s2="10")
| Index | s1[i] | s2[i] | Action | ans |
|-------|-------|-------|--------|-----|
| 0 | '0' | '1' | 0->1 | 1 |
| 1 | '1' | '0' | 1->0 (no pair) | 1+2=3 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the strings, as we perform a single linear pass.
- Space complexity: $$O(1)$$ as we only use a few integer variables for tracking the state.

# Code
```cpp
class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int ans = 0;
        if (n == 1 && s1 == "1" && s2 == "0") {
            return -1;
        }
        for (int i = 0; i < n; i++) {
            if (s1[i] == '0' && s2[i] == '1') {
                ans++;
            } else if (s1[i] == '1' && s2[i] == '0') {
                if (i + 1 < n && s1[i + 1] == '1' && s2[i + 1] == '0') {
                    ans++;
                    i++;
                } else {
                    ans += 2;
                }
            }
        }
        return ans;
    }
};
```

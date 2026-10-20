# [2657. Find the Prefix Common Array of Two Arrays](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `bit-manipulation`

---

## Problem Description
You are given two **0-indexed** integerpermutations `A` and `B` of length `n`.

A **prefix common array** of `A` and `B` is an array `C` such that `C[i]` is equal to the count of numbers that are present at or before the index `i` in both `A` and `B`.

Return *the **prefix common array** of* `A` *and* `B`.

A sequence of `n` integers is called a **permutation** if it contains all integers from `1` to `n` exactly once.

**Example 1:**

```
Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
```

**Example 2:**

```
Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
```

**Constraints:**

* `1 <= A.length == B.length == n <= 50`
* `1 <= A[i], B[i] <= n`
* `It is guaranteed that A and B are both a permutation of n integers.`

---

## Solution & Editorial
# Intuition
Since the problem asks for the count of common elements in the prefixes of two permutations, we can maintain the frequency of each number encountered so far in both arrays. By comparing these frequencies at each index, we can determine how many numbers have appeared in both prefixes.

# Approach
1. Initialize an answer vector `ans` of size `n` and two frequency arrays `count1` and `count2` of size `n + 1` to track occurrences of numbers in `A` and `B` respectively.
2. Iterate through the arrays from `i = 0` to `n - 1`.
3. At each index `i`, increment the frequency of `A[i]` in `count1` and `B[i]` in `count2`.
4. For every index `i`, perform a nested loop from `j = 1` to `n` to sum the minimum of `count1[j]` and `count2[j]`. This sum represents the count of numbers present in both prefixes up to `i`.

### Visual Trace (Example 1: A=[1,3,2,4], B=[3,1,2,4])
| i | A[i] | B[i] | count1 (active) | count2 (active) | ans[i] |
|---|---|---|---|---|---|
| 0 | 1 | 3 | {1:1} | {3:1} | 0 |
| 1 | 3 | 1 | {1:1, 3:1} | {3:1, 1:1} | 2 |
| 2 | 2 | 2 | {1:1, 3:1, 2:1} | {3:1, 1:1, 2:1} | 3 |
| 3 | 4 | 4 | {1:1, 3:1, 2:1, 4:1} | {3:1, 1:1, 2:1, 4:1} | 4 |

# Complexity
- Time complexity: $$O(n^2)$$, where $$n$$ is the length of the input arrays. We iterate through the array once, and for each element, we perform a linear scan of size $$n$$.
- Space complexity: $$O(n)$$, as we use two frequency arrays of size $$n+1$$.

# Code
```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<int> count1(n + 1);
        vector<int> count2(n + 1);
        for (int i = 0; i < n; ++i) {
            count1[A[i]]++;
            count2[B[i]]++;
            for (int j = 1; j <= n; ++j) {
                ans[i] += min(count1[j], count2[j]);
            }
        }
        return ans;
    }
};
```

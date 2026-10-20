# [3336. Find the Number of Subsequences With Equal GCD](https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `dynamic-programming`, `number-theory`, `euclidean-algorithm`, `greatest-common-divisor`

---

## Problem Description
You are given an integer array `nums`.

Your task is to find the number of pairs of **non-empty** subsequences `(seq1, seq2)` of `nums` that satisfy the following conditions:

* The subsequences `seq1` and `seq2` are **disjoint**, meaning **no index** of `nums` is common between them.
* The GCD of the elements of `seq1` is equal to the GCD of the elements of `seq2`.

Return the total number of such pairs.

Since the answer may be very large, return it **modulo** `109 + 7`.

**Example 1:**

**Input:** nums = [1,2,3,4]

**Output:** 10

**Explanation:**

The subsequence pairs which have the GCD of their elements equal to 1 are:

* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`
* `([1, 2, 3, 4], [1, 2, 3, 4])`

**Example 2:**

**Input:** nums = [10,20,30]

**Output:** 2

**Explanation:**

The subsequence pairs which have the GCD of their elements equal to 10 are:

* `([10, 20, 30], [10, 20, 30])`
* `([10, 20, 30], [10, 20, 30])`

**Example 3:**

**Input:** nums = [1,1,1,1]

**Output:** 50

**Constraints:**

* `1 <= nums.length <= 200`
* `1 <= nums[i] <= 200`

---

## Solution & Editorial
# Intuition
To find pairs of disjoint subsequences with equal GCD, we can treat each element in the input array as a decision point: add it to the first subsequence, the second, or ignore it. Since the GCD of a single element is the element itself and the GCD of a set is associative, we can maintain the current GCD of both subsequences as our state.

# Approach
1. Define a DP table `dp[g1][g2]` representing the number of ways to form two disjoint subsequences with current GCDs `g1` and `g2`. Initialize `dp[0][0] = 1` (representing empty subsequences).
2. Iterate through each number `x` in `nums`. For each state `(g1, g2)`, we have three choices:
   - Add `x` to the first subsequence: new state becomes `(gcd(g1 == 0 ? x : g1, x), g2)`.
   - Add `x` to the second subsequence: new state becomes `(g1, gcd(g2 == 0 ? x : x, g2))`.
   - Ignore `x`: state remains `(g1, g2)`.
3. Since we need non-empty subsequences, we handle the `0` GCD case by treating the first element added to a subsequence as the initial GCD.
4. After processing all elements, sum `dp[g][g]` for all `g > 0` to get the final count.

### Visual Trace (Example: [1, 2])
| Step | State (g1, g2) | Action | New State |
| :--- | :--- | :--- | :--- |
| Init | (0, 0) | - | (0, 0) = 1 |
| x=1 | (0, 0) | Add to S1 | (1, 0) = 1 |
| x=1 | (0, 0) | Add to S2 | (0, 1) = 1 |
| x=2 | (1, 0) | Add to S2 | (1, 2) = 1 |
| x=2 | (0, 1) | Add to S1 | (2, 1) = 1 |

# Complexity
- Time complexity: $$O(N \cdot M^2)$$, where $$N$$ is the length of `nums` and $$M$$ is the maximum value in `nums`. We iterate through $$N$$ elements, and for each, we update a table of size $$M \times M$$.
- Space complexity: $$O(M^2)$$ to store the DP table.

# Code
```cpp
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end()), mod = 1e9 + 7;
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            auto next_dp = dp;
            for (int g1 = 0; g1 <= m; ++g1) {
                for (int g2 = 0; g2 <= m; ++g2) {
                    if (!dp[g1][g2]) continue;
                    int n1 = gcd(g1, x), n2 = gcd(g2, x);
                    next_dp[n1][g2] = (next_dp[n1][g2] + dp[g1][g2]) % mod;
                    next_dp[g1][n2] = (next_dp[g1][n2] + dp[g1][g2]) % mod;
                }
            }
            dp = move(next_dp);
        }

        long long ans = 0;
        for (int g = 1; g <= m; ++g)
            ans = (ans + dp[g][g]) % mod;
        return ans;
    }
};
```

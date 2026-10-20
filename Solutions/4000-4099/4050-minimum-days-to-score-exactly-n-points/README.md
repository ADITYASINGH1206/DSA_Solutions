# [4050. Minimum Days to Score Exactly N Points](https://leetcode.com/problems/minimum-days-to-score-exactly-n-points/)
**Difficulty:** `Medium` | **Tags:** `math`, `dynamic-programming`

---

## Problem Description
You are given an integer `n` representing a target score.

Your score starts at 0, and each day you either **earn** points or **skip**.

Points are earned during a streak. On the first day of a streak you earn 1 point, on the second day 2 points, on the third day 3 points, and so on. **Skipping** a day earns **nothing** and **resets** the streak, so the next time you earn points, you start from 1 again.

Return the **minimum** number of days, including any skipped days, needed to reach a score of **exactly** `n`.

**Example 1:**

**Input:** n = 2

**Output:** 3

**Explanation:**​​​​​​​

* Day 1: earn 1 point. Score is 1.
* Day 2: skip, which resets the streak. Earning here would add 2 points and take the score past `n = 2`.
* Day 3: the streak has reset, so earning gives 1 point. Score is exactly `n = 2` in 3 days.

**Example 2:**

**Input:** n = 9

**Output:** 6

**Explanation:**​​​​​​​

* Days 1 to 3: earn 1, 2, and 3 points. Score is `1 + 2 + 3 = 6`.
* Day 4: skip, which resets the streak.
* Days 5 and 6: earn 1 and 2 points. Score is exactly `6 + 1 + 2 = 9` in 6 days.

**Example 3:**

**Input:** n = 12

**Output:** 7

**Explanation:**​​​​​​​

* Days 1 to 3: earn 1, 2, and 3 points. Score is `1 + 2 + 3 = 6`.
* Day 4: skip, which resets the streak.
* Days 5 to 7: earn 1, 2, and 3 points. Score is exactly `6 + 1 + 2 + 3 = 12` in 7 days.

**Constraints:**

* `1 <= n <= 105`

---

## Solution & Editorial
# Intuition
To reach a target score `n`, we can view the process as a sequence of "streaks" separated by "skip" days. A streak of length `j` contributes `j*(j+1)/2` points and takes `j` days. A skip day adds 1 day to the total count and resets the streak. This structure suggests that the minimum days to reach `n` can be broken down into subproblems: the minimum days to reach `n - points_from_streak` plus the days taken by that streak and the subsequent skip.

# Approach
1. Define `dp[i]` as the minimum days to reach exactly score `i`.
2. Initialize `dp` with a large value (`1e9`) and set `dp[0] = -1`. The base case `dp[0] = -1` is used because every streak is followed by a skip day (adding 1 to the total), effectively canceling out the -1 when we reach the final target.
3. Iterate `i` from 1 to `n`. For each `i`, iterate through all possible streak lengths `j` such that the points earned `j*(j+1)/2 <= i`.
4. The transition is `dp[i] = min(dp[i], j + 1 + dp[i - points])`, where `j` is the streak length and `1` represents the mandatory skip day.

### Visual Trace (n = 2)
| i | j=1 (pts=1) | dp[i] calculation | Result |
|---|---|---|---|
| 0 | - | - | -1 |
| 1 | 1 (pts=1) | 1 + 1 + dp[0] = 1 | 1 |
| 2 | 1 (pts=1) | 1 + 1 + dp[1] = 3 | 3 |

# Complexity
- Time complexity: $$O(N\sqrt{N})$$. The outer loop runs $N$ times. The inner loop runs up to $\sqrt{2N}$ times because the sum of the first $j$ integers is $O(j^2)$.
- Space complexity: $$O(N)$$ to store the `dp` array of size $N+1$.

# Code
```cpp
class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = -1; 
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * (j + 1) / 2 <= i; j++) {
                int points = j * (j + 1) / 2;
                dp[i] = min(dp[i], j + 1 + dp[i - points]);
            }
        }
        
        return dp[n];
    }
};
```

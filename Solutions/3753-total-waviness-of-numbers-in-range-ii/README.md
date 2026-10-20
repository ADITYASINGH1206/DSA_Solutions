# [3753. Total Waviness of Numbers in Range II](https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/)
**Difficulty:** `Hard` | **Tags:** `math`, `dynamic-programming`

---

## Problem Description
You are given two integers `num1` and `num2` representing an **inclusive** range `[num1, num2]`.

The **waviness** of a number is defined as the total count of its **peaks** and **valleys**:

* A digit is a **peak** if it is **strictly greater** than both of its immediate neighbors.
* A digit is a **valley** if it is **strictly less** than both of its immediate neighbors.
* The first and last digits of a number **cannot** be peaks or valleys.
* Any number with fewer than 3 digits has a waviness of 0.

Return the total sum of waviness for all numbers in the range `[num1, num2]`.

**Example 1:**

**Input:** num1 = 120, num2 = 130

**Output:** 3

**Explanation:**

In the range `[120, 130]`:

* `120`: middle digit 2 is a peak, waviness = 1.
* `121`: middle digit 2 is a peak, waviness = 1.
* `130`: middle digit 3 is a peak, waviness = 1.
* All other numbers in the range have a waviness of 0.

Thus, total waviness is `1 + 1 + 1 = 3`.

**Example 2:**

**Input:** num1 = 198, num2 = 202

**Output:** 3

**Explanation:**

In the range `[198, 202]`:

* `198`: middle digit 9 is a peak, waviness = 1.
* `201`: middle digit 0 is a valley, waviness = 1.
* `202`: middle digit 0 is a valley, waviness = 1.
* All other numbers in the range have a waviness of 0.

Thus, total waviness is `1 + 1 + 1 = 3`.

**Example 3:**

**Input:** num1 = 4848, num2 = 4848

**Output:** 2

**Explanation:**

Number `4848`: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

**Constraints:**

* `1 <= num1 <= num2 <= 1015`​​​​​​​

---

## Solution & Editorial
# Intuition
The problem asks for the total waviness of all numbers in a range, where waviness is defined by local extrema (peaks and valleys). Since the range is up to 10^15, we use Digit DP to count the occurrences of peaks and valleys across all numbers. The state must track the previous two digits to determine if the current digit forms a peak or valley.

# Approach
1. **Digit DP State**: We define `dfs(pos, started, last, secondLast, tight)` where:
   - `pos`: Current digit position being filled.
   - `started`: Boolean flag indicating if we have started placing non-zero digits.
   - `last`: The digit at `pos - 1`.
   - `secondLast`: The digit at `pos - 2`.
   - `tight`: Constraint flag for the upper bound of the range.
2. **Transition**: For each digit `d` from 0 to `limit`:
   - If we haven't started, we continue skipping leading zeros.
   - If we have started, we check if `last` is a peak (`last > secondLast && last > d`) or a valley (`last < secondLast && last < d`).
   - We accumulate the total waviness by adding the waviness of the sub-problem plus the count of numbers formed if the current `last` digit is an extremum.
3. **Memoization**: We cache results in `dp[pos][started][last][secondLast]` when `tight` is false to avoid redundant calculations.

### Visual Trace (Example: 120)
| State (pos, started, last, secondLast) | Action | Waviness Contribution |
| :--- | :--- | :--- |
| (0, 0, 10, 10) | Start | 0 |
| (1, 1, 1, 10) | Place 1 | 0 |
| (2, 1, 2, 1) | Place 2 | 0 |
| (3, 1, 0, 2) | Place 0 | 1 (2 is peak) |

# Complexity
- Time complexity: $$O(D \cdot 10^2)$$, where $$D$$ is the number of digits (max 15). We have $$D \times 2 \times 11 \times 11$$ states, and each state iterates over 10 possible digits.
- Space complexity: $$O(D \cdot 10^2)$$ for the memoization table.

# Code
```cpp
class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][2][11][11];
    bool vis[20][2][11][11];

    Node dfs(int pos, int started, int last, int secondLast, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][last][secondLast]) {
            return dp[pos][started][last][secondLast];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 0, 10, 10, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } else {
                long long add = 0;

                if (started && secondLast != 10) {
                    if ((last > secondLast && last > d) ||
                        (last < secondLast && last < d)) {
                        add = 1;
                    }
                }

                int nSecondLast = started ? last : 10;
                int nLast = d;

                Node nxt = dfs(pos + 1, 1, nLast, nSecondLast, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + add * nxt.cnt;
            }
        }

        if (!tight) {
            vis[pos][started][last][secondLast] = true;
            dp[pos][started][last][secondLast] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, 10, 10, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
```

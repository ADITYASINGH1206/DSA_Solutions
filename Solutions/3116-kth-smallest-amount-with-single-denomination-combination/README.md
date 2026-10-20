# [3116. Kth Smallest Amount With Single Denomination Combination](https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `binary-search`, `bit-manipulation`, `combinatorics`, `number-theory`

---

## Problem Description
You are given an integer array `coins` representing coins of different denominations and an integer `k`.

You have an infinite number of coins of each denomination. However, you are **not allowed** to combine coins of different denominations.

Return the `kth` **smallest** amount that can be made using these coins.

**Example 1:**

**Input:** coins = [3,6,9], k = 3

**Output:**  9

**Explanation:** The given coins can make the following amounts:  
Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.  
Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.  
Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.  
All of the coins combined produce: 3, 6, **9**, 12, 15, etc.

**Example 2:**

**Input:** coins = [5,2], k = 7

**Output:** 12

**Explanation:** The given coins can make the following amounts:  
Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.  
Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.  
All of the coins combined produce: 2, 4, 5, 6, 8, 10, **12**, 14, 15, etc.

**Constraints:**

* `1 <= coins.length <= 15`
* `1 <= coins[i] <= 25`
* `1 <= k <= 2 * 109`
* `coins` contains pairwise distinct integers.

---

## Solution & Editorial
# Intuition
The problem asks for the $k^{th}$ smallest value that is a multiple of at least one coin in the given set. Since the set of multiples grows monotonically, we can binary search for the answer. For a fixed value $X$, the number of multiples less than or equal to $X$ can be calculated using the Inclusion-Exclusion Principle (IEP) to avoid double-counting multiples of multiple coins (e.g., 6 is a multiple of both 2 and 3).

# Approach
1. **Preprocessing**: First, remove redundant coins. If a coin $A$ is a multiple of coin $B$, any multiple of $A$ is already a multiple of $B$. We keep only the "useful" coins.
2. **Binary Search**: The range for the $k^{th}$ smallest value is $[1, \min(coins) \times k]$. We binary search for the smallest $X$ such that the count of multiples $\le X$ is at least $k$.
3. **Inclusion-Exclusion**: To count multiples $\le X$, we iterate through all $2^m - 1$ non-empty subsets of the $m$ useful coins. For each subset, we calculate the Least Common Multiple (LCM) of its elements. If the subset size is odd, we add $\lfloor X / LCM \rfloor$ to the total; if even, we subtract it.

### Visual Trace (Example 2: coins=[5, 2], k=7)
- Useful coins: [2, 5]
- Binary Search Range: [1, 14]
- Check $X=12$:
  - Subset {2}: $\lfloor 12/2 \rfloor = 6$
  - Subset {5}: $\lfloor 12/5 \rfloor = 2$
  - Subset {2, 5}: $\lfloor 12/10 \rfloor = 1$
  - Count = $6 + 2 - 1 = 7$. Since $7 \ge k$, we narrow the search.

# Complexity
- Time complexity: $$O(2^N \cdot (N + \log(\text{max_val})))$$, where $N$ is the number of useful coins. We precompute LCMs for all $2^N$ subsets, and the binary search performs $O(\log(K \cdot \min(coins)))$ iterations, each taking $O(2^N)$ time.
- Space complexity: $$O(2^N)$$ to store the precomputed LCMs and signs for each subset.

# Code
```cpp
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<long long> useful;

        for (int coin : coins) {
            bool redundant = false;

            for (long long prev : useful) {
                if (coin % prev == 0) {
                    redundant = true;
                    break;
                }
            }

            if (!redundant) {
                useful.push_back(coin);
            }
        }

        long long high = useful[0] * 1LL * k;
        long long low = 1;

        int m = useful.size();
        int totalMasks = 1 << m;

        vector<long long> lcms(totalMasks, 1);

        vector<int> signs(totalMasks, 1);

        for (int mask = 1; mask < totalMasks; ++mask) {
            long long currentLCM = 1;
            int bits = 0;

            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    long long g = std::gcd(currentLCM, useful[i]);

                    currentLCM = currentLCM / g;

                    if (currentLCM > high / useful[i]) {
                        currentLCM = high + 1;
                        break;
                    }

                    currentLCM *= useful[i];
                    ++bits;
                }
            }

            lcms[mask] = currentLCM;

            signs[mask] = (bits % 2 == 1) ? 1 : -1;
        }

        auto count = [&](long long x) {
            long long result = 0;

            for (int mask = 1; mask < totalMasks; ++mask) {
                if (lcms[mask] <= x) {
                    result += signs[mask] * (x / lcms[mask]);
                }
            }

            return result;
        };

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
```

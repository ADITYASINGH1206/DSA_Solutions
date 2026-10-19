# [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `k`.

Find the maximum profit you can achieve. You may complete at most `k` transactions: i.e. you may buy at most `k` times and sell at most `k` times.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
```

**Example 2:**

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
```

**Constraints:**

* `1 <= k <= 100`
* `1 <= prices.length <= 1000`
* `0 <= prices[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks us to find the maximum profit by completing at most $k$ transactions. Since we can maintain the minimum effective cost of buying at each transaction level, we can model this using Dynamic Programming. Instead of keeping a full 2D table of size $O(N \times k)$, we can optimize space to $O(k)$ by tracking the minimum cost to buy (`buy`) and the maximum profit (`profit`) for each transaction count up to $k$ dynamically as we iterate through each day's price.

# Approach
1. Handle edge cases by checking if `prices` is empty; if so, return 0 immediately.
2. Initialize two vectors: `buy` of size $k + 1$ filled with `INT_MAX` representing the minimum adjusted cost to buy at transaction $i$, and `profit` of size $k + 1$ initialized to 0 representing the maximum profit achievable with at most $i$ transactions.
3. Iterate through each `price` in `prices`:
   - For each transaction index $i$ from 1 to $k$, update `buy[i] = min(buy[i], price - profit[i - 1])`, which captures the minimum effective purchase price after accounting for the profit earned from the previous transaction.
   - Update `profit[i] = max(profit[i], price - buy[i])`, which determines the maximum profit by selling at the current price using the adjusted buy cost.
4. Return `profit[k]` as the final result representing the maximum profit with at most $k$ transactions.

### Visual Walkthrough for Example 1
`k = 2`, `prices = [2, 4, 1]`

- Initial State:
  - `buy`: `[INT_MAX, INT_MAX, INT_MAX]`
  - `profit`: `[0, 0, 0]`

- Day 1 (`price = 2`):
  - $i = 1$: `buy[1] = min(INT_MAX, 2 - 0) = 2`, `profit[1] = max(0, 2 - 2) = 0`
  - $i = 2$: `buy[2] = min(INT_MAX, 2 - 0) = 2`, `profit[2] = max(0, 2 - 2) = 0`

- Day 2 (`price = 4`):
  - $i = 1$: `buy[1] = min(2, 4 - 0) = 2`, `profit[1] = max(0, 4 - 2) = 2`
  - $i = 2$: `buy[2] = min(2, 4 - 2) = 2`, `profit[2] = max(0, 4 - 2) = 2`

- Day 3 (`price = 1`):
  - $i = 1$: `buy[1] = min(2, 1 - 0) = 1`, `profit[1] = max(2, 1 - 1) = 2`
  - $i = 2$: `buy[2] = min(2, 1 - 2) = -1`, `profit[2] = max(2, 1 - (-1)) = 2`

- Final Answer: `profit[2] = 2`

# Complexity
- Time complexity: $$O(N \cdot k)$$ where $$N$$ is the number of days (`prices.size()`) and $$k$$ is the maximum number of allowed transactions. The outer loop runs $$N$$ times and the inner loop runs $$k$$ times.
- Space complexity: $$O(k)$$ since we only maintain two vectors (`buy` and `profit`) of size $$k + 1$$.

# Code
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> buy(k+1, INT_MAX);
        vector<int> profit(k+1, 0);

        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = min(buy[i], price-profit[i-1]);
                profit[i] = max(profit[i], price-buy[i]);
            }
        }

        return profit[k];
    }
};
```

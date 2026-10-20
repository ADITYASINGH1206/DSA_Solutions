# [714. Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `greedy`

---

## Problem Description
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note:**

* You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
* The transaction fee is only charged once for each stock purchase and sale.

**Example 1:**

```
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

**Example 2:**

```
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
```

**Constraints:**

* `1 <= prices.length <= 5 * 104`
* `1 <= prices[i] < 5 * 104`
* `0 <= fee < 5 * 104`

---

## Solution & Editorial
# Intuition
The problem asks us to maximize our total profit from stock transactions where each completed transaction incurs a transaction fee. We can model this using dynamic programming with two states representing whether we currently hold a stock or not, and optimize space to constant time by tracking only the previous day's states.

# Approach
1. Maintain two variables: `buy` representing the maximum profit we can have after holding a stock (effectively `-prices[i]` initially), and `sell` representing the maximum profit after not holding any stock (initially `0`).
2. Iterate through each `price` in the `prices` array.
3. Update `buy` to be the maximum of its previous value and `sell - price` (representing buying the stock today after selling previous holdings).
4. Update `sell` to be the maximum of its previous value and `buy + price - fee` (representing selling the stock today after accounting for the transaction fee).
5. Return the final `sell` profit, which guarantees the optimal maximum profit.

### Visual Trace (Example 1: prices = [1, 3, 2, 8, 4, 9], fee = 2)

| Day | Price | Action / State Transition | `buy` | `sell` |
| :--- | :--- | :--- | :--- | :--- |
| Init | - | Start | `-INF` | `0` |
| 0 | 1 | `buy = max(-INF, 0 - 1)` <br> `sell = max(0, -1 + 1 - 2)` | `-1` | `0` |
| 1 | 3 | `buy = max(-1, 0 - 3)` <br> `sell = max(0, -1 + 3 - 2)` | `-1` | `0` |
| 2 | 2 | `buy = max(-1, 0 - 2)` <br> `sell = max(0, -1 + 2 - 2)` | `-1` | `0` |
| 3 | 8 | `buy = max(-1, 0 - 8)` <br> `sell = max(0, -1 + 8 - 2)` | `-1` | `5` |
| 4 | 4 | `buy = max(-1, 5 - 4)` <br> `sell = max(5, 1 + 4 - 2)` | `1` | `5` |
| 5 | 9 | `buy = max(1, 5 - 9)` <br> `sell = max(5, 1 + 9 - 2)` | `1` | `8` |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in `prices`. We perform a single pass through the array.
- Space complexity: $$O(1)$$ auxiliary space since we only use two integer variables (`buy` and `sell`) regardless of input size.

# Code
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;

        for (int price : prices) {
            buy = max(buy, sell - price);
            sell = max(sell, buy + price - fee);
        }

        return sell;
    }
};
```

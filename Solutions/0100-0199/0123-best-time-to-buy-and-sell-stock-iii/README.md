# [123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete **at most two transactions**.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**

```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

**Example 2:**

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
```

**Example 3:**

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

**Constraints:**

* `1 <= prices.length <= 105`
* `0 <= prices[i] <= 105`

---

## Solution & Editorial
# Intuition
The problem asks for the maximum profit with at most two transactions. We can model this problem using dynamic programming with state variables tracking the minimum effective buying cost and maximum accumulated profit for both the first and second transactions.

# Approach
1. Initialize four state variables: `buy1` to track the minimum price encountered so far, `profit1` to track the maximum profit after the first transaction, `buy2` to track the minimum effective cost for the second purchase (adjusted by the profit of the first transaction), and `profit2` to track the maximum profit after the second transaction.
2. Iterate through each price in the `prices` array and update the states sequentially:
   - `buy1 = min(buy1, prices[i])`: minimizes the cost of the first buy.
   - `profit1 = max(profit1, prices[i] - buy1)`: maximizes profit of the first transaction.
   - `buy2 = min(buy2, prices[i] - profit1)`: minimizes the adjusted cost of the second buy (subtracting `profit1` models reinvesting the profit from transaction one).
   - `profit2 = max(profit2, prices[i] - buy2)`: maximizes the final profit after the second transaction.
3. Return `profit2` as the final answer.

### Visual Trace Walkthrough
Example 1: `prices = [3, 3, 5, 0, 0, 3, 1, 4]`

| Day | Price | buy1 | profit1 | buy2 | profit2 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 3 | 3 | 0 | 3 | 0 |
| 1 | 3 | 3 | 0 | 3 | 0 |
| 2 | 5 | 3 | 2 | 1 | 2 |
| 3 | 0 | 0 | 2 | -2 | 2 |
| 4 | 0 | 0 | 2 | -2 | 2 |
| 5 | 3 | 0 | 3 | 0 | 3 |
| 6 | 1 | 0 | 3 | -2 | 3 |
| 7 | 4 | 0 | 3 | 0 | 6 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in `prices`. We perform a single pass over the array.
- Space complexity: $$O(1)$$ as we only use a constant number of scalar state variables.

# Code
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())
            return 0;
        int buy1    = INT_MAX;
        int profit1 = INT_MIN;
        int buy2    = INT_MAX;
        int profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1    = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2    = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};
```

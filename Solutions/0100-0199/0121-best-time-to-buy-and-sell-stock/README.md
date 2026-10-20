# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
**Difficulty:** `Easy` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

**Example 1:**

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

**Example 2:**

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

**Constraints:**

* `1 <= prices.length <= 105`
* `0 <= prices[i] <= 104`

---

## Solution & Editorial
# Intuition
To maximize the profit from a single buy-sell transaction, we need to find the minimum stock price seen so far and simultaneously check the potential profit if we sold at the current day's price. By iterating through the prices array exactly once, we track the running minimum price and update our maximum profit dynamically.

# Approach
1. Initialize `profit` to `0` and `mins` to the first element of the `prices` array (`prices[0]`).
2. Loop through the array starting from index `1` to the end.
3. In each iteration, update `profit` as the maximum of its current value and `prices[i] - mins`.
4. Update `mins` as the minimum of its current value and `prices[i]`.
5. Return `profit` after the loop completes.

### Visual Trace Walkthrough (Example 1: `prices = [7, 1, 5, 3, 6, 4]`)
| i | prices[i] | action | profit | mins |
|---|---|---|---|---|
| - | 7 | initial | 0 | 7 |
| 1 | 1 | max(0, 1-7), min(7, 1) | 0 | 1 |
| 2 | 5 | max(0, 5-1), min(1, 5) | 4 | 1 |
| 3 | 3 | max(4, 3-1), min(1, 3) | 4 | 1 |
| 4 | 6 | max(4, 6-1), min(1, 6) | 5 | 1 |
| 5 | 4 | max(5, 4-1), min(1, 4) | 5 | 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in the `prices` array. We perform a single linear scan over the array.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra memory for tracking variables (`profit` and `mins`).

# Code
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        int mins = prices[0];
        for(int i=1;i<prices.size();i++){
            profit = max(profit,prices[i]-mins);
            mins = min(mins,prices[i]);
            
        }
        return profit;
    }
};
```

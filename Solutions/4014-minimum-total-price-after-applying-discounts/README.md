# [4014. Minimum Total Price After Applying Discounts](https://leetcode.com/problems/minimum-total-price-after-applying-discounts/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `greedy`, `sorting`

---

## Problem Description
You are given two integer arrays `prices` and `discounts`.

The value `prices[i]` represents the price of the `ith` item, and `discounts[j]` represents a discount percentage.

You may apply discounts subject to the following rules:

* Each discount can be applied to **at most** one item.
* Each item can receive **at most** one discount.
* An item may also receive no discount.

If a discount of `d` percent is applied to an item with price `p`, its final price becomes `(p * (100 - d)) / 100`. The final price is **not** rounded.

Return the **minimum** possible sum of final prices after assigning discounts optimally. Answers within `10-5` of the actual answer will be accepted.

**Example 1:**

**Input:** prices = [10,30,21], discounts = [50,60]

**Output:** 32.50000

**Explanation:**

* Apply `discounts[1] = 60` to `prices[1] = 30`, thus `30 * (100 - 60) / 100 = 12`.
* Apply `discounts[0] = 50` to `prices[2] = 21`, thus `21 * (100 - 50) / 100 = 10.5`.
* `prices[0] = 10` receives no discount, so it stays 10.

The total is `12 + 10.5 + 10 = 32.50000`, which is the minimum possible.

**Example 2:**

**Input:** prices = [100,70], discounts = [10,40,50]

**Output:** 92.00000

**Explanation:**​​​​​​​

* Apply `discounts[2] = 50` to `prices[0] = 100`, thus `100 * (100 - 50) / 100 = 50`.
* Apply `discounts[1] = 40` to `prices[1] = 70`, thus `70 * (100 - 40) / 100 = 42`.

The total is `50 + 42 = 92.00000`, which is the minimum possible.

**Example 3:**

**Input:** prices = [7,3,9], discounts = [100,100]

**Output:** 3.00000

**Explanation:**

* Apply `discounts[0] = 100` to `prices[2] = 9`, thus `9 * (100 - 100) / 100 = 0`.
* Apply `discounts[1] = 100` to `prices[0] = 7`, thus `7 * (100 - 100) / 100 = 0`.
* `prices[1] = 3` receives no discount, so it stays 3.

The total is `0 + 0 + 3 = 3.00000`, which is the minimum possible.

**Constraints:**

* `1 <= prices.length, discounts.length <= 105`
* `1 <= prices[i] <= 105`
* `1 <= discounts[j] <= 100`

---

## Solution & Editorial
# Intuition
To minimize the total price, we must maximize the absolute reduction in price for each item. Applying a discount $d$ to an item with price $p$ reduces the price by $p \times (d / 100)$. To maximize this reduction, we should greedily pair the largest prices with the largest available discount percentages.

# Approach
1. Sort the `prices` array in descending order to prioritize applying discounts to the most expensive items.
2. Sort the `discounts` array in descending order to ensure the largest percentage reductions are used first.
3. Iterate through the `prices` array. For each index $i$, if a discount exists at index $i$ (i.e., $i < \text{discounts.size()}$), apply the discount. Otherwise, add the full price to the total.

### Visual Trace (Example 1: prices=[10,30,21], discounts=[50,60])
- Sorted `prices`: `[30, 21, 10]`
- Sorted `discounts`: `[60, 50]`

| Iteration | Price | Discount | Calculation | Running Total |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 30 | 60 | $30 \times 0.4$ | 12.0 |
| 1 | 21 | 50 | $21 \times 0.5$ | 12.0 + 10.5 = 22.5 |
| 2 | 10 | N/A | 10 | 22.5 + 10 = 32.5 |

# Complexity
- Time complexity: $$O(N \log N + M \log M)$$, where $N$ is the number of prices and $M$ is the number of discounts, due to the sorting operations.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation).

# Code
```cpp
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans = 0.0;
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int n = prices.size();
        int m = discounts.size();
        for(int i = 0;i<n;i++){
            if(i<m) ans+= (double)(prices[i]*(100-discounts[i]))/100;
            else ans+= prices[i];
        }
        return ans;
    }
};
```

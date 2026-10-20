# [2706. Buy Two Chocolates](https://leetcode.com/problems/buy-two-chocolates/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given an integer array `prices` representing the prices of various chocolates in a store. You are also given a single integer `money`, which represents your initial amount of money.

You must buy **exactly** two chocolates in such a way that you still have some **non-negative** leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.

Return *the amount of money you will have leftover after buying the two chocolates*. If there is no way for you to buy two chocolates without ending up in debt, return `money`. Note that the leftover must be non-negative.

**Example 1:**

```
Input: prices = [1,2,2], money = 3
Output: 0
Explanation: Purchase the chocolates priced at 1 and 2 units respectively. You will have 3 - 3 = 0 units of money afterwards. Thus, we return 0.
```

**Example 2:**

```
Input: prices = [3,2,3], money = 3
Output: 3
Explanation: You cannot buy 2 chocolates without going in debt, so we return 3.
```

**Constraints:**

* `2 <= prices.length <= 50`
* `1 <= prices[i] <= 100`
* `1 <= money <= 100`

---

## Solution & Editorial
# Intuition
To minimize the total cost of two chocolates, we must select the two cheapest items available in the store. By sorting the `prices` array, the two smallest values are guaranteed to be at the beginning of the array.

# Approach
1. Sort the `prices` vector in non-decreasing order using `std::sort`.
2. Calculate the sum of the two smallest prices, which are located at `prices[0]` and `prices[1]`.
3. Subtract this sum from the initial `money`.
4. If the result is non-negative, return the remainder; otherwise, return the original `money` as per the problem requirements.

### Visual Trace (Example 1: prices = [1, 2, 2], money = 3)
| Step | Action | State | Result |
| :--- | :--- | :--- | :--- |
| 1 | Initial | [1, 2, 2] | - |
| 2 | Sort | [1, 2, 2] | - |
| 3 | Sum smallest | 1 + 2 = 3 | - |
| 4 | Check | 3 - 3 = 0 | 0 |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting operation, where $$N$$ is the number of chocolates.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the implementation of `std::sort`), as we perform the calculation in-place without additional data structures.

# Code
```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int m = money;
        m = m-prices[0]-prices[1];
        return m <0 ? money : m;
    }
};
```

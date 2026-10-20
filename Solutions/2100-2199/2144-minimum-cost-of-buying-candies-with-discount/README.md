# [2144. Minimum Cost of Buying Candies With Discount](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
A shop is selling candies at a discount. For **every two** candies sold, the shop gives a **third** candy for **free**.

The customer can choose **any** candy to take away for free as long as the cost of the chosen candy is less than or equal to the **minimum** cost of the two candies bought.

* For example, if there are `4` candies with costs `1`, `2`, `3`, and `4`, and the customer buys candies with costs `2` and `3`, they can take the candy with cost `1` for free, but not the candy with cost `4`.

Given a **0-indexed** integer array `cost`, where `cost[i]` denotes the cost of the `ith` candy, return *the **minimum cost** of buying **all** the candies*.

**Example 1:**

```
Input: cost = [1,2,3]
Output: 5
Explanation: We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.
```

**Example 2:**

```
Input: cost = [6,5,7,9,2,2]
Output: 23
Explanation: The way in which we can get the minimum cost is described below:
- Buy candies with costs 9 and 7
- Take the candy with cost 6 for free
- We buy candies with costs 5 and 2
- Take the last remaining candy with cost 2 for free
Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.
```

**Example 3:**

```
Input: cost = [5,5]
Output: 10
Explanation: Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
Hence, the minimum cost to buy all candies is 5 + 5 = 10.
```

**Constraints:**

* `1 <= cost.length <= 100`
* `1 <= cost[i] <= 100`

---

## Solution & Editorial
# Intuition
To minimize the total cost, we want to maximize the value of the candies we get for free. Since we get a free candy for every two purchased, we should always aim to make the most expensive candies "paid" and the cheaper ones "free". Sorting the costs in descending order allows us to greedily pick the two most expensive available candies to pay for, and then skip the next most expensive one as our free item.

# Approach
1. Sort the `cost` array in descending order (`rbegin()` to `rend()`). This places the most expensive candies at the beginning.
2. Iterate through the sorted array with a step of 3. For each group of three indices `(i, i+1, i+2)`:
   - Add `cost[i]` to the total `ans`.
   - If `i + 1` exists, add `cost[i + 1]` to `ans`.
   - Skip `cost[i + 2]` as it is the "free" candy.
3. This greedy strategy ensures that for every triplet of the most expensive remaining items, we only pay for the two highest, effectively maximizing the discount.

### Visual Trace (Example: cost = [6, 5, 7, 9, 2, 2])
- Sorted: `[9, 7, 6, 5, 2, 2]`
- Iteration 1 (i=0): Add `cost[0]` (9) and `cost[1]` (7). Skip `cost[2]` (6). `ans = 16`.
- Iteration 2 (i=3): Add `cost[3]` (5) and `cost[4]` (2). Skip `cost[5]` (2). `ans = 16 + 5 + 2 = 23`.
- Final result: 23.

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step, where $$N$$ is the number of candies. The subsequent linear scan takes $$O(N)$$.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we perform the operation in-place without additional data structures.

# Code
```cpp
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int ans = 0;
        for (int i = 0; i < cost.size(); i += 3) {
            ans += cost[i];
            if (i < cost.size() - 1) {
                ans += cost[i + 1];
            }
        }
        return ans;
    }
};
```

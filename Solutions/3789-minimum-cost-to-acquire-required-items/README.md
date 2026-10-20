# [3789. Minimum Cost to Acquire Required Items](https://leetcode.com/problems/minimum-cost-to-acquire-required-items/)
**Difficulty:** `Medium` | **Tags:** `math`, `greedy`

---

## Problem Description
You are given five integers `cost1`, `cost2`, `costBoth`, `need1`, and `need2`.

There are three types of items available:

* An item of **type 1** costs `cost1` and contributes 1 unit to the type 1 requirement only.
* An item of **type 2** costs `cost2` and contributes 1 unit to the type 2 requirement only.
* An item of **type 3** costs `costBoth` and contributes 1 unit to **both** type 1 and type 2 requirements.

You must collect enough items so that the total contribution toward type 1 is **at least** `need1` and the total contribution toward type 2 is **at least** `need2`.

Return an integer representing the **minimum** possible total cost to achieve these requirements.

**Example 1:**

**Input:** cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2

**Output:** 3

**Explanation:**

After buying three type 3 items, which cost `3 * 1 = 3`, the total contribution to type 1 is 3 (`>= need1 = 3`) and to type 2 is 3 (`>= need2 = 2`).  
Any other valid combination would cost more, so the minimum total cost is 3.

**Example 2:**

**Input:** cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3

**Output:** 22

**Explanation:**

We buy `need1 = 2` items of type 1 and `need2 = 3` items of type 2: `2 * 5 + 3 * 4 = 10 + 12 = 22`.  
Any other valid combination would cost more, so the minimum total cost is 22.

**Example 3:**

**Input:** cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0

**Output:** 0

**Explanation:**

Since no items are required (`need1 = need2 = 0`), we buy nothing and pay 0.

**Constraints:**

* `1 <= cost1, cost2, costBoth <= 106`
* `0 <= need1, need2 <= 109`

---

## Solution & Editorial
# Intuition
To minimize the total cost, we must decide whether to use individual items (type 1 and type 2) or the combined item (type 3). The core observation is that the combined item is only potentially beneficial if its cost is less than the sum of the individual costs of type 1 and type 2 items (`costBoth < cost1 + cost2`).

# Approach
1. **Evaluate Strategy**: Compare `cost1 + cost2` with `costBoth`. If `costBoth` is cheaper, we prioritize using as many type 3 items as possible.
2. **Greedy Allocation**:
   - If `costBoth < cost1 + cost2`: We first satisfy the overlapping requirement by taking `pairs = min(need1, need2)` items of type 3. Then, we satisfy the remaining `need1` or `need2` using the cheaper option between the specific item and the combined item (since the combined item can always satisfy a single requirement).
   - If `costBoth >= cost1 + cost2`: The combined item is inefficient. We simply buy `need1` items of type 1 and `need2` items of type 2.

### Visual Trace (Example 1: cost1=3, cost2=2, costBoth=1, need1=3, need2=2)
| Step | Action | costBoth < cost1+cost2 | pairs | ans | need1 | need2 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | 1 < 5 (True) | - | 0 | 3 | 2 |
| Pair | Buy 2 type 3 | - | 2 | 2 | 1 | 0 |
| Rem1 | Buy 1 type 1 | - | - | 2 + 1*1 = 3 | 0 | 0 |
| Final | - | - | - | 3 | 0 | 0 |

# Complexity
- Time complexity: $$O(1)$$. The solution performs a constant number of arithmetic operations regardless of the input size.
- Space complexity: $$O(1)$$. No auxiliary data structures are used.

# Code
```cpp
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        if (cost1 + cost2 > costBoth) {
            long long pairs = min(need1, need2);
            ans += pairs * costBoth;
            need1 -= pairs;
            need2 -= pairs;

            if (need1 > 0) {
                long long bestCost1 = min(cost1, costBoth);
                ans += (long long)need1 * bestCost1;
            }
            
            if (need2 > 0) {
                long long bestCost2 = min(cost2, costBoth);
                ans += (long long)need2 * bestCost2;
            }
        } 
        else {
            ans = ((long long)cost1 * need1) + ((long long)cost2 * need2);
        }
        
        return ans;
    }
};
```

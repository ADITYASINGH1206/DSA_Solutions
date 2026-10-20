# [1833. Maximum Ice Cream Bars](https://leetcode.com/problems/maximum-ice-cream-bars/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`, `counting-sort`

---

## Problem Description
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are `n` ice cream bars. You are given an array `costs` of length `n`, where `costs[i]` is the price of the `ith` ice cream bar in coins. The boy initially has `coins` coins to spend, and he wants to buy as many ice cream bars as possible.

**Note:** The boy can buy the ice cream bars in any order.

Return *the **maximum** number of ice cream bars the boy can buy with* `coins` *coins.*

You must solve the problem by counting sort.

**Example 1:**

```
Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
```

**Example 2:**

```
Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
```

**Example 3:**

```
Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
```

**Constraints:**

* `costs.length == n`
* `1 <= n <= 105`
* `1 <= costs[i] <= 105`
* `1 <= coins <= 108`

---

## Solution & Editorial
# Intuition
To maximize the number of ice cream bars, we must always prioritize the cheapest available options. Since the prices are bounded by a relatively small range (up to 10^5), we can use Counting Sort to avoid the O(N log N) overhead of standard sorting, achieving linear time complexity.

# Approach
1. Identify the maximum price in `costs` to determine the range for our frequency array. Create a frequency array `freq` of size `max_price + 1`.
2. Iterate through `costs` to populate `freq`, where `freq[i]` stores the count of ice cream bars costing `i` coins.
3. Iterate through the `freq` array from index 1 to `max_price`. For each price `i` with `count = freq[i]`:
   - If the total cost of these bars (`i * count`) is less than or equal to `coins`, subtract this total from `coins` and add `count` to our answer.
   - If we cannot afford all bars of price `i`, calculate how many we can afford (`coins / i`), add that to the answer, and terminate.

### Visual Trace (Example 1: costs = [1,3,2,4,1], coins = 7)
| Price (i) | Freq[i] | Remaining Coins | Count Added | Total Bars |
|-----------|---------|-----------------|-------------|------------|
| 1         | 2       | 7 - (1*2) = 5   | 2           | 2          |
| 2         | 1       | 5 - (2*1) = 3   | 1           | 3          |
| 3         | 1       | 3 - (3*1) = 0   | 1           | 4          |
| 4         | 1       | 0 < 4 (Break)   | 0           | 4          |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the number of ice cream bars and $$M$$ is the maximum price. We iterate through the input once to count and then through the frequency array once.
- Space complexity: $$O(M)$$, where $$M$$ is the maximum price, required for the frequency array.

# Code
```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        for(int x:costs){
            if(x>coins)break;
            ans++;
            coins-=x;
        }
        return ans;
    }
};
```

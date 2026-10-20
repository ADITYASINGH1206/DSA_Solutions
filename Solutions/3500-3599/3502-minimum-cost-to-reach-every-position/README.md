# [3502. Minimum Cost to Reach Every Position](https://leetcode.com/problems/minimum-cost-to-reach-every-position/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
You are given an integer array `cost` of size `n`. You are currently at position `n` (at the end of the line) in a line of `n + 1` people (numbered from 0 to `n`).

You wish to move forward in the line, but each person in front of you charges a specific amount to **swap** places. The cost to swap with person `i` is given by `cost[i]`.

You are allowed to swap places with people as follows:

* If they are in front of you, you **must** pay them `cost[i]` to swap with them.
* If they are behind you, they can swap with you for free.

Return an array `answer` of size `n`, where `answer[i]` is the **minimum** total cost to reach each position `i` in the line.

**Example 1:**

**Input:** cost = [5,3,4,1,3,2]

**Output:** [5,3,3,1,1,1]

**Explanation:**

We can get to each position in the following way:

* `i = 0`. We can swap with person 0 for a cost of 5.
* `i = 1`. We can swap with person 1 for a cost of 3.
* `i = 2`. We can swap with person 1 for a cost of 3, then swap with person 2 for free.
* `i = 3`. We can swap with person 3 for a cost of 1.
* `i = 4`. We can swap with person 3 for a cost of 1, then swap with person 4 for free.
* `i = 5`. We can swap with person 3 for a cost of 1, then swap with person 5 for free.

**Example 2:**

**Input:** cost = [1,2,4,6,7]

**Output:** [1,1,1,1,1]

**Explanation:**

We can swap with person 0 for a cost of 1, then we will be able to reach any position `i` for free.

**Constraints:**

* `1 <= n == cost.length <= 100`
* `1 <= cost[i] <= 100`

---

## Solution & Editorial
# Intuition
To reach any position `i`, we must pay the cost of swapping with some person `j` (where `j <= i`) and then potentially move to `i` for free. Since we want to minimize the total cost to reach `i`, we should choose the person `j` in the range `[0, i]` who has the minimum `cost[j]`.

# Approach
1. Initialize an `ans` vector to store the minimum cost for each position.
2. The cost to reach position `0` is simply `cost[0]`.
3. For any subsequent position `i`, the minimum cost to reach it is the minimum of the cost to reach the previous position (`ans[i-1]`) and the cost to swap with the current person (`cost[i]`).
4. This effectively maintains a running prefix minimum of the `cost` array.

### Visual Trace (Example 1: cost = [5, 3, 4, 1, 3, 2])
| i | cost[i] | ans[i-1] | ans[i] = min(ans[i-1], cost[i]) |
|---|---------|----------|----------------------------------|
| 0 | 5       | -        | 5                                |
| 1 | 3       | 5        | 3                                |
| 2 | 4       | 3        | 3                                |
| 3 | 1       | 3        | 1                                |
| 4 | 3       | 1        | 1                                |
| 5 | 2       | 1        | 1                                |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the `cost` array, as we iterate through the array exactly once.
- Space complexity: $$O(N)$$ to store the result array of size $$N$.

# Code
```cpp
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int n = cost.size();
        ans.push_back(cost[0]);
        for(int i = 1;i<n;i++){
            ans.push_back(min(ans.back(),cost[i]));

        }
        return ans;
    }
};
```

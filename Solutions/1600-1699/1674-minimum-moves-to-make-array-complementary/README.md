# [1674. Minimum Moves to Make Array Complementary](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` of **even** length `n` and an integer `limit`. In one move, you can replace any integer from `nums` with another integer between `1` and `limit`, inclusive.

The array `nums` is **complementary** if for all indices `i` (**0-indexed**), `nums[i] + nums[n - 1 - i]` equals the same number. For example, the array `[1,2,3,4]` is complementary because for all indices `i`, `nums[i] + nums[n - 1 - i] = 5`.

Return the ***minimum** number of moves required to make* `nums` ***complementary***.

**Example 1:**

```
Input: nums = [1,2,4,3], limit = 4
Output: 1
Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined elements are changed).
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
```

**Example 2:**

```
Input: nums = [1,2,2,1], limit = 2
Output: 2
Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot change any number to 3 since 3 > limit.
```

**Example 3:**

```
Input: nums = [1,2,1,2], limit = 2
Output: 0
Explanation: nums is already complementary.
```

**Constraints:**

* `n == nums.length`
* `2 <= n <= 105`
* `1 <= nums[i] <= limit <= 105`
* `n` is even.

---

## Solution & Editorial
# Intuition
To make the array complementary, every pair `(nums[i], nums[n-1-i])` must sum to the same target value `T`. For a fixed pair `(a, b)` with `a <= b`, the number of moves required to reach a target sum `T` depends on the range of possible sums achievable by changing one or both elements: 
1. **0 moves**: If `a + b == T`.
2. **1 move**: If `min(a, b) + 1 <= T <= max(a, b) + limit`.
3. **2 moves**: Otherwise.

Since we need to find a `T` that minimizes the total moves across all pairs, we can use a **Difference Array** to track the change in the number of moves as `T` varies from `2` to `2 * limit`.

# Approach
1. Initialize a difference array `d` of size `2 * limit + 2` with zeros.
2. For each pair `(a, b)` (where `a = nums[i]` and `b = nums[n-1-i]`): 
   - Let `min_val = min(a, b)` and `max_val = max(a, b)`.
   - The range of sums is `[2, 2 * limit]`.
   - Default cost is 2 moves for all `T`.
   - Cost becomes 1 move for `T` in `[min_val + 1, max_val + limit]`.
   - Cost becomes 0 moves for `T == min_val + max_val`.
   - Apply these updates to the difference array `d` to reflect the cost transitions.
3. Compute the prefix sum of `d` to find the total moves for every possible target sum `T` and return the minimum.

### Visual Trace (Example 1: nums=[1,2,4,3], limit=4)
- Pairs: (1, 3) and (2, 4).
- For (1, 3): min=1, max=3. Cost 0 at T=4, Cost 1 at [2, 1] (invalid) and [4, 7], Cost 2 elsewhere.
- After processing all pairs, the prefix sum of `d` gives the total moves for each `T`.

# Complexity
- Time complexity: $$O(N + L)$$, where $$N$$ is the length of the array and $$L$$ is the limit. We iterate through the array once ($$N/2$$ pairs) and then iterate through the difference array of size $$2L$$.
- Space complexity: $$O(L)$$, required for the difference array of size $$2L + 2$$.

# Code
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int d[limit * 2 + 2];
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n / 2; ++i) {
            int x = nums[i], y = nums[n - i - 1];
            if (x > y) {
                swap(x, y);
            }
            d[2] += 2;
            d[x + 1] -= 2;
            d[x + 1] += 1;
            d[x + y] -= 1;
            d[x + y + 1] += 1;
            d[y + limit + 1] -= 1;
            d[y + limit + 1] += 2;
        }
        int ans = n;
        for (int i = 2, s = 0; i <= limit * 2; ++i) {
            s += d[i];
            ans = min(ans, s);
        }
        return ans;
    }
};
```

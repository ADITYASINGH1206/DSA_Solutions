# [1658. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `binary-search`, `sliding-window`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.

Return *the **minimum number** of operations to reduce* `x` *to **exactly*** `0` *if it is possible**, otherwise, return* `-1`.

**Example 1:**

```
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
```

**Example 2:**

```
Input: nums = [5,6,7,8,9], x = 4
Output: -1
```

**Example 3:**

```
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 104`
* `1 <= x <= 109`

---

## Solution & Editorial
# Intuition
Instead of directly searching for the prefix and suffix that sum to `x`, we can reframe the problem: finding the minimum number of elements to remove from the ends is equivalent to finding the **longest contiguous subarray** whose sum is exactly `total_sum - x`.

# Approach
1. Calculate the `target` sum as `total_sum - x`. If `target < 0`, it is impossible to reduce `x` to zero, so return `-1`.
2. Use a sliding window (two pointers `i` and `j`) to find the longest subarray with sum equal to `target`.
3. Expand the window by incrementing `j` and adding `A[j]` to `sum`.
4. If `sum` exceeds `target`, shrink the window from the left by incrementing `i` and subtracting `A[i]` until `sum <= target`.
5. If `sum == target`, update `best` with the maximum window length `j - i + 1`.
6. The final answer is `n - best`. If no such subarray exists, return `-1`.

### Visual Trace (Example 1: nums = [1,1,4,2,3], x = 5)
- `total_sum` = 11, `target` = 11 - 5 = 6.
- Window [1, 1, 4]: `sum` = 6. `best` = 3.
- Window [1, 4, 2]: `sum` = 7 (too large), shrink to [4, 2], `sum` = 6. `best` = max(3, 2) = 3.
- Result: `n - best` = 5 - 3 = 2.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. Each element is visited at most twice (once by `j` and once by `i`).
- Space complexity: $$O(1)$$, as we only use a few integer variables for tracking the window state.

# Code
```cpp
class Solution {
public:
    int minOperations(vector<int>& A, int x) {
        int k = reduce(A.begin(), A.end()) - x;
        if (k < 0)
            return -1;

        int best = -1, i = 0, sum = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            sum += A[j];
            while (sum > k)
                sum -= A[i++];

            if (sum == k)
                best = max(best, j - i + 1);
        }

        return best < 0 ? -1 : n - best;
    }
};
```

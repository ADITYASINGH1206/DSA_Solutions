# [2033. Minimum Operations to Make a Uni-Value Grid](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `sorting`, `matrix`

---

## Problem Description
You are given a 2D integer `grid` of size `m x n` and an integer `x`.

In one operation, you can **add** `x` to or **subtract** `x` from any element in the `grid`.

A **uni-value grid** is a grid where all the elements of it are equal.

Return the **minimum** number of operations to make the grid **uni-value**. If it is not possible, return -1.

**Example 1:**

```
Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.
```

**Example 2:**

```
Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.
```

**Example 3:**

```
Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 105`
* `1 <= m * n <= 105`
* `1 <= x, grid[i][j] <= 104`

---

## Solution & Editorial
# Intuition
To make all elements in the grid equal to some target value $T$ using operations of adding or subtracting $x$, two conditions must be met: 
1. Every element $A_{i,j}$ must satisfy $A_{i,j} \equiv T \pmod x$. This implies all elements in the grid must have the same remainder when divided by $x$.
2. The problem of minimizing $\sum |A_{i,j} - T| / x$ is equivalent to finding a value $T$ that minimizes the sum of absolute differences, which is a classic property of the **median**.

# Approach
1. **Validation**: First, verify if all elements have the same remainder modulo $x$. If any element differs, return -1.
2. **Flattening**: Store all grid elements into a 1D array `nums` to simplify processing.
3. **Sorting**: Sort the `nums` array to easily identify the median.
4. **Median Calculation**: The median of the sorted array minimizes the sum of absolute deviations. Pick the element at index `(m * n) / 2` as the target value `mid`.
5. **Summation**: Calculate the total operations by summing `abs(v - mid) / x` for every element `v` in `nums`.

### Visual Trace (Example 1: grid = [[2,4],[6,8]], x = 2)
- Flattened: `[2, 4, 6, 8]`
- Sorted: `[2, 4, 6, 8]`
- Median: `nums[4/2]` = `nums[2]` = `6` (Note: any value between 4 and 6 works for even length, 6 is chosen here).
- Operations: `|2-6|/2 + |4-6|/2 + |6-6|/2 + |8-6|/2` = `2 + 1 + 0 + 1` = `4`.

# Complexity
- Time complexity: $$O(N \log N)$$, where $N = m \times n$. The bottleneck is sorting the flattened array of size $N$.
- Space complexity: $$O(N)$$, required to store the flattened grid elements.

# Code
```cpp
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int mod = grid[0][0] % x;
        int nums[m * n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] % x != mod) {
                    return -1;
                }
                nums[i * n + j] = grid[i][j];
            }
        }
        sort(nums, nums + m * n);
        int mid = nums[(m * n) >> 1];
        int ans = 0;
        for (int v : nums) {
            ans += abs(v - mid) / x;
        }
        return ans;
    }
};
```

# [1536. Minimum Swaps to Arrange a Binary Grid](https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `matrix`

---

## Problem Description
Given an `n x n` binary `grid`, in one step you can choose two **adjacent rows** of the grid and swap them.

A grid is said to be **valid** if all the cells above the main diagonal are **zeros**.

Return *the minimum number of steps* needed to make the grid valid, or **-1** if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell `(1, 1)` and ends at cell `(n, n)`.

**Example 1:**

```
Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
Output: 3
```

**Example 2:**

```
Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
Output: -1
Explanation: All rows are similar, swaps have no effect on the grid.
```

**Example 3:**

```
Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
Output: 0
```

**Constraints:**

* `n == grid.length` `== grid[i].length`
* `1 <= n <= 200`
* `grid[i][j]` is either `0` or `1`

---

## Solution & Editorial
# Intuition
To make the grid valid, each row `i` must have all zeros above the main diagonal, meaning the rightmost `1` in row `i` must be at an index `j <= i`. Since we can only swap adjacent rows, this is a classic greedy problem: for each row from top to bottom, we find the nearest row below it that satisfies the condition and "bubble" it up to the current position.

# Approach
1. Pre-calculate the position of the rightmost `1` for every row. Store these in a vector `pos` where `pos[i]` is the index of the last `1` in row `i`.
2. Iterate through each row `i` from `0` to `n-1`. We need a row that satisfies `pos[row] <= i`.
3. For each `i`, search for the first row `j` (where `j >= i`) in the current `pos` array such that `pos[j] <= i`.
4. If no such row exists, it is impossible to satisfy the condition; return `-1`.
5. If found at index `j`, the number of swaps required to bring this row to position `i` is `j - i`. Add this to the total `ans` and shift the elements in `pos` to reflect the row swap.

### Visual Trace (Example 1: grid = [[0,0,1],[1,1,0],[1,0,0]])
- Initial `pos`: `[2, 1, 0]`
- `i = 0`: Need `pos[j] <= 0`. Found `j = 2` (value 0). Swaps: `2 - 0 = 2`. `pos` becomes `[0, 2, 1]`.
- `i = 1`: Need `pos[j] <= 1`. Found `j = 1` (value 2). Wait, `pos[1]` is 2, `pos[2]` is 1. Found `j = 2` (value 1). Swaps: `2 - 1 = 1`. `pos` becomes `[0, 1, 2]`.
- `i = 2`: Need `pos[j] <= 2`. Found `j = 2` (value 2). Swaps: 0.
- Total `ans = 2 + 1 = 3`.

# Complexity
- Time complexity: $$O(n^2)$$. We iterate through `n` rows, and for each, we perform a linear scan and a potential shift operation, both bounded by $$O(n)$$.
- Space complexity: $$O(n)$$ to store the `pos` array.

# Code
```cpp
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> pos(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    pos[i] = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = i; j < n; ++j) {
                if (pos[j] <= i) {
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if (k == -1) {
                return -1;
            }
            for (; k > i; --k) {
                swap(pos[k], pos[k - 1]);
            }
        }
        return ans;
    }
};
```

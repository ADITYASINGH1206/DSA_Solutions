# [3548. Equal Sum Grid Partition II](https://leetcode.com/problems/equal-sum-grid-partition-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `matrix`, `enumeration`, `prefix-sum`

---

## Problem Description
You are given an `m x n` matrix `grid` of positive integers. Your task is to determine if it is possible to make **either one horizontal or one vertical cut** on the grid such that:

* Each of the two resulting sections formed by the cut is **non-empty**.
* The sum of elements in both sections is **equal**, or can be made equal by discounting **at most** one single cell in total (from either section).
* If a cell is discounted, the rest of the section must **remain connected**.

Return `true` if such a partition exists; otherwise, return `false`.

**Note:** A section is **connected** if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.

**Example 1:**

**Input:** grid = [[1,4],[2,3]]

**Output:** true

**Explanation:**

* A horizontal cut after the first row gives sums `1 + 4 = 5` and `2 + 3 = 5`, which are equal. Thus, the answer is `true`.

**Example 2:**

**Input:** grid = [[1,2],[3,4]]

**Output:** true

**Explanation:**

* A vertical cut after the first column gives sums `1 + 3 = 4` and `2 + 4 = 6`.
* By discounting 2 from the right section (`6 - 2 = 4`), both sections have equal sums and remain connected. Thus, the answer is `true`.

**Example 3:**

**Input:** grid = [[1,2,4],[2,3,5]]

**Output:** false

**Explanation:**

* A horizontal cut after the first row gives `1 + 2 + 4 = 7` and `2 + 3 + 5 = 10`.
* By discounting 3 from the bottom section (`10 - 3 = 7`), both sections have equal sums, but they do not remain connected as it splits the bottom section into two parts (`[2]` and `[5]`). Thus, the answer is `false`.

**Example 4:**

**Input:** grid = [[4,1,8],[3,2,6]]

**Output:** false

**Explanation:**

No valid cut exists, so the answer is `false`.

**Constraints:**

* `1 <= m == grid.length <= 105`
* `1 <= n == grid[i].length <= 105`
* `2 <= m * n <= 105`
* `1 <= grid[i][j] <= 105`

---

## Solution & Editorial
# Intuition
The problem asks if we can partition a grid into two sections with equal sums, allowing for the removal of at most one cell. The core observation is that a horizontal cut is equivalent to a vertical cut on the transposed grid. By checking both orientations, we simplify the problem to iterating through all possible cut positions and verifying if the sum difference can be resolved by removing a single cell while maintaining connectivity.

# Approach
1. **Symmetry**: We define a `check` function that evaluates horizontal cuts. To handle vertical cuts, we transpose the grid and pass it to the same `check` function.
2. **Prefix Sums**: As we iterate through rows (the cut position `i`), we maintain the running sum of the top section (`s1`) and the bottom section (`s2`). We use hash maps (`cnt1`, `cnt2`) to track the frequency of elements in each section.
3. **Validation**: 
   - If `s1 == s2`, the condition is met immediately.
   - If `s1 != s2`, we calculate the `diff = abs(s1 - s2)`. If `diff` exists in the section with the larger sum, we check if removing that cell keeps the remaining section connected. 
   - Connectivity is guaranteed if the section has more than one row and more than one column, or if the removed cell is at a corner (edge case for narrow grids).

### Visual Trace (Example 2: [[1,2],[3,4]])
- Initial: `s1=0, s2=10, cnt2={1:1, 2:1, 3:1, 4:1}`
- Cut after row 0: `s1=3, s2=7, cnt1={1:1, 2:1}, cnt2={3:1, 4:1}`
- `diff = 7 - 3 = 4`. `4` exists in `cnt2`. 
- Connectivity check: `n=2 > 1`, so removing `4` leaves `[3]` connected. Return `true`.

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ and $$N$$ are grid dimensions. We traverse the grid once for the horizontal check and once for the transposed vertical check.
- Space complexity: $$O(M \times N)$$ to store the frequency maps of elements in the grid.

# Code
```cpp
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        return check(grid) || check(rotate(grid));
    }

private:
    bool check(const vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        long long s1 = 0, s2 = 0;

        unordered_map<long long, int> cnt1, cnt2;

        for (auto& row : g) {
            for (int x : row) {
                s2 += x;
                cnt2[x]++;
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int x : g[i]) {
                s1 += x;
                s2 -= x;
                cnt1[x]++;
                cnt2[x]--;
            }

            if (s1 == s2) return true;

            if (s1 < s2) {
                long long diff = s2 - s1;
                if (cnt2[diff] > 0) {
                    if (
                        (m - i - 1 > 1 && n > 1) || (i == m - 2 && (g[i + 1][0] == diff || g[i + 1][n - 1] == diff)) || (n == 1 && (g[i + 1][0] == diff || g[m - 1][0] == diff))) return true;
                }
            } else {
                long long diff = s1 - s2;
                if (cnt1[diff] > 0) {
                    if (
                        (i + 1 > 1 && n > 1) || (i == 0 && (g[0][0] == diff || g[0][n - 1] == diff)) || (n == 1 && (g[0][0] == diff || g[i][0] == diff))) return true;
                }
            }
        }

        return false;
    }

    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> t(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                t[j][i] = grid[i][j];
            }
        }
        return t;
    }
};
```

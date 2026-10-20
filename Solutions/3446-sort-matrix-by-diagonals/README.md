# [3446. Sort Matrix by Diagonals](https://leetcode.com/problems/sort-matrix-by-diagonals/)
**Difficulty:** `Medium` | **Tags:** `array`, `sorting`, `matrix`

---

## Problem Description
You are given an `n x n` square matrix of integers `grid`. Return the matrix such that:

* The diagonals in the **bottom-left triangle** (including the middle diagonal) are sorted in **non-increasing order**.
* The diagonals in the **top-right triangle** are sorted in **non-decreasing order**.

**Example 1:**

**Input:** grid = [[1,7,3],[9,8,2],[4,5,6]]

**Output:** [[8,2,3],[9,6,7],[4,5,1]]

**Explanation:**

The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

* `[1, 8, 6]` becomes `[8, 6, 1]`.
* `[9, 5]` and `[4]` remain unchanged.

The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

* `[7, 2]` becomes `[2, 7]`.
* `[3]` remains unchanged.

**Example 2:**

**Input:** grid = [[0,1],[1,2]]

**Output:** [[2,1],[1,0]]

**Explanation:**

The diagonals with a black arrow must be non-increasing, so `[0, 2]` is changed to `[2, 0]`. The other diagonals are already in the correct order.

**Example 3:**

**Input:** grid = [[1]]

**Output:** [[1]]

**Explanation:**

Diagonals with exactly one element are already in order, so no changes are needed.

**Constraints:**

* `grid.length == grid[i].length == n`
* `1 <= n <= 10`
* `-105 <= grid[i][j] <= 105`

---

## Solution & Editorial
# Intuition
The problem requires sorting elements along diagonals of an $n \times n$ matrix. Diagonals are defined by the invariant $i - j = k$. By iterating through all possible starting points for these diagonals, we can extract the elements, sort them according to the specified order (non-increasing for the bottom-left, non-decreasing for the top-right), and write them back into the grid.

# Approach
1. **Bottom-Left Triangle**: These diagonals start at $(i, 0)$ for $i$ from $n-1$ down to $0$. We collect elements by traversing $(row, col)$ where $row$ and $col$ increment simultaneously until the boundary $n$ is reached. We sort these in descending order (`rbegin`, `rend`) and re-insert them.
2. **Top-Right Triangle**: These diagonals start at $(0, j)$ for $j$ from $n-1$ down to $1$. We collect elements similarly, but sort them in ascending order (`begin`, `end`) and re-insert them.

### Visual Trace (Example 1: 3x3)
- **Bottom-Left**: 
  - Start (2,0): `[4]` -> sorted `[4]`
  - Start (1,0): `[9, 5]` -> sorted `[9, 5]`
  - Start (0,0): `[1, 8, 6]` -> sorted `[8, 6, 1]`
- **Top-Right**:
  - Start (0,2): `[3]` -> sorted `[3]`
  - Start (0,1): `[7, 2]` -> sorted `[2, 7]`

# Complexity
- Time complexity: $$O(N^2 \log N)$$. There are $2N-1$ diagonals. The longest diagonal has length $N$. Sorting each diagonal takes $O(N \log N)$. Summing over all diagonals, we get $O(N^2 \log N)$.
- Space complexity: $$O(N)$$. We use an auxiliary vector to store elements of a single diagonal, which has a maximum size of $N$.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid;
        
        int srow = n - 1, scol = 0;
        int k = 0;
        while(k < n){
            vector<int> elements;
            int row = srow, col = scol;
            int erow = n, ecol = n; 
            while(row < erow && col < ecol){
                elements.push_back(grid[row][col]);
                row++, col++;
            }
            sort(elements.rbegin(), elements.rend());
            
            int l = 0;
            row = srow, col = scol;
            while(row < erow && col < ecol){
                grid[row][col] = elements[l];
                l++, row++, col++;
            }
            
            k++;
            srow--; 
        }
        k = 0;
        srow=0,scol =n-1;
        while(k<n-1){
            vector<int> elements;
            int row = srow, col = scol;
            int erow = n, ecol = n; 
            while(row < erow && col < ecol){
                elements.push_back(grid[row][col]);
                row++, col++;
            }
            sort(elements.begin(), elements.end());
            
            int l = 0;
            row = srow, col = scol;
            while(row < erow && col < ecol){
                grid[row][col] = elements[l];
                l++, row++, col++;
            }
            
            k++;
            scol--; 
        }
        
        return grid;
    }
};
```

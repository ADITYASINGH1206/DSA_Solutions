# [1030. Matrix Cells in Distance Order](https://leetcode.com/problems/matrix-cells-in-distance-order/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `geometry`, `sorting`, `matrix`

---

## Problem Description
You are given four integers `row`, `cols`, `rCenter`, and `cCenter`. There is a `rows x cols` matrix and you are on the cell with the coordinates `(rCenter, cCenter)`.

Return *the coordinates of all cells in the matrix, sorted by their **distance** from* `(rCenter, cCenter)` *from the smallest distance to the largest distance*. You may return the answer in **any order** that satisfies this condition.

The **distance** between two cells `(r1, c1)` and `(r2, c2)` is `|r1 - r2| + |c1 - c2|`.

**Example 1:**

```
Input: rows = 1, cols = 2, rCenter = 0, cCenter = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (0, 0) to other cells are: [0,1]
```

**Example 2:**

```
Input: rows = 2, cols = 2, rCenter = 0, cCenter = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (0, 1) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
```

**Example 3:**

```
Input: rows = 2, cols = 3, rCenter = 1, cCenter = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (1, 2) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
```

**Constraints:**

* `1 <= rows, cols <= 100`
* `0 <= rCenter < rows`
* `0 <= cCenter < cols`

---

## Solution & Editorial
# Intuition
The problem asks us to order all cells of a given `rows x cols` matrix based on their Manhattan distance from a specified center cell `(rCenter, cCenter)`. Since the total number of cells is small ($N = \text{rows} \times \text{cols} \le 100 \times 100 = 10000$), we can simply collect all coordinates into a list and sort them using a custom comparator based on the Manhattan distance formula.

# Approach
1. Initialize a 2D vector `ans` to store the coordinates of all matrix cells.
2. Iterate through all possible row indices `i` from `0` to `rows - 1` and column indices `j` from `0` to `cols - 1`, pushing each pair `{i, j}` into `ans`.
3. Sort the `ans` vector using `std::sort` with a lambda comparator. The comparator computes the Manhattan distance `|r - rCenter| + |c - cCenter|` for each cell `a` and `b`, ordering them in ascending order of distance.
4. Return the sorted `ans` vector.

### Visual Walkthrough (Example 1)
Inputs: `rows = 1, cols = 2, rCenter = 0, cCenter = 0`

- Cell Generation:
  - `i = 0, j = 0` -> pushes `[0, 0]`
  - `i = 0, j = 1` -> pushes `[0, 1]`
  - `ans` before sort: `[[0, 0], [0, 1]]`
- Distance Calculation:
  - Distance for `[0, 0]`: `|0 - 0| + |0 - 0| = 0`
  - Distance for `[0, 1]`: `|0 - 0| + |1 - 0| = 1`
- Sorted Output: `[[0, 0], [0, 1]]`

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N = \text{rows} \times \text{cols}$$. Generating all cells takes $$O(N)$$ time, and sorting $$N$$ elements takes $$O(N \log N)$$ time. Computing the Manhattan distance inside the comparator takes $$O(1)$$ time per comparison.
- Space complexity: $$O(N)$$ to store all coordinate pairs in the result vector `ans` (excluding output space, the auxiliary space is $$O(\log N)$$ or $$O(N)$$ depending on the sorting implementation).

# Code
```cpp
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        for(int i = 0;i<rows;i++){
            for(int j =0;j<cols;j++){
                ans.push_back({i,j});
            }
        }

        sort(ans.begin(),ans.end(),[&rCenter,&cCenter](const vector<int>& a,const vector<int>& b){
            return abs(a[0]-rCenter)+abs(a[1]-cCenter) < abs(b[0]-rCenter)+abs(b[1]-cCenter);
        });

        return ans;
    }
};
```

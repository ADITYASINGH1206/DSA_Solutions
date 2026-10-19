# [1252. Cells with Odd Values in a Matrix](https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `simulation`

---

## Problem Description
There is an `m x n` matrix that is initialized to all `0`'s. There is also a 2D array `indices` where each `indices[i] = [ri, ci]` represents a **0-indexed location** to perform some increment operations on the matrix.

For each location `indices[i]`, do **both** of the following:

1. Increment **all** the cells on row `ri`.
2. Increment **all** the cells on column `ci`.

Given `m`, `n`, and `indices`, return *the **number of odd-valued cells** in the matrix after applying the increment to all locations in* `indices`.

**Example 1:**

```
Input: m = 2, n = 3, indices = [[0,1],[1,1]]
Output: 6
Explanation: Initial matrix = [[0,0,0],[0,0,0]].
After applying first increment it becomes [[1,2,1],[0,1,0]].
The final matrix is [[1,3,1],[1,3,1]], which contains 6 odd numbers.
```

**Example 2:**

```
Input: m = 2, n = 2, indices = [[1,1],[0,0]]
Output: 0
Explanation: Final matrix = [[2,2],[2,2]]. There are no odd numbers in the final matrix.
```

**Constraints:**

* `1 <= m, n <= 50`
* `1 <= indices.length <= 100`
* `0 <= ri < m`
* `0 <= ci < n`

**Follow up:** Could you solve this in `O(n + m + indices.length)` time with only `O(n + m)` extra space?

---

## Solution & Editorial
# Intuition
The final value of any cell $(i, j)$ in the matrix is determined by the total number of times its row $i$ was incremented plus the total number of times its column $j$ was incremented. Instead of performing matrix updates for every single index operation, we can precompute the frequency of each row and column being targeted using hash maps, construct the final matrix values, and then count how many cells end up with an odd value.

# Approach
1. Initialize an integer `ans` to 0, an `m x n` matrix `mat` filled with zeros, and two hash maps `row` and `cols` to track the increment counts for each row and column respectively.
2. Iterate through the `indices` array and increment `row[indices[i][0]]` for each row index and `cols[indices[i][1]]` for each column index.
3. Iterate over every cell $(i, j)$ in the `m x n` matrix. Add the corresponding row count `row[i]` and column count `cols[j]` to `mat[i][j]`.
4. Iterate through `mat` once more, checking if each cell value modulo 2 is non-zero (odd). Increment `ans` for every odd cell found.
5. Return `ans`.

### Visual Walkthrough (Example 1)
Given `m = 2`, `n = 3`, `indices = [[0,1],[1,1]]`
- **Row increments**: `row[0] = 1`, `row[1] = 1`
- **Col increments**: `cols[1] = 2`
- **Matrix cell accumulation (`mat[i][j] = row[i] + cols[j]`)**:
  - `mat[0][0] = row[0] + cols[0] = 1 + 0 = 1`
  - `mat[0][1] = row[0] + cols[1] = 1 + 2 = 3`
  - `mat[0][2] = row[0] + cols[2] = 1 + 0 = 1`
  - `mat[1][0] = row[1] + cols[0] = 1 + 0 = 1`
  - `mat[1][1] = row[1] + cols[1] = 1 + 2 = 3`
  - `mat[1][2] = row[1] + cols[2] = 1 + 0 = 1`
- **Final Matrix**: `[[1, 3, 1], [1, 3, 1]]` (All 6 cells are odd).
- **Output**: `6`

# Complexity
- Time complexity: $$O(m \cdot n + L)$$ where $L$ is the number of elements in `indices`. Iterating through `indices` takes $$O(L)$$ time, populating the matrix takes $$O(m \cdot n)$$ time, and final counting takes $$O(m \cdot n)$$ time.
- Space complexity: $$O(m \cdot n + U)$$ where $U$ is the number of unique rows and columns stored in hash maps `row` and `cols`, and the auxiliary matrix `mat` takes $$O(m \cdot n)$$ space.

# Code
```cpp
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int ans = 0;
        vector<vector<int>> mat(m,vector<int>(n,0));
        int x = indices.size();
        unordered_map<int,int> row;
        unordered_map<int,int> cols;
        for(int i =0;i<x;i++){
            row[indices[i][0]]++;
        }
        for(int i =0;i<x;i++){
            cols[indices[i][1]]++;
        }
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(row[i]) mat[i][j] += row[i];
                if(cols[j]) mat[i][j] += cols[j];
            }
        }
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j]%2 != 0) ans++;
            }
        }
        return ans;

    }
};
```

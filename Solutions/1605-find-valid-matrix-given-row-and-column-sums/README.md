# [1605. Find Valid Matrix Given Row and Column Sums](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `matrix`, `flow-network`

---

## Problem Description
You are given two arrays `rowSum` and `colSum` of non-negative integers where `rowSum[i]` is the sum of the elements in the `ith` row and `colSum[j]` is the sum of the elements of the `jth` column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of **non-negative** integers of size `rowSum.length x colSum.length` that satisfies the `rowSum` and `colSum` requirements.

Return *a 2D array representing **any** matrix that fulfills the requirements*. It's guaranteed that **at least one** matrix that fulfills the requirements exists.

**Example 1:**

```
Input: rowSum = [3,8], colSum = [4,7]
Output: [[3,0],
         [1,7]]
Explanation: 
0th row: 3 + 0 = 3 == rowSum[0]
1st row: 1 + 7 = 8 == rowSum[1]
0th column: 3 + 1 = 4 == colSum[0]
1st column: 0 + 7 = 7 == colSum[1]
The row and column sums match, and all matrix elements are non-negative.
Another possible matrix is: [[1,2],
                             [3,5]]
```

**Example 2:**

```
Input: rowSum = [5,7,10], colSum = [8,6,8]
Output: [[0,5,0],
         [6,1,0],
         [2,0,8]]
```

**Constraints:**

* `1 <= rowSum.length, colSum.length <= 500`
* `0 <= rowSum[i], colSum[i] <= 108`
* `sum(rowSum) == sum(colSum)`

---

## Solution & Editorial
# Intuition
To construct a matrix satisfying given row and column sums, we can greedily fill each cell. Since the total sum of rows equals the total sum of columns, we can iterate through the matrix and at each cell `(i, j)`, assign the maximum possible value that doesn't violate the remaining constraints for the current row or column.

# Approach
1. Initialize a result matrix of size `numRows x numCols` with zeros.
2. Use two pointers, `i` for rows and `j` for columns, both starting at 0.
3. At each step, calculate `val = min(rowSum[i], colSum[j])`. This value is the largest amount we can place at `result[i][j]` without exceeding the remaining sum required for either the current row or column.
4. Subtract `val` from both `rowSum[i]` and `colSum[j]`.
5. If `rowSum[i]` becomes 0, increment `i` to move to the next row. If `colSum[j]` becomes 0, increment `j` to move to the next column.
6. Repeat until all rows and columns are processed.

### Visual Trace (Example 1: rowSum=[3,8], colSum=[4,7])
| Step | i | j | val | rowSum | colSum | Matrix |
|---|---|---|---|---|---|---|
| 1 | 0 | 0 | min(3,4)=3 | [0,8] | [1,7] | [[3,0],[0,0]] |
| 2 | 1 | 0 | min(8,1)=1 | [0,7] | [0,7] | [[3,0],[1,0]] |
| 3 | 1 | 1 | min(7,7)=7 | [0,0] | [0,0] | [[3,0],[1,7]] |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the number of rows and $$M$$ is the number of columns. Each step either increments `i` or `j`, and we perform exactly $$N + M - 1$$ operations to fill the matrix.
- Space complexity: $$O(N \times M)$$ to store the resulting matrix.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> result(numRows, vector<int>(numCols, 0));

        int i = 0, j = 0;

        while (i < numRows && j < numCols) {
            int val = min(rowSum[i], colSum[j]);
            result[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }
        return result;
    }
};
```

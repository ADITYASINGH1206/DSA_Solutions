# [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`, `simulation`

---

## Problem Description
Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.

**Example 1:**

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:**

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 10`
* `-100 <= matrix[i][j] <= 100`

---

## Solution & Editorial
# Intuition
The problem requires traversing a 2D matrix in a spiral order, starting from the top-left corner and moving inward layer by layer. We can simulate this traversal by maintaining four boundary pointers (`top`, `bottom`, `left`, and `right`) and progressively shrinking them inward as each directional pass is completed.

# Approach
1. Initialize four pointers: `top = 0`, `bottom = n - 1`, `left = 0`, and `right = m - 1` corresponding to the matrix bounds, where `n` is the number of rows and `m` is the number of columns.
2. Run a `while` loop as long as `top <= bottom` and `left <= right`.
3. Traverse from left to right along the `top` row, then increment `top`.
4. Traverse from top to bottom along the `right` column, then decrement `right`.
5. If `top <= bottom` still holds, traverse from right to left along the `bottom` row, then decrement `bottom`.
6. If `left <= right` still holds, traverse from bottom to top along the `left` column, then increment `left`.
7. Repeat until all elements are collected into the result vector `ans`.

### Visual Trace Walkthrough (Example 1)
Matrix:
```
1 2 3
4 5 6
7 8 9
```
- Initial: `top = 0, bottom = 2, left = 0, right = 2`
- Pass 1 (Left to Right along top = 0): Adds `1, 2, 3`. `top` becomes 1.
- Pass 2 (Top to Bottom along right = 2): Adds `6, 9`. `right` becomes 1.
- Pass 3 (Right to Left along bottom = 2): Adds `8, 7`. `bottom` becomes 1.
- Pass 4 (Bottom to Top along left = 0): Adds `4`. `left` becomes 1.
- Next Iteration: `top = 1, bottom = 1, left = 1, right = 1`
- Pass 1 (Left to Right along top = 1): Adds `5`. `top` becomes 2.
- Loop terminates as `top <= bottom` is violated ($2 
otleqslant 1$). Final output: `[1, 2, 3, 6, 9, 8, 7, 4, 5]`.

# Complexity
- Time complexity: $$O(m \times n)$$ — Every element in the $$m \times n$$ matrix is visited exactly once.
- Space complexity: $$O(1)$$ auxiliary space (excluding the output vector), as we only use a few scalar pointer variables.

# Code
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;
        while(top <= bottom && left <= right){
            for(int i= left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};
```

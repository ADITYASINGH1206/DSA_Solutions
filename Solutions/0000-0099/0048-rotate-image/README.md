# [48. Rotate Image](https://leetcode.com/problems/rotate-image/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `matrix`

---

## Problem Description
You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).

You have to rotate the image [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm), which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

**Example 1:**

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

**Example 2:**

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

**Constraints:**

* `n == matrix.length == matrix[i].length`
* `1 <= n <= 20`
* `-1000 <= matrix[i][j] <= 1000`

---

## Solution & Editorial
# Intuition
Rotating a matrix clockwise by 90 degrees can be broken down into two simpler geometric operations: taking the transpose of the matrix (swapping elements across the main diagonal) and then reversing each individual row. This sequence achieves an in-place rotation without requiring extra memory.

# Approach
1. Store the dimension of the matrix `n = matrix.size()`.
2. Transpose the matrix by iterating through `i` from `0` to `n - 1` and `j` from `0` to `i`, swapping `matrix[i][j]` with `matrix[j][i]`. This reflects the elements along the main diagonal.
3. Reverse each row of the matrix using `reverse(matrix[i].begin(), matrix[i].end())` to complete the 90-degree clockwise rotation.

### Visual Trace Walkthrough (Example 1)
Input: `matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]`

**Initial State:**
```
1 2 3
4 5 6
7 8 9
```

**Step 1: Transpose (swap matrix[i][j] and matrix[j][i] for j < i):**
```
1 4 7
2 5 8
3 6 9
```

**Step 2: Reverse each row:**
```
7 4 1
8 5 2
9 6 3
```

# Complexity
- Time complexity: $$O(n^2)$$ — Transposing visits each lower triangular element taking $$\frac{n(n-1)}{2}$$ swaps, and reversing rows takes $$O(n^2)$$ time to process all elements.
- Space complexity: $$O(1)$$ — The transformation is performed entirely in-place using only a few variables for iteration.

# Code
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
```

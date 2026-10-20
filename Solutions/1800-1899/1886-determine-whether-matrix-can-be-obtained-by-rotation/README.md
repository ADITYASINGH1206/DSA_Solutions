# [1886. Determine Whether Matrix Can Be Obtained By Rotation](https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/)
**Difficulty:** `Easy` | **Tags:** `array`, `matrix`

---

## Problem Description
Given two `n x n` binary matrices `mat` and `target`, return `true` *if it is possible to make* `mat` *equal to* `target` *by **rotating*** `mat` *in **90-degree increments**, or* `false` *otherwise.*

**Example 1:**

```
Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
```

**Example 2:**

```
Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
```

**Example 3:**

```
Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
```

**Constraints:**

* `n == mat.length == target.length`
* `n == mat[i].length == target[i].length`
* `1 <= n <= 10`
* `mat[i][j]` and `target[i][j]` are either `0` or `1`.

---

## Solution & Editorial
# Intuition
Since a matrix can only be rotated in 90-degree increments, there are only four possible orientations (0°, 90°, 180°, and 270°). We can simulate each rotation and compare the resulting matrix with the target matrix.

# Approach
1. Iterate 4 times to cover all possible rotations (0°, 90°, 180°, 270°).
2. In each iteration, create a new matrix `g` of size `n x n`.
3. Perform a 90-degree clockwise rotation: the element at `mat[i][j]` moves to `g[j][n - i - 1]`.
4. Compare `g` with `target`. If they are identical, return `true`.
5. Update `mat` to `g` to prepare for the next rotation.
6. If no match is found after 4 rotations, return `false`.

### Visual Trace (Example 1: mat = [[0,1],[1,0]])
| Iteration | mat (Before) | Rotation Logic | mat (After) | Match? |
| :--- | :--- | :--- | :--- | :--- |
| 1 | [[0,1],[1,0]] | (0,0)->(0,1), (0,1)->(1,1), (1,0)->(0,0), (1,1)->(1,0) | [[1,0],[0,1]] | Yes (True) |

# Complexity
- Time complexity: $$O(N^2)$$ where $$N$$ is the dimension of the matrix. We perform 4 rotations, each taking $$O(N^2)$$ time to copy elements, and comparison also takes $$O(N^2)$$.
- Space complexity: $$O(N^2)$$ to store the temporary matrix `g` during each rotation.

# Code
```cpp
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int k = 0; k < 4; ++k) {
            vector<vector<int>> g(n, vector<int>(n));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    g[i][j] = mat[j][n - i - 1];
            if (g == target) return true;
            mat = g;
        }
        return false;
    }
};
```

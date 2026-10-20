# [1861. Rotating the Box](https://leetcode.com/problems/rotating-the-box/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `matrix`

---

## Problem Description
You are given an `m x n` matrix of characters `boxGrid` representing a side-view of a box. Each cell of the box is one of the following:

* A stone `'#'`
* A stationary obstacle `'*'`
* Empty `'.'`

The box is rotated **90 degrees clockwise**, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity **does not** affect the obstacles' positions, and the inertia from the box's rotation **does not** affect the stones' horizontal positions.

It is **guaranteed** that each stone in `boxGrid` rests on an obstacle, another stone, or the bottom of the box.

Return *an* `n x m` *matrix representing the box after the rotation described above*.

**Example 1:**

```
Input: boxGrid = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
```

**Example 2:**

```
Input: boxGrid = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
```

**Example 3:**

```
Input: boxGrid = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
```

**Constraints:**

* `m == boxGrid.length`
* `n == boxGrid[i].length`
* `1 <= m, n <= 500`
* `boxGrid[i][j]` is either `'#'`, `'*'`, or `'.'`.

---

## Solution & Editorial
# Intuition
To solve this problem, we must simulate two distinct physical processes: the 90-degree clockwise rotation of the grid and the gravity-induced movement of stones. Since the rotation changes the orientation of the box, we first map the original grid to its rotated state and then process each column to allow stones to fall to their final resting positions.

# Approach
1. **Rotation**: We initialize a new matrix `ans` of size `n x m`. A 90-degree clockwise rotation maps an element at `box[i][j]` to `ans[j][m - i - 1]`.
2. **Gravity Simulation**: After rotation, gravity acts downwards in each column of `ans`. For each column, we iterate from the bottom row (`n-1`) to the top (`0`).
   - We maintain a queue `q` to store the indices of empty cells (`'.'`) encountered so far.
   - If we encounter an obstacle (`'*'`), the current queue of empty cells is cleared because stones cannot pass through obstacles.
   - If we encounter an empty cell (`'.'`), we push its row index into `q`.
   - If we encounter a stone (`'#'`) and the queue is not empty, the stone falls to the lowest available empty cell (the front of the queue). We update the grid, mark the stone's previous position as `'.'`, and push the stone's old position into the queue as a new empty spot.

### Visual Trace (Example 1: `[['#', '.', '#']]`)
- **Initial**: `box = [['#', '.', '#']]` (1x3)
- **Rotate**: `ans = [['.'], ['#'], ['#']]` (3x1)
- **Gravity**: 
  - Column 0: `ans[2][0]` is '#', `ans[1][0]` is '#', `ans[0][0]` is '.'. No movement needed as they are already at the bottom.

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ and $$N$$ are the dimensions of the input grid. We iterate through the grid once for rotation and once for gravity simulation.
- Space complexity: $$O(M \times N)$$ to store the rotated matrix `ans` and the auxiliary queue for gravity simulation.

# Code
```cpp
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        for (int j = 0; j < m; ++j) {
            queue<int> q;
            for (int i = n - 1; ~i; --i) {
                if (ans[i][j] == '*') {
                    queue<int> t;
                    swap(t, q);
                } else if (ans[i][j] == '.') {
                    q.push(i);
                } else if (!q.empty()) {
                    ans[q.front()][j] = '#';
                    q.pop();
                    ans[i][j] = '.';
                    q.push(i);
                }
            }
        }
        return ans;
    }
};
```

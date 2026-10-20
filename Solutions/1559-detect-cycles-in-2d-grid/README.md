# [1559. Detect Cycles in 2D Grid](https://leetcode.com/problems/detect-cycles-in-2d-grid/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `union-find`, `matrix`

---

## Problem Description
Given a 2D array of characters `grid` of size `m x n`, you need to find if there exists any cycle consisting of the **same value** in `grid`.

A cycle is a path of **length 4 or more** in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the **same value** of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle `(1, 1) -> (1, 2) -> (1, 1)` is invalid because from `(1, 2)` we visited `(1, 1)` which was the last visited cell.

Return `true` if any cycle of the same value exists in `grid`, otherwise, return `false`.

**Example 1:**

```
Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:
```

**Example 2:**

```
Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:
```

**Example 3:**

```
Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 500`
* `grid` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks us to detect a cycle in an undirected graph where nodes are grid cells and edges exist between adjacent cells of the same character. A cycle exists if we encounter a visited node that is not the immediate parent of the current node in our traversal.

# Approach
1. We iterate through every cell in the `grid`. If a cell has not been visited, we initiate a Breadth-First Search (BFS) to explore the connected component of identical characters.
2. We maintain a `vis` matrix to track visited cells. In the BFS queue, we store the current cell coordinates `(x, y)` along with the parent cell coordinates `(px, py)` to prevent moving backward to the immediate predecessor.
3. For each cell, we check its four neighbors. If a neighbor has the same character:
   - If it is already visited and is not the parent, we have found a cycle.
   - If it is not visited, we mark it as visited and add it to the queue with the current cell as its parent.

### Visual Trace (Example 1: 2x2 'a' block)
| Step | Queue | Visited | Action |
| :--- | :--- | :--- | :--- |
| 1 | {(0,0, -1, -1)} | {(0,0)} | Start BFS at (0,0) |
| 2 | {(0,1, 0,0), (1,0, 0,0)} | {(0,0), (0,1), (1,0)} | Push neighbors |
| 3 | {(1,0, 0,0), (1,1, 0,1)} | {(0,0), (0,1), (1,0), (1,1)} | Pop (0,1), visit (1,1) |
| 4 | {(1,1, 0,1)} | ... | (1,1) sees (1,0) as visited and not parent -> **Cycle Found** |

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ and $$N$$ are the grid dimensions. Each cell is visited at most once during the BFS traversal.
- Space complexity: $$O(M \times N)$$ for the `vis` matrix and the BFS queue in the worst case.

# Code
```cpp
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        const vector<int> dirs = {-1, 0, 1, 0, -1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!vis[i][j]) {
                    queue<array<int, 4>> q;
                    q.push({i, j, -1, -1});
                    vis[i][j] = true;

                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        int x = p[0], y = p[1], px = p[2], py = p[3];

                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dirs[k], ny = y + dirs[k + 1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                if (grid[nx][ny] != grid[x][y] || (nx == px && ny == py)) {
                                    continue;
                                }
                                if (vis[nx][ny]) {
                                    return true;
                                }
                                q.push({nx, ny, x, y});
                                vis[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
```

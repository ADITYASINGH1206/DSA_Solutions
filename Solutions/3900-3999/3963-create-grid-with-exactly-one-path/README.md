# [3963. Create Grid With Exactly One Path](https://leetcode.com/problems/create-grid-with-exactly-one-path/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
You are given two integers `m` and `n`, representing the number of rows and columns of a grid.

Construct **any** `m x n` grid consisting only of the characters `'.'` and `'#'`, where:

* `'.'` represents a free cell.
* `'#'` represents an obstacle cell.

A **valid path** is a sequence of free cells that:

* Starts at the top-left cell `(0, 0)`.
* Ends at the bottom-right cell `(m - 1, n - 1)`.
* Moves only:
  + Right, from `(i, j)` to `(i, j + 1)`, or
  + Down, from `(i, j)` to `(i + 1, j)`.

Return any grid such that there is **exactly one valid path** from the top-left cell to the bottom-right cell.

**Example 1:**

**Input:** m = 2, n = 3

**Output:** ["..#","#.."]

**Explanation:**

The only valid path is: `(0,0) → (0,1) → (1,1) → (1,2)`

**Example 2:**

**Input:** m = 3, n = 3

**Output:** ["..#","#..","##."]

**Explanation:**

The only valid path is: `(0,0) → (0,1) → (1,1) → (1,2) → (2,2)`

**Example 3:**

**Input:** m = 1, n = 4

**Output:** ["...."]

**Explanation:**

The only valid path is: `(0,0) → (0,1) → (0,2) → (0,3)`

**Constraints:**

* `1 <= m, n <= 25`

---

## Solution & Editorial
# Intuition
To ensure exactly one path exists from (0, 0) to (m-1, n-1), we can construct a "snake-like" or "zig-zag" path that visits every necessary cell while blocking all other potential branches with obstacles ('#'). By alternating the direction of movement at each step, we force the path to follow a specific sequence that covers the grid without creating alternative routes.

# Approach
1. Initialize an `m x n` grid filled entirely with obstacles ('#').
2. Start at `(0, 0)` and mark it as free ('.').
3. Use a boolean flag `moveRight` to toggle the priority of movement. 
4. In each iteration, if `moveRight` is true, attempt to move right; if blocked or at the boundary, move down. If `moveRight` is false, attempt to move down; if blocked or at the boundary, move right.
5. Mark the new position `(r, c)` as '.' and flip the `moveRight` flag.
6. Repeat until the target `(m-1, n-1)` is reached.

### Visual Trace (m=2, n=3)
| Step | r | c | moveRight | Grid State |
|---|---|---|---|---|
| Start | 0 | 0 | true | `..#`, `#..` |
| 1 | 0 | 1 | false | `..#`, `#..` |
| 2 | 1 | 1 | true | `..#`, `#..` |
| 3 | 1 | 2 | false | `..#`, `#..` |

# Complexity
- Time complexity: $$O(m \times n)$$ to initialize the grid and iterate through the path.
- Space complexity: $$O(m \times n)$$ to store the resulting grid.

# Code
```cpp
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        
        int r = 0, c = 0;
        grid[r][c] = '.'; 
        bool moveRight = true;
        
        while (r < m - 1 || c < n - 1) {
            if (moveRight) {
                if (c < n - 1) {
                    c++;
                } else {
                    r++;
                }
            } else {
                if (r < m - 1) {
                    r++;
                } else {
                    c++;
                }
            }
            grid[r][c] = '.';
            moveRight = !moveRight;
        }
        
        return grid;
    }
};
```

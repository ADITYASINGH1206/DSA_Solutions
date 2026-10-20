# [885. Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`, `simulation`

---

## Problem Description
You start at the cell `(rStart, cStart)` of an `rows x cols` grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all `rows * cols` spaces of the grid.

Return *an array of coordinates representing the positions of the grid in the order you visited them*.

**Example 1:**

```
Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
```

**Example 2:**

```
Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
```

**Constraints:**

* `1 <= rows, cols <= 100`
* `0 <= rStart < rows`
* `0 <= cStart < cols`

---

## Solution & Editorial
# Intuition
The problem requires us to traverse a grid in a clockwise spiral pattern starting from an arbitrary cell `(rStart, cStart)` and collect all coordinates that fall within the grid boundaries. Since the spiral expands predictably by incrementing step lengths after completing pairs of directions, a direct simulation of the trajectory is both optimal and robust.

# Approach
1. Initialize a dynamic array `ans` to store the output coordinates, beginning with the starting position `(rStart, cStart)`.
2. Maintain the current coordinates using variables `row` and `col`. Define step length counters `r`, `d`, `l`, and `u` for the four directions (Right, Down, Left, Up) starting at `1, 1, 2, 2` respectively and increasing by `2` after each complete turn sequence.
3. Loop while the size of `ans` is less than the total number of cells (`rows * cols`). In each iteration, simulate moving:
   - **Right** for `r` steps, incrementing `r` by 2 afterwards.
   - **Down** for `d` steps, incrementing `d` by 2 afterwards.
   - **Left** for `l` steps, incrementing `l` by 2 afterwards.
   - **Up** for `u` steps, incrementing `u` by 2 afterwards.
4. During each unit movement, check if the updated coordinates `(row, col)` lie within the grid boundaries `[0, rows - 1]` and `[0, cols - 1]`. If valid, append them to `ans`.

### Visual Trace Walkthrough (Example 1: rows = 1, cols = 4, rStart = 0, cStart = 0)
- Start: `ans = [[0,0]]`, `row = 0`, `col = 0`
- Move Right `r=1`: `col` becomes 1. Valid cell `[0,1]` added. `r` becomes 3.
- Move Down `d=1`: `row` becomes 1. Out of bounds (`row < rows` fails). `d` becomes 3.
- Move Left `l=2`: `col` becomes 0, then -1. Out of bounds. `l` becomes 4.
- Move Up `u=2`: `row` becomes 0, then -1. Out of bounds. `u` becomes 4.
- Spiral expands further until all valid cells are visited.

# Complexity
- Time complexity: $$O(\max(\text{rows}, \text{cols})^2)$$ — In the worst-case, the spiral traversal bounds scale proportionally to the maximum dimension of the grid before all cells are captured.
- Space complexity: $$O(\text{rows} \times \text{cols})$$ — To store the final output vector containing all grid coordinates.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int total = rows*cols;
        ans.push_back({rStart,cStart});
        int row = rStart , col = cStart;
        int k = 0;
        int r = 1, d = 1, l =2, u = 2;
        while(ans.size()<total){
            //Right
            for(int i = 0;i<r;i++){
                col++;
                if(row<rows && col<cols && row>=0 && col>=0){
                    ans.push_back({row,col});
                }
            }
            r+=2;

            //Down
            for(int i = 0;i<d;i++){
                row++;
                if(row<rows && col<cols && row>=0 && col>=0){
                    ans.push_back({row,col});
                }
            }
            d+=2;

            //Left
            for(int i = 0;i<l;i++){
                col--;
                if(row<rows && col<cols && row>=0 && col>=0){
                    ans.push_back({row,col});
                }
            }
            l+=2;

            //Up
            for(int i = 0;i<u;i++){
                row--;
                if(row<rows && col<cols && row>=0 && col>=0){
                    ans.push_back({row,col});
                }
            }
            u+=2;
        }


        return ans;
    }
};
```

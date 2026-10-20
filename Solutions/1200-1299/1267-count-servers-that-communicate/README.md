# [1267. Count Servers that Communicate](https://leetcode.com/problems/count-servers-that-communicate/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `union-find`, `matrix`, `counting`

---

## Problem Description
You are given a map of a server center, represented as a `m * n` integer matrix `grid`, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.  
  
Return the number of servers that communicate with any other server.

**Example 1:**

```
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.
```

**Example 2:**

```
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.
```

**Example 3:**

```
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m <= 250`
* `1 <= n <= 250`
* `grid[i][j] == 0 or 1`

---

## Solution & Editorial
# Intuition
Two servers can communicate if they share the same row or the same column. Instead of checking pairs or performing graph traversals, we can precompute the total count of servers present in each row and each column using two frequency vectors. A server at position `(i, j)` can communicate with at least one other server if and only if its row has more than 1 server (`rows[i] > 1`) or its column has more than 1 server (`cols[j] > 1`).

# Approach
1. Initialize two frequency arrays `rows` and `cols` of size 251 to store the count of servers in each row and column.
2. Iterate through every cell `(i, j)` in the `grid`. If `grid[i][j] == 1`, increment `rows[i]` and `cols[j]`.
3. Iterate through every cell `(i, j)` a second time. If `grid[i][j] == 1` and either `rows[i] > 1` or `cols[j] > 1`, increment the answer counter `ans`.
4. Return `ans`.

### Visual Trace Walkthrough (Example 3)
Matrix:
`[[1, 1, 0, 0],`
` [0, 0, 1, 0],`
` [0, 0, 1, 0],`
` [0, 0, 0, 1]]`

- **Pass 1 (Counting):**
  - Row counts: `rows = [2, 1, 1, 1, ...]`
  - Column counts: `cols = [1, 1, 2, 1, ...]`
- **Pass 2 (Evaluating):**
  - `(0, 0)`: grid is 1, `rows[0] = 2 > 1` -> `ans = 1`
  - `(0, 1)`: grid is 1, `rows[0] = 2 > 1` -> `ans = 2`
  - `(1, 2)`: grid is 1, `cols[2] = 2 > 1` -> `ans = 3`
  - `(2, 2)`: grid is 1, `cols[2] = 2 > 1` -> `ans = 4`
  - `(3, 3)`: grid is 1, `rows[3] = 1` and `cols[3] = 1` -> no increment.
- **Final Answer:** `4`

# Complexity
- Time complexity: $$O(m \times n)$$ — We iterate through the matrix twice: once to populate the row and column counts, and once to evaluate each server.
- Space complexity: $$O(m + n)$$ — Auxiliary space is used for the `rows` and `cols` frequency vectors of fixed size 251.

# Code
```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        vector<int>rows(251,0),cols(251,0);
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]&&(rows[i]>1||cols[j]>1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

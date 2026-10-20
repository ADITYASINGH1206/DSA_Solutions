# [1992. Find All Groups of Farmland](https://leetcode.com/problems/find-all-groups-of-farmland/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `breadth-first-search`, `matrix`

---

## Problem Description
You are given a **0-indexed** `m x n` binary matrix `land` where a `0` represents a hectare of forested land and a `1` represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist **entirely** of farmland. These rectangular areas are called **groups**. No two groups are adjacent, meaning farmland in one group is **not** four-directionally adjacent to another farmland in a different group.

`land` can be represented by a coordinate system where the top left corner of `land` is `(0, 0)` and the bottom right corner of `land` is `(m-1, n-1)`. Find the coordinates of the top left and bottom right corner of each **group** of farmland. A **group** of farmland with a top left corner at `(r1, c1)` and a bottom right corner at `(r2, c2)` is represented by the 4-length array `[r1, c1, r2, c2].`

Return *a 2D array containing the 4-length arrays described above for each **group** of farmland in* `land`*. If there are no groups of farmland, return an empty array. You may return the answer in **any order***.

**Example 1:**

```
Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
```

**Example 2:**

```
Input: land = [[1,1],[1,1]]
Output: [[0,0,1,1]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].
```

**Example 3:**

```
Input: land = [[0]]
Output: []
Explanation:
There are no groups of farmland.
```

**Constraints:**

* `m == land.length`
* `n == land[i].length`
* `1 <= m, n <= 300`
* `land` consists of only `0`'s and `1`'s.
* Groups of farmland are **rectangular** in shape.

---

## Solution & Editorial
# Intuition
Since the farmland groups are guaranteed to be rectangular and non-adjacent, we can identify each group by finding its top-left corner (the first '1' encountered in row-major order) and then traversing the rectangle to find its bottom-right corner. A Depth-First Search (DFS) is an effective way to explore the connected component of '1's starting from the top-left corner.

# Approach
1. Iterate through the matrix using nested loops. When we encounter a '1' that hasn't been visited, it marks the top-left corner `(i, j)` of a new farmland group.
2. Initiate a DFS from `(i, j)`. During the DFS, maintain a reference to an `end` vector to track the maximum row and column indices reached. Since the group is rectangular, the bottom-right corner will naturally be the maximum row and column index encountered during the traversal.
3. Mark visited cells in a `vis` matrix to ensure each group is processed exactly once.
4. After the DFS completes, the `end` vector contains the coordinates of the bottom-right corner. Store `[i, j, end[0], end[1]]` in the result list.

### Visual Trace (Example 1)
`land = [[1,0,0],[0,1,1],[0,1,1]]`
- Start at `(0,0)`: DFS finds `(0,0)` as bottom-right. Result: `[[0,0,0,0]]`.
- Continue to `(1,1)`: DFS explores `(1,1) -> (1,2) -> (2,1) -> (2,2)`. Max row is 2, max col is 2. Result: `[[0,0,0,0], [1,1,2,2]]`.

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ is the number of rows and $$N$$ is the number of columns. Each cell is visited exactly once by the nested loops and the DFS traversal.
- Space complexity: $$O(M \times N)$$ for the `vis` matrix and the recursion stack in the worst case (e.g., a single large rectangle).

# Code
```cpp
class Solution {
public:
    int drow[2] = {0,1};
    int dcol[2] = {1,0};
    void dfs(vector<vector<int>>& land,vector<vector<int>>& vis,vector<int>& ans,int row,int col,int&m ,int&n){
        vis[row][col] = 1;
        ans[0] = max(ans[0],row);
        ans[1] = max(ans[1],col);
        for(int i=0;i<2;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow >=0 && ncol >=0 && nrow<m && ncol <n && !vis[nrow][ncol] && land[nrow][ncol] == 1){
                dfs(land,vis,ans,nrow,ncol,m,n);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(land[i][j] == 1 && !vis[i][j]){
                    vector<int> end(2,0);
                    vector<int> temp(4,0);
                    dfs(land,vis,end,i,j,m,n);
                    temp[0]= i , temp[1] = j;
                    temp[2] = end[0] , temp[3] = end[1];
                    ans.push_back(temp);
                }
            }
        }
        return ans;

    }
};
```

# [3898. Find the Degree of Each Vertex](https://leetcode.com/problems/find-the-degree-of-each-vertex/)
**Difficulty:** `Easy` | **Tags:** `array`, `graph`, `matrix`

---

## Problem Description
You are given a 2D integer array `matrix` of size `n x n` representing the adjacency matrix of an undirected graph with `n` vertices labeled from 0 to `n - 1`.

* `matrix[i][j] = 1` indicates that there is an edge between vertices `i` and `j`.
* `matrix[i][j] = 0` indicates that there is no edge between vertices `i` and `j`.

The **degree** of a vertex is the number of edges connected to it.

Return an integer array `ans` of size `n` where `ans[i]` represents the degree of vertex `i`.

**Example 1:**

**Input:** matrix = [[0,1,1],[1,0,1],[1,1,0]]

**Output:** [2,2,2]

**Explanation:**

* Vertex 0 is connected to vertices 1 and 2, so its degree is 2.
* Vertex 1 is connected to vertices 0 and 2, so its degree is 2.
* Vertex 2 is connected to vertices 0 and 1, so its degree is 2.

Thus, the answer is `[2, 2, 2]`.

**Example 2:**

**Input:** matrix = [[0,1,0],[1,0,0],[0,0,0]]

**Output:** [1,1,0]

**Explanation:**

* Vertex 0 is connected to vertex 1, so its degree is 1.
* Vertex 1 is connected to vertex 0, so its degree is 1.
* Vertex 2 is not connected to any vertex, so its degree is 0.

Thus, the answer is `[1, 1, 0]`.

**Example 3:**

**Input:** matrix = [[0]]

**Output:** [0]

**Explanation:**

There is only one vertex and it has no edges connected to it. Thus, the answer is `[0]`.

**Constraints:**

* `1 <= n == matrix.length == matrix[i].length <= 100`​​​​​​​
* `​​​​​​​matrix[i][i] == 0`
* `matrix[i][j]` is either 0 or 1
* `matrix[i][j] == matrix[j][i]`

---

## Solution & Editorial
# Intuition
In an adjacency matrix representation of an undirected graph, the degree of a vertex $i$ is defined as the number of edges connected to it. Since the matrix entry `matrix[i][j] = 1` signifies an edge between vertex $i$ and $j$, the degree of vertex $i$ is simply the sum of all values in the $i$-th row.

# Approach
1. Initialize an empty vector `ans` to store the degrees of each vertex.
2. Iterate through each row $i$ of the `matrix` from $0$ to $n-1$.
3. For each row, maintain a counter `cur_deg` initialized to $0$.
4. Iterate through each column $j$ in the current row $i$ and add `matrix[i][j]` to `cur_deg`.
5. Append `cur_deg` to `ans` after processing each row.

### Visual Trace (Example 1: matrix = [[0,1,1],[1,0,1],[1,1,0]])
| Row (i) | Column (j) | matrix[i][j] | cur_deg (Running Sum) |
| :--- | :--- | :--- | :--- |
| 0 | 0, 1, 2 | 0, 1, 1 | 2 |
| 1 | 0, 1, 2 | 1, 0, 1 | 2 |
| 2 | 0, 1, 2 | 1, 1, 0 | 2 |

Result: `[2, 2, 2]`

# Complexity
- Time complexity: $$O(n^2)$$, where $n$ is the number of vertices. We iterate through every cell in the $n \times n$ matrix exactly once.
- Space complexity: $$O(n)$$, as we store the degree of each of the $n$ vertices in the `ans` vector.

# Code
```cpp
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            int cur_deg = 0;
            for (int j = 0; j < n; j++) {
                cur_deg += matrix[i][j];
            }
            ans.push_back(cur_deg);
        }
        
        return ans;
    }
};
```

# [2924. Find Champion II](https://leetcode.com/problems/find-champion-ii/)
**Difficulty:** `Medium` | **Tags:** `graph`

---

## Problem Description
There are `n` teams numbered from `0` to `n - 1` in a tournament; each team is also a node in a **DAG**.

You are given the integer `n` and a **0-indexed** 2D integer array `edges` of length `m` representing the **DAG**, where `edges[i] = [ui, vi]` indicates that there is a directed edge from team `ui` to team `vi` in the graph.

A directed edge from `a` to `b` in the graph means that team `a` is **stronger** than team `b` and team `b` is **weaker** than team `a`.

Team `a` will be the **champion** of the tournament if there is no team `b` that is **stronger** than team `a`.

Return *the team that will be the **champion** of the tournament if there is a **unique** champion, otherwise, return* `-1`*.*

**Notes**

* A **cycle** is a series of nodes `a1, a2, ..., an, an+1` such that node `a1` is the same node as node `an+1`, the nodes `a1, a2, ..., an` are distinct, and there is a directed edge from the node `ai` to node `ai+1` for every `i` in the range `[1, n]`.
* A **DAG** is a directed graph that does not have any **cycle**.

**Example 1:**

```
Input: n = 3, edges = [[0,1],[1,2]]
Output: 0
Explanation: Team 1 is weaker than team 0. Team 2 is weaker than team 1. So the champion is team 0.
```

**Example 2:**

```
Input: n = 4, edges = [[0,2],[1,3],[1,2]]
Output: -1
Explanation: Team 2 is weaker than team 0 and team 1. Team 3 is weaker than team 1. But team 1 and team 0 are not weaker than any other teams. So the answer is -1.
```

**Constraints:**

* `1 <= n <= 100`
* `m == edges.length`
* `0 <= m <= n * (n - 1) / 2`
* `edges[i].length == 2`
* `0 <= edge[i][j] <= n - 1`
* `edges[i][0] != edges[i][1]`
* The input is generated such that if team `a` is stronger than team `b`, team `b` is not stronger than team `a`.
* The input is generated such that if team `a` is stronger than team `b` and team `b` is stronger than team `c`, then team `a` is stronger than team `c`.

---

## Solution & Editorial
# Intuition
In a Directed Acyclic Graph (DAG), a node is a potential champion if and only if it has an in-degree of 0. If there is more than one node with an in-degree of 0, there is no unique champion. If there is exactly one, that node is the champion.

# Approach
1. Initialize a vector `winners` of size 100 (covering the constraint $n \le 100$) with zeros. This vector tracks whether a node has an incoming edge.
2. Iterate through the `edges` array. For each edge `[u, v]`, mark `winners[v]` as -1, indicating that node `v` has an incoming edge and therefore cannot be a champion.
3. Iterate through all nodes from `0` to `n-1`. If `winners[i]` remains 0, it means node `i` has no incoming edges.
4. Maintain an `ans` variable to store the index of the found champion. If we find more than one node with an in-degree of 0, return -1 immediately.

### Visual Trace (Example 2: n=4, edges=[[0,2],[1,3],[1,2]])
| Iteration | Edge | `winners` state (indices 0-3) |
| :--- | :--- | :--- |
| Initial | - | [0, 0, 0, 0] |
| 1 | [0, 2] | [0, 0, -1, 0] |
| 2 | [1, 3] | [0, 0, -1, -1] |
| 3 | [1, 2] | [0, 0, -1, -1] |

Final check: `winners[0]` is 0, `winners[1]` is 0. Since two nodes have 0, return -1.

# Complexity
- Time complexity: $$O(N + M)$$, where $N$ is the number of teams and $M$ is the number of edges. We iterate over all edges once and then over all nodes once.
- Space complexity: $$O(N)$$, as we use a fixed-size vector of size 100 to track the in-degree status of each node.

# Code
```cpp
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> winners(100,0);
        for(int i = 0;i<edges.size();i++){
            winners[edges[i][1]] = -1;
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(winners[i] == 0){
                if(ans != -1) return -1;
                else ans = i;
            }
        }
        return ans;
    }
};
```

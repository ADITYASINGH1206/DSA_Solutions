# [3600. Maximize Spanning Tree Stability with Upgrades](https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/)
**Difficulty:** `Hard` | **Tags:** `binary-search`, `greedy`, `union-find`, `graph`, `minimum-spanning-tree`

---

## Problem Description
You are given an integer `n`, representing `n` nodes numbered from 0 to `n - 1` and a list of `edges`, where `edges[i] = [ui, vi, si, musti]`:

* `ui` and `vi` indicates an undirected edge between nodes `ui` and `vi`.
* `si` is the strength of the edge.
* `musti` is an integer (0 or 1). If `musti == 1`, the edge **must** be included in the**spanning tree**. These edges **cannot** be **upgraded**.

You are also given an integer `k`, the **maximum** number of upgrades you can perform. Each upgrade **doubles** the strength of an edge, and each eligible edge (with `musti == 0`) can be upgraded **at most** once.

The **stability** of a spanning tree is defined as the **minimum** strength score among all edges included in it.

Return the **maximum** possible stability of any valid spanning tree. If it is impossible to connect all nodes, return `-1`.

**Note**: A **spanning tree** of a graph with `n` nodes is a subset of the edges that connects all nodes together (i.e. the graph is **connected**) *without* forming any cycles, and uses **exactly** `n - 1` edges.

**Example 1:**

**Input:** n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1

**Output:** 2

**Explanation:**

* Edge `[0,1]` with strength = 2 must be included in the spanning tree.
* Edge `[1,2]` is optional and can be upgraded from 3 to 6 using one upgrade.
* The resulting spanning tree includes these two edges with strengths 2 and 6.
* The minimum strength in the spanning tree is 2, which is the maximum possible stability.

**Example 2:**

**Input:** n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2

**Output:** 6

**Explanation:**

* Since all edges are optional and up to `k = 2` upgrades are allowed.
* Upgrade edges `[0,1]` from 4 to 8 and `[1,2]` from 3 to 6.
* The resulting spanning tree includes these two edges with strengths 8 and 6.
* The minimum strength in the tree is 6, which is the maximum possible stability.

**Example 3:**

**Input:** n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0

**Output:** -1

**Explanation:**

* All edges are mandatory and form a cycle, which violates the spanning tree property of acyclicity. Thus, the answer is -1.

**Constraints:**

* `2 <= n <= 105`
* `1 <= edges.length <= 105`
* `edges[i] = [ui, vi, si, musti]`
* `0 <= ui, vi < n`
* `ui != vi`
* `1 <= si <= 105`
* `musti` is either `0` or `1`.
* `0 <= k <= n`
* There are no duplicate edges.

---

## Solution & Editorial
# Intuition
To maximize the minimum edge weight (stability) in a spanning tree, we observe that the property is monotonic: if a stability of $X$ is achievable, any value less than $X$ is also achievable. This suggests we can binary search on the answer. The core challenge is verifying if a target stability $L$ is possible given $k$ upgrades.

# Approach
1. **Mandatory Edges**: First, process all edges where `must == 1`. If these edges form a cycle, return -1 immediately. If they don't connect the graph, we must ensure the remaining optional edges can complete the spanning tree.
2. **Binary Search**: The search space for the stability is $[1, 2 \times 10^5]$. For a fixed `lim`:
   - Use a Union-Find structure to greedily include all edges that already satisfy `s >= lim`.
   - Then, attempt to use up to $k$ upgrades on remaining edges that satisfy `s * 2 >= lim` to connect the remaining components.
3. **Validation**: The `check(lim)` function returns true if the graph becomes connected using only edges with effective strength $\ge lim$.

### Visual Trace (Example 1: n=3, edges=[[0,1,2,1],[1,2,3,0]], k=1)
| Step | Action | State (Components) | Edges Used |
| :--- | :--- | :--- | :--- |
| 1 | Mandatory | {0,1}, {2} | (0,1) |
| 2 | Check(2) | {0,1,2} | (0,1), (1,2) |
| 3 | Result | Connected | Stability 2 |

# Complexity
- Time complexity: $$O(E \log E \cdot \alpha(N))$$ where $$E$$ is the number of edges and $$\alpha$$ is the inverse Ackermann function. The binary search runs in $O(\log(\max S))$ iterations, and each check performs Union-Find operations.
- Space complexity: $$O(N + E)$$ to store the graph edges and the Union-Find parent/size arrays.

# Code
```cpp
class UnionFind {
public:
    vector<int> p, size;
    int cnt;

    UnionFind(int n) {
        p.resize(n);
        size.assign(n, 1);
        cnt = n;
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) return false;
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        cnt--;
        return true;
    }
};

class Solution {
public:
    int n, k;
    vector<vector<int>> edges;

    bool check(int lim) {
        UnionFind uf(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2];
            if (s >= lim) {
                uf.unite(u, v);
            }
        }

        int rem = k;
        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2];
            if (s * 2 >= lim && rem > 0) {
                if (uf.unite(u, v)) {
                    rem--;
                }
            }
        }

        return uf.cnt == 1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        this->n = n;
        this->edges = edges;
        this->k = k;

        UnionFind uf(n);
        int mn = 1e6;

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must) {
                mn = min(mn, s);
                if (!uf.unite(u, v)) {
                    return -1;
                }
            }
        }

        for (auto& e : edges) {
            uf.unite(e[0], e[1]);
        }

        if (uf.cnt > 1) {
            return -1;
        }

        int l = 1, r = mn;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};
```

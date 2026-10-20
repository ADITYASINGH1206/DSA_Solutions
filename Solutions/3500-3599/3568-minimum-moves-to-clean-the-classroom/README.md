# [3568. Minimum Moves to Clean the Classroom](https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `bit-manipulation`, `breadth-first-search`, `matrix`

---

## Problem Description
You are given an `m x n` grid `classroom` where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:

* `'S'`: Starting position of the student
* `'L'`: Litter that must be collected (once collected, the cell becomes empty)
* `'R'`: Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
* `'X'`: Obstacle the student cannot pass through
* `'.'`: Empty space

You are also given an integer `energy`, representing the student's maximum energy capacity. The student starts with this energy from the starting position `'S'`.

Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area `'R'`, which resets the energy to its **maximum** capacity `energy`.

Return the **minimum** number of moves required to collect all litter items, or `-1` if it's impossible.

**Example 1:**

**Input:** classroom = ["S.", "XL"], energy = 2

**Output:** 2

**Explanation:**

* The student starts at cell `(0, 0)` with 2 units of energy.
* Since cell `(1, 0)` contains an obstacle 'X', the student cannot move directly downward.
* A valid sequence of moves to collect all litter is as follows:
  + Move 1: From `(0, 0)` → `(0, 1)` with 1 unit of energy and 1 unit remaining.
  + Move 2: From `(0, 1)` → `(1, 1)` to collect the litter `'L'`.
* The student collects all the litter using 2 moves. Thus, the output is 2.

**Example 2:**

**Input:** classroom = ["LS", "RL"], energy = 4

**Output:** 3

**Explanation:**

* The student starts at cell `(0, 1)` with 4 units of energy.
* A valid sequence of moves to collect all litter is as follows:
  + Move 1: From `(0, 1)` → `(0, 0)` to collect the first litter `'L'` with 1 unit of energy used and 3 units remaining.
  + Move 2: From `(0, 0)` → `(1, 0)` to `'R'` to reset and restore energy back to 4.
  + Move 3: From `(1, 0)` → `(1, 1)` to collect the second litter `'L'`.
* The student collects all the litter using 3 moves. Thus, the output is 3.

**Example 3:**

**Input:** classroom = ["L.S", "RXL"], energy = 3

**Output:** -1

**Explanation:**

No valid path collects all `'L'`.

**Constraints:**

* `1 <= m == classroom.length <= 20`
* `1 <= n == classroom[i].length <= 20`
* `classroom[i][j]` is one of `'S'`, `'L'`, `'R'`, `'X'`, or `'.'`
* `1 <= energy <= 50`
* There is exactly **one** `'S'` in the grid.
* There are **at most** 10 `'L'` cells in the grid.

---

## Solution & Editorial
# Intuition
The problem requires finding the shortest path to visit all 'L' (litter) cells in a grid, given a limited energy capacity that can be replenished at 'R' (reset) cells. Since the number of litter items is small (at most 10), we can model this as a shortest-path problem on a state-space graph where the state is defined by the student's current position, current energy, and the bitmask of collected litter.

# Approach
1. **State Representation**: We define a state as `(row, col, current_energy, mask)`, where `mask` is a bitmask of length `K` (number of litter items) representing which items have been collected.
2. **BFS Traversal**: We use Breadth-First Search (BFS) to explore the state space. BFS is ideal here because each move has a uniform cost of 1, ensuring the first time we reach a state with `mask == (1 << K) - 1`, we have found the minimum moves.
3. **Transitions**:
   - From `(r, c, e, mask)`, move to adjacent `(nr, nc)` if it is not an obstacle 'X' and `e > 0`.
   - If `classroom[nr][nc] == 'L'`, update the mask: `nmask = mask | (1 << id[nr][nc])`.
   - If `classroom[nr][nc] == 'R'`, reset energy: `ne = energy`.
   - Otherwise, `ne = e - 1`.

### Visual Trace (Example 1)
`classroom = ["S.", "XL"], energy = 2`
- Start: `(0, 0, 2, 0)` moves: 0
- Queue: `[(0, 0, 2, 0)]`
- Pop `(0, 0, 2, 0)` -> Push `(0, 1, 1, 0)` (move 1)
- Pop `(0, 1, 1, 0)` -> Push `(1, 1, 0, 1)` (move 2, litter collected)
- `mask` is now `1` (full), return 2.

# Complexity
- Time complexity: $$O(M \cdot N \cdot E \cdot 2^K)$$, where $$M, N \le 20$$, $$E \le 50$$, and $$K \le 10$$. The state space is bounded by the grid dimensions, energy capacity, and the power set of litter items.
- Space complexity: $$O(M \cdot N \cdot E \cdot 2^K)$$ to store the `dist` array for visited states and the BFS queue.

# Code
```cpp
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size(), m = classroom[0].size();
        int sr = -1, sc = -1;
        vector<pair<int,int>> trash;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') { sr = i; sc = j; }
                else if (classroom[i][j] == 'L') trash.push_back({i, j});
            }

        int k = trash.size();
        if (k == 0) return 0;

        vector<vector<int>> id(n, vector<int>(m, -1));
        for (int i = 0; i < k; i++)
            id[trash[i].first][trash[i].second] = i;

        int fullMask = (1 << k) - 1;

        vector<vector<vector<vector<int>>>> dist(
            n, vector<vector<vector<int>>>(
                m, vector<vector<int>>(
                    energy + 1, vector<int>(1 << k, -1))));

        queue<array<int,4>> q;
        dist[sr][sc][energy][0] = 0;
        q.push({sr, sc, energy, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, e, mask] = q.front(); q.pop();
            int moves = dist[r][c][e][mask];

            if (mask == fullMask) return moves;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (classroom[nr][nc] == 'X') continue;
                if (e == 0) continue;

                int ne = e - 1, nmask = mask;
                if (classroom[nr][nc] == 'L') nmask |= (1 << id[nr][nc]);
                if (classroom[nr][nc] == 'R') ne = energy;

                if (dist[nr][nc][ne][nmask] == -1) {
                    dist[nr][nc][ne][nmask] = moves + 1;
                    q.push({nr, nc, ne, nmask});
                }
            }
        }
        return -1;
    }
};
```

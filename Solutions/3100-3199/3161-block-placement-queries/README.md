# [3161. Block Placement Queries](https://leetcode.com/problems/block-placement-queries/)
**Difficulty:** `Hard` | **Tags:** `array`, `binary-search`, `binary-indexed-tree`, `segment-tree`, `ordered-set`

---

## Problem Description
There exists an infinite number line, with its origin at 0 and extending towards the **positive** x-axis.

You are given a 2D array `queries`, which contains two types of queries:

1. For a query of type 1, `queries[i] = [1, x]`. Build an obstacle at distance `x` from the origin. It is guaranteed that there is **no** obstacle at distance `x` when the query is asked.
2. For a query of type 2, `queries[i] = [2, x, sz]`. Check if it is possible to place a block of size `sz` *anywhere* in the range `[0, x]` on the line, such that the block **entirely** lies in the range `[0, x]`. A block **cannot** be placed if it intersects with any obstacle, but it may touch it. Note that you do **not** actually place the block. Queries are separate.

Return a boolean array `results`, where `results[i]` is `true` if you can place the block specified in the `ith` query of type 2, and `false` otherwise.

**Example 1:**

**Input:** queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

**Output:** [false,true,true]

**Explanation:**

For query 0, place an obstacle at `x = 2`. A block of size at most 2 can be placed before `x = 3`.

**Example 2:**

**Input:** queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

**Output:** [true,true,false]

**Explanation:**

* Place an obstacle at `x = 7` for query 0. A block of size at most 7 can be placed before `x = 7`.
* Place an obstacle at `x = 2` for query 2. Now, a block of size at most 5 can be placed before `x = 7`, and a block of size at most 2 before `x = 2`.

**Constraints:**

* `1 <= queries.length <= 15 * 104`
* `2 <= queries[i].length <= 3`
* `1 <= queries[i][0] <= 2`
* `1 <= x, sz <= min(5 * 104, 3 * queries.length)`
* The input is generated such that for queries of type 1, no obstacle exists at distance `x` when the query is asked.
* The input is generated such that there is at least one query of type 2.

---

## Solution & Editorial
# Intuition
The problem asks us to maintain obstacles on a number line and query the maximum gap available before a coordinate `x`. Since obstacles are added dynamically, a naive approach would be too slow. By processing queries in reverse, we transform "adding an obstacle" into "removing an obstacle" (merging two adjacent gaps), which allows us to maintain the maximum gap size efficiently using a Segment Tree.

# Approach
1. **Offline Processing**: Collect all obstacle positions that will ever exist. Initialize a `std::set` with these positions to track the current state of the line.
2. **Segment Tree Initialization**: Build a Segment Tree where each leaf at index `pos` stores the gap size between `pos` and the previous obstacle. The tree supports point updates and range maximum queries.
3. **Reverse Traversal**: 
   - For type 2 queries (`[2, x, sz]`): Find the largest obstacle `prevObstacle` less than or equal to `x` using `upper_bound`. The maximum gap in `[0, x]` is `max(query(0, prevObstacle), x - prevObstacle)`. If this is `>= sz`, the answer is `true`.
   - For type 1 queries (`[1, x]`): Remove the obstacle at `x`. This merges the gap ending at `x` with the gap starting at `x`, effectively updating the Segment Tree to reflect the new, larger gap.

### Visual Trace (Example 1: `[[1,2],[2,3,3],[2,3,1],[2,2,2]]`)
| Step | Query | Action | State (Obstacles) | Max Gap in [0, x]
|---|---|---|---|---|
| 1 | [2, 2, 2] | Query | {0, 2} | max(gap(0,2), 2-2) = 2 >= 2 (True)
| 2 | [2, 3, 1] | Query | {0, 2} | max(gap(0,2), 3-2) = 2 >= 1 (True)
| 3 | [2, 3, 3] | Query | {0, 2} | max(gap(0,2), 3-2) = 2 >= 3 (False)
| 4 | [1, 2] | Remove | {0} | N/A

# Complexity
- Time complexity: $$O(Q \log N)$$, where $$Q$$ is the number of queries and $$N$$ is the maximum coordinate value. Each update and query in the Segment Tree takes $$O(\log N)$$, and set operations take $$O(\log Q)$$.
- Space complexity: $$O(N + Q)$$ to store the Segment Tree nodes and the set of obstacle positions.

# Code
```cpp
class Solution {
public:
    vector<int> seg;
    const int MAXX = 50000;
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        seg.resize(4 * (MAXX + 1), 0);

        set<int> obstacles;
        obstacles.insert(0);

        for (auto &q : queries) {
            if (q[0] == 1) obstacles.insert(q[1]);
        }

        vector<int> pos(obstacles.begin(), obstacles.end());
        for (int i = 1; i < (int)pos.size(); i++) {
            update(1,0,MAXX,pos[i],pos[i] - pos[i - 1]);
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            if (queries[i][0] == 2) {
                int x = queries[i][1];
                int sz = queries[i][2];
                auto it = prev(obstacles.upper_bound(x));

                int prevObstacle = *it;
                int best = query(1,0,MAXX,0,prevObstacle);
                best = max(best, x - prevObstacle);
                ans.push_back(best >= sz);
            }
            else {

                int x = queries[i][1]; 
                auto it = obstacles.find(x);
                int leftPos = *prev(it); 
                update(1,0,MAXX,x,0); 
                auto rightIt = next(it);

                if (rightIt != obstacles.end()) {
                    int rightPos = *rightIt;
                    update(1,0,MAXX,rightPos,rightPos - leftPos);
                }

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

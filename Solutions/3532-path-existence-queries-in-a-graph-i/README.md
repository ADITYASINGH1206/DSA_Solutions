# [3532. Path Existence Queries in a Graph I](https://leetcode.com/problems/path-existence-queries-in-a-graph-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `binary-search`, `union-find`, `graph`

---

## Problem Description
You are given an integer `n` representing the number of nodes in a graph, labeled from 0 to `n - 1`.

You are also given an integer array `nums` of length `n` sorted in **non-decreasing** order, and an integer `maxDiff`.

An **undirected** edge exists between nodes `i` and `j` if the **absolute** difference between `nums[i]` and `nums[j]` is **at most** `maxDiff` (i.e., `|nums[i] - nums[j]| <= maxDiff`).

You are also given a 2D integer array `queries`. For each `queries[i] = [ui, vi]`, determine whether there exists a path between nodes `ui` and `vi`.

Return a boolean array `answer`, where `answer[i]` is `true` if there exists a path between `ui` and `vi` in the `ith` query and `false` otherwise.

**Example 1:**

**Input:** n = 2, nums = [1,3], maxDiff = 1, queries = [[0,0],[0,1]]

**Output:** [true,false]

**Explanation:**

* Query `[0,0]`: Node 0 has a trivial path to itself.
* Query `[0,1]`: There is no edge between Node 0 and Node 1 because `|nums[0] - nums[1]| = |1 - 3| = 2`, which is greater than `maxDiff`.
* Thus, the final answer after processing all the queries is `[true, false]`.

**Example 2:**

**Input:** n = 4, nums = [2,5,6,8], maxDiff = 2, queries = [[0,1],[0,2],[1,3],[2,3]]

**Output:** [false,false,true,true]

**Explanation:**

The resulting graph is:

* Query `[0,1]`: There is no edge between Node 0 and Node 1 because `|nums[0] - nums[1]| = |2 - 5| = 3`, which is greater than `maxDiff`.
* Query `[0,2]`: There is no edge between Node 0 and Node 2 because `|nums[0] - nums[2]| = |2 - 6| = 4`, which is greater than `maxDiff`.
* Query `[1,3]`: There is a path between Node 1 and Node 3 through Node 2 since `|nums[1] - nums[2]| = |5 - 6| = 1` and `|nums[2] - nums[3]| = |6 - 8| = 2`, both of which are within `maxDiff`.
* Query `[2,3]`: There is an edge between Node 2 and Node 3 because `|nums[2] - nums[3]| = |6 - 8| = 2`, which is equal to `maxDiff`.
* Thus, the final answer after processing all the queries is `[false, false, true, true]`.

**Constraints:**

* `1 <= n == nums.length <= 105`
* `0 <= nums[i] <= 105`
* `nums` is sorted in **non-decreasing** order.
* `0 <= maxDiff <= 105`
* `1 <= queries.length <= 105`
* `queries[i] == [ui, vi]`
* `0 <= ui, vi < n`

---

## Solution & Editorial
# Intuition
Since the array `nums` is sorted, an edge exists between adjacent indices `i` and `i+1` if `nums[i+1] - nums[i] <= maxDiff`. If this condition holds, nodes `i` and `i+1` belong to the same connected component. If the difference exceeds `maxDiff`, a "break" occurs, and all nodes from `i+1` onwards belong to a new component. We can identify connected components by tracking these breaks using a prefix sum array.

# Approach
1. Initialize a `cmp` array of size `n` to store the component ID for each node.
2. Iterate through the `nums` array from index `1` to `n-1`. If `nums[i] - nums[i-1] > maxDiff`, increment the component ID counter. Otherwise, the current node `i` belongs to the same component as `i-1`.
3. For each query `[ui, vi]`, check if `cmp[ui] == cmp[vi]`. If they are equal, the nodes belong to the same connected component, meaning a path exists.

### Visual Trace (Example 2: nums = [2,5,6,8], maxDiff = 2)
| Index | nums[i] | Diff (i, i-1) | Break? | cmp[i] |
|-------|---------|---------------|--------|--------|
| 0     | 2       | -             | -      | 0      |
| 1     | 5       | 3 (>2)        | Yes    | 1      |
| 2     | 6       | 1 (<=2)       | No     | 1      |
| 3     | 8       | 2 (<=2)       | No     | 1      |

- Query [0,1]: cmp[0]=0, cmp[1]=1. Result: false.
- Query [1,3]: cmp[1]=1, cmp[3]=1. Result: true.

# Complexity
- Time complexity: $$O(N + Q)$$, where $$N$$ is the number of nodes and $$Q$$ is the number of queries. We perform a single linear pass over `nums` to build the component map and a constant time lookup for each query.
- Space complexity: $$O(N)$$ to store the component IDs for each node.

# Code
```cpp
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> cmp(n);

        for (int i = 1; i < n; i++) {
            cmp[i] = cmp[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }

        vector<bool> res;

        for (const auto &q : queries) {
            res.push_back(cmp[q[0]] == cmp[q[1]]);
        }

        return res;
    }
};
```

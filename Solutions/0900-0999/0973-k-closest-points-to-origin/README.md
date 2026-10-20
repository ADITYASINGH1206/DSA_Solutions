# [973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `divide-and-conquer`, `geometry`, `sorting`, `heap-priority-queue`, `quickselect`, `k-d-tree`

---

## Problem Description
Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the **X-Y** plane is the Euclidean distance (i.e., `√(x1 - x2)2 + (y1 - y2)2`).

You may return the answer in **any order**. The answer is **guaranteed** to be **unique** (except for the order that it is in).

**Example 1:**

```
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
```

**Example 2:**

```
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
```

**Constraints:**

* `1 <= k <= points.length <= 104`
* `-104 <= xi, yi <= 104`

---

## Solution & Editorial
# Intuition
To find the $k$ closest points to the origin, we can track the smallest distances encountered so far. Since we need the $k$ smallest elements out of $N$ items, maintaining a max-heap of size $k$ allows us to efficiently discard the largest distances once our collection exceeds size $k$.

# Approach
1. Initialize a max-priority queue `pq` that stores pairs of `(squared_distance, point_index)`. Using a max-heap ensures that the largest distance among the currently tracked $k + 1$ elements sits at the top and is removed immediately.
2. Iterate through each point in the `points` array, compute its squared Euclidean distance $d = x^2 + y^2$ (avoiding square roots for precision and speed), and push `{d, i}` into the priority queue.
3. If the size of `pq` exceeds $k$, pop the top element (which has the largest distance among the current set), ensuring the heap size never exceeds $k$.
4. After processing all points, extract the remaining indices from the priority queue and collect the corresponding points into the `ans` vector.

### Visual Walkthrough (Example 1)
`points = [[1, 3], [-2, 2]], k = 1`
- **i = 0**, point = `[1, 3]`: $d = 1^2 + 3^2 = 10$. Push `{10, 0}` to `pq`. Size is 1 ($\le k$). `pq` = `{(10, 0)}`.
- **i = 1**, point = `[-2, 2]`: $d = (-2)^2 + 2^2 = 8$. Push `{8, 1}` to `pq`. Size is 2 ($> k$). Pop top element `(10, 0)`. `pq` = `{(8, 1)}`.
- **Result extraction**: Extract index `1`, returning `points[1] = [-2, 2]`.

# Complexity
- Time complexity: $$O(N \log k)$$ — We iterate through all $N$ points, and for each point, we perform a heap insertion and potentially a deletion on a heap of maximum size $k$. Each heap operation takes $$O(\log k)$$ time.
- Space complexity: $$O(k)$$ — The priority queue stores at most $k + 1$ elements at any given time.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < points.size(); ++i) {
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({d, i});
            if ((int)pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
```

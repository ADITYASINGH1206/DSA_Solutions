# [1840. Maximum Building Height](https://leetcode.com/problems/maximum-building-height/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `sorting`

---

## Problem Description
You want to build `n` new buildings in a city. The new buildings will be built in a line and are labeled from `1` to `n`.

However, there are city restrictions on the heights of the new buildings:

* The height of each building must be a non-negative integer.
* The height of the first building **must** be `0`.
* The height difference between any two adjacent buildings **cannot exceed** `1`.

Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array `restrictions` where `restrictions[i] = [idi, maxHeighti]` indicates that building `idi` must have a height **less than or equal to** `maxHeighti`.

It is guaranteed that each building will appear **at most once** in `restrictions`, and building `1` will **not** be in `restrictions`.

Return *the **maximum possible height** of the **tallest** building*.

**Example 1:**

```
Input: n = 5, restrictions = [[2,1],[4,1]]
Output: 2
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
```

**Example 2:**

```
Input: n = 6, restrictions = []
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
```

**Example 3:**

```
Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
Output: 5
Explanation: The green area in the image indicates the maximum allowed height for each building.
We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
```

**Constraints:**

* `2 <= n <= 109`
* `0 <= restrictions.length <= min(n - 1, 105)`
* `2 <= idi <= n`
* `idi` is **unique**.
* `0 <= maxHeighti <= 109`

---

## Solution & Editorial
# Intuition
The problem requires maintaining a height constraint where the difference between adjacent buildings is at most 1. This implies that for any two restricted buildings at indices $x_1$ and $x_2$ with maximum heights $h_1$ and $h_2$, the height at any building $x$ between them is constrained by $h(x) \le \min(h_1 + |x - x_1|, h_2 + |x - x_2|)$. By processing these constraints in two passes (left-to-right and right-to-left), we can propagate the tightest possible height bounds across all restricted points.

# Approach
1. **Initialization**: Add the implicit constraint `[1, 0]` to the `restrictions` list and sort by building index.
2. **Left-to-Right Pass**: Iterate forward to ensure each building's height satisfies $h_i \le h_{i-1} + (x_i - x_{i-1})$. This enforces the upward slope constraint.
3. **Right-to-Left Pass**: Iterate backward to ensure $h_i \le h_{i+1} + (x_{i+1} - x_i)$. This enforces the downward slope constraint.
4. **Peak Calculation**: Between any two adjacent restricted points $(x_i, h_i)$ and $(x_{i+1}, h_{i+1})$, the maximum height reachable is $\lfloor (h_i + h_{i+1} + x_{i+1} - x_i) / 2 \rfloor$.
5. **Final Segment**: After the last restriction, the height can increase by 1 for every step until building $n$. Calculate $h_{last} + (n - x_{last})$ and update the global maximum.

### Visual Trace (Example 1: n=5, [[2,1],[4,1]])
- Sorted: `[[1,0], [2,1], [4,1]]`
- L->R: `[1,0], [2,min(1, 0+1)=1], [4,min(1, 1+2)=1]`
- R->L: `[4,1], [2,min(1, 1+2)=1], [1,min(0, 1+1)=0]`
- Peaks: Between (1,0) and (2,1) -> 0; Between (2,1) and (4,1) -> (1+1+4-2)/2 = 2.
- End: 1 + (5-4) = 2. Max = 2.

# Complexity
- Time complexity: $$O(M \log M)$$, where $$M$$ is the number of restrictions, due to the initial sorting. The two passes are $$O(M)$$.
- Space complexity: $$O(M)$$ to store the sorted restrictions.

```cpp []
class Solution {
public:
    int maxBuilding(int num, vector<vector<int>>& r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        int n = r.size();
        for (int i = 1; i < n; i++)
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);
        for (int i = n - 2; i >= 0; i--)
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);
        int res = 0;
        for (int i = 1; i < n; i++) {
            int x1 = r[i - 1][0], y1 = r[i - 1][1];
            int x2 = r[i][0], y2 = r[i][1];
            res = max(res, (y1 + y2 + x2 - x1) / 2);
        }
        return max(res, r[n - 1][1] + num - r[n - 1][0]);
    }
};

# Code
```cpp
class Solution {
public:
    int maxBuilding(int num, vector<vector<int>>& r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        int n = r.size();

        for (int i = 1; i < n; i++)
            r[i][1] = yCap(r[i - 1], r[i]);

        for (int i = n - 2; i >= 0; i--)
            r[i][1] = yCap(r[i + 1], r[i]);

        int res = 0;
        for (int i = 1; i < n; i++)
            res = max(res, yPeak(r[i - 1], r[i]));

        return max(res, r[n - 1][1] + num - r[n - 1][0]);
    }

    int yCap(vector<int>& l, vector<int>& r) {
        int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
        return min(y2, y1 + abs(x2 - x1));
    }

    int yPeak(vector<int>& l, vector<int>& r) {
        int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
        return (y1 + y2 + x2 - x1) >> 1;
    }
};
```

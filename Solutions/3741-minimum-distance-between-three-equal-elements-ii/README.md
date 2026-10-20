# [3741. Minimum Distance Between Three Equal Elements II](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given an integer array `nums`.

A tuple `(i, j, k)` of 3 **distinct** indices is **good** if `nums[i] == nums[j] == nums[k]`.

The **distance** of a **good** tuple is `abs(i - j) + abs(j - k) + abs(k - i)`, where `abs(x)` denotes the **absolute value** of `x`.

Return an integer denoting the **minimum** possible **distance** of a **good** tuple. If no **good** tuples exist, return `-1`.

**Example 1:**

**Input:** nums = [1,2,1,1,3]

**Output:** 6

**Explanation:**

The minimum distance is achieved by the good tuple `(0, 2, 3)`.

`(0, 2, 3)` is a good tuple because `nums[0] == nums[2] == nums[3] == 1`. Its distance is `abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6`.

**Example 2:**

**Input:** nums = [1,1,2,3,2,1,2]

**Output:** 8

**Explanation:**

The minimum distance is achieved by the good tuple `(2, 4, 6)`.

`(2, 4, 6)` is a good tuple because `nums[2] == nums[4] == nums[6] == 2`. Its distance is `abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8`.

**Example 3:**

**Input:** nums = [1]

**Output:** -1

**Explanation:**

There are no good tuples. Therefore, the answer is -1.

**Constraints:**

* `1 <= n == nums.length <= 105`
* `1 <= nums[i] <= n`

---

## Solution & Editorial
# Intuition
The distance formula for a tuple of indices $(i, j, k)$ where $i < j < k$ is $|i-j| + |j-k| + |k-i|$. Since $i < j < k$, this simplifies to $(j-i) + (k-j) + (k-i) = 2(k-i)$. To minimize this value, we only need to minimize the distance between the first and third index of any three indices belonging to the same value.

# Approach
1. Group all indices for each unique value in `nums` using an `unordered_map<int, vector<int>>`.
2. For each value, iterate through its sorted list of indices `ls` using a sliding window of size 3. Specifically, for any three consecutive indices $(ls[h], ls[h+1], ls[h+2])$, the distance is $2 \times (ls[h+2] - ls[h])$.
3. Track the global minimum distance across all values.

### Visual Trace (Example 1: nums = [1, 2, 1, 1, 3])
- Map: `{1: [0, 2, 3], 2: [1], 3: [4]}`
- Processing key `1`:
  - $h=0$: $i=0, k=3$. Distance = $2 \times (3 - 0) = 6$.
- Result: 6.

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of `nums`. We iterate through the array once to build the map, and then iterate through the indices of each value exactly once.
- Space complexity: $$O(N)$$, as we store each index exactly once in the hash map.

# Code
```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; ++i) {
            g[nums[i]].push_back(i);
        }
        const int inf = 1 << 30;
        int ans = inf;
        for (auto& [_, ls] : g) {
            int m = ls.size();
            for (int h = 0; h < m - 2; ++h) {
                int i = ls[h];
                int k = ls[h + 2];
                int t = (k - i) * 2;
                ans = min(ans, t);
            }
        }
        return ans == inf ? -1 : ans;
    }
};
```

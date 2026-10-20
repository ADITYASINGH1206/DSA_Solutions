# [3740. Minimum Distance Between Three Equal Elements I](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

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

* `1 <= n == nums.length <= 100`
* `1 <= nums[i] <= n`

---

## Solution & Editorial
# Intuition
To find a good tuple $(i, j, k)$ such that $nums[i] == nums[j] == nums[k]$, we first observe that the distance formula $abs(i - j) + abs(j - k) + abs(k - i)$ simplifies significantly when we assume $i < j < k$. In this ordered case, the distance becomes $(j - i) + (k - j) + (k - i) = k - i + k - i = 2 * (k - i)$. Thus, for any fixed value, we only need to find three indices $i, j, k$ that minimize the distance between the outermost indices $i$ and $k$.

# Approach
1. Group all indices of each unique number in `nums` using an `unordered_map<int, vector<int>>`. This allows us to process all occurrences of a specific value together.
2. For each number, if it appears at least 3 times, iterate through its sorted list of indices `ls`.
3. For any three indices $i, j, k$ where $i < j < k$, the distance is $2 * (k - i)$. To minimize this, we only need to consider consecutive triplets in the sorted index list (i.e., $ls[h], ls[h+1], ls[h+2]$). This is because any non-consecutive triplet would have a larger or equal $k-i$ distance.
4. Track the minimum distance found across all numbers. If no such tuple exists, return -1.

### Visual Trace (Example 1: nums = [1, 2, 1, 1, 3])
- Map: `{1: [0, 2, 3], 2: [1], 3: [4]}`
- Process key `1`:
  - Indices: `[0, 2, 3]`
  - Triplet `(0, 2, 3)`: $i=0, k=3$. Distance = $2 * (3 - 0) = 6$.
- Result: `6`

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of `nums`. We iterate through the array once to build the map, and then iterate through the indices of each number, which in total visits each index at most once.
- Space complexity: $$O(N)$$, required to store the indices in the hash map.

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

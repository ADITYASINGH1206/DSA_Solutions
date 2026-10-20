# [1722. Minimize Hamming Distance After Swap Operations](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/)
**Difficulty:** `Medium` | **Tags:** `array`, `depth-first-search`, `union-find`

---

## Problem Description
You are given two integer arrays, `source` and `target`, both of length `n`. You are also given an array `allowedSwaps` where each `allowedSwaps[i] = [ai, bi]` indicates that you are allowed to swap the elements at index `ai` and index `bi` **(0-indexed)** of array `source`. Note that you can swap elements at a specific pair of indices **multiple** times and in **any** order.

The **Hamming distance** of two arrays of the same length, `source` and `target`, is the number of positions where the elements are different. Formally, it is the number of indices `i` for `0 <= i <= n-1` where `source[i] != target[i]` **(0-indexed)**.

Return *the **minimum Hamming distance** of* `source` *and* `target` *after performing **any** amount of swap operations on array* `source`*.*

**Example 1:**

```
Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
Output: 1
Explanation: source can be transformed the following way:
- Swap indices 0 and 1: source = [2,1,3,4]
- Swap indices 2 and 3: source = [2,1,4,3]
The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
```

**Example 2:**

```
Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
Output: 2
Explanation: There are no allowed swaps.
The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
```

**Example 3:**

```
Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
Output: 0
```

**Constraints:**

* `n == source.length == target.length`
* `1 <= n <= 105`
* `1 <= source[i], target[i] <= 105`
* `0 <= allowedSwaps.length <= 105`
* `allowedSwaps[i].length == 2`
* `0 <= ai, bi <= n - 1`
* `ai != bi`

---

## Solution & Editorial
# Intuition
The problem allows us to swap elements at arbitrary indices if they are connected via the `allowedSwaps` graph. This implies that within any connected component of indices, we can rearrange the elements of `source` in any permutation we desire. To minimize the Hamming distance, we should match as many elements as possible between `source` and `target` within each connected component.

# Approach
1. **Disjoint Set Union (DSU)**: Treat each index as a node in a graph. Use a DSU structure to group indices that are connected by `allowedSwaps`. The `find` function with path compression identifies the root of each component.
2. **Component Mapping**: Iterate through all indices `i` from `0` to `n-1`. For each index, count the frequency of values present in `source` for that specific component using a hash map `cnt` where `cnt[root][value]` stores the count of `value` in the component rooted at `root`.
3. **Hamming Distance Calculation**: Iterate through all indices `i` again. For each `target[i]`, check if it exists in the `source` values of its corresponding component. If `cnt[find(i)][target[i]] > 0`, we can "match" this target value with a source value, so we decrement the count. Otherwise, this position contributes to the Hamming distance.

### Visual Trace (Example 1)
`source = [1,2,3,4]`, `target = [2,1,4,5]`, `swaps = [[0,1],[2,3]]`
- **DSU Groups**: `{0, 1}` (root 0), `{2, 3}` (root 2).
- **Source Counts**: 
  - Root 0: `{1:1, 2:1}`
  - Root 2: `{3:1, 4:1}`
- **Matching**: 
  - Index 0: `target[0]=2`. Found in Root 0. `cnt[0][2]` becomes 0.
  - Index 1: `target[1]=1`. Found in Root 0. `cnt[0][1]` becomes 0.
  - Index 2: `target[2]=4`. Found in Root 2. `cnt[2][4]` becomes 0.
  - Index 3: `target[3]=5`. Not in Root 2. `ans` increments to 1.

# Complexity
- Time complexity: $$O(N \alpha(N) + M \alpha(N))$$ where $$N$$ is the number of elements and $$M$$ is the number of swaps. The DSU operations take nearly constant time on average due to path compression.
- Space complexity: $$O(N)$$ to store the DSU parent array and the frequency maps for each component.

# Code
```cpp
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return x == p[x] ? x : p[x] = find(p[x]);
        };
        for (auto& a : allowedSwaps) {
            p[find(a[0])] = find(a[1]);
        }
        unordered_map<int, unordered_map<int, int>> cnt;
        for (int i = 0; i < n; ++i) {
            ++cnt[find(i)][source[i]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (--cnt[find(i)][target[i]] < 0) {
                ++ans;
            }
        }
        return ans;
    }
};
```

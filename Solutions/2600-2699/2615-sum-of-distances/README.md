# [2615. Sum of Distances](https://leetcode.com/problems/sum-of-distances/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** integer array `nums`.

There exists an array `arr` of length `nums.length`, where `arr[i]` is the sum of `|i - j|` over all `j` such that `nums[j] == nums[i]` and `j != i`. If there is no such `j`, set `arr[i]` to be 0.

Return the array `arr`.

**Example 1:**

```
Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
Explanation: 
When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
When i = 1, arr[1] = 0 because there is no other index with value 3.
When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
When i = 4, arr[4] = 0 because there is no other index with value 2.
```

**Example 2:**

```
Input: nums = [0,5,3]
Output: [0,0,0]
Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 109`

**Note:** This question is the same as  [2121: Intervals Between Identical Elements.](https://leetcode.com/problems/intervals-between-identical-elements/description/)

---

## Solution & Editorial
# Intuition
To calculate the sum of absolute differences $|i - j|$ for all indices $j$ where $nums[j] == nums[i]$, we observe that for a fixed value $v$, if we have a sorted list of indices $idx = [p_0, p_1, ..., p_{m-1}]$, the sum for index $p_k$ is $\sum_{j=0}^{m-1} |p_k - p_j|$. This can be split into two parts: indices smaller than $p_k$ and indices larger than $p_k$. By maintaining prefix sums of these indices, we can compute the total distance in constant time per index.

# Approach
1. Group indices by their values using an `unordered_map<int, vector<int>>`. This allows us to process each unique number independently.
2. For each group of indices $idx$, calculate the total sum of distances. Let $m$ be the number of occurrences. For a specific index $idx[i]$, the sum is $(i \cdot idx[i] - \sum_{j=0}^{i-1} idx[j]) + (\sum_{j=i+1}^{m-1} idx[j] - (m - 1 - i) \cdot idx[i])$.
3. Instead of recomputing sums, we maintain `left` (sum of distances to indices on the left) and `right` (sum of distances to indices on the right). As we iterate through the sorted indices, we update `left` and `right` incrementally.

### Visual Trace (Example 1: nums = [1, 3, 1, 1, 2])
For value 1, indices are [0, 2, 3]. $m=3$.
- $i=0$: $left=0, right=(2-0)+(3-0)=5$. $ans[0]=5$.
- $i=1$: $left=0+(2-0)*1=2, right=5-(2-0)*2=1$. $ans[2]=2+1=3$.
- $i=2$: $left=2+(3-2)*2=4, right=1-(3-2)*0=0$. $ans[3]=4+0=4$.

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the length of the array. We iterate through the array once to group indices and once more to compute the sums, visiting each index exactly once.
- Space complexity: $$O(N)$$ to store the indices in the hash map and the result array.

# Code
```cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> d;
        for (int i = 0; i < n; ++i) {
            d[nums[i]].push_back(i);
        }
        for (auto& [_, idx] : d) {
            int m = idx.size();
            long long left = 0;
            long long right = -1LL * m * idx[0];
            for (int i : idx) {
                right += i;
            }
            for (int i = 0; i < m; ++i) {
                ans[idx[i]] = left + right;
                if (i + 1 < m) {
                    left += (idx[i + 1] - idx[i]) * (i + 1);
                    right -= (idx[i + 1] - idx[i]) * (m - i - 1);
                }
            }
        }
        return ans;
    }
};
```

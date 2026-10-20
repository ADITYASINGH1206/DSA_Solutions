# [3788. Maximum Score of a Split](https://leetcode.com/problems/maximum-score-of-a-split/)
**Difficulty:** `Medium` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` of length `n`.

Choose an index `i` such that `0 <= i < n - 1`.

For a chosen split index `i`:

* Let `prefixSum(i)` be the sum of `nums[0] + nums[1] + ... + nums[i]`.
* Let `suffixMin(i)` be the minimum value among `nums[i + 1], nums[i + 2], ..., nums[n - 1]`.

The **score** of a split at index `i` is defined as:

`score(i) = prefixSum(i) - suffixMin(i)`

Return an integer denoting the **maximum** score over all valid split indices.

**Example 1:**

**Input:** nums = [10,-1,3,-4,-5]

**Output:** 17

**Explanation:**

The optimal split is at `i = 2`, `score(2) = prefixSum(2) - suffixMin(2) = (10 + (-1) + 3) - (-5) = 17`.

**Example 2:**

**Input:** nums = [-7,-5,3]

**Output:** -2

**Explanation:**

The optimal split is at `i = 0`, `score(0) = prefixSum(0) - suffixMin(0) = (-7) - (-5) = -2`.

**Example 3:**

**Input:** nums = [1,1]

**Output:** 0

**Explanation:**

The only valid split is at `i = 0`, `score(0) = prefixSum(0) - suffixMin(0) = 1 - 1 = 0`.

**Constraints:**

* `2 <= nums.length <= 105`
* `-109​​​​​​​ <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
To maximize the score `prefixSum(i) - suffixMin(i)`, we need to efficiently calculate the prefix sum up to index `i` and the minimum value in the suffix starting from `i+1` for every possible split point `i`. Since the constraints allow $O(N)$ time, we can precompute these values using two auxiliary arrays.

# Approach
1. **Prefix Sums**: Iterate from index `0` to `n-2` to compute the running sum of elements. Store these in a `prefix_sum` vector where `prefix_sum[i]` holds the sum of `nums[0...i]`.
2. **Suffix Minimums**: Iterate backwards from `n-1` down to `1`. Maintain a running minimum `mini` of the elements encountered so far. Store the minimum of the suffix `nums[i...n-1]` at `suffix_min[i-1]`.
3. **Calculate Score**: Iterate through all valid split indices `i` (from `0` to `n-2`), compute `prefix_sum[i] - suffix_min[i]`, and track the global maximum.

### Visual Trace (Example 1: [10, -1, 3, -4, -5])
| i | nums[i] | prefixSum[i] | suffixMin[i] | score | 
|---|---|---|---|---|
| 0 | 10 | 10 | -5 | 15 |
| 1 | -1 | 9 | -5 | 14 |
| 2 | 3 | 12 | -5 | 17 |
| 3 | -4 | 8 | -5 | 13 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform three linear passes: one for prefix sums, one for suffix minimums, and one to compute the maximum score.
- Space complexity: $$O(N)$$ to store the `prefix_sum` and `suffix_min` arrays.

# Code
```cpp
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ans = LLONG_MIN;
        vector<long long> prefix_sum;
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i<n-1;i++){
            sum += nums[i];
            prefix_sum.push_back(sum);
        }
        vector<int> suffix_min(n,0);
        int mini = INT_MAX;
        for(int i =n-1;i>0;i--){
            mini = min(mini,nums[i]);
            suffix_min[i-1] = mini;
        }
        for(int i = 0;i<n-1;i++){
            ans = max(ans,prefix_sum[i]-suffix_min[i]);
        }

        return ans;
    }
};
```

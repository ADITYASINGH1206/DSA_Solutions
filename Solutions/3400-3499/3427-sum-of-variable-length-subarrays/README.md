# [3427. Sum of Variable Length Subarrays](https://leetcode.com/problems/sum-of-variable-length-subarrays/)
**Difficulty:** `Easy` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` of size `n`. For **each** index `i` where `0 <= i < n`, define a subarray `nums[start ... i]` where `start = max(0, i - nums[i])`.

Return the total sum of all elements from the subarray defined for each index in the array.

**Example 1:**

**Input:** nums = [2,3,1]

**Output:** 11

**Explanation:**

| i | Subarray | Sum |
| --- | --- | --- |
| 0 | `nums[0] = [2]` | 2 |
| 1 | `nums[0 ... 1] = [2, 3]` | 5 |
| 2 | `nums[1 ... 2] = [3, 1]` | 4 |
| **Total Sum** |  | 11 |

The total sum is 11. Hence, 11 is the output.

**Example 2:**

**Input:** nums = [3,1,1,2]

**Output:** 13

**Explanation:**

| i | Subarray | Sum |
| --- | --- | --- |
| 0 | `nums[0] = [3]` | 3 |
| 1 | `nums[0 ... 1] = [3, 1]` | 4 |
| 2 | `nums[1 ... 2] = [1, 1]` | 2 |
| 3 | `nums[1 ... 3] = [1, 1, 2]` | 4 |
| **Total Sum** |  | 13 |

The total sum is 13. Hence, 13 is the output.

**Constraints:**

* `1 <= n == nums.length <= 100`
* `1 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks us to compute the sum of specific subarrays defined by a dynamic starting index `start = max(0, i - nums[i])` for every index `i`. Given the small constraints (n <= 100), a direct simulation of these subarrays is efficient and optimal.

# Approach
1. Initialize an integer `ans` to 0 to store the cumulative sum.
2. Iterate through each index `i` from `0` to `n-1`.
3. For each `i`, calculate the `start` index using `max(0, i - nums[i])`.
4. Iterate from `start` to `i` (inclusive) and add each element `nums[j]` to `ans`.
5. Return `ans` after processing all indices.

### Visual Trace (Example 1: nums = [2, 3, 1])
| i | nums[i] | start | Subarray | Sum | ans |
|---|---|---|---|---|---|
| 0 | 2 | max(0, 0-2)=0 | [2] | 2 | 2 |
| 1 | 3 | max(0, 1-3)=0 | [2, 3] | 5 | 7 |
| 2 | 1 | max(0, 2-1)=1 | [3, 1] | 4 | 11 |

# Complexity
- Time complexity: $$O(n^2)$$, where $$n$$ is the length of the array. In the worst case, each subarray spans the entire array, leading to a nested loop structure.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int start = max(0, i - nums[i]);
            for (int j = start; j <= i; ++j) {
                ans += nums[j];
            }
        }
        return ans;
    }
};
```

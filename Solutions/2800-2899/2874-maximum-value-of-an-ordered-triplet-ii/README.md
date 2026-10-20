# [2874. Maximum Value of an Ordered Triplet II](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** integer array `nums`.

Return ***the maximum value over all triplets of indices*** `(i, j, k)` *such that* `i < j < k`*.* If all such triplets have a negative value, return `0`.

The **value of a triplet of indices** `(i, j, k)` is equal to `(nums[i] - nums[j]) * nums[k]`.

**Example 1:**

```
Input: nums = [12,6,1,2,7]
Output: 77
Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
It can be shown that there are no ordered triplets of indices with a value greater than 77.
```

**Example 2:**

```
Input: nums = [1,10,3,4,19]
Output: 133
Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
It can be shown that there are no ordered triplets of indices with a value greater than 133.
```

**Example 3:**

```
Input: nums = [1,2,3]
Output: 0
Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.
```

**Constraints:**

* `3 <= nums.length <= 105`
* `1 <= nums[i] <= 106`

---

## Solution & Editorial
# Intuition
To maximize the expression `(nums[i] - nums[j]) * nums[k]` for `i < j < k`, we observe that for a fixed `j`, we want to maximize `nums[i]` (where `i < j`) and `nums[k]` (where `k > j`). By precomputing the maximum values to the left and right of every index, we can transform an $O(N^3)$ brute-force search into an $O(N)$ linear scan.

# Approach
1. Create two arrays: `left` to store the maximum value encountered from the start up to index `i`, and `right` to store the maximum value from the end down to index `i`.
2. Iterate forward to populate `left[i] = max(left[i-1], nums[i])`.
3. Iterate backward to populate `right[i] = max(right[i+1], nums[i])`.
4. Iterate through all possible middle indices `j` (from `1` to `n-2`). For each `j`, the maximum possible value is `(left[j-1] - nums[j]) * right[j+1]`.
5. Maintain a global `ans` variable to track the maximum result found, ensuring we return `0` if all results are negative.

### Visual Trace (Example 1: [12, 6, 1, 2, 7])
| Index | nums | left | right |
|-------|------|------|-------|
| 0 | 12 | 12 | 12 |
| 1 | 6 | 12 | 7 |
| 2 | 1 | 12 | 7 |
| 3 | 2 | 12 | 7 |
| 4 | 7 | 12 | 7 |

For `j=2`: `(left[1] - nums[2]) * right[3] = (12 - 1) * 7 = 77`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the array. We perform three linear passes: one for `left`, one for `right`, and one for the final calculation.
- Space complexity: $$O(N)$$ to store the `left` and `right` arrays.

# Code
```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1], nums[i]);
        }
        for(int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1], nums[i]);
        }
        long long ans = 0; 
        for(int i = 1; i < n - 1; i++){
            long long res = (long long)(left[i-1] - nums[i]) * right[i+1];
            ans = max(ans, res);
        }

        return ans;
    }
};
```

# [3432. Count Partitions with Even Sum Difference](https://leetcode.com/problems/count-partitions-with-even-sum-difference/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` of length `n`.

A **partition** is defined as an index `i` where `0 <= i < n - 1`, splitting the array into two **non-empty** subarrays such that:

* Left subarray contains indices `[0, i]`.
* Right subarray contains indices `[i + 1, n - 1]`.

Return the number of **partitions** where the **difference** between the **sum** of the left and right subarrays is **even**.

**Example 1:**

**Input:** nums = [10,10,3,7,6]

**Output:** 4

**Explanation:**

The 4 partitions are:

* `[10]`, `[10, 3, 7, 6]` with a sum difference of `10 - 26 = -16`, which is even.
* `[10, 10]`, `[3, 7, 6]` with a sum difference of `20 - 16 = 4`, which is even.
* `[10, 10, 3]`, `[7, 6]` with a sum difference of `23 - 13 = 10`, which is even.
* `[10, 10, 3, 7]`, `[6]` with a sum difference of `30 - 6 = 24`, which is even.

**Example 2:**

**Input:** nums = [1,2,2]

**Output:** 0

**Explanation:**

No partition results in an even sum difference.

**Example 3:**

**Input:** nums = [2,4,6,8]

**Output:** 3

**Explanation:**

All partitions result in an even sum difference.

**Constraints:**

* `2 <= n == nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To determine if the difference between the left subarray sum ($L$) and the right subarray sum ($R$) is even, we observe that $L - R$ is even if and only if $L$ and $R$ have the same parity (both even or both odd). Since the total sum $S = L + R$, if $S$ is odd, $L$ and $R$ must have different parities, making $L - R$ always odd. If $S$ is even, $L$ and $R$ must have the same parity, making $L - R$ always even.

# Approach
1. Calculate the total sum of the array, `rsum`.
2. Iterate through the array from index `0` to `n - 2` to maintain a running `lsum` (left subarray sum) and update `rsum` (right subarray sum) by subtracting the current element.
3. For each partition point `i`, check if `(lsum - rsum) % 2 == 0`. If true, increment the counter `ans`.

### Visual Trace (Example 1: [10, 10, 3, 7, 6])
| i | nums[i] | lsum | rsum | diff | Even? |
|---|---|---|---|---|---|
| 0 | 10 | 10 | 26 | -16 | Yes |
| 1 | 10 | 20 | 16 | 4 | Yes |
| 2 | 3 | 23 | 13 | 10 | Yes |
| 3 | 7 | 30 | 6 | 24 | Yes |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform one pass to calculate the total sum and one pass to iterate through potential partition points.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
    
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0;
        int ans = 0;
        
        for(int i = 0; i < n - 1; i++){
            lsum += nums[i];       
            rsum -= nums[i];       
            if((lsum - rsum) % 2 == 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
```

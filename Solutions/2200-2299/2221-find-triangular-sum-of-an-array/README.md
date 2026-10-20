# [2221. Find Triangular Sum of an Array](https://leetcode.com/problems/find-triangular-sum-of-an-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `simulation`, `combinatorics`, `number-theory`

---

## Problem Description
You are given a **0-indexed** integer array `nums`, where `nums[i]` is a digit between `0` and `9` (**inclusive**).

The **triangular sum** of `nums` is the value of the only element present in `nums` after the following process terminates:

1. Let `nums` comprise of `n` elements. If `n == 1`, **end** the process. Otherwise, **create** a new **0-indexed** integer array `newNums` of length `n - 1`.
2. For each index `i`, where `0 <= i < n - 1`, **assign** the value of `newNums[i]` as `(nums[i] + nums[i+1]) % 10`, where `%` denotes modulo operator.
3. **Replace** the array `nums` with `newNums`.
4. **Repeat** the entire process starting from step 1.

Return *the triangular sum of* `nums`.

**Example 1:**

```
Input: nums = [1,2,3,4,5]
Output: 8
Explanation:
The above diagram depicts the process from which we obtain the triangular sum of the array.
```

**Example 2:**

```
Input: nums = [5]
Output: 5
Explanation:
Since there is only one element in nums, the triangular sum is the value of that element itself.
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `0 <= nums[i] <= 9`

---

## Solution & Editorial
# Intuition
The problem describes a process analogous to Pascal's Triangle, where each element in the next row is the sum of two adjacent elements in the current row, taken modulo 10. Since the constraints are small (N <= 1000), a direct simulation of this process is efficient enough to pass within time limits.

# Approach
1. Maintain the current size `n` of the array. While `n > 1`, we perform a reduction step.
2. In each iteration, update the array in-place. For each index `i` from `0` to `n-2`, set `nums[i] = (nums[i] + nums[i+1]) % 10`.
3. Decrement `n` after each pass to reflect the shrinking size of the array.
4. Once `n == 1`, the remaining element at `nums[0]` is the triangular sum.

### Visual Trace (Example 1: [1, 2, 3, 4, 5])
| Iteration | Array State |
| :--- | :--- |
| Start | [1, 2, 3, 4, 5] |
| Pass 1 | [3, 5, 7, 9] |
| Pass 2 | [8, 2, 6] |
| Pass 3 | [0, 8] |
| Pass 4 | [8] |

# Complexity
- Time complexity: $$O(N^2)$$, where $$N$$ is the length of the input array. We perform $$N-1$$ passes, and the $$k$$-th pass performs $$N-k$$ additions. The sum of the arithmetic series $$(N-1) + (N-2) + ... + 1$$ is $$O(N^2)$$.
- Space complexity: $$O(1)$$, as we perform the reduction in-place using the existing `nums` vector without allocating additional data structures.

# Code
```cpp
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n>1){
            for(int i = 0;i<n-1;i++){
                nums[i] = (nums[i] + nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }
    
};
```

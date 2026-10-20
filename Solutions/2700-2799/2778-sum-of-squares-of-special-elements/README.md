# [2778. Sum of Squares of Special Elements ](https://leetcode.com/problems/sum-of-squares-of-special-elements/)
**Difficulty:** `Easy` | **Tags:** `array`, `enumeration`

---

## Problem Description
You are given a **1-indexed** integer array `nums` of length `n`.

An element `nums[i]` of `nums` is called **special** if `i` divides `n`, i.e. `n % i == 0`.

Return *the **sum of the squares** of all **special** elements of* `nums`.

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: 21
Explanation: There are exactly 3 special elements in nums: nums[1] since 1 divides 4, nums[2] since 2 divides 4, and nums[4] since 4 divides 4. 
Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21.
```

**Example 2:**

```
Input: nums = [2,7,1,19,18,3]
Output: 63
Explanation: There are exactly 4 special elements in nums: nums[1] since 1 divides 6, nums[2] since 2 divides 6, nums[3] since 3 divides 6, and nums[6] since 6 divides 6. 
Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63.
```

**Constraints:**

* `1 <= nums.length == n <= 50`
* `1 <= nums[i] <= 50`

---

## Solution & Editorial
# Intuition
The problem asks us to identify elements at indices that are divisors of the array length $n$. Since the array is 1-indexed, an element at 0-indexed position `i` corresponds to the 1-indexed position `i + 1`. We simply need to iterate through the array and check the divisibility condition for each index.

# Approach
1. Initialize a variable `ans` to 0 to store the cumulative sum of squares.
2. Determine the length of the array `n`.
3. Iterate through the array using a loop from `i = 0` to `n - 1`.
4. For each index `i`, check if `n` is divisible by `i + 1` using the modulo operator: `n % (i + 1) == 0`.
5. If the condition holds, square the value `nums[i]` and add it to `ans`.
6. Return `ans` after the loop completes.

### Visual Trace (Example 1: nums = [1, 2, 3, 4], n = 4)
| i | i+1 | n % (i+1) == 0 | nums[i] | Square | ans |
|---|-----|----------------|---------|--------|-----|
| 0 | 1   | 4 % 1 == 0 (T) | 1       | 1      | 1   |
| 1 | 2   | 4 % 2 == 0 (T) | 2       | 4      | 5   |
| 2 | 3   | 4 % 3 == 0 (F) | 3       | -      | 5   |
| 3 | 4   | 4 % 4 == 0 (T) | 4       | 16     | 21  |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass over the input array, executing constant-time arithmetic operations at each step.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(n%(i+1)==0){
                ans += pow(nums[i],2);
            }
        }
        return ans;
    }
};
```

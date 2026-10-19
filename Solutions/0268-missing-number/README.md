# [268. Missing Number](https://leetcode.com/problems/missing-number/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `math`, `binary-search`, `bit-manipulation`, `sorting`

---

## Problem Description
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

**Example 1:**

**Input:** nums = [3,0,1]

**Output:** 2

**Explanation:**

`n = 3` since there are 3 numbers, so all numbers are in the range `[0,3]`. 2 is the missing number in the range since it does not appear in `nums`.

**Example 2:**

**Input:** nums = [0,1]

**Output:** 2

**Explanation:**

`n = 2` since there are 2 numbers, so all numbers are in the range `[0,2]`. 2 is the missing number in the range since it does not appear in `nums`.

**Example 3:**

**Input:** nums = [9,6,4,2,3,5,7,0,1]

**Output:** 8

**Explanation:**

`n = 9` since there are 9 numbers, so all numbers are in the range `[0,9]`. 8 is the missing number in the range since it does not appear in `nums`.

**Constraints:**

* `n == nums.length`
* `1 <= n <= 104`
* `0 <= nums[i] <= n`
* All the numbers of `nums` are **unique**.

**Follow up:** Could you implement a solution using only `O(1)` extra space complexity and `O(n)` runtime complexity?

---

## Solution & Editorial
# Intuition
The problem asks us to find the single missing number from an array containing $n$ distinct numbers in the range $[0, n]$. Since the numbers form a continuous sequence from $0$ to $n$ with exactly one missing element, we can utilize the arithmetic progression sum formula to find the expected sum and subtract the actual sum of the elements present in the array.

# Approach
1. Initialize a variable `sum` to $0$ and store the size of the array `nums` in variable `n`.
2. Iterate through each element in `nums` using a for loop and accumulate their total into `sum`.
3. Calculate the expected sum of all integers from $0$ to $n$ using the standard formula $n \times (n + 1) / 2$.
4. Subtract the accumulated `sum` from the expected sum to isolate the missing number and return the result.

### Visual Trace Walkthrough
For Example 1: `nums = [3, 0, 1]`
- `n = 3`
- Loop execution:
  - `i = 0`: `nums[0] = 3`, `sum = 3`
  - `i = 1`: `nums[1] = 0`, `sum = 3 + 0 = 3`
  - `i = 2`: `nums[2] = 1`, `sum = 3 + 1 = 4`
- Expected Sum: $3 \times (3 + 1) / 2 = 6$
- Result: `6 - 4 = 2`

# Complexity
- Time complexity: $$O(n)$$ — We iterate through the array of size $n$ exactly once to compute the sum.
- Space complexity: $$O(1)$$ — Only a constant amount of extra memory is used for scalar variables `sum`, `n`, and `ans`.

# Code
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        int ans = (n*(n+1))/2 -sum;
        return ans;
    }
};
```

# [2535. Difference Between Element Sum and Digit Sum of an Array](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given a positive integer array `nums`.

* The **element sum** is the sum of all the elements in `nums`.
* The **digit sum** is the sum of all the digits (not necessarily distinct) that appear in `nums`.

Return *the **absolute** difference between the **element sum** and **digit sum** of* `nums`.

**Note** that the absolute difference between two integers `x` and `y` is defined as `|x - y|`.

**Example 1:**

```
Input: nums = [1,15,6,3]
Output: 9
Explanation: 
The element sum of nums is 1 + 15 + 6 + 3 = 25.
The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
The absolute difference between the element sum and digit sum is |25 - 16| = 9.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: 0
Explanation:
The element sum of nums is 1 + 2 + 3 + 4 = 10.
The digit sum of nums is 1 + 2 + 3 + 4 = 10.
The absolute difference between the element sum and digit sum is |10 - 10| = 0.
```

**Constraints:**

* `1 <= nums.length <= 2000`
* `1 <= nums[i] <= 2000`

---

## Solution & Editorial
# Intuition
The problem asks for the absolute difference between the sum of array elements and the sum of their individual digits. Since the constraints are small (array length up to 2000, values up to 2000), a direct simulation calculating both sums independently is efficient and straightforward.

# Approach
1. Calculate the `elementSum` by iterating through the array and summing all integers.
2. Calculate the `digitSum` by iterating through each integer in the array and extracting its digits using modulo (`% 10`) and division (`/ 10`) operations.
3. Return the absolute difference `|elementSum - digitSum|`.

### Visual Trace (Example 1: [1, 15, 6, 3])
| Step | Current Num | Element Sum | Digit Sum |
| :--- | :--- | :--- | :--- |
| Init | - | 0 | 0 |
| 1 | 1 | 1 | 1 |
| 2 | 15 | 16 | 1 + (1+5) = 7 |
| 3 | 6 | 22 | 7 + 6 = 13 |
| 4 | 3 | 25 | 13 + 3 = 16 |
| Final | - | 25 | 16 | Result: |25-16| = 9 |

# Complexity
- Time complexity: $$O(N \cdot \log_{10}(M))$$, where $$N$$ is the number of elements and $$M$$ is the maximum value in the array. Each number is processed to extract its digits, which takes logarithmic time relative to its value.
- Space complexity: $$O(1)$$, as we only use a few integer variables to store the running sums.

# Code
```cpp
class Solution {
public:
    int helper(int n){
        int t = n;
        int digitSum = 0;
        while(t>0){
            digitSum += t%10;
            t/=10;
        }
        return digitSum;
    }
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int digits = 0;
        for(int i = 0;i<nums.size();i++){
            digits += helper(nums[i]);
        }
        return abs(sum-digits);
    }
};
```

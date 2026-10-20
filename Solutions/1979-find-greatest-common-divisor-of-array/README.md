# [1979. Find Greatest Common Divisor of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `number-theory`, `euclidean-algorithm`, `greatest-common-divisor`

---

## Problem Description
Given an integer array `nums`, return*the **greatest common divisor** of the smallest number and largest number in* `nums`.

The **greatest common divisor** of two numbers is the largest positive integer that evenly divides both numbers.

**Example 1:**

```
Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
```

**Example 2:**

```
Input: nums = [7,5,6,8,3]
Output: 1
Explanation:
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.
```

**Example 3:**

```
Input: nums = [3,3]
Output: 3
Explanation:
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.
```

**Constraints:**

* `2 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
To find the greatest common divisor (GCD) of the smallest and largest elements in an array, we must first identify these two boundary values. Once found, we can apply the Euclidean algorithm, which is the standard, efficient method for computing the GCD of two integers.

# Approach
1. Initialize `smallest` to `INT_MAX` and `largest` to `INT_MIN` to track the array bounds.
2. Iterate through the `nums` vector once. For each element `nums[i]`, update `largest` if the current value is greater, and update `smallest` if the current value is smaller.
3. After the loop, use the built-in `__gcd(largest, smallest)` function to compute the result.

### Visual Trace (Example 1: [2, 5, 6, 9, 10])
| Iteration | nums[i] | smallest | largest |
|-----------|---------|----------|---------|
| Initial   | -       | INT_MAX  | INT_MIN |
| 1         | 2       | 2        | 2       |
| 2         | 5       | 2        | 5       |
| 3         | 6       | 2        | 6       |
| 4         | 9       | 2        | 9       |
| 5         | 10      | 2        | 10      |

Result: `__gcd(10, 2)` = 2.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in the array. We perform a single pass to find the min and max, and the GCD calculation takes logarithmic time relative to the values, which is negligible here.
- Space complexity: $$O(1)$$, as we only use two integer variables to store the min and max values regardless of the input size.

# Code
```cpp
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >largest){
                largest = nums[i];
            }
            if(nums[i]<smallest){
                smallest = nums[i];
            }
        }
        return __gcd(largest, smallest);
    }
};
```

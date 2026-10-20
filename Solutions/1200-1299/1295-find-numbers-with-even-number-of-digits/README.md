# [1295. Find Numbers with Even Number of Digits](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
Given an array `nums` of integers, return how many of them contain an **even number** of digits.

**Example 1:**

```
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
```

**Example 2:**

```
Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
```

**Constraints:**

* `1 <= nums.length <= 500`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
The problem requires us to count how many numbers in the given array contain an even number of digits. We can inspect each number individually, count its digits by repeatedly dividing by 10, and check if the total digit count is even.

# Approach
1. Initialize a counter `ans` to `0` to keep track of numbers with an even number of digits.
2. Iterate through each `num` in the `nums` vector.
3. For each `num`, copy it into a temporary variable `temp` and initialize `digits` to `0`.
4. While `temp` is non-zero, increment `digits` and perform integer division `temp /= 10` to strip the last digit.
5. After the inner loop terminates, check if `digits % 2 == 0`. If true, increment `ans`.
6. Return `ans` after processing all elements.

### Visual Trace Walkthrough (Example 1: nums = [12, 345, 2, 6, 7896])

| `num` | `temp` iterations | `digits` | `digits % 2 == 0` | `ans` update |
|---|---|---|---|---|
| 12 | 12 -> 1 -> 0 | 2 | True | `ans` becomes 1 |
| 345 | 345 -> 34 -> 3 -> 0 | 3 | False | `ans` remains 1 |
| 2 | 2 -> 0 | 1 | False | `ans` remains 1 |
| 6 | 6 -> 0 | 1 | False | `ans` remains 1 |
| 7896 | 7896 -> 789 -> 78 -> 7 -> 0 | 4 | True | `ans` becomes 2 |

# Complexity
- Time complexity: $$O(N \log_{10} M)$$, where $$N$$ is the number of elements in `nums` and $$M$$ is the maximum value in `nums`. Each number takes $$O(\log_{10}(\text{num}))$$ divisions to count its digits.
- Space complexity: $$O(1)$$, as only a constant amount of extra memory (`ans`, `temp`, `digits`) is used regardless of input size.

# Code
```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int num:nums){
            int temp = num;
            int digits = 0;
            while(temp){
                digits++;
                temp/=10;
            }
            if(digits%2 ==0) ans++;
        }
        return ans;
    }
};
```

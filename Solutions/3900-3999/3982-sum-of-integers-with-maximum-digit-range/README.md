# [3982. Sum of Integers with Maximum Digit Range](https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given an integer array `nums`.

The **digit range** of an integer is defined as the difference between its **largest** digit and **smallest** digit.

For example, the digit range of 5724 is `7 - 2 = 5`.

Return the sum of all integers in `nums` whose **digit range** is equal to the **maximum digit range** among all integers in the array.

**Example 1:**

**Input:** nums = [5724,111,350]

**Output:** 6074

**Explanation:**

| `i` | `nums[i]` | Largest | Smallest | Digit Range |
| --- | --- | --- | --- | --- |
| 0 | 5724 | 7 | 2 | 5 |
| 1 | 111 | 1 | 1 | 0 |
| 2 | 350 | 5 | 0 | 5 |

The maximum digit range is 5. The integers with this digit range are 5724 and 350, so the answer is `5724 + 350 = 6074`.

**Example 2:**

**Input:** nums = [90,900]

**Output:** 990

**Explanation:**

| `i` | `nums[i]` | Largest | Smallest | Digit Range |
| --- | --- | --- | --- | --- |
| 0 | 90 | 9 | 0 | 9 |
| 1 | 900 | 9 | 0 | 9 |

The maximum digit range is 9. Both integers have this digit range, so the answer is `90 + 900 = 990`.

**Constraints:**

* `1 <= nums.length <= 100`
* `10 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To solve this problem, we need to identify the maximum digit range across all numbers in the array and then aggregate the sum of all numbers that share this specific range. Since the range is defined by the difference between the maximum and minimum digits of a number, we can compute this for each integer using simple modulo and division operations.

# Approach
1. Initialize `maxi` to track the global maximum digit range found so far and `ans` to store the cumulative sum of numbers matching this range.
2. Iterate through each integer in `nums`. For each integer:
   - Extract digits using `temp % 10` and `temp /= 10`.
   - Maintain `m1` (maximum digit) and `s1` (minimum digit) during the extraction.
   - Calculate the digit range `dif = m1 - s1`.
3. If `dif > maxi`, update `maxi = dif` and reset `ans = nums[i]` (since a new maximum range is found, previous sums are discarded).
4. If `dif == maxi`, add `nums[i]` to `ans`.

### Visual Trace (Example 1: [5724, 111, 350])
| Iteration | Number | Max Digit | Min Digit | Range | Max Range (`maxi`) | Sum (`ans`) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 5724 | 7 | 2 | 5 | 5 | 5724 |
| 2 | 111 | 1 | 1 | 0 | 5 | 5724 |
| 3 | 350 | 5 | 0 | 5 | 5 | 6074 |

# Complexity
- Time complexity: $$O(N \cdot K)$$, where $$N$$ is the number of elements in `nums` and $$K$$ is the number of digits in the largest integer (at most 6 for $10^5$). This is effectively $$O(N)$$.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int maxi =  0;
        for(int i = 0;i<n;i++){
            int temp = nums[i];
            int m1 = 0;
            int s1 = INT_MAX;
            int dif = 0;
            while(temp){
                int digit = temp%10;
                if(digit > m1) m1 = digit;
                if(digit < s1) s1 = digit;
                temp/=10;
            }
            dif = m1-s1;
            if(dif>maxi){
                maxi = dif;
                ans = nums[i];
            }
            else if(dif == maxi){
                ans += nums[i];
            }
        }
        return ans;
    }
};
```

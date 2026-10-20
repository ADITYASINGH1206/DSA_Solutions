# [3895. Count Digit Appearances](https://leetcode.com/problems/count-digit-appearances/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`

---

## Problem Description
You are given an integer array `nums` and an integer `digit`.

Return the total number of times `digit` appears in the decimal representation of all elements in `nums`.

**Example 1:**

**Input:** nums = [12,54,32,22], digit = 2

**Output:** 4

**Explanation:**

The digit 2 appears once in 12 and 32, and twice in 22. Thus, the total number of times digit 2 appears is 4.

**Example 2:**

**Input:** nums = [1,34,7], digit = 9

**Output:** 0

**Explanation:**

The digit 9 does not appear in the decimal representation of any element in `nums`, so the total number of times digit 9 appears is 0.

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 106​​​​​​​`
* `0 <= digit <= 9`

---

## Solution & Editorial
# Intuition
To count the occurrences of a specific digit across an array of integers, we must decompose each integer into its constituent decimal digits. Since the constraints on `nums[i]` are relatively small (up to 10^6), iterating through each number and extracting digits using modulo and division operations is highly efficient.

# Approach
1. Initialize a counter `ans` to 0.
2. Iterate through each integer `num` in the input vector `nums`.
3. For each `num`, create a temporary variable `temp` to process its digits.
4. While `temp` is greater than 0, extract the last digit using `temp % 10`.
5. Compare the extracted digit with the target `digit`. If they match, increment `ans`.
6. Update `temp` by performing integer division `temp /= 10` to shift to the next decimal place.
7. Return `ans` after processing all elements.

### Visual Trace (Example 1: nums = [12, 22], digit = 2)
| Number | Iteration | temp | dig | Match? | ans |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 12 | 1 | 12 | 2 | Yes | 1 |
| 12 | 2 | 1 | 1 | No | 1 |
| 22 | 1 | 22 | 2 | Yes | 2 |
| 22 | 2 | 2 | 2 | Yes | 3 |

# Complexity
- Time complexity: $$O(N \cdot \log_{10}(M))$$, where $$N$$ is the number of elements in `nums` and $$M$$ is the maximum value in `nums`. Each number has at most $$\log_{10}(M)$$ digits.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(int num : nums){
            int temp = num ;
            while(temp){
                int dig = temp%10;
                if(dig == digit) ans++;
                temp/=10;
                
            }
        }
        return ans;
    }
};
```

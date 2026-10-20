# [3300. Minimum Element After Replacement With Digit Sum](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given an integer array `nums`.

You replace each element in `nums` with the **sum** of its digits.

Return the **minimum** element in `nums` after all replacements.

**Example 1:**

**Input:** nums = [10,12,13,14]

**Output:** 1

**Explanation:**

`nums` becomes `[1, 3, 4, 5]` after all replacements, with minimum element 1.

**Example 2:**

**Input:** nums = [1,2,3,4]

**Output:** 1

**Explanation:**

`nums` becomes `[1, 2, 3, 4]` after all replacements, with minimum element 1.

**Example 3:**

**Input:** nums = [999,19,199]

**Output:** 10

**Explanation:**

`nums` becomes `[27, 10, 19]` after all replacements, with minimum element 10.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 104`

---

## Solution & Editorial
# Intuition
To solve this problem, we need to transform each integer in the input array into the sum of its digits and then identify the smallest value among these transformed results. Since the constraints on the input values are small (up to 10^4), a direct simulation of the digit summation process for each element is highly efficient.

# Approach
1. Initialize a variable `ans` to `INT_MAX` to keep track of the global minimum found so far.
2. Iterate through each integer `num` in the input vector `nums`.
3. For each `num`, calculate the sum of its digits using a `while` loop: extract the last digit using the modulo operator (`temp % 10`), add it to a running `sum`, and remove the last digit using integer division (`temp /= 10`).
4. After computing the `sum` for the current `num`, update `ans` if `sum` is smaller than the current `ans`.
5. Return `ans` after processing all elements.

### Visual Trace (Example 1: [10, 12, 13, 14])
| Input (num) | Digit Summation | Resulting Sum | Current Min (ans) |
| :--- | :--- | :--- | :--- |
| 10 | 1 + 0 | 1 | 1 |
| 12 | 1 + 2 | 3 | 1 |
| 13 | 1 + 3 | 4 | 1 |
| 14 | 1 + 4 | 5 | 1 |

# Complexity
- Time complexity: $$O(N \cdot \log_{10} M)$$, where $$N$$ is the number of elements in `nums` and $$M$$ is the maximum value in `nums`. Each number requires a number of operations proportional to its number of digits, which is logarithmic relative to the value of the number.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int num : nums){
            int temp = num;
            int sum = 0;
            while(temp){
                int digit = temp%10;
                sum+= digit;
                temp/=10;
            }
            if(sum < ans) ans = sum;
        }
        return ans;

    }
};
```

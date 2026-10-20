# [3190. Find Minimum Operations to Make All Elements Divisible by Three](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given an integer array `nums`. In one operation, you can add or subtract 1 from **any** element of `nums`.

Return the **minimum** number of operations to make all elements of `nums` divisible by 3.

**Example 1:**

**Input:** nums = [1,2,3,4]

**Output:** 3

**Explanation:**

All array elements can be made divisible by 3 using 3 operations:

* Subtract 1 from 1.
* Add 1 to 2.
* Subtract 1 from 4.

**Example 2:**

**Input:** nums = [3,6,9]

**Output:** 0

**Constraints:**

* `1 <= nums.length <= 50`
* `1 <= nums[i] <= 50`

---

## Solution & Editorial
# Intuition
To make any integer $x$ divisible by 3, we only need to consider its remainder when divided by 3. If $x \equiv 0 \pmod 3$, it is already divisible. If $x \equiv 1 \pmod 3$, we can subtract 1 to reach a multiple of 3. If $x \equiv 2 \pmod 3$, we can add 1 to reach the next multiple of 3. In both non-zero cases, exactly one operation is required.

# Approach
1. Initialize a counter `ans` to 0.
2. Iterate through each element `i` in the input vector `nums`.
3. Calculate the remainder of `i` divided by 3 using the modulo operator (`i % 3`).
4. If the remainder is 1 or 2, increment `ans` by 1, as one operation (either subtraction or addition) will make the number divisible by 3.
5. Return `ans` after processing all elements.

### Visual Trace (Example 1: nums = [1, 2, 3, 4])
| Element (i) | i % 3 | Operation Needed | ans (Running Total) |
| :--- | :--- | :--- | :--- |
| 1 | 1 | 1 | 1 |
| 2 | 2 | 1 | 2 |
| 3 | 0 | 0 | 2 |
| 4 | 1 | 1 | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a single integer variable `ans` regardless of input size.

# Code
```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i :nums){
            if((i%3==1)||(i%3==2)){
                ans++;
            }
        }
        return ans;    
    }
};
```

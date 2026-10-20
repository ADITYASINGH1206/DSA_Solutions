# [3550. Smallest Index With Digit Sum Equal to Index](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given an integer array `nums`.

Return the **smallest** index `i` such that the sum of the digits of `nums[i]` is equal to `i`.

If no such index exists, return `-1`.

**Example 1:**

**Input:** nums = [1,3,2]

**Output:** 2

**Explanation:**

* For `nums[2] = 2`, the sum of digits is 2, which is equal to index `i = 2`. Thus, the output is 2.

**Example 2:**

**Input:** nums = [1,10,11]

**Output:** 1

**Explanation:**

* For `nums[1] = 10`, the sum of digits is `1 + 0 = 1`, which is equal to index `i = 1`.
* For `nums[2] = 11`, the sum of digits is `1 + 1 = 2`, which is equal to index `i = 2`.
* Since index 1 is the smallest, the output is 1.

**Example 3:**

**Input:** nums = [1,2,3]

**Output:** -1

**Explanation:**

* Since no index satisfies the condition, the output is -1.

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks for the smallest index `i` where the sum of the digits of `nums[i]` equals `i`. Since we need the *smallest* index, a simple linear scan from left to right is optimal. As soon as we encounter an index satisfying the condition, we can return it immediately.

# Approach
1. Iterate through the array `nums` using an index `i` from `0` to `n-1`.
2. For each element `nums[i]`, calculate the sum of its digits by repeatedly extracting the last digit using the modulo operator (`% 10`) and reducing the number using integer division (`/ 10`).
3. Compare the calculated `sum` with the current index `i`.
4. If `sum == i`, return `i` immediately.
5. If the loop completes without finding a match, return `-1`.

### Visual Trace (Example 2: nums = [1, 10, 11])
| Index (i) | Value (nums[i]) | Digit Sum | Match (Sum == i)? |
| :--- | :--- | :--- | :--- |
| 0 | 1 | 1 | No (1 != 0) |
| 1 | 10 | 1+0 = 1 | Yes (1 == 1) -> Return 1 |

# Complexity
- Time complexity: $$O(N \cdot D)$$, where $$N$$ is the length of the array and $$D$$ is the number of digits in the largest element (at most 4 digits for 1000). Since $$D$$ is constant, this is effectively $$O(N)$$.
- Space complexity: $$O(1)$$, as we only use a few integer variables for calculation regardless of the input size.

# Code
```cpp
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int temp = nums[i];
            int sum = 0;
            while(temp){
                int digit = temp%10;
                sum += digit;
                temp/=10;
            }
            if(sum == i) return i;
        }
        return -1;
    }
};
```

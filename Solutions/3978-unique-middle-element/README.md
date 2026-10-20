# [3978. Unique Middle Element](https://leetcode.com/problems/unique-middle-element/)
**Difficulty:** `Easy` | **Tags:** `array`, `counting`

---

## Problem Description
You are given an integer array `nums` of odd length `n`.

Return `true` if the middle element of `nums` appears **exactly** once in the array. Otherwise return `false`.

**Example 1:**

**Input:** nums = [1,2,3]

**Output:** true

**Explanation:**

The middle element of `nums` is 2, which appears exactly once.

Thus, the answer is `true`.

**Example 2:**

**Input:** nums = [1,2,2]

**Output:** false

**Explanation:**

The middle element of `nums` is 2, which appears twice.

Thus, the answer is `false`.

**Constraints:**

* `1 <= n == nums.length <= 100`
* `n` is odd.
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To determine if the middle element is unique, we identify the middle index using integer division and count its occurrences across the entire array. Since the array length is small (up to 100), a simple linear scan is optimal.

# Approach
1. Calculate the middle index `mid` as `n / 2`.
2. Store the value at `nums[mid]` in a variable `target`.
3. Iterate through the array `nums`, incrementing a `count` variable whenever an element matches `target`.
4. If `count` exceeds 1 at any point, terminate early and return `false`.
5. After the loop, return `true` if `count` is exactly 1.

### Visual Trace (Example 1: nums = [1, 2, 3])
| Step | Variable | Value |
| :--- | :--- | :--- |
| 1 | n | 3 |
| 2 | mid | 1 |
| 3 | target | nums[1] = 2 |
| 4 | Iteration 1 | num=1, count=0 |
| 5 | Iteration 2 | num=2, count=1 |
| 6 | Iteration 3 | num=3, count=1 |
| 7 | Result | count == 1 (True) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for variables `n`, `mid`, `target`, and `count`.

# Code
```cpp
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;         
        int target = nums[mid];   
        int count = 0;
        
        for (int num : nums) {
            if (num == target) {
                count++;
            }
            if (count > 1) {
                return false; 
            }
        }
        
        return count == 1;
    }
};
```

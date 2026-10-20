# [3736. Minimum Moves to Equal Array Elements III](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given an integer array `nums`.

In one move, you may **increase** the value of any single element `nums[i]` by 1.

Return the **minimum total** number of **moves** required so that all elements in `nums` become **equal**.

**Example 1:**

**Input:** nums = [2,1,3]

**Output:** 3

**Explanation:**

To make all elements equal:

* Increase `nums[0] = 2` by 1 to make it 3.
* Increase `nums[1] = 1` by 1 to make it 2.
* Increase `nums[1] = 2` by 1 to make it 3.

Now, all elements of `nums` are equal to 3. The minimum total moves is `3`.

**Example 2:**

**Input:** nums = [4,4,5]

**Output:** 2

**Explanation:**

To make all elements equal:

* Increase `nums[0] = 4` by 1 to make it 5.
* Increase `nums[1] = 4` by 1 to make it 5.

Now, all elements of `nums` are equal to 5. The minimum total moves is `2`.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To make all elements in an array equal by only increasing values, every element must eventually reach the value of the current maximum element in the array. Any target value smaller than the maximum would be impossible to reach using only increments, and any target value larger than the maximum would require unnecessary additional moves for all elements.

# Approach
1. Identify the maximum element in the array, `maxi`, which serves as the target value for all other elements.
2. Iterate through each element `num` in the array `nums`.
3. Calculate the difference `maxi - num` for each element and accumulate these differences into a variable `ans`.
4. Return the total sum `ans`.

### Visual Trace (Example 1: nums = [2, 1, 3])
| Step | Element | Target (maxi) | Diff (maxi - num) | Running Sum (ans) |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 2 | 3 | 1 | 1 |
| 2 | 1 | 3 | 2 | 3 |
| 3 | 3 | 3 | 0 | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in `nums`. We perform one pass to find the maximum and one pass to calculate the sum of differences.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int ans = 0;
        for(int num:nums){
            ans += abs(num-maxi);
        }
        return ans;

    }
};
```

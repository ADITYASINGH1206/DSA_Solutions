# [2733. Neither Minimum nor Maximum](https://leetcode.com/problems/neither-minimum-nor-maximum/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
Given an integer array `nums` containing **distinct** **positive** integers, find and return **any** number from the array that is neither the **minimum** nor the **maximum** value in the array, or **`-1`** if there is no such number.

Return *the selected integer.*

**Example 1:**

```
Input: nums = [3,2,1,4]
Output: 2
Explanation: In this example, the minimum value is 1 and the maximum value is 4. Therefore, either 2 or 3 can be valid answers.
```

**Example 2:**

```
Input: nums = [1,2]
Output: -1
Explanation: Since there is no number in nums that is neither the maximum nor the minimum, we cannot select a number that satisfies the given condition. Therefore, there is no answer.
```

**Example 3:**

```
Input: nums = [2,1,3]
Output: 2
Explanation: Since 2 is neither the maximum nor the minimum value in nums, it is the only valid answer.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* All values in `nums` are distinct

---

## Solution & Editorial
# Intuition
Since the array contains distinct positive integers, any array with fewer than 3 elements cannot contain a value that is neither the minimum nor the maximum. For arrays with 3 or more elements, sorting the array allows us to easily identify the elements between the minimum (at index 0) and the maximum (at index n-1).

# Approach
1. Check the size of the input vector `nums`. If the size `n` is less than or equal to 2, return -1 immediately as no such element exists.
2. Sort the vector `nums` in ascending order using `std::sort`.
3. Once sorted, the minimum value is at `nums[0]` and the maximum value is at `nums[n-1]`. Any element at an index `i` where `0 < i < n-1` satisfies the condition.
4. Simply return `nums[1]` as it is guaranteed to be neither the minimum nor the maximum for any `n > 2`.

### Visual Trace (Example 1: [3, 2, 1, 4])
| Step | Action | State | Result |
| :--- | :--- | :--- | :--- |
| 1 | Initial | [3, 2, 1, 4] | - |
| 2 | Sort | [1, 2, 3, 4] | - |
| 3 | Check n > 2 | n=4 | True |
| 4 | Return nums[1] | - | 2 |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting operation, where $$N$$ is the length of the array.
- Space complexity: $$O(1)$$ or $$O(\log N)$$ depending on the implementation of `std::sort` (stack space for recursion), as we perform the sort in-place.

# Code
```cpp
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n>2){
            ans = nums[1];
        }
        return ans;
    }
};
```

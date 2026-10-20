# [747. Largest Number At Least Twice of Others](https://leetcode.com/problems/largest-number-at-least-twice-of-others/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
You are given an integer array `nums` where the largest integer is **unique**.

Determine whether the largest element in the array is **at least twice** as much as every other number in the array. If it is, return *the **index** of the largest element, or return* `-1` *otherwise*.

**Example 1:**

```
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.
```

**Constraints:**

* `2 <= nums.length <= 50`
* `0 <= nums[i] <= 100`
* The largest element in `nums` is unique.

---

## Solution & Editorial
# Intuition
To determine if the largest element in the array is at least twice as large as every other number, we only need to track the two largest distinct values in the array: the absolute maximum (`first`) and the second-largest maximum (`second`). If the maximum element is greater than or equal to twice the second-largest element, it is guaranteed to be at least twice as large as all other elements.

# Approach
1. Initialize `first = 0`, `second = 0`, and `ans = 0` to track the largest value, second-largest value, and the index of the largest value.
2. Iterate through each element `nums[i]` from index `0` to `n - 1`:
   - If `nums[i] > first`, update `second = first`, then update `first = nums[i]` and record `ans = i`.
   - Otherwise, if `nums[i] > second`, update `second = nums[i]`.
3. After the loop, check the condition `first >= 2 * second`. If true, return `ans`; otherwise, return `-1`.

### Visual Walkthrough for Example 1: `nums = [3, 6, 1, 0]`

| Index `i` | `nums[i]` | Condition Checked | `first` | `second` | `ans` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 3 | `3 > 0` (True) | 3 | 0 | 0 |
| 1 | 6 | `6 > 3` (True) | 6 | 3 | 1 |
| 2 | 1 | `1 > 6` (False), `1 > 3` (False) | 6 | 3 | 1 |
| 3 | 0 | `0 > 6` (False), `0 > 3` (False) | 6 | 3 | 1 |

Final check: `first (6) >= 2 * second (3)` evaluates to `6 >= 6`, which is `true`. Returns index `1`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in `nums`. We iterate through the array of size $$N$$ exactly once.
- Space complexity: $$O(1)$$ auxiliary space, as only a few scalar variables (`first`, `second`, `ans`) are maintained.

# Code
```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first =0 , second = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>first){
                second = first;
                first=nums[i];
                ans=i;
            }else if(nums[i]>second){
                second = nums[i];
            }
        }
        if(first>=2*second){
            return ans;
        }
        return -1;
    }
};
```

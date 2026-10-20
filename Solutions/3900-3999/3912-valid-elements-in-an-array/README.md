# [3912. Valid Elements in an Array](https://leetcode.com/problems/valid-elements-in-an-array/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
You are given an integer array `nums`.

An element `nums[i]` is considered **valid** if it satisfies **at least** one of the following conditions:

* It is **strictly greater** than every element to its left.
* It is **strictly greater** than every element to its right.

The first and last elements are always valid.

Return an array of all valid elements in the same order as they appear in `nums`.

**Example 1:**

**Input:** nums = [1,2,4,2,3,2]

**Output:** [1,2,4,3,2]

**Explanation:**

* `nums[0]` and `nums[5]` are always valid.
* `nums[1]` and `nums[2]` are strictly greater than every element to their left.
* `nums[4]` is strictly greater than every element to its right.
* Thus, the answer is `[1, 2, 4, 3, 2]`.

**Example 2:**

**Input:** nums = [5,5,5,5]

**Output:** [5,5]

**Explanation:**

* The first and last elements are always valid.
* No other elements are strictly greater than all elements to their left or to their right.
* Thus, the answer is `[5, 5]`.

**Example 3:**

**Input:** nums = [1]

**Output:** [1]

**Explanation:**

Since there is only one element, it is always valid. Thus, the answer is `[1]`.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
An element is valid if it is a prefix maximum or a suffix maximum. By maintaining running maximums from both ends of the array, we can identify all such elements in a single linear pass.

# Approach
1. Initialize a boolean array `valid` of size `n` to track which indices satisfy the conditions. Mark the first and last elements as `true`.
2. Use two variables, `max_left` and `max_right`, initialized to the first and last elements respectively.
3. Iterate from index `1` to `n-2`. In each iteration:
   - Check if `nums[i]` is strictly greater than `max_left`. If so, mark `valid[i]` as `true` and update `max_left`.
   - Simultaneously, check the symmetric index `j = n - 1 - i`. If `nums[j]` is strictly greater than `max_right`, mark `valid[j]` as `true` and update `max_right`.
4. Collect all elements where `valid[i]` is `true` into a result vector.

### Visual Trace (nums = [1, 2, 4, 2, 3, 2])
| i | nums[i] | max_left | valid[i] | j | nums[j] | max_right | valid[j] |
|---|---|---|---|---|---|---|---|
| 1 | 2 | 1 | T | 4 | 3 | 2 | T |
| 2 | 4 | 2 | T | 3 | 2 | 3 | F |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the array. We perform a single pass to identify valid indices and a second pass to collect them.
- Space complexity: $$O(N)$$ to store the boolean `valid` array.

# Code
```cpp
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return nums;
        
        vector<bool> valid(n, false);
        valid[0] = true;
        valid[n - 1] = true;
        
        int max_left = nums[0];
        int max_right = nums[n - 1];
        
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > max_left) valid[i] = true;
            max_left = max(max_left, nums[i]);
            
            int j = n - 1 - i; 
            if (nums[j] > max_right) valid[j] = true;
            max_right = max(max_right, nums[j]);
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (valid[i]) {
                result.push_back(nums[i]);
            }
        }
        
        return result;
    }
};
```

# [896. Monotonic Array](https://leetcode.com/problems/monotonic-array/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
An array is **monotonic** if it is either monotone increasing or monotone decreasing.

An array `nums` is monotone increasing if for all `i <= j`, `nums[i] <= nums[j]`. An array `nums` is monotone decreasing if for all `i <= j`, `nums[i] >= nums[j]`.

Given an integer array `nums`, return `true` *if the given array is monotonic, or* `false` *otherwise*.

**Example 1:**

```
Input: nums = [1,2,2,3]
Output: true
```

**Example 2:**

```
Input: nums = [6,5,4,4]
Output: true
```

**Example 3:**

```
Input: nums = [1,3,2]
Output: false
```

**Constraints:**

* `1 <= nums.length <= 105`
* `-105 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
An array is monotonic if it never decreases or never increases from left to right. We can traverse the array in a single pass while maintaining a state variable (`change`) that records whether we have observed an increasing trend, a decreasing trend, or no conclusive trend yet.

# Approach
1. Initialize an integer variable `change` to `0`, representing an undetermined monotonic direction.
2. Iterate through the vector `nums` from index `1` to `nums.size() - 1` using a loop variable `i`.
3. Compare `nums[i]` with `nums[i-1]`:
   - If `nums[i] > nums[i-1]`, we detect an upward step. If `change` was previously `-1` (meaning we already saw a downward trend), return `false`. Otherwise, set `change = 1`.
   - If `nums[i] < nums[i-1]`, we detect a downward step. If `change` was previously `1` (meaning we already saw an upward trend), return `false`. Otherwise, set `change = -1`.
4. If the loop completes without violating monotonicity, return `true`.

### Visual Trace Walkthrough (Example 1: `nums = [1, 2, 2, 3]`)
| Index `i` | `nums[i-1]` | `nums[i]` | Condition | `change` (Before) | `change` (After) | Action |
| :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| 1 | 1 | 2 | `2 > 1` | `0` | `1` | Set `change = 1` |
| 2 | 2 | 2 | Equal | `1` | `1` | No change |
| 3 | 2 | 3 | `3 > 2` | `1` | `1` | Match existing trend |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in `nums`. We traverse the array at most once.
- Space complexity: $$O(1)$$, as we only use a single scalar variable `change` for state tracking.

# Code
```cpp
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int change = 0; 
        
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) { 
                if (change == -1) return false;
                change = 1;
            } 
            else if (nums[i] < nums[i-1]) {
                if (change == 1) return false;
                change = -1;
            }
        }
        
        return true;
    }
};
```

# [3818. Minimum Prefix Removal to Make Array Strictly Increasing](https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/)
**Difficulty:** `Medium` | **Tags:** `array`

---

## Problem Description
You are given an integer array `nums`.

You need to remove **exactly** one prefix (possibly empty) from nums.

Return an integer denoting the **minimum** length of the removed prefix such that the remaining array is **strictly increasing**.

**Example 1:**

**Input:** nums = [1,-1,2,3,3,4,5]

**Output:** 4

**Explanation:**

Removing the `prefix = [1, -1, 2, 3]` leaves the remaining array `[3, 4, 5]` which is strictly increasing.

**Example 2:**

**Input:** nums = [4,3,-2,-5]

**Output:** 3

**Explanation:**

Removing the `prefix = [4, 3, -2]` leaves the remaining array `[-5]` which is strictly increasing.

**Example 3:**

**Input:** nums = [1,2,3,4]

**Output:** 0

**Explanation:**

The array `nums = [1, 2, 3, 4]` is already strictly increasing so removing an empty prefix is sufficient.

**Constraints:**

* `1 <= nums.length <= 105`
* `-109 <= nums[i] <= 109​​​​​​​`

---

## Solution & Editorial
# Intuition
To make the remaining suffix of an array strictly increasing, we must identify the longest possible suffix that already satisfies the strictly increasing property. Any prefix ending before this suffix can be removed. The problem asks for the *minimum* length of the removed prefix, which is equivalent to finding the *maximum* length of the remaining strictly increasing suffix.

# Approach
1. Start from the end of the array `nums` and iterate backwards towards the beginning.
2. Maintain a pointer or index `i` moving from `n-1` down to `1`.
3. At each step, compare `nums[i]` with `nums[i-1]`. If `nums[i] <= nums[i-1]`, the strictly increasing property is violated at index `i`. This means the longest strictly increasing suffix starts at index `i`.
4. Therefore, the minimum prefix to remove must include all elements up to index `i-1`, which corresponds to a length of `i`.
5. If the loop completes without finding such a violation, the entire array is already strictly increasing, so we return `0`.

### Visual Trace (Example 1: [1, -1, 2, 3, 3, 4, 5])
| Index `i` | `nums[i]` | `nums[i-1]` | Condition `nums[i] <= nums[i-1]` | Action |
|-----------|-----------|-------------|--------------------------------|--------|
| 6 | 5 | 4 | False | Continue |
| 5 | 4 | 3 | False | Continue |
| 4 | 3 | 3 | True | Return `i` (4) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass from the end of the array to the point where the increasing property breaks.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for indices.

# Code
```cpp
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n =nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]<=nums[i-1]){
                return i;
            }
        }
        return 0;
    }
};
```

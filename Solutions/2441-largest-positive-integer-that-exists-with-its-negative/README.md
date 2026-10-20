# [2441. Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `two-pointers`, `sorting`

---

## Problem Description
Given an integer array `nums` that **does not contain** any zeros, find **the largest positive** integer `k` such that `-k` also exists in the array.

Return *the positive integer* `k`. If there is no such integer, return `-1`.

**Example 1:**

```
Input: nums = [-1,2,-3,3]
Output: 3
Explanation: 3 is the only valid k we can find in the array.
```

**Example 2:**

```
Input: nums = [-1,10,6,7,-7,1]
Output: 7
Explanation: Both 1 and 7 have their corresponding negative values in the array. 7 has a larger value.
```

**Example 3:**

```
Input: nums = [-10,8,6,7,-2,-3]
Output: -1
Explanation: There is no a single valid k, we return -1.
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `-1000 <= nums[i] <= 1000`
* `nums[i] != 0`

---

## Solution & Editorial
# Intuition
To find the largest positive integer $k$ such that $-k$ also exists in the array, we need an efficient way to check for the existence of the negation of each positive number. A hash set provides $O(1)$ average time complexity for lookups, making it ideal for this task.

# Approach
1. Initialize an `unordered_set<int>` named `st` with all elements from the input vector `nums`. This allows for constant-time existence checks.
2. Initialize a variable `ans` to `-1` to store the maximum $k$ found so far.
3. Iterate through each `num` in `nums`:
   - If `num` is positive and the set `st` contains `-num`, it means both $k$ and $-k$ exist.
   - Update `ans` with the maximum of its current value and `num`.
4. Return `ans` after the loop completes.

### Visual Trace (Example 1: nums = [-1, 2, -3, 3])
| Iteration | num | num > 0? | st contains -num? | ans |
|-----------|-----|----------|-------------------|-----|
| 1         | -1  | No       | -                 | -1  |
| 2         | 2   | Yes      | No                | -1  |
| 3         | -3  | No       | -                 | -1  |
| 4         | 3   | Yes      | Yes (-3 exists)   | 3   |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the array. We perform one pass to build the set and one pass to check for existence, both of which are linear.
- Space complexity: $$O(N)$$ to store the elements in the `unordered_set`.

# Code
```cpp
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = -1;
        for (int num : nums) {
            if (num > 0 && st.count(-num))
                ans = max(ans, num);
        }

        return ans;
    }
};
```

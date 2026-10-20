# [2367. Number of Arithmetic Triplets](https://leetcode.com/problems/number-of-arithmetic-triplets/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `two-pointers`, `enumeration`

---

## Problem Description
You are given a **0-indexed**, **strictly increasing** integer array `nums` and a positive integer `diff`. A triplet `(i, j, k)` is an **arithmetic triplet** if the following conditions are met:

* `i < j < k`,
* `nums[j] - nums[i] == diff`, and
* `nums[k] - nums[j] == diff`.

Return *the number of unique **arithmetic triplets**.*

**Example 1:**

```
Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3.
```

**Example 2:**

```
Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.
```

**Constraints:**

* `3 <= nums.length <= 200`
* `0 <= nums[i] <= 200`
* `1 <= diff <= 50`
* `nums` is **strictly** increasing.

---

## Solution & Editorial
# Intuition
Since the constraints on the input array length are small ($N \le 200$), we can directly verify every possible triplet $(i, j, k)$ to check if it satisfies the arithmetic progression conditions defined by the constant `diff`.

# Approach
1. Initialize a counter `ans` to 0.
2. Use three nested loops to iterate through all possible indices $(i, j, k)$ such that $0 \le i < j < k < n$.
3. For each combination, check if `nums[j] - nums[i] == diff` and `nums[k] - nums[j] == diff`.
4. If both conditions are met, increment `ans`.

### Visual Trace (Example 1: nums = [0, 1, 4, 6, 7, 10], diff = 3)
| i | j | k | nums[i] | nums[j] | nums[k] | Condition (diff=3) | Match |
|---|---|---|---|---|---|---|---|
| 0 | 1 | 2 | 0 | 1 | 4 | 1-0=1, 4-1=3 | No |
| 1 | 2 | 4 | 1 | 4 | 7 | 4-1=3, 7-4=3 | Yes (ans=1) |
| 2 | 4 | 5 | 4 | 7 | 10 | 7-4=3, 10-7=3 | Yes (ans=2) |

# Complexity
- Time complexity: $$O(N^3)$$, where $$N$$ is the length of the array. We iterate through all triplets using three nested loops.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for the counter and loop indices.

# Code
```cpp
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
```

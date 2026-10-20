# [2006. Count Number of Pairs With Absolute Difference K](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
Given an integer array `nums` and an integer `k`, return *the number of pairs* `(i, j)` *where* `i < j` *such that* `|nums[i] - nums[j]| == k`.

The value of `|x|` is defined as:

* `x` if `x >= 0`.
* `-x` if `x < 0`.

**Example 1:**

```
Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
```

**Example 2:**

```
Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
```

**Example 3:**

```
Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
```

**Constraints:**

* `1 <= nums.length <= 200`
* `1 <= nums[i] <= 100`
* `1 <= k <= 99`

---

## Solution & Editorial
# Intuition
Since the constraints on the array length are small ($N \le 200$), a direct comparison of all possible pairs is highly efficient and guarantees correctness. We simply need to iterate through every pair $(i, j)$ where $i < j$ and check if the absolute difference matches $k$.

# Approach
1. Initialize a counter `ans` to 0.
2. Use a nested loop structure: the outer loop iterates index `i` from $0$ to $n-1$, and the inner loop iterates index `j` from $i+1$ to $n-1$.
3. For each pair, calculate `abs(nums[i] - nums[j])`. If the result equals `k`, increment `ans`.
4. Return `ans` after all pairs have been checked.

### Visual Trace (Example 1: nums = [1, 2, 2, 1], k = 1)
| i | j | nums[i] | nums[j] | abs diff | Match? | ans |
|---|---|---|---|---|---|---|
| 0 | 1 | 1 | 2 | 1 | Yes | 1 |
| 0 | 2 | 1 | 2 | 1 | Yes | 2 |
| 0 | 3 | 1 | 1 | 0 | No | 2 |
| 1 | 2 | 2 | 2 | 0 | No | 2 |
| 1 | 3 | 2 | 1 | 1 | Yes | 3 |
| 2 | 3 | 2 | 1 | 1 | Yes | 4 |

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the length of the input array. We perform a nested iteration over the array, resulting in $\frac{N(N-1)}{2}$ comparisons.
- Space complexity: $$O(1)$$ as we only use a constant amount of extra space for the counter and loop indices.

# Code
```cpp
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(nums[i] - nums[j])==k) ans++;
            }
        }
        return ans;
    }
};
```

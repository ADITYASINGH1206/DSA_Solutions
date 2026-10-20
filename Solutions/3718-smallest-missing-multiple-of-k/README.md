# [3718. Smallest Missing Multiple of K](https://leetcode.com/problems/smallest-missing-multiple-of-k/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
Given an integer array `nums` and an integer `k`, return the **smallest positive multiple** of `k` that is **missing** from `nums`.

A **multiple** of `k` is any positive integer divisible by `k`.

**Example 1:**

**Input:** nums = [8,2,3,4,6], k = 2

**Output:** 10

**Explanation:**

The multiples of `k = 2` are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from `nums` is 10.

**Example 2:**

**Input:** nums = [1,4,7,10,15], k = 5

**Output:** 5

**Explanation:**

The multiples of `k = 5` are 5, 10, 15, 20... and the smallest multiple missing from `nums` is 5.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* `1 <= k <= 100`

---

## Solution & Editorial
# Intuition
To find the smallest missing multiple of $k$, we observe that the multiples of $k$ are $1k, 2k, 3k, \dots$. We can map these to indices $0, 1, 2, \dots$ by dividing each multiple by $k$ and subtracting 1. Since the constraints are small ($N, k \le 100$), we can represent the presence of these multiples using a bitmask.

# Approach
1. Initialize a bitmask array `x` of size 2 to track the presence of the first 128 multiples of $k$. 
2. Iterate through `nums`. If a number `n` is divisible by $k$, calculate its index `i = n / k - 1`. If `i` is within our bitmask range, set the corresponding bit using `x[i >> 6] |= 1ULL << (i & 63)`.
3. Identify the first missing multiple by checking which 64-bit block is not full. If `x[0]` is all ones (`-1ULL`), the missing multiple is in the second block.
4. Use `bit_width` on the lowest set bit of the inverted mask to find the first zero bit, then convert this back to the original multiple value.

### Visual Trace (nums = [8, 2, 3, 4, 6], k = 2)
- Multiples of 2: 2, 4, 6, 8, 10, ...
- Indices (n/k - 1): 0, 1, 2, 3, 4, ...
- `nums` contains: 2 (idx 0), 4 (idx 1), 6 (idx 2), 8 (idx 3).
- Bitmask `x[0]` bits 0, 1, 2, 3 are set.
- The first unset bit is index 4.
- Result: (4 + 1) * 2 = 10.

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of `nums`. We perform a single pass over the array and constant-time bitwise operations.
- Space complexity: $$O(1)$$, as we use a fixed-size array of two 64-bit integers regardless of input size.

# Code
```cpp
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        uint64_t x[2] = {0, 0};
        for (auto& n : nums)
            if (n % k == 0) {
                int i = n / k - 1;
                x[i >> 6] |= 1ULL << (i & 63);
            }

        int z = x[0] == -1ULL;
        return (z * 64 + bit_width(++x[z] & -x[z])) * k;
    }
};
```

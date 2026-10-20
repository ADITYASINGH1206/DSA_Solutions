# [2274. Maximum Consecutive Floors Without Special Floors](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/)
**Difficulty:** `Medium` | **Tags:** `array`, `sorting`

---

## Problem Description
Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be **special floors**, used for relaxation only.

You are given two integers `bottom` and `top`, which denote that Alice has rented all the floors from `bottom` to `top` (**inclusive**). You are also given the integer array `special`, where `special[i]` denotes a special floor that Alice has designated for relaxation.

Return *the **maximum** number of consecutive floors without a special floor*.

**Example 1:**

```
Input: bottom = 2, top = 9, special = [4,6]
Output: 3
Explanation: The following are the ranges (inclusive) of consecutive floors without a special floor:
- (2, 3) with a total amount of 2 floors.
- (5, 5) with a total amount of 1 floor.
- (7, 9) with a total amount of 3 floors.
Therefore, we return the maximum number which is 3 floors.
```

**Example 2:**

```
Input: bottom = 6, top = 8, special = [7,6,8]
Output: 0
Explanation: Every floor rented is a special floor, so we return 0.
```

**Constraints:**

* `1 <= special.length <= 105`
* `1 <= bottom <= special[i] <= top <= 109`
* All the values of `special` are **unique**.

---

## Solution & Editorial
# Intuition
To find the maximum number of consecutive floors without a special floor, we must consider the gaps between the special floors, as well as the gaps between the boundaries of our rented range (`bottom` and `top`) and the nearest special floors. By sorting the `special` array, these gaps become easily calculable as the difference between adjacent elements.

# Approach
1. Sort the `special` array in non-decreasing order. This allows us to process the floors linearly.
2. Initialize `res` with the maximum of the gap before the first special floor (`A[0] - bottom`) and the gap after the last special floor (`top - A[n - 1]`).
3. Iterate through the sorted `special` array from index 1 to `n-1`. For each pair of adjacent special floors `A[i]` and `A[i-1]`, the number of consecutive non-special floors between them is `A[i] - A[i-1] - 1`.
4. Update `res` with the maximum value found during the iteration.

### Visual Trace (Example 1: bottom=2, top=9, special=[4,6])
- Sorted `special`: `[4, 6]`
- Initial `res`: `max(4-2, 9-6) = max(2, 3) = 3`
- Iteration `i=1`: `A[1]-A[0]-1 = 6-4-1 = 1`
- `res = max(3, 1) = 3`
- Result: `3`

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of special floors. This is dominated by the sorting step.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we perform the calculation in-place without auxiliary data structures.

# Code
```cpp
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& A) {
        sort(begin(A), end(A));
        int n = A.size(), res = max(A[0] - bottom, top - A[n - 1]);
        for (int i = 1; i < n; ++i)
            res = max(res, A[i] - A[i - 1] - 1);
        return res;
    }
};
```

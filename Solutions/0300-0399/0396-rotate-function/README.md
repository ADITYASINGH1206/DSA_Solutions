# [396. Rotate Function](https://leetcode.com/problems/rotate-function/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `dynamic-programming`

---

## Problem Description
You are given an integer array `nums` of length `n`.

Assume `arrk` to be an array obtained by rotating `nums` by `k` positions clock-wise. We define the **rotation function** `F` on `nums` as follow:

* `F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].`

Return *the maximum value of* `F(0), F(1), ..., F(n-1)`.

The test cases are generated so that the answer fits in a **32-bit** integer.

**Example 1:**

```
Input: nums = [4,3,2,6]
Output: 26
Explanation:
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
```

**Example 2:**

```
Input: nums = [100]
Output: 0
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 105`
* `-100 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
The rotation function $F(k)$ can be efficiently computed from $F(k-1)$ in $O(1)$ time by exploiting the algebraic relationship between consecutive rotations. Instead of recomputing each $F(k)$ from scratch in $O(N^2)$ time, we maintain the sum of all elements in the array and use it to transition between state values in linear time.

# Approach
1. Calculate the sum of all elements in `nums` and store it in variable `s`. Simultaneously, compute the initial rotation function value $F(0)$ and store it in variable `f`.
2. Initialize `ans` to `f` to keep track of the maximum rotation function value encountered.
3. Iterate from $i = 1$ to $n - 1$. For each step, update the rotation value using the recurrence relation: $F(k) = F(k-1) + \text{sum} - n \times \text{nums}[n - k]$. In our code, this translates to `f = f + s - n * nums[n - i]`.
4. Update `ans` with the maximum of its current value and the newly computed `f`.
5. Return `ans` after the loop completes.

### Visual Trace Walkthrough (Example 1: `nums = [4, 3, 2, 6]`, $n = 4$)
- **Initialization ($i$ loop)**:
  - `s` = $4 + 3 + 2 + 6 = 15$
  - `f` = $(0 \times 4) + (1 \times 3) + (2 \times 2) + (3 \times 6) = 0 + 3 + 4 + 18 = 25$
  - `ans` = 25

- **Rotation Loop**:
  - $i = 1$: `f` = $25 + 15 - 4 \times \text{nums}[3] = 40 - 4 \times 6 = 16$. `ans` = $\max(25, 16) = 25$
  - $i = 2$: `f` = $16 + 15 - 4 \times \text{nums}[2] = 31 - 4 \times 2 = 23$. `ans` = $\max(25, 23) = 25$
  - $i = 3$: `f` = $23 + 15 - 4 \times \text{nums}[1] = 38 - 4 \times 3 = 26$. `ans` = $\max(25, 26) = 26$

- **Final Output**: `26`

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the array of size $N$ twice: once to calculate the initial sum and $F(0)$, and once to compute the rotation values for $F(1)$ through $F(N-1)$.
- Space complexity: $$O(1)$$ — Only a few primitive scalar variables (`f`, `s`, `n`, `ans`) are maintained, requiring constant auxiliary memory.

# Code
```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, s = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
            s += nums[i];
        }
        int ans = f;
        for (int i = 1; i < n; ++i) {
            f = f + s - n * nums[n - i];
            ans = max(ans, f);
        }
        return ans;
    }
};
```

# [2897. Apply Operations on Array to Maximize Sum of Squares](https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `greedy`, `bit-manipulation`

---

## Problem Description
You are given a **0-indexed** integer array `nums` and a **positive** integer `k`.

You can do the following operation on the array **any** number of times:

* Choose any two distinct indices `i` and `j` and **simultaneously** update the values of `nums[i]` to `(nums[i] AND nums[j])` and `nums[j]` to `(nums[i] OR nums[j])`. Here, `OR` denotes the bitwise `OR` operation, and `AND` denotes the bitwise `AND` operation.

You have to choose `k` elements from the final array and calculate the sum of their **squares**.

Return *the **maximum** sum of squares you can achieve*.

Since the answer can be very large, return it **modulo** `109 + 7`.

**Example 1:**

```
Input: nums = [2,6,5,8], k = 2
Output: 261
Explanation: We can do the following operations on the array:
- Choose i = 0 and j = 3, then change nums[0] to (2 AND 8) = 0 and nums[3] to (2 OR 8) = 10. The resulting array is nums = [0,6,5,10].
- Choose i = 2 and j = 3, then change nums[2] to (5 AND 10) = 0 and nums[3] to (5 OR 10) = 15. The resulting array is nums = [0,6,0,15].
We can choose the elements 15 and 6 from the final array. The sum of squares is 152 + 62 = 261.
It can be shown that this is the maximum value we can get.
```

**Example 2:**

```
Input: nums = [4,5,4,7], k = 3
Output: 90
Explanation: We do not need to apply any operations.
We can choose the elements 7, 5, and 4 with a sum of squares: 72 + 52 + 42 = 90.
It can be shown that this is the maximum value we can get.
```

**Constraints:**

* `1 <= k <= nums.length <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
The core observation is that the bitwise AND and OR operations preserve the total count of set bits at each bit position across the entire array. Specifically, for any two numbers, the operation shifts bits such that one number accumulates more set bits while the other loses them. To maximize the sum of squares, we want to concentrate as many set bits as possible into the largest numbers, as $x^2 + y^2 < (x+c)^2 + (y-c)^2$ for $x > y$ and $c > 0$.

# Approach
1. **Count Bits**: Since the maximum value is $10^9$ (less than $2^{30}$), we maintain a frequency array `cnt` of size 30 to store how many numbers in the input have the $i$-th bit set.
2. **Reconstruct Numbers**: We create a new array `a` of size $N$. For each bit position $b$ from 29 down to 0, if there are `cnt[b]` numbers with the $b$-th bit set, we distribute these bits to the first `cnt[b]` elements of `a`. This greedily makes the largest numbers as large as possible.
3. **Calculate Sum**: After reconstruction, the first $k$ elements of `a` will contain the largest possible values. We compute the sum of their squares modulo $10^9 + 7$.

### Visual Trace (Example 1: nums = [2, 6, 5, 8], k = 2)
- Binary: 2(0010), 6(0110), 5(0101), 8(1000)
- `cnt` array (bits 0-3): [1, 2, 2, 1]
- Reconstruction:
  - Bit 3 (cnt=1): `a[0] |= 8` -> `a` = [8, 0, 0, 0]
  - Bit 2 (cnt=2): `a[0] |= 4`, `a[1] |= 4` -> `a` = [12, 4, 0, 0]
  - Bit 1 (cnt=2): `a[0] |= 2`, `a[1] |= 2` -> `a` = [14, 6, 0, 0]
  - Bit 0 (cnt=1): `a[0] |= 1` -> `a` = [15, 6, 0, 0]
- Result: $15^2 + 6^2 = 225 + 36 = 261$.

# Complexity
- Time complexity: $$O(N \cdot \log(\max(nums)))$$. We iterate over $N$ elements to count bits, and then iterate over 30 bits for each of the $N$ elements to reconstruct the array.
- Space complexity: $$O(N)$$. We store the reconstructed array of size $N$ and a constant-sized bit count array of size 30.

# Code
```cpp
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> cnt(30, 0);
        for (int x : nums) {
            for (int b = 0; b < 30; ++b) {
                if (x & (1 << b)) cnt[b]++;
            }
        }
        vector<long long> a(n, 0);
        for (int b = 29; b >= 0; --b) {
            int c = cnt[b];
            for (int i = 0; i < c; ++i) {
                a[i] |= (1LL << b);
            }
        }
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            ans = (ans + a[i] * a[i]) % MOD;
        }
        return (int)ans;
    }
};
```

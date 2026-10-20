# [3514. Number of Unique XOR Triplets II](https://leetcode.com/problems/number-of-unique-xor-triplets-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `bit-manipulation`, `enumeration`

---

## Problem Description
You are given an integer array `nums`.

A **XOR triplet** is defined as the XOR of three elements `nums[i] XOR nums[j] XOR nums[k]` where `i <= j <= k`.

Return the number of **unique** XOR triplet values from all possible triplets `(i, j, k)`.

**Example 1:**

**Input:** nums = [1,3]

**Output:** 2

**Explanation:**

The possible XOR triplet values are:

* `(0, 0, 0) → 1 XOR 1 XOR 1 = 1`
* `(0, 0, 1) → 1 XOR 1 XOR 3 = 3`
* `(0, 1, 1) → 1 XOR 3 XOR 3 = 1`
* `(1, 1, 1) → 3 XOR 3 XOR 3 = 3`

The unique XOR values are `{1, 3}`. Thus, the output is 2.

**Example 2:**

**Input:** nums = [6,7,8,9]

**Output:** 4

**Explanation:**

The possible XOR triplet values are `{6, 7, 8, 9}`. Thus, the output is 4.

**Constraints:**

* `1 <= nums.length <= 1500`
* `1 <= nums[i] <= 1500`

---

## Solution & Editorial
# Intuition
To find the number of unique XOR triplets `nums[i] ^ nums[j] ^ nums[k]` where `i <= j <= k`, we observe that the expression can be decomposed into `(nums[i] ^ nums[j]) ^ nums[k]`. Since the constraints on `nums[i]` are small (up to 1500), the XOR sum will not exceed the next power of two, which is 2048. We can precompute all possible XOR pairs and then combine them with every element in the array to find all unique triplet XORs.

# Approach
1. Initialize two boolean arrays, `pair_xor` and `triplet_xor`, of size 2048 to track reachable XOR values.
2. Iterate through all pairs `(i, j)` where `0 <= i <= j < n`. Calculate `nums[i] ^ nums[j]` and mark the corresponding index in `pair_xor` as `true`.
3. Iterate through all indices `x` in `pair_xor` that are `true`. For each `x`, iterate through every element `v` in `nums`. The value `x ^ v` represents a valid triplet XOR. Mark this in `triplet_xor`.
4. Finally, count the number of `true` entries in `triplet_xor`.

### Visual Trace (Example 1: nums = [1, 3])
- **Step 1 (Pairs):**
  - (0,0): 1^1 = 0. `pair_xor[0] = true`
  - (0,1): 1^3 = 2. `pair_xor[2] = true`
  - (1,1): 3^3 = 0. `pair_xor[0] = true`
- **Step 2 (Triplets):**
  - x=0: 0^1=1, 0^3=3. `triplet_xor[1]=true`, `triplet_xor[3]=true`
  - x=2: 2^1=3, 2^3=1. `triplet_xor[3]=true`, `triplet_xor[1]=true`
- **Result:** Count of `true` in `triplet_xor` is 2.

# Complexity
- Time complexity: $$O(N^2 + M \cdot N)$$, where $$N$$ is the length of `nums` and $$M$$ is the maximum possible XOR value (2048). The first nested loop runs in $$O(N^2)$$, and the second nested loop runs in $$O(M \cdot N)$$.
- Space complexity: $$O(M)$$, as we only store boolean flags for the range of possible XOR values.

# Code
```cpp
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int max_xor = 2048;

        vector<bool> pair_xor(max_xor, false);
        vector<bool> triplet_xor(max_xor, false);

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pair_xor[nums[i] ^ nums[j]] = true;
            }
        }

        for (int x = 0; x < max_xor; x++) {
            if (!pair_xor[x]) continue;
            for (int v : nums) {
                triplet_xor[x ^ v] = true;
            }
        }

        int count = 0;
        for(int i = 0; i < max_xor; i++){
            if(triplet_xor[i]) count++;
        }

        return count;
    }
};
```

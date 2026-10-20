# [4010. Maximize Pair Strength Using GCD](https://leetcode.com/problems/maximize-pair-strength-using-gcd/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `enumeration`, `number-theory`

---

## Problem Description
You are given an integer array `nums`.

Choose exactly one pair of distinct indices `i` and `j`. The strength of the pair is defined as `(nums[i] * nums[j]) / gcd(nums[i], nums[j])2`.

Return the maximum strength over all possible pairs.

**Example 1:**

**Input:** nums = [2,3,5]

**Output:** 15

**Explanation:**

Choosing `i = 1` and `j = 2` gives strength `(3 * 5) / gcd(3, 5)2 = 15 / 1 = 15`, which is the maximum over all pairs.

**Example 2:**

**Input:** nums = [4,6,8]

**Output:** 12

**Explanation:**

Choosing `i = 1` and `j = 2` gives strength `(6 * 8) / gcd(6, 8)2 = 48 / 4 = 12`, which is the maximum over all pairs.

**Example 3:**

**Input:** nums = [3,3]

**Output:** 1

**Explanation:**

Choosing `i = 0` and `j = 1` gives strength `(3 * 3) / gcd(3, 3)2 = 9 / 9 = 1`, the maximum over all pairs.

**Constraints:**

* `2 <= nums.length <= 2000`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
The problem asks us to maximize the expression `(nums[i] * nums[j]) / gcd(nums[i], nums[j])^2` for all distinct pairs `(i, j)`. Since the constraints on the array length are relatively small (`N <= 2000`), an exhaustive search over all possible pairs is computationally feasible.

# Approach
1. Initialize a variable `ans` to 0 to store the maximum strength found.
2. Use two nested loops to iterate through all unique pairs `(i, j)` where `0 <= i < n` and `i + 1 <= j < n`.
3. For each pair, calculate the greatest common divisor `g` using `std::gcd`.
4. Compute the strength using 64-bit integer arithmetic (`1LL`) to prevent overflow during the multiplication `nums[i] * nums[j]`.
5. Update `ans` with the maximum value encountered.

### Visual Trace (Example 1: nums = [2, 3, 5])
| i | j | nums[i] | nums[j] | gcd | strength | ans |
|---|---|---|---|---|---|---|
| 0 | 1 | 2 | 3 | 1 | 6/1 = 6 | 6 |
| 0 | 2 | 2 | 5 | 1 | 10/1 = 10 | 10 |
| 1 | 2 | 3 | 5 | 1 | 15/1 = 15 | 15 |

# Complexity
- Time complexity: $$O(N^2 \cdot \log(\min(A, B)))$$, where $$N$$ is the length of the array and $$A, B$$ are the values of the elements. The nested loops run in $$O(N^2)$$ and the GCD computation takes logarithmic time relative to the values.
- Space complexity: $$O(1)$$, as we only use a few variables for tracking the maximum and current indices.

# Code
```cpp
using ll = long long;
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        ll ans =0;
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                ll g = gcd(nums[i], nums[j]);
                ll strength = (1LL * nums[i] * nums[j]) / (g * g);
                ans = max(ans, strength);
            }
        }
        return ans;
    }
};
```

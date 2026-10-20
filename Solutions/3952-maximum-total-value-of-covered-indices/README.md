# [3952. Maximum Total Value of Covered Indices](https://leetcode.com/problems/maximum-total-value-of-covered-indices/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `dynamic-programming`, `greedy`

---

## Problem Description
You are given an integer array `nums` of length `n` and a binary string `s` of length `n`, where `s[i] == '1'` means index `i` initially contains a **token** and `s[i] == '0'` means it does not.

You may perform the following operation any number of times:

* Choose a token currently located at index `i`, where `i > 0`, such that this token has **not** been moved before.
* Move this token from index `i` to index `i - 1`.

An index is considered **covered** if it contains a token after all moves.

Return an integer denoting the **maximum total value** of `nums` at the covered indices after optimally performing the operations.

**Example 1:**

**Input:** nums = [9,2,6,1], s = "0101"

**Output:** 15

**Explanation:**

* Initially, indices 1 and 3 contain tokens.
* Move the token from index 3 to index 2.
* Move the token from index 1 to index 0.
* The covered indices are `[0, 2]`, so the total value is `nums[0] + nums[2] = 9 + 6 = 15`.

**Example 2:**

**Input:** nums = [5,1,4], s = "001"

**Output:** 4

**Explanation:**

* Initially, only index 2 contains a token.
* It is optimal to leave the token at index 2.
* The covered index is `[2]`, so the total value is `nums[2] = 4`.

**Example 3:**

**Input:** nums = [9,3,5], s = "011"

**Output:** 14

**Explanation:**

* Initially, indices 1 and 2 contain tokens.
* Move the token from index 1 to index 0.
* The covered indices are `[0, 2]`, so the total value is `nums[0] + nums[2] = 9 + 5 = 14`.

**Constraints:**

* `1 <= n == nums.length == s.length <= 105`
* `1 <= nums[i] <= 105`
* ​​​​​​​`s[i]` is either `'0'` or `'1'`

---

## Solution & Editorial
# Intuition
The problem allows moving a token at index `i` to `i-1` exactly once. This implies that for a contiguous block of tokens starting at index `start` and ending at `end`, we can effectively "shift" the token coverage to include index `start-1` if `start > 0`. Within any contiguous block of tokens, we can choose to cover any subset of indices of size `k` (where `k` is the number of tokens) within the range `[start-1, end]`, provided we don't violate the constraint that each token moves at most once. Specifically, for a block of tokens, we can cover all indices in `[start, end]` plus potentially `start-1`. To maximize the sum, we simply exclude the minimum value in the range `[start-1, end]` if we choose to shift, or keep all if no shift is possible.

# Approach
1. Iterate through the string `s` to identify contiguous blocks of tokens ('1's).
2. For each block spanning `[start, end]`:
   - If `start == 0`, we cannot move any token to the left. The total value is the sum of `nums[start...end]`.
   - If `start > 0`, we have the option to shift the tokens to cover `[start-1, end]`. Since we have `(end - start + 1)` tokens, we can cover any `(end - start + 1)` indices within the range `[start-1, end]`. To maximize the sum, we take the sum of all elements in `[start-1, end]` and subtract the minimum element in that range.
3. Accumulate these values into `ans`.

### Visual Trace (Example 1: nums=[9,2,6,1], s="0101")
- Block 1: `s[1]` is '1'. `start=1, end=1`. `start > 0`, range `[0, 1]`. `sum=9+2=11`, `min=2`. `ans += 11-2 = 9`.
- Block 2: `s[3]` is '1'. `start=3, end=3`. `start > 0`, range `[2, 3]`. `sum=6+1=7`, `min=1`. `ans += 7-1 = 6`.
- Total `ans = 9 + 6 = 15`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the array. We traverse the array once, and each element is visited a constant number of times.
- Space complexity: $$O(1)$$ as we only use a few variables to track indices and sums.

# Code
```cpp
class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;
        int i = 0;
        
        while (i < n) {
            if (s[i] == '1') {
                int start = i;
                while (i < n && s[i] == '1') {
                    i++;
                }
                int end = i - 1;
                
                if (start > 0) {
                    long long sum = 0;
                    int mini = nums[start - 1]; 
                    for (int j = start - 1; j <= end; j++) {
                        sum += nums[j];
                        mini = min(mini, nums[j]);
                    }
                    ans += (sum - mini);
                } else {
                    for (int j = start; j <= end; j++) {
                        ans += nums[j];
                    }
                }
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
```

# [3151. Special Array I](https://leetcode.com/problems/special-array-i/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
An array is considered **special** if the *parity* of every pair of adjacent elements is different. In other words, one element in each pair **must** be even, and the other **must** be odd.

You are given an array of integers `nums`. Return `true` if `nums` is a **special** array, otherwise, return `false`.

**Example 1:**

**Input:** nums = [1]

**Output:** true

**Explanation:**

There is only one element. So the answer is `true`.

**Example 2:**

**Input:** nums = [2,1,4]

**Output:** true

**Explanation:**

There is only two pairs: `(2,1)` and `(1,4)`, and both of them contain numbers with different parity. So the answer is `true`.

**Example 3:**

**Input:** nums = [4,3,1,6]

**Output:** false

**Explanation:**

`nums[1]` and `nums[2]` are both odd. So the answer is `false`.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To determine if an array is "special," we must ensure that no two adjacent elements share the same parity. Since parity is defined by the remainder when divided by 2, two numbers have the same parity if and only if `nums[i] % 2 == nums[i-1] % 2`.

# Approach
1. Check the base case: if the array length `n` is 1, it is special by definition, so return `true`.
2. Iterate through the array starting from the second element (index `i = 1` to `n-1`).
3. For each pair `(nums[i-1], nums[i])`, compare their parities using the modulo operator.
4. If `nums[i] % 2 == nums[i-1] % 2`, the parity condition is violated; return `false` immediately.
5. If the loop completes without finding any violations, return `true`.

### Visual Trace (Example 3: [4, 3, 1, 6])
| Index (i) | nums[i-1] | nums[i] | Parity (i-1) | Parity (i) | Match? |
|-----------|-----------|---------|--------------|------------|--------|
| 1         | 4         | 3       | 0 (Even)     | 1 (Odd)    | No     |
| 2         | 3         | 1       | 1 (Odd)      | 1 (Odd)    | Yes    |

At `i=2`, the parities match, so the function returns `false`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass through the input.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for loop variables.

# Code
```cpp
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        for(int i =1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2) return false;
        }
        return true;
    }
};
```

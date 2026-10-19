# [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sorting`, `counting`, `boyer-moore-majority-vote-algorithm`

---

## Problem Description
Given an integer array of size `n`, find all elements that appear more than `⌊n / 3⌋` times.

**Example 1:**

```
Input: nums = [3,2,3]
Output: [3]
```

**Example 2:**

```
Input: nums = [1]
Output: [1]
```

**Example 3:**

```
Input: nums = [1,2]
Output: [1,2]
```

**Constraints:**

* `1 <= nums.length <= 5 * 104`
* `-109 <= nums[i] <= 109`

**Follow up:** Could you solve the problem in linear time and in `O(1)` space?

---

## Solution & Editorial
# Intuition
There can be at most two elements in an array of size `n` that appear strictly more than `\lfloor n / 3 \rfloor` times. We can extend the classic Boyer-Moore Majority Vote algorithm to track up to two potential candidates simultaneously using two candidate variables and two counters.

# Approach
1. Initialize two candidates `num1` and `num2` with distinct dummy values, and their respective counts `c1` and `c2` to zero.
2. Iterate through `nums`: if the current element matches `num1`, increment `c1`; else if it matches `num2`, increment `c2`; else if `c1 == 0`, assign `num1 = nums[i]` and `c1 = 1`; else if `c2 == 0`, assign `num2 = nums[i]` and `c2 = 1`; otherwise, decrement both `c1` and `c2`.
3. Perform a second pass over `nums` to count the exact frequencies of `num1` and `num2` to verify if they genuinely exceed the threshold `n / 3`.
4. Collect all verified candidates into the answer vector and return it.

### Visual Walkthrough (Example 1: `nums = [3, 2, 3]`)
| Iteration | Element `nums[i]` | `num1`, `c1` | `num2`, `c2` | Action / Explanation |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 3 | `3`, `1` | `-2`, `0` | `c1` was 0, so `num1` becomes 3, `c1 = 1` |
| 1 | 2 | `3`, `1` | `2`, `1` | `c2` was 0, so `num2` becomes 2, `c2 = 1` |
| 2 | 3 | `3`, `2` | `2`, `1` | Matches `num1`, so `c1` increments to 2 |

Verification pass counts `num1` (3) twice and `num2` (2) once. Since `2 > 3 / 3` (1), `3` is added to result.

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the array of size `N` exactly twice: once for finding potential candidates and once for validation.
- Space complexity: $$O(1)$$ — Only a few primitive variables are used for tracking counts and candidates, requiring constant extra memory.

# Code
```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = -1, num2 = -2; 
        int c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) {
                c1++;
            } else if (nums[i] == num2) {
                c2++;
            } else if (c1 == 0) {
                num1 = nums[i];
                c1 = 1;
            } else if (c2 == 0) {
                num2 = nums[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        int count1 = 0;
        int count2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) count1++;
            else if (nums[i] == num2) count2++;
        }

        vector<int> ans;
        int threshold = n / 3;
        
        if (count1 > threshold) ans.push_back(num1);
        if (count2 > threshold) ans.push_back(num2);
        
        return ans;
    }
};
```

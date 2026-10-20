# [2843.   Count Symmetric Integers](https://leetcode.com/problems/count-symmetric-integers/)
**Difficulty:** `Easy` | **Tags:** `math`, `enumeration`

---

## Problem Description
You are given two positive integers `low` and `high`.

An integer `x` consisting of `2 * n` digits is **symmetric** if the sum of the first `n` digits of `x` is equal to the sum of the last `n` digits of `x`. Numbers with an odd number of digits are never symmetric.

Return *the **number of symmetric** integers in the range* `[low, high]`.

**Example 1:**

```
Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
```

**Example 2:**

```
Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
```

**Constraints:**

* `1 <= low <= high <= 104`

---

## Solution & Editorial
# Intuition
Since the constraints are small (up to 10^4), we can iterate through every integer in the range [low, high]. For each integer, we check if it has an even number of digits and if the sum of the first half equals the sum of the second half.

# Approach
1. Iterate through each integer `i` from `low` to `high`.
2. Convert `i` to a string `str` to easily access its digits and length `n`.
3. If `n` is odd, the number cannot be symmetric, so skip it.
4. If `n` is even, use two pointers `left` (starting at 0) and `right` (starting at `n-1`) to traverse towards the center.
5. Accumulate the digit values into `left_d` and `right_d` respectively.
6. If `left_d == right_d`, increment the counter `ans`.

### Visual Trace (Example: 1230)
- `str` = "1230", `n` = 4
- Iteration 1: `left`=0, `right`=3. `left_d` = 1, `right_d` = 0. `left` becomes 1, `right` becomes 2.
- Iteration 2: `left`=1, `right`=2. `left_d` = 1+2=3, `right_d` = 0+3=3. `left` becomes 2, `right` becomes 1.
- Loop terminates as `left` is no longer < `right`.
- `left_d` (3) == `right_d` (3), so 1230 is symmetric.

# Complexity
- Time complexity: $$O(N \cdot D)$$, where $$N$$ is the number of integers in the range `[low, high]` and $$D$$ is the number of digits (at most 4). Given the constraints, this is effectively constant time.
- Space complexity: $$O(D)$$, where $$D$$ is the number of digits, used to store the string representation of the integer.

# Code
```cpp
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans =0;
        for(int i = low;i<=high;i++){
            string str= to_string(i);
            int n = str.length();
            int left = 0, right = n-1;
            int left_d = 0, right_d = 0;
            if(n%2 ==0){
                while(left<right){
                    left_d += str[left++]-'0';
                    right_d+= str[right--]-'0';
                }
                if(left_d == right_d) ans++;
            }
        }
        return ans;
    }
};
```

# [2160. Minimum Sum of Four Digit Number After Splitting Digits](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/)
**Difficulty:** `Easy` | **Tags:** `math`, `greedy`, `sorting`

---

## Problem Description
You are given a **positive** integer `num` consisting of exactly four digits. Split `num` into two new integers `new1` and `new2` by using the **digits** found in `num`. **Leading zeros** are allowed in `new1` and `new2`, and **all** the digits found in `num` must be used.

* For example, given `num = 2932`, you have the following digits: two `2`'s, one `9` and one `3`. Some of the possible pairs `[new1, new2]` are `[22, 93]`, `[23, 92]`, `[223, 9]` and `[2, 329]`.

Return *the **minimum** possible sum of* `new1` *and* `new2`.

**Example 1:**

```
Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
```

**Example 2:**

```
Input: num = 4009
Output: 13
Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
```

**Constraints:**

* `1000 <= num <= 9999`

---

## Solution & Editorial
# Intuition
To minimize the sum of two numbers formed by splitting four digits, we must place the smallest digits in the tens place and the largest digits in the units place. By sorting the four digits in non-decreasing order, we ensure that the two smallest digits contribute the least to the total sum when multiplied by 10.

# Approach
1. Extract the four digits of the integer `num` using modulo and division operations, storing them in a `vector<int>`.
2. Sort the `digits` vector in non-decreasing order.
3. Assign the two smallest digits (`digits[0]` and `digits[1]`) to the tens place of `new1` and `new2` respectively.
4. Assign the two largest digits (`digits[2]` and `digits[3]`) to the units place of `new1` and `new2` respectively.
5. The minimum sum is calculated as `(digits[0] * 10 + digits[3]) + (digits[1] * 10 + digits[2])`.

### Visual Trace (Example 1: num = 2932)
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Extract digits | {2, 9, 3, 2} |
| 2 | Sort digits | {2, 2, 3, 9} |
| 3 | Form new1 | 2 * 10 + 9 = 29 |
| 4 | Form new2 | 2 * 10 + 3 = 23 |
| 5 | Sum | 29 + 23 = 52 |

# Complexity
- Time complexity: $$O(1)$$. Since the input is always a four-digit number, sorting a fixed-size array of 4 elements takes constant time.
- Space complexity: $$O(1)$$. We use a fixed-size vector of 4 integers to store the digits.

# Code
```cpp
class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        int temp = num;
        while(temp != 0){
            int digit = temp%10;
            temp/=10;
            digits.push_back(digit);
        }
        sort(digits.begin(),digits.end());
        int num1 = digits[0]*10 + digits[3];
        int num2 = digits[1]*10 + digits[2];
        return num1+num2;
    }
};
```

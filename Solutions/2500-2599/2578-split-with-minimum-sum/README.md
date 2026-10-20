# [2578. Split With Minimum Sum](https://leetcode.com/problems/split-with-minimum-sum/)
**Difficulty:** `Easy` | **Tags:** `math`, `greedy`, `sorting`

---

## Problem Description
Given a positive integer `num`, split it into two non-negative integers `num1` and `num2` such that:

* The concatenation of `num1` and `num2` is a permutation of `num`.
  + In other words, the sum of the number of occurrences of each digit in `num1` and `num2` is equal to the number of occurrences of that digit in `num`.
* `num1` and `num2` can contain leading zeros.

Return *the **minimum** possible sum of* `num1` *and* `num2`.

**Notes:**

* It is guaranteed that `num` does not contain any leading zeros.
* The order of occurrence of the digits in `num1` and `num2` may differ from the order of occurrence of `num`.

**Example 1:**

```
Input: num = 4325
Output: 59
Explanation: We can split 4325 so that num1 is 24 and num2 is 35, giving a sum of 59. We can prove that 59 is indeed the minimal possible sum.
```

**Example 2:**

```
Input: num = 687
Output: 75
Explanation: We can split 687 so that num1 is 68 and num2 is 7, which would give an optimal sum of 75.
```

**Constraints:**

* `10 <= num <= 109`

---

## Solution & Editorial
# Intuition
To minimize the sum of two numbers formed by partitioning the digits of a given integer, we must place the smallest available digits in the highest place values (tens, hundreds, etc.). By sorting the digits in non-decreasing order, we can greedily distribute them alternately between `num1` and `num2` to ensure the smallest digits occupy the most significant positions in both numbers.

# Approach
1. Convert the integer `num` to a string `s` to easily access and manipulate individual digits.
2. Sort the string `s` in non-decreasing order. This ensures that when we distribute digits, the smallest ones are processed first.
3. Iterate through the sorted string. Use the modulo operator (`i % 2`) to alternate appending digits to `num1` and `num2`.
4. Convert the resulting strings `num1` and `num2` back to integers and return their sum.

### Visual Trace (Example 1: num = 4325)
- **Initial**: `s = "4325"`
- **Sorted**: `s = "2345"`
- **Iteration**:
  - `i=0`: `s[0]='2'`, `num1` becomes "2"
  - `i=1`: `s[1]='3'`, `num2` becomes "3"
  - `i=2`: `s[2]='4'`, `num1` becomes "24"
  - `i=3`: `s[3]='5'`, `num2` becomes "35"
- **Result**: `stoi("24") + stoi("35") = 24 + 35 = 59`

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of digits in `num`. Sorting the digits takes $$O(N \log N)$$, and the subsequent linear pass takes $$O(N)$$.
- Space complexity: $$O(N)$$, required to store the string representation of the digits.

# Code
```cpp
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        
        string num1 = "";
        string num2 = "";
        for(int i = 0; i < s.size(); i++) {
            if(i % 2 == 0) {
                num1 += s[i];
            } else {
                num2 += s[i];
            }
        }
        return stoi(num1) + stoi(num2);
    }
};
```

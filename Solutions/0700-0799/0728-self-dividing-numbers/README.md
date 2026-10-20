# [728. Self Dividing Numbers](https://leetcode.com/problems/self-dividing-numbers/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
A **self-dividing number** is a number that is divisible by every digit it contains.

* For example, `128` is **a self-dividing number** because `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`.

A **self-dividing number** is not allowed to contain the digit zero.

Given two integers `left` and `right`, return *a list of all the **self-dividing numbers** in the range* `[left, right]` (both **inclusive**).

**Example 1:**

```
Input: left = 1, right = 22
Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
```

**Example 2:**

```
Input: left = 47, right = 85
Output: [48,55,66,77]
```

**Constraints:**

* `1 <= left <= right <= 104`

---

## Solution & Editorial
# Intuition
The problem asks us to identify all numbers within a given range `[left, right]` that are divisible by each of their constituent digits and do not contain the digit zero. We can iterate through every integer in the range and validate it using a helper function that extracts its digits one by one.

# Approach
1. Iterate from `left` to `right` using a `for` loop in `selfDividingNumbers` and maintain an `ans` vector.
2. For each number `i`, pass it to the helper function `dig(int num)` to check the self-dividing property.
3. Inside `dig(int num)`, store the original value in `n` and extract digits using modulo arithmetic (`num % 10`).
4. If a digit is `0`, return `false`. If `n` is not divisible by the extracted `digit` (`n % digit != 0`), return `false`.
5. Divide `num` by `10` to process the next higher-order digit until `num` becomes `0`.
6. If all digits pass the check, return `true` and add the number to `ans`.

### Visual Dry Run
For `left = 11`, `right = 12`:
- `i = 11`: `dig(11)` extracts digit `1`, checks `11 % 1 == 0`. Next digit `1`, checks `11 % 1 == 0`. Returns `true`. `ans` gets `11`.
- `i = 12`: `dig(12)` extracts digit `2`, checks `12 % 2 == 0`. Next digit `1`, checks `12 % 1 == 0`. Returns `true`. `ans` gets `12`.

# Complexity
- Time complexity: $$O((R - L + 1) 	imes 	ext{digits})$$, where $$R - L + 1$$ is the number of integers in the range `[left, right]`, and $$	ext{digits}$$ is the number of digits in each integer (at most 5 for numbers up to $$10^4$$).
- Space complexity: $$O(1)$$ auxiliary space, excluding the output vector `ans` which requires space proportional to the number of valid self-dividing numbers found.

# Code
```cpp
class Solution {
public:
    bool dig(int num){
        int n = num;
        while(num){
            int digit = num%10;
            if(digit!=0){
                if(n%digit!=0){
                return false;
                }
            }else{
                return false;
            }
        num/=10;
    }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i = left;i<=right;i++){
            if(dig(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }

};
```

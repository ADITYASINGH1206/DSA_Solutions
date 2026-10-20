# [4039. Sum of Decoded Numbers](https://leetcode.com/problems/sum-of-decoded-numbers/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `simulation`

---

## Problem Description
You are given an integer array `nums`.

Each `nums[i]` is an **encoded** integer representing two positive integers `xi` and `yi`. To decode `nums[i]`, define:

* `widthi = nums[i] % 10`.
* `di = floor(nums[i] / 10)`.
* `xi` as the integer formed by the first `widthi` digits of the decimal representation of `di`.
* `yi` as the integer formed by all remaining digits of the decimal representation of `di`.

It is guaranteed that the decimal representation of `di` contains more than `widthi` digits. Therefore, both `xi` and `yi` contain at least one digit.

The **decoded value** of `nums[i]` is `xiyi`.

Return the sum of the decoded values of all elements in `nums`, modulo `109 + 7`.

The `floor()` function returns the integer part of the division.

**Example 1:**

**Input:** nums = [231]

**Output:** 8

**Explanation:**

* For 231, we have `width = 1`, `d = 23`, `x = 2`, and `y = 3`.
* The decoded value of 231 is `23 = 8`.
* Since there is only one element in `nums`, the sum of the decoded values is 8.

**Example 2:**

**Input:** nums = [2522,2101]

**Output:** 1649

**Explanation:**

* For 2522, we have `width = 2`, `d = 252`, `x = 25`, and `y = 2`.
* The decoded value of 2522 is `252 = 625`.
* For 2101, we have `width = 1`, `d = 210`, `x = 2`, and `y = 10`.
* The decoded value of 2101 is `210 = 1024`.
* The sum of the decoded values is `625 + 1024 = 1649`.

**Example 3:**

**Input:** nums = [2301]

**Output:** 73741817

**Explanation:**

* For 2301, we have `width = 1`, `d = 230`, `x = 2`, and `y = 30`.
* The decoded value is `230 = 1073741824`.
* Therefore, the answer is `1073741824 modulo (109 + 7) = 73741817`.

**Constraints:**

* `1 <= nums.length <= 105`
* `100 < nums[i] < 1015`
* `1 <= widthi <= 9`
* `1 <= xi, yi < 109`
* The digit sequences used to form `xi` and `yi` do not have leading zeros.
* It is guaranteed that every element in `nums` is a valid encoded integer.

---

## Solution & Editorial
# Intuition
The problem requires calculating the sum of powers $x_i^{y_i}$ modulo $10^9 + 7$. Since $y_i$ can be as large as $10^9$, a linear approach to exponentiation is infeasible. We must use Binary Exponentiation (also known as Exponentiation by Squaring) to compute each term in logarithmic time.

# Approach
1. Iterate through each number in the input array `nums`.
2. For each `nums[i]`, extract `width = nums[i] % 10` and `d = nums[i] / 10`.
3. Convert `d` to a string to easily split it into `x` (first `width` digits) and `y` (remaining digits) using `substr`.
4. Convert the substrings back to integers `x1` and `y1`.
5. Compute $x_1^{y_1} \pmod{10^9 + 7}$ using a modular exponentiation function.
6. Accumulate the result in `ans` and apply the modulo operator at each step to prevent overflow.

### Visual Trace (Example 2: nums = [2522, 2101])
| nums[i] | width | d | x | y | x^y (mod 10^9+7) | Running Sum |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 2522 | 2 | 252 | 25 | 2 | 625 | 625 |
| 2101 | 1 | 210 | 2 | 10 | 1024 | 1649 |

# Complexity
- Time complexity: $$O(N \log Y)$$, where $N$ is the number of elements and $Y$ is the maximum exponent. Each modular exponentiation takes logarithmic time relative to the exponent.
- Space complexity: $$O(D)$$, where $D$ is the number of digits in `d` (at most 15), used for string conversion and substring operations.

# Code
```cpp
class Solution {
public:
    long long modulo = 1e9 + 7;
    long long power(long long x, long long y) {
        long long res = 1;
        x = x % modulo; 
        
        while (y > 0) {
            if (y % 2 == 1) {
                res = (res * x) % modulo;
            }
            y = y / 2;
            x = (x * x) % modulo;
        }
        return res;
    }
    
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        for(int i = 0; i < n; i++){
            long long num = nums[i];
            
            int width = num % 10;
            long long d = num / 10; 
            string ds = to_string(d);
            string x = ds.substr(0, width);
            string y = ds.substr(width);
            long long x1 = x.empty() ? 0 : stoll(x);
            long long y1 = y.empty() ? 0 : stoll(y);
            ans += power(x1, y1);
            ans = ans % modulo;
        }   
        
        return ans;
    }
};
```

# [2894. Divisible and Non-divisible Sums Difference](https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
You are given positive integers `n` and `m`.

Define two integers as follows:

* `num1`: The sum of all integers in the range `[1, n]` (both **inclusive**) that are **not divisible** by `m`.
* `num2`: The sum of all integers in the range `[1, n]` (both **inclusive**) that are **divisible** by `m`.

Return *the integer* `num1 - num2`.

**Example 1:**

```
Input: n = 10, m = 3
Output: 19
Explanation: In the given example:
- Integers in the range [1, 10] that are not divisible by 3 are [1,2,4,5,7,8,10], num1 is the sum of those integers = 37.
- Integers in the range [1, 10] that are divisible by 3 are [3,6,9], num2 is the sum of those integers = 18.
We return 37 - 18 = 19 as the answer.
```

**Example 2:**

```
Input: n = 5, m = 6
Output: 15
Explanation: In the given example:
- Integers in the range [1, 5] that are not divisible by 6 are [1,2,3,4,5], num1 is the sum of those integers = 15.
- Integers in the range [1, 5] that are divisible by 6 are [], num2 is the sum of those integers = 0.
We return 15 - 0 = 15 as the answer.
```

**Example 3:**

```
Input: n = 5, m = 1
Output: -15
Explanation: In the given example:
- Integers in the range [1, 5] that are not divisible by 1 are [], num1 is the sum of those integers = 0.
- Integers in the range [1, 5] that are divisible by 1 are [1,2,3,4,5], num2 is the sum of those integers = 15.
We return 0 - 15 = -15 as the answer.
```

**Constraints:**

* `1 <= n, m <= 1000`

---

## Solution & Editorial
# Intuition
To solve this problem, we need to partition the set of integers from 1 to $n$ into two subsets based on their divisibility by $m$. Since $n$ is small ($n \le 1000$), a simple linear scan is highly efficient and optimal.

# Approach
1. Initialize two integer accumulators, `x` (for non-divisible sum) and `y` (for divisible sum), to 0.
2. Iterate through every integer `i` from 1 to `n` inclusive.
3. For each `i`, check the condition `i % m == 0`:
   - If true, add `i` to `y`.
   - If false, add `i` to `x`.
4. Return the difference `x - y`.

### Visual Trace (n=10, m=3)
| i | i % 3 == 0 | x (not div) | y (div) |
|---|---|---|---|
| 1 | No | 1 | 0 |
| 2 | No | 3 | 0 |
| 3 | Yes | 3 | 3 |
| 4 | No | 7 | 3 |
| 5 | No | 12 | 3 |
| 6 | Yes | 12 | 9 |
| 7 | No | 19 | 9 |
| 8 | No | 27 | 9 |
| 9 | Yes | 27 | 18 |
| 10 | No | 37 | 18 |

Result: 37 - 18 = 19.

# Complexity
- Time complexity: $$O(n)$$ — We perform a single pass from 1 to $n$, executing constant-time arithmetic and conditional operations at each step.
- Space complexity: $$O(1)$$ — We only use two integer variables to store the running sums, regardless of the input size.

# Code
```cpp
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int x= 0,y=0;
        for(int i  =1 ; i<=n;i++){
            if(i%m!=0){
                x+=i;
            }else{
                y+=i;
            }
        }
        return x-y;
    }
};
```

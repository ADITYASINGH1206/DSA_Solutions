# [3658. GCD of Odd and Even Sums](https://leetcode.com/problems/gcd-of-odd-and-even-sums/)
**Difficulty:** `Easy` | **Tags:** `math`, `number-theory`

---

## Problem Description
You are given an integer `n`. Your task is to compute the **GCD** (greatest common divisor) of two values:

* `sumOdd`: the sum of the smallest `n` positive odd numbers.
* `sumEven`: the sum of the smallest `n` positive even numbers.

Return the GCD of `sumOdd` and `sumEven`.

**Example 1:**

**Input:** n = 4

**Output:** 4

**Explanation:**

* Sum of the first 4 odd numbers `sumOdd = 1 + 3 + 5 + 7 = 16`
* Sum of the first 4 even numbers `sumEven = 2 + 4 + 6 + 8 = 20`

Hence, `GCD(sumOdd, sumEven) = GCD(16, 20) = 4`.

**Example 2:**

**Input:** n = 5

**Output:** 5

**Explanation:**

* Sum of the first 5 odd numbers `sumOdd = 1 + 3 + 5 + 7 + 9 = 25`
* Sum of the first 5 even numbers `sumEven = 2 + 4 + 6 + 8 + 10 = 30`

Hence, `GCD(sumOdd, sumEven) = GCD(25, 30) = 5`.

**Constraints:**

* `1 <= n <= 10​​​​​​​00`

---

## Solution & Editorial
# Intuition
The sum of the first $n$ positive odd numbers is $n^2$, and the sum of the first $n$ positive even numbers is $n(n+1)$. The problem asks for $\text{gcd}(n^2, n(n+1))$.

# Approach
1. The sum of the first $n$ odd numbers is given by the arithmetic series formula: $1 + 3 + \dots + (2n-1) = n^2$.
2. The sum of the first $n$ even numbers is given by: $2 + 4 + \dots + 2n = 2(1 + 2 + \dots + n) = 2 \cdot \frac{n(n+1)}{2} = n(n+1)$.
3. We need to compute $\text{gcd}(n^2, n(n+1))$.
4. Factoring out $n$, we get $\text{gcd}(n \cdot n, n \cdot (n+1)) = n \cdot \text{gcd}(n, n+1)$.
5. Since consecutive integers $n$ and $n+1$ are always coprime, $\text{gcd}(n, n+1) = 1$.
6. Therefore, the result is simply $n \cdot 1 = n$.

### Visual Trace (n=4)
| Variable | Value |
| :--- | :--- |
| sumOdd ($n^2$) | 16 |
| sumEven ($n(n+1)$) | 20 |
| GCD(16, 20) | 4 |

# Complexity
- Time complexity: $$O(1)$$ — The result is derived directly from the input $n$ using a constant-time mathematical property.
- Space complexity: $$O(1)$$ — No auxiliary space is used.

# Code
```cpp
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
```

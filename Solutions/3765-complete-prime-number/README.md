# [3765. Complete Prime Number](https://leetcode.com/problems/complete-prime-number/)
**Difficulty:** `Medium` | **Tags:** `math`, `enumeration`, `number-theory`

---

## Problem Description
You are given an integer `num`.

A number `num` is called a **Complete Prime Number** if every **prefix** and every **suffix** of `num` is **prime**.

Return `true` if `num` is a Complete Prime Number, otherwise return `false`.

**Note**:

* A **prefix** of a number is formed by the **first** `k` digits of the number.
* A **suffix** of a number is formed by the **last** `k` digits of the number.
* Single-digit numbers are considered Complete Prime Numbers only if they are **prime**.

**Example 1:**

**Input:** num = 23

**Output:** true

**Explanation:**

* **​​​​​​​**Prefixes of `num = 23` are 2 and 23, both are prime.
* Suffixes of `num = 23` are 3 and 23, both are prime.
* All prefixes and suffixes are prime, so 23 is a Complete Prime Number and the answer is `true`.

**Example 2:**

**Input:** num = 39

**Output:** false

**Explanation:**

* Prefixes of `num = 39` are 3 and 39. 3 is prime, but 39 is not prime.
* Suffixes of `num = 39` are 9 and 39. Both 9 and 39 are not prime.
* At least one prefix or suffix is not prime, so 39 is not a Complete Prime Number and the answer is `false`.

**Example 3:**

**Input:** num = 7

**Output:** true

**Explanation:**

* 7 is prime, so all its prefixes and suffixes are prime and the answer is `true`.

**Constraints:**

* `1 <= num <= 109`

---

## Solution & Editorial
# Intuition
A number is a "Complete Prime Number" if every prefix and every suffix is prime. Since the number of digits in a 32-bit integer is small (at most 10), we can efficiently extract all prefixes and suffixes and verify their primality using a standard trial division algorithm.

# Approach
1. **Primality Test**: Implement a helper function `prime(int& num)` that checks if a number is prime using trial division up to $\sqrt{num}$. Handle edge cases like $num \le 1$ and even numbers.
2. **Prefix Check**: Convert the number to a string or iteratively divide by 10 to extract prefixes. For `num = 23`, prefixes are `23` and `2`.
3. **Suffix Check**: Use a power-of-10 divisor `p` to extract suffixes. For `num = 23`, suffixes are `23` and `3`.
4. **Validation**: If any prefix or suffix fails the `prime` test, return `false`. Otherwise, return `true`.

### Visual Trace (num = 23)
| Step | Operation | Value | Prime? |
| :--- | :--- | :--- | :--- |
| Prefix 1 | 23 | 23 | Yes |
| Prefix 2 | 23 / 10 | 2 | Yes |
| Suffix 1 | 23 % 100 | 23 | Yes |
| Suffix 2 | 23 % 10 | 3 | Yes |

# Complexity
- Time complexity: $$O(\sqrt{N} \cdot \log N)$$, where $N$ is the input number. There are $O(\log N)$ prefixes and suffixes, and each primality test takes $O(\sqrt{N})$.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool prime(int& num) {
        if (num <= 1) {
            return false;
        } else if (num == 2) {
            return true;
        } else if (num % 2 == 0) {
            return false;
        } else {
            for (int i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    bool completePrime(int num) {
        if(!prime(num)){
            return false;
        }
        int x = num;
        while(x){
            if(!prime(x)){
                return false;
            }
            x/=10;
        }
        int p=1;
        while(p<=num/10){
            p*=10;
        }
        x=num;
        while (p > 1) {
            x %= p;
            if (!prime(x))
                return false;
            p /= 10;
        }
        return true;
    }
};
```

# [3918. Sum of Primes Between Number and Its Reverse](https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/)
**Difficulty:** `Medium` | **Tags:** `math`, `number-theory`

---

## Problem Description
You are given an integer `n`.

Let `r` be the integer formed by reversing the digits of `n`.

Return the **sum** of all prime numbers between `min(n, r)` and `max(n, r)`, inclusive.

**Example 1:**

**Input:** n = 13

**Output:** 132

**Explanation:**

* The reverse of 13 is 31. Thus, the range is `[13, 31]`.
* The prime numbers in this range are 13, 17, 19, 23, 29, and 31.
* The sum of these prime numbers is `13 + 17 + 19 + 23 + 29 + 31 = 132`.

**Example 2:**

**Input:** n = 10

**Output:** 17

**Explanation:**

* The reverse of 10 is 1. Thus, the range is `[1, 10]`.
* The prime numbers in this range are 2, 3, 5, and 7.
* The sum of these prime numbers is `2 + 3 + 5 + 7 = 17`.

**Example 3:**

**Input:** n = 8

**Output:** 0

**Explanation:**

* The reverse of 8 is 8. Thus, the range is `[8, 8]`.
* There are no prime numbers in this range, so the sum is 0.

**Constraints:**

* `1 <= n <= 1000`

---

## Solution & Editorial
# Intuition
To solve this problem, we need to identify the range defined by the integer `n` and its digit-reversed counterpart `r`. Once the range `[min(n, r), max(n, r)]` is established, we iterate through every integer in this interval and verify its primality using trial division.

# Approach
1. **Digit Reversal**: Convert the integer `n` to a string, reverse the string, and convert it back to an integer `r` using `stoi`.
2. **Range Definition**: Determine the lower bound `start = min(n, r)` and the upper bound `end = max(n, r)`.
3. **Primality Testing**: Implement a helper function `isPrime(k)` that returns `true` if `k > 1` and has no divisors other than 1 and itself, checked up to `sqrt(k)`.
4. **Summation**: Iterate from `start` to `end` inclusive, adding the current number to `ans` if `isPrime(i)` is true.

### Visual Trace (Example 1: n = 13)
| Step | Variable | Value |
| :--- | :--- | :--- |
| Reverse | r | 31 |
| Range | [start, end] | [13, 31] |
| Iteration | i | 13, 14, ..., 31 |
| Prime Check | isPrime(i) | 13(T), 17(T), 19(T), 23(T), 29(T), 31(T) |
| Summation | ans | 13+17+19+23+29+31 = 132 |

# Complexity
- Time complexity: $$O(N \sqrt{N})$$ where $$N$$ is the value of the input. We iterate through the range (at most $$N$$) and perform a primality test for each, which takes $$O(\sqrt{N})$$ time.
- Space complexity: $$O(1)$$ (ignoring the small constant space for string conversion), as we only use a few integer variables for tracking the sum and bounds.

# Code
```cpp
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int r = stoi(s);
        
        int start = min(n, r);
        int end = max(n, r);
        
        int ans = 0;
        for (int i = start; i <= end; i++) {
            if(isPrime(i)) {
                ans+= i;
            }
        }
        
        return ans;
    }
};
```

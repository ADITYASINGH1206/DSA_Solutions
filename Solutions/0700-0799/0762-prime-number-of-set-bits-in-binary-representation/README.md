# [762. Prime Number of Set Bits in Binary Representation](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/)
**Difficulty:** `Easy` | **Tags:** `math`, `bit-manipulation`, `primality-test`

---

## Problem Description
Given two integers `left` and `right`, return *the **count** of numbers in the **inclusive** range* `[left, right]` *having a **prime number of set bits** in their binary representation*.

Recall that the **number of set bits** an integer has is the number of `1`'s present when written in binary.

* For example, `21` written in binary is `10101`, which has `3` set bits.

**Example 1:**

```
Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.
```

**Example 2:**

```
Input: left = 10, right = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
5 numbers have a prime number of set bits.
```

**Constraints:**

* `1 <= left <= right <= 106`
* `0 <= right - left <= 104`

---

## Solution & Editorial
# Intuition
The problem asks us to count how many numbers in the inclusive range `[left, right]` have a prime number of set bits (1s) in their binary representation. Since the maximum value of `right` is $10^6$, its binary representation has at most 20 bits. Thus, the number of set bits for any number in the range will always be between 0 and 20. We can predefine the prime numbers up to 20 in a hash set and check the popcount of each number efficiently using compiler builtins.

# Approach
1. Initialize an `unordered_set<int>` named `primes` containing the prime numbers up to 20: `{2, 3, 5, 7, 11, 13, 17, 19}`.
2. Initialize an accumulator variable `ans` to `0` to keep track of numbers meeting the condition.
3. Iterate from `i = left` to `right` inclusive.
4. For each integer `i`, use `__builtin_popcount(i)` to count the number of set bits in its binary representation.
5. Check if the set bit count exists in the `primes` set using `primes.count(...)`. Add the result (0 or 1) to `ans`.
6. Return `ans` after the loop completes.

### Visual Trace Walkthrough (Example 1: left = 6, right = 10)
| i | Binary | Set Bits (`__builtin_popcount`) | Is Prime? (`primes.count`) | `ans` (Cumulative) |
|---|--------|-----------------------------------|----------------------------|--------------------|
| 6 | `110`  | 2                                 | Yes (1)                    | 1                  |
| 7 | `111`  | 3                                 | Yes (1)                    | 2                  |
| 8 | `1000` | 1                                 | No (0)                     | 2                  |
| 9 | `1001` | 2                                 | Yes (1)                    | 3                  |
| 10| `1010` | 2                                 | Yes (1)                    | 4                  |

# Complexity
- Time complexity: $$O((right - left) \times \log(\text{right}))$$ — We iterate `right - left + 1` times. In each iteration, `__builtin_popcount` evaluates in $O(1)$ hardware instructions (or $O(\log(\text{right}))$ bit operations), and hash set lookup takes $O(1)$ average time.
- Space complexity: $$O(1)$$ — The `primes` set stores a fixed number of elements (at most 8 primes), and all other variables consume constant auxiliary space.

# Code
```cpp
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            ans += primes.count(__builtin_popcount(i));
        }
        return ans;
    }
};
```

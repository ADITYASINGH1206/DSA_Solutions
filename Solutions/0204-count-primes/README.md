# [204. Count Primes](https://leetcode.com/problems/count-primes/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `enumeration`, `number-theory`, `primality-test`, `sieve-theory`, `prime-number-sieve`

---

## Problem Description
Given an integer `n`, return *the number of prime numbers that are strictly less than* `n`.

**Example 1:**

```
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

**Example 2:**

```
Input: n = 0
Output: 0
```

**Example 3:**

```
Input: n = 1
Output: 0
```

**Constraints:**

* `0 <= n <= 5 * 106`

---

## Solution & Editorial
# Intuition
To efficiently count all prime numbers strictly less than $n$, we can use the classical Sieve of Eratosthenes algorithm. Instead of testing each number for primality individually, we iteratively mark the multiples of each prime number as composite, beginning from its square.

# Approach
1. Initialize a vector `primes` of size $n+1$ with all elements set to `1` (assuming all numbers are prime initially).
2. Iterate `i` from $2$ up to $n$. If `primes[i]` is `1`, it is a prime number.
3. For each found prime `i`, mark all its multiples starting from $i^2$ up to $n$ as `0` (composite) by incrementing in steps of `i`.
4. Iterate from $2$ up to $n-1$ and count how many entries in `primes` remain `1`.
5. Return the accumulated count `ans`.

### Visual Walkthrough for $n = 10$
- `primes` initialized to size 11 with all 1s.
- `i = 2`: `primes[2] == 1`, mark multiples $2^2 = 4, 6, 8, 10$ as `0`.
- `i = 3`: `primes[3] == 1`, mark multiples $3^2 = 9$ as `0`.
- `i = 4`: `primes[4] == 0`, skip.
- `i = 5`: `primes[5] == 1`, mark multiples $5^2 = 25 > 10$, skip.
- Final count of remaining 1s from index 2 to 9: 2, 3, 5, 7 $ightarrow$ Total count = $4$.

# Complexity
- Time complexity: $$O(n \log \log n)$$ — The outer loop runs up to $n$, and the inner harmonic series sum of multiples yields an overall complexity bounded by $n \log \log n$.
- Space complexity: $$O(n)$$ — Auxiliary vector `primes` of size $n+1$ is used to store primality states.

# Code
```cpp
class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        vector<int> primes(n+1,1);

        for(long long i = 2;i<=n;i++){
            if(primes[i] == 1){
                for(long long j = i*i ;j<=n;j+=i){
                    primes[j] = 0;
                }
            }
        }
        for(int i = 2;i<n;i++){
            if(primes[i]) ans++;
        }
        return ans;
    }
};
```

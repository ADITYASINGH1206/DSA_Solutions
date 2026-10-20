# [3821. Find Nth Smallest Integer With K One Bits](https://leetcode.com/problems/find-nth-smallest-integer-with-k-one-bits/)
**Difficulty:** `Hard` | **Tags:** `math`, `bit-manipulation`, `combinatorics`

---

## Problem Description
You are given two positive integers `n` and `k`.

Return an integer denoting the `nth` smallest positive integer that has **exactly** `k` ones in its binary representation. It is guaranteed that the answer is **strictly less** than `250`.

**Example 1:**

**Input:** n = 4, k = 2

**Output:** 9

**Explanation:**

The 4 smallest positive integers that have exactly `k = 2` ones in their binary representations are:

* `3 = 112`
* `5 = 1012`
* `6 = 1102`
* `9 = 10012`

**Example 2:**

**Input:** n = 3, k = 1

**Output:** 4

**Explanation:**

The 3 smallest positive integers that have exactly `k = 1` one in their binary representations are:

* `1 = 12`
* `2 = 102`
* `4 = 1002`

**Constraints:**

* `1 <= n <= 250`
* `1 <= k <= 50`
* The answer is strictly less than `250`.

---

## Solution & Editorial
# Intuition
To find the $n^{th}$ smallest integer with exactly $k$ set bits, we can construct the number bit by bit from most significant to least significant. The core observation is that the number of integers with exactly $k$ bits in a range of length $L$ is given by the binomial coefficient $\binom{L}{k}$. By iterating through bit positions, we can decide whether to set the current bit based on whether $n$ is greater than the count of numbers that could be formed if this bit were 0.

# Approach
1. Precompute Pascal's triangle to store binomial coefficients $\binom{i}{j}$ up to 64 to allow $O(1)$ lookups.
2. Iterate from the highest possible bit (e.g., 62) down to 0. At each `bit` position, calculate how many numbers can be formed using `k` bits in the remaining `bit` positions (i.e., `combinations[bit][k]`).
3. If $n$ is greater than this count, it means the $n^{th}$ number must have this bit set. We set the bit in `result`, subtract the count from $n$, and decrement $k$.
4. If $n$ is less than or equal to the count, the current bit must be 0, and we proceed to the next lower bit.

### Visual Trace (n=4, k=2)
| Bit | Count (C(bit, k)) | n > Count? | Action | Result | k |
|---|---|---|---|---|---|
| 3 | C(3, 2) = 3 | Yes | Set bit 3, n=4-3=1 | 8 | 1 |
| 2 | C(2, 1) = 2 | No | Skip | 8 | 1 |
| 1 | C(1, 1) = 1 | No | Skip | 8 | 1 |
| 0 | C(0, 1) = 0 | Yes | Set bit 0, n=1-0=1 | 9 | 0 |

# Complexity
- Time complexity: $$O(B^2)$$ where $B$ is the number of bits (64). The precomputation takes $O(B^2)$ and the bit iteration takes $O(B)$.
- Space complexity: $$O(B^2)$$ to store the Pascal's triangle table.

# Code
```cpp
class Solution {
public:
    long long combinations[65][65];

    void initCombinations() {
        memset(combinations, 0, sizeof(combinations));
        for (int i = 0; i <= 64; i++) {
            combinations[i][0] = 1; // nC0 is always 1
            for (int j = 1; j <= i; j++) {
                combinations[i][j] = combinations[i - 1][j - 1] + combinations[i - 1][j];
            }
        }
    }

    long long nthSmallest(long long n, int k) {
        initCombinations();
        
        long long result = 0;
    
        for (int bit = 62; bit >= 0; bit--) {
            long long count = (bit >= k) ? combinations[bit][k] : 0;
            
            if (n > count) {
                result |= (1LL << bit);
                n -= count;
                k--;
                if (k == 0) break; 
            } else {

            }
        }
        
        return result;
    }
};
```

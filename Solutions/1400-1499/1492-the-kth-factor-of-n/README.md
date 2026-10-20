# [1492. The kth Factor of n](https://leetcode.com/problems/the-kth-factor-of-n/)
**Difficulty:** `Medium` | **Tags:** `math`, `number-theory`, `prime-factorization`

---

## Problem Description
You are given two positive integers `n` and `k`. A factor of an integer `n` is defined as an integer `i` where `n % i == 0`.

Consider a list of all factors of `n` sorted in **ascending order**, return *the* `kth` *factor* in this list or return `-1` if `n` has less than `k` factors.

**Example 1:**

```
Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
```

**Example 2:**

```
Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.
```

**Example 3:**

```
Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
```

**Constraints:**

* `1 <= k <= n <= 1000`

**Follow up:**

Could you solve this problem in less than O(n) complexity?

---

## Solution & Editorial
# Intuition
To find the $k^{th}$ factor of an integer $n$, we can iterate through all possible divisors from $1$ to $n$. Since a factor $i$ must satisfy $n \pmod i = 0$, we can collect all such integers in a list and retrieve the element at index $k-1$.

# Approach
1. Initialize an empty vector `factors` to store the divisors found.
2. Iterate through every integer `i` from $1$ to $n$ inclusive.
3. For each `i`, check if `n % i == 0`. If true, append `i` to the `factors` vector.
4. After the loop, check if the size of `factors` is at least $k$. If it is, return `factors[k-1]`. Otherwise, return -1.

### Visual Trace (n=12, k=3)
| Iteration (i) | n % i == 0 | factors (vector) |
| :--- | :--- | :--- |
| 1 | Yes | [1] |
| 2 | Yes | [1, 2] |
| 3 | Yes | [1, 2, 3] |
| 4 | Yes | [1, 2, 3, 4] |
| 5 | No | [1, 2, 3, 4] |
| 6 | Yes | [1, 2, 3, 4, 6] |
| 7-11 | No | [1, 2, 3, 4, 6] |
| 12 | Yes | [1, 2, 3, 4, 6, 12] |

Result: `factors[3-1]` = `factors[2]` = 3.

# Complexity
- Time complexity: $$O(n)$$ — We perform a single pass from $1$ to $n$, executing a constant time modulo operation at each step.
- Space complexity: $$O(d)$$ where $d$ is the number of factors of $n$. In the worst case, this is $O(n)$ if we store all factors, though for $n \le 1000$, this is negligible.

# Code
```cpp
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i=1;i<=n;i++){
            if(n%i==0) factors.push_back(i);
        }
        if(k<=factors.size()) return factors[k-1];

        return -1;
        
        
    }
};
```

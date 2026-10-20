# [3848. Check Digitorial Permutation](https://leetcode.com/problems/check-digitorial-permutation/)
**Difficulty:** `Medium` | **Tags:** `math`, `counting`

---

## Problem Description
You are given an integer `n`.

A number is called **digitorial** if the sum of the **factorials** of its digits is **equal** to the number itself.

Determine whether **any permutation** of `n` (including the original order) forms a **digitorial** number.

Return `true` if such a **permutation** exists, otherwise return `false`.

**Note**:

* The **factorial** of a non-negative integer `x`, denoted as `x!`, is the **product** of all positive integers **less than or equal** to `x`, and `0! = 1`.
* A **permutation** is a rearrangement of all the digits of a number that does **not** start with zero. Any arrangement starting with zero is invalid.

**Example 1:**

**Input:** n = 145

**Output:** true

**Explanation:**

The number 145 itself is digitorial since `1! + 4! + 5! = 1 + 24 + 120 = 145`. Thus, the answer is `true`.

**Example 2:**

**Input:** n = 10

**Output:** false

**Explanation:**​​​​​​​

10 is not digitorial since `1! + 0! = 2` is not equal to 10, and the permutation `"01"` is invalid because it starts with zero.

**Constraints:**

* `1 <= n <= 109`

---

## Solution & Editorial
# Intuition
A number is "digitorial" if the sum of the factorials of its digits equals the number itself. Since the sum of factorials of digits is invariant under permutation, any permutation of the digits of $n$ will result in the same sum of factorials. Therefore, we only need to check if the set of digits in the original number $n$ is identical to the set of digits in the number formed by the sum of their factorials.

# Approach
1. Calculate the sum of the factorials of each digit in $n$. Let this sum be `sumFact`.
2. Convert both the original number $n$ and the calculated `sumFact` into string representations.
3. Sort both strings. If the sorted strings are identical, it implies that `sumFact` is a permutation of the digits of $n$.
4. Since the problem asks if *any* permutation of $n$ is digitorial, and the sum of factorials is constant for all permutations, we simply verify if the digits of `sumFact` match the digits of $n$.

### Visual Trace (n = 145)
| Step | Operation | Result |
| :--- | :--- | :--- |
| 1 | Digits of 145 | {1, 4, 5} |
| 2 | Factorials | 1! = 1, 4! = 24, 5! = 120 |
| 3 | `sumFact` | 1 + 24 + 120 = 145 |
| 4 | Sorted Digits of n | "145" |
| 5 | Sorted Digits of sumFact | "145" |
| 6 | Match? | True |

# Complexity
- Time complexity: $$O(D \log D)$$, where $D$ is the number of digits in $n$ (at most 10 for $n \le 10^9$). Sorting the digits takes $O(D \log D)$, and calculating the sum takes $O(D)$.
- Space complexity: $$O(D)$$, required to store the string representations of the number and the sum.

# Code
```cpp
class Solution {
public:
    int factorial(int d) {
        int fact = 1;
        for (int i = 2; i <= d; ++i) {
            fact *= i;
        }
        return fact;
    }

    bool isDigitorialPermutation(int n) {
        string originalStr = to_string(n);
        

        int sumFact = 0;
        for (char c : originalStr) {
            sumFact += factorial(c - '0');
        }

        string sumStr = std::to_string(sumFact);
        
        sort(originalStr.begin(), originalStr.end());
        sort(sumStr.begin(), sumStr.end());
    
        return originalStr == sumStr;
    }
};
```

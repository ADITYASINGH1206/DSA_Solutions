# [1545. Find Kth Bit in Nth Binary String](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `recursion`, `simulation`

---

## Problem Description
Given two positive integers `n` and `k`, the binary string `Sn` is formed as follows:

* `S1 = "0"`
* `Si = Si - 1 + "1" + reverse(invert(Si - 1))` for `i > 1`

Where `+` denotes the concatenation operation, `reverse(x)` returns the reversed string `x`, and `invert(x)` inverts all the bits in `x` (`0` changes to `1` and `1` changes to `0`).

For example, the first four strings in the above sequence are:

* `S1 = "0"`
* `S2 = "011"`
* `S3 = "0111001"`
* `S4 = "011100110110001"`

Return *the* `kth` *bit* *in* `Sn`. It is guaranteed that `k` is valid for the given `n`.

**Example 1:**

```
Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".
```

**Example 2:**

```
Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
```

**Constraints:**

* `1 <= n <= 20`
* `1 <= k <= 2n - 1`

---

## Solution & Editorial
# Intuition
The sequence $S_n$ is constructed recursively. Notice that the length of $S_n$ is $2^n - 1$. The middle element of $S_n$ is always '1', splitting the string into a left half (identical to $S_{n-1}$) and a right half (the inverted and reversed version of $S_{n-1}$). We can determine the $k^{th}$ bit by identifying which segment $k$ falls into without constructing the full string.

# Approach
1. Base Case: If $n=1$, the string is "0", so return '0'.
2. Calculate the middle index: $mid = 2^{n-1}$.
3. If $k == mid$, the bit is '1'.
4. If $k < mid$, the bit is in the left half, which is identical to $S_{n-1}$. Recurse with `findKthBit(n - 1, k)`.
5. If $k > mid$, the bit is in the right half. The right half is the inverse of the reversed left half. The index $k$ in $S_n$ corresponds to the index $(2^n - k)$ in $S_{n-1}$. Find that bit and invert it.

### Visual Trace (n=3, k=6)
- $S_3$ length is $2^3 - 1 = 7$. $mid = 4$.
- $k=6 > 4$: Right half. Mirror index: $2^3 - 6 = 2$.
- Recurse: `findKthBit(2, 2)`.
- $S_2$ length is $2^2 - 1 = 3$. $mid = 2$.
- $k=2 == 2$: Return '1'.
- Backtrack: Invert '1' to '0'. Result: '0'.

# Complexity
- Time complexity: $$O(n)$$. We reduce $n$ by 1 in each recursive step, leading to a depth of $n$.
- Space complexity: $$O(n)$$. The recursion stack depth is $n$.

# Code
```cpp
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int mid = 1 << (n - 1);
        
        if (k == mid) {
            return '1'; 
        } else if (k < mid) {
            return findKthBit(n - 1, k);
        } else {
            int mirrored_k = (1 << n) - k;
            char bit = findKthBit(n - 1, mirrored_k);
            return bit == '0' ? '1' : '0'; 
        }
    }
};
```

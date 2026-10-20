# [2595. Number of Even and Odd Bits](https://leetcode.com/problems/number-of-even-and-odd-bits/)
**Difficulty:** `Easy` | **Tags:** `bit-manipulation`

---

## Problem Description
You are given a **positive** integer `n`.

Let `even` denote the number of even indices in the binary representation of `n` with value 1.

Let `odd` denote the number of odd indices in the binary representation of `n` with value 1.

Note that bits are indexed from **right to left** in the binary representation of a number.

Return the array `[even, odd]`.

**Example 1:**

**Input:** n = 50

**Output:** [1,2]

**Explanation:**

The binary representation of 50 is `110010`.

It contains 1 on indices 1, 4, and 5.

**Example 2:**

**Input:** n = 2

**Output:** [0,1]

**Explanation:**

The binary representation of 2 is `10`.

It contains 1 only on index 1.

**Constraints:**

* `1 <= n <= 1000`

---

## Solution & Editorial
# Intuition
To determine the parity of bits at specific indices, we can process the binary representation of the integer `n` from right to left (least significant bit to most significant bit). By maintaining a toggle state, we can track whether the current index is even or odd without needing to store the entire binary string.

# Approach
1. Initialize `even` and `odd` counters to 0 and a boolean `turn` to `true` (representing index 0, which is even).
2. Iterate while `n > 0`:
   - Check if the current bit is 1 using `n % 2`.
   - If the bit is 1, increment the corresponding counter based on the `turn` state.
   - Perform integer division `n /= 2` to shift to the next bit.
   - Toggle `turn` to switch between even and odd index tracking.
3. Return the result as a vector `{even, odd}`.

### Visual Trace (n = 50)
Binary: `110010` (Indices: 543210)

| Iteration | n | Bit (n%2) | turn | even | odd |
|-----------|---|-----------|------|------|-----|
| 0 | 50 | 0 | true | 0 | 0 |
| 1 | 25 | 1 | false | 0 | 1 |
| 2 | 12 | 0 | true | 0 | 1 |
| 3 | 6 | 0 | false | 0 | 1 |
| 4 | 3 | 1 | true | 1 | 1 |
| 5 | 1 | 1 | false | 1 | 2 |

# Complexity
- Time complexity: $$O(\log n)$$, where $$\log n$$ is the number of bits in the integer $n$. Since $n \le 1000$, this is at most 10 iterations.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        bool turn =true;
        while(n){
            if(n%2){
                if(turn){
                    even++;
                }else{
                    odd++;
                }
            }
            n/=2;
            turn=!turn;
        }
        return {even,odd};
    }
};
```

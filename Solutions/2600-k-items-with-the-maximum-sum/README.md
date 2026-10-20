# [2600. K Items With the Maximum Sum](https://leetcode.com/problems/k-items-with-the-maximum-sum/)
**Difficulty:** `Easy` | **Tags:** `math`, `greedy`

---

## Problem Description
There is a bag that consists of items, each item has a number `1`, `0`, or `-1` written on it.

You are given four **non-negative** integers `numOnes`, `numZeros`, `numNegOnes`, and `k`.

The bag initially contains:

* `numOnes` items with `1`s written on them.
* `numZeroes` items with `0`s written on them.
* `numNegOnes` items with `-1`s written on them.

We want to pick exactly `k` items among the available items. Return *the **maximum** possible sum of numbers written on the items*.

**Example 1:**

```
Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
Output: 2
Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 2 items with 1 written on them and get a sum in a total of 2.
It can be proven that 2 is the maximum possible sum.
```

**Example 2:**

```
Input: numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
Output: 3
Explanation: We have a bag of items with numbers written on them {1, 1, 1, 0, 0}. We take 3 items with 1 written on them, and 1 item with 0 written on it, and get a sum in a total of 3.
It can be proven that 3 is the maximum possible sum.
```

**Constraints:**

* `0 <= numOnes, numZeros, numNegOnes <= 50`
* `0 <= k <= numOnes + numZeros + numNegOnes`

---

## Solution & Editorial
# Intuition
To maximize the sum when picking exactly `k` items, we should prioritize picking items with the highest values first. The greedy strategy is to exhaust all `1`s, then all `0`s, and finally resort to `-1`s only if necessary.

# Approach
1. If `k` is less than or equal to `numOnes`, we simply pick `k` items of value `1`, resulting in a sum of `k`.
2. If `k` exceeds `numOnes`, we take all `numOnes` (adding `numOnes` to our sum) and reduce `k` by `numOnes`.
3. If the remaining `k` is less than or equal to `numZeros`, we pick the remaining items from the `0`s, which adds nothing to the sum, so the total remains `numOnes`.
4. If `k` still exceeds `numZeros`, we must pick the remaining items from the `-1`s. We subtract the remaining `k` from `numOnes` to account for the `-1`s added to our selection.

### Visual Trace (Example 2: numOnes=3, numZeros=2, numNegOnes=0, k=4)
| Step | Action | Remaining k | Current Sum |
| :--- | :--- | :--- | :--- |
| 1 | Take all 3 ones | 4 - 3 = 1 | 3 |
| 2 | Take 1 zero | 1 - 1 = 0 | 3 |
| 3 | Done | 0 | 3 |

# Complexity
- Time complexity: $$O(1)$$ — The solution performs a constant number of arithmetic operations and comparisons regardless of input size.
- Space complexity: $$O(1)$$ — No auxiliary data structures are used; only a few integer variables are maintained.

# Code
```cpp
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k>numOnes){
            k-=numOnes;
            if(k>numZeros){
                k-=numZeros;
                return numOnes-min(k,numNegOnes);
            }else{
                return numOnes;
            }
        }else{
            return k;
        }
    }
};
```

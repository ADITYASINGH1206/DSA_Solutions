# [3800. Minimum Cost to Make Two Binary Strings Equal](https://leetcode.com/problems/minimum-cost-to-make-two-binary-strings-equal/)
**Difficulty:** `Medium` | **Tags:** `string`, `greedy`

---

## Problem Description
You are given two binary strings `s` and `t`, both of length `n`, and three **positive** integers `flipCost`, `swapCost`, and `crossCost`.

You are allowed to apply the following operations any number of times (in any order) to the strings `s` and `t`:

* Choose any index `i` and flip `s[i]` or `t[i]` (change `'0'` to `'1'` or `'1'` to `'0'`). The cost of this operation is `flipCost`.
* Choose two **distinct** indices `i` and `j`, and swap either `s[i]` and `s[j]` or `t[i]` and `t[j]`. The cost of this operation is `swapCost`.
* Choose an index `i` and swap `s[i]` with `t[i]`. The cost of this operation is `crossCost`.

Return an integer denoting the **minimum** total cost needed to make the strings `s` and `t` equal.

**Example 1:**

**Input:** s = "01000", t = "10111", flipCost = 10, swapCost = 2, crossCost = 2

**Output:** 16

**Explanation:**

We can perform the following operations:

* Swap `s[0]` and `s[1]` (`swapCost = 2`). After this operation, `s = "10000"` and `t = "10111"`.
* Cross swap `s[2]` and `t[2]` (`crossCost = 2`). After this operation, `s = "10100"` and `t = "10011"`.
* Swap `s[2]` and `s[3]` (`swapCost = 2`). After this operation, `s = "10010"` and `t = "10011"`.
* Flip `s[4]` (`flipCost = 10`). After this operation, `s = t = "10011"`.

The total cost is `2 + 2 + 2 + 10 = 16`.

**Example 2:**

**Input:** s = "001", t = "110", flipCost = 2, swapCost = 100, crossCost = 100

**Output:** 6

**Explanation:**

Flipping all the bits of `s` makes the strings equal, and the total cost is `3 * flipCost = 3 * 2 = 6`.

**Example 3:**

**Input:** s = "1010", t = "1010", flipCost = 5, swapCost = 5, crossCost = 5

**Output:** 0

**Explanation:**

The strings are already equal, so no operations are required.

**Constraints:**

* `n == s.length == t.length`
* `1 <= n <= 105`​​​​​​​
* `1 <= flipCost, swapCost, crossCost <= 109`
* `s` and `t` consist only of the characters `'0'` and `'1'`.

---

## Solution & Editorial
# Intuition
To make two binary strings equal, we only care about the positions where `s[i] != t[i]`. There are two types of mismatches: `(0, 1)` and `(1, 0)`. We can resolve these mismatches using three operations: flipping, swapping within a string, or cross-swapping. The core observation is that we can pair up mismatches to minimize costs, choosing between direct flips or combinations of swaps and cross-swaps.

# Approach
1. Count the occurrences of `(0, 1)` mismatches (`c01`) and `(1, 0)` mismatches (`c10`).
2. Define the cost to resolve a pair of different mismatches (e.g., one `(0, 1)` and one `(1, 0)`) as `cost_diff = min(swapCost, 2 * flipCost)`. This is because we can either swap two indices in one string or flip both bits.
3. Define the cost to resolve a pair of identical mismatches (e.g., two `(0, 1)` pairs) as `cost_same = min(crossCost + swapCost, 2 * flipCost)`. This is because we can cross-swap one index and then swap it with another, or simply flip both.
4. Calculate the number of `diff_pairs` as `min(c01, c10)`. These are resolved using `cost_diff`.
5. The remaining mismatches are of the same type. We pair them up using `cost_same` and handle any final single mismatch with `flipCost`.

### Visual Trace (Example 1: s="01000", t="10111")
- `c01` (s=0, t=1): indices 1, 2, 3, 4 -> count = 4
- `c10` (s=1, t=0): index 0 -> count = 1
- `diff_pairs` = min(4, 1) = 1. Cost = 1 * min(2, 20) = 2.
- `remainder` = |4 - 1| = 3. `same_pairs` = 3 / 2 = 1. Cost = 1 * min(2+2, 20) = 4.
- `singles` = 3 % 2 = 1. Cost = 1 * 10 = 10.
- Total = 2 + 4 + 10 = 16.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the strings, as we iterate through the strings once to count mismatches.
- Space complexity: $$O(1)$$ as we only use a few variables to store counts and costs.

# Code
```cpp
class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long c01 = 0;
        long long c10 = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0' && t[i] == '1') {
                c01++;
            } else if (s[i] == '1' && t[i] == '0') {
                c10++;
            }
        }
        
        long long cost_diff = min((long long)swapCost, 2LL * flipCost);
        long long cost_same = min((long long)(crossCost + swapCost), 2LL * flipCost);
        
        long long diff_pairs = min(c01, c10);

        long long remainder = abs(c01 - c10);
        long long same_pairs = remainder / 2;
        long long singles = remainder % 2; 

        long long totalCost = (diff_pairs * cost_diff) + 
                              (same_pairs * cost_same) + 
                              (singles * flipCost);
                              
        return totalCost;
    }
};
```

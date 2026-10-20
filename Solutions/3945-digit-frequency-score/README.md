# [3945. Digit Frequency Score](https://leetcode.com/problems/digit-frequency-score/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `math`

---

## Problem Description
You are given an integer `n`.

The **score** of `n` is defined as the **sum** of `d * freq(d)` over all **distinct** digits `d`, where `freq(d)` denotes the number of times the digit `d` appears in `n`.

Return an integer denoting the score of `n`.

**Example 1:**

**Input:** n = 122

**Output:** 5

**Explanation:**

* The digit 1 appears 1 time, contributing `1 * 1 = 1`.
* The digit 2 appears 2 times, contributing `2 * 2 = 4`.
* Thus, the score of `n` is `1 + 4 = 5`.

**Example 2:**

**Input:** n = 101

**Output:** 2

**Explanation:**

* The digit 0 appears 1 time, contributing `0 * 1 = 0`.
* The digit 1 appears 2 times, contributing `1 * 2 = 2`.
* Thus, the score of `n` is 2.

**Constraints:**

* `1 <= n <= 109`

---

## Solution & Editorial
# Intuition
The problem defines the score as the sum of `d * freq(d)` for each distinct digit `d`. Mathematically, this is equivalent to summing every individual digit present in the number `n`. Since each occurrence of a digit `d` contributes `d` to the total sum, the frequency `freq(d)` effectively multiplies the digit `d` by the number of times it appears, which is exactly what a standard digit summation loop does.

# Approach
1. Initialize an integer `ans` to 0 to store the cumulative score.
2. Use a `while` loop to extract digits from `n` using the modulo operator (`temp % 10`).
3. Add the extracted digit to `ans`.
4. Divide `temp` by 10 to move to the next digit until `temp` becomes 0.

### Visual Trace (n = 122)
| Iteration | temp | digit | ans (sum) |
|-----------|------|-------|-----------|
| Initial   | 122  | -     | 0         |
| 1         | 12   | 2     | 2         |
| 2         | 1    | 2     | 4         |
| 3         | 0    | 1     | 5         |

# Complexity
- Time complexity: $$O(\log_{10} n)$$, as we iterate through each digit of the number once.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;
        int temp = n;
        while(temp){
            int digit = temp%10;
            ans += digit;
            temp/=10;
        }
        return ans;
    }

};
```

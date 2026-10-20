# [3751. Total Waviness of Numbers in Range I](https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/)
**Difficulty:** `Medium` | **Tags:** `math`, `dynamic-programming`, `enumeration`

---

## Problem Description
You are given two integers `num1` and `num2` representing an **inclusive** range `[num1, num2]`.

The **waviness** of a number is defined as the total count of its **peaks** and **valleys**:

* A digit is a **peak** if it is **strictly greater** than both of its immediate neighbors.
* A digit is a **valley** if it is **strictly less** than both of its immediate neighbors.
* The first and last digits of a number **cannot** be peaks or valleys.
* Any number with fewer than 3 digits has a waviness of 0.

Return the total sum of waviness for all numbers in the range `[num1, num2]`.

**Example 1:**

**Input:** num1 = 120, num2 = 130

**Output:** 3

**Explanation:**

In the range `[120, 130]`:

* `120`: middle digit 2 is a peak, waviness = 1.
* `121`: middle digit 2 is a peak, waviness = 1.
* `130`: middle digit 3 is a peak, waviness = 1.
* All other numbers in the range have a waviness of 0.

Thus, total waviness is `1 + 1 + 1 = 3`.

**Example 2:**

**Input:** num1 = 198, num2 = 202

**Output:** 3

**Explanation:**

In the range `[198, 202]`:

* `198`: middle digit 9 is a peak, waviness = 1.
* `201`: middle digit 0 is a valley, waviness = 1.
* `202`: middle digit 0 is a valley, waviness = 1.
* All other numbers in the range have a waviness of 0.

Thus, total waviness is `1 + 1 + 1 = 3`.

**Example 3:**

**Input:** num1 = 4848, num2 = 4848

**Output:** 2

**Explanation:**

Number `4848`: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

**Constraints:**

* `1 <= num1 <= num2 <= 105`

---

## Solution & Editorial
# Intuition
Since the constraints on `num1` and `num2` are relatively small ($10^5$), we can directly calculate the waviness for every integer in the range $[num1, num2]$. The waviness of a number is determined by its digits, so we can extract the digits of each number and check the peak/valley condition for every internal digit.

# Approach
1. Iterate through each integer `x` from `num1` to `num2` inclusive.
2. For each `x`, convert it into a sequence of digits by repeatedly taking the modulo 10 and dividing by 10.
3. If the number has fewer than 3 digits, its waviness is 0.
4. For numbers with 3 or more digits, iterate from the second digit to the second-to-last digit (index 1 to $m-2$ in the array).
5. Check if the current digit `nums[i]` is a peak (`nums[i] > nums[i-1]` and `nums[i] > nums[i+1]`) or a valley (`nums[i] < nums[i-1]` and `nums[i] < nums[i+1]`).
6. Accumulate the count of these occurrences and return the total sum.

### Visual Trace (Example 1: 120)
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Extract digits | `nums = [0, 2, 1]` (reversed) |
| 2 | Check index 1 | `nums[1]=2`. Is `2 > 0` and `2 > 1`? Yes. |
| 3 | Result | Waviness = 1 |

# Complexity
- Time complexity: $$O(N \cdot D)$$, where $$N$$ is the number of integers in the range ($num2 - num1 + 1$) and $$D$$ is the number of digits in the integers (at most 6 for $10^5$).
- Space complexity: $$O(D)$$, where $$D$$ is the number of digits stored in the array (constant space, as $D \le 6$).

# Code
```cpp
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int x = num1; x <= num2; x++) {
            ans += f(x);
        }
        return ans;
    }

    int f(int x) {
        int nums[20], m = 0;
        while (x > 0) {
            nums[m++] = x % 10;
            x /= 10;
        }
        if (m < 3) {
            return 0;
        }
        int s = 0;
        for (int i = 1; i < m - 1; i++) {
            if ((nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) || (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])) {
                s++;
            }
        }
        return s;
    }
};
```

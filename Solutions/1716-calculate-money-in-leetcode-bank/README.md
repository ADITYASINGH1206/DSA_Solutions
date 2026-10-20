# [1716. Calculate Money in Leetcode Bank](https://leetcode.com/problems/calculate-money-in-leetcode-bank/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
Hercy wants to save money for his first car. He puts money in the Leetcode bank **every day**.

He starts by putting in `$1` on Monday, the first day. Every day from Tuesday to Sunday, he will put in `$1` more than the day before. On every subsequent Monday, he will put in `$1` more than the **previous Monday**.

Given `n`, return *the total amount of money he will have in the Leetcode bank at the end of the* `nth` *day.*

**Example 1:**

```
Input: n = 4
Output: 10
Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
```

**Example 2:**

```
Input: n = 10
Output: 37
Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
```

**Example 3:**

```
Input: n = 20
Output: 96
Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
```

**Constraints:**

* `1 <= n <= 1000`

---

## Solution & Editorial
# Intuition
The problem describes a periodic savings pattern where the daily deposit increases linearly within a week and increments at the start of each new week. Since the constraints are small ($n \le 1000$), a direct simulation of the daily deposits is both efficient and intuitive.

# Approach
1. Initialize `ans` to 0 to track the total savings, `mon` to 1 to track the starting deposit for the current week, and `prev` to 1 to track the deposit amount of the previous day.
2. Iterate from day 1 to `n`.
3. If the current day `i` is a Monday (`i % 7 == 1`), update the total `ans` by adding the current week's starting value `mon`, then increment `mon` for the next week.
4. If it is not a Monday, add `prev + 1` to `ans` and update `prev` to `prev + 1` to reflect the daily increment.

### Visual Trace (n = 10)
| Day (i) | Condition | Operation | ans | mon | prev |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | Monday | ans += 1 | 1 | 2 | 1 |
| 2 | Other | ans += 2 | 3 | 2 | 2 |
| 3 | Other | ans += 3 | 6 | 2 | 3 |
| 4 | Other | ans += 4 | 10 | 2 | 4 |
| 5 | Other | ans += 5 | 15 | 2 | 5 |
| 6 | Other | ans += 6 | 21 | 2 | 6 |
| 7 | Other | ans += 7 | 28 | 2 | 7 |
| 8 | Monday | ans += 2 | 30 | 3 | 2 |
| 9 | Other | ans += 3 | 33 | 3 | 3 |
| 10 | Other | ans += 4 | 37 | 3 | 4 |

# Complexity
- Time complexity: $$O(n)$$, as we iterate exactly $$n$$ times to calculate the daily deposit.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for variables `ans`, `mon`, and `prev`.

# Code
```cpp
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int mon = 1;
        int prev = 1;
        for(int i = 1;i<=n;i++){
            if(i%7 == 1){
                ans += mon;
                prev = mon;
                mon++;
            }else{
                ans += prev+1;
                prev += 1;
            }
        }
        return ans;

    }
};
```

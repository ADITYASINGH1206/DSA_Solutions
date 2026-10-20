# [3483. Unique 3-Digit Even Numbers](https://leetcode.com/problems/unique-3-digit-even-numbers/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `recursion`, `enumeration`

---

## Problem Description
You are given an array of digits called `digits`. Your task is to determine the number of **distinct** three-digit even numbers that can be formed using these digits.

**Note**: Each *copy* of a digit can only be used **once per number**, and there may **not** be leading zeros.

**Example 1:**

**Input:** digits = [1,2,3,4]

**Output:** 12

**Explanation:** The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.

**Example 2:**

**Input:** digits = [0,2,2]

**Output:** 2

**Explanation:** The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.

**Example 3:**

**Input:** digits = [6,6,6]

**Output:** 1

**Explanation:** Only 666 can be formed.

**Example 4:**

**Input:** digits = [1,3,5]

**Output:** 0

**Explanation:** No even 3-digit numbers can be formed.

**Constraints:**

* `3 <= digits.length <= 10`
* `0 <= digits[i] <= 9`

---

## Solution & Editorial
# Intuition
To form a 3-digit number from a given set of digits, we need to select three digits such that the resulting number is even and does not have a leading zero. Since the input size is small (up to 10 digits), we can use backtracking to explore all valid permutations of length 3. To ensure we count only distinct numbers, we sort the input array and skip duplicate digits at the same recursion level.

# Approach
1. **Sort the Input**: Sorting the `digits` array is crucial for handling duplicates. By sorting, identical digits are adjacent, allowing us to skip redundant branches in the recursion tree.
2. **Backtracking**: We use a `backtrack` function that maintains the current number (`num`), the number of digits placed (`dig`), and a `vis` array to track used indices.
3. **Pruning & Constraints**:
   - **Leading Zero**: If `dig == 0` and `digits[i] == 0`, we skip this branch.
   - **Duplicates**: If `digits[i] == digits[i-1]` and the previous identical digit was not used in the current recursion level, we skip to avoid generating the same number multiple times.
   - **Base Case**: Once `dig == 3`, we check if `num % 2 == 0`. If true, we increment the `ans` counter.

### Visual Trace (Example: digits = [1, 2, 2])
| Step | Current Num | Digits Used | Result |
| :--- | :--- | :--- | :--- |
| 1 | 1 | {1} | - |
| 2 | 12 | {1, 2} | - |
| 3 | 122 | {1, 2, 2} | Even (Count=1) |
| 4 | 2 | {2} | - |
| 5 | 21 | {2, 1} | - |
| 6 | 212 | {2, 1, 2} | Even (Count=2) |

# Complexity
- Time complexity: $$O(P(N, 3)) = O(N^3)$$, where $$N$$ is the length of the input array. Since $$N \le 10$$, this is effectively constant time, exploring at most $$10 \times 9 \times 8 = 720$$ permutations.
- Space complexity: $$O(N)$$ due to the recursion stack depth of 3 and the `vis` array of size $$N$$.

# Code
```cpp
class Solution {
public:
    void backtrack(vector<int>& digits, vector<int>& vis, int& ans, int num, int dig) {
        if (dig == 3) {
            if (num % 2 == 0) ans++;
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (vis[i] == 1) continue; 
            if (dig == 0 && digits[i] == 0) continue;
            if (i > 0 && digits[i] == digits[i-1] && !vis[i-1]) continue;
            vis[i] = 1;
            backtrack(digits, vis, ans, num * 10 + digits[i], dig + 1);
            vis[i] = 0;
        }
    }
    
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        vector<int> vis(digits.size(), 0);
        sort(digits.begin(), digits.end());
        backtrack(digits, vis, ans, 0, 0);
        return ans;
    }
};
```

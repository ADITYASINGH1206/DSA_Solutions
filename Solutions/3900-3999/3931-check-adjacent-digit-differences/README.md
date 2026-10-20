# [3931. Check Adjacent Digit Differences](https://leetcode.com/problems/check-adjacent-digit-differences/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a string `s` consisting of digits.

Return `true` if the **absolute difference** between every pair of **adjacent** digits is at most 2, otherwise return `false`.

The absolute difference between `a` and `b` is defined as `abs(a - b)`.

**Example 1:**

**Input:** s = "132"

**Output:** true

**Explanation:**

* The absolute difference between digits at `s[0]` and `s[1]` is `abs(1 - 3) = 2`.
* The absolute difference between digits at `s[1]` and `s[2]` is `abs(3 - 2) = 1`.
* Since both differences are at most 2, the answer is true.

**Example 2:**

**Input:** s = "129"

**Output:** false

**Explanation:**

* The absolute difference between digits at `s[0]` and `s[1]` is `abs(1 - 2) = 1`.
* The absolute difference between digits at `s[1]` and `s[2]` is `abs(2 - 9) = 7`, which is greater than 2.
* Therefore, the answer is false.

**Constraints:**

* `2 <= s.length <= 100`
* `s` consists only of digits.

---

## Solution & Editorial
# Intuition
The problem requires verifying a local property (absolute difference $\le 2$) for all adjacent pairs in a string of digits. Since we only need to check each pair once, a single linear pass is sufficient to determine the validity of the entire string.

# Approach
1. Iterate through the string `s` from index `0` to `n-2`.
2. For each index `i`, calculate the absolute difference between the digit at `s[i]` and `s[i+1]` by converting characters to their integer values using `s[i] - '0'`.
3. If `abs((s[i] - '0') - (s[i+1] - '0'))` exceeds 2, immediately return `false`.
4. If the loop completes without finding any invalid pairs, return `true`.

### Visual Trace (Example: s = "132")
| Iteration (i) | s[i] | s[i+1] | Difference | Valid? |
| :--- | :--- | :--- | :--- | :--- |
| 0 | '1' | '3' | abs(1-3) = 2 | Yes |
| 1 | '3' | '2' | abs(3-2) = 1 | Yes |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass over the string, executing constant-time arithmetic operations at each step.
- Space complexity: $$O(1)$$, as we only use a few integer variables for indexing and calculation, regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for(int i = 0;i<n-1;i++){
            int dif = abs((s[i]-'0') - (s[i+1]-'0'));
            if(dif > 2) return false;
        }
        return true;
        
    }
};
```

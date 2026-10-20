# [3228. Maximum Number of Operations to Move Ones to the End](https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/)
**Difficulty:** `Medium` | **Tags:** `string`, `greedy`, `counting`

---

## Problem Description
You are given a binary string `s`.

You can perform the following operation on the string **any** number of times:

* Choose **any** index `i` from the string where `i + 1 < s.length` such that `s[i] == '1'` and `s[i + 1] == '0'`.
* Move the character `s[i]` to the **right** until it reaches the end of the string or another `'1'`. For example, for `s = "010010"`, if we choose `i = 1`, the resulting string will be `s = "000110"`.

Return the **maximum** number of operations that you can perform.

**Example 1:**

**Input:** s = "1001101"

**Output:** 4

**Explanation:**

We can perform the following operations:

* Choose index `i = 0`. The resulting string is `s = "0011101"`.
* Choose index `i = 4`. The resulting string is `s = "0011011"`.
* Choose index `i = 3`. The resulting string is `s = "0010111"`.
* Choose index `i = 2`. The resulting string is `s = "0001111"`.

**Example 2:**

**Input:** s = "00111"

**Output:** 0

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is either `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
The problem asks us to move '1's to the right past '0's. Notice that when we encounter a '0' that follows a '1', all '1's accumulated so far can "jump" over this '0'. Crucially, once a group of '1's moves past a '0', they effectively merge with any subsequent '1's, increasing the potential for future jumps.

# Approach
1. Maintain a counter `ones` to track the number of '1's encountered so far.
2. Iterate through the string `s`. If `s[i]` is '1', increment `ones`.
3. If `s[i]` is '0' and the previous character `s[i-1]` was a '1', it signifies a transition point where all currently accumulated `ones` can move past this '0'. Add the current `ones` count to the total `res`.
4. If `s[i]` is '0' but the previous character was also '0', no new operations are added because the '1's have already moved past the preceding '0's.

### Visual Trace (s = "1001101")
| Index | Char | `ones` | `res` | Action |
| :--- | :--- | :--- | :--- | :--- |
| 0 | '1' | 1 | 0 | Increment `ones` |
| 1 | '0' | 1 | 1 | `s[i-1]` was '1', add `ones` to `res` |
| 2 | '0' | 1 | 1 | `s[i-1]` was '0', skip |
| 3 | '1' | 2 | 1 | Increment `ones` |
| 4 | '1' | 3 | 1 | Increment `ones` |
| 5 | '0' | 3 | 4 | `s[i-1]` was '1', add `ones` to `res` |
| 6 | '1' | 4 | 4 | Increment `ones` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single linear scan.
- Space complexity: $$O(1)$$, as we only use two integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ones++;
            else if ((i > 0) && s[i - 1] == '1')
                res += ones;
        }

        return res;
    }
};
```

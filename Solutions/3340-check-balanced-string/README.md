# [3340. Check Balanced String](https://leetcode.com/problems/check-balanced-string/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a string `num` consisting of only digits. A string of digits is called **balanced** if the sum of the digits at even indices is equal to the sum of digits at odd indices.

Return `true` if `num` is **balanced**, otherwise return `false`.

**Example 1:**

**Input:** num = "1234"

**Output:** false

**Explanation:**

* The sum of digits at even indices is `1 + 3 == 4`, and the sum of digits at odd indices is `2 + 4 == 6`.
* Since 4 is not equal to 6, `num` is not balanced.

**Example 2:**

**Input:** num = "24123"

**Output:** true

**Explanation:**

* The sum of digits at even indices is `2 + 1 + 3 == 6`, and the sum of digits at odd indices is `4 + 2 == 6`.
* Since both are equal the `num` is balanced.

**Constraints:**

* `2 <= num.length <= 100`
* `num` consists of digits only

---

## Solution & Editorial
# Intuition
The problem asks us to compare the sum of digits at even indices with the sum of digits at odd indices. Since we only need to traverse the string once to accumulate these two sums, a simple linear scan is sufficient.

# Approach
1. Initialize two integer variables, `even` and `odd`, to zero.
2. Iterate through the string `num` using an index `i` from `0` to `n-1`.
3. For each character `num[i]`, convert it to its integer value by subtracting the character `'0'`.
4. Use the modulo operator `i % 2` to determine if the index is even or odd and add the value to the corresponding accumulator.
5. Finally, return the boolean result of `odd == even`.

### Visual Trace (Example 1: "1234")
| Index (i) | Value | Parity | Even Sum | Odd Sum |
|-----------|-------|--------|----------|---------|
| 0         | 1     | Even   | 1        | 0       |
| 1         | 2     | Odd    | 1        | 2       |
| 2         | 3     | Even   | 4        | 2       |
| 3         | 4     | Odd    | 4        | 6       |

Result: 4 == 6 is false.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use two integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool isBalanced(string num) {
        int odd = 0;
        int even = 0;
        int n = num.size();
        for(int i =0;i<n;i++){
            if(i%2 ==0) even +=( num[i] - '0');
            else odd += (num[i] - '0');
        }

        return odd == even;
    }
};
```

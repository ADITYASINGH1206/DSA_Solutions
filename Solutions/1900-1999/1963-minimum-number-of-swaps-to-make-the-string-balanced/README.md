# [1963. Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/)
**Difficulty:** `Medium` | **Tags:** `two-pointers`, `string`, `stack`, `greedy`, `bracket-sequences`

---

## Problem Description
You are given a **0-indexed** string `s` of **even** length `n`. The string consists of **exactly** `n / 2` opening brackets `'['` and `n / 2` closing brackets `']'`.

A string is called **balanced** if and only if:

* It is the empty string, or
* It can be written as `AB`, where both `A` and `B` are **balanced** strings, or
* It can be written as `[C]`, where `C` is a **balanced** string.

You may swap the brackets at **any** two indices **any** number of times.

Return *the **minimum** number of swaps to make* `s` ***balanced***.

**Example 1:**

```
Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
```

**Example 2:**

```
Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
```

**Example 3:**

```
Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
```

**Constraints:**

* `n == s.length`
* `2 <= n <= 106`
* `n` is even.
* `s[i]` is either `'['` or `']'`.
* The number of opening brackets `'['` equals `n / 2`, and the number of closing brackets `']'` equals `n / 2`.

---

## Solution & Editorial
# Intuition
To balance the string, we need to eliminate the "imbalance" caused by closing brackets that appear without a preceding opening bracket. By tracking the net count of open brackets, we can identify how many closing brackets are "unmatched" at any point. Since one swap can fix two unmatched closing brackets (by moving an opening bracket from the end to the front), the total number of swaps required is related to the maximum depth of the imbalance.

# Approach
1. Initialize a counter `size` to 0, which represents the current number of unmatched opening brackets.
2. Iterate through the string `s`. If we encounter an opening bracket `[` , increment `size`.
3. If we encounter a closing bracket `]` and `size > 0`, it means this closing bracket can be matched with a previous opening bracket, so decrement `size`.
4. After the loop, `size` represents the number of unmatched opening brackets remaining. Because each swap resolves two imbalances (one `[` and one `]`), the minimum swaps needed is `(size + 1) / 2`.

### Visual Trace (Example 2: "]]][[[")
| Index | Char | size (before) | Action | size (after) |
|-------|------|---------------|--------|--------------|
| 0     | ]    | 0             | None   | 0            |
| 1     | ]    | 0             | None   | 0            |
| 2     | ]    | 0             | None   | 0            |
| 3     | [    | 0             | Inc    | 1            |
| 4     | [    | 1             | Inc    | 2            |
| 5     | [    | 2             | Inc    | 3            |

Result: (3 + 1) / 2 = 2 swaps.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single linear scan.
- Space complexity: $$O(1)$$, as we only use a single integer variable to track the state.

# Code
```cpp
class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '[')
                size++;
            else if (size > 0) 
                size--;
        }
        return (size + 1) / 2;
    }
};
```

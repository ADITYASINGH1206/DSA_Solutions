# [1247. Minimum Swaps to Make Strings Equal](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/)
**Difficulty:** `Medium` | **Tags:** `math`, `string`, `greedy`

---

## Problem Description
You are given two strings `s1` and `s2` of equal length consisting of letters `"x"` and `"y"` **only**. Your task is to make these two strings equal to each other. You can swap any two characters that belong to **different** strings, which means: swap `s1[i]` and `s2[j]`.

Return the minimum number of swaps required to make `s1` and `s2` equal, or return `-1` if it is impossible to do so.

**Example 1:**

```
Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
```

**Example 2:**

```
Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
```

**Example 3:**

```
Input: s1 = "xx", s2 = "xy"
Output: -1
```

**Constraints:**

* `1 <= s1.length, s2.length <= 1000`
* `s1.length == s2.length`
* `s1, s2` only contain `'x'` or `'y'`.

---

## Solution & Editorial
# Intuition
We want to make two strings `s1` and `s2` equal by swapping characters between them. Since indices where `s1[i] == s2[i]` are already correct, we only care about mismatched indices where `s1[i] != s2[i]`. At any mismatched position, the pair of characters can either be `('x', 'y')` or `('y', 'x')`. We can count these discrepancies and greedily pair them up to minimize the total number of swaps.

# Approach
1. Iterate through both strings from index `0` to `n - 1` using a single loop.
2. Count mismatches where `s1[i] == 'x' && s2[i] == 'y'` and store in variable `xy`.
3. Count mismatches where `s1[i] == 'y' && s2[i] == 'x'` and store in variable `yx`.
4. Check if the total sum of mismatches `xy + yx` is odd. If it is odd, it is impossible to pair them up completely, so return `-1`.
5. If the total sum is even, calculate the minimum swaps: pairs of `('xy', 'xy')` take `1` swap (`xy / 2`), pairs of `('yx', 'yx')` take `1` swap (`yx / 2`), and if there is one leftover `xy` and one leftover `yx`, they can be fixed in `2` swaps (`(xy % 2) * 2`).

### Visual Walkthrough (Example 2: s1 = "xy", s2 = "yx")
- Iteration: 
  - `i = 0`: `s1[0] = 'x', s2[0] = 'y'` $ightarrow$ `xy = 1`
  - `i = 1`: `s1[1] = 'y', s2[1] = 'x'` $ightarrow$ `yx = 1`
- Check parity: `xy + yx = 2` (Even, valid)
- Swap calculation: `xy/2 + yx/2 + (xy%2)*2 = 0 + 0 + 2 = 2`
- Output: `2`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of strings `s1` and `s2`. We traverse the strings once to count mismatches.
- Space complexity: $$O(1)$$ as only a few scalar variables (`xy`, `yx`, `n`) are used for counting.

# Code
```cpp
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0;
        int yx = 0;
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(s1[i] == 'x' && s2[i] == 'y') xy++;
            if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }
        if((xy+yx)%2) return -1;
        return xy/2 + yx/2 + (xy%2)*2;
    }
};
```

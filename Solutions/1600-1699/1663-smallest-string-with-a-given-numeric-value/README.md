# [1663. Smallest String With A Given Numeric Value](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/)
**Difficulty:** `Medium` | **Tags:** `string`, `greedy`

---

## Problem Description
The **numeric value** of a **lowercase character** is defined as its position `(1-indexed)` in the alphabet, so the numeric value of `a` is `1`, the numeric value of `b` is `2`, the numeric value of `c` is `3`, and so on.

The **numeric value** of a **string** consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string `"abe"` is equal to `1 + 2 + 5 = 8`.

You are given two integers `n` and `k`. Return *the **lexicographically smallest string** with **length** equal to `n` and **numeric value** equal to `k`.*

Note that a string `x` is lexicographically smaller than string `y` if `x` comes before `y` in dictionary order, that is, either `x` is a prefix of `y`, or if `i` is the first position such that `x[i] != y[i]`, then `x[i]` comes before `y[i]` in alphabetic order.

**Example 1:**

```
Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
```

**Example 2:**

```
Input: n = 5, k = 73
Output: "aaszz"
```

**Constraints:**

* `1 <= n <= 105`
* `n <= k <= 26 * n`

---

## Solution & Editorial
# Intuition
To construct the lexicographically smallest string of length `n` with a total numeric value `k`, we must prioritize placing the smallest possible characters ('a') at the beginning of the string. Since each character must have a value of at least 1, we start by filling the string with 'a's and then greedily distribute the remaining value from the end of the string towards the front to maximize the values of the trailing characters.

# Approach
1. Initialize a string `s` of length `n` filled with 'a's. This accounts for the minimum possible value of `n` (since each 'a' is 1).
2. Calculate the remaining value to distribute: `k = k - n`.
3. Iterate from the end of the string (`i = n - 1`) to the beginning. For each position, determine how much of the remaining `k` can be added to the current 'a' (which already has a value of 1).
4. If `k` is less than 25, add the entire remaining `k` to the current character and set `k = 0`.
5. If `k` is 25 or greater, set the current character to 'z' (which is 'a' + 25) and subtract 25 from `k`.

### Visual Trace (n=3, k=27)
- Initial: `s = "aaa"`, `k = 27 - 3 = 24`
- i=2: `k=24`. Since `24 < 25`, `s[2] = 'a' + 24 = 'y'`. `k` becomes 0.
- Result: `"aay"`

# Complexity
- Time complexity: $$O(n)$$, as we perform a single pass to initialize the string and a single pass to update the characters.
- Space complexity: $$O(n)$$, required to store the resulting string of length `n`.

# Code
```cpp
class Solution {
public:
    string getSmallestString(int n, int k) {
        string s="";
        for(int i=0;i<n;i++)s+='a';
        k=k-n;
        for(int i=n-1;i>=0;i--){
            if(k==0)break;
            else if(k<25){
                s[i] = (char)('a'+k);          
                k=0;
            }
            else{
                s[i] = (char)('a'+25);
                k = k - 25;
            }
        }
        return s;
    }
};
```

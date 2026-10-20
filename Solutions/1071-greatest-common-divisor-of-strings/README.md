# [1071. Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`, `euclidean-algorithm`, `greatest-common-divisor`

---

## Problem Description
For two strings `s` and `t`, we say "`t` divides `s`" if and only if `s = t + t + t + ... + t + t` (i.e., `t` is concatenated with itself one or more times).

Given two strings `str1` and `str2`, return *the largest string* `x` *such that* `x` *divides both* `str1` *and* `str2`.

**Example 1:**

**Input:** str1 = "ABCABC", str2 = "ABC"

**Output:** "ABC"

**Example 2:**

**Input:** str1 = "ABABAB", str2 = "ABAB"

**Output:** "AB"

**Example 3:**

**Input:** str1 = "LEET", str2 = "CODE"

**Output:** ""

**Example 4:**

**Input:** str1 = "AAAAAB", str2 = "AAA"

**Output:** ""​​​​​​​

**Constraints:**

* `1 <= str1.length, str2.length <= 1000`
* `str1` and `str2` consist of English uppercase letters.

---

## Solution & Editorial
# Intuition
If two strings share a common divisor string, their concatenation must be commutative. That is, `str1 + str2` must equal `str2 + str1`. Furthermore, the length of the largest common divisor string must have a length equal to the greatest common divisor (GCD) of the lengths of `str1` and `str2`.

# Approach
1. Check if `str1 + str2` is equal to `str2 + str1`. If they are not equal, it implies no common divisor string exists, so return an empty string `""`.
2. Compute the greatest common divisor of the lengths of the two strings using `std::gcd(str1.size(), str2.size())`.
3. Extract and return the prefix of `str1` of length equal to the computed GCD using `str1.substr(0, gcdLength)`.

### Visual Trace Walkthrough (Example 1)
- `str1` = "ABCABC", `str2` = "ABC"
- `str1 + str2` = "ABCABCABC"
- `str2 + str1` = "ABCABCABC"
- Equality check passes.
- `gcd(6, 3)` = `3`.
- Substring `str1.substr(0, 3)` returns "ABC".

# Complexity
- Time complexity: $$O(N + M)$$ where $$N$$ and $$M$$ are the lengths of `str1` and `str2`. The string concatenation check takes $$O(N + M)$$ time, and string comparison takes proportional time.
- Space complexity: $$O(N + M)$$ auxiliary space required to store the concatenated temporary string objects during the equality comparison.

# Code
```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int gcdLength =gcd(str1.size(), str2.size());
        
        return str1.substr(0, gcdLength);
    }
};
```

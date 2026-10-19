# [709. To Lower Case](https://leetcode.com/problems/to-lower-case/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
Given a string `s`, return *the string after replacing every uppercase letter with the same lowercase letter*.

**Example 1:**

```
Input: s = "Hello"
Output: "hello"
```

**Example 2:**

```
Input: s = "here"
Output: "here"
```

**Example 3:**

```
Input: s = "LOVELY"
Output: "lovely"
```

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists of printable ASCII characters.

---

## Solution & Editorial
# Intuition
The problem requires transforming all uppercase English letters in a given string to their corresponding lowercase equivalents while leaving all other characters unchanged. Since strings in C++ are mutable, we can iterate through the string by reference and apply a standard character transformation method to each element in place.

# Approach
1. Iterate over every character `x` in the string `s` by reference (`auto& x`) to allow in-place modification.
2. For each character `x`, invoke the standard library function `tolower(x)` which handles uppercase-to-lowercase conversion safely, leaving non-alphabetic characters untouched.
3. Return the modified string `s`.

### Visual Trace Walkthrough
For Example 1: `s = "Hello"`
- Initial: `s = "Hello"`
- Iteration 1 (`x = 'H'`): `tolower('H')` returns `'h'`, `s = "hello"`
- Iteration 2 (`x = 'e'`): `tolower('e')` returns `'e'`, `s = "hello"`
- Iteration 3 (`x = 'l'`): `tolower('l')` returns `'l'`, `s = "hello"`
- Iteration 4 (`x = 'l'`): `tolower('l')` returns `'l'`, `s = "hello"`
- Iteration 5 (`x = 'o'`): `tolower('o')` returns `'o'`, `s = "hello"`
- Final Result: `"hello"`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of string `s`. We perform a single linear scan over the string, visiting each character exactly once.
- Space complexity: $$O(1)$$, as the transformation is performed entirely in-place without allocating any auxiliary data structures.

# Code
```cpp
class Solution {
public:
    string toLowerCase(string s) {
        for(auto& x :s){
            x= tolower(x);
        }
        return s;
    }
};
```

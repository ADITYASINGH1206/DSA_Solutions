# [744. Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)
**Difficulty:** `Easy` | **Tags:** `array`, `binary-search`

---

## Problem Description
You are given an array of characters `letters` that is sorted in **non-decreasing order**, and a character `target`. There are **at least two different** characters in `letters`.

Return *the smallest character in* `letters` *that is lexicographically greater than* `target`. If such a character does not exist, return the first character in `letters`.

**Example 1:**

```
Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
```

**Example 2:**

```
Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
```

**Example 3:**

```
Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
```

**Constraints:**

* `2 <= letters.length <= 104`
* `letters[i]` is a lowercase English letter.
* `letters` is sorted in **non-decreasing** order.
* `letters` contains at least two different characters.
* `target` is a lowercase English letter.

---

## Solution & Editorial
# Intuition
The problem asks us to find the smallest character strictly greater than the given `target` in a sorted array `letters`. Since the array is already sorted in non-decreasing order, this maps directly to finding the upper bound of `target` using binary search. If all characters are less than or equal to `target`, the condition wraps around and returns the first element of the array.

# Approach
1. Use the standard library function `upper_bound` to find the first iterator in `letters` that is strictly greater than `target`.
2. Convert the resulting iterator to an integer index `i` by subtracting `letters.begin()`.
3. Return `letters[i % letters.size()]`. The modulo operator gracefully handles the wrap-around case where `upper_bound` points past the end of the array (i.e., `i == letters.size()`), mapping it back to index `0`.

### Visual Walkthrough (Example 2: letters = ["c","f","j"], target = "c")
- `upper_bound` scans `letters` and finds the first element strictly greater than `'c'`, which is `'f'` at index `1`.
- `i = 1`.
- `letters[1 % 3]` evaluates to `letters[1]`, which is `'f'`.

### Visual Walkthrough (Example 3: letters = ["x","x","y","y"], target = "z")
- `upper_bound` finds no element greater than `'z'`, returning `letters.end()`, so `i = 4`.
- `letters[4 % 4]` evaluates to `letters[0]`, which is `'x'`.

# Complexity
- Time complexity: $$O(\log N)$$ where $$N$$ is the size of `letters`. The `upper_bound` function performs a binary search over the sorted array.
- Space complexity: $$O(1)$$ auxiliary space since only a few scalar variables are used.

# Code
```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        return letters[i % letters.size()];
    }
};
```

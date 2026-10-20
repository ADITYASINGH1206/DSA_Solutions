# [1081. Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `greedy`, `monotonic-stack`

---

## Problem Description
Given a string `s`, return *the* *lexicographically smallest* *subsequence* *of* `s` *that contains all the distinct characters of* `s` *exactly once*.

**Example 1:**

```
Input: s = "bcabc"
Output: "abc"
```

**Example 2:**

```
Input: s = "cbacdcbc"
Output: "acdb"
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consists of lowercase English letters.

**Note:** This question is the same as 316: <https://leetcode.com/problems/remove-duplicate-letters/>

---

## Solution & Editorial
# Intuition
The problem asks for the lexicographically smallest subsequence of $s$ that contains all distinct characters of $s$ exactly once. To achieve this, we can greedily build our result using a monotonic stack. If we encounter a character that is smaller than the characters currently at the top of our stack, and those larger characters appear later in the string, it is always optimal to pop them to make room for the smaller character earlier in the sequence.

# Approach
1. Count the frequency of each character in $s$ using an integer array `freq` of size 27.
2. Maintain a `stack` (implemented as a `std::string`) to build the lexicographically smallest subsequence and a `std::bitset<27> seen` to keep track of characters currently inside the stack.
3. Iterate through each character `c` in $s$:
   - Decrement `freq[x]` where `x = c & 31` (representing the 1-based or relative alphabet index).
   - If `c` is already present in `seen`, skip it.
   - While the `stack` is not empty, the top of the stack is lexicographically greater than `c`, and the frequency of the top character is greater than 0 (meaning it appears later in the string), remove the top character from the stack and unset its bit in `seen`.
   - Push `c` into the `stack` and mark its bit in `seen`.
4. Return the resulting `stack` string.

### Visual Walkthrough (Example 1: s = "bcabc")
- Character frequencies: a:2, b:2, c:1
- Iterate `c = 'b'`: `stack = "b"`, `seen = {b}`
- Iterate `c = 'c'`: `stack = "bc"`, `seen = {b, c}`
- Iterate `c = 'a'`: 
  - Top is 'c' > 'a' and `freq['c'] > 0`? No (`freq['c'] = 0`). Do not pop 'c'.
  - Top is 'b' > 'a' and `freq['b'] > 0` (`freq['b'] = 1`). Pop 'b'.
  - `stack = "ac"`, `seen = {a, c}`
- Iterate `c = 'b'`: `stack = "acb"`, `seen = {a, b, c}`
- Iterate `c = 'c'`: Already in `seen`. Skip.

# Complexity
- Time complexity: $$O(N)$$ — Each character is pushed and popped from the stack at most once, and frequency calculation takes linear time.
- Space complexity: $$O(1)$$ — The alphabet size is fixed at 26, requiring constant extra space for `freq`, `seen`, and the result stack relative to the input length.

# Code
```cpp
class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[27] = {0};
        bitset<27> seen;
        string stack;

        for (auto& c : s)
            freq[c & 31]++;

        for (auto& c : s) {
            int x = c & 31;
            freq[x]--;

            if (seen.test(x))
                continue;

            while (stack.length() && stack.back() > c && freq[stack.back() & 31]) {
                seen.reset(stack.back() & 31);
                stack.pop_back();
            }

            stack.push_back(c);
            seen.set(x);
        }

        return stack;
    }
};
```

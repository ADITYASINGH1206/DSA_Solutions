# [3746. Minimum String Length After Balanced Removals](https://leetcode.com/problems/minimum-string-length-after-balanced-removals/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `counting`

---

## Problem Description
You are given a string `s` consisting only of the characters `'a'` and `'b'`.

You are allowed to repeatedly remove **any substring** where the number of `'a'` characters is equal to the number of `'b'` characters. After each removal, the remaining parts of the string are concatenated together without gaps.

Return an integer denoting the **minimum possible length** of the string after performing any number of such operations.

**Example 1:**

**Input:** s = `"aabbab"`

**Output:** 0

**Explanation:**

The substring `"aabbab"` has three `'a'` and three `'b'`. Since their counts are equal, we can remove the entire string directly. The minimum length is 0.

**Example 2:**

**Input:** s = `"aaaa"`

**Output:** 4

**Explanation:**

Every substring of `"aaaa"` contains only `'a'` characters. No substring can be removed as a result, so the minimum length remains 4.

**Example 3:**

**Input:** s = `"aaabb"`

**Output:** 1

**Explanation:**

First, remove the substring `"ab"`, leaving `"aab"`. Next, remove the new substring `"ab"`, leaving `"a"`. No further removals are possible, so the minimum length is 1.

**Constraints:**

* `1 <= s.length <= 105`
* `s[i]` is either `'a'` or `'b'`.

---

## Solution & Editorial
# Intuition
The problem allows removing any substring with an equal count of 'a's and 'b's. A key observation is that any such substring can be reduced to a sequence of adjacent 'ab' or 'ba' pairs. By using a stack, we can greedily match incoming characters with the top of the stack whenever they differ, effectively eliminating balanced pairs until only a sequence of identical characters remains.

# Approach
1. Initialize an empty stack `st` to store characters that cannot be immediately paired.
2. Iterate through the string `s` using index `i`.
3. For each character `s[i]`, check if the stack is non-empty and if the top of the stack is different from `s[i]`.
4. If they differ, it means we have found a balanced pair (e.g., 'ab' or 'ba'). Pop the stack and increment `i` to consume the current character.
5. If they are the same or the stack is empty, push `s[i]` onto the stack.
6. The final size of the stack represents the minimum length, as no more balanced substrings can be formed.

### Visual Trace (Example 3: "aaabb")
| Step | Current Char | Stack State | Action |
| :--- | :--- | :--- | :--- |
| 1 | 'a' | ['a'] | Push |
| 2 | 'a' | ['a', 'a'] | Push |
| 3 | 'a' | ['a', 'a', 'a'] | Push |
| 4 | 'b' | ['a', 'a'] | Pop (match 'ab') |
| 5 | 'b' | ['a'] | Pop (match 'ab') |
Final Stack Size: 1

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. Each character is pushed onto and popped from the stack at most once.
- Space complexity: $$O(N)$$ in the worst case (e.g., "aaaaa"), where all characters are stored in the stack.

# Code
```cpp
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            while (!st.empty() and s[i] != st.top()) {
                if (i >= s.size()) break;
                st.pop();
                i++;
            }
            if (i < s.size())
            st.push(s[i]);
        }
        return st.size();
    }
};
```

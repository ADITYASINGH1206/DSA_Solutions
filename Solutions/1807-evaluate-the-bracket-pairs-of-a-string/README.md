# [1807. Evaluate the Bracket Pairs of a String](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `string`

---

## Problem Description
You are given a string `s` that contains some bracket pairs, with each pair containing a **non-empty** key.

* For example, in the string `"(name)is(age)yearsold"`, there are **two** bracket pairs that contain the keys `"name"` and `"age"`.

You know the values of a wide range of keys. This is represented by a 2D string array `knowledge` where each `knowledge[i] = [keyi, valuei]` indicates that key `keyi` has a value of `valuei`.

You are tasked to evaluate **all** of the bracket pairs. When you evaluate a bracket pair that contains some key `keyi`, you will:

* Replace `keyi` and the bracket pair with the key's corresponding `valuei`.
* If you do not know the value of the key, you will replace `keyi` and the bracket pair with a question mark `"?"` (without the quotation marks).

Each key will appear at most once in your `knowledge`. There will not be any nested brackets in `s`.

Return *the resulting string after evaluating **all** of the bracket pairs.*

**Example 1:**

```
Input: s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
Output: "bobistwoyearsold"
Explanation:
The key "name" has a value of "bob", so replace "(name)" with "bob".
The key "age" has a value of "two", so replace "(age)" with "two".
```

**Example 2:**

```
Input: s = "hi(name)", knowledge = [["a","b"]]
Output: "hi?"
Explanation: As you do not know the value of the key "name", replace "(name)" with "?".
```

**Example 3:**

```
Input: s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
Output: "yesyesyesaaa"
Explanation: The same key can appear multiple times.
The key "a" has a value of "yes", so replace all occurrences of "(a)" with "yes".
Notice that the "a"s not in a bracket pair are not evaluated.
```

**Constraints:**

* `1 <= s.length <= 105`
* `0 <= knowledge.length <= 105`
* `knowledge[i].length == 2`
* `1 <= keyi.length, valuei.length <= 10`
* `s` consists of lowercase English letters and round brackets `'('` and `')'`.
* Every open bracket `'('` in `s` will have a corresponding close bracket `')'`.
* The key in each bracket pair of `s` will be non-empty.
* There will not be any nested bracket pairs in `s`.
* `keyi` and `valuei` consist of lowercase English letters.
* Each `keyi` in `knowledge` is unique.

---

## Solution & Editorial
# Intuition
To efficiently evaluate bracket pairs, we need to map each key to its corresponding value for constant-time retrieval. Since the string `s` contains non-nested brackets, we can process the string linearly, identifying keys within parentheses and replacing them using a hash map.

# Approach
1. **Map Construction**: Populate an `unordered_map<string, string>` with the `knowledge` array. This allows $O(1)$ average time complexity for key lookups.
2. **Linear Scan**: Iterate through the string `s` using an index `i`.
   - If `s[i]` is not `'('`, append the character directly to the result string `res`.
   - If `s[i]` is `'('`, find the closing bracket `')'` at index `j`. Extract the substring between `i` and `j` as the key.
   - Check the map for the key. If found, append the value; otherwise, append `'?'`.
   - Update `i` to `j` to skip the processed bracket pair.

### Visual Trace (Example 1: s = "(name)is", knowledge = [["name", "bob"]])
| Index (i) | Char | Action | Result (res) |
| :--- | :--- | :--- | :--- |
| 0 | '(' | Find ')' at 5, key="name" | "bob" |
| 5 | ')' | Skip | "bob" |
| 6 | 'i' | Append | "bobi" |
| 7 | 's' | Append | "bobis" |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the length of string `s` and $$M$$ is the total number of characters in the `knowledge` array. We traverse `s` once and perform constant-time map lookups.
- Space complexity: $$O(M)$$, required to store the `knowledge` pairs in the hash map.

# Code
```cpp
class Solution {
public:
    string evaluate(string s, auto& K) {
        unordered_map<string, string> d;
        for (auto& k : K)
            d[k[0]] = k[1];

        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                int j = s.find(")", i + 1);
                auto t = s.substr(i + 1, j - i - 1);
                res += d.count(t) ? d[t] : "?";
                i = j;
            } else
                res += s[i];
        }

        return res;
    }
};
```

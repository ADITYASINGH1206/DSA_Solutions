# [402. Remove K Digits](https://leetcode.com/problems/remove-k-digits/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `greedy`, `monotonic-stack`

---

## Problem Description
Given string num representing a non-negative integer `num`, and an integer `k`, return *the smallest possible integer after removing* `k` *digits from* `num`.

**Example 1:**

```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```

**Example 2:**

```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```

**Example 3:**

```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```

**Constraints:**

* `1 <= k <= num.length <= 105`
* `num` consists of only digits.
* `num` does not have any leading zeros except for the zero itself.

---

## Solution & Editorial
# Intuition
The problem asks us to find the smallest possible integer by removing exactly $k$ digits from a given string representation of a number. To make a number as small as possible, higher place values must be minimized. Consequently, if a digit is larger than the digit immediately following it, removing the larger (left) digit results in a smaller number at that higher place value.

# Approach
1. Maintain a string `ans` acting as a monotonic increasing stack of characters.
2. Iterate through each character `c` in the input string `num`.
3. While `ans` is not empty, we have not yet removed $k$ digits (`count < k`), and the last element of `ans` is greater than the current character `c` (`ans.back() > c`), pop the last element from `ans` and increment `count`.
4. Append the current character `c` to `ans`.
5. If we finish iterating through `num` and still have remaining removals to perform (`count < k`), continue popping from the back of `ans`.
6. Strip any leading zeros from `ans`. If the resulting string is empty or contains only zeros, return ""0"". Otherwise, return the cleaned string.

### Visual Walkthrough (Example 1: num = "1432219", k = 3)

| Character `c` | Stack `ans` before pop | Action | Stack `ans` after operation | `count` |
| :---: | :---: | :---: | :---: | :---: |
| '1' | "" | Push '1' | "1" | 0 |
| '4' | "1" | Push '4' | "14" | 0 |
| '3' | "14" | Pop '4' (since '4' > '3') | "13" | 1 |
| '2' | "13" | Pop '3' (since '3' > '2') | "12" | 2 |
| '2' | "12" | Push '2' (not > '2') | "122" | 2 |
| '1' | "122" | Pop '2', then pop '2' | "11" | 4 (Stop, k=3 reached) ||
| '9' | "12" | Push '9' | "129" | 3 |

After loop, since `count < k` is false, leading zeros check passes, final output is "1219".

# Complexity
- Time complexity: $$O(N)$$ — Each character is pushed onto and popped from the string stack at most once, where $N$ is the length of `num`. Finding leading zeros and substring operations take linear time.
- Space complexity: $$O(N)$$ — Auxiliary storage required for the result string `ans` in the worst-case scenario.

# Code
```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int n = num.size();
        int count = 0;
        for (char c : num) {
            if (ans.empty()) {
                ans += c;
            } else {
                while (!ans.empty() && count < k && ans.back() > c) {
                    ans.pop_back();
                    count++;
                }
                ans.push_back(c);
            }

        }
        while (count < k && !ans.empty()) {
            ans.pop_back();
            count++;
        }
        size_t first_nonzero = ans.find_first_not_of('0');
        if (first_nonzero == string::npos) {
            return "0";
        }
        return ans.substr(first_nonzero);
    }
};
```

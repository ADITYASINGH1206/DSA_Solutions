# [2375. Construct Smallest Number From DI String](https://leetcode.com/problems/construct-smallest-number-from-di-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `backtracking`, `stack`, `greedy`

---

## Problem Description
You are given a **0-indexed** string `pattern` of length `n` consisting of the characters `'I'` meaning **increasing** and `'D'` meaning **decreasing**.

A **0-indexed** string `num` of length `n + 1` is created using the following conditions:

* `num` consists of the digits `'1'` to `'9'`, where each digit is used **at most** once.
* If `pattern[i] == 'I'`, then `num[i] < num[i + 1]`.
* If `pattern[i] == 'D'`, then `num[i] > num[i + 1]`.

Return *the lexicographically **smallest** possible string* `num` *that meets the conditions.*

**Example 1:**

```
Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
```

**Example 2:**

```
Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.
```

**Constraints:**

* `1 <= pattern.length <= 8`
* `pattern` consists of only the letters `'I'` and `'D'`.

---

## Solution & Editorial
# Intuition
To construct the lexicographically smallest number, we want to place smaller digits as early as possible. When we encounter an 'I' (increasing), we can safely place the next available smallest digit. However, when we encounter a 'D' (decreasing), we must defer placing the current digit until we reach the end of the decreasing sequence, effectively reversing the order of digits in that segment to satisfy the constraint.

# Approach
1. We iterate from `1` to `n + 1` (where `n` is the length of the pattern). We treat these numbers as the pool of available digits.
2. We push each number onto a `stack`. 
3. Whenever we encounter an 'I' in the pattern or reach the end of the loop, we know the current decreasing sequence (if any) has ended. We pop all elements from the `stack` and append them to our result string `ans`.
4. This stack-based approach naturally reverses segments of digits corresponding to 'D' sequences, ensuring the smallest possible digits are used while maintaining the relative order required by the pattern.

### Visual Trace (Example: "IIID")
| Iteration (i) | Push | Pattern[i-1] | Stack State | Result (ans) |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | I | [1] | "1" |
| 2 | 2 | I | [2] | "12" |
| 3 | 3 | I | [3] | "123" |
| 4 | 4 | D | [3, 4] | "123" |
| 5 (End) | 5 | - | [3, 4, 5] | "12354" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the pattern. We iterate through the numbers once, and each number is pushed and popped from the stack exactly once.
- Space complexity: $$O(N)$$ to store the result string and the stack, which holds at most $$N+1$$ elements.

# Code
```cpp
class Solution {
public:
    string smallestNumber(string pattern) {
        string ans = "";
        stack<int> st;
        int n = pattern.size();
        
        for (int i = 1; i <= n + 1; i++) {
            st.push(i);
            if (i == n + 1 || pattern[i - 1] == 'I') {
                while (!st.empty()) {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        return ans;
    }
};
```

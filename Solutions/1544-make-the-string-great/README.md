# [1544. Make The String Great](https://leetcode.com/problems/make-the-string-great/)
**Difficulty:** `Easy` | **Tags:** `string`, `stack`

---

## Problem Description
Given a string `s` of lower and upper case English letters.

A good string is a string which doesn't have **two adjacent characters** `s[i]` and `s[i + 1]` where:

* `0 <= i <= s.length - 2`
* `s[i]` is a lower-case letter and `s[i + 1]` is the same letter but in upper-case or **vice-versa**.

To make the string good, you can choose **two adjacent** characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return *the string* after making it good. The answer is guaranteed to be unique under the given constraints.

**Notice** that an empty string is also good.

**Example 1:**

```
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
```

**Example 2:**

```
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""
```

**Example 3:**

```
Input: s = "s"
Output: "s"
```

**Constraints:**

* `1 <= s.length <= 100`
* `s` contains only lower and upper case English letters.

---

## Solution & Editorial
# Intuition
The problem requires removing adjacent pairs of characters that are the same letter but different cases. Since removing a pair can bring two previously non-adjacent characters together, a stack-based approach is ideal to maintain the current state of the "good" string efficiently.

# Approach
1. Initialize an empty string `ans` to act as a stack.
2. Iterate through each character `s[i]` in the input string.
3. For each character, check if `ans` is empty. If it is, push `s[i]` onto `ans`.
4. If `ans` is not empty, compare `s[i]` with the last character in `ans` (`ans.back()`):
   - If they are the same letter but different cases (checked by `tolower(s[i]) == tolower(ans.back())` and `s[i] != ans.back()`), they form a "bad" pair. Pop the last character from `ans`.
   - Otherwise, push `s[i]` onto `ans`.
5. Return the final `ans` string.

### Visual Trace (Example: "leEeetcode")
| Iteration | Current Char | Stack (`ans`) | Action |
| :--- | :--- | :--- | :--- |
| 0 | 'l' | "l" | Push |
| 1 | 'e' | "le" | Push |
| 2 | 'E' | "l" | Pop ('e' and 'E' match) |
| 3 | 'e' | "le" | Push |
| 4 | 'e' | "lee" | Push |
| 5 | 't' | "leet" | Push |
| ... | ... | ... | ... |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We iterate through the string exactly once, and each character is pushed and popped from the stack at most once.
- Space complexity: $$O(N)$$ in the worst case (e.g., "abcdef"), where the stack stores all characters of the input string.

# Code
```cpp
class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        int n = s.size();
        for(int i =0;i<n;i++){
            if(ans.empty()){
                ans.push_back(s[i]);
            }else{
                if(s[i] != ans.back() && tolower(s[i]) == tolower(ans.back())){
                    ans.pop_back();
                }else{
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};
```

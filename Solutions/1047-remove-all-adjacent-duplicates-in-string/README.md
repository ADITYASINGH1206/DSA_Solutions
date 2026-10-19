# [1047. Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
**Difficulty:** `Easy` | **Tags:** `string`, `stack`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make **duplicate removals** on `s` until we no longer can.

Return *the final string after all such duplicate removals have been made*. It can be proven that the answer is **unique**.

**Example 1:**

```
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
```

**Example 2:**

```
Input: s = "azxxzy"
Output: "ay"
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
When processing adjacent elements for cancellation or reduction, a stack-based approach is ideal. Since we only need to compare the current character with the most recently added character, a string used as a stack allows us to maintain elements in linear time without extra stack overhead.

# Approach
1. Initialize an empty string `ans` to serve as our stack and a variable `n` to store the size of `s`.
2. Iterate through each character `s[i]` of the input string from left to right.
3. If `ans` is empty or if the current character `s[i]` does not match the top element of `ans` (`ans.back()`), append `s[i]` to `ans` using `push_back`.
4. If the current character `s[i]` matches `ans.back()`, pop the top element from `ans` using `pop_back()` to eliminate the adjacent duplicate pair.
5. Return the resulting string `ans` after processing all characters.

### Visual Walkthrough for `s = "abbaca"`

| Index `i` | Character `s[i]` | Action | `ans` state before | `ans` state after |
| :---: | :---: | :--- | :--- | :--- |
| 0 | 'a' | Empty stack, push | `""` | `"a"` |
| 1 | 'b' | No match, push | `"a"` | `"ab"` |
| 2 | 'b' | Match `ans.back()`, pop | `"abb"` | `"a"` |
| 3 | 'a' | Match `ans.back()`, pop | `"aa"` | `""` |
| 4 | 'c' | Empty stack, push | `""` | `"c"` |
| 5 | 'a' | No match, push | `"c"` | `"ca"` |

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the string of length $$N$$ exactly once, performing constant time $$O(1)$$ string operations (`push_back`, `pop_back`, `back`) at each step.
- Space complexity: $$O(N)$$ — In the worst-case scenario where no duplicates exist, the auxiliary string `ans` stores all $$N$$ characters.

# Code
```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int n = s.size();
        for(int i =0;i<n;i++){
            if(ans.empty()){
                ans.push_back(s[i]);
            }
            else{
                if(s[i] == ans.back()) ans.pop_back();
                else{
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};
```

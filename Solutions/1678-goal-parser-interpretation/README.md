# [1678. Goal Parser Interpretation](https://leetcode.com/problems/goal-parser-interpretation/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You own a **Goal Parser** that can interpret a string `command`. The `command` consists of an alphabet of `"G"`, `"()"` and/or `"(al)"` in some order. The Goal Parser will interpret `"G"` as the string `"G"`, `"()"` as the string `"o"`, and `"(al)"` as the string `"al"`. The interpreted strings are then concatenated in the original order.

Given the string `command`, return *the **Goal Parser**'s interpretation of* `command`.

**Example 1:**

```
Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
```

**Example 2:**

```
Input: command = "G()()()()(al)"
Output: "Gooooal"
```

**Example 3:**

```
Input: command = "(al)G(al)()()G"
Output: "alGalooG"
```

**Constraints:**

* `1 <= command.length <= 100`
* `command` consists of `"G"`, `"()"`, and/or `"(al)"` in some order.

---

## Solution & Editorial
# Intuition
The problem requires a simple transformation of specific patterns within a string. Since the patterns "G", "()", and "(al)" are uniquely identifiable by their starting characters, we can process the string in a single linear pass.

# Approach
1. Initialize an empty string `ans` to store the result.
2. Iterate through the `command` string using an index `i`.
3. If `command[i]` is 'G', append 'G' to `ans`.
4. If `command[i]` is '(', check the next character `command[i+1]`:
   - If it is ')', append 'o' to `ans` and increment `i` by 1 to skip the closing parenthesis.
   - If it is 'a', append 'al' to `ans` and increment `i` by 3 to skip the 'a', 'l', and closing parenthesis.

### Visual Trace: `command = "G()(al)"`
| Index (i) | Char | Action | `ans` |
|-----------|------|--------|-------|
| 0 | 'G' | Append 'G' | "G" |
| 1 | '(' | Next is ')', append 'o', skip ')' | "Go" |
| 3 | '(' | Next is 'a', append 'al', skip 'al)' | "Goal" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the command string, as we visit each character exactly once.
- Space complexity: $$O(N)$$ to store the resulting interpreted string.

# Code
```cpp
class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for(int i=0;i<command.size();i++){
            if(command[i] == 'G') ans+= "G";
            else if(command[i] == '('){
                if(command[i+1] == ')'){
                    ans += "o";
                    i++;
                }else{
                    ans += "al";
                    i+= 2;
                }
                
            }
        }
        return ans;
    }
};
```

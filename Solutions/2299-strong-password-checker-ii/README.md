# [2299. Strong Password Checker II](https://leetcode.com/problems/strong-password-checker-ii/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
A password is said to be **strong** if it satisfies all the following criteria:

* It has at least `8` characters.
* It contains at least **one lowercase** letter.
* It contains at least **one uppercase** letter.
* It contains at least **one digit**.
* It contains at least **one special character**. The special characters are the characters in the following string: `"!@#$%^&*()-+"`.
* It does **not** contain `2` of the same character in adjacent positions (i.e., `"aab"` violates this condition, but `"aba"` does not).

Given a string `password`, return `true` *if it is a **strong** password*. Otherwise, return `false`.

**Example 1:**

```
Input: password = "IloveLe3tcode!"
Output: true
Explanation: The password meets all the requirements. Therefore, we return true.
```

**Example 2:**

```
Input: password = "Me+You--IsMyDream"
Output: false
Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
```

**Example 3:**

```
Input: password = "1aB!"
Output: false
Explanation: The password does not meet the length requirement. Therefore, we return false.
```

**Constraints:**

* `1 <= password.length <= 100`
* `password` consists of letters, digits, and special characters: `"!@#$%^&*()-+"`.

---

## Solution & Editorial
# Intuition
To determine if a password is "strong," we must verify six distinct constraints. Since the constraints are independent and the input size is small (up to 100 characters), a single linear pass through the string is sufficient to track the presence of required character types and check for adjacent duplicates.

# Approach
1. **Length Check**: Immediately return `false` if the length of `password` is less than 8.
2. **State Tracking**: Initialize four boolean flags (`upper`, `lower`, `digit`, `special`) to `false`.
3. **Single Pass**: Iterate through the string once:
   - Check for adjacent duplicates: If `i > 0` and `password[i] == password[i-1]`, return `false` immediately.
   - Update flags: Use standard library functions `isupper`, `islower`, `isdigit`, and `ispunct` to update the respective boolean flags.
4. **Final Validation**: After the loop, return `true` only if all four boolean flags are `true`.

### Visual Trace (Example: "aA1!")
| Index | Char | Condition | State Update |
| :--- | :--- | :--- | :--- |
| 0 | 'a' | Lower | `lower = true` |
| 1 | 'A' | Upper | `upper = true` |
| 2 | '1' | Digit | `digit = true` |
| 3 | '!' | Special | `special = true` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the password. We iterate through the string exactly once, performing constant-time checks at each character.
- Space complexity: $$O(1)$$, as we only use a fixed number of boolean variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if(n<8){
            return false;
        }
        bool upper = false;
        bool lower = false;
        bool digit = false;
        bool special = false;
        for(int i =0;i<n;i++){
            if(i>0&&password[i]==password[i-1]){
                return false;
            }else if(isupper(password[i])){
                upper=true;
            }else if(islower(password[i])){
                lower=true;
            }else if(isdigit(password[i])){
                digit=true;
            }else if(ispunct(password[i])){
                special=true;
            }
        }
        if(upper&&lower&&digit&&special){
            return true;
        }
        return false;
    }
};
```

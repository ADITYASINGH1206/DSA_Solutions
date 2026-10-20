# [1108. Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
Given a valid (IPv4) IP `address`, return a defanged version of that IP address.

A *defanged IP address* replaces every period `"."` with `"[.]"`.

**Example 1:**

```
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
```

**Example 2:**

```
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
```

**Constraints:**

* The given `address` is a valid IPv4 address.

---

## Solution & Editorial
# Intuition
The problem requires transforming a standard IPv4 address string into a defanged version by replacing every period `'.'` with `'[.]'`. Since each character in the input string must be inspected and conditionally copied or expanded, a straightforward linear scan is both optimal and extremely efficient.

# Approach
1. Initialize an empty result string `output` to store the defanged address.
2. Iterate through each character of the input `address` string from index `0` to `address.size() - 1` using a standard `for` loop.
3. At each index `i`, check if the character `address[i]` is equal to `'.'`. If it is, append `"[.]"` to `output`. Otherwise, append the character `address[i]` directly.
4. After the loop completes, return the constructed `output` string.

### Visual Walkthrough (Example 1: address = "1.1.1.1")
| Index `i` | `address[i]` | Condition `address[i] == '.'` | Action | `output` State |
| :---: | :---: | :---: | :--- | :--- |
| 0 | `'1'` | False | Append `'1'` | `"1"` |
| 1 | `'.'` | True | Append `"[.]"` | `"1[.]"` |
| 2 | `'1'` | False | Append `'1'` | `"1[.]1"` |
| 3 | `'.'` | True | Append `"[.]"` | `"1[.]1[.]"` |
| 4 | `'1'` | False | Append `'1'` | `"1[.]1[.]1"` |
| 5 | `'.'` | True | Append `"[.]"` | `"1[.]1[.]1[.]"` |
| 6 | `'1'` | False | Append `'1'` | `"1[.]1[.]1[.]1"` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input string `address`. We iterate through the string of length $$N$$ exactly once, performing constant time $$O(1)$$ append operations.
- Space complexity: $$O(N)$$ auxiliary space to store the resulting defanged string `output`, which in the worst case contains up to $$N + 6$$ characters.

# Code
```cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string output = "";
        for(int i=0 ; i<address.size() ; i++){
            if(address[i] == '.'){
                output += "[.]";
            }
            else{
                output+= address[i];
            }
        }
        return output;
    }
};
```

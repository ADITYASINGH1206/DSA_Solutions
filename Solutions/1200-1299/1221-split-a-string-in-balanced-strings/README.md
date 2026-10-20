# [1221. Split a String in Balanced Strings](https://leetcode.com/problems/split-a-string-in-balanced-strings/)
**Difficulty:** `Easy` | **Tags:** `string`, `greedy`, `counting`

---

## Problem Description
**Balanced** strings are those that have an equal quantity of `'L'` and `'R'` characters.

Given a **balanced** string `s`, split it into some number of substrings such that:

* Each substring is balanced.

Return *the **maximum** number of balanced strings you can obtain.*

**Example 1:**

```
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
```

**Example 2:**

```
Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
```

**Example 3:**

```
Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
```

**Constraints:**

* `2 <= s.length <= 1000`
* `s[i]` is either `'L'` or `'R'`.
* `s` is a **balanced** string.

---

## Solution & Editorial
# Intuition
To maximize the number of balanced substrings, we should greedily cut the string as soon as we encounter the shortest possible prefix that has an equal number of 'L' and 'R' characters. Since every valid split point localizes a balanced block without affecting future choices, a single-pass counting technique guarantees the optimal maximum count.

# Approach
1. Initialize `ans` to 0 to keep track of the total number of balanced substrings found, and `count` to 0 to maintain the net balance between 'R' and 'L'.
2. Iterate through each character `c` in the string `s` using a range-based for loop.
3. If `c == 'R'`, increment `count` by 1; otherwise, decrement `count` by 1.
4. Whenever `count` reaches 0, it signifies that a valid balanced substring has been completely traversed. Increment `ans` by 1.
5. Return `ans` after processing the entire string.

### Visual Trace (Example 1: s = "RLRRLLRLRL")

| Index | Character | `count` Update | Net `count` | `ans` Increment | Current `ans` |
| :---: | :---: | :---: | :---: | :---: | :---: | 
| 0 | R | +1 | 1 | No | 0 |
| 1 | L | -1 | 0 | Yes (+1) | 1 |
| 2 | R | +1 | 1 | No | 1 |
| 3 | R | +1 | 2 | No | 1 |
| 4 | L | -1 | 1 | No | 1 |
| 5 | L | -1 | 0 | Yes (+1) | 2 |
| 6 | R | +1 | 1 | No | 2 |
| 7 | L | -1 | 0 | Yes (+1) | 3 |
| 8 | R | +1 | 1 | No | 3 |
| 9 | L | -1 | 0 | Yes (+1) | 4 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of string `s`. We iterate through the string exactly once.
- Space complexity: $$O(1)$$ as we only use a constant amount of extra memory for scalar variables `ans` and `count`.

# Code
```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int count = 0;
        for(char c:s){
            if(c == 'R'){
                count +=1;
            }else{
                count -= 1;
            }
            if(count == 0){
                ans+=1;
            }
        }
        return ans;
    }
};
```

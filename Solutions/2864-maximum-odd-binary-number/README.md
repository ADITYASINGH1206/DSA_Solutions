# [2864. Maximum Odd Binary Number](https://leetcode.com/problems/maximum-odd-binary-number/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`, `greedy`

---

## Problem Description
You are given a **binary** string `s` that contains at least one `'1'`.

You have to **rearrange** the bits in such a way that the resulting binary number is the **maximum odd binary number** that can be created from this combination.

Return *a string representing the maximum odd binary number that can be created from the given combination.*

**Note** that the resulting string **can** have leading zeros.

**Example 1:**

```
Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
```

**Example 2:**

```
Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
```

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists only of `'0'` and `'1'`.
* `s` contains at least one `'1'`.

---

## Solution & Editorial
# Intuition
To maximize a binary number, we want the most significant bits (leftmost) to be '1'. Since the number must be odd, the least significant bit (rightmost) must be '1'. Therefore, the strategy is to place one '1' at the very end and fill the remaining positions from left to right with all other available '1's, followed by all available '0's.

# Approach
1. First, identify the rightmost '1' in the string and move it to the last index to satisfy the odd number requirement.
2. Once the last bit is fixed as '1', use a two-pointer approach to move all remaining '1's to the front of the string (indices 0 to n-2).
3. The `l` pointer tracks the position where the next '1' should be placed, while the `r` pointer searches for the next available '1' to swap into the front.

### Visual Trace (s = "0101")
| Step | String | l | r | Action |
| :--- | :--- | :--- | :--- | :--- |
| Init | 0101 | - | - | Move last '1' to end |
| After | 0101 | - | - | (Already at end) |
| Loop 1 | 1001 | 0 | 1 | Swap s[0] and s[1] |
| Loop 2 | 1001 | 1 | 1 | l increments |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a constant number of passes over the string to locate and swap bits.
- Space complexity: $$O(1)$$, as we perform the rearrangement in-place without allocating additional data structures.

# Code
```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        if(n == 1) return s;

        int r = n - 1;
        int l = n - 2;
        while(s[r] != '1'){
            if(s[l] == '1') swap(s[l], s[r]);
            else{
                l--;
            }
        }
        l = 0;
        r = 0; 
        while(r < n - 1 && l < n - 1) {
            if(s[l] == '1') {
                l++;
                r = max(r, l); 
            }
            else {
                while(r < n - 1 && s[r] != '1') {
                    r++;
                }
                if (r < n - 1) {
                    swap(s[l], s[r]);
                    l++;
                    r++;
                }
            }
        }
        
        return s;
    }
};
```

# [3216. Lexicographically Smallest String After a Swap](https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/)
**Difficulty:** `Easy` | **Tags:** `string`, `greedy`

---

## Problem Description
Given a string `s` containing only digits, return the lexicographically smallest string that can be obtained after swapping **adjacent** digits in `s` with the same **parity** at most **once**.

Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.

**Example 1:**

**Input:** s = "45320"

**Output:** "43520"

**Explanation:**

`s[1] == '5'` and `s[2] == '3'` both have the same parity, and swapping them results in the lexicographically smallest string.

**Example 2:**

**Input:** s = "001"

**Output:** "001"

**Explanation:**

There is no need to perform a swap because `s` is already the lexicographically smallest.

**Constraints:**

* `2 <= s.length <= 100`
* `s` consists only of digits.

---

## Solution & Editorial
# Intuition
To achieve the lexicographically smallest string with at most one adjacent swap of same-parity digits, we must identify the first pair of adjacent characters `(s[i], s[i+1])` where `s[i] > s[i+1]` and both digits share the same parity. Swapping this specific pair immediately yields the smallest possible result because a change at an earlier index has a greater impact on lexicographical order than any change at a later index.

# Approach
1. Iterate through the string using a sliding window of size 2, defined by indices `l` and `r` (where `r = l + 1`).
2. For each pair, check if `s[l]` and `s[r]` have the same parity using the modulo operator (`% 2`).
3. If they share parity and `s[l] > s[r]`, perform a single swap and return the modified string immediately.
4. If the loop completes without finding such a pair, the string is already in its lexicographically smallest form.

### Visual Trace (s = "45320")
| Iteration | l | r | s[l] | s[r] | Same Parity? | s[l] > s[r]? | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 1 | '4' | '5' | No | No | Continue |
| 2 | 1 | 2 | '5' | '3' | Yes | Yes | Swap, Return "43520" |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single linear scan of the string, and the swap operation is $$O(1)$$.
- Space complexity: $$O(1)$$ (or $$O(N)$$ depending on string mutability), as we only use a constant amount of extra space for pointers and temporary variables.

# Code
```cpp
class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        int l =0;
        int r = 1;
        while(r<n){
            int t1 = s[l];
            int t2 = s[r];
            if(t1%2==0){
                if(t2%2==0 && t1>t2){
                    swap(s[l],s[r]);
                    return s;
                }
            }else{
                if(t2%2!=0 && t1>t2){
                    swap(s[l],s[r]);
                    return s;
                }    
            }
            l++,r++;
        }
        return s;
    }
};
```

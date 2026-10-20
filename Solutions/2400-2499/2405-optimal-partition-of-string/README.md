# [2405. Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `greedy`

---

## Problem Description
Given a string `s`, partition the string into one or more **substrings** such that the characters in each substring are **unique**. That is, no letter appears in a single substring more than **once**.

Return *the **minimum** number of substrings in such a partition.*

Note that each character should belong to exactly one substring in a partition.

**Example 1:**

```
Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
```

**Example 2:**

```
Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of only English lowercase letters.

---

## Solution & Editorial
# Intuition
To minimize the number of substrings, we should greedily extend each substring as far as possible. As soon as we encounter a character that already exists in the current substring, we must terminate the current partition and start a new one.

# Approach
1. Initialize a frequency array `freq` of size 26 to track characters in the current substring.
2. Iterate through the string using a pointer `r`. 
3. For each character `s[r]`, check if it has already appeared in the current substring (i.e., `freq[s[r]-'a'] == 1`).
4. If it has, increment the partition count `ans`, reset the `freq` array to zero, and start a new substring.
5. If it hasn't, mark the character as seen in `freq` and move to the next character.

### Visual Trace: s = "abacaba"
| r | s[r] | freq state | ans | Action |
|---|---|---|---|---|
| 0 | 'a' | {a:1} | 1 | Add 'a' |
| 1 | 'b' | {a:1, b:1} | 1 | Add 'b' |
| 2 | 'a' | {a:1, b:1} | 2 | Reset, Add 'a' |
| 3 | 'c' | {a:1, c:1} | 2 | Add 'c' |
| 4 | 'a' | {a:1, c:1} | 3 | Reset, Add 'a' |
| 5 | 'b' | {a:1, b:1} | 3 | Add 'b' |
| 6 | 'a' | {a:1, b:1} | 4 | Reset, Add 'a' |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We traverse the string exactly once.
- Space complexity: $$O(1)$$, as the frequency array is fixed at size 26 regardless of input size.

# Code
```cpp
class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        if(n == 1) return 1;
        int ans = 1;
        int l = 0;
        int r= 0;
        vector<int> freq(26,0);
        while(r<n){
            if(freq[s[r]-'a'] == 1){
                ans++;
                fill(freq.begin(), freq.end(), 0);
            }else{
                freq[s[r]-'a']++;
                r++;
            }
        }

        return ans;

    }
};
```

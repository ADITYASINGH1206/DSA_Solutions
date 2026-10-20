# [316. Remove Duplicate Letters](https://leetcode.com/problems/remove-duplicate-letters/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `greedy`, `monotonic-stack`

---

## Problem Description
Given a string `s`, remove duplicate letters so that every letter appears once and only once. You must make sure your result is **the smallest in lexicographical order** among all possible results.

**Example 1:**

```
Input: s = "bcabc"
Output: "abc"
```

**Example 2:**

```
Input: s = "cbacdcbc"
Output: "acdb"
```

**Constraints:**

* `1 <= s.length <= 104`
* `s` consists of lowercase English letters.

**Note:** This question is the same as 1081: <https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/>

---

## Solution & Editorial
# Intuition
To form the lexicographically smallest subsequence where every character appears exactly once, we need to maintain a monotonic increasing stack. Whenever we encounter a character that is smaller than the top of our stack, and the top character appears later in the string (meaning we can safely pop it now and guarantee it will be seen again), we greedily pop it to keep the prefix as small as possible.

# Approach
1. Store the last occurrence index of each character using a frequency map/array. This informs us whether a character will appear again later in the string.
2. Iterate through the string `s` using pointer `i`. If a character is already present in our result (`isPresent` is true), skip it.
3. While the stack is not empty, the top of the stack is greater than the current character `s[i]`, and the last occurrence of the stack top is greater than the current index `i`, pop the top element from the stack and mark it as absent in `isPresent`.
4. Push the current character `s[i]` onto the stack and mark it as present.
5. Extract characters from the stack, reverse the resulting string, and return it.

### Visual Walkthrough for Example 1: `s = "bcabc"`

| Index `i` | Char `s[i]` | Action | Stack State (Bottom to Top) | `isPresent` | Last Occurrence Map |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | `b` | Push `b` | `['b']` | `b: true` | `b: 3, c: 4, a: 2` |
| 1 | `c` | Push `c` | `['b', 'c']` | `b: true, c: true` | `b: 3, c: 4, a: 2` |
| 2 | `a` | Pop `c` (last occ 4 > 2), Pop `b` (last occ 3 > 2), Push `a` | `['a']` | `a: true, b: false, c: false` | `b: 3, c: 4, a: 2` |
| 3 | `b` | Push `b` | `['a', 'b']` | `a: true, b: true` | `b: 3, c: 4, a: 2` |
| 4 | `c` | Push `c` | `['a', 'b', 'c']` | `a: true, b: true, c: true` | `b: 3, c: 4, a: 2` |

Result from stack: `"cba"`, reversed to `"abc"`.

# Complexity
- Time complexity: $$O(N)$$ — Each character is pushed and popped from the stack at most once. Finding last occurrences takes a single pass over the string of length $$N$$.
- Space complexity: $$O(1)$$ — The stack and tracking arrays hold at most 26 lowercase English letters, which requires constant extra space relative to the input size.

# Code
```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        map<char,int>freq;
        for(int i = 0 ; i<n ;i++){
            freq[s[i]-'a'] = i;
        }
        vector<bool>isPresent(26,false);
        int i = 0;
        stack<char>st;
        while(i<n){
            if (isPresent[s[i] - 'a']){
                i++;
                continue;
            }
            while(!st.empty() && st.top() > s[i]  && freq[st.top() - 'a'] > i ){
                isPresent[st.top() - 'a'] = false;
                st.pop();
            }

            isPresent[s[i] - 'a'] = true;
            st.push(s[i]);
            
            i++;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
```

# [784. Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/)
**Difficulty:** `Medium` | **Tags:** `string`, `backtracking`, `bit-manipulation`

---

## Problem Description
Given a string `s`, you can transform every letter individually to be lowercase or uppercase to create another string.

Return *a list of all possible strings we could create*. Return the output in **any order**.

**Example 1:**

```
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
```

**Example 2:**

```
Input: s = "3z4"
Output: ["3z4","3Z4"]
```

**Constraints:**

* `1 <= s.length <= 12`
* `s` consists of lowercase English letters, uppercase English letters, and digits.

---

## Solution & Editorial
# Intuition
The problem asks us to find all possible strings formed by independently toggling the case of every letter in a given string `s`. Since each alphabetic character presents two choices (lowercase or uppercase) and numeric characters present a single choice (the character itself), we can systematically explore all branching combinations using a recursive backtracking approach.

# Approach
1. Define a helper function `backtrack(int i, string& s, string& cur, vector<string>& ans)` that builds permutations incrementally.
2. If `cur.size() == s.size()`, we have constructed a valid permutation of length equal to `s`. Append `cur` to `ans` and return.
3. At index `i`, check if `s[i]` is an alphabetic character using `isalpha(s[i])`:
   - If it is a letter, branch twice: first append `tolower(s[i])` to `cur`, recurse on `i + 1`, then pop the character; next append `toupper(s[i])` to `cur`, recurse on `i + 1`, and pop the character.
   - If it is a digit, simply append `s[i]` to `cur`, recurse on `i + 1`, and pop the character.
4. Initiate the recursion from index `0` with an empty string `cur` inside `letterCasePermutation` and return the accumulated result vector `ans`.

### Visual Trace (Example 1: s = "a1b2")

```text
Initial Call: backtrack(0, "a1b2", cur="")
├── s[0] = 'a' (alpha)
│   ├── Branch 1 (lowercase): cur = "a", backtrack(1)
│   │   └── s[1] = '1' (digit) -> cur = "a1", backtrack(2)
│   │       └── s[2] = 'b' (alpha)
│   │           ├── Branch 1 (lowercase): cur = "a1b", backtrack(3)
│   │           │   └── s[3] = '2' (digit) -> cur = "a1b2", backtrack(4) -> ans.push("a1b2")
│   │           └── Branch 2 (uppercase): cur = "a1B", backtrack(3)
│   │               └── s[3] = '2' (digit) -> cur = "a1B2", backtrack(4) -> ans.push("a1B2")
│   └── Branch 2 (uppercase): cur = "A", backtrack(1)
│       └── s[1] = '1' (digit) -> cur = "A1", backtrack(2)
│           └── s[2] = 'b' (alpha)
│               ├── Branch 1 (lowercase): cur = "A1b", backtrack(3)
│               │   └── s[3] = '2' (digit) -> cur = "A1b2", backtrack(4) -> ans.push("A1b2")
│               └── Branch 2 (uppercase): cur = "A1B", backtrack(3)
│                   └── s[3] = '2' (digit) -> cur = "A1B2", backtrack(4) -> ans.push("A1B2")
```

# Complexity
- Time complexity: $$O(2^N \cdot N)$$ where $$N$$ is the length of string `s`. In the worst-case scenario where all characters are letters, there are $$2^N$$ possible strings, and copying each string of length $$N$$ into the result vector takes $$O(N)$$ time.
- Space complexity: $$O(N)$$ auxiliary space for the recursion stack and the temporary string `cur` (excluding the space required to store the output array `ans`).

# Code
```cpp
class Solution {
public:
    void backtrack(int i,string& s,string& cur,vector<string>& ans){
        if(cur.size() == s.size()){
            ans.push_back(cur);
            return;
        }
        

        if(isalpha(s[i])){
            cur+= tolower(s[i]);
            backtrack(i+1,s,cur,ans);
            cur.pop_back();
            cur+=toupper(s[i]);
            backtrack(i+1,s,cur,ans);
            cur.pop_back();
        }else{
            cur+= s[i];
            backtrack(i+1,s,cur,ans);
            cur.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string cur;
        backtrack(0,s,cur,ans);
        return ans;
    }
};
```

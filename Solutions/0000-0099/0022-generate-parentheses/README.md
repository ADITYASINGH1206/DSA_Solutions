# [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `backtracking`, `bracket-sequences`

---

## Problem Description
Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.

**Example 1:**

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

**Example 2:**

```
Input: n = 1
Output: ["()"]
```

**Constraints:**

* `1 <= n <= 8`

---

## Solution & Editorial
# Intuition
The problem asks us to generate all well-formed combinations of $n$ pairs of parentheses. A well-formed combination requires that at any point in the prefix of the string, the number of closing brackets does not exceed the number of opening brackets, and the total count of both opening and closing brackets equals $n$ at the end. This structure lends itself naturally to a backtracking approach where we track the counts of used open and close parentheses.

# Approach
1. Define a recursive helper function `backtrack` that accepts the answer vector `ans`, reference to `n`, current count of open brackets `l`, current count of close brackets `r`, and the current string `curs`.
2. Base case: When `l == n` and `r == n`, we have formed a valid string of length $2n$. Push `curs` to `ans` and return.
3. If `l < n`, append an opening parenthesis `'('` to `curs`, recursively call `backtrack` with `l + 1`, and then backtrack by removing the last character (`curs.pop_back()`).
4. If `r < l`, append a closing parenthesis `')'` to `curs`, recursively call `backtrack` with `r + 1`, and then backtrack by removing the last character (`curs.pop_back()`).
5. In `generateParenthesis`, initialize an empty string `temp` and `ans` vector, invoke `backtrack(ans, n, 0, 0, temp)`, and return `ans`.

### Visual Trace Walkthrough ($n = 3$)
```text
Initial: l=0, r=0, curs=""
  ├─ add '(', l=1, r=0, curs="("
  │   ├─ add '(', l=2, r=0, curs="(("
  │   │   ├─ add '(', l=3, r=0, curs="((("
  │   │   │   └─ add ')', l=3, r=1, curs="((()"
  │   │   │       └─ add ')', l=3, r=2, curs="((()"))"
  │   │   │           └─ add ')', l=3, r=3, curs="((()))" -> push to ans
  │   ... (explores remaining valid branches)
```

# Complexity
- Time complexity: $$O\left(\frac{4^n}{\sqrt{n}}\right)$$ — The number of valid parenthesis combinations for $n$ pairs is given by the $n$-th Catalan number, which grows asymptotically as $\frac{4^n}{n^{3/2}}$. Each valid string takes $O(n)$ time to construct.
- Space complexity: $$O(n)$$ — The maximum depth of the recursion tree is $2n$ (the length of each generated string), and auxiliary space used by `curs` is bounded by $O(n)$.

# Code
```cpp
class Solution {
public:
    void backtrack(vector<string>& ans, int& n, int l, int r, string& curs) {
        if (l == n && r == n) {
            ans.push_back(curs);
            return;
        }
        
        if (l < n) {
            curs += '(';                        
            backtrack(ans, n, l + 1, r, curs);  
            curs.pop_back();                    
        }

        if (r < l) {
            curs += ')';                        
            backtrack(ans, n, l, r + 1, curs);  
            curs.pop_back();                    
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        backtrack(ans, n, 0, 0, temp);
        return ans;
    }
};
```

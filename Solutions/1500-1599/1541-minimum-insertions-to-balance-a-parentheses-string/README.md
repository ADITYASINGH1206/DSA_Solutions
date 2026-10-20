# [1541. Minimum Insertions to Balance a Parentheses String](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `greedy`, `bracket-sequences`

---

## Problem Description
Given a parentheses string `s` containing only the characters `'('` and `')'`. A parentheses string is **balanced** if:

* Any left parenthesis `'('` must have a corresponding two consecutive right parenthesis `'))'`.
* Left parenthesis `'('` must go before the corresponding two consecutive right parenthesis `'))'`.

In other words, we treat `'('` as an opening parenthesis and `'))'` as a closing parenthesis.

* For example, `"())"`, `"())(())))"` and `"(())())))"` are balanced, `")()"`, `"()))"` and `"(()))"` are not balanced.

You can insert the characters `'('` and `')'` at any position of the string to balance it if needed.

Return *the minimum number of insertions* needed to make `s` balanced.

**Example 1:**

```
Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.
```

**Example 2:**

```
Input: s = "())"
Output: 0
Explanation: The string is already balanced.
```

**Example 3:**

```
Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of `'('` and `')'` only.

---

## Solution & Editorial
# Intuition
To balance the string, we need to ensure every '(' is followed by exactly two ')'. We can maintain a counter `p` representing the number of required closing parentheses. By processing the string linearly, we can greedily satisfy these requirements and track the number of insertions `k` needed when we encounter missing characters.

# Approach
1. Initialize `p` (required closing parentheses) to 0 and `k` (insertions) to 0.
2. Iterate through the string `s`:
   - If current char is '(', increment `p` by 2. If `p` becomes odd, it means we have a single ')' pending, so we must insert one ')' to complete the pair (increment `k`, decrement `p`).
   - If current char is ')', decrement `p`. If `p` drops below 0, it means we have an extra ')' without a preceding '(', so we insert one '(' (increment `k`, add 2 to `p` to account for the new '(' and the consumed ')').
3. After the loop, the remaining `p` represents unmatched opening parentheses, each needing two ')' (total `p` insertions). Return `p + k`.

### Visual Trace (Example: "(()))")
| Step | Char | p (needed) | k (insertions) | Action |
|---|---|---|---|---|
| 0 | - | 0 | 0 | Init |
| 1 | '(' | 2 | 0 | p += 2 |
| 2 | '(' | 4 | 0 | p += 2 |
| 3 | ')' | 3 | 0 | p -= 1 |
| 4 | ')' | 2 | 0 | p -= 1 |
| 5 | ')' | 1 | 0 | p -= 1 |
| Final | - | 1 | 0 | Return p+k = 1 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string, as we perform a single pass.
- Space complexity: $$O(1)$$ as we only use a few integer variables.

# Code
```cpp
class Solution {
public:
    int minInsertions(string& s) {
        int p=0, n=s.size(), k=0;
        for(int i=0; i<n; i++){
            char c=s[i];
            if (c=='('){
                p+=2;
                if (p&1==1){
                    k++;
                    p--;
                }
            }
            else{
                p--;
                if (p<0){
                    k++;
                    p+=2;
                }
               
            }
        }
        return p+k;
    }
};
```

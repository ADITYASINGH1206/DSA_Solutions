# [3955. Valid Binary Strings With Cost Limit](https://leetcode.com/problems/valid-binary-strings-with-cost-limit/)
**Difficulty:** `Medium` | **Tags:** `string`, `backtracking`, `bit-manipulation`, `enumeration`

---

## Problem Description
You are given two integers `n` and `k`.

The **cost** of a binary string `s` is defined as the sum of all indices `i` (0-based) such that `s[i] == '1'`.

A binary string is considered **valid** if:

* It does not contain two consecutive `'1'` characters.
* Its cost is **less than or equal** to `k`.

Return a list of all valid binary strings of length `n` in any order.

**Example 1:**

**Input:** n = 3, k = 1

**Output:** ["000","010","100"]

**Explanation:**

The binary strings of length 3 without consecutive `'1'` characters are:

* `"000"` : `cost = 0`
* "`100"` : `cost = 0`
* `"010"` : `cost = 1`
* `"001"` : `cost = 2`
* `"101"` : `cost = 0 + 2 = 2`

Among these, the strings with cost less than or equal to `k = 1` are `"000"`, `"010"` and `"100"`.

Thus, the valid strings are `["000", "010", "100"]`.

**Example 2:**

**Input:** n = 1, k = 0

**Output:** ["0","1"]

**Explanation:**

The valid binary strings of length 1 are `"0"` and `"1"`.

Thus the answer is `["0", "1"]`.

**Constraints:**

* `1 <= n <= 12`
* `0 <= k <= n * (n - 1) / 2`

---

## Solution & Editorial
# Intuition
Since the constraint on $n$ is small ($n \le 12$), we can explore the state space of all valid binary strings using backtracking. The core constraints are the absence of consecutive '1's and a maximum cost limit $k$. We can prune the search tree by only appending '1' when the previous character is '0' and ensuring the cumulative cost does not exceed $k$.

# Approach
1. Use a recursive `backtrack` function that maintains the current string `cur`, the current `cost`, and the target length `n`.
2. Base Case: When `cur.size() == n`, if `cost <= k`, add `cur` to the result list.
3. Recursive Step:
   - If the last character was '1', we are forced to append '0' to avoid consecutive '1's.
   - If the last character was '0' (or the string is empty), we can append '0' unconditionally. We can also append '1' if the cost constraint allows.
4. State Management: Use `cur.push_back` and `cur.pop_back` to manage the string state efficiently without creating unnecessary copies.

### Visual Trace (n=3, k=1)
| Step | `cur` | `cost` | Action |
| :--- | :--- | :--- | :--- |
| 1 | "" | 0 | Try '0' -> "0" |
| 2 | "0" | 0 | Try '0' -> "00" |
| 3 | "00" | 0 | Try '0' -> "000" (Valid) |
| 4 | "00" | 0 | Try '1' -> "001" (Cost 2 > 1, Invalid) |
| 5 | "0" | 0 | Try '1' -> "01" |
| 6 | "01" | 1 | Try '0' -> "010" (Valid) |

# Complexity
- Time complexity: $$O(2^n)$$ in the worst case, though significantly pruned by the consecutive '1' constraint (Fibonacci growth).
- Space complexity: $$O(n)$$ for the recursion stack and the string buffer.

# Code
```cpp
class Solution {
public:
    void backtrack(int n,int k,int cost,string& cur,vector<string>& ans){
        if(cur.size() == n){
            if (cost <= k) ans.push_back(cur);
            return;
        }

        if(cur.size()==0){
            cur+='0';
            backtrack(n,k,cost,cur,ans);
            cur.pop_back();
            cur+='1';
            backtrack(n,k,cost,cur,ans);
            cur.pop_back();
        }
        else{
            if(cur.back() == '1'){
                cur+= '0';
                backtrack(n,k,cost,cur,ans);
                cur.pop_back();
            }else{
                cur+='0';
                backtrack(n,k,cost,cur,ans);
                cur.pop_back();
                cur+='1';
                cost+=cur.size()-1;
                backtrack(n,k,cost,cur,ans);
                cur.pop_back();
            }
        }

    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string cur;
        backtrack(n,k,0,cur,ans);
        return ans;
    }
};
```

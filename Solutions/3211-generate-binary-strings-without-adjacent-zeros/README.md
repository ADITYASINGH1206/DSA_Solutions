# [3211. Generate Binary Strings Without Adjacent Zeros](https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/)
**Difficulty:** `Medium` | **Tags:** `string`, `backtracking`, `bit-manipulation`

---

## Problem Description
You are given a positive integer `n`.

A binary string `x` is **valid** if all substrings of `x` of length 2 contain **at least** one `"1"`.

Return all **valid** strings with length `n`**,** in *any* order.

**Example 1:**

**Input:** n = 3

**Output:** ["010","011","101","110","111"]

**Explanation:**

The valid strings of length 3 are: `"010"`, `"011"`, `"101"`, `"110"`, and `"111"`.

**Example 2:**

**Input:** n = 1

**Output:** ["0","1"]

**Explanation:**

The valid strings of length 1 are: `"0"` and `"1"`.

**Constraints:**

* `1 <= n <= 18`

---

## Solution & Editorial
# Intuition
The problem requires generating all binary strings of length `n` such that no two zeros are adjacent. This constraint implies that whenever we append a '0', the previous character must not have been a '0'. This structure is naturally suited for a backtracking approach where we explore the decision tree of appending '0' or '1' while pruning branches that violate the condition.

# Approach
1. Use a recursive `helper` function that maintains the current string `cur`.
2. Base Case: If `cur.size() == n`, we have formed a valid string, so we add it to the `result` vector.
3. Recursive Step:
   - We can always append '1' to the current string.
   - We can only append '0' if the current string is empty or the last character is '1'.

### Visual Trace (n=2)
| Step | Current String | Action | Valid? |
| :--- | :--- | :--- | :--- |
| 1 | "" | Add '0' | Yes |
| 2 | "0" | Add '1' | Yes |
| 3 | "01" | Base Case | Yes (Result: "01") |
| 4 | "" | Add '1' | Yes |
| 5 | "1" | Add '0' | Yes |
| 6 | "10" | Base Case | Yes (Result: "10") |
| 7 | "1" | Add '1' | Yes |
| 8 | "11" | Base Case | Yes (Result: "11") |

# Complexity
- Time complexity: $$O(2^n)$$ — In the worst case, we explore a binary tree of depth $$n$$. While the pruning reduces the number of valid strings (Fibonacci sequence), the recursion tree still visits nodes proportional to $$2^n$$.
- Space complexity: $$O(n)$$ — The recursion stack depth is $$n$$, and the string `cur` grows to length $$n$$.

# Code
```cpp
class Solution {
public:

    void helper(string cur,int& n,vector<string>& result){
        if(cur.size() == n) {
            result.push_back(cur);
            return;
        } 

        if (cur.empty() || cur.back() == '1') {
            helper(cur + '0', n, result);
        }
        helper(cur+'1',n,result);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        helper("",n,ans);
        return ans;
    }
};
```

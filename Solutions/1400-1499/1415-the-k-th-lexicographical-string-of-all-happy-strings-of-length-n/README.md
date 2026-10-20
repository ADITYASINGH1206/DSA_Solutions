# [1415. The k-th Lexicographical String of All Happy Strings of Length n](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)
**Difficulty:** `Medium` | **Tags:** `string`, `backtracking`

---

## Problem Description
A **happy string** is a string that:

* consists only of letters of the set `['a', 'b', 'c']`.
* `s[i] != s[i + 1]` for all values of `i` from `1` to `s.length - 1` (string is 1-indexed).

For example, strings **"abc", "ac", "b"** and **"abcbabcbcb"** are all happy strings and strings **"aa", "baa"** and **"ababbc"** are not happy strings.

Given two integers `n` and `k`, consider a list of all happy strings of length `n` sorted in lexicographical order.

Return *the kth string* of this list or return an **empty string** if there are less than `k` happy strings of length `n`.

**Example 1:**

```
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
```

**Example 2:**

```
Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
```

**Example 3:**

```
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
```

**Constraints:**

* `1 <= n <= 10`
* `1 <= k <= 100`

---

## Solution & Editorial
# Intuition
Since the constraints are small ($n \le 10$), we can generate all valid "happy strings" in lexicographical order using depth-first search (DFS). By iterating through characters 'a', 'b', and 'c' in order, the recursion naturally explores the search space in lexicographical sequence, allowing us to stop early once we reach the $k$-th string.

# Approach
1. Use a recursive lambda `dfs` to build the string `s` character by character.
2. At each step, iterate through 'a', 'b', and 'c'. Only append a character if it is the first character or different from the last character added (`s.back() != c`).
3. Once `s.size() == n`, add the string to the `ans` vector.
4. Prune the search by checking `ans.size() >= k` at the start of each recursive call to avoid unnecessary work.
5. After the DFS completes, return the $k$-th element (index $k-1$) if it exists, otherwise return an empty string.

### Visual Trace (n=2, k=3)
| Step | Action | `s` | `ans` |
| :--- | :--- | :--- | :--- |
| 1 | Start | "" | [] |
| 2 | Add 'a' | "a" | [] |
| 3 | Add 'b' | "ab" | ["ab"] |
| 4 | Add 'c' | "ac" | ["ab", "ac"] |
| 5 | Add 'b' | "ba" | ["ab", "ac", "ba"] |

# Complexity
- Time complexity: $$O(3 \cdot 2^{n-1})$$. There are 3 choices for the first character and 2 choices for each subsequent character, leading to a total of $3 \cdot 2^{n-1}$ possible happy strings. We visit each node in the recursion tree.
- Space complexity: $$O(n)$$. The recursion stack depth is $n$, and the string `s` stores at most $n$ characters.

# Code
```cpp
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        string s = "";
        auto dfs = [&](this auto&& dfs) -> void {
            if (s.size() == n) {
                ans.emplace_back(s);
                return;
            }
            if (ans.size() >= k) {
                return;
            }
            for (char c = 'a'; c <= 'c'; ++c) {
                if (s.empty() || s.back() != c) {
                    s.push_back(c);
                    dfs();
                    s.pop_back();
                }
            }
        };
        dfs();
        return ans.size() < k ? "" : ans[k - 1];
    }
};
```

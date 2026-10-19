# [131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `backtracking`

---

## Problem Description
Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return *all possible palindrome partitioning of* `s`.

**Example 1:**

```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```

**Example 2:**

```
Input: s = "a"
Output: [["a"]]
```

**Constraints:**

* `1 <= s.length <= 16`
* `s` contains only lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks us to find all possible ways to partition a string such that every substring is a palindrome. Since we need to explore all valid partitioning combinations, a backtracking approach is ideal. At each step, we can try all possible prefix substrings from the current index, verify if they are palindromes, and recursively partition the remaining suffix.

# Approach
1. Define a helper function `isPalindrome(const string& s)` to check if a given substring reads the same forwards and backwards using a two-pointer approach.
2. Implement a recursive `backtrack(int idx, vector<string>& cur, vector<vector<string>>& ans, string& s)` function where `idx` represents the current starting position in the string `s`.
3. Base Case: If `idx` reaches `s.size()`, a valid partition has been found. Push the current partition `cur` into `ans` and return.
4. Recursive Step: Iterate through all possible ending indices `i` from `idx` to `s.size() - 1`. Extract the substring `temp = s.substr(idx, i - idx + 1)`.
5. If `temp` is a palindrome, add it to `cur`, recurse with `backtrack(i + 1, cur, ans, s)`, and then backtrack by removing the last element from `cur`.

### Visual Trace Walkthrough (Example 1: s = "aab")

| `idx` | `i` | `temp` | Is Palindrome? | Action / State (`cur`) | Next Recursive Call |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 0 | "a" | Yes | `cur = ["a"]` | `backtrack(1)` |
| 1 | 1 | "a" | Yes | `cur = ["a", "a"]` | `backtrack(2)` |
| 2 | 2 | "b" | Yes | `cur = ["a", "a", "b"]` | `backtrack(3)` (Match Found! `ans.push_back(["a","a","b"])`) |
| 1 | 2 | "ab" | No | Skip | - |
| 0 | 1 | "aa" | Yes | `cur = ["aa"]` | `backtrack(2)` |
| 2 | 2 | "b" | Yes | `cur = ["aa", "b"]` | `backtrack(3)` (Match Found! `ans.push_back(["aa","b"])`) |
| 0 | 2 | "aab"| No | Skip | - |

# Complexity
- Time complexity: $$O(N \cdot 2^{N})$$ — There are $$2^{N-1}$$ possible ways to partition a string of length $$N$$. For each partition, substring extraction and palindrome verification take up to $$O(N)$$ time in the worst case.
- Space complexity: $$O(N)$$ — The recursion stack goes as deep as the string length $$N$$, and the temporary vector `cur` stores at most $$N$$ elements. This excludes the output space required to store all results.

# Code
```cpp
class Solution {
public:
    bool isPalindrome(const string& s){
        int n = s.size();
        if(n <= 1) return true;
        int l = 0;
        int r = n - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    void backtrack(int idx, vector<string>& cur, vector<vector<string>>& ans, string& s){
        if(idx == s.size()){
            ans.push_back(cur);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            string temp = s.substr(idx, i - idx + 1);
            if(isPalindrome(temp)){
                cur.push_back(temp);
                backtrack(i + 1, cur, ans, s);
                cur.pop_back(); 
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        backtrack(0, cur, ans, s);
        return ans;
    }
};
```

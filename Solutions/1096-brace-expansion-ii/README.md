# [1096. Brace Expansion II](https://leetcode.com/problems/brace-expansion-ii/)
**Difficulty:** `Hard` | **Tags:** `hash-table`, `string`, `backtracking`, `stack`, `breadth-first-search`, `sorting`

---

## Problem Description
Under the grammar given below, strings can represent a set of lowercase words. Let `R(expr)` denote the set of words the expression represents.

The grammar can best be understood through simple examples:

* Single letters represent a singleton set containing that word.
  + `R("a") = {"a"}`
  + `R("w") = {"w"}`
* When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
  + `R("{a,b,c}") = {"a","b","c"}`
  + `R("{{a,b},{b,c}}") = {"a","b","c"}` (notice the final set only contains each word at most once)
* When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
  + `R("{a,b}{c,d}") = {"ac","ad","bc","bd"}`
  + `R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}`

Formally, the three rules for our grammar:

* For every lowercase letter `x`, we have `R(x) = {x}`.
* For expressions `e1, e2, ... , ek` with `k >= 2`, we have `R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...`
* For expressions `e1` and `e2`, we have `R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}`, where `+` denotes concatenation, and `×` denotes the cartesian product.

Given an expression representing a set of words under the given grammar, return *the sorted list of words that the expression represents*.

**Example 1:**

```
Input: expression = "{a,b}{c,{d,e}}"
Output: ["ac","ad","ae","bc","bd","be"]
```

**Example 2:**

```
Input: expression = "{{a,z},a{b,c},{ab,z}}"
Output: ["a","ab","ac","z"]
Explanation: Each distinct word is written only once in the final answer.
```

**Constraints:**

* `1 <= expression.length <= 60`
* `expression[i]` consists of `'{'`, `'}'`, `','`or lowercase English letters.
* The given `expression` represents a set of words based on the grammar given in the description.

---

## Solution & Editorial
# Intuition
The problem requires evaluating a set expression governed by union (`+`) and concatenation (`*`) operations, with nested braces and operator precedence. By employing a dual-stack parser—one stack for operators (`op`) and one stack for operands (sets of strings, `st`)—we can evaluate expressions sequentially while respecting operator precedence and parentheses.

# Approach
1. Iterate through the `expr` string character by character while tracking the previous character `prv` to implicitly insert concatenation operators (`*`) where necessary.
2. Handle commas (representing union `+`) by resolving higher or equal precedence operators on the stack until an opening brace `{` or stack base is encountered.
3. Handle opening braces `{` by inserting an explicit `*` if it follows a letter or closing brace, then pushing `{` onto the operator stack.
4. Handle closing braces `}` by reducing all operations up to the matching `{`, then popping the `{`.
5. Handle letters by accumulating contiguous alphabetical characters into a singleton set and pushing it onto the operand stack `st`. If a letter follows a closing brace `}` or another letter, implicitly push a `*` operator.
6. After iterating through the expression, flush any remaining operations in the stack, sort the resulting strings lexicographically, and remove duplicates.

### Visual Dry Run / Trace Walkthrough (Example 1: "{a,b}{c,{d,e}}")
- `i = 0..6`: Parses `{a,b}`, pushes `{ "a", "b" }` to `st` and operator `*` between the adjacent groups.
- `i = 7..14`: Parses `{c,{d,e}}`, evaluates inner `{d,e}` first, then concatenates and unions according to precedence.
- Final evaluation yields `["ac", "ad", "ae", "bc", "bd", "be"]`.

# Complexity
- Time complexity: $$O(N \cdot M \log M)$$, where $$N$$ is the expression length and $$M$$ is the maximum number of generated strings across any sub-expression due to Cartesian products.
- Space complexity: $$O(M)$$ auxiliary storage for the string sets stored in the operand stack and final sorted array.

# Code
```cpp
class Solution {
public:
    vector<char> op;
    vector<vector<string>> st;

    void perf() {
        int x=st.size()-2, y = st.size()-1;
        if (op.back()=='+'){
            st[x].reserve(st[x].size()+st[y].size());
            st[x].insert(st[x].end(), st[y].begin(), st[y].end());
        }
        else {
            vector<string> nxt;
            nxt.reserve(st[x].size()*st[y].size());
            for (const auto& l : st[x]) {
                for (const auto& r : st[y]) 
                    nxt.push_back(l+r);
            }
            st[x]=move(nxt);
        }
        op.pop_back();
        st.pop_back();
    }
    vector<string> braceExpansionII(string& expr) {
        const int n=expr.size();
        op.reserve(n);

        char prv='@', cur;

        for (int i=0; i<n; i++, prv=cur) {
            cur = expr[i];
            switch (cur) {
            case ',': 
                while (!op.empty() && op.back() != '{') perf();
                op.push_back('+');
                break;
            case '{':
                if (prv=='}' || isalpha(prv)) op.push_back('*');
                op.push_back('{');
                break;
            case '}':
                while (!op.empty() && op.back()!='{') perf();
                op.pop_back();
                break;
            default:
                if (prv=='}') op.push_back('*');
                string s;
                for (; i<n && isalpha(expr[i]); i++) s+=expr[i];
                st.push_back({s});
                i--;
                cur=expr[i];
            }
        }

        while (!op.empty()) perf();

        auto ans=st.front();
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
```

# [1111. Maximum Nesting Depth of Two Valid Parentheses Strings](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/)
**Difficulty:** `Medium` | **Tags:** `string`, `stack`, `bracket-sequences`

---

## Problem Description
A string is a *valid parentheses string* (denoted VPS) if and only if it consists of `"("` and `")"` characters only, and:

* It is the empty string, or
* It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are VPS's, or
* It can be written as `(A)`, where `A` is a VPS.

We can similarly define the *nesting depth* `depth(S)` of any VPS `S` as follows:

* `depth("") = 0`
* `depth(A + B) = max(depth(A), depth(B))`, where `A` and `B` are VPS's
* `depth("(" + A + ")") = 1 + depth(A)`, where `A` is a VPS.

For example, `""`, `"()()"`, and `"()(()())"` are VPS's (with nesting depths 0, 1, and 2), and `")("` and `"(()"` are not VPS's.

Given a VPS seq, split it into two disjoint subsequences `A` and `B`, such that `A` and `B` are VPS's (and `A.length + B.length = seq.length`). The subsequences may not necessarily be contiguous.

For example, for the sequence `123456789`, one possible split is:

* `A = {1, 3, 5, 7, 9}`,
* `B = {2, 4, 6, 8}`.

This corresponds to the output `[0, 1, 0, 1, 0, 1, 0, 1, 0]`  where 0 indicates membership in `A` and 1 indicates membership in `B`.

Now choose **any** such `A` and `B` such that `max(depth(A), depth(B))` is the minimum possible value.

Return an `answer` array (of length `seq.length`) that encodes such a choice of `A` and `B`:  `answer[i] = 0` if `seq[i]` is part of `A`, else `answer[i] = 1`.  Note that even though multiple answers may exist, you may return any of them.

**Example 1:**

```
Input: seq = "(()())"
Output: [0,1,1,1,1,0]
```

**Example 2:**

```
Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]
```

**Constraints:**

* `1 <= seq.size <= 10000`

---

## Solution & Editorial
# Intuition
To minimize the maximum nesting depth of two disjoint valid parentheses strings (VPS) $A$ and $B$, we need to evenly distribute the nesting levels between both subsequences. As we iterate through the sequence and encounter opening parentheses `(` and closing parentheses `)`, tracking the current nesting `depth` allows us to assign alternating indices to $A$ (denoted by `0`) and $B$ (denoted by `1`) based on the parity of the depth.

# Approach
1. Initialize an integer `depth` to `0` and a result vector `ans` of size `n` with all zeros.
2. Iterate through each character `seq[i]` from index `0` to `n - 1`:
   - If `seq[i] == '('`, increment `depth` first, then assign `ans[i] = depth % 2`.
   - If `seq[i] == ')'`, assign `ans[i] = depth % 2` first, then decrement `depth`.
3. Return the `ans` vector representing the partition assignment.

### Visual Walkthrough for Example 1: `seq = "(()())"`
| Index `i` | `seq[i]` | Action | `depth` before op | `ans[i]` (`depth % 2`) | `depth` after op |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | `(` | `depth++` | 0 | `1 % 2 = 1` -> wait, `depth` becomes 1 -> `1 % 2 = 1` | 1 |
| 1 | `(` | `depth++` | 1 | `2 % 2 = 0` | 2 |
| 2 | `)` | `depth--` | 2 | `2 % 2 = 0` | 1 |
| 3 | `(` | `depth++` | 1 | `2 % 2 = 0` | 2 |
| 4 | `)` | `depth--` | 2 | `2 % 2 = 0` | 1 |
| 5 | `)` | `depth--` | 1 | `1 % 2 = 1` | 0 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string `seq`. We make a single pass through the sequence.
- Space complexity: $$O(N)$$ for storing the output answer vector of size $$N$$.

# Code
```cpp
class Solution {
    public:
    vector<int>maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int>ans (n,0);
        int depth = 0;

        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
};
```

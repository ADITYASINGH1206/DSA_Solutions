# [77. Combinations](https://leetcode.com/problems/combinations/)
**Difficulty:** `Medium` | **Tags:** `backtracking`

---

## Problem Description
Given two integers `n` and `k`, return *all possible combinations of* `k` *numbers chosen from the range* `[1, n]`.

You may return the answer in **any order**.

**Example 1:**

```
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
```

**Example 2:**

```
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
```

**Constraints:**

* `1 <= n <= 20`
* `1 <= k <= n`

---

## Solution & Editorial
# Intuition
The problem asks us to find all unique combinations of size $k$ chosen from the range $[1, n]$. This can be efficiently solved using depth-first search backtracking by building combinations incrementally and exploring all valid candidate numbers starting from the current index.

# Approach
1. Define a recursive helper function `combo` that accepts the result container `ans`, the current combination `curr`, the upper bound `n`, the target size `k`, and the starting index `i`.
2. In `combo`, check if `curr.size() == k`. If true, we have found a valid combination of length $k$. Append a copy of `curr` to `ans` and return.
3. Iterate from the current index `i` up to `n`. For each iteration, push the current number `i` into `curr`, recursively call `combo` with the next starting index `i + 1`, and then backtrack by calling `curr.pop_back()`.
4. In the main function `combine`, initialize an empty `ans` matrix and an empty `curr` vector, then invoke `combo` starting with index `1`.

### Visual Trace (Example 1: n = 4, k = 2)
| Call Stack / Step | `i` | `curr` State | Action |
| :--- | :--- | :--- | :--- |
| `combo(..., 1)` | 1 | `[1]` | Push 1, recurse with `i=2` |
| `combo(..., 2)` | 2 | `[1, 2]` | Size == k (2). Push to `ans`, pop 2 |
| `combo(..., 2)` | 3 | `[1, 3]` | Size == k (2). Push to `ans`, pop 3 |
| `combo(..., 2)` | 4 | `[1, 4]` | Size == k (2). Push to `ans`, pop 4 |
| `combo(..., 1)` | 2 | `[2]` | Push 2, recurse with `i=3` |
| `combo(..., 3)` | 3 | `[2, 3]` | Size == k (2). Push to `ans`, pop 3 |

# Complexity
- Time complexity: $$O(\binom{n}{k} \cdot k)$$, where $$\binom{n}{k}$$ is the total number of combinations generated, and each valid combination requires $$O(k)$$ time to be copied into the answer matrix.
- Space complexity: $$O(k)$$ auxiliary space for the recursion stack and the `curr` vector during exploration (excluding the space required to store the final output).

# Code
```cpp
class Solution {
public:

    void combo(vector<vector<int>>& ans, vector<int>& curr, int n, int k, int i) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (i; i <= n; i++) {
            curr.push_back(i);
            combo(ans, curr, n, k, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        int i = 1;
        combo(ans, curr, n, k, i);
        return ans;
    }
};
```

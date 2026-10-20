# [1871. Jump Game VII](https://leetcode.com/problems/jump-game-vii/)
**Difficulty:** `Medium` | **Tags:** `string`, `dynamic-programming`, `sliding-window`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** binary string `s` and two integers `minJump` and `maxJump`. In the beginning, you are standing at index `0`, which is equal to `'0'`. You can move from index `i` to index `j` if the following conditions are fulfilled:

* `i + minJump <= j <= min(i + maxJump, s.length - 1)`, and
* `s[j] == '0'`.

Return `true` *if you can reach index* `s.length - 1` *in* `s`*, or* `false` *otherwise.*

**Example 1:**

```
Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
```

**Example 2:**

```
Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
```

**Constraints:**

* `2 <= s.length <= 105`
* `s[i]` is either `'0'` or `'1'`.
* `s[0] == '0'`
* `1 <= minJump <= maxJump < s.length`

---

## Solution & Editorial
# Intuition
To determine if we can reach the last index, we need to know if any index `j` within the range `[i - maxJump, i - minJump]` is reachable. A naive check for every index would result in $O(N \cdot \text{maxJump})$ complexity, which is too slow. By maintaining a prefix sum array of reachable indices, we can query whether any reachable index exists in the valid jump window in $O(1)$ time.

# Approach
1. Define a boolean array `f` where `f[i]` is true if index `i` is reachable.
2. Define a prefix sum array `pre` where `pre[i+1]` stores the count of reachable indices in `f[0...i]`.
3. Iterate from `i = 1` to `n-1`. If `s[i] == '0'`, check if there is at least one reachable index in the range `[i - maxJump, i - minJump]` using the prefix sum: `pre[r + 1] - pre[l] > 0` where `l = i - maxJump` and `r = i - minJump`.
4. Update `pre[i + 1]` to include the reachability status of `f[i]` for future iterations.

### Visual Trace (s = "011010", minJump = 2, maxJump = 3)
| i | s[i] | Range [l, r] | Reachable? | pre[i+1] |
|---|---|---|---|---|
| 0 | 0 | - | Yes | 1 |
| 1 | 1 | - | No | 1 |
| 2 | 1 | - | No | 1 |
| 3 | 0 | [0, 1] | Yes (pre[2]-pre[0]=1) | 2 |
| 4 | 1 | - | No | 2 |
| 5 | 0 | [2, 3] | Yes (pre[4]-pre[2]=1) | 3 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string. We perform a single pass over the string, and each index update/query is $$O(1)$$.
- Space complexity: $$O(N)$$ to store the reachability array `f` and the prefix sum array `pre`.

# Code
```cpp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int pre[n + 1];
        memset(pre, 0, sizeof(pre));
        pre[1] = 1;
        bool f[n];
        memset(f, 0, sizeof(f));
        f[0] = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                int l = max(0, i - maxJump);
                int r = i - minJump;
                f[i] = l <= r && pre[r + 1] - pre[l];
            }
            pre[i + 1] = pre[i] + f[i];
        }
        return f[n - 1];
    }
};
```

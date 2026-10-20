# [3666. Minimum Operations to Equalize Binary String](https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/)
**Difficulty:** `Hard` | **Tags:** `math`, `string`, `breadth-first-search`, `union-find`, `ordered-set`

---

## Problem Description
You are given a binary string `s`, and an integer `k`.

In one operation, you must choose **exactly** `k` **different** indices and **flip** each `'0'` to `'1'` and each `'1'` to `'0'`.

Return the **minimum** number of operations required to make all characters in the string equal to `'1'`. If it is not possible, return -1.

**Example 1:**

**Input:** s = "110", k = 1

**Output:** 1

**Explanation:**

* There is one `'0'` in `s`.
* Since `k = 1`, we can flip it directly in one operation.

**Example 2:**

**Input:** s = "0101", k = 3

**Output:** 2

**Explanation:**

One optimal set of operations choosing `k = 3` indices in each operation is:

* **Operation 1**: Flip indices `[0, 1, 3]`. `s` changes from `"0101"` to `"1000"`.
* **Operation 2**: Flip indices `[1, 2, 3]`. `s` changes from `"1000"` to `"1111"`.

Thus, the minimum number of operations is 2.

**Example 3:**

**Input:** s = "101", k = 2

**Output:** -1

**Explanation:**

Since `k = 2` and `s` has only one `'0'`, it is impossible to flip exactly `k` indices to make all `'1'`. Hence, the answer is -1.

**Constraints:**

* `1 <= s.length <= 10​​​​​​​5`
* `s[i]` is either `'0'` or `'1'`.
* `1 <= k <= s.length`

---

## Solution & Editorial
# Intuition
The problem asks for the minimum number of operations to transform a binary string into all '1's. Since each operation flips exactly $k$ bits, the state of the string is determined solely by the number of '0's currently present. We can model this as a Breadth-First Search (BFS) on the number of '0's, where each state transition represents one operation.

# Approach
1. Let $n$ be the length of the string and $c$ be the current count of '0's. When we flip $k$ indices, suppose we choose $x$ indices that are currently '0' and $k-x$ indices that are currently '1'.
2. The new count of '0's becomes $c' = (c - x) + (k - x) = c + k - 2x$.
3. Constraints on $x$: 
   - $0 \le x \le c$ (cannot flip more '0's than available).
   - $0 \le k - x \le n - c$ (cannot flip more '1's than available).
4. Combining these, $x$ must satisfy $\max(0, k - (n - c)) \le x \le \min(k, c)$.
5. We use a BFS to find the shortest path from the initial count of '0's to 0. To optimize, we maintain sets of unvisited states partitioned by parity to quickly find reachable states.

### Visual Trace (Example 2: s = "0101", k = 3, n = 4)
- Initial: $c = 2$. Target: $0$.
- Queue: `[2]`. Parity sets: `ts[0] = {0, 2, 4}, ts[1] = {1, 3}`.
- BFS Level 0: Pop 2. $x$ range: $[\max(0, 3-2), \min(3, 2)] = [1, 2]$.
  - $x=1: c' = 2+3-2(1) = 3$.
  - $x=2: c' = 2+3-2(2) = 1$.
  - Queue: `[3, 1]`. Remove 3, 1 from `ts`.
- BFS Level 1: Pop 3. $x$ range: $[\max(0, 3-1), \min(3, 3)] = [2, 3]$.
  - $x=2: c' = 3+3-2(2) = 2$ (visited).
  - $x=3: c' = 3+3-2(3) = 0$ (Target reached!).
- Result: 2.

# Complexity
- Time complexity: $$O(N)$$. Each state (number of '0's) is added to the queue and removed from the `std::set` exactly once. The `lower_bound` and `erase` operations on the set effectively traverse the state space linearly.
- Space complexity: $$O(N)$$. We store the states in sets and the queue, which are bounded by the number of possible '0' counts, $N+1$.

# Code
```cpp
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();

        set<int> ts[2];
        for (int i = 0; i <= n; i++) {
            ts[i % 2].insert(i);
        }

        int cnt0 = count(s.begin(), s.end(), '0');
        ts[cnt0 % 2].erase(cnt0);

        queue<int> q;
        q.push(cnt0);

        int ans = 0;

        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int cur = q.front();
                q.pop();
                if (cur == 0) {
                    return ans;
                }

                int l = cur + k - 2 * min(cur, k);
                int r = cur + k - 2 * max(k - n + cur, 0);

                auto& t = ts[l % 2];
                auto it = t.lower_bound(l);

                while (it != t.end() && *it <= r) {
                    q.push(*it);
                    it = t.erase(it);
                }
            }
            ans++;
        }

        return -1;
    }
};
```

# [3629. Minimum Jumps to Reach End via Prime Teleportation](https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `math`, `breadth-first-search`, `number-theory`

---

## Problem Description
You are given an integer array `nums` of length `n`.

You start at index 0, and your goal is to reach index `n - 1`.

From any index `i`, you may perform one of the following operations:

* **Adjacent Step**: Jump to index `i + 1` or `i - 1`, if the index is within bounds.
* **Prime Teleportation**: If `nums[i]` is a prime number `p`, you may instantly jump to any index `j != i` such that `nums[j] % p == 0`.

Return the **minimum** number of jumps required to reach index `n - 1`.

**Example 1:**

**Input:** nums = [1,2,4,6]

**Output:** 2

**Explanation:**

One optimal sequence of jumps is:

* Start at index `i = 0`. Take an adjacent step to index 1.
* At index `i = 1`, `nums[1] = 2` is a prime number. Therefore, we teleport to index `i = 3` as `nums[3] = 6` is divisible by 2.

Thus, the answer is 2.

**Example 2:**

**Input:** nums = [2,3,4,7,9]

**Output:** 2

**Explanation:**

One optimal sequence of jumps is:

* Start at index `i = 0`. Take an adjacent step to index `i = 1`.
* At index `i = 1`, `nums[1] = 3` is a prime number. Therefore, we teleport to index `i = 4` since `nums[4] = 9` is divisible by 3.

Thus, the answer is 2.

**Example 3:**

**Input:** nums = [4,6,5,8]

**Output:** 3

**Explanation:**

* Since no teleportation is possible, we move through `0 → 1 → 2 → 3`. Thus, the answer is 3.

**Constraints:**

* `1 <= n == nums.length <= 105`
* `1 <= nums[i] <= 106`

---

## Solution & Editorial
# Intuition
To find the minimum number of jumps, we model the problem as a shortest-path search on an unweighted graph where indices are nodes. The challenge lies in the "Prime Teleportation" rule, which connects an index `i` to all indices `j` where `nums[j]` is divisible by the prime factors of `nums[i]`. By precomputing prime factors using a sieve-like approach, we can efficiently map each prime to the list of indices containing multiples of that prime, allowing us to perform a Breadth-First Search (BFS) to find the shortest path.

# Approach
1. **Precomputation**: Use a sieve to precompute prime factors for all numbers up to $10^6$. Store these in a global `factors` array where `factors[x]` contains all prime factors of `x`.
2. **Graph Construction**: Build an adjacency mapping `g` where `g[p]` stores all indices `i` such that `nums[i]` is divisible by prime `p`. This allows $O(1)$ lookup for teleportation targets.
3. **BFS Traversal**: 
   - Initialize a queue with index 0 and a `vis` array to track visited indices.
   - In each BFS layer, for the current index `i`:
     - Add adjacent indices `i-1` and `i+1` to the queue.
     - If `nums[i]` is prime, iterate through all indices `j` in `g[p]` (where `p` is a prime factor of `nums[i]`) and add them to the queue.
   - Clear `g[nums[i]]` after processing to ensure each prime-based edge is traversed only once, maintaining efficiency.

### Visual Trace (Example 1: [1, 2, 4, 6])
| Step | Queue | Visited | Action |
| :--- | :--- | :--- | :--- |
| 0 | [0] | {0} | Start at 0 |
| 1 | [1] | {0, 1} | Move to 1 (adj) |
| 2 | [3] | {0, 1, 3} | Teleport from 1 (p=2) to 3 (6%2==0) |

# Complexity
- Time complexity: $$O(N \log(\max(nums)) + M \log \log M)$$, where $N$ is the array length and $M$ is the maximum value in `nums`. The sieve takes $O(M \log \log M)$, and BFS visits each index and prime factor edge at most once.
- Space complexity: $$O(N + M \log M)$$ to store the prime factors and the adjacency mapping for indices.

# Code
```cpp
const int mx = 1e6 + 1;
vector<int> factors[mx];

int init = [] {
    for (int i = 2; i < mx; ++i) {
        if (factors[i].empty()) {
            for (int j = i; j < mx; j += i) {
                factors[j].push_back(i);
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> g;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p : factors[x]) {
                g[p].push_back(i);
            }
        }
        int ans = 0;
        vector<bool> vis(n, false);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        while (true) {
            queue<int> nq;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                if (i == n - 1) {
                    return ans;
                }
                vector<int> idx = g[nums[i]];
                idx.push_back(i + 1);
                if (i > 0) {
                    idx.push_back(i - 1);
                }
                for (int j : idx) {
                    if (!vis[j]) {
                        vis[j] = true;
                        nq.push(j);
                    }
                }
                g[nums[i]].clear();
            }
            q = nq;
            ans++;
        }
    }
};
```

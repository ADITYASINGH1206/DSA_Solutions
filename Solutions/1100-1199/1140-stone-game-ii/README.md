# [1140. Stone Game II](https://leetcode.com/problems/stone-game-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `dynamic-programming`, `minimax-algorithm`, `prefix-sum`, `game-theory`, `zero-sum-game`

---

## Problem Description
Alice and Bob continue their games with piles of stones. There are a number of piles **arranged in a row**, and each pile has a positive integer number of stones `piles[i]`. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take **all the stones** in the **first** `X` remaining piles, where `1 <= X <= 2M`. Then, we set `M = max(M, X)`. Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

**Example 1:**

**Input:** piles = [2,7,9,4,4]

**Output:** 10

**Explanation:**

* If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get `2 + 4 + 4 = 10` stones in total.
* If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get `2 + 7 = 9` stones in total.

So we return 10 since it's larger.

**Example 2:**

**Input:** piles = [1,2,3,4,5,100]

**Output:** 104

**Constraints:**

* `1 <= piles.length <= 100`
* `1 <= piles[i] <= 104`

---

## Solution & Editorial
# Intuition
This is a classic minimax game theory problem where both players play optimally. To maximize her own score, the current player tries to maximize the total stones she can collect from the current pile index onward, given the parameter $M$. By leveraging suffix sums, we can instantly compute the remaining stones available from index $i$ onward and subtract the optimal stones the opponent can get from the remaining piles.

# Approach
1. Precompute a suffix sum array `suffix` where `suffix[i]` represents the sum of all elements from index `i` to `n - 1`.
2. Define a memoized recursive function `solve(i, M)` that returns the maximum stones the current player can obtain starting from index `i` with parameter `M`.
3. Base case: If `i == n`, no stones are left, so return 0.
4. Iterate through all valid choices of $X$ piles the current player can take, where $1 \le X \le 2M$ and $i + X \le n$.
5. For each choice, the current player gets the total remaining stones `suffix[i]` minus what the opponent can achieve recursively from the next state `solve(i + X, max(M, X))`.
6. Store and return the maximum value across all valid choices of $X$ in the memoization table `dp[i][M]`.

# Complexity
- Time complexity: $$O(N^3)$$, where $N$ is the number of piles. There are $O(N^2)$ states defined by `i` and `M`. For each state, we iterate $X$ up to $2M$ (which is at most $N$), leading to roughly $O(N^3)$ total operations.
- Space complexity: $$O(N^2)$$ due to the 2D memoization table `dp` of size $N \times (N+1)$ and the `suffix` array of size $N + 1$.

# Code
```cpp
class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        if (i == n) {
            return 0;
        }

        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int best = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int nextM = max(M, X);
            int current = suffix[i] - solve(i + X, nextM);
            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};
```

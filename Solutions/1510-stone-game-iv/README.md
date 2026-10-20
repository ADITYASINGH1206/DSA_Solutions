# [1510. Stone Game IV](https://leetcode.com/problems/stone-game-iv/)
**Difficulty:** `Hard` | **Tags:** `math`, `dynamic-programming`, `minimax-algorithm`, `game-theory`, `nim-game`, `sprague-grundy-theorem`, `zero-sum-game`

---

## Problem Description
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are `n` stones in a pile. On each player's turn, that player makes a *move* consisting of removing **any** non-zero **square number** of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer `n`, return `true` if and only if Alice wins the game otherwise return `false`, assuming both players play optimally.

**Example 1:**

```
Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.
```

**Example 2:**

```
Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).
```

**Example 3:**

```
Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).
```

**Constraints:**

* `1 <= n <= 105`

---

## Solution & Editorial
# Intuition
This is a classic impartial game that can be solved using the Sprague-Grundy theorem or, more simply, by identifying winning and losing positions. A position $n$ is a winning position if there exists at least one move to a losing position. Conversely, a position is a losing position if all possible moves lead to winning positions.

# Approach
1. We define a boolean array `dp` where `dp[i]` is true if the current player can win starting with `i` stones.
2. We iterate through all numbers from $0$ to $N$. If `dp[i]` is false (a losing position), then any position $i + j^2$ (where $j^2$ is a perfect square) must be a winning position because the current player can move to $i$ and force the opponent into a losing state.
3. We use a `std::bitset` for memory efficiency and a static lambda to precompute the results for all $N$ up to $10^5$ once, ensuring $O(1)$ query time.

### Visual Trace (n=5)
| i | dp[i] | Action |
|---|---|---|
| 0 | F | Base case (Losing) |
| 1 | T | Can move to 0 (1-1^2) |
| 2 | F | Only move is to 1 (2-1^2), 1 is T, so 2 is F |
| 3 | T | Can move to 2 (3-1^2), 2 is F, so 3 is T |
| 4 | T | Can move to 0 (4-2^2), 0 is F, so 4 is T |
| 5 | F | Moves to 4 (T) or 1 (T), both are T, so 5 is F |

# Complexity
- Time complexity: $$O(N\sqrt{N})$$ — We iterate up to $N$, and for each $i$, we iterate through squares $j^2 \le N-i$, resulting in a harmonic series sum.
- Space complexity: $$O(N)$$ — We store the win/loss state for each integer up to $N$ in a `std::bitset`.

# Code
```cpp
class Solution {
public:
    static const int MAX = 100000;
    inline static bitset<MAX + 1> dp;

    inline static bool init = []() {
        for (int i = 0; i <= MAX; i++) {
            if (dp.test(i)) continue;
            for (int j = 1; j * j <= MAX - i; j++)
                dp.set(i + j * j);
        }
        
        return false;
    }();

    bool winnerSquareGame(int n) { return dp.test(n); }
};
```

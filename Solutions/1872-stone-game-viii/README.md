# [1872. Stone Game VIII](https://leetcode.com/problems/stone-game-viii/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `dynamic-programming`, `minimax-algorithm`, `prefix-sum`, `game-theory`, `zero-sum-game`

---

## Problem Description
Alice and Bob take turns playing a game, with **Alice starting first**.

There are `n` stones arranged in a row. On each player's turn, while the number of stones is **more than one**, they will do the following:

1. Choose an integer `x > 1`, and **remove** the leftmost `x` stones from the row.
2. Add the **sum** of the **removed** stones' values to the player's score.
3. Place a **new stone**, whose value is equal to that sum, on the left side of the row.

The game stops when **only** **one** stone is left in the row.

The **score difference** between Alice and Bob is `(Alice's score - Bob's score)`. Alice's goal is to **maximize** the score difference, and Bob's goal is the **minimize** the score difference.

Given an integer array `stones` of length `n` where `stones[i]` represents the value of the `ith` stone **from the left**, return *the **score difference** between Alice and Bob if they both play **optimally**.*

**Example 1:**

```
Input: stones = [-1,2,-3,4,-5]
Output: 5
Explanation:
- Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of
  value 2 on the left. stones = [2,-5].
- Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on
  the left. stones = [-3].
The difference between their scores is 2 - (-3) = 5.
```

**Example 2:**

```
Input: stones = [7,-6,5,10,5,-2,-6]
Output: 13
Explanation:
- Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 to her score, and places a
  stone of value 13 on the left. stones = [13].
The difference between their scores is 13 - 0 = 13.
```

**Example 3:**

```
Input: stones = [-10,-12]
Output: -22
Explanation:
- Alice can only make one move, which is to remove both stones. She adds (-10) + (-12) = -22 to her
  score and places a stone of value -22 on the left. stones = [-22].
The difference between their scores is (-22) - 0 = -22.
```

**Constraints:**

* `n == stones.length`
* `2 <= n <= 105`
* `-104 <= stones[i] <= 104`

---

## Solution & Editorial
# Intuition
This problem can be modeled as a game where each move reduces the number of stones by replacing a prefix with its sum. Let $P[i]$ be the prefix sum of the stones up to index $i$. If a player chooses to remove $k$ stones (indices $0$ to $k-1$), they gain $P[k-1]$ points and the new state effectively becomes a game starting with a single stone of value $P[k-1]$ followed by the remaining stones $stones[k 	o n-1]$. The key observation is that the score difference for the current player is the prefix sum $P[k-1]$ minus the optimal score difference the *other* player can achieve from the remaining state.

# Approach
1. Compute the prefix sums of the `stones` array in-place. After this, `stones[i]` stores the sum of all elements from index $0$ to $i$.
2. Let $dp[i]$ be the maximum score difference the current player can achieve when the game is reduced to a state where the first stone has value $P[i]$ and the remaining stones are $stones[i+1 	o n-1]$.
3. The transition is $dp[i] = \max(P[i+1] - dp[i+1], P[i+2] - dp[i+2], \dots, P[n-1] - dp[n-1])$.
4. Notice that $dp[i] = \max(P[i+1] - dp[i+1], dp[i+1])$. By iterating backwards from $n-2$ down to $1$, we can maintain the running maximum `best` to achieve $O(1)$ auxiliary space.

### Visual Trace (Example 1: [-1, 2, -3, 4, -5])
- Prefix Sums: `[-1, 1, -2, 2, -3]`
- Initial `best` (for $i=4$): `stones[4] = -3`
- Iteration $i=3$: `best = max(-3, stones[3] - (-3)) = max(-3, 2 + 3) = 5`
- Iteration $i=2$: `best = max(5, stones[2] - 5) = max(5, -2 - 5) = 5`
- Iteration $i=1$: `best = max(5, stones[1] - 5) = max(5, 1 - 5) = 5`
- Final Result: 5

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the number of stones. We perform one pass to compute prefix sums and one pass to compute the DP values.
- Space complexity: $$O(1)$$ as we perform the prefix sum calculation in-place and use only a single variable to track the optimal score difference.

# Code
```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        int best = stones[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            best = max(best, stones[i] - best);
        }

        return best;
    }
};
```

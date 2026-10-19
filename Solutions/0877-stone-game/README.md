# [877. Stone Game](https://leetcode.com/problems/stone-game/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `dynamic-programming`, `minimax-algorithm`, `game-theory`, `zero-sum-game`

---

## Problem Description
Alice and Bob play a game with piles of stones. There are an **even** number of piles arranged in a row, and each pile has a **positive** integer number of stones `piles[i]`.

The objective of the game is to end with the most stones. The **total** number of stones across all the piles is **odd**, so there are no ties.

Alice and Bob take turns, with **Alice starting first**. Each turn, a player takes the entire pile of stones either from the **beginning** or from the **end** of the row. This continues until there are no more piles left, at which point the person with the **most stones wins**.

Assuming Alice and Bob play optimally, return `true` *if Alice wins the game, or* `false` *if Bob wins*.

**Example 1:**

```
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alice starts first, and can only take the first 5 or the last 5.
Say she takes the first 5, so that the row becomes [3, 4, 5].
If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
```

**Example 2:**

```
Input: piles = [3,7,2,3]
Output: true
```

**Constraints:**

* `2 <= piles.length <= 500`
* `piles.length` is **even**.
* `1 <= piles[i] <= 500`
* `sum(piles[i])` is **odd**.

---

## Solution & Editorial
# Intuition
The problem presents a game with an even number of piles and an odd total sum of stones, meaning ties are impossible. Because Alice plays first and the number of piles is even, Alice can always force a win by controlling either all the piles at odd-indexed positions or all the piles at even-indexed positions.

# Approach
1. Observe that the total number of piles is even ($N$ is even). This allows Alice to divide the piles into two disjoint sets of equal size: all piles at even indices ($0, 2, 4, 	o$) and all piles at odd indices ($1, 3, 5, 	o$).
2. The sum of the stones at even-indexed piles and the sum of the stones at odd-indexed piles must partition the total sum of stones. Since the total sum is odd, one of these two sums must be strictly greater than the other.
3. Alice can always choose to inspect the first and last piles. By picking appropriately on her first turn and subsequent turns, Alice can force her opponent into a restricted subset of indices, ensuring she secures the sum of all piles in her chosen parity.
4. Since Alice can always guarantee winning by adopting this strategy, the function directly returns `true` for any valid input constraints.

# Complexity
- Time complexity: $$O(1)$$
- Space complexity: $$O(1)$$

# Code
```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
```

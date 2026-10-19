# [486. Predict the Winner](https://leetcode.com/problems/predict-the-winner/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `dynamic-programming`, `recursion`, `minimax-algorithm`, `game-theory`, `zero-sum-game`

---

## Problem Description
You are given an integer array `nums`.

Two players are playing a game with this array: Player 1 and Player 2.

Player 1 and Player 2 take turns, with Player 1 starting first. Both players start the game with a score of 0.

At each turn, the current player takes the number at **either end** of the array (i.e., `nums[0]` or `nums[nums.length - 1]`), **removing** it from the array and adding it to their own score. The game ends when there are no more elements in the array.

Return `true` if Player 1's final score is **greater than or equal** to Player 2's final score, and `false` otherwise.

**Note** that a tie counts as a win for Player 1. You may assume that both players play optimally.

**Example 1:**

**Input:** nums = [1,5,2]

**Output:** false

**Explanation:**

* Player 1 must open by taking either 1 or 2, and both choices lead to the same result.
* If Player 1 takes 1, the array becomes `[5,2]`. Player 2 takes 5, leaving 2 for Player 1.
* If Player 1 takes 2, the array becomes `[1,5]`. Player 2 takes 5, leaving 1 for Player 1.
* Either way, Player 1 finishes with `1 + 2 = 3` and Player 2 finishes with `5`. Player 1 can never win, so return `false`.

**Example 2:**

**Input:** nums = [1,5,233,7]

**Output:** true

**Explanation:**

* Player 1 first takes 1, leaving `[5,233,7]`. Player 2 must then choose between 5 and 7, and no matter which number Player 2 chooses, Player 1 can take 233 on the next turn.
* Player 1 finishes with a higher score (234) than Player 2 (12), so return `true`.

**Constraints:**

* `1 <= nums.length <= 20`
* `0 <= nums[i] <= 107`

---

## Solution & Editorial
# Intuition
This problem can be modeled as a zero-sum game with optimal play from both participants. Instead of tracking each player's absolute score, we can compute the maximum score differential a player can achieve over their opponent from a subarray `nums[i...j]`. If the final score differential for the entire array is greater than or equal to `0`, Player 1 wins.

# Approach
1. Check if the array length `n` is even. If `n` is even, Player 1 can always guarantee at least a tie by forcing a strategy on even/odd index sums. Thus, return `true` immediately when `n % 2 == 0`.
2. Define a 1D DP array initialized with `nums`. Here, `dp[j]` represents the maximum net score advantage for the current player on the subarray from index `i` to `j`.
3. Iterate backward with `i` from `n - 2` down to `0` and forward with `j` from `i + 1` up to `n - 1`.
4. At each state, the current player chooses between taking the left element `nums[i]` (leaving the opponent with `dp[j]`) or the right element `nums[j]` (leaving the opponent with `dp[j - 1]`). Thus, the transition state update is `dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1])`.
5. Finally, check if `dp[n - 1] >= 0` to determine if Player 1 wins.

### Visual Walkthrough for Example 1: `nums = [1, 5, 2]`
- Array length `n = 3` (odd).
- Initial `dp = [1, 5, 2]`.
- Iteration `i = 1` (`nums[1] = 5`):
  - `j = 2`: `dp[2] = max(nums[1] - dp[2], nums[2] - dp[1]) = max(5 - 2, 2 - 5) = max(3, -3) = 3`. `dp` becomes `[1, 5, 3]`.
- Iteration `i = 0` (`nums[0] = 1`):
  - `j = 1`: `dp[1] = max(nums[0] - dp[1], nums[1] - dp[0]) = max(1 - 5, 5 - 1) = max(-4, 4) = 4`.
  - `j = 2`: `dp[2] = max(nums[0] - dp[2], nums[2] - dp[1]) = max(1 - 3, 2 - 4) = max(-2, -2) = -2`. `dp` becomes `[1, 4, -2]`.
- Final result: `dp[2] = -2 < 0`, returning `false`.

# Complexity
- Time complexity: $$O(N^2)$$, where $$N$$ is the size of the array. The nested loops iterate over all possible subarrays `(i, j)` where $$0 \] le i < j < N$$.
- Space complexity: $$O(N)$$, utilizing a single 1D DP vector of size $$N$$ by optimizing space from an $$O(N^2)$$ 2D DP table.

# Code
```cpp
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        if (n % 2 == 0) return true; 
        
        vector<int> dp(nums);
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] >= 0;
    }
};
```

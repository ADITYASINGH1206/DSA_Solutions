# [2029. Stone Game IX](https://leetcode.com/problems/stone-game-ix/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `greedy`, `minimax-algorithm`, `counting`, `game-theory`, `nim-game`, `zero-sum-game`

---

## Problem Description
Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an associated value. You are given an integer array `stones`, where `stones[i]` is the **value** of the `ith` stone.

Alice and Bob take turns, with **Alice** starting first. On each turn, the player may remove any stone from `stones`. The player who removes a stone **loses** if the **sum** of the values of **all removed stones** is divisible by `3`. Bob will win automatically if there are no remaining stones (even if it is Alice's turn).

Assuming both players play **optimally**, return `true` *if Alice wins and* `false` *if Bob wins*.

**Example 1:**

```
Input: stones = [2,1]
Output: true
Explanation: The game will be played as follows:
- Turn 1: Alice can remove either stone.
- Turn 2: Bob removes the remaining stone. 
The sum of the removed stones is 1 + 2 = 3 and is divisible by 3. Therefore, Bob loses and Alice wins the game.
```

**Example 2:**

```
Input: stones = [2]
Output: false
Explanation: Alice will remove the only stone, and the sum of the values on the removed stones is 2. 
Since all the stones are removed and the sum of values is not divisible by 3, Bob wins the game.
```

**Example 3:**

```
Input: stones = [5,1,2,4,3]
Output: false
Explanation: Bob will always win. One possible way for Bob to win is shown below:
- Turn 1: Alice can remove the second stone with value 1. Sum of removed stones = 1.
- Turn 2: Bob removes the fifth stone with value 3. Sum of removed stones = 1 + 3 = 4.
- Turn 3: Alices removes the fourth stone with value 4. Sum of removed stones = 1 + 3 + 4 = 8.
- Turn 4: Bob removes the third stone with value 2. Sum of removed stones = 1 + 3 + 4 + 2 = 10.
- Turn 5: Alice removes the first stone with value 5. Sum of removed stones = 1 + 3 + 4 + 2 + 5 = 15.
Alice loses the game because the sum of the removed stones (15) is divisible by 3. Bob wins the game.
```

**Constraints:**

* `1 <= stones.length <= 105`
* `1 <= stones[i] <= 104`

---

## Solution & Editorial
# Intuition
The game depends entirely on the modulo 3 values of the stones. Since the sum must not be divisible by 3, we categorize stones into three buckets: those with remainder 0, 1, and 2. Stones with remainder 0 are "neutral" because they don't change the sum's modulo, but they can force a turn swap. The game's outcome is determined by the counts of these buckets and who is forced to pick a stone that makes the running sum divisible by 3.

# Approach
1. Count the occurrences of `stones[i] % 3` into an array `f` of size 3.
2. If the count of stones with remainder 0 (`f[0]`) is even, the players can effectively "pass" the turn by picking a 0-remainder stone. If `f[0]` is even, Alice wins if there is at least one stone of type 1 and one stone of type 2, as she can force Bob into a losing state.
3. If `f[0]` is odd, the player who is forced to pick the last 0-remainder stone loses the advantage. In this case, Alice wins if the difference between the counts of type 1 and type 2 stones is at least 3, allowing her to exhaust the opponent's options.

### Visual Trace (Example 1: stones = [2, 1])
- `f[0] = 0`, `f[1] = 1`, `f[2] = 1`
- `f[0]` is even (0). Condition `min(f[1], f[2]) >= 1` is `min(1, 1) >= 1`, which is `true`.
- Result: `true` (Alice wins).

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of stones, as we iterate through the array once to count remainders.
- Space complexity: $$O(1)$$, as we only use a fixed-size array of 3 integers regardless of input size.

# Code
```cpp
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3] = {0, 0, 0};

        for (auto& s : stones)
            f[s % 3]++;

        if (~f[0] & 1)
            return min(f[1], f[2]) >= 1;

        return abs(f[1] - f[2]) >= 3;
    }
};
```

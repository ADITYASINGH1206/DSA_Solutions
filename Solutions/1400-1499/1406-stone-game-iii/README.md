# [1406. Stone Game III](https://leetcode.com/problems/stone-game-iii/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `dynamic-programming`, `minimax-algorithm`, `game-theory`, `zero-sum-game`

---

## Problem Description
Alice and Bob continue their games with piles of stones. There are several stones **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take `1`, `2`, or `3` stones from the **first** remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is `0` initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob **play optimally**.

Return `"Alice"` *if Alice will win,* `"Bob"` *if Bob will win, or* `"Tie"` *if they will end the game with the same score*.

**Example 1:**

```
Input: stoneValue = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
```

**Example 2:**

```
Input: stoneValue = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
```

**Example 3:**

```
Input: stoneValue = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
```

**Constraints:**

* `1 <= stoneValue.length <= 5 * 104`
* `-1000 <= stoneValue[i] <= 1000`

---

## Solution & Editorial
# Intuition
This problem is a classic minimax game theory challenge. The core observation is that each player wants to maximize their own score, which is equivalent to maximizing the difference between their score and their opponent's score. We define `dp[i]` as the maximum relative score difference (Current Player - Opponent) that can be achieved starting from the $i$-th stone to the end of the array.

# Approach
1. **State Definition**: Let `dp[i]` be the maximum value of `(Player's Score - Opponent's Score)` starting from index `i`. 
2. **Recurrence Relation**: At any index `i`, a player can take 1, 2, or 3 stones. 
   - If they take 1 stone: `score = stoneValue[i] - dp[i+1]`
   - If they take 2 stones: `score = stoneValue[i] + stoneValue[i+1] - dp[i+2]`
   - If they take 3 stones: `score = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]`
   The player will choose the maximum of these three options.
3. **Space Optimization**: Since `dp[i]` only depends on `dp[i+1]`, `dp[i+2]`, and `dp[i+3]`, we only need a fixed-size array of size 3. We use `i % 3` to map the indices, effectively reusing the space as we iterate backwards from the end of the array.
4. **Base Cases**: 
   - `dp[n] = 0` (no stones left).
   - `dp[n-1]` and `dp[n-2]` are pre-calculated to handle the boundary conditions for the loop.
5. **Final Decision**: If `dp[0] > 0`, Alice wins. If `dp[0] < 0`, Bob wins. Otherwise, it's a tie.

### Visual Trace (Example 1: `stoneValue = [1, 2, 3, 7]`)
| Index `i` | Stones Taken | Calculation | `dp[i%3]` (Relative Score) |
| :--- | :--- | :--- | :--- |
| 4 (End) | - | Base Case | `dp[1] = 0` |
| 3 | [7] | `7 - dp[1]` | `dp[0] = 7` |
| 2 | [3] or [3,7] | `max(3-7, 3+7-0)` | `dp[2] = 10` |
| 1 | [2], [2,3], [2,3,7] | `max(2-10, 5-7, 12-0)` | `dp[1] = 12` |
| 0 | [1], [1,2], [1,2,3] | `max(1-12, 3-10, 6-7)` | `dp[0] = -1` |

**Result**: `dp[0] = -1` (Negative), so **Bob** wins.

# Complexity
- Time complexity: $$O(N)$$
We iterate through the `stoneValue` array exactly once from back to front. Each step involves a constant number of operations (at most 3 comparisons).

- Space complexity: $$O(1)$$$
We use a fixed-size array `dp[3]` regardless of the input size $N$. The space used is independent of the number of stones.

# Code
```cpp
class Solution {
public:
    static string stoneGameIII(vector<int>& stoneValue) {
        const int n=stoneValue.size();
        if (n==1) 
            return stoneValue[0]>0?"Alice":(stoneValue[0]<0?"Bob":"Tie");
        if (n==2){
            if(stoneValue[0]<0 )
                return stoneValue[0]+stoneValue[1]>0?"Alice":(stoneValue[0]!=stoneValue[1]?"Bob":"Tie");
            return "Alice";
        }
        int dp[3]={0};
        dp[n%3]=0;
        dp[(n-1)%3]=stoneValue[n-1]-dp[n%3];
        dp[(n-2)%3]=max(stoneValue[n-2]-dp[(n-1)%3], stoneValue[n-2]+stoneValue[n-1]-dp[n%3]);
        for (int i=n-3; i>=0; i--){
            const int s0=stoneValue[i], s1=stoneValue[i+1], s2=stoneValue[i+2];
            int res=s0-dp[(i+1)%3];
            res=max(res, s0+s1-dp[(i+2)%3]);
            res=max(res, s0+s1+s2-dp[(i+3)%3]);
            dp[i%3]=res;
        }
        int win=dp[0];
        return win>0?"Alice":(win<0?"Bob":"Tie");
        
    }
};
```

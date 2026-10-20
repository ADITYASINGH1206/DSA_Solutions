# [3847. Find the Score Difference in a Game](https://leetcode.com/problems/find-the-score-difference-in-a-game/)
**Difficulty:** `Medium` | **Tags:** `array`, `simulation`

---

## Problem Description
You are given an integer array `nums`, where `nums[i]` represents the points scored in the `ith` game.

There are **exactly** two players. Initially, the first player is **active** and the second player is **inactive**.

The following rules apply **sequentially** for each game `i`:

* If `nums[i]` is odd, the active and inactive players swap roles.
* In every 6th game (that is, game indices `5, 11, 17, ...`), the active and inactive players swap roles.
* The active player plays the `ith` game and gains `nums[i]` points.

Return the **score difference**, defined as the first player's **total** score **minus** the second player's **total** score.

**Example 1:**

**Input:** nums = [1,2,3]

**Output:** 0

**Explanation:**​​​​​​​

* Game 0: Since the points are odd, the second player becomes active and gains `nums[0] = 1` point.
* Game 1: No swap occurs. The second player gains `nums[1] = 2` points.
* Game 2: Since the points are odd, the first player becomes active and gains `nums[2] = 3` points.
* The score difference is `3 - 3 = 0`.

**Example 2:**

**Input:** nums = [2,4,2,1,2,1]

**Output:** 4

**Explanation:**

* Games 0 to 2: The first player gains `2 + 4 + 2 = 8` points.
* Game 3: Since the points are odd, the second player is now active and gains `nums[3] = 1` point.
* Game 4: The second player gains `nums[4] = 2` points.
* Game 5: Since the points are odd, the players swap roles. Then, because this is the 6th game, the players swap again. The second player gains `nums[5] = 1` point.
* The score difference is `8 - 4 = 4`.

**Example 3:**

**Input:** nums = [1]

**Output:** -1

**Explanation:**

* Game 0: Since the points are odd, the second player is now active and gains `nums[0] = 1` point.
* The score difference is `0 - 1 = -1`.

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires tracking the state of two players and their respective scores as we iterate through the game sequence. Since the rules for swapping are deterministic and depend only on the current game index and the points scored, a direct simulation is the most efficient approach.

# Approach
1. Initialize a `playerScores` vector of size 2 to track the total points for Player 0 and Player 1, and an `activeIdx` variable set to 0 (Player 0 starts active).
2. Iterate through the `nums` array. For each game `i`:
   - Check if `nums[i]` is odd; if so, toggle `activeIdx` using `1 - activeIdx`.
   - Check if the current game is a multiple of 6 (i.e., `(i + 1) % 6 == 0`); if so, toggle `activeIdx` again.
   - Add `nums[i]` to `playerScores[activeIdx]`.
3. Return the difference `playerScores[0] - playerScores[1]`.

### Visual Trace (Example 1: nums = [1, 2, 3])
| Game (i) | Points | Odd? | 6th Game? | Active Player | Scores [P0, P1] |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 1 | Yes | No | 1 | [0, 1] |
| 1 | 2 | No | No | 1 | [0, 3] |
| 2 | 3 | Yes | No | 0 | [3, 3] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. We perform a single pass over the input array with constant-time operations inside the loop.
- Space complexity: $$O(1)$$, as we only use a fixed-size vector of length 2 and a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        vector<int> playerScores(2, 0);
        int activeIdx = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 != 0) {
                activeIdx = 1 - activeIdx; 
            }
            if ((i + 1) % 6 == 0) {
                activeIdx = 1 - activeIdx;
            }
            playerScores[activeIdx] += nums[i];
        }

        return playerScores[0] - playerScores[1];
    }
};
```

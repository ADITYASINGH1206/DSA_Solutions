# [2225. Find Players With Zero or One Losses](https://leetcode.com/problems/find-players-with-zero-or-one-losses/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sorting`, `counting`

---

## Problem Description
You are given an integer array `matches` where `matches[i] = [winneri, loseri]` indicates that the player `winneri` defeated player `loseri` in a match.

Return *a list* `answer` *of size* `2` *where:*

* `answer[0]` is a list of all players that have **not** lost any matches.
* `answer[1]` is a list of all players that have lost exactly **one** match.

The values in the two lists should be returned in **increasing** order.

**Note:**

* You should only consider the players that have played **at least one** match.
* The testcases will be generated such that **no** two matches will have the **same** outcome.

**Example 1:**

```
Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
```

**Example 2:**

```
Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].
```

**Constraints:**

* `1 <= matches.length <= 105`
* `matches[i].length == 2`
* `1 <= winneri, loseri <= 105`
* `winneri != loseri`
* All `matches[i]` are **unique**.

---

## Solution & Editorial
# Intuition
To identify players with zero or one losses, we need to track the total number of losses for every player who has participated in at least one match. A `std::map` is ideal here because it maintains keys in sorted order, which satisfies the requirement to return the final lists in increasing order.

# Approach
1. Initialize a `std::map<int, int> lossCount` to store the number of losses for each player. The key is the player ID, and the value is the loss count.
2. Iterate through the `matches` array. For each match `[winner, loser]`:
   - Ensure the `winner` exists in the map (initialize to 0 if not present).
   - Increment the `loser`'s loss count in the map.
3. After processing all matches, iterate through the `lossCount` map:
   - If a player's value is `0`, they have never lost; add them to `zeroLoss`.
   - If a player's value is `1`, they have lost exactly once; add them to `oneLoss`.
4. Since `std::map` is ordered by key, the resulting vectors will naturally be sorted.

### Visual Trace (Example 1)
`matches = [[1,3], [2,3], [3,6]]`
| Step | Action | Map State (Player: Losses) |
| :--- | :--- | :--- |
| 1 | Process [1,3] | {1:0, 3:1} |
| 2 | Process [2,3] | {1:0, 2:0, 3:2} |
| 3 | Process [3,6] | {1:0, 2:0, 3:2, 6:1} |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of matches. Each insertion and lookup in the `std::map` takes $$O(\log P)$$ time, where $$P$$ is the number of unique players. Since $$P \le 2N$$, this simplifies to $$O(N \log N)$$.
- Space complexity: $$O(N)$$, as we store at most $$2N$$ unique players in the map.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lossCount; 
        
        for(int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];
            if(lossCount.find(winner) == lossCount.end()) {
                lossCount[winner] = 0;
            }
            lossCount[loser]++;
        }
        
        vector<int> zeroLoss;
        vector<int> oneLoss;
        for(auto it : lossCount) {
            if(it.second == 0) {
                zeroLoss.push_back(it.first);
            } else if(it.second == 1) {
                oneLoss.push_back(it.first);
            }
        }
        return {zeroLoss, oneLoss};
    }
};
```

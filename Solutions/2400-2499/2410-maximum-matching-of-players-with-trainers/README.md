# [2410. Maximum Matching of Players With Trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `greedy`, `sorting`

---

## Problem Description
You are given a **0-indexed** integer array `players`, where `players[i]` represents the **ability** of the `ith` player. You are also given a **0-indexed** integer array `trainers`, where `trainers[j]` represents the **training capacity** of the `jth` trainer.

The `ith` player can **match** with the `jth` trainer if the player's ability is **less than or equal to** the trainer's training capacity. Additionally, the `ith` player can be matched with at most one trainer, and the `jth` trainer can be matched with at most one player.

Return *the **maximum** number of matchings between* `players` *and* `trainers` *that satisfy these conditions.*

**Example 1:**

```
Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.
```

**Example 2:**

```
Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.
```

**Constraints:**

* `1 <= players.length, trainers.length <= 105`
* `1 <= players[i], trainers[j] <= 109`

**Note:** This question is the same as  [445: Assign Cookies.](https://leetcode.com/problems/assign-cookies/description/)

---

## Solution & Editorial
# Intuition
To maximize the number of successful pairings, we should always attempt to satisfy the player with the lowest ability using the smallest possible trainer that can accommodate them. This greedy strategy ensures we save larger capacity trainers for players with higher abilities, preventing "wasted" capacity.

# Approach
1. Sort both `players` and `trainers` arrays in non-decreasing order. Sorting allows us to process the smallest requirements first.
2. Use two pointers, `i` for `players` and `j` for `trainers`, both initialized to 0.
3. Iterate while both pointers are within bounds:
   - If `players[i] <= trainers[j]`, a match is possible. Increment `ans`, and move both `i` and `j` to the next available index.
   - If `players[i] > trainers[j]`, the current trainer is too weak for the current player. Since the arrays are sorted, this trainer cannot satisfy any subsequent (higher ability) players. Move `j` forward to try a stronger trainer.

### Visual Trace (Example 1: players=[4,7,9], trainers=[2,5,8,8])
| i | j | players[i] | trainers[j] | Action | ans |
|---|---|---|---|---|---|
| 0 | 0 | 4 | 2 | 4 > 2, j++ | 0 |
| 0 | 1 | 4 | 5 | 4 <= 5, match! | 1 |
| 1 | 2 | 7 | 8 | 7 <= 8, match! | 2 |
| 2 | 3 | 9 | 8 | 9 > 8, j++ | 2 |
| 2 | 4 | - | - | j out of bounds | 2 |

# Complexity
- Time complexity: $$O(N \log N + M \log M)$$, where $$N$$ and $$M$$ are the lengths of `players` and `trainers` respectively, due to the sorting step. The two-pointer traversal is linear, $$O(N + M)$$.
- Space complexity: $$O(1)$$ (or $$O(\log N + \log M)$$ depending on the sorting implementation's stack usage), as we only use a few integer variables for tracking.

# Code
```cpp
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m = players.size();
        int n = trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans = 0;
        int i =0 ,j =0;
        while(i<m && j<n){
            if(players[i] <= trainers[j]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }

        return ans;
    }
};
```

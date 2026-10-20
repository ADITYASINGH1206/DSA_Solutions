# [4034. Minimum Bishop Moves to Reach Target](https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`

---

## Problem Description
There is an `8 x 8` empty chessboard with **1-indexed** rows and columns.

You are given an array `source = [sr, sc]` representing the starting position of a **bishop**, and an array `target = [tr, tc]` representing the target position.

In one move, the bishop travels one or more squares along a single **diagonal** direction, staying within the board.

Return the **minimum** number of moves for the bishop to land **exactly** on `target`. If it can never reach `target`, return -1.

**Example 1:**

**Input:** source = [8,1], target = [1,8]

**Output:** 1

**Explanation:**

**​​​​​​​​​​​​​​**

A single diagonal move takes the bishop straight from `(8, 1)` to `(1, 8)`.

**Example 2:**

**Input:** source = [4,2], target = [1,3]

**Output:** 2

**Explanation:**

The bishop moves from `(4, 2)` to `(3, 1)`, then from `(3, 1)` to `(1, 3)`, reaching the target in 2 moves.

**Example 3:**

**Input:** source = [1,1], target = [3,4]

**Output:** -1

**Explanation:**

No matter how many diagonal moves it makes, the bishop starting at `(1, 1)` can never land on `(3, 4)`. Thus, the answer is -1.

**Constraints:**​​​​​​​

* `source.length == target.length == 2`
* `1 <= sr, sc, tr, tc <= 8`
* `source != target`

---

## Solution & Editorial
# Intuition
A bishop on a chessboard always stays on squares of the same color. The color of a square `(r, c)` is determined by the parity of `r + c`. If the parity of the source and target squares differs, the target is unreachable. If they are the same, the bishop can reach the target in at most two moves.

# Approach
1. **Parity Check**: A bishop moves diagonally, meaning both row and column indices change by the same absolute amount. Thus, `(r + c)` changes by `(dr + dc)` or `(dr - dc)`. Since `|dr| == |dc|`, the change is always even. If `(sr + sc) % 2 != (tr + tc) % 2`, return -1.
2. **One-Move Check**: If the bishop is already on the same diagonal as the target, the absolute difference between rows equals the absolute difference between columns: `abs(sr - tr) == abs(sc - tc)`. If true, return 1.
3. **Two-Move Case**: If the parities match but the bishop is not on the same diagonal, it can always reach the target in exactly 2 moves by intersecting the two diagonals passing through the source and target.

### Visual Trace (Example 2: source=[4,2], target=[1,3])
| Step | Position | Logic |
| :--- | :--- | :--- |
| Start | (4, 2) | Parity: (4+2)%2 = 0 |
| Target | (1, 3) | Parity: (1+3)%2 = 0 (Match) |
| Check | abs(4-1) != abs(2-3) | 3 != 1 (Not on same diagonal) |
| Result | 2 | Return 2 |

# Complexity
- Time complexity: $$O(1)$$. The solution performs a constant number of arithmetic operations regardless of board size.
- Space complexity: $$O(1)$$. No auxiliary data structures are used.

# Code
```cpp
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(source[0] == target[0] && source[1] == target[1]) return 0;

        if((source[0] + source[1])%2 != (target[0] + target[1])%2)return -1;


        if(abs(source[0]-target[0]) == abs(source[1]-target[1])) return 1;

        else return 2;
    }
};
```

# [3996. Even Number of Knight Moves](https://leetcode.com/problems/even-number-of-knight-moves/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given two integer arrays `start` and `target`, where each array is of the form `[x, y]` representing a cell on a standard 8 x 8 chessboard.

Return `true` if a knight can move from `start` to `target` in an **even** number of moves. Otherwise, return `false`.

**Note:** A valid knight move consists of moving two squares in one direction and one square perpendicular to it. The figure below illustrates all eight possible moves from a cell.

**Example 1:**

**Input:** start = [1,1], target = [2,2]

**Output:** true

**Explanation:**

One possible sequence of moves is `(1, 1) -> (3, 2) -> (2, 4) -> (4, 3) -> (2, 2)`.

The knight reaches the target in 4 moves, which is even. Thus, the answer is `true`.

**Example 2:**

**Input:** start = [4,5], target = [6,6]

**Output:** false

**Explanation:**​​​​​​​

It is impossible to reach `target = [6, 6]` from `start = [4, 5]` in an even number of moves. Thus, the answer is `false`.

**Constraints:**

* `start.length == target.length == 2`
* `0 <= start[i], target[i] <= 7`

---

## Solution & Editorial
# Intuition
A knight's move on a chessboard always changes the color of the square it occupies. Specifically, a move from $(x, y)$ to $(x \pm 1, y \pm 2)$ or $(x \pm 2, y \pm 1)$ changes the parity of the sum of coordinates $(x + y)$. Since each move flips the parity of the sum, an even number of moves results in the same parity as the starting square, while an odd number of moves results in the opposite parity.

# Approach
1. Calculate the parity of the sum of coordinates for the `start` position: `(start[0] + start[1]) % 2`.
2. Calculate the parity of the sum of coordinates for the `target` position: `(target[0] + target[1]) % 2`.
3. A knight can reach the target in an even number of moves if and only if the parity of the sum of coordinates remains unchanged. This is equivalent to checking if `(start[0] + start[1] + target[0] + target[1]) % 2 == 0`.

### Visual Trace (Example 1: start=[1,1], target=[2,2])
| Step | Position | Sum (x+y) | Parity |
| :--- | :--- | :--- | :--- |
| Start | (1, 1) | 2 | Even |
| Move 1 | (3, 2) | 5 | Odd |
| Move 2 | (2, 4) | 6 | Even |
| Move 3 | (4, 3) | 7 | Odd |
| Move 4 | (2, 2) | 4 | Even |

Since the parity of the sum at the start (2) and target (4) are both even, the condition holds.

# Complexity
- Time complexity: $$O(1)$$. The solution performs a constant number of arithmetic operations regardless of the input values.
- Space complexity: $$O(1)$$. No auxiliary data structures are used.

# Code
```cpp
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return (start[0] + start[1] + target[0] + target[1]) % 2 == 0;
    }
};
```

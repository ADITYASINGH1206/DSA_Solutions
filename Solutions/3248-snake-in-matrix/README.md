# [3248. Snake in Matrix](https://leetcode.com/problems/snake-in-matrix/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`, `simulation`

---

## Problem Description
There is a snake in an `n x n` matrix `grid` and can move in **four possible directions**. Each cell in the `grid` is identified by the position: `grid[i][j] = (i * n) + j`.

The snake starts at cell 0 and follows a sequence of commands.

You are given an integer `n` representing the size of the `grid` and an array of strings `commands` where each `command[i]` is either `"UP"`, `"RIGHT"`, `"DOWN"`, and `"LEFT"`. It's guaranteed that the snake will remain within the `grid` boundaries throughout its movement.

Return the position of the final cell where the snake ends up after executing `commands`.

**Example 1:**

**Input:** n = 2, commands = ["RIGHT","DOWN"]

**Output:** 3

**Explanation:**

|  |  |
| --- | --- |
| 0 | 1 |
| 2 | 3 |

|  |  |
| --- | --- |
| 0 | 1 |
| 2 | 3 |

|  |  |
| --- | --- |
| 0 | 1 |
| 2 | 3 |

**Example 2:**

**Input:** n = 3, commands = ["DOWN","RIGHT","UP"]

**Output:** 1

**Explanation:**

|  |  |  |
| --- | --- | --- |
| 0 | 1 | 2 |
| 3 | 4 | 5 |
| 6 | 7 | 8 |

|  |  |  |
| --- | --- | --- |
| 0 | 1 | 2 |
| 3 | 4 | 5 |
| 6 | 7 | 8 |

|  |  |  |
| --- | --- | --- |
| 0 | 1 | 2 |
| 3 | 4 | 5 |
| 6 | 7 | 8 |

|  |  |  |
| --- | --- | --- |
| 0 | 1 | 2 |
| 3 | 4 | 5 |
| 6 | 7 | 8 |

**Constraints:**

* `2 <= n <= 10`
* `1 <= commands.length <= 100`
* `commands` consists only of `"UP"`, `"RIGHT"`, `"DOWN"`, and `"LEFT"`.
* The input is generated such the snake will not move outside of the boundaries.

---

## Solution & Editorial
# Intuition
The problem maps a 2D grid coordinate system $(i, j)$ to a 1D integer value using the formula $pos = i \times n + j$. Since the snake's movement is constrained within the grid, we can track its position using simple row and column indices and compute the final value at the end.

# Approach
1. Initialize the snake's starting position at $(i, j) = (0, 0)$.
2. Iterate through each string in the `commands` vector.
3. Update the coordinates based on the command:
   - "UP": Decrement $i$.
   - "DOWN": Increment $i$.
   - "LEFT": Decrement $j$.
   - "RIGHT": Increment $j$.
4. After processing all commands, calculate the final position using the provided formula: $ans = (i \times n) + j$.

### Visual Trace (Example 1: n=2, commands=["RIGHT", "DOWN"])
| Step | Command | $i$ | $j$ | $i \times n + j$ |
| :--- | :--- | :--- | :--- | :--- |
| Start | - | 0 | 0 | 0 |
| 1 | "RIGHT" | 0 | 1 | 1 |
| 2 | "DOWN" | 1 | 1 | 3 |

# Complexity
- Time complexity: $$O(K)$$, where $$K$$ is the number of commands. We perform a single pass over the command list, and each operation inside the loop is $O(1)$.
- Space complexity: $$O(1)$$, as we only use two integer variables to track the current position.

# Code
```cpp
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0 ,j=0;
        for(auto command :commands){
            if(command == "UP") i--;
            else if(command =="DOWN") i++;
            else if(command == "LEFT") j--;
            else j++;
        }
        int ans = (i*n) + j;
        return ans;
    }
};
```

# [657. Robot Return to Origin](https://leetcode.com/problems/robot-return-to-origin/)
**Difficulty:** `Easy` | **Tags:** `string`, `simulation`

---

## Problem Description
There is a robot starting at the position `(0, 0)`, the origin, on a 2D plane. Given a sequence of its moves, judge if this robot **ends up at** `(0, 0)` after it completes its moves.

You are given a string `moves` that represents the move sequence of the robot where `moves[i]` represents its `ith` move. Valid moves are `'R'` (right), `'L'` (left), `'U'` (up), and `'D'` (down).

Return `true` *if the robot returns to the origin after it finishes all of its moves, or* `false` *otherwise*.

**Note**: The way that the robot is "facing" is irrelevant. `'R'` will always make the robot move to the right once, `'L'` will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.

**Example 1:**

```
Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.
```

**Example 2:**

```
Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
```

**Constraints:**

* `1 <= moves.length <= 2 * 104`
* `moves` only contains the characters `'U'`, `'D'`, `'L'` and `'R'`.

---

## Solution & Editorial
# Intuition
The problem asks us to track the net displacement of a robot on a 2D plane starting from the origin $(0, 0)$. Since each directional move has a fixed magnitude and independent axis, we can simply maintain the coordinate offsets using two integer variables and check if they return to zero at the end.

# Approach
1. Initialize coordinate variables `x = 0` and `y = 0` to represent the robot's current position on the 2D plane.
2. Iterate through each character `i` in the `moves` string using a range-based for loop.
3. Update the coordinates based on the character value: decrement `y` for 'U', increment `y` for 'D', decrement `x` for 'L', and increment `x` for 'R'.
4. After processing all moves, evaluate whether both `x == 0` and `y == 0` hold true. Return `true` if condition is met, otherwise `false`.

### Visual Trace Walkthrough (Example 1: `moves = "UD"`)
- Initial state: `x = 0`, `y = 0`
- Character `'U'`: `y` becomes `-1`. (`x = 0`, `y = -1`)
- Character `'D'`: `y` becomes `0`. (`x = 0`, `y = 0`)
- Final check: `x == 0 && y == 0` evaluates to `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string `moves`. We iterate through the string of moves exactly once.
- Space complexity: $$O(1)$$. Only a constant amount of extra memory (`x` and `y`) is used regardless of input size.

# Code
```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0 , y= 0;
        for(char i:moves){
            if(i=='U'){
                y--;
            }
            else if(i=='D'){
                y++;
            }else if(i=='L'){
                x--;
            }else if(i=='R'){
                x++;
            }
        }
        if(x==0&&y==0){
            return true;
        }
        return false;
    }
};
```

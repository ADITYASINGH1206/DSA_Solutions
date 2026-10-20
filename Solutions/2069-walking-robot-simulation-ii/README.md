# [2069. Walking Robot Simulation II](https://leetcode.com/problems/walking-robot-simulation-ii/)
**Difficulty:** `Medium` | **Tags:** `design`, `simulation`

---

## Problem Description
A `width x height` grid is on an XY-plane with the **bottom-left** cell at `(0, 0)` and the **top-right** cell at `(width - 1, height - 1)`. The grid is aligned with the four cardinal directions (`"North"`, `"East"`, `"South"`, and `"West"`). A robot is **initially** at cell `(0, 0)` facing direction `"East"`.

The robot can be instructed to move for a specific number of **steps**. For each step, it does the following.

1. Attempts to move **forward one** cell in the direction it is facing.
2. If the cell the robot is **moving to** is **out of bounds**, the robot instead **turns** 90 degrees **counterclockwise** and retries the step.

After the robot finishes moving the number of steps required, it stops and awaits the next instruction.

Implement the `Robot` class:

* `Robot(int width, int height)` Initializes the `width x height` grid with the robot at `(0, 0)` facing `"East"`.
* `void step(int num)` Instructs the robot to move forward `num` steps.
* `int[] getPos()` Returns the current cell the robot is at, as an array of length 2, `[x, y]`.
* `String getDir()` Returns the current direction of the robot, `"North"`, `"East"`, `"South"`, or `"West"`.

**Example 1:**

```
Input
["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"]
[[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
Output
[null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]

Explanation
Robot robot = new Robot(6, 3); // Initialize the grid and the robot at (0, 0) facing East.
robot.step(2);  // It moves two steps East to (2, 0), and faces East.
robot.step(2);  // It moves two steps East to (4, 0), and faces East.
robot.getPos(); // return [4, 0]
robot.getDir(); // return "East"
robot.step(2);  // It moves one step East to (5, 0), and faces East.
                // Moving the next step East would be out of bounds, so it turns and faces North.
                // Then, it moves one step North to (5, 1), and faces North.
robot.step(1);  // It moves one step North to (5, 2), and faces North (not West).
robot.step(4);  // Moving the next step North would be out of bounds, so it turns and faces West.
                // Then, it moves four steps West to (1, 2), and faces West.
robot.getPos(); // return [1, 2]
robot.getDir(); // return "West"
```

**Constraints:**

* `2 <= width, height <= 100`
* `1 <= num <= 105`
* At most `104` calls **in total** will be made to `step`, `getPos`, and `getDir`.

---

## Solution & Editorial
# Intuition
The robot moves along the perimeter of the grid. Instead of simulating step-by-step, which would be inefficient for large `num`, we can map the entire perimeter to a single linear range `[0, perimeter - 1]`. By tracking the robot's position as an offset within this perimeter, we can calculate its coordinates and direction in constant time using modular arithmetic.

# Approach
1. **Linearize the Perimeter**: The total perimeter of a `width x height` grid is `2 * (width - 1) + 2 * (height - 1)`. We map the robot's movement to a single integer `pos` in the range `[0, perimeter - 1]`.
2. **Modular Movement**: Since the robot moves in a cycle, `step(num)` is simply `pos = (pos + num) % perimeter`.
3. **Coordinate Mapping**: 
   - `0 <= pos <= w`: Bottom edge, moving East.
   - `w < pos <= w + h`: Right edge, moving North.
   - `w + h < pos <= 2*w + h`: Top edge, moving West.
   - `2*w + h < pos < perimeter`: Left edge, moving South.
4. **Direction Logic**: The direction is determined by the current `pos` range. A special case exists at `pos == 0`: if the robot has moved at least once, it is at the corner facing South; otherwise, it is at the start facing East.

### Visual Trace (Example 1: 6x3 grid)
- `w = 5`, `h = 2`, `perimeter = 16`
- `step(2)`: `pos = 2` -> `(2, 0)`, East
- `step(2)`: `pos = 4` -> `(4, 0)`, East
- `step(2)`: `pos = 6` -> `(5, 1)`, North

# Complexity
- Time complexity: $$O(1)$$ per operation. All calculations (modulo, comparisons) are constant time.
- Space complexity: $$O(1)$$ as we only store a few integer variables regardless of grid size.

# Code
```cpp
class Robot {
private:
    int w;
    int h;
    int perimeter;
    int pos;
    bool has_moved;

public:
    Robot(int width, int height) {
        w = width - 1;
        h = height - 1;
        perimeter = 2 * w + 2 * h;
        pos = 0;
        has_moved = false;
    }
    
    void step(int num) {
        has_moved = true;
        pos = (pos + num) % perimeter;
    }
    
    vector<int> getPos() {
        if (pos <= w) {
            return {pos, 0};
        } else if (pos <= w + h) {
            return {w, pos - w};
        } else if (pos <= 2 * w + h) {
            return {2 * w + h - pos, h};
        } else {
            return {0, perimeter - pos};
        }
    }
    
    string getDir() {
        if (pos == 0) {
            return has_moved ? "South" : "East";
        } else if (pos <= w) {
            return "East";
        } else if (pos <= w + h) {
            return "North";
        } else if (pos <= 2 * w + h) {
            return "West";
        } else {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
```

# [3968. Maximum Manhattan Distance After All Moves](https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/)
**Difficulty:** `Medium` | **Tags:** `math`, `string`, `counting`

---

## Problem Description
You are given a string `moves` consisting of the characters `'U'`, `'D'`, `'L'`, `'R'`, and `'_'`.

Starting from the origin `(0, 0)`, each character represents one move on a 2D plane:

* `'U'`: Move up by 1 unit.
* `'D'`: Move down by 1 unit.
* `'L'`: Move left by 1 unit.
* `'R'`: Move right by 1 unit.
* `'_'`: Can be independently replaced with any one of `'U'`, `'D'`, `'L'`, or `'R'`.

Return the maximum **Manhattan distance** from the origin that can be achieved after all moves have been performed.

**Example 1:**

**Input:** moves = "L\_D\_"

**Output:** 4

**Explanation:**

One optimal choice is:

* `'L'`: `(0, 0) -> (-1, 0)`
* `'_'` treated as `'D'`: `(-1, 0) -> (-1, -1)`
* `'D'`: `(-1, -1) -> (-1, -2)`
* `'_'` treated as `'L'`: `(-1, -2) -> (-2, -2)`

The final Manhattan distance from the origin is `|0 - (-2)| + |0 - (-2)| = 4`.

**Example 2:**

**Input:** moves = "U\_R"

**Output:** 3

**Explanation:**

One optimal choice is:

* `'U'`: `(0, 0) -> (0, 1)`
* `'_'` treated as `'U'`: `(0, 1) -> (0, 2)`
* `'R'`: `(0, 2) -> (1, 2)`

The final Manhattan distance from the origin is `|0 - 1| + |0 - 2| = 3`.

**Constraints:**

* `1 <= moves.length <= 105`
* `moves` consists of only `'U'`, `'D'`, `'L'`, `'R'`, and `'_'`.

---

## Solution & Editorial
# Intuition
The Manhattan distance from the origin $(0,0)$ to a point $(x, y)$ is defined as $|x| + |y|$. Since each move is independent and the goal is to maximize this sum, we can treat the fixed moves and the wildcard moves ('_') separately. Each wildcard move can be used to increase the absolute value of either the x-coordinate or the y-coordinate by 1, effectively adding 1 to the total Manhattan distance.

# Approach
1. Initialize `xf` and `yf` to track the net displacement from fixed moves ('U', 'D', 'L', 'R').
2. Initialize `ans` to 0 to count the number of wildcard moves ('_').
3. Iterate through the string `moves`:
   - If the character is 'U', increment `yf`.
   - If 'D', decrement `yf`.
   - If 'L', decrement `xf`.
   - If 'R', increment `xf`.
   - If '_', increment `ans`.
4. The final Manhattan distance is the sum of the absolute values of the final coordinates plus the number of wildcard moves: `abs(xf) + abs(yf) + ans`.

### Visual Trace (Example 1: "L_D_")
| Step | Char | xf | yf | ans |
| :--- | :--- | :--- | :--- | :--- |
| Start | - | 0 | 0 | 0 |
| 1 | L | -1 | 0 | 0 |
| 2 | _ | -1 | 0 | 1 |
| 3 | D | -1 | -1 | 1 |
| 4 | _ | -1 | -1 | 2 |

Final calculation: `abs(-1) + abs(-1) + 2 = 1 + 1 + 2 = 4`.

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int maxDistance(string moves) {
        int ans = 0;
        int xf = 0;
        int yf = 0;
        for(char c:moves){
            if(c == 'U')yf++;
            else if(c == 'D')yf--;
            else if(c == 'L')xf--;
            else if(c == 'R')xf++;
            else{
                ans++;
            }
        }
        ans += abs(xf) + abs(yf);

        return ans;
    }
};
```

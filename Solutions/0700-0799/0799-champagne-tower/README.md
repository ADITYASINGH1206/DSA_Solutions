# [799. Champagne Tower](https://leetcode.com/problems/champagne-tower/)
**Difficulty:** `Medium` | **Tags:** `dynamic-programming`

---

## Problem Description
We stack glasses in a pyramid, where the **first** row has `1` glass, the **second** row has `2` glasses, and so on until the 100th row.  Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.

Now after pouring some non-negative integer cups of champagne, return how full the `jth` glass in the `ith` row is (both `i` and `j` are 0-indexed.)

**Example 1:**

```
Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.
```

**Example 2:**

```
Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
```

**Example 3:**

```
Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000
```

**Constraints:**

* `0 <= poured <= 109`
* `0 <= query_glass <= query_row < 100`

---

## Solution & Editorial
# Intuition
The champagne tower problem can be modeled as a directed flow of liquid down a triangular pyramid of glasses. Since the maximum query row is bounded by $100$, we can simulate the exact amount of champagne flowing through each glass using a 2D dynamic programming grid up to the queried row.

# Approach
1. Initialize a 2D array `f` of size $101 	imes 101$ with zeros, representing the amount of champagne in each glass. Set `f[0][0]` to the initial amount `poured`.
2. Iterate through each row `i` from `0` up to `query_row`, and for each row, iterate through each glass `j` from `0` to `i`.
3. For each glass `(i, j)`, if the accumulated champagne `f[i][j]` exceeds $1$, calculate the overflow as `half = (f[i][j] - 1) / 2.0`.
4. Cap the current glass `f[i][j]` at $1$ and distribute the overflow equally to the lower-left glass `f[i + 1][j]` and lower-right glass `f[i + 1][j + 1]`.
5. Finally, return the capped value of `f[query_row][query_glass]`, bounded strictly to a maximum of $1.0$.

### Visual Trace Walkthrough (Example 2: poured = 2, query_row = 1, query_glass = 1)
- Initial state: `f[0][0] = 2.0`, all other cells are $0$.
- Row `i = 0`, Glass `j = 0`:
  - `f[0][0] > 1` ($2.0 > 1$). Overflow `half = (2.0 - 1) / 2.0 = 0.5`.
  - `f[0][0]` becomes `1.0`.
  - `f[1][0] += 0.5` $ightarrow 0.5$
  - `f[1][1] += 0.5` $ightarrow 0.5$
- Outer loop terminates since `i` reaches `query_row = 1`.
- Return `f[1][1]` which evaluates to `0.5`.

# Complexity
- Time complexity: $$O(R^2)$$ where $$R$$ is `query_row`. We iterate through a triangle of height `query_row + 1`, leading to $\frac{(R+1)(R+2)}{2}$ operations. Given $R < 100$, this takes at most around $5000$ operations.
- Space complexity: $$O(R^2)$$ to store the 2D grid `f` of fixed size $101 	imes 101$.

# Code
```cpp
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double f[101][101] = {0.0};
        f[0][0] = poured;
        for (int i = 0; i <= query_row; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (f[i][j] > 1) {
                    double half = (f[i][j] - 1) / 2.0;
                    f[i][j] = 1;
                    f[i + 1][j] += half;
                    f[i + 1][j + 1] += half;
                }
            }
        }
        return f[query_row][query_glass];
    }
};
```

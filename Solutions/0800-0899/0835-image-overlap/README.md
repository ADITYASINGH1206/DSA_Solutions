# [835. Image Overlap](https://leetcode.com/problems/image-overlap/)
**Difficulty:** `Medium` | **Tags:** `array`, `matrix`

---

## Problem Description
You are given two images, `img1` and `img2`, represented as binary, square matrices of size `n x n`. A binary matrix has only `0`s and `1`s as values.

We **translate** one image however we choose by sliding all the `1` bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the **overlap** by counting the number of positions that have a `1` in **both** images.

Note also that a translation does **not** include any kind of rotation. Any `1` bits that are translated outside of the matrix borders are erased.

Return *the largest possible overlap*.

**Example 1:**

```
Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.

The number of positions that have a 1 in both images is 3 (shown in red).
```

**Example 2:**

```
Input: img1 = [[1]], img2 = [[1]]
Output: 1
```

**Example 3:**

```
Input: img1 = [[0]], img2 = [[0]]
Output: 0
```

**Constraints:**

* `n == img1.length == img1[i].length`
* `n == img2.length == img2[i].length`
* `1 <= n <= 30`
* `img1[i][j]` is either `0` or `1`.
* `img2[i][j]` is either `0` or `1`.

---

## Solution & Editorial
# Intuition
The problem requires us to find the maximum possible overlap of 1-bits between two $n \times n$ binary matrices, `img1` and `img2`, under any translation. Instead of testing all possible translational offsets directly on the grids, we can collect the coordinates of all 1-bits in both images and track the relative displacement vectors required to align every 1-bit in `img1` with every 1-bit in `img2`. The translation vector that maps the maximum number of pairs is our answer.

# Approach
1. Extract the coordinates of all 1-bits from `img1` and store them in a vector of pairs `A`. Similarly, extract the coordinates of all 1-bits from `img2` and store them in `B`.
2. Initialize a 2D frequency table `cnt` of dimensions $(2n) \times (2n)$ filled with zeros to store the frequency of each displacement vector. We add an offset of `n` to the coordinate differences to handle negative shifts safely within non-negative array indices.
3. Iterate over every coordinate `a` in `A` and every coordinate `b` in `B`, compute the relative displacement `dx = b.first - a.first + n` and `dy = b.second - a.second + n`, and increment the frequency count `cnt[dx][dy]`.
4. Keep track of the maximum overlap encountered during the accumulation using the `best` variable and return it.

### Visual Walkthrough / Trace for Example 1
`img1 = [[1,1,0],[0,1,0],[0,1,0]]`, `img2 = [[0,0,0],[0,1,1],[0,0,1]]`, with `n = 3`.
- `A` contains: `(0,0)`, `(0,1)`, `(1,1)`, `(2,1)`
- `B` contains: `(1,1)`, `(1,2)`, `(2,2)`

Pairwise difference vectors `(dx, dy) = (b.first - a.first + n, b.second - a.second + n)`:
- `a = (0,0)` maps to `b = (1,1) -> (1 + 3, 1 + 3) = (4, 4)`
- `a = (0,1)` maps to `b = (1,2) -> (1 + 3, 2 - 1 + 3) = (4, 4)`
- `a = (1,1)` maps to `b = (2,2) -> (2 - 1 + 3, 2 - 1 + 3) = (4, 4)`

The vector `(4, 4)` accumulates a frequency count of `3`, resulting in `best = 3`.

# Complexity
- Time complexity: $$O(n^2 + K_1 \cdot K_2)$$ where $$n$$ is the grid dimension and $$K_1, K_2$$ are the counts of 1-bits in `img1` and `img2` respectively. Extracting the coordinates takes $$O(n^2)$$ time, and nested loops over `A` and `B` execute $$K_1 \cdot K_2$$ iterations. In the worst case where matrices are completely filled with 1s, $$K_1 = K_2 = n^2$$, yielding $$O(n^4)$$ worst-case time, but execution is extremely fast for sparse matrices.
- Space complexity: $$O(n^2 + K_1 + K_2)$$ to store the coordinate vectors `A`, `B`, and the displacement frequency matrix `cnt` of size $2n \times 2n$.

# Code
```cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> A, B;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) A.emplace_back(i, j);
                if (img2[i][j] == 1) B.emplace_back(i, j);
            }
        }
        vector<vector<int>> cnt(2 * n, vector<int>(2 * n, 0));
        int best = 0;
        for (auto& a : A) {
            for (auto& b : B) {
                int dx = b.first - a.first + n;
                int dy = b.second - a.second + n;
                best = max(best, ++cnt[dx][dy]);
            }
        }
        return best;
    }
};
```

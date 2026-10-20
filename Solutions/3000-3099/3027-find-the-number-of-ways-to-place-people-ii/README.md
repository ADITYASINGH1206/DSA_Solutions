# [3027. Find the Number of Ways to Place People II](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `geometry`, `sorting`, `enumeration`

---

## Problem Description
You are given a 2D array `points` of size `n x 2` representing integer coordinates of some points on a 2D-plane, where `points[i] = [xi, yi]`.

We define the **right** direction as positive x-axis (**increasing x-coordinate**) and the **left** direction as negative x-axis (**decreasing x-coordinate**). Similarly, we define the **up** direction as positive y-axis (**increasing y-coordinate**) and the **down** direction as negative y-axis (**decreasing y-coordinate**)

You have to place `n` people, including Alice and Bob, at these points such that there is **exactly one** person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the **upper left corner** and Bob's position as the **lower right corner** of the fence (**Note** that the fence **might not** enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either **inside** the fence or **on** the fence, Alice will be sad.

Return *the number of **pairs of points** where you can place Alice and Bob, such that Alice **does not** become sad on building the fence*.

**Note** that Alice can only build a fence with Alice's position as the upper left corner, and Bob's position as the lower right corner. For example, Alice cannot build either of the fences in the picture below with four corners `(1, 1)`, `(1, 3)`, `(3, 1)`, and `(3, 3)`, because:

* With Alice at `(3, 3)` and Bob at `(1, 1)`, Alice's position is not the upper left corner and Bob's position is not the lower right corner of the fence.
* With Alice at `(1, 3)` and Bob at `(1, 1)` (as the rectangle shown in the image instead of a line), Bob's position is not the lower right corner of the fence.

**Example 1:**

```
Input: points = [[1,1],[2,2],[3,3]]
Output: 0
Explanation: There is no way to place Alice and Bob such that Alice can build a fence with Alice's position as the upper left corner and Bob's position as the lower right corner. Hence we return 0.
```

**Example 2:**

```
Input: points = [[6,2],[4,4],[2,6]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (4, 4) and Bob at (6, 2).
- Place Alice at (2, 6) and Bob at (4, 4).
You cannot place Alice at (2, 6) and Bob at (6, 2) because the person at (4, 4) will be inside the fence.
```

**Example 3:**

```
Input: points = [[3,1],[1,3],[1,1]]
Output: 2
Explanation: There are two ways to place Alice and Bob such that Alice will not be sad:
- Place Alice at (1, 1) and Bob at (3, 1).
- Place Alice at (1, 3) and Bob at (1, 1).
You cannot place Alice at (1, 3) and Bob at (3, 1) because the person at (1, 1) will be on the fence.
Note that it does not matter if the fence encloses any area, the first and second fences in the image are valid.
```

**Constraints:**

* `2 <= n <= 1000`
* `points[i].length == 2`
* `-109 <= points[i][0], points[i][1] <= 109`
* All `points[i]` are distinct.

---

## Solution & Editorial
# Intuition
To satisfy the condition where Alice is at the upper-left and Bob is at the lower-right, we must have $x_A \le x_B$ and $y_A \ge y_B$. The constraint that no other point lies within or on the rectangle defined by $(x_A, y_A)$ and $(x_B, y_B)$ implies that for a fixed Alice, we must find Bob such that no other point $P_k$ satisfies $x_A \le x_k \le x_B$ and $y_B \le y_k \le y_A$. By sorting points primarily by increasing $x$ and secondarily by decreasing $y$, we can iterate through potential Bob positions for each Alice and maintain a running threshold of the "highest" $y$ coordinate encountered so far to prune invalid candidates.

# Approach
1. **Sort**: Sort the points such that $x$ is increasing. If $x$ values are equal, sort by $y$ descending. This ensures that for any pair $(i, j)$ with $i < j$, $x_i \le x_j$ is guaranteed.
2. **Iterate**: For each point $i$ (Alice), iterate through all subsequent points $j$ (Bob).
3. **Validate**: A point $j$ is a valid Bob if $y_j \le y_i$. To ensure no points are inside the rectangle, we maintain `lowerYLimit`. As we iterate $j$, we only consider points where $y_j \le y_i$. If we find a point $j$ such that $y_j > lowerYLimit$, it is a candidate. We then update `lowerYLimit = y_j`.
4. **Trace**: For `points = [[1,1],[2,2],[3,3]]` (sorted: `[[1,1],[2,2],[3,3]]`):
   - $i=0 (1,1)$: $j=1 (2,2)$ ($y_j > y_i$, skip), $j=2 (3,3)$ ($y_j > y_i$, skip).
   - $i=1 (2,2)$: $j=2 (3,3)$ ($y_j > y_i$, skip).
   - Result: 0.

# Complexity
- Time complexity: $$O(N^2)$$ due to the nested loop structure iterating over all pairs after sorting.
- Space complexity: $$O(1)$$, excluding the space required for sorting, as we only use a few integer variables.

# Code
```cpp
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];               
        });

        int ans = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int upperY = points[i][1];       
            int lowerYLimit = INT_MIN;      
            for (int j = i + 1; j < n; j++) {
                int currentY = points[j][1];
                if (currentY <= upperY && currentY > lowerYLimit) {
                    ans++;
                    lowerYLimit = currentY;
                    if (currentY == upperY) break;
                }
            }
        }

        return ans;
    }
};
```

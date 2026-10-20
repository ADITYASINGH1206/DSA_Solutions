# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)
**Difficulty:** `Easy` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

**Example 1:**

```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

**Example 2:**

```
Input: numRows = 1
Output: [[1]]
```

**Constraints:**

* `1 <= numRows <= 30`

---

## Solution & Editorial
# Intuition
Pascal's triangle can be generated row by row using dynamic programming, where each row's boundary elements are always 1, and every interior element is the sum of the two elements directly above it from the previous row.

# Approach
1. Initialize a 2D vector `f` and push the first row `[1]` into it.
2. Iterate `numRows - 1` times, treating each iteration as generating the next row `g` based on the previous row `f[i]`.
3. For each row `g`, start by pushing `1`. Then iterate through the previous row `f[i]` using index `j` from 1 to `f[i].size() - 1`, pushing the sum `f[i][j - 1] + f[i][j]` into `g`.
4. Complete the row by pushing a trailing `1`, and then append `g` to the 2D vector `f`.
5. Return `f` after generating all rows.

### Visual Trace Walkthrough (Example 1: numRows = 5)
- **Initial State:** `f = [[1]]`
- **Iteration 0 (i = 0):** Previous row `f[0] = [1]`. Inner loop doesn't execute. New row `g = [1, 1]`. `f = [[1], [1, 1]]`
- **Iteration 1 (i = 1):** Previous row `f[1] = [1, 1]`. Inner loop adds `f[1][0] + f[1][1] = 2`. New row `g = [1, 2, 1]`. `f = [[1], [1, 1], [1, 2, 1]]`
- **Iteration 2 (i = 2):** Previous row `f[2] = [1, 2, 1]`. Inner loop adds `1+2=3`, `2+1=3`. New row `g = [1, 3, 3, 1]`. `f = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]`
- **Iteration 3 (i = 3):** Previous row `f[3] = [1, 3, 3, 1]`. Inner loop adds `1+3=4`, `3+3=6`, `3+1=4`. New row `g = [1, 4, 6, 4, 1]`. `f = [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]`

# Complexity
- Time complexity: $$O(N^2)$$ where $$N$$ is `numRows`. The outer loop runs `numRows - 1` times and the inner loop runs proportionally to the row index, resulting in a total number of operations equal to the triangular number $$1 + 2 + \dots + N = \frac{N(N+1)}{2}$$.
- Space complexity: $$O(N^2)$$ to store all the elements of Pascal's triangle across the rows in the 2D output vector.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> f;
        f.push_back(vector<int>(1, 1));
        for (int i = 0; i < numRows - 1; ++i) {
            vector<int> g;
            g.push_back(1);
            for (int j = 1; j < f[i].size(); ++j) {
                g.push_back(f[i][j - 1] + f[i][j]);
            }
            g.push_back(1);
            f.push_back(g);
        }
        return f;
    }
};
```

# [2500. Delete Greatest Value in Each Row](https://leetcode.com/problems/delete-greatest-value-in-each-row/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`, `heap-priority-queue`, `matrix`, `simulation`

---

## Problem Description
You are given an `m x n` matrix `grid` consisting of positive integers.

Perform the following operation until `grid` becomes empty:

* Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
* Add the maximum of deleted elements to the answer.

**Note** that the number of columns decreases by one after each operation.

Return *the answer after performing the operations described above*.

**Example 1:**

```
Input: grid = [[1,2,4],[3,3,1]]
Output: 8
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 4 from the first row and 3 from the second row (notice that, there are two cells with value 3 and we can remove any of them). We add 4 to the answer.
- In the second operation, we remove 2 from the first row and 3 from the second row. We add 3 to the answer.
- In the third operation, we remove 1 from the first row and 1 from the second row. We add 1 to the answer.
The final answer = 4 + 3 + 1 = 8.
```

**Example 2:**

```
Input: grid = [[10]]
Output: 10
Explanation: The diagram above shows the removed values in each step.
- In the first operation, we remove 10 from the first row. We add 10 to the answer.
The final answer = 10.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `1 <= grid[i][j] <= 100`

---

## Solution & Editorial
# Intuition
To maximize the sum of the maximums removed in each step, we must ensure that for every row, the largest available elements are removed in descending order. By sorting each row individually, we align the elements such that the largest elements of all rows occupy the same relative column index, allowing us to process them column by column.

# Approach
1. Sort each row of the `grid` in non-decreasing order. After sorting, the largest element of each row will be at the last index (`n-1`), the second largest at `n-2`, and so on.
2. Iterate through each column index `i` from `0` to `n-1`.
3. For each column, find the maximum value among all rows at that specific column index `i`. This is the maximum of the currently "greatest" available elements in the remaining grid.
4. Accumulate these maximums into `ans` and return the final sum.

### Visual Trace (Example 1: `[[1,2,4],[3,3,1]]`)
- **Initial Sort:**
  Row 0: `[1, 2, 4]`
  Row 1: `[1, 3, 3]`
- **Iteration 1 (Column 2):** Max of `(4, 3)` is `4`. `ans = 4`.
- **Iteration 2 (Column 1):** Max of `(2, 3)` is `3`. `ans = 4 + 3 = 7`.
- **Iteration 3 (Column 0):** Max of `(1, 1)` is `1`. `ans = 7 + 1 = 8`.

# Complexity
- Time complexity: $$O(M \cdot N \log N)$$, where $$M$$ is the number of rows and $$N$$ is the number of columns. Sorting each of the $$M$$ rows takes $$O(N \log N)$$, and the subsequent column-wise traversal takes $$O(M \cdot N)$$.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, as we modify the input grid in-place).

# Code
```cpp
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        if(m==n && m ==1) return grid[0][0];
        for(int i = 0;i<m;i++){
            sort(grid[i].begin(),grid[i].end());
        }
        for(int i =0;i<n;i++){
            int temp = INT_MIN;
            for(int j=0;j<m;j++){
                if(grid[j][i] > temp) temp = grid[j][i];
            }
            ans += temp;
        }
        return ans;
    }
};
```

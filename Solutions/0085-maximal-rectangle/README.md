# [85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`, `stack`, `matrix`, `monotonic-stack`

---

## Problem Description
Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return *its area*.

**Example 1:**

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
```

**Example 2:**

```
Input: matrix = [["0"]]
Output: 0
```

**Example 3:**

```
Input: matrix = [["1"]]
Output: 1
```

**Constraints:**

* `rows == matrix.length`
* `cols == matrix[i].length`
* `1 <= rows, cols <= 200`
* `matrix[i][j]` is `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
By treating each row of the matrix as the base of a histogram where the height of each column is the consecutive number of '1's ending at that row, the problem is reduced to finding the largest rectangle in a histogram across all rows. This can be solved efficiently using a monotonic stack to compute the nearest smaller element to the left and right for every column height.

# Approach
1. Maintain a vector `heights` of size `cols` initialized to 0, representing the histogram heights for the current row.
2. Iterate through each row of the `matrix`. If `matrix[i][j] == '1'`, increment `heights[j]`, otherwise reset `heights[j]` to 0.
3. For each updated histogram, delegate to `maximumRectangle(heights)` to find the maximal rectangular area using a monotonic stack:
   - Compute the `left` boundary array: for each bar, find the index of the first bar to its left that is strictly shorter.
   - Compute the `right` boundary array: for each bar, find the index of the first bar to its right that is strictly shorter.
   - Calculate the area for each bar as `heights[i] * (right[i] - left[i] - 1)` and update the global maximum `ans`.

### Visual Walkthrough (Example 1 Row 1)
Given `matrix[1] = ["1", "0", "1", "1", "1"]` after processing row 0 and 1:
- `heights` = `[2, 0, 2, 1, 1]`
- `left` = `[-1, -1, 2, 2, 4]`
- `right` = `[1, 5, 3, 5, 5]`
- Widths `right[i] - left[i] - 1`: `[1, 5, 0, 2, 0]`
- Areas: `[2, 0, 0, 2, 0]` -> Max area for this row is 2.

# Complexity
- Time complexity: $$O(R \times C)$$ where $$R$$ is the number of rows and $$C$$ is the number of columns. Each row takes $$O(C)$$ time to update heights and $$O(C)$$ time for the monotonic stack histogram computation.
- Space complexity: $$O(C)$$ auxiliary space for the `heights`, `left`, `right` vectors and the monotonic stack.

# Code
```cpp
class Solution {
public:
    int maximumRectangle(vector<int>& heights){
        int n = heights.size();
        vector<int> left(n),right(n);
        stack<int> stk;

        for(int i = 0;i<n;i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int ans = 0;
        for(int i =0;i<n;i++){
            int width = right[i] - left[i] - 1;
            int area = heights[i]* width;
            ans = max(ans,area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> heights(n,0);
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1')heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans,maximumRectangle(heights));
        }

        return ans;
        
    }
};
```

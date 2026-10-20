# [2326. Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv/)
**Difficulty:** `Medium` | **Tags:** `array`, `linked-list`, `matrix`, `simulation`

---

## Problem Description
You are given two integers `m` and `n`, which represent the dimensions of a matrix.

You are also given the `head` of a linked list of integers.

Generate an `m x n` matrix that contains the integers in the linked list presented in **spiral** order **(clockwise)**, starting from the **top-left** of the matrix. If there are remaining empty spaces, fill them with `-1`.

Return *the generated matrix*.

**Example 1:**

```
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
```

**Example 2:**

```
Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
```

**Constraints:**

* `1 <= m, n <= 105`
* `1 <= m * n <= 105`
* The number of nodes in the list is in the range `[1, m * n]`.
* `0 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires filling a matrix in a spiral order using values from a linked list. Since the traversal pattern is fixed (right, down, left, up), we can maintain four boundaries (`topRow`, `bottomRow`, `leftColumn`, `rightColumn`) to track the current layer of the spiral and update them as we exhaust each direction.

# Approach
1. Initialize an `m x n` matrix filled with `-1`.
2. Define four pointers: `topRow = 0`, `bottomRow = m - 1`, `leftColumn = 0`, `rightColumn = n - 1`.
3. Iterate while the `head` pointer is not null:
    - Traverse from `leftColumn` to `rightColumn` along `topRow`. Increment `topRow`.
    - Traverse from `topRow` to `bottomRow` along `rightColumn`. Decrement `rightColumn`.
    - Traverse from `rightColumn` down to `leftColumn` along `bottomRow`. Decrement `bottomRow`.
    - Traverse from `bottomRow` up to `topRow` along `leftColumn`. Increment `leftColumn`.
4. At each step, check if `head` is still valid before assigning values to `matrix[row][col]`.

### Visual Trace (Example 1: 3x5)
| Step | Direction | Range | Boundary Update |
| :--- | :--- | :--- | :--- |
| 1 | Right | (0,0) to (0,4) | topRow: 0 -> 1 |
| 2 | Down | (1,4) to (2,4) | rightColumn: 4 -> 3 |
| 3 | Left | (2,3) to (2,0) | bottomRow: 2 -> 1 |
| 4 | Up | (1,0) to (1,0) | leftColumn: 0 -> 1 |

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ and $$N$$ are the dimensions of the matrix. We visit each cell exactly once.
- Space complexity: $$O(M \times N)$$ to store the resulting matrix.

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int topRow = 0, bottomRow = m - 1, leftColumn = 0, rightColumn = n - 1;
        
        while (head) {
            for (int col = leftColumn; col <= rightColumn && head; ++col) {
                matrix[topRow][col] = head->val;
                head = head->next;
            }
            topRow++;
            
            for (int row = topRow; row <= bottomRow && head; ++row) {
                matrix[row][rightColumn] = head->val;
                head = head->next;
            }
            rightColumn--;
            
            for (int col = rightColumn; col >= leftColumn && head; --col) {
                matrix[bottomRow][col] = head->val;
                head = head->next;
            }
            bottomRow--;
            
            for (int row = bottomRow; row >= topRow && head; --row) {
                matrix[row][leftColumn] = head->val;
                head = head->next;
            }
            leftColumn++;
        }
        
        return matrix;
    }
};
```

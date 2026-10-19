# [79. Word Search](https://leetcode.com/problems/word-search/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `backtracking`, `depth-first-search`, `matrix`

---

## Problem Description
Given an `m x n` grid of characters `board` and a string `word`, return `true` *if* `word` *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:**

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

**Example 2:**

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

**Example 3:**

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

**Constraints:**

* `m == board.length`
* `n = board[i].length`
* `1 <= m, n <= 6`
* `1 <= word.length <= 15`
* `board` and `word` consists of only lowercase and uppercase English letters.

**Follow up:** Could you use search pruning to make your solution faster with a larger `board`?

---

## Solution & Editorial
# Intuition
The problem asks whether a given word can be constructed from sequentially adjacent cells in a 2D character grid without reusing any cell. This naturally maps to a Depth-First Search (DFS) / Backtracking problem where we explore all four orthogonal directions from each starting cell on the board.

# Approach
1. Iterate over every cell `(i, j)` in the `board` using the `exist` function as a potential starting point for the target `word`.
2. Define a recursive helper function `combination(row, clm, board, word, index)` that checks if the character at `board[row][clm]` matches `word[index]`.
3. Base Case: If `index == word.size()`, we have successfully matched all characters and return `true`.
4. Boundary and Mismatch Check: If `row` or `clm` goes out of bounds, or if `board[row][clm] != word[index]`, return `false`.
5. In-Place State Modification: To prevent visiting the same cell twice in the current path, temporarily mark the current cell as visited by setting `board[row][clm] = '#'`.
6. Recursive Exploration: Recursively explore all four neighbors: `(row + 1, clm)`, `(row - 1, clm)`, `(row, clm + 1)`, and `(row, clm - 1)` with `index + 1`.
7. Backtrack: Restore the original character of `board[row][clm]` from `temp` before returning the accumulated result `found`.

### Visual Trace Walkthrough
For `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]` and `word = "AB"` starting from `(0, 0)`:

| Call | `row` | `clm` | `index` | `board[row][clm]` | Target `word[index]` | Action / Next State |
| :--- | :---: | :---: | :---: | :---: | :---: | :--- |
| 1 | 0 | 0 | 0 | 'A' | 'A' | Matches. Mark `board[0][0] = '#'` |
| 2 | 0 | 1 | 1 | 'B' | 'B' | Matches. Mark `board[0][1] = '#'` |
| 3 | 0 | 1 | 2 | - | - | `index == word.size()` returns `true` |

# Complexity
- Time complexity: $$O(N \cdot 3^L)$$, where $$N$$ is the total number of cells in the board ($$m \times n$$) and $$L$$ is the length of the `word`. From each cell, we branch into at most 3 directions (since the incoming direction is immediately blocked by the visited mark). 
- Space complexity: $$O(L)$$, where $$L$$ is the length of the `word`, corresponding to the maximum depth of the recursive call stack during backtracking.

# Code
```cpp
class Solution {
public:
    bool combination(int row, int clm, vector<vector<char>>& board, string& word, int index) {
        if (index == word.size()) return true;

        if (row < 0 || row >= board.size() || clm < 0 || clm >= board[0].size() || board[row][clm] != word[index]) {
            return false;
        }

        char temp = board[row][clm];
        board[row][clm] = '#'; 

        bool found = combination(row + 1, clm, board, word, index + 1) || 
                     combination(row - 1, clm, board, word, index + 1) || 
                     combination(row, clm + 1, board, word, index + 1) || 
                     combination(row, clm - 1, board, word, index + 1);  

        board[row][clm] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (combination(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
};
```

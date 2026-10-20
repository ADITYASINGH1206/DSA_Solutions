# [1301. Number of Paths with Max Score](https://leetcode.com/problems/number-of-paths-with-max-score/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`, `matrix`

---

## Problem Description
You are given a square `board` of characters. You can move on the board starting at the bottom right square marked with the character `'S'`.

You need to reach the top left square marked with the character `'E'`. The rest of the squares are labeled either with a numeric character `1, 2, ..., 9` or with an obstacle `'X'`. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, **taken modulo `10^9 + 7`**.

In case there is no path, return `[0, 0]`.

**Example 1:**

```
Input: board = ["E23","2X2","12S"]
Output: [7,1]
```

**Example 2:**

```
Input: board = ["E12","1X1","21S"]
Output: [4,2]
```

**Example 3:**

```
Input: board = ["E11","XXX","11S"]
Output: [0,0]
```

**Constraints:**

* `2 <= board.length == board[i].length <= 100`

---

## Solution & Editorial
# Intuition
We need to find the maximum score path from the bottom-right corner ('S') to the top-left corner ('E') on a board, along with the count of such paths modulo $10^9 + 7$. Since we can only move up, left, and up-left, any state at `(i, j)` depends entirely on the reachable states below and to its right: `(i + 1, j)`, `(i, j + 1)`, and `(i + 1, j + 1)`. This optimal substructure allows us to solve the problem using dynamic programming in reverse order from the target 'S' back to 'E'.

# Approach
1. Initialize two 2D DP tables: `maxScore` initialized to `-1` and `ways` initialized to `0` of size $n 	imes n$.
2. Set the base case at the bottom-right corner `(n - 1, n - 1)` where `maxScore = 0` and `ways = 1`.
3. Iterate backwards from `i = n - 1` down to `0` and `j = n - 1` down to `0`.
4. Skip any cell containing an obstacle `'X'` or the starting cell `(n - 1, n - 1)`.
5. For each valid cell, check the three possible next moves: down `(i + 1, j)`, right `(i, j + 1)`, and diagonal-down-right `(i + 1, j + 1)`. Aggregate the maximum score and accumulate the path counts modulo $10^9 + 7$.
6. Add the current cell's numeric value (`board[i][j] - '0'`) to the `bestScore` if reachable, and update `ways[i][j]`.
7. Finally, if `maxScore[0][0]` remains `-1`, return `{0, 0}`; otherwise, return `{maxScore[0][0], ways[0][0]}`.

# Complexity
- Time complexity: $$O(N^2)$$ — We iterate through each cell of the $n 	imes n$ board exactly once, performing constant number of checks per cell.
- Space complexity: $$O(N^2)$$ — Two 2D vectors `maxScore` and `ways` of size $n 	imes n$ are maintained to store the DP states.

# Code
```cpp
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int mod = 1e9 + 7;
        int n = board.size();

        vector<vector<int>> maxScore(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        maxScore[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(board[i][j] == 'X'){
                    continue;
                }

                if(i == n - 1 && j == n - 1){
                    continue;
                }

                int bestScore = -1;
                long long totalWays = 0;

                if(i + 1 < n && maxScore[i + 1][j] != -1){
                    if(maxScore[i + 1][j] > bestScore){
                        bestScore = maxScore[i + 1][j];
                        totalWays = ways[i + 1][j];
                    }else if(maxScore[i + 1][j] == bestScore){
                        totalWays = (totalWays + ways[i + 1][j]) % mod;
                    }
                }

                if(j + 1 < n && maxScore[i][j + 1] != -1){
                    if(maxScore[i][j + 1] > bestScore){
                        bestScore = maxScore[i][j + 1];
                        totalWays = ways[i][j + 1];
                    }else if(maxScore[i][j + 1] == bestScore){
                        totalWays = (totalWays + ways[i][j + 1]) % mod;
                    }
                }

                if(i + 1 < n && j + 1 < n && maxScore[i + 1][j + 1] != -1){
                    if(maxScore[i + 1][j + 1] > bestScore){
                        bestScore = maxScore[i + 1][j + 1];
                        totalWays = ways[i + 1][j + 1];
                    }else if(maxScore[i + 1][j + 1] == bestScore){
                        totalWays = (totalWays + ways[i + 1][j + 1]) % mod;
                    }
                }

                if(bestScore == -1){
                    continue;
                }

                int curr = 0;
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    curr = board[i][j] - '0';
                }

                maxScore[i][j] = bestScore + curr;
                ways[i][j] = totalWays % mod;
            }
        }

        if(maxScore[0][0] == -1){
            return {0, 0};
        }

        return {maxScore[0][0], ways[0][0]};
    }
};
```

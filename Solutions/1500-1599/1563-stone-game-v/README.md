# [1563. Stone Game V](https://leetcode.com/problems/stone-game-v/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `dynamic-programming`, `game-theory`

---

## Problem Description
There are several stones **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.

In each round of the game, Alice divides the row into **two non-empty rows** (i.e. left row and right row), then Bob calculates the value of each row which is the sum of the values of all the stones in this row. Bob throws away the row which has the maximum value, and Alice's score increases by the value of the remaining row. If the value of the two rows are equal, Bob lets Alice decide which row will be thrown away. The next round starts with the remaining row.

The game ends when there is only **one stone remaining**. Alice's score is initially **zero**.

Return *the maximum score that Alice can obtain*.

**Example 1:**

```
Input: stoneValue = [6,2,3,4,5,5]
Output: 18
Explanation: In the first round, Alice divides the row to [6,2,3], [4,5,5]. The left row has the value 11 and the right row has value 14. Bob throws away the right row and Alice's score is now 11.
In the second round Alice divides the row to [6], [2,3]. This time Bob throws away the left row and Alice's score becomes 16 (11 + 5).
The last round Alice has only one choice to divide the row which is [2], [3]. Bob throws away the right row and Alice's score is now 18 (16 + 2). The game ends because only one stone is remaining in the row.
```

**Example 2:**

```
Input: stoneValue = [7,7,7,7,7,7,7]
Output: 28
```

**Example 3:**

```
Input: stoneValue = [4]
Output: 0
```

**Constraints:**

* `1 <= stoneValue.length <= 500`
* `1 <= stoneValue[i] <= 106`

---

## Solution & Editorial
# Intuition
The problem asks us to find the maximum score Alice can achieve by recursively splitting a range of stones. Since the state depends on the range `[l, r]` and we need to choose a split point `k` such that we maximize the score, a naive $O(N^3)$ approach would involve iterating over all possible split points for every range. We can optimize this to $O(N^2)$ by observing that the choice of the split point is monotonic relative to the prefix sums, allowing us to use two pointers to maintain the optimal split ranges.

# Approach
1. **Prefix Sums**: Precompute `prefix` sums to calculate the sum of any subarray `[l, r]` in $O(1)$ time.
2. **DP State**: Define `dp[l][r]` as the maximum score obtainable from the range `[l, r]`. 
3. **Optimization**: For a range `[l, r]`, we split at `k`. If `leftSum < rightSum`, Alice gets `leftSum + dp[l][k]`. If `leftSum > rightSum`, Alice gets `rightSum + dp[k+1][r]`. If `leftSum == rightSum`, Alice gets `max(dp[l][k], dp[k+1][r]) + leftSum`.
4. **Two Pointers**: Instead of iterating all `k`, we maintain `leftPtr` and `rightPtr` to track the boundaries where `leftSum` is less than or equal to `rightSum`. This allows us to query the best previous DP values in $O(1)$ amortized time.

### Visual Trace (Example 1: [6, 2, 3, 4, 5, 5])
| Range | Split Point | Left Sum | Right Sum | Action |
| :--- | :--- | :--- | :--- | :--- |
| [0, 5] | 2 | 11 | 14 | Keep Left (11) |
| [0, 2] | 0 | 6 | 5 | Keep Right (5) |
| [1, 2] | 1 | 2 | 3 | Keep Left (2) |

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the number of stones. The nested loops iterate over all possible ranges, and the two pointers move monotonically, ensuring each state is processed efficiently.
- Space complexity: $$O(N^2)$$ to store the `dp`, `leftBest`, and `rightBest` tables.

# Code
```cpp
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        vector<vector<int>> leftBest(n, vector<int>(n, 0));

        vector<vector<int>> rightBest(n, vector<int>(n, 0));

        vector<int> leftPtr(n);

        vector<int> rightPtr(n);

        for (int i = 0; i < n; ++i) {
            leftBest[i][i] = stoneValue[i];
            rightBest[i][i] = stoneValue[i];

            leftPtr[i] = i - 1;

            rightPtr[i] = i;
        }

        for (int len = 2; len <= n; ++len) {
            for (int l = 0; l + len <= n; ++l) {
                int r = l + len - 1;

                long long total = prefix[r + 1] - prefix[l];

                while (leftPtr[l] + 1 <= r - 1) {
                    int k = leftPtr[l] + 1;
                    long long leftSum = prefix[k + 1] - prefix[l];

                    if (2 * leftSum > total) {
                        break;
                    }

                    ++leftPtr[l];
                }

                while (rightPtr[l] <= r - 1) {
                    int k = rightPtr[l];
                    long long leftSum = prefix[k + 1] - prefix[l];

                    if (2 * leftSum >= total) {
                        break;
                    }

                    ++rightPtr[l];
                }

                int best = 0;

                if (leftPtr[l] >= l) {
                    best = leftBest[l][leftPtr[l]];
                }

                if (rightPtr[l] <= r - 1) {
                    best = max(best, rightBest[rightPtr[l] + 1][r]);
                }

                dp[l][r] = best;

                leftBest[l][r] = max(
                    leftBest[l][r - 1],
                    dp[l][r] + static_cast<int>(total)
                );

                rightBest[l][r] = max(
                    rightBest[l + 1][r],
                    dp[l][r] + static_cast<int>(total)
                );
            }
        }

        return dp[0][n - 1];
    }
};
```

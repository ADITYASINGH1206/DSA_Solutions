# [3414. Maximum Score of Non-overlapping Intervals](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/)
**Difficulty:** `Hard` | **Tags:** `array`, `binary-search`, `dynamic-programming`, `sorting`

---

## Problem Description
You are given a 2D integer array `intervals`, where `intervals[i] = [li, ri, weighti]`. Interval `i` starts at position `li` and ends at `ri`, and has a weight of `weighti`. You can choose *up to* 4 **non-overlapping** intervals. The **score** of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from `intervals` with **maximum** score, representing your choice of non-overlapping intervals.

Two intervals are said to be **non-overlapping** if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.

**Example 1:**

**Input:** intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]

**Output:** [2,3]

**Explanation:**

You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.

**Example 2:**

**Input:** intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]

**Output:** [1,3,5,6]

**Explanation:**

You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.

**Constraints:**

* `1 <= intevals.length <= 5 * 104`
* `intervals[i].length == 3`
* `intervals[i] = [li, ri, weighti]`
* `1 <= li <= ri <= 109`
* `1 <= weighti <= 109`

---

## Solution & Editorial
# Intuition
To maximize the total weight of up to 4 non-overlapping intervals, we can frame this as a variation of the Weighted Interval Scheduling problem. Since we need to select at most 4 intervals and return the lexicographically smallest set of indices, we use dynamic programming where `dp[k][i]` stores the best selection of `k` non-overlapping intervals considering the first `i` intervals sorted by their end times.

# Approach
1. **Sorting**: Sort all intervals by their end times (`r_i`). This allows us to use binary search to efficiently find the rightmost interval that ends before the current interval starts.
2. **DP State**: Let `dp[k][i]` be the optimal `Node` (containing total weight and sorted indices) using `k` intervals from the first `i` sorted intervals.
3. **Transition**: For each interval `i` (with weight `w` and start `l`), we have two choices:
   - **Exclude**: `dp[k][i] = dp[k][i-1]`.
   - **Include**: Find the largest index `p` such that `intervals[p].r < l` using `std::lower_bound`. If `dp[k-1][p]` is valid, form a new candidate by adding the current interval's index to the set of indices from `dp[k-1][p]`.
4. **Lexicographical Requirement**: When comparing two `Node` objects, if scores are equal, we compare the sorted index vectors to ensure the lexicographically smallest result.

### Visual Trace (Example 1)
Intervals sorted by end time: `[[1,3,2], [4,5,2], [1,5,5], [6,7,1], [6,9,3], [8,9,1]]`
- `dp[k][i]` tracks the best score and indices for `k` intervals using a subset of the first `i` sorted intervals.
- Binary search finds the last compatible interval index `p` such that `intervals[p].r < current.l`.

# Complexity
- Time complexity: $$O(N \log N + N \cdot K \cdot K \log K)$$, where $$N$$ is the number of intervals and $$K=4$$. Sorting takes $$O(N \log N)$$, and the DP table filling involves $$N \times K$$ states, each performing a binary search ($$\log N$$) and a vector copy/sort ($$K \log K$$).
- Space complexity: $$O(N \cdot K^2)$$ to store the indices in the DP table.

# Code
```cpp
class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
        bool valid;

        Node() : score(0), valid(false) {}
        Node(long long s, vector<int> v) : score(s), ids(std::move(v)), valid(true) {}
    };

    bool better(const Node& a, const Node& b) {
        if (!a.valid) return false;
        if (!b.valid) return true;

        if (a.score != b.score) return a.score > b.score;

        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        const int K = 4;

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; ++i) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            return x[1] < y[1];
        });

        vector<long long> ends(n);
        for (int i = 0; i < n; ++i) {
            ends[i] = a[i][1];
        }

        vector<vector<Node>> dp(K + 1, vector<Node>(n + 1));

        for (int i = 0; i <= n; ++i) {
            dp[0][i] = Node(0, {});
        }

        for (int i = 1; i <= n; ++i) {
            long long l = a[i - 1][0];
            long long w = a[i - 1][2];
            int idx = (int)a[i - 1][3];

            int p = lower_bound(ends.begin(), ends.begin() + (i - 1), l) - ends.begin();

            for (int k = 1; k <= K; ++k) {
                dp[k][i] = dp[k][i - 1];

                if (dp[k - 1][p].valid) {
                    vector<int> ids = dp[k - 1][p].ids;

                    ids.push_back(idx);

                    sort(ids.begin(), ids.end());

                    Node take(dp[k - 1][p].score + w, std::move(ids));

                    if (better(take, dp[k][i])) {
                        dp[k][i] = std::move(take);
                    }
                }
            }
        }

        Node ans;

        for (int k = 1; k <= K; ++k) {
            if (better(dp[k][n], ans)) {
                ans = dp[k][n];
            }
        }

        return ans.ids;
    }
};
```

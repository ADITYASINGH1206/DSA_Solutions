# [2389. Longest Subsequence With Limited Sum](https://leetcode.com/problems/longest-subsequence-with-limited-sum/)
**Difficulty:** `Easy` | **Tags:** `array`, `binary-search`, `greedy`, `sorting`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` of length `n`, and an integer array `queries` of length `m`.

Return *an array* `answer` *of length* `m` *where* `answer[i]` *is the **maximum** size of a **subsequence** that you can take from* `nums` *such that the **sum** of its elements is less than or equal to* `queries[i]`.

A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```
Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
```

**Example 2:**

```
Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.
```

**Constraints:**

* `n == nums.length`
* `m == queries.length`
* `1 <= n, m <= 1000`
* `1 <= nums[i], queries[i] <= 106`

---

## Solution & Editorial
# Intuition
To maximize the size of a subsequence with a sum less than or equal to a target, we should always pick the smallest available elements first. By sorting the array, we ensure that we can greedily select the smallest elements to keep the sum as low as possible while maximizing the count.

# Approach
1. **Sort**: Sort the `nums` array in non-decreasing order. This allows us to build the smallest possible subsequence sum for any given length.
2. **Prefix Sum**: Compute the prefix sums of the sorted `nums`. `pre_sum[j]` will represent the sum of the smallest `j+1` elements.
3. **Query Processing**: For each query in `queries`, iterate through the `pre_sum` array. Since `pre_sum` is monotonically increasing, we find the largest index `j` such that `pre_sum[j] <= queries[i]`. The answer for that query is `j + 1`.

### Visual Trace (Example 1: nums=[4,5,2,1], queries=[3,10,21])
- Sorted `nums`: `[1, 2, 4, 5]`
- `pre_sum`: `[1, 3, 7, 12]`

| Query | Comparison with `pre_sum` | Max Index `j` | Result (`j+1`) |
| :--- | :--- | :--- | :--- |
| 3 | `1 <= 3`, `3 <= 3`, `7 > 3` | 1 | 2 |
| 10 | `1 <= 10`, `3 <= 10`, `7 <= 10`, `12 > 10` | 2 | 3 |
| 21 | `1, 3, 7, 12 <= 21` | 3 | 4 |

# Complexity
- Time complexity: $$O(N \log N + M \cdot N)$$, where $$N$$ is the length of `nums` and $$M$$ is the length of `queries`. Sorting takes $$O(N \log N)$$, and for each of the $$M$$ queries, we perform a linear scan of the prefix sum array of size $$N$$.
- Space complexity: $$O(N)$$, required to store the prefix sum array.

# Code
```cpp
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin(), nums.end());
        int sum = 0;
        vector<int> pre_sum;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pre_sum.push_back(sum);
        }

        vector<int> ans(m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pre_sum[j] <= queries[i])
                    ans[i] = j + 1;
                else
                    break;
            }
        }
        return ans;
    }
};
```

# [3488. Closest Equal Element Queries](https://leetcode.com/problems/closest-equal-element-queries/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `binary-search`

---

## Problem Description
You are given a **circular** array `nums` and an array `queries`.

For each query `i`, you have to find the following:

* The **minimum** distance between the element at index `queries[i]` and **any** other index `j` in the **circular** array, where `nums[j] == nums[queries[i]]`. If no such index exists, the answer for that query should be -1.

Return an array `answer` of the **same** size as `queries`, where `answer[i]` represents the result for query `i`.

**Example 1:**

**Input:** nums = [1,3,1,4,1,3,2], queries = [0,3,5]

**Output:** [2,-1,3]

**Explanation:**

* Query 0: The element at `queries[0] = 0` is `nums[0] = 1`. The nearest index with the same value is 2, and the distance between them is 2.
* Query 1: The element at `queries[1] = 3` is `nums[3] = 4`. No other index contains 4, so the result is -1.
* Query 2: The element at `queries[2] = 5` is `nums[5] = 3`. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: `5 -> 6 -> 0 -> 1`).

**Example 2:**

**Input:** nums = [1,2,3,4], queries = [0,1,2,3]

**Output:** [-1,-1,-1,-1]

**Explanation:**

Each value in `nums` is unique, so no index shares the same value as the queried element. This results in -1 for all queries.

**Constraints:**

* `1 <= queries.length <= nums.length <= 105`
* `1 <= nums[i] <= 106`
* `0 <= queries[i] < nums.length`

---

## Solution & Editorial
# Intuition
To handle the circular nature of the array, we can linearize the problem by concatenating the array with itself (doubling the size to $2N$). This allows us to treat circular distances as linear distances within the range $[0, 2N-1]$. By calculating the distance to the nearest identical element to the left and right for every index, we can determine the minimum distance for any query.

# Approach
1. Create a doubled array representation by iterating up to $2N$. We maintain two maps (or arrays) to track the last seen index of each value.
2. **Left Pass**: Iterate from $0$ to $2N-1$. For each index $i$, calculate the distance to the previous occurrence of `nums[i % n]` and store the minimum in `d[i]`.
3. **Right Pass**: Iterate from $2N-1$ down to $0$. For each index $i$, calculate the distance to the next occurrence of `nums[i % n]` and update `d[i]` with the minimum of its current value and the new distance.
4. **Circular Reduction**: Since the array is circular, the distance for an index $i < N$ is the minimum of `d[i]` and `d[i + n]`.
5. **Query Resolution**: For each query, if the calculated distance is $\ge N$, it means no other index contains the same value, so return -1; otherwise, return the distance.

### Visual Trace (Example 1: nums = [1,3,1,4,1,3,2])
| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Value | 1 | 3 | 1 | 4 | 1 | 3 | 2 | 1 | 3 | 1 | 4 | 1 | 3 | 2 |
| Min Dist | 2 | 4 | 2 | inf | 2 | 4 | inf | 2 | 4 | 2 | inf | 2 | 4 | inf |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the size of the array. We perform a constant number of passes over an array of size $2N$.
- Space complexity: $$O(N)$$, required for the distance array `d` and the hash maps used to track indices.

# Code
```cpp
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = n * 2;
        vector<int> d(m, m);

        unordered_map<int, int> left;
        for (int i = 0; i < m; i++) {
            int x = nums[i % n];
            if (left.count(x)) {
                d[i] = min(d[i], i - left[x]);
            }
            left[x] = i;
        }

        unordered_map<int, int> right;
        for (int i = m - 1; i >= 0; i--) {
            int x = nums[i % n];
            if (right.count(x)) {
                d[i] = min(d[i], right[x] - i);
            }
            right[x] = i;
        }

        for (int i = 0; i < n; i++) {
            d[i] = min(d[i], d[i + n]);
        }

        vector<int> ans;
        for (int query : queries) {
            ans.push_back(d[query] >= n ? -1 : d[query]);
        }
        return ans;
    }
};
```

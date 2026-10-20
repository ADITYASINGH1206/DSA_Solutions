# [3653. XOR After Range Multiplication Queries I](https://leetcode.com/problems/xor-after-range-multiplication-queries-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `divide-and-conquer`, `simulation`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` of length `n` and a 2D integer array `queries` of size `q`, where `queries[i] = [li, ri, ki, vi]`.

For each query, you must apply the following operations in order:

* Set `idx = li`.
* While `idx <= ri`:
  + Update: `nums[idx] = (nums[idx] * vi) % (109 + 7)`
  + Set `idx += ki`.

Return the **bitwise XOR** of all elements in `nums` after processing all queries.

**Example 1:**

**Input:** nums = [1,1,1], queries = [[0,2,1,4]]

**Output:** 4

**Explanation:**

* A single query `[0, 2, 1, 4]` multiplies every element from index 0 through index 2 by 4.
* The array changes from `[1, 1, 1]` to `[4, 4, 4]`.
* The XOR of all elements is `4 ^ 4 ^ 4 = 4`.

**Example 2:**

**Input:** nums = [2,3,1,5,4], queries = [[1,4,2,3],[0,2,1,2]]

**Output:** 31

**Explanation:**

* The first query `[1, 4, 2, 3]` multiplies the elements at indices 1 and 3 by 3, transforming the array to `[2, 9, 1, 15, 4]`.
* The second query `[0, 2, 1, 2]` multiplies the elements at indices 0, 1, and 2 by 2, resulting in `[4, 18, 2, 15, 4]`.
* Finally, the XOR of all elements is `4 ^ 18 ^ 2 ^ 15 ^ 4 = 31`.​​​​​​​**​​​​​​​**

**Constraints:**

* `1 <= n == nums.length <= 103`
* `1 <= nums[i] <= 109`
* `1 <= q == queries.length <= 103`
* `queries[i] = [li, ri, ki, vi]`
* `0 <= li <= ri < n`
* `1 <= ki <= n`
* `1 <= vi <= 105`

---

## Solution & Editorial
# Intuition
The problem asks us to perform a series of range-based multiplication updates on an array and then compute the XOR sum of the final elements. Given the constraints ($N, Q \le 10^3$), a direct simulation of each query is efficient enough to pass within the time limits.

# Approach
1. Iterate through each query `[li, ri, ki, vi]` in the `queries` array.
2. For each query, initialize a pointer `idx` at `li`.
3. While `idx <= ri`, update `nums[idx]` by multiplying it with `vi` modulo $10^9 + 7$. Increment `idx` by `ki` in each step.
4. After processing all queries, iterate through the modified `nums` array and compute the cumulative bitwise XOR sum.

### Visual Trace (Example 2)
`nums = [2, 3, 1, 5, 4]`, `queries = [[1, 4, 2, 3], [0, 2, 1, 2]]`

| Query | Initial | Update Indices | Resulting `nums` |
| :--- | :--- | :--- | :--- |
| [1, 4, 2, 3] | [2, 3, 1, 5, 4] | 1, 3 | [2, 9, 1, 15, 4] |
| [0, 2, 1, 2] | [2, 9, 1, 15, 4] | 0, 1, 2 | [4, 18, 2, 15, 4] |

Final XOR: `4 ^ 18 ^ 2 ^ 15 ^ 4 = 31`.

# Complexity
- Time complexity: $$O(Q \cdot \frac{N}{K_{avg}})$$, where $Q$ is the number of queries and $N$ is the array length. In the worst case ($K=1$), this is $O(Q \cdot N)$. Given $N, Q \le 10^3$, $10^6$ operations are well within the time limit.
- Space complexity: $$O(1)$$, as we perform the updates in-place and only use a few auxiliary variables.

# Code
```cpp
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = 1LL * nums[idx] * v % mod;
            }
        }
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
```

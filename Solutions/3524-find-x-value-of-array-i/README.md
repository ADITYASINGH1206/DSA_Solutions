# [3524. Find X Value of Array I](https://leetcode.com/problems/find-x-value-of-array-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `dynamic-programming`

---

## Problem Description
You are given an array of **positive** integers `nums`, and a **positive** integer `k`.

You are allowed to perform an operation **once** on `nums`, where in each operation you can remove any **non-overlapping** prefix and suffix from `nums` such that `nums` remains **non-empty**.

You need to find the **x-value** of `nums`, which is the number of ways to perform this operation so that the **product** of the remaining elements leaves a *remainder* of `x` when divided by `k`.

Return an array `result` of size `k` where `result[x]` is the **x-value** of `nums` for `0 <= x <= k - 1`.

A **prefix** of an array is a subarray that starts from the beginning of the array and extends to any point within it.

A **suffix** of an array is a subarray that starts at any point within the array and extends to the end of the array.

**Note** that the prefix and suffix to be chosen for the operation can be **empty**.

**Example 1:**

**Input:** nums = [1,2,3,4,5], k = 3

**Output:** [9,2,4]

**Explanation:**

* For `x = 0`, the possible operations include all possible ways to remove non-overlapping prefix/suffix that do not remove `nums[2] == 3`.
* For `x = 1`, the possible operations are:
  + Remove the empty prefix and the suffix `[2, 3, 4, 5]`. `nums` becomes `[1]`.
  + Remove the prefix `[1, 2, 3]` and the suffix `[5]`. `nums` becomes `[4]`.
* For `x = 2`, the possible operations are:
  + Remove the empty prefix and the suffix `[3, 4, 5]`. `nums` becomes `[1, 2]`.
  + Remove the prefix `[1]` and the suffix `[3, 4, 5]`. `nums` becomes `[2]`.
  + Remove the prefix `[1, 2, 3]` and the empty suffix. `nums` becomes `[4, 5]`.
  + Remove the prefix `[1, 2, 3, 4]` and the empty suffix. `nums` becomes `[5]`.

**Example 2:**

**Input:** nums = [1,2,4,8,16,32], k = 4

**Output:** [18,1,2,0]

**Explanation:**

* For `x = 0`, the only operations that **do not** result in `x = 0` are:
  + Remove the empty prefix and the suffix `[4, 8, 16, 32]`. `nums` becomes `[1, 2]`.
  + Remove the empty prefix and the suffix `[2, 4, 8, 16, 32]`. `nums` becomes `[1]`.
  + Remove the prefix `[1]` and the suffix `[4, 8, 16, 32]`. `nums` becomes `[2]`.
* For `x = 1`, the only possible operation is:
  + Remove the empty prefix and the suffix `[2, 4, 8, 16, 32]`. `nums` becomes `[1]`.
* For `x = 2`, the possible operations are:
  + Remove the empty prefix and the suffix `[4, 8, 16, 32]`. `nums` becomes `[1, 2]`.
  + Remove the prefix `[1]` and the suffix `[4, 8, 16, 32]`. `nums` becomes `[2]`.
* For `x = 3`, there is no possible way to perform the operation.

**Example 3:**

**Input:** nums = [1,1,2,1,1], k = 2

**Output:** [9,6]

**Constraints:**

* `1 <= nums[i] <= 109`
* `1 <= nums.length <= 105`
* `1 <= k <= 5`

---

## Solution & Editorial
# Intuition
The problem asks us to count the number of subarrays (formed by removing a prefix and a suffix) whose product modulo $k$ equals $x$. Since $k$ is very small ($k \le 5$), we can maintain the counts of all possible remainders of subarrays ending at the current index. By iterating through the array, we can update these counts dynamically.

# Approach
1. We maintain a `state` vector of size $k$, where `state[r]` stores the number of subarrays ending at the previous index that have a product modulo $k$ equal to $r$.
2. For each element `value` in `nums`, we calculate its remainder `rem = value % k`.
3. We create a `next` state vector. For every existing remainder `r` in `state`, the new product modulo $k$ becomes `(r * rem) % k`. We add `state[r]` to `next[(r * rem) % k]`.
4. We also consider the subarray consisting only of the current element `value`, which has a remainder of `rem`. We increment `next[rem]` by 1.
5. We accumulate these counts into the global `ans` array to track the total number of valid subarrays found across all positions.

### Visual Trace (nums = [1, 2, 3], k = 3)
| Step | Value | State (r=0,1,2) | Ans (r=0,1,2) |
| :--- | :--- | :--- | :--- |
| Init | - | [0, 0, 0] | [0, 0, 0] |
| 1 | 1 | [0, 1, 0] | [0, 1, 0] |
| 2 | 2 | [0, 1, 1] | [0, 2, 1] |
| 3 | 3 | [0, 0, 0] | [3, 2, 1] |

# Complexity
- Time complexity: $$O(N \cdot K)$$, where $N$ is the length of `nums` and $K \le 5$. We iterate through the array once, and for each element, we perform a constant number of operations proportional to $K$.
- Space complexity: $$O(K)$$, as we only store the `state` and `next` vectors of size $K$.

# Code
```cpp
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), state(k);
        for (int value : nums) {
            int rem = value % k;
            vector<long long> next(k);
            for (int r = 0; r < k; r++) {
                int productRem = (r * rem) % k;
                next[productRem] += state[r];
                ans[productRem] += state[r];
            }
            next[rem]++;
            ans[rem]++;
            state = next;
        }
        return ans;
    }
};
```

# [3987. Minimum Total Cost to Process All Elements](https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `simulation`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

Initially, you have `k` units of resources.

You must process the elements of `nums` from left to right. To process the `ith` element, you need `nums[i]` resources.

If your available resources are less than `nums[i]`, you may perform an operation that increases your available resources by `k`. The value of `k` is fixed and does not change throughout the process. The first such operation incurs a cost of 1, the second incurs a cost of 2, and so on.

After processing the `ith` element, your available resources decrease by `nums[i]`.

Return an integer denoting the **minimum total cost** required to process all elements. Since the answer may be very large, return it **modulo** `109 + 7`.

**Example 1:**

**Input:** nums = [1,2,3,4], k = 4

**Output:** 3

**Explanation:**

* After processing `nums[0]`, we have `4 - 1 = 3` units of resources left.
* After processing `nums[1]`, we have `3 - 2 = 1` unit of resources left.
* Since `nums[2] = 3` and only 1 unit of resources is available, we perform the first operation costing 1. After processing `nums[2]`, we have `1 + 4 - 3 = 2` units of resources left.
* Since `nums[3] = 4` and only 2 units of resources are available, we perform the second operation costing 2, to have `2 + 4 = 6` units of resources, which is enough to process `nums[3]`.
* Thus, the total cost is `1 + 2 = 3`.

**Example 2:**

**Input:** nums = [1,1,7,14], k = 4

**Output:** 15

**Explanation:**

* After processing `nums[0]`, we have `4 - 1 = 3` units of resources left.
* After processing `nums[1]`, we have `3 - 1 = 2` units of resources left.
* Since `nums[2] = 7` and only 2 units of resources are available, we perform two operations costing `1 + 2 = 3`. After processing `nums[2]`, we have `2 + 4 + 4 - 7 = 3` units of resources left.
* Since `nums[3] = 14` and only 3 units of resources are available, we perform three operations costing `3 + 4 + 5 = 12`, to have `3 + 4 + 4 + 4 = 15` units of resources, which is enough to process `nums[3]`.
* Thus, the total cost is `3 + 12 = 15`.

**Example 3:**

**Input:** nums = [1,2,3,4], k = 10

**Output:** 0

**Explanation:**

To process all elements, we can use the initial 10 units of resources without performing any operations. Thus, the total cost required is 0.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`
* `1 <= k <= 109`

---

## Solution & Editorial
# Intuition
To process each element `nums[i]`, we maintain a running balance of available resources `cr`. When `cr` is insufficient, we must perform the minimum number of operations to cover the deficit. Since each operation adds `k` resources and costs an increasing amount (1, 2, 3...), the total cost for a sequence of operations is the sum of an arithmetic progression.

# Approach
1. Initialize `cr = k` (initial resources), `ops = 0` (total operations performed so far), and `ans = 0` (total cost).
2. Iterate through each `nums[i]`:
   - If `cr < nums[i]`, calculate the deficit `need = nums[i] - cr`.
   - Determine the number of refills required: `refil = ceil(need / k)`, calculated as `(need + k - 1) / k`.
   - The cost of these new operations is the sum of integers from `ops + 1` to `ops + refil`. This is computed using the formula for the sum of an arithmetic series: `sum(1 to n) = n * (n + 1) / 2`.
   - Update `ans` by adding the difference `sum(ops + refil) - sum(ops)` modulo `10^9 + 7`.
   - Update `cr` by adding `refil * k` and increment `ops` by `refil`.
   - Subtract `nums[i]` from `cr`.

### Visual Trace (Example 1: nums=[1,2,3,4], k=4)
| Step | nums[i] | cr (pre) | Need | Refills | Cost | ops | cr (post) |
|---|---|---|---|---|---|---|---|
| 0 | 1 | 4 | 0 | 0 | 0 | 0 | 3 |
| 1 | 2 | 3 | 0 | 0 | 0 | 0 | 1 |
| 2 | 3 | 1 | 2 | 1 | 1 | 1 | 2 |
| 3 | 4 | 2 | 2 | 1 | 2 | 2 | 2 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. We iterate through the array exactly once, performing constant-time arithmetic operations at each step.
- Space complexity: $$O(1)$$, as we only use a few `long long` variables to track state.

# Code
```cpp
class Solution {
public:
    const int MOD = 1000000007;

    long long sum_n(long long n) {
        if (n % 2 == 0) {
            return ((n / 2) % MOD) * ((n + 1) % MOD) % MOD;
        } else {

            return (n % MOD) * (((n + 1) / 2) % MOD) % MOD;
        }
    }


    int minimumCost(vector<int>& nums, int k) {
        long long cr = k;
        long long ops = 0;
        long long ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (cr < nums[i]) {
                long long need = nums[i] - cr;
                long long refil = (need + k - 1) / k;
                long long dif = (sum_n(ops + refil) - sum_n(ops) + MOD) % MOD;

                ans = (ans + dif) % MOD;
                cr += refil * (long long)k;
                ops += refil;
            }
            cr -= nums[i];
        }
        
        return ans;
    }
};
```

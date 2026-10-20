# [3824. Minimum K to Reduce Array Within Limit](https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`

---

## Problem Description
You are given a **positive** integer array `nums`.

For a positive integer `k`, define `nonPositive(nums, k)` as the **minimum** number of **operations** needed to make every element of `nums` **non-positive**. In one operation, you can choose an index `i` and reduce `nums[i]` by `k`.

Return an integer denoting the **minimum** value of `k` such that `nonPositive(nums, k) <= k2`.

**Example 1:**

**Input:** nums = [3,7,5]

**Output:** 3

**Explanation:**

When `k = 3`, `nonPositive(nums, k) = 6 <= k2`.

* Reduce `nums[0] = 3` one time. `nums[0]` becomes `3 - 3 = 0`.
* Reduce `nums[1] = 7` three times. `nums[1]` becomes `7 - 3 - 3 - 3 = -2`.
* Reduce `nums[2] = 5` two times. `nums[2]` becomes `5 - 3 - 3 = -1`.

**Example 2:**

**Input:** nums = [1]

**Output:** 1

**Explanation:**

When `k = 1`, `nonPositive(nums, k) = 1 <= k2`.

* Reduce `nums[0] = 1` one time. `nums[0]` becomes `1 - 1 = 0`.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
The problem asks for the minimum positive integer $k$ such that the total number of operations required to reduce all elements in `nums` to non-positive values is at most $k^2$. Since the total number of operations is monotonically decreasing as $k$ increases, and the condition $total \le k^2$ becomes easier to satisfy as $k$ grows, we can employ binary search on the possible values of $k$.

# Approach
1. **Binary Search Range**: The minimum possible value for $k$ is 1. The maximum possible value is the maximum element in `nums` (or a sufficiently large upper bound like $10^9$), as $k$ equal to the maximum element reduces every number in exactly 1 operation, and $1 \times N \le N^2$ is generally true for $N \ge 1$.
2. **Check Function**: For a chosen $k$, the number of operations to reduce a single element $p$ to $\le 0$ is $\lceil p/k \rceil$, which can be calculated using integer division as `(p + k - 1) / k`.
3. **Condition**: Sum these operations for all elements in `nums`. If the sum is $\le k^2$, then $k$ is a candidate, and we try smaller values by setting `high = k - 1`. Otherwise, we need a larger $k$, so we set `low = k + 1`.

### Visual Trace (Example 1: nums = [3, 7, 5])
| Iteration | low | high | k | total ops | total <= k^2 | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | 10^9 | 500M | 3 | Yes | ans=500M, high=499M |
| ... | ... | ... | ... | ... | ... | ... |
| Final | 1 | 2 | 3 | 1+3+2=6 | 6 <= 9 (Yes) | ans=3, high=2 |

# Complexity
- Time complexity: $$O(N \log(\text{max\_val}))$$ where $N$ is the length of `nums` and $\text{max\_val}$ is the upper bound of the binary search ($10^9$). We iterate through the array for each step of the binary search.
- Space complexity: $$O(1)$$ as we only use a few variables for the binary search and summation, ignoring the input storage.

# Code
```cpp
class Solution {
public:
    int minimumK(vector<int>& nums) {
        vector<int> v = nums;
        long long low=1;
        long long high = 1000000000;
        long long ans = high;
        while(low<=high){
            long long k = low + (high-low )/2;
            long long total = 0;
            for(int p:v){
                total += (p+k-1)/k;
            }
            if(total <= k*k){
                ans = k;
                high = k-1;
            }else{
                low = k+1;
            }
        }
        return (int)ans;
        
    }
};
```

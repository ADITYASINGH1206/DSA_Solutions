# [3013. Divide an Array Into Subarrays With Minimum Cost II](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `sliding-window`, `heap-priority-queue`

---

## Problem Description
You are given a **0-indexed** array of integers `nums` of length `n`, and two **positive** integers `k` and `dist`.

The **cost** of an array is the value of its **first** element. For example, the cost of `[1,2,3]` is `1` while the cost of `[3,4,1]` is `3`.

You need to divide `nums` into `k` **disjoint contiguous** subarrays, such that the difference between the starting index of the **second** subarray and the starting index of the `kth` subarray should be **less than or equal to** `dist`. In other words, if you divide `nums` into the subarrays `nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)]`, then `ik-1 - i1 <= dist`.

Return *the **minimum** possible sum of the cost of these* *subarrays*.

**Example 1:**

```
Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
Output: 5
Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.
```

**Example 2:**

```
Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
Output: 15
Explanation: The best possible way to divide nums into 4 subarrays is: [10], [1], [2], and [2,2,1]. This choice is valid because ik-1 - i1 is 3 - 1 = 2 which is less than dist. The total cost is nums[0] + nums[1] + nums[2] + nums[3] which is 10 + 1 + 2 + 2 = 15.
The division [10], [1], [2,2,2], and [1] is not valid, because the difference between ik-1 and i1 is 5 - 1 = 4, which is greater than dist.
It can be shown that there is no possible way to divide nums into 4 subarrays at a cost lower than 15.
```

**Example 3:**

```
Input: nums = [10,8,18,9], k = 3, dist = 1
Output: 36
Explanation: The best possible way to divide nums into 3 subarrays is: [10], [8], and [18,9]. This choice is valid because ik-1 - i1 is 2 - 1 = 1 which is equal to dist.The total cost is nums[0] + nums[1] + nums[2] which is 10 + 8 + 18 = 36.
The division [10], [8,18], and [9] is not valid, because the difference between ik-1 and i1 is 3 - 1 = 2, which is greater than dist.
It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 36.
```

**Constraints:**

* `3 <= n <= 105`
* `1 <= nums[i] <= 109`
* `3 <= k <= n`
* `k - 2 <= dist <= n - 2`

---

## Solution & Editorial
# Intuition
The problem asks us to partition an array into $k$ subarrays such that the sum of the costs (the first element of each subarray) is minimized. Since the first element of the first subarray is always `nums[0]`, we need to select $k-1$ additional indices from the range `[1, n-1]` such that the distance between the first and last selected index is at most `dist`. This effectively reduces to finding the $k-1$ smallest elements in a sliding window of size `dist + 1`.

# Approach
1. We fix the first subarray starting at index 0. We need to choose $k-1$ additional starting indices from the range `[1, n-1]`.
2. The constraint $i_{k-1} - i_1 \le dist$ implies that for any valid partition, the $k-1$ indices must fall within a window of size `dist + 1`.
3. We maintain two multisets: `l` (storing the $k-1$ smallest elements) and `r` (storing the remaining elements in the current window).
4. As the window slides, we remove the element that falls out of the window and add the new element, rebalancing `l` and `r` to ensure `l` always contains the $k-1$ smallest values.

### Visual Trace (Example 1: nums=[1,3,2,6,4,2], k=3, dist=3)
- Initial window (indices 1 to 4): `{3, 2, 6, 4}`. $k-1=2$.
- `l` stores `{2, 3}`, `r` stores `{4, 6}`. Sum = $1 + 2 + 3 = 6$.
- Slide window: remove `nums[1]=3`, add `nums[5]=2`.
- New window (indices 2 to 5): `{2, 6, 4, 2}`. Smallest 2 are `{2, 2}`.
- `l` becomes `{2, 2}`, `r` becomes `{4, 6}`. Sum = $1 + 2 + 2 = 5$.

# Complexity
- Time complexity: $$O(N \log K)$$, where $N$ is the array size. Each insertion and deletion in the `multiset` takes logarithmic time relative to the number of elements stored ($K$).
- Space complexity: $$O(N)$$, required to store the elements in the multisets within the sliding window.

# Code
```cpp
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        --k;
        multiset<int> l(nums.begin() + 1, nums.begin() + dist + 2), r;
        long long s = accumulate(nums.begin(), nums.begin() + dist + 2, 0LL);
        while (l.size() > k) {
            int x = *l.rbegin();
            l.erase(l.find(x));
            s -= x;
            r.insert(x);
        }
        long long ans = s;
        for (int i = dist + 2; i < nums.size(); ++i) {
            int x = nums[i - dist - 1];
            auto it = l.find(x);
            if (it != l.end()) {
                l.erase(it);
                s -= x;
            } else {
                r.erase(r.find(x));
            }
            int y = nums[i];
            if (y < *l.rbegin()) {
                l.insert(y);
                s += y;
            } else {
                r.insert(y);
            }
            while (l.size() == k - 1) {
                int x = *r.begin();
                r.erase(r.find(x));
                l.insert(x);
                s += x;
            }
            while (l.size() == k + 1) {
                int x = *l.rbegin();
                l.erase(l.find(x));
                s -= x;
                r.insert(x);
            }
            ans = min(ans, s);
        }
        return ans;
    }
};
```

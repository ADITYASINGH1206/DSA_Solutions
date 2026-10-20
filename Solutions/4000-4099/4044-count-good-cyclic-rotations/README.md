# [4044. Count Good Cyclic Rotations](https://leetcode.com/problems/count-good-cyclic-rotations/)
**Difficulty:** `Medium` | **Tags:** `array`, `sliding-window`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` of even length `n`.

A **cyclic rotation** of `nums` is obtained by choosing a prefix of `nums` whose length is between 0 and `n - 1` (inclusive), and moving it to the end of the array while preserving the order of all elements.

A cyclic rotation is **good** if the sum of its first `n / 2` elements is **strictly greater** than the sum of its last `n / 2` elements.

Return the number of cyclic rotations of `nums` that are good.

**Example 1:**

**Input:** nums = [1,2,3,4,5,6]

**Output:** 3

**Explanation:**

The cyclic rotations of `nums` are:

| Cyclic rotation | Sum of first `n / 2` elements | Sum of last `n / 2` elements |
| --- | --- | --- |
| `[1, 2, 3, 4, 5, 6]` | `1 + 2 + 3 = 6` | `4 + 5 + 6 = 15` |
| `[2, 3, 4, 5, 6, 1]` | `2 + 3 + 4 = 9` | `5 + 6 + 1 = 12` |
| `[3, 4, 5, 6, 1, 2]` | `3 + 4 + 5 = 12` | `6 + 1 + 2 = 9` |
| `[4, 5, 6, 1, 2, 3]` | `4 + 5 + 6 = 15` | `1 + 2 + 3 = 6` |
| `[5, 6, 1, 2, 3, 4]` | `5 + 6 + 1 = 12` | `2 + 3 + 4 = 9` |
| `[6, 1, 2, 3, 4, 5]` | `6 + 1 + 2 = 9` | `3 + 4 + 5 = 12` |

The first half has a greater sum than the second half for 3 rotations. Thus, the answer is 3.

**Example 2:**

**Input:** nums = [1,2,1,2]

**Output:** 0

**Explanation:**

The cyclic rotations of `nums` are:

| Cyclic rotation | Sum of first `n / 2` elements | Sum of last `n / 2` elements |
| --- | --- | --- |
| `[1, 2, 1, 2]` | `1 + 2 = 3` | `1 + 2 = 3` |
| `[2, 1, 2, 1]` | `2 + 1 = 3` | `2 + 1 = 3` |
| `[1, 2, 1, 2]` | `1 + 2 = 3` | `1 + 2 = 3` |
| `[2, 1, 2, 1]` | `2 + 1 = 3` | `2 + 1 = 3` |

No cyclic rotation is good because the two sums are equal for every rotation. Thus, the answer is 0.

**Constraints:**

* `2 <= n == nums.length <= 105`
* `1 <= nums[i] <= 109`
* `n` is even.

---

## Solution & Editorial
# Intuition
To determine if a cyclic rotation is "good," we need to compare the sum of the first $n/2$ elements with the sum of the remaining $n/2$ elements. Since the total sum of the array is constant, we can represent the sum of the second half as `total_sum - first_half_sum`. A rotation is good if `first_half_sum > total_sum - first_half_sum`, which simplifies to `2 * first_half_sum > total_sum`.

# Approach
1. Calculate the `total` sum of the array once.
2. Initialize `sum` as the sum of the first $n/2$ elements (the initial window).
3. Use a sliding window to simulate cyclic rotations. As we shift the window by one position, we add the next element (`nums[r % n]`) and remove the element that just left the window (`nums[l]`).
4. For each rotation, check the condition `sum > total - sum` and increment the counter if true.

### Visual Trace (Example 1: [1, 2, 3, 4, 5, 6], n=6, n/2=3)
| Rotation | Window | Sum | Total - Sum | Good? |
| :--- | :--- | :--- | :--- | :--- |
| 0 | [1, 2, 3] | 6 | 15 | No |
| 1 | [2, 3, 4] | 9 | 12 | No |
| 2 | [3, 4, 5] | 12 | 9 | Yes |
| 3 | [4, 5, 6] | 15 | 6 | Yes |
| 4 | [5, 6, 1] | 12 | 9 | Yes |
| 5 | [6, 1, 2] | 9 | 12 | No |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the array. We perform a single pass to calculate the total sum and another pass to slide the window across all $N$ rotations.
- Space complexity: $$O(1)$$, as we only store a few integer variables regardless of the input size.

# Code
```cpp
using ll = long long;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        ll total = accumulate(nums.begin(),nums.end(),0LL);
        ll sum = 0;
        for(int i= 0;i<n/2;i++){
            sum+=nums[i];
        }
        int l =0;
        int r = n/2;
        for(int i=0;i<n;i++){
            sum+=nums[r%n];
            sum-=nums[l++];
            r++;
            if(sum>total-sum){
                ans++;
            }
        }
        return ans;
    }
};
```

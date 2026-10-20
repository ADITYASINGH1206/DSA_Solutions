# [1855. Maximum Distance Between a Pair of Values](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `binary-search`

---

## Problem Description
You are given two **non-increasing 0-indexed** integer arrays `nums1`​​​​​​ and `nums2`​​​​​​.

A pair of indices `(i, j)`, where `0 <= i < nums1.length` and `0 <= j < nums2.length`, is **valid** if both `i <= j` and `nums1[i] <= nums2[j]`. The **distance** of the pair is `j - i`​​​​.

Return *the **maximum distance** of any **valid** pair* `(i, j)`*. If there are no valid pairs, return* `0`.

An array `arr` is **non-increasing** if `arr[i-1] >= arr[i]` for every `1 <= i < arr.length`.

**Example 1:**

```
Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
```

**Example 2:**

```
Input: nums1 = [2,2,2], nums2 = [10,10,1]
Output: 1
Explanation: The valid pairs are (0,0), (0,1), and (1,1).
The maximum distance is 1 with pair (0,1).
```

**Example 3:**

```
Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
Output: 2
Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
The maximum distance is 2 with pair (2,4).
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 105`
* `1 <= nums1[i], nums2[j] <= 105`
* Both `nums1` and `nums2` are **non-increasing**.

---

## Solution & Editorial
# Intuition
Since both arrays are non-increasing, for a fixed index `i` in `nums1`, we want to find the largest index `j` in `nums2` such that `nums2[j] >= nums1[i]`. Because `nums2` is non-increasing, the condition `nums2[j] >= nums1[i]` holds for all indices from `0` up to some threshold index. By reversing `nums2`, the array becomes non-decreasing, allowing us to use binary search to efficiently find the rightmost valid `j`.

# Approach
1. Reverse `nums2` so that it becomes non-decreasing. This transforms the problem of finding the largest `j` such that `nums2[j] >= nums1[i]` into finding the first element in the reversed array that is greater than or equal to `nums1[i]`.
2. Iterate through each index `i` of `nums1`.
3. For each `nums1[i]`, use `std::lower_bound` on the reversed `nums2` to find the first index `k` where `reversed_nums2[k] >= nums1[i]`.
4. The original index `j` in `nums2` corresponds to `nums2.size() - 1 - k`.
5. Calculate the distance `j - i` and update the maximum `ans` if `j >= i`.

### Visual Trace (Example 1)
`nums1 = [55, 30, 5, 4, 2]`, `nums2 = [100, 20, 10, 10, 5]`
Reversed `nums2` (let's call it `R`): `[5, 10, 10, 20, 100]`

| i | nums1[i] | lower_bound in R | k (idx in R) | j (orig idx) | j - i | ans |
|---|----------|------------------|--------------|--------------|-------|-----|
| 0 | 55       | 100              | 4            | 0            | 0     | 0   |
| 1 | 30       | 100              | 4            | 0            | -1    | 0   |
| 2 | 5        | 5                | 0            | 4            | 2     | 2   |
| 3 | 4        | 5                | 0            | 4            | 1     | 2   |
| 4 | 2        | 5                | 0            | 4            | 0     | 2   |

# Complexity
- Time complexity: $$O(N \log M)$$, where $$N$$ is the length of `nums1` and $$M$$ is the length of `nums2$$. We iterate through `nums1` once and perform a binary search on `nums2` for each element.
- Space complexity: $$O(1)$$ (ignoring the space used by the `reverse` operation, which modifies the input in-place).

# Code
```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        reverse(nums2.begin(), nums2.end());
        for (int i = 0; i < nums1.size(); ++i) {
            int j = nums2.size() - (lower_bound(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin()) - 1;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

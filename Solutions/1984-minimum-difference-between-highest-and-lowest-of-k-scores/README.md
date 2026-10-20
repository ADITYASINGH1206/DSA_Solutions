# [1984. Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/)
**Difficulty:** `Easy` | **Tags:** `array`, `sliding-window`, `sorting`

---

## Problem Description
You are given a **0-indexed** integer array `nums`, where `nums[i]` represents the score of the `ith` student. You are also given an integer `k`.

Pick the scores of any `k` students from the array so that the **difference** between the **highest** and the **lowest** of the `k` scores is **minimized**.

Return *the **minimum** possible difference*.

**Example 1:**

```
Input: nums = [90], k = 1
Output: 0
Explanation: There is one way to pick score(s) of one student:
- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.
```

**Example 2:**

```
Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: There are six ways to pick score(s) of two students:
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
The minimum possible difference is 2.
```

**Constraints:**

* `1 <= k <= nums.length <= 1000`
* `0 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To minimize the difference between the highest and lowest scores in a subset of size $k$, we must ensure the elements in our subset are as close to each other as possible. Sorting the array allows us to group elements by proximity, turning the problem into finding the smallest range of length $k$ in a sorted sequence.

# Approach
1. Sort the input array `nums` in non-decreasing order. This ensures that for any subarray of length $k$, the difference between the maximum and minimum is simply `nums[i + k - 1] - nums[i]`.
2. Initialize a sliding window of size $k$. Let `l` be the start index and `r` be the end index (`r = k - 1`).
3. Iterate through the sorted array, sliding the window one position at a time. In each step, calculate the difference `nums[r] - nums[l]` and update the global minimum `ans`.
4. Continue until the window reaches the end of the array.

### Visual Trace (Example 2: nums = [9, 4, 1, 7], k = 2)
- Sorted: `[1, 4, 7, 9]`
- Window 1 (l=0, r=1): `[1, 4]`, diff = 4 - 1 = 3. `ans` = 3.
- Window 2 (l=1, r=2): `[4, 7]`, diff = 7 - 4 = 3. `ans` = 3.
- Window 3 (l=2, r=3): `[7, 9]`, diff = 9 - 7 = 2. `ans` = 2.
- Result: 2.

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step. The sliding window traversal takes $$O(N)$$, which is dominated by the sort.
- Space complexity: $$O(1)$$ or $$O(\log N)$$ depending on the sorting implementation's stack usage, as we perform the operation in-place.

# Code
```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = k-1;
        while(r<n){
            ans = min(ans,nums[r]-nums[l]);
            r++,l++;
        }
        return ans;
    }
};
```

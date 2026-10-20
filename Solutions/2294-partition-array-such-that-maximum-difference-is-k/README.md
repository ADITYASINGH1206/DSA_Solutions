# [2294. Partition Array Such That Maximum Difference Is K](https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given an integer array `nums` and an integer `k`. You may partition `nums` into one or more **subsequences** such that each element in `nums` appears in **exactly** one of the subsequences.

Return *the **minimum** number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is **at most*** `k`*.*

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```
Input: nums = [3,6,1,2,5], k = 2
Output: 2
Explanation:
We can partition nums into the two subsequences [3,1,2] and [6,5].
The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.
```

**Example 2:**

```
Input: nums = [1,2,3], k = 1
Output: 2
Explanation:
We can partition nums into the two subsequences [1,2] and [3].
The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].
```

**Example 3:**

```
Input: nums = [2,2,4,5], k = 0
Output: 3
Explanation:
We can partition nums into the three subsequences [2,2], [4], and [5].
The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `0 <= nums[i] <= 105`
* `0 <= k <= 105`

---

## Solution & Editorial
# Intuition
To minimize the number of subsequences, we want to pack as many elements as possible into each subsequence. By sorting the array, we can greedily group elements that are close to each other. Once the difference between the current element and the minimum element of the current subsequence exceeds `k`, we are forced to start a new subsequence.

# Approach
1. Sort the input array `nums` in non-decreasing order. This allows us to process elements linearly and maintain the minimum value of the current subsequence easily.
2. Initialize `ans = 1` (since at least one subsequence is needed) and `min_val = nums[0]`.
3. Iterate through the sorted array starting from the second element (`i = 1`):
   - If `nums[i] - min_val > k`, the current element cannot fit into the existing subsequence. Increment `ans` and update `min_val` to `nums[i]` to start a new subsequence.
   - Otherwise, continue to the next element.

### Visual Trace (Example 1: nums = [3,6,1,2,5], k = 2)
- Sorted: `[1, 2, 3, 5, 6]`
- Start: `ans = 1`, `min_val = 1`
- `i=1` (val 2): `2 - 1 <= 2` (True), keep `min_val = 1`
- `i=2` (val 3): `3 - 1 <= 2` (True), keep `min_val = 1`
- `i=3` (val 5): `5 - 1 > 2` (True), `ans = 2`, `min_val = 5`
- `i=4` (val 6): `6 - 5 <= 2` (True), keep `min_val = 5`
- Result: `2`

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step, where $$N$$ is the length of the array. The subsequent linear scan takes $$O(N)$$.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we only use a few integer variables for tracking.

# Code
```cpp
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 1; 
        int min_val = nums[0]; 
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - min_val > k) {
                ans++;
                min_val = nums[i]; 
            }
        }
        
        return ans;
    }
};
```

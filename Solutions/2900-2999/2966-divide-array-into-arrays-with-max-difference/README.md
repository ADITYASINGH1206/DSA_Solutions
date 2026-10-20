# [2966. Divide Array Into Arrays With Max Difference](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given an integer array `nums` of size `n` where `n` is a multiple of 3 and a positive integer `k`.

Divide the array `nums` into `n / 3` arrays of size **3** satisfying the following condition:

* The difference between **any** two elements in one array is **less than or equal** to `k`.

Return a **2D** array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return **any** of them.

**Example 1:**

**Input:** nums = [1,3,4,8,7,9,3,5,1], k = 2

**Output:** [[1,1,3],[3,4,5],[7,8,9]]

**Explanation:**

The difference between any two elements in each array is less than or equal to 2.

**Example 2:**

**Input:** nums = [2,4,2,2,5,2], k = 2

**Output:** []

**Explanation:**

Different ways to divide `nums` into 2 arrays of size 3 are:

* [[2,2,2],[2,4,5]] (and its permutations)
* [[2,2,4],[2,2,5]] (and its permutations)

Because there are four 2s there will be an array with the elements 2 and 5 no matter how we divide it. since `5 - 2 = 3 > k`, the condition is not satisfied and so there is no valid division.

**Example 3:**

**Input:** nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14

**Output:** [[2,2,2],[4,5,5],[5,5,7],[7,8,8],[9,9,10],[11,12,12]]

**Explanation:**

The difference between any two elements in each array is less than or equal to 14.

**Constraints:**

* `n == nums.length`
* `1 <= n <= 105`
* `n` is a multiple of 3
* `1 <= nums[i] <= 105`
* `1 <= k <= 105`

---

## Solution & Editorial
# Intuition
To minimize the difference between elements within each group of three, we must group elements that are numerically close to each other. Sorting the array allows us to consider contiguous segments of size 3, which inherently minimizes the spread within each group.

# Approach
1. **Sort**: Sort the input array `nums` in non-decreasing order. This ensures that for any triplet `(nums[i], nums[i+1], nums[i+2])`, the difference between the maximum and minimum element is simply `nums[i+2] - nums[i]`.
2. **Iterate**: Traverse the sorted array in steps of 3. For each triplet starting at index `i`, check if `nums[i+2] - nums[i] <= k`.
3. **Validate**: If the condition holds for all triplets, add them to the result vector. If any triplet violates the condition, return an empty vector immediately as no valid partition exists.

### Visual Trace (Example 1: nums = [1,3,4,8,7,9,3,5,1], k = 2)
- **Sorted**: `[1, 1, 3, 3, 4, 5, 7, 8, 9]`
- **Iteration 1 (i=0)**: `[1, 1, 3]`. `3 - 1 = 2 <= 2`. Valid.
- **Iteration 2 (i=3)**: `[3, 4, 5]`. `5 - 3 = 2 <= 2`. Valid.
- **Iteration 3 (i=6)**: `[7, 8, 9]`. `9 - 7 = 2 <= 2`. Valid.
- **Result**: `[[1, 1, 3], [3, 4, 5], [7, 8, 9]]`

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step. The subsequent linear scan takes $$O(N)$$, which is dominated by the sort.
- Space complexity: $$O(N)$$ to store the result vector, or $$O(1)$$ auxiliary space if we ignore the output storage (depending on the sorting implementation's stack usage).

# Code
```cpp
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i+=3){
            if(nums[i+2]-nums[i]>k) return {};
            else{
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }
        }

        return ans;
    }
};
```

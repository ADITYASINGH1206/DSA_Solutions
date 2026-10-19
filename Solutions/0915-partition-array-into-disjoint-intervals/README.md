# [915. Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)
**Difficulty:** `Medium` | **Tags:** `array`

---

## Problem Description
Given an integer array `nums`, partition it into two (contiguous) subarrays `left` and `right` so that:

* Every element in `left` is less than or equal to every element in `right`.
* `left` and `right` are non-empty.
* `left` has the smallest possible size.

Return *the length of* `left` *after such a partitioning*.

Test cases are generated such that partitioning exists.

**Example 1:**

```
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
```

**Example 2:**

```
Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
```

**Constraints:**

* `2 <= nums.length <= 105`
* `0 <= nums[i] <= 106`
* There is at least one valid answer for the given input.

---

## Solution & Editorial
# Intuition
To partition the array such that every element in the `left` subarray is less than or equal to every element in the `right` subarray, we need the maximum element of the `left` part to be less than or equal to the minimum element of the `right` part. Precomputing prefix maximums and suffix minimums allows us to evaluate this condition efficiently for every potential split point.

# Approach
1. Initialize two vectors, `maxi` of size `n` to store prefix maximums and `mini` of size `n` to store suffix minimums.
2. Build the `maxi` array iteratively from left to right, where `maxi[i]` tracks the maximum value in `nums[0...i]`.
3. Build the `mini` array iteratively from right to left, where `mini[i]` tracks the minimum value in `nums[i...n-1]`.
4. Iterate through all possible split indices `i` from `0` to `n-2`. The first index `i` where `maxi[i] <= mini[i+1]` satisfies the requirement, and we return its length `i + 1`.

### Visual Walkthrough for Example 1
`nums = [5, 0, 3, 8, 6]`

- `maxi` (Prefix Max): `[5, 5, 5, 8, 8]`
- `mini` (Suffix Min): `[0, 0, 3, 6, 6]`

| Index `i` | `nums[i]` | `maxi[i]` | `mini[i+1]` | Condition `maxi[i] <= mini[i+1]` | Result |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 5 | 5 | 0 | `5 <= 0` (False) | - |
| 1 | 0 | 5 | 3 | `5 <= 3` (False) | - |
| 2 | 3 | 5 | 6 | `5 <= 6` (True) | Returns `2 + 1 = 3` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. We perform three linear passes: one to compute `maxi`, one to compute `mini`, and one to find the partition point.
- Space complexity: $$O(N)$$ to store the auxiliary `maxi` and `mini` arrays of size $$N$$.

# Code
```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n,0);
        vector<int> mini(n,0);
        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            if(nums[i]>maxi[i-1]){
                maxi[i] = nums[i];
            }
            else{
                maxi[i] = maxi[i-1];
            }
        }
        for(int i = n-2;i>=0;i--){
            if(nums[i]<mini[i+1]){
                mini[i] = nums[i];
            }
            else{
                mini[i] = mini[i+1];
            }
        }
        for(int i = 0;i<n-1;i++){
            if(maxi[i] <= mini[i+1]) return i+1;
        }
        return -1;
    }
};
```

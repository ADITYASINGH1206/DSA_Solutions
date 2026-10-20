# [2574. Left and Right Sum Differences](https://leetcode.com/problems/left-and-right-sum-differences/)
**Difficulty:** `Easy` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** integer array `nums` of size `n`.

Define two arrays `leftSum` and `rightSum` where:

* `leftSum[i]` is the sum of elements to the left of the index `i` in the array `nums`. If there is no such element, `leftSum[i] = 0`.
* `rightSum[i]` is the sum of elements to the right of the index `i` in the array `nums`. If there is no such element, `rightSum[i] = 0`.

Return an integer array `answer` of size `n` where `answer[i] = |leftSum[i] - rightSum[i]|`.

**Example 1:**

```
Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
```

**Example 2:**

```
Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To calculate the absolute difference between the sum of elements to the left and right of each index, we can observe that the total sum of the array is constant. By maintaining a running `leftSum` and calculating the `rightSum` by subtracting the current element from the total sum, we can compute the result in a single pass after an initial summation.

# Approach
1. Calculate the total sum of the array `nums` and store it in `rightsum`.
2. Iterate through the array using an index `i`:
   - Subtract `nums[i]` from `rightsum` to get the sum of elements strictly to the right of `i`.
   - Calculate the absolute difference between `leftsum` and the updated `rightsum`.
   - Store this difference in the `ans` vector.
   - Add `nums[i]` to `leftsum` to prepare for the next iteration.

### Visual Trace (nums = [10, 4, 8, 3])
| i | nums[i] | leftsum | rightsum (before) | rightsum (after) | diff | ans |
|---|---|---|---|---|---|---|
| 0 | 10 | 0 | 25 | 15 | 15 | [15] |
| 1 | 4 | 10 | 15 | 11 | 1 | [15, 1] |
| 2 | 8 | 14 | 11 | 3 | 11 | [15, 1, 11] |
| 3 | 3 | 22 | 3 | 0 | 22 | [15, 1, 11, 22] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform one pass to calculate the total sum and one pass to compute the differences.
- Space complexity: $$O(N)$$ to store the result array, or $$O(1)$$ auxiliary space if we exclude the output vector.

# Code
```cpp
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int leftsum =0;
        int rightsum =0;
        for(int i=0;i<nums.size();i++){
            rightsum+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            rightsum-=nums[i];
            int dif = abs(leftsum-rightsum);
            ans.push_back(dif);
            leftsum+=nums[i];
        }
        return ans;
    }
};
```

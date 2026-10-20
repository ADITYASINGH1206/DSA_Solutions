# [1480. Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]…nums[i])`.

Return the running sum of `nums`.

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

**Example 2:**

```
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

**Example 3:**

```
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `-10^6 <= nums[i] <= 10^6`

---

## Solution & Editorial
# Intuition
The problem asks for the cumulative sum of elements in an array. Since each element at index `i` depends only on the sum of elements from `0` to `i-1` plus the current element `nums[i]`, we can compute this efficiently in a single pass by maintaining a running total.

# Approach
1. Initialize a result vector `res` of the same size as the input `nums`.
2. Maintain an integer variable `ans` initialized to 0 to keep track of the cumulative sum.
3. Iterate through the input array `nums` using an index `i`.
4. In each iteration, add the current element `nums[i]` to `ans` and store the updated `ans` in `res[i]`.

### Visual Trace (Example 1: nums = [1, 2, 3, 4])
| Iteration (i) | nums[i] | ans (prev + nums[i]) | res[i] |
| :--- | :--- | :--- | :--- |
| 0 | 1 | 0 + 1 = 1 | 1 |
| 1 | 2 | 1 + 2 = 3 | 3 |
| 2 | 3 | 3 + 3 = 6 | 6 |
| 3 | 4 | 6 + 4 = 10 | 10 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input array, as we perform a single linear scan.
- Space complexity: $$O(N)$$ to store the result vector. If modifying the input array in-place is permitted, this could be reduced to $$O(1)$$.

# Code
```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>res(nums.size());
        int ans =0;
        for(int i =0 ; i<nums.size() ; i++){
            ans+= nums[i];
            res[i]=ans;
            
        }
        return res;
    }
};
```

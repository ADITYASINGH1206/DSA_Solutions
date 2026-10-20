# [3264. Final Array State After K Multiplication Operations I](https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `heap-priority-queue`, `simulation`

---

## Problem Description
You are given an integer array `nums`, an integer `k`, and an integer `multiplier`.

You need to perform `k` operations on `nums`. In each operation:

* Find the **minimum** value `x` in `nums`. If there are multiple occurrences of the minimum value, select the one that appears **first**.
* Replace the selected minimum value `x` with `x * multiplier`.

Return an integer array denoting the *final state* of `nums` after performing all `k` operations.

**Example 1:**

**Input:** nums = [2,1,3,5,6], k = 5, multiplier = 2

**Output:** [8,4,6,5,6]

**Explanation:**

| Operation | Result |
| --- | --- |
| After operation 1 | [2, 2, 3, 5, 6] |
| After operation 2 | [4, 2, 3, 5, 6] |
| After operation 3 | [4, 4, 3, 5, 6] |
| After operation 4 | [4, 4, 6, 5, 6] |
| After operation 5 | [8, 4, 6, 5, 6] |

**Example 2:**

**Input:** nums = [1,2], k = 3, multiplier = 4

**Output:** [16,8]

**Explanation:**

| Operation | Result |
| --- | --- |
| After operation 1 | [4, 2] |
| After operation 2 | [4, 8] |
| After operation 3 | [16, 8] |

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* `1 <= k <= 10`
* `1 <= multiplier <= 5`

---

## Solution & Editorial
# Intuition
Since the constraints are small ($N \le 100, K \le 10$), a direct simulation of the process is optimal. In each of the $K$ steps, we identify the index of the minimum element and update it by multiplying it with the given `multiplier`.

# Approach
1. Define a helper function `minres` that iterates through the `nums` array to find the index of the first occurrence of the minimum value.
2. In the main function `getFinalState`, execute a loop that runs exactly $K$ times.
3. Inside the loop, call `minres` to locate the index of the current minimum element and update `nums[idx]` by multiplying it with `multiplier`.
4. Return the modified `nums` vector.

### Visual Trace (Example 1: nums = [2, 1, 3, 5, 6], k = 5, multiplier = 2)
| Iteration | Min Index | Operation | Result |
| :--- | :--- | :--- | :--- |
| 1 | 1 | nums[1] * 2 | [2, 2, 3, 5, 6] |
| 2 | 0 | nums[0] * 2 | [4, 2, 3, 5, 6] |
| 3 | 1 | nums[1] * 2 | [4, 4, 3, 5, 6] |
| 4 | 2 | nums[2] * 2 | [4, 4, 6, 5, 6] |
| 5 | 0 | nums[0] * 2 | [8, 4, 6, 5, 6] |

# Complexity
- Time complexity: $$O(K \cdot N)$$, where $K$ is the number of operations and $N$ is the length of the array. In each of the $K$ operations, we perform a linear scan of the array to find the minimum.
- Space complexity: $$O(1)$$, as we modify the input array in-place and use only a constant amount of extra space for variables.

# Code
```cpp
class Solution {
public:

    int minres(vector<int>& nums){
        int idx = 0;
        int mn = INT_MAX;
        for(int i =0;i<nums.size();i++){
            if(nums[i] < mn){
                mn = nums[i];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        for(int i=0;i<k;i++){
            nums[minres(nums)] = multiplier* nums[minres(nums)];
        }
        return nums;
    }
};
```

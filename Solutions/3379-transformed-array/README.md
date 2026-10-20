# [3379. Transformed Array](https://leetcode.com/problems/transformed-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `simulation`

---

## Problem Description
You are given an integer array `nums` that represents a circular array. Your task is to create a new array `result` of the **same** size, following these rules:

For each index `i` (where `0 <= i < nums.length`), perform the following **independent** actions:

* If `nums[i] > 0`: Start at index `i` and move `nums[i]` steps to the **right** in the circular array. Set `result[i]` to the value at the index where you land.
* If `nums[i] < 0`: Start at index `i` and move `abs(nums[i])` steps to the **left** in the circular array. Set `result[i]` to the value at the index where you land.
* If `nums[i] == 0`: Set `result[i]` to `nums[i]`.

Return the new array `result`.

**Note:** Since `nums` is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.

**Example 1:**

**Input:** nums = [3,-2,1,1]

**Output:** [1,1,1,3]

**Explanation:**

* For `nums[0]` that is equal to 3, If we move 3 steps to right, we reach `nums[3]`. So `result[0]` should be 1.
* For `nums[1]` that is equal to -2, If we move 2 steps to left, we reach `nums[3]`. So `result[1]` should be 1.
* For `nums[2]` that is equal to 1, If we move 1 step to right, we reach `nums[3]`. So `result[2]` should be 1.
* For `nums[3]` that is equal to 1, If we move 1 step to right, we reach `nums[0]`. So `result[3]` should be 3.

**Example 2:**

**Input:** nums = [-1,4,-1]

**Output:** [-1,-1,4]

**Explanation:**

* For `nums[0]` that is equal to -1, If we move 1 step to left, we reach `nums[2]`. So `result[0]` should be -1.
* For `nums[1]` that is equal to 4, If we move 4 steps to right, we reach `nums[2]`. So `result[1]` should be -1.
* For `nums[2]` that is equal to -1, If we move 1 step to left, we reach `nums[1]`. So `result[2]` should be 4.

**Constraints:**

* `1 <= nums.length <= 100`
* `-100 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem requires simulating movement in a circular array. Since the array is circular, moving $k$ steps from index $i$ is equivalent to finding the index $(i + k) \pmod n$. The key challenge is handling negative indices correctly in C++, where the modulo operator can return negative values.

# Approach
1. Initialize a result vector `ans` of the same size as `nums`.
2. Iterate through each index `i` from $0$ to $n-1$.
3. If `nums[i] > 0`, the target index is `(i + nums[i]) % n`.
4. If `nums[i] == 0`, the target index is `i` itself.
5. If `nums[i] < 0`, the target index is `((i + nums[i]) % n + n) % n`. Adding `n` before the final modulo ensures the result is always in the range $[0, n-1]$, effectively handling the wrap-around for negative steps.
6. Assign `ans[i] = nums[target_index]`.

### Visual Trace (Example 1: nums = [3, -2, 1, 1], n = 4)
| i | nums[i] | Calculation | Target Index | Result |
|---|---|---|---|---|
| 0 | 3 | (0+3)%4 | 3 | nums[3]=1 |
| 1 | -2 | (1-2)%4 = -1 -> (-1+4)%4 | 3 | nums[3]=1 |
| 2 | 1 | (2+1)%4 | 3 | nums[3]=1 |
| 3 | 1 | (3+1)%4 | 0 | nums[0]=3 |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the array, as we iterate through the array exactly once.
- Space complexity: $$O(N)$$ to store the resulting array.

# Code
```cpp
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);\
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int idx = (i + nums[i]) % n;
                ans[i] = nums[idx];
            }
            else if(nums[i] ==0){
                ans[i] = nums[i];
            }
            else{
                int idx = ((i - abs(nums[i])) % n + n) % n;
                ans[i] = nums[idx];
            }
        }
        return ans;
    }
};
```

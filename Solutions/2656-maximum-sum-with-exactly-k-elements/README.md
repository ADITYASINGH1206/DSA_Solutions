# [2656. Maximum Sum With Exactly K Elements ](https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`

---

## Problem Description
You are given a **0-indexed** integer array `nums` and an integer `k`. Your task is to perform the following operation **exactly** `k` times in order to maximize your score:

1. Select an element `m` from `nums`.
2. Remove the selected element `m` from the array.
3. Add a new element with a value of `m + 1` to the array.
4. Increase your score by `m`.

Return *the maximum score you can achieve after performing the operation exactly* `k` *times.*

**Example 1:**

```
Input: nums = [1,2,3,4,5], k = 3
Output: 18
Explanation: We need to choose exactly 3 elements from nums to maximize the sum.
For the first iteration, we choose 5. Then sum is 5 and nums = [1,2,3,4,6]
For the second iteration, we choose 6. Then sum is 5 + 6 and nums = [1,2,3,4,7]
For the third iteration, we choose 7. Then sum is 5 + 6 + 7 = 18 and nums = [1,2,3,4,8]
So, we will return 18.
It can be proven, that 18 is the maximum answer that we can achieve.
```

**Example 2:**

```
Input: nums = [5,5,5], k = 2
Output: 11
Explanation: We need to choose exactly 2 elements from nums to maximize the sum.
For the first iteration, we choose 5. Then sum is 5 and nums = [5,5,6]
For the second iteration, we choose 6. Then sum is 5 + 6 = 11 and nums = [5,5,7]
So, we will return 11.
It can be proven, that 11 is the maximum answer that we can achieve.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* `1 <= k <= 100`

---

## Solution & Editorial
# Intuition
To maximize the total score, we must always pick the largest available element in the array. Since picking an element $m$ replaces it with $m+1$, the optimal strategy is to repeatedly select the current maximum, add it to our score, and increment it for the next iteration.

# Approach
1. Find the maximum element in the array. Sorting the array `nums` in ascending order allows us to easily access the largest element at `nums[n-1]`.
2. Initialize `ans` to 0 to store the cumulative score.
3. Perform the operation exactly `k` times using a loop:
   - Add the current maximum (`nums[n-1]`) to `ans`.
   - Increment the value at `nums[n-1]` by 1 to reflect the rule that the new element is $m+1$.
4. Return the final `ans`.

### Visual Trace (Example 1: nums = [1,2,3,4,5], k = 3)
| Iteration | Current Max | Score (ans) | Updated Array | 
| :--- | :--- | :--- | :--- |
| 1 | 5 | 5 | [1,2,3,4,6] |
| 2 | 6 | 11 | [1,2,3,4,7] |
| 3 | 7 | 18 | [1,2,3,4,8] |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting of the array. The subsequent loop runs in $$O(k)$$, making the total complexity $$O(N \log N + k)$$. Given the constraints ($N, k \le 100$), this is highly efficient.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation), as we only use a few integer variables.

# Code
```cpp
class Solution {
public:

    int maximizeSum(vector<int>& nums, int k) {
        int count = 0;
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        while(count != k){
            ans += nums[n-1];
            nums[n-1] += 1;
            count++;
        }
        return ans;
    }
};
```

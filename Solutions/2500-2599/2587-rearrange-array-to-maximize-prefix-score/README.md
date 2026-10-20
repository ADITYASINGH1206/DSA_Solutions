# [2587. Rearrange Array to Maximize Prefix Score](https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** integer array `nums`. You can rearrange the elements of `nums` to **any order** (including the given order).

Let `prefix` be the array containing the prefix sums of `nums` after rearranging it. In other words, `prefix[i]` is the sum of the elements from `0` to `i` in `nums` after rearranging it. The **score** of `nums` is the number of positive integers in the array `prefix`.

Return *the maximum score you can achieve*.

**Example 1:**

```
Input: nums = [2,-1,0,1,-3,3,-3]
Output: 6
Explanation: We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
prefix = [2,5,6,5,2,2,-1], so the score is 6.
It can be shown that 6 is the maximum score we can obtain.
```

**Example 2:**

```
Input: nums = [-2,-3,0]
Output: 0
Explanation: Any rearrangement of the array will result in a score of 0.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `-106 <= nums[i] <= 106`

---

## Solution & Editorial
# Intuition
To maximize the number of positive prefix sums, we should greedily pick the largest available numbers first. By placing the largest positive values at the beginning of the array, we build up the prefix sum as quickly as possible, delaying the impact of negative numbers that would decrease the sum.

# Approach
1. Sort the input array `nums` in descending order. This ensures that we encounter the largest values first, maximizing the growth of the prefix sum.
2. Initialize a `long long` variable `sum` to track the running prefix sum and an integer `ans` to count how many prefixes are strictly positive.
3. Iterate through the sorted array. For each element, add it to `sum`.
4. If the current `sum` is greater than 0, increment `ans`. If `sum` becomes less than or equal to 0, stop the process immediately, as any subsequent elements (which are smaller or negative) will not be able to recover a positive prefix sum.

### Visual Trace (Example 1: nums = [2,-1,0,1,-3,3,-3])
Sorted: [3, 2, 1, 0, -1, -3, -3]

| Step | Element | Sum | Sum > 0? | Ans |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 3 | 3 | Yes | 1 |
| 2 | 2 | 5 | Yes | 2 |
| 3 | 1 | 6 | Yes | 3 |
| 4 | 0 | 6 | Yes | 4 |
| 5 | -1 | 5 | Yes | 5 |
| 6 | -3 | 2 | Yes | 6 |
| 7 | -3 | -1 | No | Break |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step, where $$N$$ is the length of the array. The subsequent linear scan takes $$O(N)$$.
- Space complexity: $$O(1)$$ (ignoring the space required for the sorting implementation, which is typically $$O(\log N)$$ stack space).

# Code
```cpp
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        
        long long sum = 0;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (sum > 0) {
                ans++;
            } else {
                break;
            }
        }
        
        return ans;
    }
};
```

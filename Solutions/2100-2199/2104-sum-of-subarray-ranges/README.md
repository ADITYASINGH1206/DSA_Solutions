# [2104. Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `monotonic-stack`

---

## Problem Description
You are given an integer array `nums`. The **range** of a subarray of `nums` is the difference between the largest and smallest element in the subarray.

Return *the **sum of all** subarray ranges of* `nums`*.*

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
```

**Example 2:**

```
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
```

**Example 3:**

```
Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `-109 <= nums[i] <= 109`

**Follow-up:** Could you find a solution with `O(n)` time complexity?

---

## Solution & Editorial
# Intuition
The range of a subarray is defined as `max(subarray) - min(subarray)`. By the linearity of expectation (or simply summation properties), the sum of all subarray ranges is equivalent to the sum of all subarray maximums minus the sum of all subarray minimums. We can calculate these efficiently using a monotonic stack to find the boundaries where each element `nums[i]` acts as the minimum or maximum.

# Approach
1. For each element `nums[i]`, we determine how many subarrays it is the minimum of and how many it is the maximum of.
2. Let `left_min[i]` be the distance to the nearest smaller element to the left, and `right_min[i]` be the distance to the nearest smaller element to the right. The number of subarrays where `nums[i]` is the minimum is `left_min[i] * right_min[i]`.
3. We repeat this logic for maximums using `left_max` and `right_max` with a monotonic decreasing stack.
4. To handle duplicates correctly and avoid double-counting, we use strict inequalities for one side (e.g., `>=` for min, `>` for min) to ensure each subarray has a unique minimum/maximum index.

### Visual Trace (nums = [1, 2, 3])
| Index | Value | left_min | right_min | left_max | right_max | Min Contribution | Max Contribution |
|---|---|---|---|---|---|---|---|
| 0 | 1 | 1 | 3 | 1 | 3 | 1*1*3 = 3 | 1*1*3 = 3 |
| 1 | 2 | 2 | 2 | 1 | 2 | 2*2*2 = 8 | 2*1*2 = 4 |
| 2 | 3 | 3 | 1 | 1 | 1 | 3*3*1 = 9 | 3*1*1 = 3 |

*Note: The actual logic calculates the contribution of each element to the total sum by multiplying its value by the number of subarrays it dominates.* 

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the array. Each element is pushed and popped from the stack at most once for each of the four passes.
- Space complexity: $$O(N)$$ to store the boundary arrays and the stacks.

# Code
```cpp
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        vector<int> left_min(n);
        vector<int> right_min(n);
        vector<int> left_max(n);
        vector<int> right_max(n);

        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        stack<int> s4;

        
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && nums[s1.top()] >= nums[i]) {
                s1.pop();
            }
            left_min[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && nums[s2.top()] > nums[i]) {
                s2.pop();
            }
            right_min[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }


        for (int i = 0; i < n; i++) {
            while (!s3.empty() && nums[s3.top()] <= nums[i]) {
                s3.pop();
            }
            left_max[i] = s3.empty() ? i + 1 : i - s3.top();
            s3.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s4.empty() && nums[s4.top()] < nums[i]) {
                s4.pop();
            }
            right_max[i] = s4.empty() ? n - i : s4.top() - i;
            s4.push(i);
        }

        for(int i = 0;i<n;i++){
            long long min_sum = (long long)nums[i]*left_min[i]*right_min[i];
            long long max_sum = (long long)nums[i]*left_max[i]*right_max[i];

            ans += max_sum-min_sum;
        }
        return ans;
    }
};
```

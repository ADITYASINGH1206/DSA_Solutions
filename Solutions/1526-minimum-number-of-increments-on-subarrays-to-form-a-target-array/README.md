# [1526. Minimum Number of Increments on Subarrays to Form a Target Array](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/)
**Difficulty:** `Hard` | **Tags:** `array`, `dynamic-programming`, `stack`, `greedy`, `monotonic-stack`

---

## Problem Description
You are given an integer array `target`. You have an integer array `initial` of the same size as `target` with all elements initially zeros.

In one operation you can choose **any** subarray from `initial` and increment each value by one.

Return *the minimum number of operations to form a* `target` *array from* `initial`.

The test cases are generated so that the answer fits in a 32-bit integer.

**Example 1:**

```
Input: target = [1,2,3,2,1]
Output: 3
Explanation: We need at least 3 operations to form the target array from the initial array.
[0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
[1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
[1,2,2,2,1] increment 1 at index 2.
[1,2,3,2,1] target array is formed.
```

**Example 2:**

```
Input: target = [3,1,1,2]
Output: 4
Explanation: [0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2]
```

**Example 3:**

```
Input: target = [3,1,5,4,2]
Output: 7
Explanation: [0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1] -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] -> [3,1,5,4,2].
```

**Constraints:**

* `1 <= target.length <= 105`
* `1 <= target[i] <= 105`
* ​​​​​​​The input is generated such that the answer fits inside a 32 bit integer.

---

## Solution & Editorial
# Intuition
To form the `target` array from an array of zeros using subarray increments, we observe that an operation covering a range `[i, j]` contributes to the values of all elements in that range. When moving from `target[i-1]` to `target[i]`, if `target[i] > target[i-1]`, we are forced to start at least `target[i] - target[i-1]` new operations to cover the increase. If `target[i] <= target[i-1]`, the existing operations covering `target[i-1]` are sufficient to cover `target[i]`.

# Approach
1. Initialize `ans` with the value of the first element `target[0]`, as we need at least that many operations to reach the first target value.
2. Iterate through the array starting from the second element (index 1).
3. For each element `target[i]`, compare it with the previous element `target[i-1]`.
4. If `target[i] > target[i-1]`, add the difference `target[i] - target[i-1]` to `ans`. This represents the new operations required to "build up" to the higher value.
5. If `target[i] <= target[i-1]`, no new operations are needed because the current operations covering `target[i-1]` can simply be extended or truncated to cover `target[i]`.

### Visual Trace (Example 1: [1, 2, 3, 2, 1])
| Index (i) | target[i] | target[i-1] | Diff (target[i] - target[i-1]) | ans (Cumulative) |
|-----------|-----------|-------------|--------------------------------|------------------|
| 0         | 1         | -           | -                              | 1                |
| 1         | 2         | 1           | 1                              | 2                |
| 2         | 3         | 2           | 1                              | 3                |
| 3         | 2         | 3           | -1 (ignored)                   | 3                |
| 4         | 1         | 2           | -1 (ignored)                   | 3                |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the `target` array. We perform a single pass through the array.
- Space complexity: $$O(1)$$, as we only use a single integer variable `ans` to track the total operations.

# Code
```cpp
class Solution {
public:
int minNumberOperations(vector<int>& target){
    int ans = target[0];
    for (int i = 1; i < target.size(); i++)
        ans += max(target[i] - target[i - 1], 0);
    return ans;
    }
};
```

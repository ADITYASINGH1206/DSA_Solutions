# [3737. Count Subarrays With Majority Element I](https://leetcode.com/problems/count-subarrays-with-majority-element-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `divide-and-conquer`, `segment-tree`, `merge-sort`, `counting`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` and an integer `target`.

Return the number of **subarrays** of `nums` in which `target` is the **majority element**.

The **majority element** of a subarray is the element that appears **strictly** **more than half** of the times in that subarray.

**Example 1:**

**Input:** nums = [1,2,2,3], target = 2

**Output:** 5

**Explanation:**

Valid subarrays with `target = 2` as the majority element:

* `nums[1..1] = [2]`
* `nums[2..2] = [2]`
* `nums[1..2] = [2,2]`
* `nums[0..2] = [1,2,2]`
* `nums[1..3] = [2,2,3]`

So there are 5 such subarrays.

**Example 2:**

**Input:** nums = [1,1,1,1], target = 1

**Output:** 10

**Explanation:**

**​​​​​​​**All 10 subarrays have 1 as the majority element.

**Example 3:**

**Input:** nums = [1,2,3], target = 4

**Output:** 0

**Explanation:**

`target = 4` does not appear in `nums` at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 10​​​​​​​9`
* `1 <= target <= 109`

---

## Solution & Editorial
# Intuition
To determine if a `target` is the majority element in a subarray, we must satisfy the condition that its frequency is strictly greater than half the length of the subarray. Given the constraint $N \le 1000$, an $O(N^2)$ approach is efficient enough to explore all possible subarrays.

# Approach
1. Iterate through every possible starting index `i` of a subarray from `0` to `n-1`.
2. For each starting index `i`, iterate through every possible ending index `j` from `i` to `n-1`.
3. Maintain a counter `cnt` that tracks the occurrences of `target` within the current window `[i, j]`.
4. Calculate the length of the current subarray as `len = j - i + 1`.
5. Check the majority condition: if `2 * cnt > len`, the `target` is the majority element, and we increment the answer `ans`.

### Visual Trace (nums = [1, 2, 2, 3], target = 2)
| i | j | Subarray | cnt | len | 2*cnt > len | ans |
|---|---|----------|-----|-----|-------------|-----|
| 0 | 0 | [1]      | 0   | 1   | 0 > 1 (F)   | 0   |
| 0 | 1 | [1, 2]   | 1   | 2   | 2 > 2 (F)   | 0   |
| 0 | 2 | [1, 2, 2]| 2   | 3   | 4 > 3 (T)   | 1   |
| 1 | 1 | [2]      | 1   | 1   | 2 > 1 (T)   | 2   |
| 1 | 2 | [2, 2]   | 2   | 2   | 4 > 2 (T)   | 3   |
| 1 | 3 | [2, 2, 3]| 2   | 3   | 4 > 3 (T)   | 4   |
| 2 | 2 | [2]      | 1   | 1   | 2 > 1 (T)   | 5   |

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the length of the array. We use nested loops to iterate over all $N(N+1)/2$ subarrays.
- Space complexity: $$O(1)$$ as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == target) cnt++;

                int len = j - i + 1;

                if (2 * cnt > len)
                    ans++;
            }
        }

        return (int)ans;
    }
};
```

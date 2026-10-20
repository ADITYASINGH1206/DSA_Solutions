# [3194. Minimum Average of Smallest and Largest Elements](https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`, `sorting`

---

## Problem Description
You have an array of floating point numbers `averages` which is initially empty. You are given an array `nums` of `n` integers where `n` is even.

You repeat the following procedure `n / 2` times:

* Remove the **smallest** element, `minElement`, and the **largest** element `maxElement`, from `nums`.
* Add `(minElement + maxElement) / 2` to `averages`.

Return the **minimum** element in `averages`.

**Example 1:**

**Input:** nums = [7,8,3,4,15,13,4,1]

**Output:** 5.5

**Explanation:**

| step | nums | averages |
| --- | --- | --- |
| 0 | [7,8,3,4,15,13,4,1] | [] |
| 1 | [7,8,3,4,13,4] | [8] |
| 2 | [7,8,4,4] | [8,8] |
| 3 | [7,4] | [8,8,6] |
| 4 | [] | [8,8,6,5.5] |

The smallest element of averages, 5.5, is returned.

**Example 2:**

**Input:** nums = [1,9,8,3,10,5]

**Output:** 5.5

**Explanation:**

| step | nums | averages |
| --- | --- | --- |
| 0 | [1,9,8,3,10,5] | [] |
| 1 | [9,8,3,5] | [5.5] |
| 2 | [8,5] | [5.5,6] |
| 3 | [] | [5.5,6,6.5] |

**Example 3:**

**Input:** nums = [1,2,3,7,8,9]

**Output:** 5.0

**Explanation:**

| step | nums | averages |
| --- | --- | --- |
| 0 | [1,2,3,7,8,9] | [] |
| 1 | [2,3,7,8] | [5] |
| 2 | [3,7] | [5,5] |
| 3 | [] | [5,5,5] |

**Constraints:**

* `2 <= n == nums.length <= 50`
* `n` is even.
* `1 <= nums[i] <= 50`

---

## Solution & Editorial
# Intuition
To minimize the average of pairs formed by the smallest and largest elements, we must first identify these elements efficiently. Sorting the array allows us to pair the smallest available element with the largest available element using two pointers, ensuring we process each pair in order.

# Approach
1. Sort the input array `nums` in non-decreasing order. This places the smallest elements at the beginning and the largest at the end.
2. Initialize a variable `ans` to a large value (e.g., `INT_MAX`) to track the minimum average found.
3. Use a loop to iterate `n / 2` times. In each iteration `i`:
   - The smallest element is at index `i` (`nums[i]`).
   - The largest element is at index `n - i - 1` (`nums[n - i - 1]`).
   - Calculate the average: `(nums[i] + nums[n - i - 1]) / 2.0`.
   - Update `ans` if the current average is smaller than the existing `ans`.
4. Return `ans` after the loop completes.

### Visual Trace (Example 1: [7,8,3,4,15,13,4,1])
Sorted: [1, 3, 4, 4, 7, 8, 13, 15]

| Iteration (i) | Smallest (nums[i]) | Largest (nums[n-i-1]) | Average | Min Average (ans) |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 1 | 15 | 8.0 | 8.0 |
| 1 | 3 | 13 | 8.0 | 8.0 |
| 2 | 4 | 8 | 6.0 | 6.0 |
| 3 | 4 | 7 | 5.5 | 5.5 |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step. The subsequent linear scan takes $$O(N)$$, which is dominated by the sort.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we perform the operations in-place without auxiliary data structures.

# Code
```cpp
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double ans = INT_MAX;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        while(i<n/2){
            double maxi = nums[n-i-1];
            double mini = nums[i];
            double average = (maxi+mini)/2;
            ans = min(ans,average);
            i++;
        }


        return ans;
    }
};
```

# [1619. Mean of Array After Removing Some Elements](https://leetcode.com/problems/mean-of-array-after-removing-some-elements/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
Given an integer array `arr`, return *the mean of the remaining integers after removing the smallest `5%` and the largest `5%` of the elements.*

Answers within `10-5` of the **actual answer** will be considered accepted.

**Example 1:**

```
Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
Output: 2.00000
Explanation: After erasing the minimum and the maximum values of this array, all elements are equal to 2, so the mean is 2.
```

**Example 2:**

```
Input: arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
Output: 4.00000
```

**Example 3:**

```
Input: arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
Output: 4.77778
```

**Constraints:**

* `20 <= arr.length <= 1000`
* `arr.length`**is a multiple** of `20`.
* `0 <= arr[i] <= 105`

---

## Solution & Editorial
# Intuition
To calculate the mean after removing the smallest and largest 5% of elements, we must first identify which elements fall into these categories. Since the array is not necessarily sorted, sorting it allows us to easily isolate the bottom 5% and top 5% by index range.

# Approach
1. Sort the input array `arr` in non-decreasing order. This groups the smallest elements at the beginning and the largest at the end.
2. Calculate the number of elements to remove from each end: `fivePercent = arr.size() * 0.05`.
3. Compute the sum of the elements in the range `[fivePercent, arr.size() - fivePercent)`. This effectively excludes the bottom 5% and top 5%.
4. Divide the calculated sum by the count of the remaining elements (`arr.size() - 2 * fivePercent`) to get the mean.

### Visual Trace (Example 1: arr.length = 20)
- `fivePercent` = 20 * 0.05 = 1.
- Sorted `arr`: `[1, 2, 2, ..., 2, 3]`
- Range to sum: `arr[1]` to `arr[18]` (inclusive).
- Sum = `2 * 18 = 36`.
- Remaining count = `20 - 2 = 18`.
- Mean = `36 / 18 = 2.0`.

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the length of the array, due to the sorting operation. The subsequent summation and division are $$O(N)$$.
- Space complexity: $$O(1)$$ or $$O(\log N)$$ depending on the implementation of `std::sort` (typically introsort uses logarithmic stack space).

# Code
```cpp
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int length = arr.size();
        int fivePercent = length * 5 /100;
        int sum = accumulate(arr.begin()+fivePercent,arr.end()-fivePercent,0);
        int remainingSize = length - (2 * fivePercent);
        double mean = sum/(double)remainingSize;
        return mean;
    }
};
```

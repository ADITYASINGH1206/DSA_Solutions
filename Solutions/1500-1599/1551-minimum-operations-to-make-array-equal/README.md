# [1551. Minimum Operations to Make Array Equal](https://leetcode.com/problems/minimum-operations-to-make-array-equal/)
**Difficulty:** `Medium` | **Tags:** `math`

---

## Problem Description
You have an array `arr` of length `n` where `arr[i] = (2 * i) + 1` for all valid values of `i` (i.e., `0 <= i < n`).

In one operation, you can select two indices `x` and `y` where `0 <= x, y < n` and subtract `1` from `arr[x]` and add `1` to `arr[y]` (i.e., perform `arr[x] -=1` and `arr[y] += 1`). The goal is to make all the elements of the array **equal**. It is **guaranteed** that all the elements of the array can be made equal using some operations.

Given an integer `n`, the length of the array, return *the minimum number of operations* needed to make all the elements of arr equal.

**Example 1:**

```
Input: n = 3
Output: 2
Explanation: arr = [1, 3, 5]
First operation choose x = 2 and y = 0, this leads arr to be [2, 3, 4]
In the second operation choose x = 2 and y = 0 again, thus arr = [3, 3, 3].
```

**Example 2:**

```
Input: n = 6
Output: 9
```

**Constraints:**

* `1 <= n <= 104`

---

## Solution & Editorial
# Intuition
The array is defined as `arr[i] = 2*i + 1`. The target value for every element in the array is the median, which is exactly `n`. Since the array is symmetric around `n`, we only need to move values from the elements greater than `n` to the elements smaller than `n` until all elements equal `n`.

# Approach
1. The target value for all elements is `n`. 
2. We iterate through the first half of the array (indices `0` to `n/2 - 1`).
3. For each index `i`, the value is `2*i + 1`. The difference between the target `n` and the current value is `n - (2*i + 1)`.
4. We accumulate these differences into `ans` to find the total number of operations required.

### Visual Trace (n = 3)
- Target = 3
- Loop runs for `i = 0` (since `n/2 = 1`):
  - `i = 0`: `arr[0] = 1`. Difference = `3 - 1 = 2`.
  - `ans = 0 + 2 = 2`.
- Result: 2.

# Complexity
- Time complexity: $$O(n)$$ because we iterate through half of the array elements.
- Space complexity: $$O(1)$$ as we only use a single integer variable `ans` to store the result.

# Code
```cpp
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i =0;i<n/2;i++){
            int temp = abs(((2*i)+1)-n);
            ans += temp;
        }
        return ans;
    }
};
```

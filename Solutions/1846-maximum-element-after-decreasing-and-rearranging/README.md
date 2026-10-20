# [1846. Maximum Element After Decreasing and Rearranging](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given an array of positive integers `arr`. Perform some operations (possibly none) on `arr` so that it satisfies these conditions:

* The value of the **first** element in `arr` must be `1`.
* The absolute difference between any 2 adjacent elements must be **less than or equal to** `1`. In other words, `abs(arr[i] - arr[i - 1]) <= 1` for each `i` where `1 <= i < arr.length` (**0-indexed**). `abs(x)` is the absolute value of `x`.

There are 2 types of operations that you can perform any number of times:

* **Decrease** the value of any element of `arr` to a **smaller positive integer**.
* **Rearrange** the elements of `arr` to be in any order.

Return *the **maximum** possible value of an element in* `arr` *after performing the operations to satisfy the conditions*.

**Example 1:**

```
Input: arr = [2,2,1,2,1]
Output: 2
Explanation: 
We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
The largest element in arr is 2.
```

**Example 2:**

```
Input: arr = [100,1,1000]
Output: 3
Explanation: 
One possible way to satisfy the conditions is by doing the following:
1. Rearrange arr so it becomes [1,100,1000].
2. Decrease the value of the second element to 2.
3. Decrease the value of the third element to 3.
Now arr = [1,2,3], which satisfies the conditions.
The largest element in arr is 3.
```

**Example 3:**

```
Input: arr = [1,2,3,4,5]
Output: 5
Explanation: The array already satisfies the conditions, and the largest element is 5.
```

**Constraints:**

* `1 <= arr.length <= 105`
* `1 <= arr[i] <= 109`

---

## Solution & Editorial
# Intuition
To maximize the largest element, we must keep elements as large as possible while satisfying the constraints. Since we can rearrange the array, sorting it first allows us to process elements in non-decreasing order, making it easier to enforce the condition that adjacent elements differ by at most 1.

# Approach
1. **Sort**: Sort the array `arr` in non-decreasing order. This allows us to greedily assign the smallest possible valid values to the smallest available numbers.
2. **Initialize**: Set the first element `arr[0]` to 1, as required by the problem.
3. **Iterate**: Traverse the sorted array from index 1 to `n-1`. For each element `arr[i]`, ensure it satisfies the condition `arr[i] <= arr[i-1] + 1`. If `arr[i]` is already smaller than or equal to `arr[i-1] + 1`, we keep it as is (or effectively keep it as large as possible). If it is larger, we cap it at `arr[i-1] + 1`.
4. **Result**: The last element of the modified array will be the maximum possible value.

### Visual Trace (Example 2: [100, 1, 1000])
- **Sort**: `[1, 100, 1000]`
- **Step 0**: `arr[0] = 1`
- **Step 1 (i=1)**: `arr[1] = min(100, 1 + 1) = 2`. Array: `[1, 2, 1000]`
- **Step 2 (i=2)**: `arr[2] = min(1000, 2 + 1) = 3`. Array: `[1, 2, 3]`
- **Result**: `3`

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step, where $$N$$ is the length of the array. The subsequent linear scan takes $$O(N)$$.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we modify the array in-place.

# Code
```cpp
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        return arr.back();
    }
};
```

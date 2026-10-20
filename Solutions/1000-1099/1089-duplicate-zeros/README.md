# [1089. Duplicate Zeros](https://leetcode.com/problems/duplicate-zeros/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`

---

## Problem Description
Given a fixed-length integer array `arr`, duplicate each occurrence of zero, shifting the remaining elements to the right.

**Note** that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

**Example 1:**

```
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
```

**Example 2:**

```
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
```

**Constraints:**

* `1 <= arr.length <= 104`
* `0 <= arr[i] <= 9`

---

## Solution & Editorial
# Intuition
The problem requires us to modify the array in place by duplicating every zero encountered and shifting subsequent elements to the right while discarding any elements that exceed the original array bounds. We can simulate this directly by iterating through the array and performing insertions and deletions.

# Approach
1. Initialize a loop variable `i` from `0` to `arr.size() - 1`.
2. Check if the element at `arr[i]` is equal to `0`.
3. If `arr[i]` is `0`, insert a new `0` immediately after index `i` using `arr.insert(arr.begin() + (i + 1), 0)`.
4. Increment `i` by 1 to skip processing the newly inserted zero, preventing an infinite loop.
5. Call `arr.pop_back()` to maintain the fixed size of the array.

### Visual Trace Walkthrough
Example: `arr = [1, 0, 2, 3]`
- `i = 0`: `arr[0] = 1` (Not zero). `arr` remains `[1, 0, 2, 3]`.
- `i = 1`: `arr[1] = 0` (Zero found). Insert `0` at index 2 $ightarrow$ `[1, 0, 0, 2, 3]`. Increment `i` to 2. Pop back $ightarrow$ `[1, 0, 0, 2]`.
- `i = 2`: `arr[2] = 0` (Newly inserted zero). Insert `0` at index 3 $ightarrow$ `[1, 0, 0, 0, 2]`. Increment `i` to 3. Pop back $ightarrow$ `[1, 0, 0, 0]`.
- `i = 3`: `arr[3] = 0` (Newly inserted zero). Insert `0` at index 4 $ightarrow$ `[1, 0, 0, 0, 0]`. Increment `i` to 4. Pop back $ightarrow$ `[1, 0, 0, 0]`.
- Loop terminates as `i` reaches array bounds.

# Complexity
- Time complexity: $$O(N^2)$$ where $$N$$ is the size of the array. In the worst case (e.g., all zeros), each insertion shifts up to $$N$$ elements, taking $$O(N)$$ time per zero.
- Space complexity: $$O(1)$$ auxiliary space, as all modifications are performed directly in place on the existing array.

# Code
```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                arr.insert(arr.begin() + (i + 1), 0);
                i = i + 1;
                arr.pop_back();
            }
        }
    }
};
```

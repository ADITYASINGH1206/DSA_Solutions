# [1299. Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given an array `arr`, replace every element in that array with the greatest element among the elements to its right, and replace the last element with `-1`.

After doing so, return the array.

**Example 1:**

```
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation: 
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
```

**Example 2:**

```
Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.
```

**Constraints:**

* `1 <= arr.length <= 104`
* `1 <= arr[i] <= 105`

---

## Solution & Editorial
# Intuition
To replace each element with the greatest element to its right efficiently, we can traverse the array backwards from right to left. By maintaining the running maximum of elements seen so far from the right, we can update each position in a single pass without needing any auxiliary data structures.

# Approach
1. Initialize `n` as the size of `arr` and a variable `maxi` to `-1`, representing the maximum element to the right of the current element.
2. Iterate backwards from index `i = n - 1` down to `0`.
3. In each iteration, use `swap(arr[i], maxi)` to store the current running maximum into `arr[i]` and retrieve the original element into `maxi` temporarily.
4. Update `maxi = max(maxi, arr[i])` to propagate the maximum value found so far to the next iterations.
5. Return the modified `arr`.

### Visual Walkthrough (Example 1: `arr = [17, 18, 5, 4, 6, 1]`)

| Index `i` | Before Swap (`maxi`) | Operation (`swap(arr[i], maxi)`) | After Swap (`arr[i]`, `maxi`) | Updated `maxi = max(maxi, arr[i])` |
| :---: | :---: | :---: | :---: | :--- |
| 5 | -1 | `swap(arr[5], -1)` | `arr[5] = -1`, `maxi = 1` | `max(1, -1) = 1` |
| 4 | 1 | `swap(arr[4], 1)` | `arr[4] = 1`, `maxi = 6` | `max(6, 1) = 6` |
| 3 | 6 | `swap(arr[3], 6)` | `arr[3] = 6`, `maxi = 4` | `max(4, 6) = 6` |
| 2 | 6 | `swap(arr[2], 6)` | `arr[2] = 6`, `maxi = 5` | `max(5, 6) = 6` |
| 1 | 6 | `swap(arr[1], 6)` | `arr[1] = 6`, `maxi = 18` | `max(18, 6) = 18` |
| 0 | 18 | `swap(arr[0], 18)` | `arr[0] = 18`, `maxi = 17` | `max(17, 18) = 18` |

Result: `[18, 6, 6, 6, 1, -1]`

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in `arr`. We perform a single linear scan from the last element to the first.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for scalar variables (`n`, `maxi`) and perform the operation in-place.

# Code
```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int maxi=-1;
        for(int i=n-1;i>=0;i--){
            swap(arr[i],maxi);
            maxi=max(maxi,arr[i]);
        }
        return arr;
    }
};
```

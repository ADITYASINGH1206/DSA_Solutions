# [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`, `sorting`

---

## Problem Description
You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

**Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.

The final sorted array should not be returned by the function, but instead be *stored inside the array* `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

**Example 1:**

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```

**Example 2:**

```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
```

**Example 3:**

```
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
```

**Constraints:**

* `nums1.length == m + n`
* `nums2.length == n`
* `0 <= m, n <= 200`
* `1 <= m + n <= 200`
* `-109 <= nums1[i], nums2[j] <= 109`

**Follow up:** Can you come up with an algorithm that runs in `O(m + n)` time?

---

## Solution & Editorial
# Intuition
When merging two sorted arrays into the end of the first array, starting from the front would overwrite existing elements in `nums1`. By utilizing a two-pointer approach working backwards from the end of both arrays, we can place the largest remaining elements directly into their final sorted positions without needing extra space.

# Approach
1. Initialize pointer `p1` at `m - 1` (last valid element in `nums1`), pointer `p2` at `n - 1` (last element in `nums2`), and pointer `p` at `m + n - 1` (the very end of `nums1`).
2. Iterate while `p2 >= 0` to ensure all elements from `nums2` are placed.
3. Compare elements at `nums1[p1]` and `nums2[p2]`. If `p1 >= 0` and `nums1[p1] > nums2[p2]`, assign `nums1[p] = nums1[p1]` and decrement `p1`. Otherwise, assign `nums1[p] = nums2[p2]` and decrement `p2`.
4. Decrement `p` in each iteration.
5. If `p1` finishes before `p2`, remaining elements of `nums2` are automatically copied over. If `p2` finishes first, the remaining elements of `nums1` are already in place.

### Visual Trace Walkthrough
Example 1: `nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3`
- Initial: `p1 = 2`, `p2 = 2`, `p = 5`
- `nums1[2] (3) < nums2[2] (6)` -> `nums1[5] = 6`, `p2 = 1`, `p = 4`
- `nums1[2] (3) < nums2[1] (5)` -> `nums1[4] = 5`, `p2 = 0`, `p = 3`
- `nums1[2] (3) > nums2[0] (2)` -> `nums1[3] = 3`, `p1 = 1`, `p = 2`
- `nums1[1] (2) == nums2[0] (2)` -> `nums1[2] = 2`, `p2 = -1`, `p = 1`
- Loop terminates as `p2 < 0`. Final `nums1 = [1, 2, 2, 3, 5, 6]`.

# Complexity
- Time complexity: $$O(m + n)$$ — Each element from `nums1` and `nums2` is visited at most once by pointers `p1` and `p2`.
- Space complexity: $$O(1)$$ — In-place merging requires only a constant amount of extra memory for pointers.

# Code
```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int p = m+n-1;
        while(p2>=0){
            if(p1>=0 && nums1[p1] > nums2[p2]){
                nums1[p] = nums1[p1];
                p1--;
                
            }else{
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        
    }
};
```

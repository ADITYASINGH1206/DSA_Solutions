# [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)
**Difficulty:** `Hard` | **Tags:** `array`, `binary-search`, `divide-and-conquer`

---

## Problem Description
Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

**Example 1:**

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

**Example 2:**

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

**Constraints:**

* `nums1.length == m`
* `nums2.length == n`
* `0 <= m <= 1000`
* `0 <= n <= 1000`
* `1 <= m + n <= 2000`
* `-106 <= nums1[i], nums2[i] <= 106`

---

## Solution & Editorial
# Intuition
To find the median of two sorted arrays in `O(log(m+n))` time, we can leverage binary search. The core idea is to partition both arrays into two halves such that all elements in the left halves are less than or equal to all elements in the right halves. If we can find such a partition, the median will be derived from the maximum element of the left halves and the minimum element of the right halves.

# Approach
The solution employs a binary search strategy on the smaller of the two arrays to find the optimal partition point. This ensures the binary search range is minimized, leading to `O(log(min(m,n)))` time complexity.

1.  **Handle Array Sizes**: First, the code ensures that `nums1` is always the smaller array. If `nums2` is smaller, it recursively calls `findMedianSortedArrays` with `nums2` and `nums1` swapped. This optimization limits the binary search range to `min(m, n)`. Let `n1` be `nums1.size()` and `n2` be `nums2.size()` after this potential swap.

2.  **Binary Search Initialization**: Initialize `low = 0` and `high = n1`. These represent the possible cut points (`c1`) in `nums1`. `c1` denotes that `c1` elements from `nums1` are in the left partition.

3.  **Iterative Search**: The `while (low <= high)` loop performs the binary search:
    *   **Calculate `c1`**: `c1 = (low + high) >> 1` determines the partition point in `nums1`.
    *   **Calculate `c2`**: The total number of elements in the combined left partition should be `(n1 + n2 + 1) / 2`. Thus, `c2 = (n1 + n2 + 1) / 2 - c1` determines the partition point in `nums2`.
    *   **Define Boundary Elements**: To check the validity of the partition, we need the elements immediately surrounding the cuts:
        *   `l1`: The element just before `c1` in `nums1`. If `c1` is 0, `l1` is `INT_MIN` (no elements from `nums1` in the left partition).
        *   `l2`: The element just before `c2` in `nums2`. If `c2` is 0, `l2` is `INT_MIN`.
        *   `r1`: The element at `c1` in `nums1`. If `c1` is `n1`, `r1` is `INT_MAX` (all elements from `nums1` are in the left partition).
        *   `r2`: The element at `c2` in `nums2`. If `c2` is `n2`, `r2` is `INT_MAX`.

4.  **Check Partition Validity**: The condition `l1 <= r2 && l2 <= r1` verifies if the partition is valid. This means all elements in the left halves (`l1`, `l2`) are less than or equal to all elements in the right halves (`r1`, `r2`).
    *   **If Valid**: If the condition holds, we've found the correct partition.
        *   If `(n1 + n2)` is even, the median is the average of `max(l1, l2)` and `min(r1, r2)`.
        *   If `(n1 + n2)` is odd, the median is `max(l1, l2)`.
    *   **If Invalid**: Adjust the binary search range:
        *   If `l1 > r2`, it means `c1` is too large (too many elements from `nums1` are in the left partition), so we need to move the cut `c1` to the left: `high = c1 - 1`.
        *   Else (`l2 > r1`), it means `c1` is too small (too few elements from `nums1` are in the left partition), so we need to move the cut `c1` to the right: `low = c1 + 1`.

5.  **Return**: The loop continues until a valid partition is found and the median is returned.

### Visual Dry Run: Example 1
`nums1 = [1,3], nums2 = [2]`

1.  Initial call: `findMedianSortedArrays([1,3], [2])`
    *   `nums2.size() (1) < nums1.size() (2)` is true. Recursive call: `findMedianSortedArrays([2], [1,3])`.
    *   Now, `nums1 = [2]` (`n1=1`), `nums2 = [1,3]` (`n2=2`).
    *   Total elements `n1+n2 = 3`. Target left partition size `(3+1)/2 = 2`.
    *   `low = 0`, `high = n1 = 1`.

| Iteration | `low` | `high` | `c1` | `c2` | `l1` | `l2` | `r1` | `r2` | Condition (`l1<=r2 && l2<=r1`) | Action | `nums1` Left | `nums2` Left | `nums1` Right | `nums2` Right |
| :-------- | :---- | :----- | :--- | :--- | :--- | :--- | :--- | :--- | :-------------------------------- | :----- | :----------- | :----------- | :------------ | :------------ |
| 1         | 0     | 1      | 0    | 2    | INT_MIN | 3    | 2    | INT_MAX | `INT_MIN<=INT_MAX && 3<=2` (F) | `low = 1` | `[]`         | `[1,3]`      | `[2]`         | `[]`          |
| 2         | 1     | 1      | 1    | 1    | 2    | 1    | INT_MAX | 3    | `2<=3 && 1<=INT_MAX` (T)        | Return | `[2]`        | `[1]`        | `[]`          | `[3]`         |

*   In Iteration 2, the condition is true. Total elements `(n1+n2) = 3` is odd.
*   Median is `max(l1, l2) = max(2, 1) = 2`.
*   The function returns `2.0`.

# Complexity
- Time complexity: $$O(\log(\min(M,N)))$$ — The binary search is performed on the smaller of the two arrays. The search space for `c1` is `min(M, N)`, and in each step, the search space is halved. All operations inside the loop (calculating `c1`, `c2`, `l1`, `l2`, `r1`, `r2`, and checking conditions) take constant time, $$O(1)$$. Therefore, the overall time complexity is logarithmic with respect to the size of the smaller array.
- Space complexity: $$O(1)$$ — The algorithm uses a fixed number of variables regardless of the input array sizes. The recursive call for swapping arrays is a tail call and does not add significant stack space in most modern compilers, effectively making it $$O(1)$$ auxiliary space.

# Code
```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0,high = n1;
        
        while(low<=high){
            int c1 = (low+high) >> 1;
            int c2 = (n1+n2 +1)/2 - c1;

            int l1 = c1 == 0 ? INT_MIN : nums1[c1-1];
            int l2 = c2 == 0 ? INT_MIN : nums2[c2-1];

            int r1 = c1 == n1 ? INT_MAX : nums1[c1];
            int r2 = c2 == n2 ? INT_MAX : nums2[c2];   

            if(l1 <= r2 && l2 <= r1){
                if( (n1 + n2) %2 == 0){
                    return (max(l1,l2) + min(r1,r2))/ 2.0;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1> r2) high = c1 -1;
            else low = c1 +1;
        }
        return 0.0;         
    }
};
```

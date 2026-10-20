# [1752. Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given an array `nums`, return `true` *if the array was originally sorted in non-decreasing order, then rotated **some** number of positions (including zero)*. Otherwise, return `false`.

There may be **duplicates** in the original array.

**Note:** An array `A` rotated by `x` positions results in an array `B` of the same length such that `B[i] == A[(i+x) % A.length]` for every valid index `i`.

**Example 1:**

```
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
```

**Example 2:**

```
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
```

**Example 3:**

```
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
An array that is sorted and then rotated will have at most one "drop" (a point where `nums[i] > nums[i+1]`). If we consider the array as circular, the last element `nums[n-1]` and the first element `nums[0]` also form a pair that must be checked to account for the rotation.

# Approach
1. Initialize a counter `cnt` to 0.
2. Iterate through the array using index `i` from `0` to `n-1`.
3. For each index, compare `nums[i]` with the next element in a circular fashion: `nums[(i + 1) % n]`.
4. If `nums[i] > nums[(i + 1) % n]`, increment `cnt`.
5. After the loop, if `cnt <= 1`, the array is a rotated sorted array. Otherwise, it is not.

### Visual Trace (Example 1: [3, 4, 5, 1, 2])
| i | nums[i] | nums[(i+1)%5] | Drop? | cnt |
|---|---|---|---|---|
| 0 | 3 | 4 | No | 0 |
| 1 | 4 | 5 | No | 0 |
| 2 | 5 | 1 | Yes | 1 |
| 3 | 1 | 2 | No | 1 |
| 4 | 2 | 3 | No | 1 |
Result: `cnt` (1) <= 1 is true.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we perform a single pass over the elements.
- Space complexity: $$O(1)$$, as we only use a single integer variable for counting.

# Code
```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            cnt += nums[i] > (nums[(i + 1) % n]);
        }
        return cnt <= 1;
    }
};
```

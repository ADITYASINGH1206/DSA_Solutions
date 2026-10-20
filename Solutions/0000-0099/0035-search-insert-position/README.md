# [35. Search Insert Position](https://leetcode.com/problems/search-insert-position/)
**Difficulty:** `Easy` | **Tags:** `array`, `binary-search`

---

## Problem Description
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```
Input: nums = [1,3,5,6], target = 5
Output: 2
```

**Example 2:**

```
Input: nums = [1,3,5,6], target = 2
Output: 1
```

**Example 3:**

```
Input: nums = [1,3,5,6], target = 7
Output: 4
```

**Constraints:**

* `1 <= nums.length <= 104`
* `-104 <= nums[i] <= 104`
* `nums` contains **distinct** values sorted in **ascending** order.
* `-104 <= target <= 104`

---

## Solution & Editorial
# Intuition
Since the input array `nums` is sorted in ascending order and we need an $$O(\log n)$$ time complexity solution, binary search is the optimal strategy. We can maintain a search window `[l, r]` and narrow it down until we locate the target or find the exact insertion index.

# Approach
1. Initialize two pointers: `l = 0` representing the start of the array and `r = n - 1` representing the end of the array.
2. Run a `while` loop as long as `l <= r`.
3. Compute the middle index `mid = l + (r - l) / 2` to prevent potential integer overflow.
4. If `nums[mid] == target`, immediately return `mid`.
5. If `nums[mid] > target`, the target must lie in the left half, so update `r = mid - 1`.
6. If `nums[mid] < target`, the target must lie in the right half, so update `l = mid + 1`.
7. If the loop terminates without finding the target, `l` points to the exact correct insertion index.

### Visual Dry Run (Example 1: nums = [1, 3, 5, 6], target = 5)
| Iteration | `l` | `r` | `mid` | `nums[mid]` | Action | Next State |
| :--- | :---: | :---: | :---: | :---: | :--- | :--- |
| 1 | 0 | 3 | 1 | 3 | `nums[mid] < target` | `l = mid + 1` (2) |
| 2 | 2 | 3 | 2 | 5 | `nums[mid] == target` | Returns `2` |

# Complexity
- Time complexity: $$O(\log n)$$ — The search space is halved in each iteration of the binary search loop.
- Space complexity: $$O(1)$$ — Only a few integer variables are used for pointers and indices.

# Code
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r= mid-1;
            else l = mid+1;
        }

        return l;
    }
};
```

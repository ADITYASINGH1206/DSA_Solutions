# [27. Remove Element](https://leetcode.com/problems/remove-element/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`

---

## Problem Description
Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm). The order of the elements may be changed. Then return *the number of elements in* `nums` *which are not equal to* `val`.

Consider the number of elements in `nums` which are not equal to `val` be `k`, to get accepted, you need to do the following things:

* Change the array `nums` such that the first `k` elements of `nums` contain the elements which are not equal to `val`. The remaining elements of `nums` are not important as well as the size of `nums`.
* Return `k`.

**Custom Judge:**

The judge will test your solution with the following code:

```
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted**.

**Example 1:**

```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Constraints:**

* `0 <= nums.length <= 100`
* `0 <= nums[i] <= 50`
* `0 <= val <= 100`

---

## Solution & Editorial
# Intuition
The problem requires us to remove all occurrences of a specified value `val` from an array `nums` in-place and return the count of remaining elements. Since we must modify the array in-place with $O(1)$ extra memory, we can maintain a write pointer (`y`) that tracks the position where the next valid element (not equal to `val`) should be placed.

# Approach
1. Initialize an integer pointer `y` to `0`. This variable acts as the write index and also counts the number of valid elements.
2. Iterate through each element `x` in the `nums` vector using a range-based for loop.
3. Check if the current element `x` is not equal to `val`.
4. If `x != val`, assign `x` to `nums[y]` and then increment `y` by `1`.
5. After checking all elements, return `y` as the total count of elements not equal to `val`.

### Visual Walkthrough (Example 1: `nums = [3, 2, 2, 3]`, `val = 3`)

| Iteration | `x` (Current Element) | Condition `x != 3` | Action | `nums` Array State | `y` (Write Index) |
| :---: | :---: | :---: | :---: | :---: | :---: |
| Start | - | - | - | `[3, 2, 2, 3]` | `0` |
| 1 | `3` | False | Skip | `[3, 2, 2, 3]` | `0` |
| 2 | `2` | True | `nums[0] = 2`, `y++` | `[2, 2, 2, 3]` | `1` |
| 3 | `2` | True | `nums[1] = 2`, `y++` | `[2, 2, 2, 3]` | `2` |
| 4 | `3` | False | Skip | `[2, 2, 2, 3]` | `2` |

Final returned value: `2`. The first 2 elements contain `[2, 2]`.

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the `nums` array of size $$N$$ exactly once, performing constant time $$O(1)$$ comparisons and assignments at each step.
- Space complexity: $$O(1)$$ — No additional memory or data structures are used; modifications are done entirely in-place.

# Code
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int y = 0;
        for (int x : nums) {
            if (x != val) {
                nums[y++] = x;
            }
        }
        return y;
    }
};
```

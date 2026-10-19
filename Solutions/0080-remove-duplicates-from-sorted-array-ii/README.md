# [80. Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`

---

## Problem Description
Given an integer array `nums` sorted in **non-decreasing order**, remove some duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that each unique element appears **at most twice**. The **relative order** of the elements should be kept the **same**.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part** of the array `nums`. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.

Return `k` *after placing the final result in the first* `k` *slots of* `nums`.

Do **not** allocate extra space for another array. You must do this by **modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** with O(1) extra memory.

**Custom Judge:**

The judge will test your solution with the following code:

```
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be **accepted**.

**Example 1:**

```
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Constraints:**

* `1 <= nums.length <= 3 * 104`
* `-104 <= nums[i] <= 104`
* `nums` is sorted in **non-decreasing** order.

---

## Solution & Editorial
# Intuition
Since the array is sorted in non-decreasing order, any duplicate elements will appear contiguously. We can maintain a write pointer `i` that allows each unique element to appear at most twice by comparing the current element with the element located two positions behind the write pointer (`nums[i-2]`).

# Approach
1. Initialize a write pointer `i` to `0` to keep track of the valid position in the modified array.
2. Iterate through each element `n` in the input array `nums` using a range-based for loop.
3. For each element, check if `i < 2` (allowing the first two elements unconditionally) or if `n != nums[i-2]` (ensuring no more than two identical elements are consecutively placed).
4. If the condition holds, assign `nums[i++] = n`, effectively storing the valid element and advancing the write pointer.
5. Finally, return `i` representing the new length of the array.

### Visual Dry Run (Example 1: `nums = [1, 1, 1, 2, 2, 3]`)

| Iteration (`n`) | `i` (before) | Condition (`i < 2 || n != nums[i-2]`) | Action | `nums` Array State | `i` (after) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `1` | `0` | `0 < 2` (True) | `nums[0] = 1` | `[1, 1, 1, 2, 2, 3]` | `1` |
| `1` | `1` | `1 < 2` (True) | `nums[1] = 1` | `[1, 1, 1, 2, 2, 3]` | `2` |
| `1` | `2` | `2 < 2` False, `1 != nums[0]` (False) | Skipped | `[1, 1, 1, 2, 2, 3]` | `2` |
| `2` | `2` | `2 < 2` False, `2 != nums[0]` (True) | `nums[2] = 2` | `[1, 1, 2, 2, 2, 3]` | `3` |
| `2` | `3` | `3 < 2` False, `2 != nums[1]` (True) | `nums[3] = 2` | `[1, 1, 2, 2, 2, 3]` | `4` |
| `3` | `4` | `4 < 2` False, `3 != nums[2]` (True) | `nums[4] = 3` | `[1, 1, 2, 2, 3, 3]` | `5` |

# Complexity
- Time complexity: $$O(N)$$ — We perform a single linear scan over the array of size $N$, executing constant time operations ($O(1)$) at each step.
- Space complexity: $$O(1)$$ — The modifications are performed strictly in-place using a single integer counter `i`, requiring no auxiliary memory structures.

# Code
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n != nums[i-2])
                nums[i++] = n;
        return i;
    }
};
```

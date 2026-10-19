# [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`

---

## Problem Description
Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**.

Consider the number of *unique elements* in `nums` to be `k​​​​​​​`​​​​​​​. After removing duplicates, return the number of unique elements `k`.

The first `k` elements of `nums` should contain the unique numbers in **sorted order**. The remaining elements beyond index `k - 1` can be ignored.

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
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Constraints:**

* `1 <= nums.length <= 3 * 104`
* `-100 <= nums[i] <= 100`
* `nums` is sorted in **non-decreasing** order.

---

## Solution & Editorial
# Intuition
Since the array is sorted in non-decreasing order, any duplicate elements must appear adjacent to each other. We can efficiently remove duplicates in-place using a two-pointer approach, maintaining a slow pointer for the unique elements region and a fast pointer to scan the array.

# Approach
1. Initialize a pointer `i = 0` to track the last position of the unique elements array.
2. Iterate through the array using a fast pointer `j` starting from index `1` to `nums.size() - 1`.
3. Compare `nums[j]` with `nums[i]`. If they are not equal, it means we have found a new unique element.
4. Increment `i` by 1 and assign `nums[i] = nums[j]` to place the unique element in its correct position.
5. After the loop completes, return `i + 1` representing the total number of unique elements.

### Visual Walkthrough (Example 1: `nums = [1, 1, 2]`)

| Iteration | `j` | `nums[j]` | `i` | `nums[i]` | Condition `nums[j] != nums[i]` | Action | Array State (`nums`) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| Initial | - | - | 0 | 1 | - | - | `[1, 1, 2]` |
| 1 | 1 | 1 | 0 | 1 | `1 != 1` (False) | Skip | `[1, 1, 2]` |
| 2 | 2 | 2 | 0 | 1 | `2 != 1` (True) | `i++` (1), `nums[1] = 2` | `[1, 2, 2]` |

Final returned length: `i + 1 = 2`.

# Complexity
- Time complexity: $$O(N)$$ — The fast pointer `j` traverses the array of size `N` exactly once, performing constant time $$O(1)$$ comparisons and assignments.
- Space complexity: $$O(1)$$ — Only a constant amount of extra memory (`i` and `j`) is used, satisfying in-place modification constraints.

# Code
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j =1;j<nums.size();j++){
            if(nums[j]!= nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};
```

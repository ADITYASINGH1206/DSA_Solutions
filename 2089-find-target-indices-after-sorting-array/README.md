# [2089. Find Target Indices After Sorting Array](https://leetcode.com/problems/find-target-indices-after-sorting-array/)
**Difficulty:** Easy | **Tags:** c, array, sorting

---

## Problem Description
You are given a **0-indexed** integer array `nums` and a target element `target`.

A **target index** is an index `i` such that `nums[i] == target`.

Return *a list of the target indices of* `nums` after *sorting* `nums` *in **non-decreasing** order*. If there are no target indices, return *an **empty** list*. The returned list must be sorted in **increasing** order.

**Example 1:**

```
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
```

**Example 2:**

```
Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.
```

**Example 3:**

```
Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i], target <= 100`

---

## Solution & Editorial
# Intuition
The core idea is that if we sort the array, all occurrences of the `target` element will become contiguous. Once the array is sorted, we can simply iterate through it and collect the indices where the element matches the `target`.

# Approach
1.  Initialize an empty `std::vector<int> ans` to store the indices where `nums[i]` equals `target` after sorting.
2.  Sort the input `nums` array in non-decreasing order using `std::sort(nums.begin(), nums.end())`. This operation rearranges the elements such that all identical values are grouped together.
3.  Iterate through the sorted `nums` array from index `i = 0` up to `n-1` (where `n` is `nums.size()`).
4.  Inside the loop, check if the current element `nums[i]` is equal to the `target`.
5.  If `nums[i] == target`, add the current index `i` to the `ans` vector using `ans.push_back(i)`.
6.  After iterating through the entire sorted array, return the `ans` vector, which will contain all target indices in increasing order.

### Visual Dry Run (Example 1: `nums = [1,2,5,2,3], target = 2`)

| Step | `nums` (initial) | `ans` (initial) | Action                               | `nums` (after sort) | `i` | `nums[i]` | `nums[i] == target` | `ans` (after push) |
| :--- | :--------------- | :-------------- | :----------------------------------- | :------------------ | :-- | :-------- | :------------------ | :----------------- |
| 1    | `[1,2,5,2,3]`    | `[]`            | Initialize `ans`                     | `[1,2,5,2,3]`       |     |           |                     | `[]`               |
| 2    | `[1,2,5,2,3]`    | `[]`            | Sort `nums`                          | `[1,2,2,3,5]`       |     |           |                     | `[]`               |
| 3    |                  |                 | Loop `i=0`                           | `[1,2,2,3,5]`       | 0   | 1         | False               | `[]`               |
| 4    |                  |                 | Loop `i=1`                           | `[1,2,2,3,5]`       | 1   | 2         | True                | `[1]`              |
| 5    |                  |                 | Loop `i=2`                           | `[1,2,2,3,5]`       | 2   | 2         | True                | `[1,2]`            |
| 6    |                  |                 | Loop `i=3`                           | `[1,2,2,3,5]`       | 3   | 3         | False               | `[1,2]`            |
| 7    |                  |                 | Loop `i=4`                           | `[1,2,2,3,5]`       | 4   | 5         | False               | `[1,2]`            |
| 8    |                  |                 | Return `ans`                         |                     |     |           |                     | `[1,2]`            |

# Complexity
- Time complexity: $$O(N \text{ log } N)$$ 
  The dominant operation is sorting the `nums` array, which takes $$O(N \text{ log } N)$$ time using `std::sort` for an array of size `N`. The subsequent linear scan to find target indices takes $$O(N)$$ time. Therefore, the total time complexity is $$O(N \text{ log } N) + O(N) = O(N \text{ log } N)$$.

- Space complexity: $$O(\text{log } N)$$ 
  `std::sort` typically uses an IntroSort algorithm, which has an auxiliary space complexity of $$O(\text{log } N)$$ due to the recursion stack. The `ans` vector stores the result; its size can be up to `N` elements in the worst case (if all elements are `target`), but it is considered output space rather than auxiliary space for the algorithm's internal workings. Thus, the auxiliary space complexity is dominated by the sorting algorithm's stack space.

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
The problem asks us to find all indices where a `target` element appears in an array *after* it has been sorted. The most straightforward way to achieve this is to first sort the array, which brings all occurrences of the `target` element together. Once sorted, we can then iterate through the array to identify and collect these indices.

# Approach
The solution follows a direct two-step process: sorting the input array and then performing a linear scan.

1.  **Initialize Result Vector**: A `std::vector<int> ans` is created to store the indices where the `target` is found.
2.  **Sort the Array**: The input `nums` array is sorted in non-decreasing order using `std::sort(nums.begin(), nums.end())`. This ensures that all identical elements, including the `target`, are grouped together.
3.  **Linear Scan for Target Indices**: The code then iterates through the sorted `nums` array from index `0` to `n-1` (where `n` is the size of `nums`).
4.  **Collect Indices**: In each iteration, if `nums[i]` is equal to `target`, the current index `i` is added to the `ans` vector.
5.  **Return Result**: Finally, the `ans` vector containing all target indices in increasing order is returned.

### Visual Dry Run (Example 1: `nums = [1,2,5,2,3], target = 2`)

| Step | `nums` (initial) | `nums` (sorted) | `i` | `nums[i]` | `target` | `nums[i] == target`? | `ans` |
| :--- | :--------------- | :-------------- | :-- | :-------- | :------- | :------------------- | :---- |
| 1    | `[1,2,5,2,3]`    | -               | -   | -         | `2`      | -                    | `[]`  |
| 2    | -                | `[1,2,2,3,5]`   | -   | -         | `2`      | -                    | `[]`  |
| 3    | -                | `[1,2,2,3,5]`   | `0` | `1`       | `2`      | `false`              | `[]`  |
| 4    | -                | `[1,2,2,3,5]`   | `1` | `2`       | `2`      | `true`               | `[1]` |
| 5    | -                | `[1,2,2,3,5]`   | `2` | `2`       | `2`      | `true`               | `[1,2]` |
| 6    | -                | `[1,2,2,3,5]`   | `3` | `3`       | `2`      | `false`              | `[1,2]` |
| 7    | -                | `[1,2,2,3,5]`   | `4` | `5`       | `2`      | `false`              | `[1,2]` |
| 8    | -                | -               | -   | -         | -        | -                    | `[1,2]` |

# Complexity
- Time complexity: $$O(N \log N)$$ 
  The dominant operation is sorting the `nums` array using `std::sort`, which typically has a time complexity of $$O(N \log N)$$, where $$N$$ is the number of elements in `nums`. The subsequent linear scan to find target indices takes $$O(N)$$ time. Therefore, the overall time complexity is $$O(N \log N) + O(N) = O(N \log N)$$.

- Space complexity: $$O(N)$$ 
  The `ans` vector stores the resulting target indices. In the worst case, all elements in `nums` could be equal to `target`, requiring `ans` to store $$N$$ elements. Thus, the space complexity for the output is $$O(N)$$. The `std::sort` algorithm typically uses $$O(\log N)$$ auxiliary space for its recursion stack (e.g., with Introsort), but this is dominated by the output vector's space requirement.

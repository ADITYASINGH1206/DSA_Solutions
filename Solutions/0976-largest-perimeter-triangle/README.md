# [976. Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `greedy`, `sorting`, `quicksort`, `polygons`

---

## Problem Description
Given an integer array `nums`, return *the largest perimeter of a triangle with a non-zero area, formed from three of these lengths*. If it is impossible to form any triangle of a non-zero area, return `0`.

**Example 1:**

```
Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
```

**Example 2:**

```
Input: nums = [1,2,1,10]
Output: 0
Explanation: 
You cannot use the side lengths 1, 1, and 2 to form a triangle.
You cannot use the side lengths 1, 1, and 10 to form a triangle.
You cannot use the side lengths 1, 2, and 10 to form a triangle.
As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.
```

**Constraints:**

* `3 <= nums.length <= 104`
* `1 <= nums[i] <= 106`

---

## Solution & Editorial
# Intuition
To maximize the perimeter of a triangle formed by three side lengths from an array, we should evaluate the largest available numbers first. Sorting the array in descending order allows us to use a greedy approach, checking adjacent triplets for the valid triangle inequality condition.

# Approach
1. Get the size of the array `n = nums.size()`.
2. Sort the array `nums` in descending order using `sort(nums.rbegin(), nums.rend())` so that larger elements are evaluated first.
3. Iterate from `i = 0` to `n - 3` to check every triplet of consecutive elements: `a = nums[i]`, `b = nums[i+1]`, and `c = nums[i+2]`.
4. Since the array is sorted descendingly, `a` is already the largest side. The triangle inequality condition simplifies to checking whether `a < b + c`.
5. If this condition holds, immediately return the perimeter `a + b + c` since we want the largest possible perimeter and we are scanning from largest to smallest.
6. If the loop completes without finding any valid triangle, return `0`.

### Visual Trace (Example 1: nums = [2, 1, 2])
- Sorted descending: `nums = [2, 2, 1]`
- `i = 0`: `a = 2`, `b = 2`, `c = 1` -> Check `2 < 2 + 1` (True). Return `2 + 2 + 1 = 5`.

# Complexity
- Time complexity: $$O(N \log N)$$ — Dominated by sorting the array of size $$N$$. The linear scan takes $$O(N)$$ time.
- Space complexity: $$O(1)$$ — Sorting is performed in-place (excluding auxiliary sorting stack space which is $$O(\log N)$$ depending on the standard library implementation).

# Code
```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        for(int i =0;i<n-2;i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];
            if(a<(b+c)) return a+b+c;
        }
        return 0;
    }
};
```

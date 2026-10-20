# [2971. Find Polygon With the Largest Perimeter](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`, `prefix-sum`, `polygons`

---

## Problem Description
You are given an array of **positive** integers `nums` of length `n`.

A **polygon** is a closed plane figure that has at least `3` sides. The **longest side** of a polygon is **smaller** than the sum of its other sides.

Conversely, if you have `k` (`k >= 3`) **positive** real numbers `a1`, `a2`, `a3`, ..., `ak` where `a1 <= a2 <= a3 <= ... <= ak` **and** `a1 + a2 + a3 + ... + ak-1 > ak`, then there **always** exists a polygon with `k` sides whose lengths are `a1`, `a2`, `a3`, ..., `ak`.

The **perimeter** of a polygon is the sum of lengths of its sides.

Return *the **largest** possible **perimeter** of a **polygon** whose sides can be formed from* `nums`, *or* `-1` *if it is not possible to create a polygon*.

**Example 1:**

```
Input: nums = [5,5,5]
Output: 15
Explanation: The only possible polygon that can be made from nums has 3 sides: 5, 5, and 5. The perimeter is 5 + 5 + 5 = 15.
```

**Example 2:**

```
Input: nums = [1,12,1,2,5,50,3]
Output: 12
Explanation: The polygon with the largest perimeter which can be made from nums has 5 sides: 1, 1, 2, 3, and 5. The perimeter is 1 + 1 + 2 + 3 + 5 = 12.
We cannot have a polygon with either 12 or 50 as the longest side because it is not possible to include 2 or more smaller sides that have a greater sum than either of them.
It can be shown that the largest possible perimeter is 12.
```

**Example 3:**

```
Input: nums = [5,5,50]
Output: -1
Explanation: There is no possible way to form a polygon from nums, as a polygon has at least 3 sides and 50 > 5 + 5.
```

**Constraints:**

* `3 <= n <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
To form a polygon with $k$ sides, the longest side must be strictly less than the sum of all other sides. By sorting the array in descending order, we can greedily check if the current largest element can serve as the longest side of a polygon formed by all preceding elements.

# Approach
1. Calculate the total sum of all elements in `nums` and store it in `ans`.
2. Sort `nums` in descending order. This allows us to treat the current element `nums[i]` as the potential longest side.
3. Iterate through the sorted array. For each `nums[i]`, the sum of all other sides is `temp = ans - nums[i]`.
4. If `nums[i] < temp`, the condition for a polygon is satisfied. Since we are iterating from the largest possible values, the first valid configuration we encounter provides the maximum possible perimeter.
5. If the condition is not met, subtract `nums[i]` from `ans` and continue to the next element.
6. If the loop completes without finding a valid polygon, return -1.

### Visual Trace (Example 2: [1, 12, 1, 2, 5, 50, 3])
Sorted: [50, 12, 5, 3, 2, 1, 1] | Initial Sum: 74

| Iteration | `nums[i]` | `temp` (Sum - `nums[i]`) | Condition (`nums[i] < temp`) | Action |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 50 | 24 | 50 < 24 (False) | `ans` = 24 |
| 1 | 12 | 12 | 12 < 12 (False) | `ans` = 12 |
| 2 | 5 | 7 | 5 < 7 (True) | Return 12 |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step. The subsequent linear scan takes $$O(N)$$.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation).

# Code
```cpp
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int num:nums) ans+=num;
        sort(nums.rbegin(),nums.rend());
        for(int i = 0;i<n;i++){
            long long temp = ans - nums[i];
            if(nums[i] < temp ) return ans;
            else ans -= nums[i];
        }
        return -1;
    }
};
```

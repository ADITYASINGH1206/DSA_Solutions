# [3861. Minimum Capacity Box](https://leetcode.com/problems/minimum-capacity-box/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
You are given an integer array `capacity`, where `capacity[i]` represents the capacity of the `ith` box, and an integer `itemSize` representing the size of an item.

The `ith` box can store the item if `capacity[i] >= itemSize`.

Return an integer denoting the index of the box with the **minimum** capacity that can store the item. If multiple such boxes exist, return the **smallest index**.

If no box can store the item, return -1.

**Example 1:**

**Input:** capacity = [1,5,3,7], itemSize = 3

**Output:** 2

**Explanation:**

The box at index 2 has a capacity of 3, which is the minimum capacity that can store the item. Thus, the answer is 2.

**Example 2:**

**Input:** capacity = [3,5,4,3], itemSize = 2

**Output:** 0

**Explanation:**

The minimum capacity that can store the item is 3, and it appears at indices 0 and 3. Thus, the answer is 0.

**Example 3:**

**Input:** capacity = [4], itemSize = 5

**Output:** -1

**Explanation:**

No box has enough capacity to store the item, so the answer is -1.

**Constraints:**

* `1 <= capacity.length <= 100`
* `1 <= capacity[i] <= 100`
* `1 <= itemSize <= 100`

---

## Solution & Editorial
# Intuition
To find the box with the minimum capacity that can accommodate the `itemSize`, we need to iterate through the array and track the smallest capacity encountered so far that satisfies the condition `capacity[i] >= itemSize`. Since we need the smallest index in case of ties, we only update our result when we find a capacity strictly smaller than the current minimum.

# Approach
1. Initialize `ans` to -1 (to handle the case where no box is suitable) and `min_capacity` to `INT_MAX`.
2. Iterate through the `capacity` array using index `i`.
3. For each box, check if `capacity[i] >= itemSize`.
4. If true, compare `capacity[i]` with `min_capacity`. If `capacity[i] < min_capacity`, update `min_capacity = capacity[i]` and `ans = i`.
5. Because we only update `ans` when `capacity[i]` is strictly less than `min_capacity`, the smallest index is naturally preserved for duplicate minimum values.

### Visual Trace (Example 2: capacity = [3, 5, 4, 3], itemSize = 2)
| Index | Capacity | Condition (>= 2) | Min Capacity | Ans |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 3 | True | 3 | 0 |
| 1 | 5 | True | 3 | 0 |
| 2 | 4 | True | 3 | 0 |
| 3 | 3 | True | 3 | 0 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the `capacity` array, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;
        int min_capacity = INT_MAX;
        
        for (int i = 0; i < capacity.size(); ++i) {
            if (capacity[i] >= itemSize) {
                if (capacity[i] < min_capacity) {
                    min_capacity = capacity[i];
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};
```

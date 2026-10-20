# [3551. Minimum Swaps to Sort by Digit Sum](https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sorting`

---

## Problem Description
You are given an array `nums` of **distinct** positive integers. You need to sort the array in **increasing** order based on the sum of the digits of each number. If two numbers have the same digit sum, the **smaller** number appears first in the sorted order.

Return the **minimum** number of swaps required to rearrange `nums` into this sorted order.

A **swap** is defined as exchanging the values at two distinct positions in the array.

**Example 1:**

**Input:** nums = [37,100]

**Output:** 1

**Explanation:**

* Compute the digit sum for each integer: `[3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]`
* Sort the integers based on digit sum: `[100, 37]`. Swap `37` with `100` to obtain the sorted order.
* Thus, the minimum number of swaps required to rearrange `nums` is 1.

**Example 2:**

**Input:** nums = [22,14,33,7]

**Output:** 0

**Explanation:**

* Compute the digit sum for each integer: `[2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]`
* Sort the integers based on digit sum: `[22, 14, 33, 7]`. The array is already sorted.
* Thus, the minimum number of swaps required to rearrange `nums` is 0.

**Example 3:**

**Input:** nums = [18,43,34,16]

**Output:** 2

**Explanation:**

* Compute the digit sum for each integer: `[1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]`
* Sort the integers based on digit sum: `[16, 34, 43, 18]`. Swap `18` with `16`, and swap `43` with `34` to obtain the sorted order.
* Thus, the minimum number of swaps required to rearrange `nums` is 2.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`
* `nums` consists of **distinct** positive integers.

---

## Solution & Editorial
# Intuition
To find the minimum number of swaps required to sort an array, we can model the array as a permutation graph. Each element's current position and its target sorted position define a directed edge. The minimum number of swaps to sort an array is equivalent to the sum of `(cycle_length - 1)` for all disjoint cycles in this permutation.

# Approach
1. **Digit Sum Calculation**: Create a helper structure `a` storing `{digit_sum, value, original_index}` for each element in `nums`.
2. **Sorting**: Sort `a` based on the primary key (digit sum) and secondary key (value) to determine the target configuration.
3. **Cycle Decomposition**: Use a boolean array `vis` to track visited indices. Iterate through the array; if an element is not visited and not in its correct position, traverse the cycle by following the `original_index` pointers.
4. **Counting Swaps**: For each cycle of length `len`, add `len - 1` to the total swap count.

### Visual Trace (Example 3: [18, 43, 34, 16])
- Initial: `[(18, 9, 0), (43, 7, 1), (34, 7, 2), (16, 7, 3)]`
- Sorted: `[(16, 7, 3), (34, 7, 2), (43, 7, 1), (18, 9, 0)]`
- Cycles:
  - Index 0 -> 3 -> 0 (Length 2, Swaps: 1)
  - Index 1 -> 2 -> 1 (Length 2, Swaps: 1)
- Total Swaps: 1 + 1 = 2

# Complexity
- Time complexity: $$O(N \log N)$$ due to sorting the array of size $$N$$. The cycle decomposition traversal visits each element exactly once, taking $$O(N)$$.
- Space complexity: $$O(N)$$ to store the auxiliary array of structures and the visited boolean array.

# Code
```cpp
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> a(n);
        for (int i = 0; i < n; i++) {
            int s = 0, x = nums[i];
            while (x > 0) {
                s += x % 10;
                x /= 10;
            }
            a[i] = {s, nums[i], i};
        }
        sort(a.begin(), a.end());

        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i][2] == i) continue;
            int j = i, len = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = a[j][2];
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};
```

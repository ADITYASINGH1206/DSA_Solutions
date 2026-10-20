# [3942. Minimum Operations to Sort a Permutation](https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/)
**Difficulty:** `Medium` | **Tags:** `array`

---

## Problem Description
You are given an integer array `nums` of length `n`, where `nums` is a permutation of the integers from 0 to `n - 1`.

You may perform **only** the following operations:

* **Reverse** the entire array.
* **Rotate Left by One**: Move the first element to the end of the array, and rest elements to left by one position.

Return an integer denoting the **minimum** number of operations required to sort the array in **increasing** order. If it is **not possible** to sort the array using only the given operations, return -1.

**Example 1:**

**Input:** nums = [0,2,1]

**Output:** 2

**Explanation:**

* Rotate Left by one: `[2, 1, 0]`
* Reverse the array: `[0, 1, 2]`

The array becomes sorted in 2 operations, which is minimal

**Example 2:**

**Input:** nums = [1,0,2]

**Output:** 2

**Explanation:**

* Reverse the array: `[2, 0, 1]`
* Rotate Left by one: `[0, 1, 2]`

The array becomes sorted in 2 operations, which is minimal.

**Example 3:**

**Input:** nums = [2,0,1,3]

**Output:** -1

**Explanation:**

It is impossible to reach `[2, 0, 1, 3]`. Thus, the answer is -1.

**Constraints:**

* `1 <= n == nums.length <= 105`
* `0 <= nums[i] <= n - 1`
* `nums` is a permutation of integers from 0 to `n - 1`.

---

## Solution & Editorial
# Intuition
The problem asks for the minimum operations to sort a permutation using only global rotations and a full array reversal. Since the target state is a sorted sequence `[0, 1, ..., n-1]`, we observe that any valid sequence reachable via these operations must be a cyclic shift of either the sorted sequence or its reverse. We identify the position of `0` to determine the current cyclic offset and verify if the remaining elements follow the required ascending or descending pattern.

# Approach
1. Locate the index `idx` of the element `0` in the input array `nums`.
2. Check if the array is a cyclic shift of the sorted sequence `[0, 1, ..., n-1]` (ascending) or the reversed sequence `[0, n-1, ..., 1]` (descending) by iterating through the array starting from `idx` using modulo arithmetic.
3. If neither pattern matches, return `-1`.
4. If it matches, calculate the cost based on the operations:
   - To reach the sorted state from an ascending cyclic shift, we can rotate left `idx` times or reverse then rotate.
   - To reach the sorted state from a descending cyclic shift, we perform a reverse and then rotate.
5. Return the minimum of the possible operation counts.

### Visual Trace (Example 1: [0, 2, 1])
- `n = 3`, `idx = 0` (where `nums[0] == 0`).
- `asc` check: `nums[(0+1)%3] == 2` (expected 1), `nums[(0+2)%3] == 1` (expected 2). `asc` is false.
- `desc` check: `nums[(0+1)%3] == 2` (expected 2), `nums[(0+2)%3] == 1` (expected 1). `desc` is true.
- Result: `min(3-0, 0+2) = 2`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the array, as we perform a single pass to find the index and a single pass to verify the cyclic pattern.
- Space complexity: $$O(1)$$ as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
    
        int idx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }
        
        bool asc = true;
        bool desc = true;
        
        for (int i = 1; i < n; i++) {
            if (nums[(idx + i) % n] != i) {
                asc = false;
            }
            if (nums[(idx + i) % n] != n - i) {
                desc = false;
            }
        }
        
        if (!asc && !desc) {
            return -1;
        }

        if (asc && desc) {
            return min({idx, n - idx + 2, n - idx, idx + 2});
        } else if (asc) {
            return min(idx, n - idx + 2);
        } else {
            return min(n - idx, idx + 2);
        }
    }
};
```

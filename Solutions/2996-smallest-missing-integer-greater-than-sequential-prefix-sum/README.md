# [2996. Smallest Missing Integer Greater Than Sequential Prefix Sum](https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`

---

## Problem Description
**Note:** The updated title is **"Smallest Missing Integer Greater Than or Equal to Sequential Prefix Sum".**

You are given a **0-indexed** array of integers `nums`.

A prefix `nums[0..i]` is **sequential** if, for all `1 <= j <= i`, `nums[j] = nums[j - 1] + 1`. In particular, the prefix consisting only of `nums[0]` is **sequential**.

Return *the **smallest** integer* `x` *missing from* `nums` *such that* `x` *is greater than or equal to the sum of the **longest** sequential prefix.*

**Example 1:**

```
Input: nums = [1,2,3,2,5]
Output: 6
Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
```

**Example 2:**

```
Input: nums = [3,4,5,1,12,14,13]
Output: 15
Explanation: The longest sequential prefix of nums is [3,4,5] with a sum of 12. 12, 13, and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
```

**Constraints:**

* `1 <= nums.length <= 50`
* `1 <= nums[i] <= 50`

---

## Solution & Editorial
# Intuition
The problem asks for the smallest missing integer that is at least as large as the sum of the longest sequential prefix. Since a sequential prefix must start from the very first element and follow the rule $nums[j] = nums[j-1] + 1$, we can determine this sum in a single linear pass. By storing all elements of the array in a hash set, we can efficiently find the first integer starting from this sum that does not exist in the array.

# Approach
1.  **Store Elements**: Insert all elements of the input array `A` into an `unordered_set` called `seen`. This allows for $O(1)$ average-time lookups to check if a specific integer exists in the array.
2.  **Calculate Prefix Sum**: Initialize `sum` with the first element `A[0]`. Iterate through the array starting from index 1. If the current element `A[i]` is exactly one greater than the previous element `A[i-1]`, add `A[i]` to `sum`. If the sequence breaks, stop the iteration immediately.
3.  **Find Missing Integer**: Starting from the calculated `sum`, check if it exists in the `seen` set. If it does, increment `sum` by 1 and repeat the check. The first value of `sum` that is not found in the set is the smallest missing integer greater than or equal to the sequential prefix sum.

### Visual Trace (Example 2)
Input: `nums = [3, 4, 5, 1, 12, 14, 13]`

| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Build Set | `seen = {1, 3, 4, 5, 12, 13, 14}` |
| 2 | Start Prefix | `sum = 3` (from `nums[0]`) |
| 3 | `nums[1]=4` | `4 == 3+1`? Yes. `sum = 3 + 4 = 7` |
| 4 | `nums[2]=5` | `5 == 4+1`? Yes. `sum = 7 + 5 = 12` |
| 5 | `nums[3]=1` | `1 == 5+1`? No. **Break Loop.** |
| 6 | Check `sum=12` | In `seen`? Yes. `sum = 13` |
| 7 | Check `sum=13` | In `seen`? Yes. `sum = 14` |
| 8 | Check `sum=14` | In `seen`? Yes. `sum = 15` |
| 9 | Check `sum=15` | In `seen`? No. **Return 15.** |

# Complexity
- Time complexity: $$O(N)$$
  - Building the `unordered_set` takes $$O(N)$$ time.
  - Calculating the sequential prefix sum takes at most $$O(N)$$ time.
  - The `while` loop to find the missing integer runs at most $$O(N)$$ times because there are only $N$ elements in the set that could cause an increment.
- Space complexity: $$O(N)$$
  - We use an `unordered_set` to store all $N$ elements of the input array for fast lookup.

# Code
```cpp
class Solution {
public:
    int missingInteger(vector<int>& A) {
        int n = A.size();
        unordered_set<int> seen(A.begin(), A.end());
        int sum = A[0];

        for (int i = 1; i < n; i++) {
            if (A[i] == A[i - 1] + 1) sum += A[i];
            else break;
        }

        while (seen.count(sum))
            sum++;

        return sum;
    }
};
```

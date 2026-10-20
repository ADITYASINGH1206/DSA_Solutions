# [414. Third Maximum Number](https://leetcode.com/problems/third-maximum-number/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
You are given an integer array `nums`.

Return the **third distinct maximum** number in this array. If the third **maximum** does not exist, return the **maximum** number.

**Example 1:**

```
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
```

**Example 2:**

```
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
```

**Example 3:**

```
Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
```

**Constraints:**

* `1 <= nums.length <= 104`
* `-231 <= nums[i] <= 231 - 1`

**Follow up:** Can you find an `O(n)` solution?

---

## Solution & Editorial
# Intuition
To find the third distinct maximum number in a single pass without sorting, we can maintain three distinct variables (`m1`, `m2`, and `m3`) representing the largest, second largest, and third largest numbers encountered so far. Since the input numbers can span the full range of 32-bit integers, we initialize these tracking variables to `LONG_MIN` to properly handle negative values.

# Approach
1. Initialize three `long` variables: `m1 = LONG_MIN`, `m2 = LONG_MIN`, and `m3 = LONG_MIN` to track the top three distinct maximums.
2. Iterate through each `num` in the `nums` vector.
3. If `num` is already equal to `m1`, `m2`, or `m3`, skip it to ensure all tracked maximums are strictly distinct.
4. If `num > m1`, shift existing maximums down (`m3 = m2`, `m2 = m1`) and update `m1 = num`.
5. Else if `num > m2`, shift `m2` down (`m3 = m2`) and update `m2 = num`.
6. Else if `num > m3`, update `m3 = num`.
7. After the loop completes, check if `m3` was updated (i.e., `m3 != LONG_MIN`). If so, return `m3`. Otherwise, return `m1` since a distinct third maximum does not exist.

### Visual Trace Walkthrough (Example 1: `nums = [3, 2, 1]`)

| Iteration | `num` | `m1` | `m2` | `m3` | Action Taken |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Initial | - | `LONG_MIN` | `LONG_MIN` | `LONG_MIN` | Start |
| 1 | `3` | `3` | `LONG_MIN` | `LONG_MIN` | `3 > m1` |
| 2 | `2` | `3` | `2` | `LONG_MIN` | `2 > m2` |
| 3 | `1` | `3` | `2` | `1` | `1 > m3` |

Result: `m3` is `1`, which is returned.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in `nums`. We traverse the array exactly once.
- Space complexity: $$O(1)$$ auxiliary space, as we only use a constant number of variables (`m1`, `m2`, `m3`) regardless of input size.

# Code
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
        for (int num : nums) {
            if (num == m1 || num == m2 || num == m3) continue;
            if (num > m1) {
                m3 = m2;
                m2 = m1;
                m1 = num;
            } else if (num > m2) {
                m3 = m2;
                m2 = num;
            } else if (num > m3) {
                m3 = num;
            }
        }
        return (int) (m3 != LONG_MIN ? m3 : m1);
    }
};
```

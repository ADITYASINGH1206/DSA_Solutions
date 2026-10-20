# [3761. Minimum Absolute Distance Between Mirror Pairs](https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `math`

---

## Problem Description
You are given an integer array `nums`.

A **mirror pair** is a pair of indices `(i, j)` such that:

* `0 <= i < j < nums.length`, and
* `reverse(nums[i]) == nums[j]`, where `reverse(x)` denotes the integer formed by reversing the digits of `x`. Leading zeros are omitted after reversing, for example `reverse(120) = 21`.

Return the **minimum** absolute distance between the indices of any mirror pair. The absolute distance between indices `i` and `j` is `abs(i - j)`.

If no mirror pair exists, return `-1`.

**Example 1:**

**Input:** nums = [12,21,45,33,54]

**Output:** 1

**Explanation:**

The mirror pairs are:

* (0, 1) since `reverse(nums[0]) = reverse(12) = 21 = nums[1]`, giving an absolute distance `abs(0 - 1) = 1`.
* (2, 4) since `reverse(nums[2]) = reverse(45) = 54 = nums[4]`, giving an absolute distance `abs(2 - 4) = 2`.

The minimum absolute distance among all pairs is 1.

**Example 2:**

**Input:** nums = [120,21]

**Output:** 1

**Explanation:**

There is only one mirror pair (0, 1) since `reverse(nums[0]) = reverse(120) = 21 = nums[1]`.

The minimum absolute distance is 1.

**Example 3:**

**Input:** nums = [21,120]

**Output:** -1

**Explanation:**

There are no mirror pairs in the array.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`​​​​​​​

---

## Solution & Editorial
# Intuition
To find the minimum distance between mirror pairs, we need to efficiently track the most recent index of each reversed number encountered so far. Since a mirror pair $(i, j)$ satisfies $reverse(nums[i]) == nums[j]$, we can iterate through the array and store the index of each number's reverse in a hash map. When we encounter a number $nums[j]$, we check if its reverse has been previously stored as a potential $nums[i]$.

# Approach
1. Initialize a hash map `pos` to store the most recent index of a reversed value.
2. Iterate through the array `nums` using index `i`.
3. At each step, check if `nums[i]` exists in `pos`. If it does, it means we found a mirror pair $(pos[nums[i]], i)$. Update the minimum distance `ans = min(ans, i - pos[nums[i]])`.
4. Calculate `rev = reverse(nums[i])` and update `pos[rev] = i` to ensure we always track the index that minimizes the distance for future occurrences.
5. If `ans` remains greater than the array size, return -1.

### Visual Trace (Example 1: [12, 21, 45, 33, 54])
| i | nums[i] | reverse | pos map (after update) | ans |
|---|---|---|---|---|
| 0 | 12 | 21 | {21: 0} | inf |
| 1 | 21 | 12 | {21: 0, 12: 1} | 1 |
| 2 | 45 | 54 | {21: 0, 12: 1, 54: 2} | 1 |
| 3 | 33 | 33 | {21: 0, 12: 1, 54: 2, 33: 3} | 1 |
| 4 | 54 | 45 | {21: 0, 12: 1, 54: 2, 33: 3, 45: 4} | 1 |

# Complexity
- Time complexity: $$O(N \cdot \log_{10}(\max(nums)))$$, where $N$ is the length of the array. Each number is processed once, and the reverse operation takes logarithmic time relative to the value of the number.
- Space complexity: $$O(N)$$, as we store at most $N$ entries in the hash map.

# Code
```cpp
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        unordered_map<int, int> pos;
        auto reverse = [](int x) {
            int y = 0;
            for (; x > 0; x /= 10) {
                y = y * 10 + x % 10;
            }
            return y;
        };
        for (int i = 0; i < n; ++i) {
            if (pos.contains(nums[i])) {
                ans = min(ans, i - pos[nums[i]]);
            }
            pos[reverse(nums[i])] = i;
        }
        return ans > n ? -1 : ans;
    }
};
```

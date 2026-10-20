# [1899. Merge Triplets to Form Target Triplet](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`

---

## Problem Description
A **triplet** is an array of three integers. You are given a 2D integer array `triplets`, where `triplets[i] = [ai, bi, ci]` describes the `ith` **triplet**. You are also given an integer array `target = [x, y, z]` that describes the **triplet** you want to obtain.

To obtain `target`, you may apply the following operation on `triplets` **any number** of times (possibly **zero**):

* Choose two indices (**0-indexed**) `i` and `j` (`i != j`) and **update** `triplets[j]` to become `[max(ai, aj), max(bi, bj), max(ci, cj)]`.
  + For example, if `triplets[i] = [2, 5, 3]` and `triplets[j] = [1, 7, 5]`, `triplets[j]` will be updated to `[max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5]`.

Return `true` *if it is possible to obtain the* `target` ***triplet*** `[x, y, z]` *as an **element** of* `triplets`*, or* `false` *otherwise*.

**Example 1:**

```
Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update the last triplet to be [max(2,1), max(5,7), max(3,5)] = [2,7,5]. triplets = [[2,5,3],[1,8,4],[2,7,5]]
The target triplet [2,7,5] is now an element of triplets.
```

**Example 2:**

```
Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
Output: false
Explanation: It is impossible to have [3,2,5] as an element because there is no 2 in any of the triplets.
```

**Example 3:**

```
Input: triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and third triplets [[2,5,3],[2,3,4],[1,2,5],[5,2,3]]. Update the third triplet to be [max(2,1), max(5,2), max(3,5)] = [2,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,2,3]].
- Choose the third and fourth triplets [[2,5,3],[2,3,4],[2,5,5],[5,2,3]]. Update the fourth triplet to be [max(2,5), max(5,2), max(5,3)] = [5,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,5,5]].
The target triplet [5,5,5] is now an element of triplets.
```

**Constraints:**

* `1 <= triplets.length <= 105`
* `triplets[i].length == target.length == 3`
* `1 <= ai, bi, ci, x, y, z <= 1000`

---

## Solution & Editorial
# Intuition
The core observation is that we can only merge triplets that do not contain any values exceeding the corresponding elements in the `target` triplet. If a triplet has any element greater than the target, including it in a merge operation would make it impossible to ever reach the target, as the `max` operation is non-decreasing.

# Approach
1. Initialize three boolean flags `xt`, `yt`, and `zt` to `false`, representing whether we have found a triplet that contributes the exact target value for the first, second, and third positions, respectively.
2. Iterate through each `triplet` in the input array.
3. Filter out any triplet that contains a value larger than the target (i.e., `triplet[0] > x || triplet[1] > y || triplet[2] > z`).
4. For valid triplets, update the flags: if `triplet[0] == x`, set `xt = true`; if `triplet[1] == y`, set `yt = true`; if `triplet[2] == z`, set `zt = true`.
5. After processing all triplets, the result is `true` if all three flags are `true`, otherwise `false`.

### Visual Trace (Example 1: target = [2, 7, 5])
| Triplet | Valid? | xt | yt | zt |
| :--- | :--- | :--- | :--- | :--- |
| [2, 5, 3] | Yes | T | F | F |
| [1, 8, 4] | No (8 > 7) | T | F | F |
| [1, 7, 5] | Yes | T | T | T |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of triplets. We perform a single pass through the input array.
- Space complexity: $$O(1)$$, as we only use three boolean variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        bool xt = false, yt = false, zt = false;

        for (auto &triplet : triplets) {
            if (triplet[0] <= x && triplet[1] <= y && triplet[2] <= z) {
                if (triplet[0] == x) xt = true;
                if (triplet[1] == y) yt = true;
                if (triplet[2] == z) zt = true;
            }
        }

        return xt && yt && zt;
    }
};
```

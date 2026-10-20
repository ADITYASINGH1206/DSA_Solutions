# [3819. Rotate Non Negative Elements](https://leetcode.com/problems/rotate-non-negative-elements/)
**Difficulty:** `Medium` | **Tags:** `array`, `simulation`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

Rotate only the **non-negative** elements of the array to the **left** by `k` positions, in a cyclic manner.

All **negative** elements must stay in their original positions and must not move.

After rotation, place the **non-negative** elements back into the array in the new order, filling only the positions that originally contained **non-negative** values and **skipping all negative** positions.

Return the resulting array.

**Example 1:**

**Input:** nums = [1,-2,3,-4], k = 3

**Output:** [3,-2,1,-4]

**Explanation:**​​​​​​​

* The non-negative elements, in order, are `[1, 3]`.
* Left rotation with `k = 3` results in:
  + `[1, 3] -> [3, 1] -> [1, 3] -> [3, 1]`
* Placing them back into the non-negative indices results in `[3, -2, 1, -4]`.

**Example 2:**

**Input:** nums = [-3,-2,7], k = 1

**Output:** [-3,-2,7]

**Explanation:**

* The non-negative elements, in order, are `[7]`.
* Left rotation with `k = 1` results in `[7]`.
* Placing them back into the non-negative indices results in `[-3, -2, 7]`.

**Example 3:**

**Input:** nums = [5,4,-9,6], k = 2

**Output:** [6,5,-9,4]

**Explanation:**

* The non-negative elements, in order, are `[5, 4, 6]`.
* Left rotation with `k = 2` results in `[6, 5, 4]`.
* Placing them back into the non-negative indices results in `[6, 5, -9, 4]`.

**Constraints:**

* `1 <= nums.length <= 105`
* `-105 <= nums[i] <= 105`
* `0 <= k <= 105`

---

## Solution & Editorial
# Intuition
The problem requires rotating only non-negative elements while keeping negative elements fixed. Since the relative order of non-negative elements must be preserved during rotation, we can decouple the non-negative elements from the array, perform the rotation independently, and then map them back to their original indices.

# Approach
1. **Extraction**: Iterate through the input `nums` and collect all non-negative elements into a temporary vector `temp`.
2. **Rotation**: Calculate the effective rotation index `k %= m`, where `m` is the size of `temp`. Use `std::rotate` to perform a left cyclic shift on `temp` by `k` positions.
3. **Reinsertion**: Iterate through the original `nums` array again. Whenever a non-negative element is encountered, replace it with the next element from the rotated `temp` vector.

### Visual Trace (Example 1: nums = [1, -2, 3, -4], k = 3)
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Extract non-negatives | `temp = [1, 3]` |
| 2 | Calculate `k` | `k = 3 % 2 = 1` |
| 3 | Rotate `temp` | `temp = [3, 1]` |
| 4 | Reinsert into `nums` | `nums[0]=3, nums[2]=1` |
| Result | Final Array | `[3, -2, 1, -4]` |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. We perform one pass to extract elements, one pass to rotate (which is linear), and one pass to reinsert.
- Space complexity: $$O(N)$$ to store the extracted non-negative elements in the `temp` vector.

# Code
```cpp
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;
        for (int x : nums) {
            if (x >= 0) temp.push_back(x);
        }
        
        int m = temp.size();
        if (m == 0) return nums;
    
        k %= m;
        rotate(temp.begin(), temp.begin() +k, temp.end());
        int temp_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                nums[i] = temp[temp_idx++];
            }
        }
        
        return nums;
    }
};
```

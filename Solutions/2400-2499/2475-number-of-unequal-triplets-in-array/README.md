# [2475. Number of Unequal Triplets in Array](https://leetcode.com/problems/number-of-unequal-triplets-in-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`

---

## Problem Description
You are given a **0-indexed** array of positive integers `nums`. Find the number of triplets `(i, j, k)` that meet the following conditions:

* `0 <= i < j < k < nums.length`
* `nums[i]`, `nums[j]`, and `nums[k]` are **pairwise distinct**.
  + In other words, `nums[i] != nums[j]`, `nums[i] != nums[k]`, and `nums[j] != nums[k]`.

Return *the number of triplets that meet the conditions.*

**Example 1:**

```
Input: nums = [4,4,2,4,3]
Output: 3
Explanation: The following triplets meet the conditions:
- (0, 2, 4) because 4 != 2 != 3
- (1, 2, 4) because 4 != 2 != 3
- (2, 3, 4) because 2 != 4 != 3
Since there are 3 triplets, we return 3.
Note that (2, 0, 4) is not a valid triplet because 2 > 0.
```

**Example 2:**

```
Input: nums = [1,1,1,1,1]
Output: 0
Explanation: No triplets meet the conditions so we return 0.
```

**Constraints:**

* `3 <= nums.length <= 100`
* `1 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
To form a valid triplet $(i, j, k)$ where $nums[i] \neq nums[j] \neq nums[k]$, we need to select three elements with distinct values. Instead of checking all $O(N^3)$ combinations, we can group elements by their frequency. For any specific value $v$ with frequency $f_v$, if we treat it as the "middle" element of a triplet, the number of valid triplets is the product of the number of elements to its left (with different values), the frequency $f_v$, and the number of elements to its right (with different values).

# Approach
1. Use an `unordered_map<int, int> mp` to store the frequency of each number in `nums`.
2. Iterate through the map. Maintain a `left` variable representing the count of elements processed so far (which are guaranteed to have values different from the current map entry).
3. For each entry with frequency `curr`:
   - Calculate `right` as `total_elements - left - curr`.
   - Add `left * curr * right` to the total `ans`.
   - Update `left` by adding `curr`.

### Visual Trace (nums = [4, 4, 2, 4, 3])
- Frequencies: {4: 3, 2: 1, 3: 1}
- Total $N = 5$

| Iteration | Value | `curr` | `left` | `right` | `ans` (add) | New `left` |
|-----------|-------|--------|--------|---------|-------------|------------|
| 1         | 4     | 3      | 0      | 2       | 0           | 3          |
| 2         | 2     | 1      | 3      | 1       | 3           | 4          |
| 3         | 3     | 1      | 4      | 0       | 0           | 5          |

Final `ans` = 3.

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the length of the array. We iterate through the array once to build the frequency map and then iterate through the distinct elements in the map.
- Space complexity: $$O(N)$$ to store the frequency map in the worst case where all elements are distinct.

# Code
```cpp
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        int n = nums.size();
        int left = 0, curr, right;
        for (auto& it : mp) {
            curr = it.second;
            right = n - curr - left;
            ans += (left * curr * right);
            left += it.second;
        }
        return ans;
    }
};
```

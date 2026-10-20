# [3866. First Unique Even Element](https://leetcode.com/problems/first-unique-even-element/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
You are given an integer array `nums`.

Return an integer denoting the first **even** integer (earliest by array index) that appears **exactly** once in `nums`. If no such integer exists, return -1.

An integer `x` is considered **even** if it is divisible by 2.

**Example 1:**

**Input:** nums = [3,4,2,5,4,6]

**Output:** 2

**Explanation:**

Both 2 and 6 are even and they appear exactly once. Since 2 occurs first in the array, the answer is 2.

**Example 2:**

**Input:** nums = [4,4]

**Output:** -1

**Explanation:**

No even integer appears exactly once, so return -1.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To identify the first unique even element, we need to track the frequency of every number in the array. Since we need the *first* occurrence by index, a two-pass approach is optimal: first count all occurrences, then iterate through the original array to check the conditions.

# Approach
1. Initialize an `unordered_map<int, int> freq` to store the count of each integer present in `nums`.
2. Iterate through the input vector `nums` once to populate `freq`.
3. Iterate through the original `nums` vector a second time. For each element `x`:
   - Check if `x` is even (`x % 2 == 0`).
   - Check if its frequency in `freq` is exactly 1.
   - Return the first `x` that satisfies both conditions.
4. If the loop completes without finding such an element, return -1.

### Visual Trace (Example 1: [3, 4, 2, 5, 4, 6])
| Step | Action | State of `freq` |
| :--- | :--- | :--- |
| 1 | Count frequencies | {3:1, 4:2, 2:1, 5:1, 6:1} |
| 2 | Check 3 | Odd, skip |
| 3 | Check 4 | Even, freq=2, skip |
| 4 | Check 2 | Even, freq=1, **Return 2** |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform one pass to build the hash map and one pass to verify the conditions.
- Space complexity: $$O(K)$$, where $$K$$ is the number of unique elements in the array, stored in the hash map. In the worst case, $$K = N$$.

# Code
```cpp
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int x : nums) {
            if(x % 2 == 0 && freq[x] == 1) {
                return x;
            }
        }
        return -1;
    }
};
```

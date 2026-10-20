# [3994. Minimum Adjacent Swaps to Partition Array](https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`

---

## Problem Description
You are given an integer array `nums` and two integers `a` and `b` such that `a < b`.

An array is called **good** if it can be split into three **contiguous** parts, in this order, such that:

* Every element in the first part is **less than** `a`.
* Every element in the second part is **in** the range `[a, b]` inclusive.
* Every element in the third part is **greater than** `b`.

Any of the three parts **may be** empty.

In one **adjacent swap**, you may swap two **neighboring** elements of `nums`.

Return the **minimum number** of adjacent swaps required to make `nums` good. Since the answer may be very large, return it **modulo** `109 + 7`.

**Example 1:**

**Input:** nums = [1,3,2,4,5,6], a = 3, b = 4

**Output:** 1

**Explanation:**

* Swap `nums[1]` and `nums[2]`. The array becomes `[1, 2, 3, 4, 5, 6]`.
* This array is good because it can be split into `[1, 2]`, `[3, 4]`, and `[5, 6]`.

**Example 2:**

**Input:** nums = [9,7,5,3], a = 4, b = 8

**Output:** 5

**Explanation:**

One sequence of optimal swaps is as follows:

* Swap `nums[2]` and `nums[3]`. The array becomes `[9, 7, 3, 5]`.
* Swap `nums[1]` and `nums[2]`. The array becomes `[9, 3, 7, 5]`.
* Swap `nums[0]` and `nums[1]`. The array becomes `[3, 9, 7, 5]`.
* Swap `nums[1]` and `nums[2]`. The array becomes `[3, 7, 9, 5]`.
* Swap `nums[2]` and `nums[3]`. The array becomes `[3, 7, 5, 9]`.
* This array is good because it can be split into `[3]`, `[7, 5]`, and `[9]`.

**Example 3:**

**Input:** nums = [3,7,5,9], a = 4, b = 8

**Output:** 0

**Explanation:**

The array is already good. No swaps are needed.

**Constraints:**

* `1 <= nums.length <= 105`
* `​​​​​​​1 <= nums[i] <= 109`
* `1 <= a < b <= 109​​​​​​​`

---

## Solution & Editorial
# Intuition
To make the array "good," we need to partition it into three contiguous segments: elements < `a`, elements in `[a, b]`, and elements > `b`. The minimum number of adjacent swaps required to reorder elements into a specific relative sequence is equivalent to the number of inversions needed to move elements to their target zones. Since we only care about the relative order of three categories, we can calculate the cost by counting how many elements of a "later" category appear before an element of an "earlier" category.

# Approach
1. **Categorize Elements**: Every element belongs to one of three groups: Group 1 (< `a`), Group 2 (`[a, b]`), or Group 3 (> `b`).
2. **Calculate Swaps for Group 1**: Iterate through the array. Maintain a counter `ga` for elements that are NOT in Group 1 (i.e., elements $\ge a$). Every time we encounter an element in Group 1, it must "jump over" all preceding elements that belong to Group 2 or Group 3. Thus, we add `ga` to our total `ans`.
3. **Calculate Swaps for Group 2**: Iterate through the array again. Ignore Group 1 elements. Maintain a counter `gb` for elements in Group 3 (> `b`). Every time we encounter an element in Group 2, it must "jump over" all preceding elements that belong to Group 3. Thus, we add `gb` to our total `ans`.

### Visual Trace (Example 2: `nums = [9, 7, 5, 3], a = 4, b = 8`)
- **Pass 1 (Group 1: < 4)**:
  - `9` (>=4): `ga=1`
  - `7` (>=4): `ga=2`
  - `5` (>=4): `ga=3`
  - `3` (<4): `ans += 3` (Total `ans=3`)
- **Pass 2 (Group 2: [4, 8])**:
  - `9` (>8): `gb=1`
  - `7` (in [4,8]): `ans += 1` (Total `ans=4`)
  - `5` (in [4,8]): `ans += 1` (Total `ans=5`)
  - `3` (<4): skip
- **Result**: `5`

# Complexity
- Time complexity: $$O(N)$$ — We perform two linear passes over the input array.
- Space complexity: $$O(1)$$ — We only use a few integer variables for counting and the result.

# Code
```cpp
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long MOD = 1e9 + 7;
        long long ans = 0;
        long long ga = 0; 
        for (int num : nums) {
            if (num < a) {
                ans = (ans + ga) % MOD;
            } else {
                ga++;
            }
        }
        long long gb = 0;
        for (int num : nums) {
            if (num < a) {
                continue; 
            } else if (num > b) {
                gb++;
            } else {
                ans = (ans + gb) % MOD;
            }
        }
        
        return ans;
    }
};
```

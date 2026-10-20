# [3868. Minimum Cost to Equalize Arrays Using Swaps](https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `greedy`, `counting`

---

## Problem Description
You are given two integer arrays `nums1` and `nums2` of size `n`.

You can perform the following two operations any number of times on these two arrays:

* **Swap within the same array**: Choose two indices `i` and `j`. Then, choose either to swap `nums1[i]` and `nums1[j]`, or `nums2[i]` and `nums2[j]`. This operation is **free of charge**.
* **Swap between two arrays**: Choose an index `i`. Then, swap `nums1[i]` and `nums2[i]`. This operation **incurs a cost of 1**.

Return an integer denoting the **minimum cost** to make `nums1` and `nums2` **identical**. If this is not possible, return -1.

**Example 1:**

**Input:** nums1 = [10,20], nums2 = [20,10]

**Output:** 0

**Explanation:**

* Swap `nums2[0] = 20` and `nums2[1] = 10`.
  + `nums2` becomes `[10, 20]`.
  + This operation is free of charge.
* `nums1` and `nums2` are now identical. The cost is 0.

**Example 2:**

**Input:** nums1 = [10,10], nums2 = [20,20]

**Output:** 1

**Explanation:**

* Swap `nums1[0] = 10` and `nums2[0] = 20`.
  + `nums1` becomes `[20, 10]`.
  + `nums2` becomes `[10, 20]`.
  + This operation costs 1.
* Swap `nums2[0] = 10` and `nums2[1] = 20`.
  + `nums2` becomes `[20, 10]`.
  + This operation is free of charge.
* `nums1` and `nums2` are now identical. The cost is 1.

**Example 3:**

**Input:** nums1 = [10,20], nums2 = [30,40]

**Output:** -1

**Explanation:**

It is impossible to make the two arrays identical. Therefore, the answer is -1.

**Constraints:**

* `2 <= n == nums1.length == nums2.length <= 8 * 104`
* `1 <= nums1[i], nums2[i] <= 8 * 104`

---

## Solution & Editorial
# Intuition
Since we can perform free swaps within the same array, the relative order of elements does not matter. The problem reduces to ensuring that for every unique value present in the combined multiset of `nums1` and `nums2`, the total count of that value is even, and we must distribute these values such that each array ends up with exactly half of the total count of each value.

# Approach
1. **Frequency Validation**: First, count the occurrences of every number across both arrays combined. If any number appears an odd number of times in total, it is impossible to split them equally, so return -1.
2. **Target Distribution**: For each unique value `v`, the total count `total = freq[v]` must be split equally between `nums1` and `nums2`. Thus, each array must contain exactly `target = total / 2` instances of `v`.
3. **Greedy Swap Calculation**: Iterate through the unique values. If `nums1` currently contains more than the `target` count of a specific value `v`, the excess `count1[v] - target` must be swapped with `nums2` at some index where `nums2` has a value that `nums1` needs. The total number of such swaps is simply the sum of all positive differences `count1[v] - target`.

### Visual Trace (Example 2: nums1=[10,10], nums2=[20,20])
- `freq`: {10: 2, 20: 2}
- `count1`: {10: 2, 20: 0}
- `target` for 10: 2/2 = 1. `count1[10]` (2) > 1. `swaps` += (2 - 1) = 1.
- `target` for 20: 2/2 = 1. `count1[20]` (0) < 1. No addition.
- Result: 1.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the size of the arrays. We iterate through the arrays once to populate hash maps and once through the unique elements in the maps.
- Space complexity: $$O(N)$$ to store the frequency counts in hash maps.

# Code
```cpp
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> count1;

        for (int i = 0; i < n; i++) {
            freq[nums1[i]]++;
            freq[nums2[i]]++;
            count1[nums1[i]]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second % 2 != 0) {
                return -1;
            }
        }

        int swaps = 0;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            int val = it->first;
            int total = it->second;
            int target = total / 2;

            if (count1[val] > target) {
                swaps += (count1[val] - target);
            }
        }

        return swaps;
    }
};
```

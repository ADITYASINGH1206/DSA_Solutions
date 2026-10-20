# [3940. Limit Occurrences in Sorted Array](https://leetcode.com/problems/limit-occurrences-in-sorted-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`

---

## Problem Description
You are given a **sorted** integer array `nums` and an integer `k`.

Return an array such that each **distinct** element appears **at most** `k` times, while preserving the relative order of the elements in `nums`.

Note: If a distinct element appears **at least** `k` times, then it must appear **exactly** `k` times in the resulting array.

**Example 1:**

**Input:** nums = [1,1,1,2,2,3], k = 2

**Output:** [1,1,2,2,3]

**Explanation:**

Each element can appear at most 2 times.

* The element 1 appears 3 times, so only 2 occurrences are kept.
* The element 2 appears 2 times, so both occurrences are kept.
* The element 3 appears 1 time, so it is kept.

Thus, the resulting array is `[1, 1, 2, 2, 3]`.

**Example 2:**

**Input:** nums = [1,2,3], k = 1

**Output:** [1,2,3]

**Explanation:**

All elements are distinct and already appear at most once, so the array remains unchanged.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* `nums` is sorted in non-decreasing order.
* `1 <= k <= nums.length`

**Follow-up:**

* Can you solve this in-place using O(1) extra space?
* Note that the space used for returning or resizing the result does not count toward the space complexity mentioned above, as some languages do not support in-place resizing.

---

## Solution & Editorial
# Intuition
Since the input array `nums` is sorted, we could use two pointers to count occurrences. However, a hash map provides a clean, readable way to track the frequency of each element as we iterate through the array, ensuring we only append an element to our result if its current count is less than `k`.

# Approach
1. Initialize an `unordered_map<int, int> counts` to store the frequency of each integer encountered.
2. Initialize an empty vector `ans` to store the result.
3. Iterate through each `num` in the input `nums`:
   - Check if `counts[num]` is strictly less than `k`.
   - If true, append `num` to `ans` and increment `counts[num]`.
   - If false, skip the element as it has already reached the allowed limit.
4. Return `ans`.

### Visual Trace (Example 1: nums = [1,1,1,2,2,3], k = 2)
| Iteration | num | counts[num] | Action | ans |
|-----------|-----|-------------|--------|-----|
| 1         | 1   | 0 < 2       | Add 1  | [1] |
| 2         | 1   | 1 < 2       | Add 1  | [1, 1] |
| 3         | 1   | 2 < 2       | Skip   | [1, 1] |
| 4         | 2   | 0 < 2       | Add 2  | [1, 1, 2] |
| 5         | 2   | 1 < 2       | Add 2  | [1, 1, 2, 2] |
| 6         | 3   | 0 < 2       | Add 3  | [1, 1, 2, 2, 3] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. We perform a single pass over the array, and hash map operations (insertion/lookup) are $$O(1)$$ on average.
- Space complexity: $$O(N)$$, as in the worst case (all elements are distinct), the hash map and the result vector will store up to $$N$$ elements.

# Code
```cpp
class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<int> ans;
        
        for (int num : nums) {
            if (counts[num] < k) {
                ans.push_back(num);
                counts[num]++;
            }
        }
        
        return ans;
    }
};
```

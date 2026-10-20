# [349. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `two-pointers`, `binary-search`, `sorting`

---

## Problem Description
Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must be **unique** and you may return the result in **any order**.

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires finding the unique common elements present in both `nums1` and `nums2`. Since uniqueness is required and order does not matter, a hash set is the ideal data structure to achieve $O(1)$ average time complexity lookups and automatic duplicate suppression.

# Approach
1. Initialize an unordered set `s` using all elements from `nums1` to eliminate duplicates and allow constant-time membership checks.
2. Create an empty vector `result` to store the intersection elements.
3. Iterate through each element `num` in `nums2`.
4. If `num` exists in the set `s`, append `num` to `result` and erase `num` from `s` to ensure each intersecting element is added only once.
5. Return the populated `result` vector.

### Visual Trace Walkthrough
Example: `nums1 = [1, 2, 2, 1]`, `nums2 = [2, 2]`

| Iteration | `num` (from `nums2`) | `s.count(num)` | Action | `s` after operation | `result` |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `2` | `true` | Insert `2`, Erase `2` from `s` | `{1}` | `[2]` |
| 2 | `2` | `false` | None (already erased) | `{1}` | `[2]` |

# Complexity
- Time complexity: $$O(N + M)$$ where $$N$$ is the size of `nums1` and $$M$$ is the size of `nums2`. Inserting elements of `nums1` into the hash set takes $$O(N)$$ time. Traversing `nums2` and performing set lookups and erasures takes $$O(M)$$ time.
- Space complexity: $$O(N)$$ to store the unique elements of `nums1` inside the unordered set `s` and the output vector space.

# Code
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> result;
        
        for (int num : nums2) {
            if (s.count(num)) {
                result.push_back(num);
                s.erase(num); 
            }
        }
        
        return result;
    }
};
```

# [2215. Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
Given two **0-indexed** integer arrays `nums1` and `nums2`, return *a list* `answer` *of size* `2` *where:*

* `answer[0]` *is a list of all **distinct** integers in* `nums1` *which are **not** present in* `nums2`*.*
* `answer[1]` *is a list of all **distinct** integers in* `nums2` *which are **not** present in* `nums1`.

**Note** that the integers in the lists may be returned in **any** order.

**Example 1:**

```
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].
```

**Example 2:**

```
Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 1000`
* `-1000 <= nums1[i], nums2[i] <= 1000`

---

## Solution & Editorial
# Intuition
To identify distinct elements present in one array but not the other, we need to efficiently handle duplicates and perform membership lookups. Using hash sets allows us to reduce both input arrays to their unique elements and perform constant-time lookups to check for existence.

# Approach
1. Initialize two `unordered_set<int>` objects, `s1` and `s2`, by inserting all elements from `nums1` and `nums2` respectively. This automatically handles duplicates and provides $O(1)$ average time complexity for lookups.
2. Iterate through each unique element `v` in `s1`. If `v` is not found in `s2` (using `s2.contains(v)`), add it to `ans[0]`.
3. Iterate through each unique element `v` in `s2`. If `v` is not found in `s1` (using `s1.contains(v)`), add it to `ans[1]`.
4. Return the resulting `ans` vector.

### Visual Trace (Example 1: nums1=[1,2,3], nums2=[2,4,6])
| Step | s1 | s2 | ans[0] | ans[1] |
| :--- | :--- | :--- | :--- | :--- |
| Init | {1,2,3} | {2,4,6} | [] | [] |
| Check s1 | 1 not in s2 | - | [1] | [] |
| Check s1 | 2 in s2 | - | [1] | [] |
| Check s1 | 3 not in s2 | - | [1,3] | [] |
| Check s2 | - | 2 in s1 | [1,3] | [] |
| Check s2 | - | 4 not in s1 | [1,3] | [4] |
| Check s2 | - | 6 not in s1 | [1,3] | [4,6] |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of `nums1` and `nums2`. Constructing the sets takes $$O(N + M)$$, and iterating through the sets takes $$O(N + M)$$ with constant-time lookups.
- Space complexity: $$O(N + M)$$ to store the unique elements of both arrays in the hash sets.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        for (int v : s1) {
            if (!s2.contains(v)) {
                ans[0].push_back(v);
            }
        }
        for (int v : s2) {
            if (!s1.contains(v)) {
                ans[1].push_back(v);
            }
        }
        return ans;
    }
};
```

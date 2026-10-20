# [350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `two-pointers`, `binary-search`, `sorting`

---

## Problem Description
Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```

**Example 2:**

```
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`

**Follow up:**

* What if the given array is already sorted? How would you optimize your algorithm?
* What if `nums1`'s size is small compared to `nums2`'s size? Which algorithm is better?
* What if elements of `nums2` are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

---

## Solution & Editorial
# Intuition
To find the intersection of two arrays with multiplicity, we need to track the exact frequency of each element in the first array. A hash map allows us to count occurrences in linear time, and then stream through the second array to decrement frequencies and collect matching elements.

# Approach
1. Initialize an `unordered_map<int, int> cnt` to store the frequency of each element in `nums1`.
2. Iterate through each element `x` in `nums1` and increment its frequency count in `cnt`.
3. Initialize an empty `vector<int> ans` to store the intersection result.
4. Iterate through each element `x` in `nums2`. Check if `x` exists in `cnt` and its frequency is greater than `0`. If so, append `x` to `ans` and decrement its count in `cnt`.
5. Return `ans` containing all matched elements.

### Visual Walkthrough (Example 1: nums1 = [1,2,2,1], nums2 = [2,2])
- **Step 1 (Frequency Map construction from nums1):**
  `cnt[1] = 2`, `cnt[2] = 2`
- **Step 2 (Processing nums2):**
  - `x = 2`: `cnt[2]` is 2 (> 0), append `2` to `ans`, `cnt[2]` becomes 1. `ans = [2]`
  - `x = 2`: `cnt[2]` is 1 (> 0), append `2` to `ans`, `cnt[2]` becomes 0. `ans = [2, 2]`
- **Final Output:** `[2, 2]`

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the size of `nums1` and $$M$$ is the size of `nums2`. Building the frequency map takes $$O(N)$$ time, and traversing `nums2` takes $$O(M)$$ time with expected $$O(1)$$ hash map lookups.
- Space complexity: $$O(N)$$ to store the frequency map for the unique elements of `nums1`, plus auxiliary space for the result vector.

# Code
```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt;
        for (int x : nums1) {
            ++cnt[x];
        }
        vector<int> ans;
        for (int x : nums2) {
            if (cnt[x]-- > 0) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

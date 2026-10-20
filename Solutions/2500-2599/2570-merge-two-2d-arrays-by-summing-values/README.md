# [2570. Merge Two 2D Arrays by Summing Values](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `two-pointers`

---

## Problem Description
You are given two **2D** integer arrays `nums1` and `nums2.`

* `nums1[i] = [idi, vali]` indicate that the number with the id `idi` has a value equal to `vali`.
* `nums2[i] = [idi, vali]` indicate that the number with the id `idi` has a value equal to `vali`.

Each array contains **unique** ids and is sorted in **ascending** order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:

* Only ids that appear in at least one of the two arrays should be included in the resulting array.
* Each id should be included **only once** and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays, then assume its value in that array to be `0`.

Return *the resulting array*. The returned array must be sorted in ascending order by id.

**Example 1:**

```
Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
Output: [[1,6],[2,3],[3,2],[4,6]]
Explanation: The resulting array contains the following:
- id = 1, the value of this id is 2 + 4 = 6.
- id = 2, the value of this id is 3.
- id = 3, the value of this id is 2.
- id = 4, the value of this id is 5 + 1 = 6.
```

**Example 2:**

```
Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
Explanation: There are no common ids, so we just include each id with its value in the resulting list.
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 200`
* `nums1[i].length == nums2[j].length == 2`
* `1 <= idi, vali <= 1000`
* Both arrays contain unique ids.
* Both arrays are in strictly ascending order by id.

---

## Solution & Editorial
# Intuition
Since both input arrays are already sorted by their IDs, we can leverage the Two Pointers technique to merge them in a single pass. This avoids the overhead of hash maps or sorting, achieving optimal linear time complexity.

# Approach
1. Initialize two pointers, `left` for `nums1` and `right` for `nums2`, both starting at 0.
2. Compare the IDs at `nums1[left][0]` and `nums2[right][0]`:
   - If `nums1[left][0] < nums2[right][0]`, append `nums1[left]` to the result and increment `left`.
   - If `nums1[left][0] > nums2[right][0]`, append `nums2[right]` to the result and increment `right`.
   - If they are equal, append the ID and the sum of their values to the result, then increment both `left` and `right`.
3. After one pointer reaches the end of its array, append the remaining elements from the other array to the result.

### Visual Trace (Example 1)
`nums1 = [[1,2],[2,3],[4,5]]`, `nums2 = [[1,4],[3,2],[4,1]]`

| Step | left | right | nums1[left][0] | nums2[right][0] | Action | Result |
|---|---|---|---|---|---|---|
| 1 | 0 | 0 | 1 | 1 | Equal | [1, 6] |
| 2 | 1 | 1 | 2 | 3 | 2 < 3 | [1, 6], [2, 3] |
| 3 | 2 | 1 | 4 | 3 | 4 > 3 | [1, 6], [2, 3], [3, 2] |
| 4 | 2 | 2 | 4 | 4 | Equal | [1, 6], [2, 3], [3, 2], [4, 6] |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of `nums1` and `nums2` respectively. We traverse each array exactly once.
- Space complexity: $$O(N + M)$$ to store the merged result.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left = 0;
        int right = 0;
        while(left < n1 && right < n2){
            if(nums1[left][0] < nums2[right][0]){
                ans.push_back({nums1[left][0],nums1[left][1]});
                left++;
            }
            else if(nums1[left][0] > nums2[right][0]){
                ans.push_back({nums2[right][0],nums2[right][1]});
                right++;
            }else{
                ans.push_back({nums1[left][0],nums1[left][1]+nums2[right][1]});
                left++;
                right++;
            }
        }
        while(left < n1){
            ans.push_back({nums1[left][0],nums1[left][1]});
            left++;
        }
        while(right < n2){
            ans.push_back({nums2[right][0],nums2[right][1]});
            right++;
        }
        return ans;
    }
};
```

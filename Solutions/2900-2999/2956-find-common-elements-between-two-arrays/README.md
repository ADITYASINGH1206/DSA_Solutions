# [2956. Find Common Elements Between Two Arrays](https://leetcode.com/problems/find-common-elements-between-two-arrays/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given two integer arrays `nums1` and `nums2` of sizes `n` and `m`, respectively. Calculate the following values:

* `answer1` : the number of indices `i` such that `nums1[i]` exists in `nums2`.
* `answer2` : the number of indices `i` such that `nums2[i]` exists in `nums1`.

Return `[answer1,answer2]`.

**Example 1:**

**Input:** nums1 = [2,3,2], nums2 = [1,2]

**Output:** [2,1]

**Explanation:**

**Example 2:**

**Input:** nums1 = [4,3,2,3,1], nums2 = [2,2,5,2,3,6]

**Output:** [3,4]

**Explanation:**

The elements at indices 1, 2, and 3 in `nums1` exist in `nums2` as well. So `answer1` is 3.

The elements at indices 0, 1, 3, and 4 in `nums2` exist in `nums1`. So `answer2` is 4.

**Example 3:**

**Input:** nums1 = [3,4,2,3], nums2 = [1,5]

**Output:** [0,0]

**Explanation:**

No numbers are common between `nums1` and `nums2`, so answer is [0,0].

**Constraints:**

* `n == nums1.length`
* `m == nums2.length`
* `1 <= n, m <= 100`
* `1 <= nums1[i], nums2[i] <= 100`

---

## Solution & Editorial
# Intuition
To determine how many elements of one array exist in another, we can iterate through each element of the first array and check if it appears anywhere in the second array. Since the constraints are small (up to 100), a nested loop approach is efficient enough to solve the problem directly.

# Approach
1. Initialize a result vector `ans` of size 2 with zeros.
2. Iterate through each element `nums1[i]` of `nums1`. For each element, perform a linear scan through `nums2`. If a match is found, increment `ans[0]` and immediately break the inner loop to avoid double-counting the same element in `nums1`.
3. Repeat the process for `nums2`: iterate through each element `nums2[i]` and scan `nums1`. If a match is found, increment `ans[1]` and break the inner loop.
4. Return the `ans` vector.

### Visual Trace (Example 1: nums1 = [2,3,2], nums2 = [1,2])
| Step | Current Element | Search Space | Match Found? | ans[0] |
| :--- | :--- | :--- | :--- | :--- |
| 1 | nums1[0]=2 | [1,2] | Yes | 1 |
| 2 | nums1[1]=3 | [1,2] | No | 1 |
| 3 | nums1[2]=2 | [1,2] | Yes | 2 |

# Complexity
- Time complexity: $$O(n \times m)$$, where $$n$$ and $$m$$ are the lengths of `nums1` and `nums2` respectively. We perform a nested loop for both calculations.
- Space complexity: $$O(1)$$, as we only use a fixed-size vector to store the two results, regardless of input size.

# Code
```cpp
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2,0);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans[0]+=1;
                    break;
                }
            }
        }
        for(int i=0;i<nums2.size();i++){
            for(int j=0;j<nums1.size();j++){
                if(nums2[i]==nums1[j]){
                    ans[1]+=1;
                    break;
                }
            }
        }
        return ans;
    }
};
```

# [2780. Minimum Index of a Valid Split](https://leetcode.com/problems/minimum-index-of-a-valid-split/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sorting`

---

## Problem Description
An element `x` of an integer array `arr` of length `m` is **dominant** if **more than half** the elements of `arr` have a value of `x`.

You are given a **0-indexed** integer array `nums` of length `n` with one **dominant** element.

You can split `nums` at an index `i` into two arrays `nums[0, ..., i]` and `nums[i + 1, ..., n - 1]`, but the split is only **valid** if:

* `0 <= i < n - 1`
* `nums[0, ..., i]`, and `nums[i + 1, ..., n - 1]` have the same dominant element.

Here, `nums[i, ..., j]` denotes the subarray of `nums` starting at index `i` and ending at index `j`, both ends being inclusive. Particularly, if `j < i` then `nums[i, ..., j]` denotes an empty subarray.

Return *the **minimum** index of a **valid split***. If no valid split exists, return `-1`.

**Example 1:**

```
Input: nums = [1,2,2,2]
Output: 2
Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3. 
In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
It can be shown that index 2 is the minimum index of a valid split.
```

**Example 2:**

```
Input: nums = [2,1,3,1,1,1,7,1,2,1]
Output: 4
Explanation: We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
It can be shown that index 4 is the minimum index of a valid split.
```

**Example 3:**

```
Input: nums = [3,3,3,3,7,2,2]
Output: -1
Explanation: It can be shown that there is no valid split.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`
* `nums` has exactly one dominant element.

---

## Solution & Editorial
# Intuition
Since the problem guarantees that the entire array has a dominant element, that element must also be the dominant element for any valid split. We first identify this global dominant element using a frequency map, then iterate through the array to check if the split condition holds for both the left and right partitions.

# Approach
1. **Identify the Dominant Element**: Iterate through `nums` once to populate an `unordered_map<int, int> freq` and track the element with the highest frequency (`majorityEle`).
2. **Iterate and Validate**: Perform a second pass from index `0` to `n-2`. Maintain a running count of `majorityEle` in the left partition (`leftCount`).
3. **Check Conditions**: For each index `i`:
   - `leftSize = i + 1`
   - `rightSize = n - leftSize`
   - `rightCount = maxFreq - leftCount`
   - A split is valid if `leftCount * 2 > leftSize` AND `rightCount * 2 > rightSize`.
4. **Return**: Return the first index `i` that satisfies the condition. If the loop completes without finding one, return `-1`.

### Visual Trace (Example 1: [1, 2, 2, 2])
- `maxFreq` = 3, `majorityEle` = 2
- `i = 0`: `leftCount` = 0, `leftSize` = 1, `rightCount` = 3, `rightSize` = 3. `0*2 > 1` (F)
- `i = 1`: `leftCount` = 1, `leftSize` = 2, `rightCount` = 2, `rightSize` = 2. `2 > 2` (F)
- `i = 2`: `leftCount` = 2, `leftSize` = 3, `rightCount` = 1, `rightSize` = 1. `4 > 3` (T) AND `2 > 1` (T). Return 2.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform two linear passes: one to count frequencies and one to validate splits.
- Space complexity: $$O(N)$$ in the worst case for the `unordered_map` to store frequencies of distinct elements.

# Code
```cpp
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int majorityEle = 0;
        int maxFreq = 0;
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
                majorityEle = num;
            }
        }
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == majorityEle) {
                leftCount++;
            }
            int rightCount = maxFreq - leftCount;
            int leftSize = i + 1;
            int rightSize = n - leftSize;
            if (leftCount * 2 > leftSize && rightCount * 2 > rightSize) {
                return i;
            }
        }

        return -1;
    }
};
```

# [2248. Intersection of Multiple Arrays](https://leetcode.com/problems/intersection-of-multiple-arrays/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`, `counting`

---

## Problem Description
Given a 2D integer array `nums` where `nums[i]` is a non-empty array of **distinct** positive integers, return *the list of integers that are present in **each array** of* `nums` *sorted in **ascending order***.

**Example 1:**

```
Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
Output: [3,4]
Explanation: 
The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
```

**Example 2:**

```
Input: nums = [[1,2,3],[4,5,6]]
Output: []
Explanation: 
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= sum(nums[i].length) <= 1000`
* `1 <= nums[i][j] <= 1000`
* All the values of `nums[i]` are **unique**.

---

## Solution & Editorial
# Intuition
Since the problem constraints specify that each sub-array contains distinct integers and the values are bounded between 1 and 1000, we can leverage a frequency array to track the occurrences of each number across all sub-arrays. If a number appears exactly as many times as there are sub-arrays, it must be present in every sub-array.

# Approach
1. Initialize a frequency array `freq` of size 1001 with zeros to store the count of each integer encountered.
2. Iterate through each sub-array in `nums` and each integer within those sub-arrays, incrementing the corresponding index in `freq`.
3. After processing all sub-arrays, iterate through the `freq` array from 1 to 1000. If `freq[i]` equals the total number of sub-arrays (`nums.size()`), append `i` to the result vector `ans`.
4. Since we iterate through `freq` in increasing order, the resulting `ans` vector is naturally sorted.

### Visual Trace (Example 1: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]])
- `n` = 3
- After processing all arrays:
  - `freq[1]` = 2, `freq[2]` = 2, `freq[3]` = 3, `freq[4]` = 3, `freq[5]` = 2, `freq[6]` = 1
- Check `freq[i] == 3`:
  - `i=3`: `freq[3] == 3` (True) -> `ans = [3]`
  - `i=4`: `freq[4] == 3` (True) -> `ans = [3, 4]`

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the total number of elements across all sub-arrays and $$M$$ is the range of values (1000). We traverse every element once and then iterate through the fixed-size frequency array.
- Space complexity: $$O(M)$$, as we use a fixed-size array of 1001 integers to store frequencies regardless of the input size.

# Code
```cpp
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;
        vector<int>freq(1001,0);
        int n = nums.size();
        for(vector v:nums){
            for(int num : v){
                freq[num]++;
            }
        }
        for(int i = 0;i<1001;i++){
            if(freq[i]==n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

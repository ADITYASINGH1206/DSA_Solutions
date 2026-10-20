# [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `prefix-sum`

---

## Problem Description
Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to* `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,1,1], k = 2
Output: 2
```

**Example 2:**

```
Input: nums = [1,2,3], k = 3
Output: 2
```

**Constraints:**

* `1 <= nums.length <= 2 * 104`
* `-1000 <= nums[i] <= 1000`
* `-107 <= k <= 107`

---

## Solution & Editorial
# Intuition
The problem asks us to find the total number of continuous subarrays whose elements sum up to a given target $k$. A naive approach of checking every possible subarray takes $$O(N^2)$$ or $$O(N^3)$$ time. We can optimize this by maintaining a running prefix sum and utilizing a frequency map to count how many previous prefix sums equal `presum - k` in logarithmic time per element.

# Approach
1. Initialize a frequency map `mpp` to store the counts of prefix sums encountered so far, and set `mpp[0] = 1` to account for any valid subarray starting directly from index 0.
2. Maintain `presum` to accumulate the running sum of elements from the beginning of `nums` up to the current index `i`.
3. For each element `nums[i]`, update `presum += nums[i]` and compute `remove = presum - k`.
4. Add the frequency of `remove` from `mpp` to our total answer `ans`.
5. Increment the frequency of the current `presum` in `mpp` by 1.

### Visual Dry Run (Example 1: nums = [1, 1, 1], k = 2)

| i | nums[i] | presum | remove = presum - k | mpplookup[remove] | ans | mpp state after update |
|---|---------|--------|---------------------|-------------------|-----|------------------------|
| - | -       | 0      | -                   | -                 | 0   | {0: 1}                 |
| 0 | 1       | 1      | -1                  | mpp[-1] (0)       | 0   | {0: 1, 1: 1}           |
| 1 | 1       | 2      | 0                   | mpp[0] (1)        | 1   | {0: 1, 1: 1, 2: 1}     |
| 2 | 1       | 3      | 1                   | mpp[1] (1)        | 2   | {0: 1, 1: 1, 2: 1, 3: 1}|

Final Output: `2`

# Complexity
- Time complexity: $$O(N \log N)$$ — We iterate through the array of size $$N$$ once. At each iteration, we perform lookups and insertions into a balanced binary search tree (`std::map`), which takes $$O(\log N)$$ time per operation.
- Space complexity: $$O(N)$$ — In the worst-case scenario, every prefix sum is unique, requiring space proportional to the size of the array to store them inside `mpp`.

# Code
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0] =1;
        int ans=0;
        int presum =0;
        for(int i=0;i<nums.size();i++){
            presum+= nums[i];
            int remove = presum-k;
            ans += mpp[remove];
            mpp[presum] += 1;

        }
        return ans;
    }
};
```

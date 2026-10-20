# [2341. Maximum Number of Pairs in Array](https://leetcode.com/problems/maximum-number-of-pairs-in-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
You are given a **0-indexed** integer array `nums`. In one operation, you may do the following:

* Choose **two** integers in `nums` that are **equal**.
* Remove both integers from `nums`, forming a **pair**.

The operation is done on `nums` as many times as possible.

Return *a **0-indexed** integer array* `answer` *of size* `2` *where* `answer[0]` *is the number of pairs that are formed and* `answer[1]` *is the number of leftover integers in* `nums` *after doing the operation as many times as possible*.

**Example 1:**

```
Input: nums = [1,3,2,1,3,2,2]
Output: [3,1]
Explanation:
Form a pair with nums[0] and nums[3] and remove them from nums. Now, nums = [3,2,3,2,2].
Form a pair with nums[0] and nums[2] and remove them from nums. Now, nums = [2,2,2].
Form a pair with nums[0] and nums[1] and remove them from nums. Now, nums = [2].
No more pairs can be formed. A total of 3 pairs have been formed, and there is 1 number leftover in nums.
```

**Example 2:**

```
Input: nums = [1,1]
Output: [1,0]
Explanation: Form a pair with nums[0] and nums[1] and remove them from nums. Now, nums = [].
No more pairs can be formed. A total of 1 pair has been formed, and there are 0 numbers leftover in nums.
```

**Example 3:**

```
Input: nums = [0]
Output: [0,1]
Explanation: No pairs can be formed, and there is 1 number leftover in nums.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To maximize the number of pairs, we simply need to count the occurrences of each unique integer in the array. For any integer that appears $k$ times, we can form $\lfloor k/2 \rfloor$ pairs, leaving behind $k \pmod 2$ elements.

# Approach
1. Initialize a frequency map (or a fixed-size array since constraints are small) to store the count of each number in `nums`.
2. Iterate through the input `nums` and populate the map.
3. Iterate through the map entries. For each count `it.second`:
   - Add `it.second / 2` to `ans[0]` (total pairs).
   - Subtract `(it.second / 2) * 2` from `ans[1]` (initially set to the total length of the array).
4. Return the resulting `ans` vector.

### Visual Trace (Example 1: nums = [1,3,2,1,3,2,2])
| Number | Frequency | Pairs (freq/2) | Leftover (freq%2) |
| :--- | :--- | :--- | :--- |
| 1 | 2 | 1 | 0 |
| 3 | 2 | 1 | 0 |
| 2 | 3 | 1 | 1 |
| **Total** | | **3** | **1** |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the input array. We traverse the array once to count frequencies and then iterate over the unique elements (at most $N$).
- Space complexity: $$O(K)$$, where $K$ is the number of unique elements in `nums`. Given the constraints ($0 \le nums[i] \le 100$), this is effectively $O(1)$ space.

# Code
```cpp
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = {0,n};
        unordered_map<int,int> mp;
        for(auto x: nums){
            mp[x]++;
        }
    
        for(auto it: mp){
            if(it.second>=2){
                ans[0]+= it.second/2;
                ans[1] -= (it.second/2)*2;
            }
        }
        return ans;
    }
};
```

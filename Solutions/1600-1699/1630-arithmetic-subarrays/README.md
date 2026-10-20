# [1630. Arithmetic Subarrays](https://leetcode.com/problems/arithmetic-subarrays/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sorting`

---

## Problem Description
A sequence of numbers is called **arithmetic** if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence `s` is arithmetic if and only if `s[i+1] - s[i] == s[1] - s[0]` for all valid `i`.

For example, these are **arithmetic** sequences:

```
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
```

The following sequence is not **arithmetic**:

```
1, 1, 2, 5, 7
```

You are given an array of `n` integers, `nums`, and two arrays of `m` integers each, `l` and `r`, representing the `m` range queries, where the `ith` query is the range `[l[i], r[i]]`. All the arrays are **0-indexed**.

Return *a list of* `boolean` *elements* `answer`*, where* `answer[i]` *is* `true` *if the subarray* `nums[l[i]], nums[l[i]+1], ... , nums[r[i]]` *can be **rearranged** to form an **arithmetic** sequence, and* `false` *otherwise.*

**Example 1:**

```
Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
```

**Example 2:**

```
Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
Output: [false,true,false,false,true,true]
```

**Constraints:**

* `n == nums.length`
* `m == l.length`
* `m == r.length`
* `2 <= n <= 500`
* `1 <= m <= 500`
* `0 <= l[i] < r[i] < n`
* `-105 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To determine if a subarray can form an arithmetic sequence, the most straightforward property is that when sorted, the difference between any two consecutive elements must be constant. Since the constraints are small ($N, M \le 500$), sorting each subarray is efficient enough to pass within the time limits.

# Approach
1. Iterate through each query defined by the range `[l[k], r[k]]`.
2. For each query, extract the elements from `nums` into a temporary vector `subarr`.
3. Sort `subarr` in non-decreasing order.
4. Calculate the common difference `dif` as `subarr[1] - subarr[0]`.
5. Iterate through the sorted `subarr` and verify that `subarr[i] - subarr[i-1]` equals `dif` for all `i > 0`. If any pair fails this condition, the subarray is not arithmetic.
6. Store the result in the `ans` vector.

### Visual Trace (Example 1: Query 0)
- `nums = [4, 6, 5, 9, 3, 7]`, `l[0]=0`, `r[0]=2`
- Subarray: `[4, 6, 5]`
- Sorted: `[4, 5, 6]`
- `dif = 5 - 4 = 1`
- Check: `6 - 5 == 1` (True)
- Result: `true`

# Complexity
- Time complexity: $$O(M \cdot N \log N)$$, where $$M$$ is the number of queries and $$N$$ is the maximum length of a subarray. For each of the $$M$$ queries, we extract up to $$N$$ elements and perform a sort operation taking $$O(N \log N)$$.
- Space complexity: $$O(N)$$, required to store the temporary `subarr` for each query.

# Code
```cpp
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int ls = l.size();
        vector<bool> ans(ls,false);
        int k = 0;
        while(k<ls){
            vector<int> subarr;
            for(int i = l[k];i<=r[k];i++){
                subarr.push_back(nums[i]);
            }
            sort(subarr.begin(),subarr.end());
            bool ap = true;
            int size = subarr.size();
            if(size == 1){
                ans[k] = true;
                k++;
                continue;
            }
            int dif = subarr[1]-subarr[0];
            for(int i =1;i<subarr.size();i++){
                if(subarr[i]-subarr[i-1] != dif){
                    ap = false;
                    break;
                }
            }
            ans[k] = ap;
            k++;
        }
        return ans;
    }
};
```

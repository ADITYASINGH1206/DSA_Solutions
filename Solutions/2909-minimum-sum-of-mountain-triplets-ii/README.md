# [2909. Minimum Sum of Mountain Triplets II](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
You are given a **0-indexed** array `nums` of integers.

A triplet of indices `(i, j, k)` is a **mountain** if:

* `i < j < k`
* `nums[i] < nums[j]` and `nums[k] < nums[j]`

Return *the **minimum possible sum** of a mountain triplet of* `nums`. *If no such triplet exists, return* `-1`.

**Example 1:**

```
Input: nums = [8,6,1,5,3]
Output: 9
Explanation: Triplet (2, 3, 4) is a mountain triplet of sum 9 since: 
- 2 < 3 < 4
- nums[2] < nums[3] and nums[4] < nums[3]
And the sum of this triplet is nums[2] + nums[3] + nums[4] = 9. It can be shown that there are no mountain triplets with a sum of less than 9.
```

**Example 2:**

```
Input: nums = [5,4,8,7,10,2]
Output: 13
Explanation: Triplet (1, 3, 5) is a mountain triplet of sum 13 since: 
- 1 < 3 < 5
- nums[1] < nums[3] and nums[5] < nums[3]
And the sum of this triplet is nums[1] + nums[3] + nums[5] = 13. It can be shown that there are no mountain triplets with a sum of less than 13.
```

**Example 3:**

```
Input: nums = [6,5,4,3,4,5]
Output: -1
Explanation: It can be shown that there are no mountain triplets in nums.
```

**Constraints:**

* `3 <= nums.length <= 105`
* `1 <= nums[i] <= 108`

---

## Solution & Editorial
# Intuition
To form a mountain triplet $(i, j, k)$, we need $i < j < k$ such that $nums[i] < nums[j]$ and $nums[k] < nums[j]$. To minimize the sum $nums[i] + nums[j] + nums[k]$, for a fixed peak $j$, we must choose the smallest possible $nums[i]$ from the left side and the smallest possible $nums[k]$ from the right side.

# Approach
1. Precompute two arrays: `left` and `right`.
   - `left[i]` stores the minimum value in the range $[0, i]$.
   - `right[i]` stores the minimum value in the range $[i, n-1]$.
2. Iterate through each index $j$ from $1$ to $n-2$ as a potential peak.
3. Check if $nums[j] > left[j-1]$ and $nums[j] > right[j+1]$. If true, calculate the sum $nums[j] + left[j-1] + right[j+1]$ and update the global minimum `ans`.

### Visual Trace (nums = [8, 6, 1, 5, 3])
| Index | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| nums | 8 | 6 | 1 | 5 | 3 |
| left | 8 | 6 | 1 | 1 | 1 |
| right | 1 | 1 | 1 | 3 | 3 |

- $j=1: nums[1]=6. left[0]=8. 6 > 8$ (False)
- $j=2: nums[2]=1. left[1]=6. 1 > 6$ (False)
- $j=3: nums[3]=5. left[2]=1, right[4]=3. 5 > 1$ and $5 > 3$ (True). Sum = $5+1+3 = 9$.

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the array. We perform three linear passes: one for `left`, one for `right`, and one to find the minimum sum.
- Space complexity: $$O(N)$$ to store the `left` and `right` prefix/suffix minimum arrays.

# Code
```cpp
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> left(n,0),right(n,0);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            left[i] = min(left[i-1],nums[i]);
        }
        for(int i = n-2;i>=0;i--){
            right[i] = min(right[i+1],nums[i]);
        }
        for(int i = 1;i<n-1;i++){
            if(nums[i]>left[i-1] && nums[i]>right[i+1]){
                ans = min(ans,nums[i]+left[i-1]+right[i+1]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```

# [2176. Count Equal and Divisible Pairs in an Array](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given a **0-indexed** integer array `nums` of length `n` and an integer `k`, return *the **number of pairs*** `(i, j)` *where* `0 <= i < j < n`, *such that* `nums[i] == nums[j]` *and* `(i * j)` *is divisible by* `k`.

**Example 1:**

```
Input: nums = [3,1,2,2,2,1,3], k = 2
Output: 4
Explanation:
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
```

**Example 2:**

```
Input: nums = [1,2,3,4], k = 1
Output: 0
Explanation: Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i], k <= 100`

---

## Solution & Editorial
# Intuition
Since the constraints on the array length are very small ($n \le 100$), a direct brute-force approach is optimal. We need to check every possible pair $(i, j)$ such that $0 \le i < j < n$ and verify two conditions: the values at these indices are equal, and their product is divisible by $k$.

# Approach
1. Initialize a counter `ans` to 0.
2. Use a nested loop structure: the outer loop iterates through index `i` from $0$ to $n-1$, and the inner loop iterates through index `j` from $i+1$ to $n-1$.
3. For each pair $(i, j)$, calculate the product $r = i \times j$.
4. Check if `nums[i] == nums[j]` and `r % k == 0`. If both are true, increment `ans`.
5. Return `ans` after all iterations complete.

### Visual Trace (Example 1: nums = [3,1,2,2,2,1,3], k = 2)
| i | j | nums[i] | nums[j] | i*j | (i*j)%2 == 0 | Match? |
|---|---|---|---|---|---|---|
| 0 | 6 | 3 | 3 | 0 | True | Yes (ans=1) |
| 2 | 3 | 2 | 2 | 6 | True | Yes (ans=2) |
| 2 | 4 | 2 | 2 | 8 | True | Yes (ans=3) |
| 3 | 4 | 2 | 2 | 12 | True | Yes (ans=4) |

# Complexity
- Time complexity: $$O(n^2)$$ — We iterate through all pairs $(i, j)$ in the array, which results in $\frac{n(n-1)}{2}$ iterations.
- Space complexity: $$O(1)$$ — We only use a few integer variables for counting and indexing, requiring constant extra space.

# Code
```cpp
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        if(n == 1) return 0;
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int r = i*j;
                if(nums[i] == nums[j] && r%k ==0) ans++;
            }
        }
        return ans;

    }
};
```

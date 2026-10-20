# [3637. Trionic Array I](https://leetcode.com/problems/trionic-array-i/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
You are given an integer array `nums` of length `n`.

An array is **trionic** if there exist indices `0 < p < q < n − 1` such that:

* `nums[0...p]` is **strictly** increasing,
* `nums[p...q]` is **strictly** decreasing,
* `nums[q...n − 1]` is **strictly** increasing.

Return `true` if `nums` is trionic, otherwise return `false`.

**Example 1:**

**Input:** nums = [1,3,5,4,2,6]

**Output:** true

**Explanation:**

Pick `p = 2`, `q = 4`:

* `nums[0...2] = [1, 3, 5]` is strictly increasing (`1 < 3 < 5`).
* `nums[2...4] = [5, 4, 2]` is strictly decreasing (`5 > 4 > 2`).
* `nums[4...5] = [2, 6]` is strictly increasing (`2 < 6`).

**Example 2:**

**Input:** nums = [2,1,3]

**Output:** false

**Explanation:**

There is no way to pick `p` and `q` to form the required three segments.

**Constraints:**

* `3 <= n <= 100`
* `-1000 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires identifying three distinct segments: strictly increasing, strictly decreasing, and strictly increasing. This structure implies exactly two "direction changes" in the sequence of slopes: from positive to negative at index $p$, and from negative to positive at index $q$. By tracking the current slope direction and counting how many times the trend switches, we can determine if the array satisfies the trionic property in a single pass.

# Approach
1. Initialize `dirchange` to 0 (neutral) and `total` to 0 (count of direction switches).
2. Iterate through the array from index 1 to $n-1$. For each pair `(nums[i-1], nums[i])`:
   - If `nums[i] > nums[i-1]` (positive slope): If the previous direction was not positive (i.e., `dirchange` was 0 or -1), increment `total` and set `dirchange` to 1.
   - If `nums[i] < nums[i-1]` (negative slope): If the previous direction was positive (i.e., `dirchange` was 1), increment `total` and set `dirchange` to -1. If `dirchange` was 0, return `false` immediately as the sequence must start by increasing.
   - If `nums[i] == nums[i-1]`, return `false` as the segments must be strictly monotonic.
3. After the loop, the array is trionic if and only if `total == 3`.

### Visual Trace (Example 1: [1, 3, 5, 4, 2, 6])
| Step | Pair | Slope | dirchange | total |
|---|---|---|---|---|
| 1 | (1,3) | + | 1 | 1 |
| 2 | (3,5) | + | 1 | 1 |
| 3 | (5,4) | - | -1 | 2 |
| 4 | (4,2) | - | -1 | 2 |
| 5 | (2,6) | + | 1 | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the array, as we perform a single linear scan.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool ans = true;
        int dirchange = 0;
        int total =0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>0){
                if(dirchange == 0){
                    dirchange = 1;
                    total++;
                }
                else if(dirchange == -1){
                    dirchange =1;
                    total++;
                }
            }
            if(nums[i]-nums[i-1]<0){
                if(dirchange == 0){
                    return false;
                }
                else if(dirchange == 1){
                    dirchange = -1;
                    total++;
                }
            }
            if(nums[i]==nums[i-1]){
                return false;
            }
        }
        if(total != 3){
            ans = false;
        }
        return ans;
        
    }
};
```

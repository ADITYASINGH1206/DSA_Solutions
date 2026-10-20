# [1004. Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`, `sliding-window`, `prefix-sum`

---

## Problem Description
Given a binary array `nums` and an integer `k`, return *the maximum number of consecutive* `1`*'s in the array if you can flip at most* `k` `0`'s.

**Example 1:**

```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

**Example 2:**

```
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `nums[i]` is either 0 or 1.
* `0 <= k <= nums.length`

---

## Solution & Editorial
# Intuition
The problem asks for the maximum consecutive ones in a binary array after flipping at most $k$ zeros. This can be framed as finding the longest subarray containing at most $k$ zeros. A sliding window approach is ideal here because the validity condition is monotonic: if a window contains at most $k$ zeros, any subwindow of it also contains at most $k$ zeros, and expanding or shrinking the window dynamically allows us to track the maximum valid length efficiently.

# Approach
1. Initialize pointers `l = 0` and `r = 0` to define the bounds of the sliding window, along with `count = 0` to track the number of zeros currently in the window, and `ans = 0` to record the maximum valid window size.
2. Iterate with the right pointer `r` from `0` to `n - 1`. If `nums[r] == 0`, increment `count`.
3. While `count > k`, increment the left pointer `l`. If the element leaving the window at `l` is `0`, decrement `count` to maintain the invariant that the window has at most `k` zeros.
4. Update `ans` with the maximum length encountered using `r - l + 1` at each step.
5. Continue until `r` traverses the entire array and return `ans`.

### Visual Trace Walkthrough (Example 1: `nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2`)

| r | nums[r] | count | l (after shrink) | Window `[l, r]` | ans | Explanation |
|---|---------|-------|------------------|----------------|-----|-------------|
| 0 | 1       | 0     | 0                | `[0, 0]`       | 1   | Valid window |
| 1 | 1       | 0     | 0                | `[0, 1]`       | 2   | Valid window |
| 2 | 1       | 0     | 0                | `[0, 2]`       | 3   | Valid window |
| 3 | 0       | 1     | 0                | `[0, 3]`       | 4   | 1 zero included |
| 4 | 0       | 2     | 0                | `[0, 4]`       | 5   | 2 zeros included (limit reached) |
| 5 | 0       | 3     | 1                | `[1, 5]`       | 5   | Exceeds $k$, shrink `l` until `count == 2` |
| 6 | 1       | 2     | 2                | `[2, 6]`       | 5   | Shrink `l` to maintain $\le 2$ zeros |
| 7 | 1       | 2     | 3                | `[3, 7]`       | 5   | Shrink `l` to maintain $\le 2$ zeros |
| 8 | 1       | 2     | 3                | `[3, 8]`       | 6   | Window expands to size 6 |
| 9 | 1       | 2     | 3                | `[3, 9]`       | 7   | Window expands to size 7 |
| 10| 0       | 3     | 6                | `[6, 10]`      | 7   | Shrink `l` past first zero |

# Complexity
- Time complexity: $$O(N)$$ — The right pointer `r` traverses the array of size $N$ exactly once. The left pointer `l` also only moves forward and visits each element at most once. Thus, total operations are linear.
- Space complexity: $$O(1)$$ — Only a few primitive variables (`l`, `r`, `count`, `ans`, `n`) are used, requiring constant auxiliary space.

# Code
```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r<n){
            if(nums[r] == 0){
                count++;
                while(count>k){
                    if(nums[l] ==0){
                        count--;
                    }
                    l++;
                }
            }
            ans = max(ans,r-l+1);
            r++;
        
        }
        return ans;
    }
};
```

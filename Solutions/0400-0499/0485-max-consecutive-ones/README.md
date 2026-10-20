# [485. Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given a binary array `nums`, return *the maximum number of consecutive* `1`*'s in the array*.

**Example 1:**

```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
```

**Example 2:**

```
Input: nums = [1,0,1,1,0,1]
Output: 2
```

**Constraints:**

* `1 <= nums.length <= 105`
* `nums[i]` is either `0` or `1`.

---

## Solution & Editorial
# Intuition
The problem asks us to find the maximum length of a contiguous subsegment containing only `1`s in a binary array. We can achieve this by performing a single linear scan through the array, keeping track of the current streak of consecutive `1`s and updating the global maximum whenever a larger streak is encountered.

# Approach
1. Initialize two integer variables: `mx` to track the current count of consecutive `1`s and `ans` to store the maximum count found so far.
2. Iterate through each element `nums[i]` of the array using a `for` loop from `i = 0` to `nums.size() - 1`.
3. If `nums[i] == 1`, increment `mx` by 1 and update `ans = max(ans, mx)`.
4. If `nums[i] == 0`, reset the current count `mx = 0` as the consecutive sequence of `1`s has broken.
5. After the loop completes, return `ans`.

### Visual Trace (Example 1: `nums = [1,1,0,1,1,1]`)
| Index `i` | `nums[i]` | Action | `mx` | `ans` |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 1 | `mx++`, `max(0, 1)` | 1 | 1 |
| 1 | 1 | `mx++`, `max(1, 2)` | 2 | 2 |
| 2 | 0 | `mx = 0` | 0 | 2 |
| 3 | 1 | `mx++`, `max(2, 1)` | 1 | 2 |
| 4 | 1 | `mx++`, `max(2, 2)` | 2 | 2 |
| 5 | 1 | `mx++`, `max(2, 3)` | 3 | 3 |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in `nums`. We traverse the array exactly once.
- Space complexity: $$O(1)$$ auxiliary space, as we only use two integer variables (`mx` and `ans`).

# Code
```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                mx++;
                ans = max(ans,mx);
            }else{
                mx = 0;
            }
        }
        return ans;
    }
};
```

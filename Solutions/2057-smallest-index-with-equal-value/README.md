# [2057. Smallest Index With Equal Value](https://leetcode.com/problems/smallest-index-with-equal-value/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given a **0-indexed** integer array `nums`, return *the **smallest** index* `i` *of* `nums` *such that* `i mod 10 == nums[i]`*, or* `-1` *if such index does not exist*.

`x mod y` denotes the **remainder** when `x` is divided by `y`.

**Example 1:**

```
Input: nums = [0,1,2]
Output: 0
Explanation: 
i=0: 0 mod 10 = 0 == nums[0].
i=1: 1 mod 10 = 1 == nums[1].
i=2: 2 mod 10 = 2 == nums[2].
All indices have i mod 10 == nums[i], so we return the smallest index 0.
```

**Example 2:**

```
Input: nums = [4,3,2,1]
Output: 2
Explanation: 
i=0: 0 mod 10 = 0 != nums[0].
i=1: 1 mod 10 = 1 != nums[1].
i=2: 2 mod 10 = 2 == nums[2].
i=3: 3 mod 10 = 3 != nums[3].
2 is the only index which has i mod 10 == nums[i].
```

**Example 3:**

```
Input: nums = [1,2,3,4,5,6,7,8,9,0]
Output: -1
Explanation: No index satisfies i mod 10 == nums[i].
```

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 9`

---

## Solution & Editorial
# Intuition
The problem asks for the smallest index `i` such that `i % 10 == nums[i]`. Since we need the *smallest* index, a simple linear scan from left to right is optimal. The first index that satisfies the condition is guaranteed to be the smallest.

# Approach
1. Iterate through the array `nums` using an index `i` from `0` to `n-1`.
2. For each index `i`, calculate `i % 10` and compare it with the value at `nums[i]`.
3. If the condition `i % 10 == nums[i]` holds, immediately return `i` as it is the smallest index.
4. If the loop completes without finding any such index, return `-1`.

### Visual Trace (Example 2: nums = [4, 3, 2, 1])
| Index (i) | i % 10 | nums[i] | Match? |
|-----------|--------|---------|--------|
| 0         | 0      | 4       | No     |
| 1         | 1      | 3       | No     |
| 2         | 2      | 2       | Yes    |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass through the input array.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for the loop variable.

# Code
```cpp
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i%10 == nums[i]) return i;
        }
        return -1;
    }
};
```

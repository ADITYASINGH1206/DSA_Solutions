# [2154. Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`, `simulation`

---

## Problem Description
You are given an array of integers `nums`. You are also given an integer `original` which is the first number that needs to be searched for in `nums`.

You then do the following steps:

1. If `original` is found in `nums`, **multiply** it by two (i.e., set `original = 2 * original`).
2. Otherwise, **stop** the process.
3. **Repeat** this process with the new number as long as you keep finding the number.

Return *the **final** value of* `original`.

**Example 1:**

```
Input: nums = [5,3,6,1,12], original = 3
Output: 24
Explanation: 
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
```

**Example 2:**

```
Input: nums = [2,7,9], original = 4
Output: 4
Explanation:
- 4 is not found in nums. Thus, 4 is returned.
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i], original <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks us to repeatedly search for a value and update it if found. Since the constraints are small (N <= 1000), a direct simulation of the search process is efficient enough to pass within the time limits.

# Approach
1. Initialize a boolean flag `found` to `true` to enter the `while` loop.
2. Inside the loop, reset `found` to `false`.
3. Iterate through the `nums` array. If `nums[i]` matches the current `original` value, update `original` by doubling it, set `found` to `true`, and break the inner loop to restart the search with the new value.
4. If the loop completes without finding the current `original`, `found` remains `false`, terminating the `while` loop.

### Visual Trace (Example 1: nums = [5,3,6,1,12], original = 3)
| Iteration | Current `original` | Found? | Action |
| :--- | :--- | :--- | :--- |
| 1 | 3 | Yes | 3 found, `original` becomes 6 |
| 2 | 6 | Yes | 6 found, `original` becomes 12 |
| 3 | 12 | Yes | 12 found, `original` becomes 24 |
| 4 | 24 | No | 24 not found, terminate |

# Complexity
- Time complexity: $$O(N \times K)$$, where $$N$$ is the size of the array and $$K$$ is the number of successful multiplications. In the worst case, we scan the array for each doubling step.
- Space complexity: $$O(1)$$, as we only use a few integer variables for tracking state.

# Code
```cpp
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        bool found = true;
        while(found){
            found = false;
            for(int i = 0;i<n;i++){
                if(nums[i] == original){
                    original *= 2;
                    found = true;
                    break;
                }
            }
        }

        return original;
    }
};
```

# [3206. Alternating Groups I](https://leetcode.com/problems/alternating-groups-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `sliding-window`

---

## Problem Description
There is a circle of red and blue tiles. You are given an array of integers `colors`. The color of tile `i` is represented by `colors[i]`:

* `colors[i] == 0` means that tile `i` is **red**.
* `colors[i] == 1` means that tile `i` is **blue**.

Every 3 contiguous tiles in the circle with **alternating** colors (the middle tile has a different color from its **left** and **right** tiles) is called an **alternating** group.

Return the number of **alternating** groups.

**Note** that since `colors` represents a **circle**, the **first** and the **last** tiles are considered to be next to each other.

**Example 1:**

**Input:** colors = [1,1,1]

**Output:** 0

**Explanation:**

**Example 2:**

**Input:** colors = [0,1,0,0,1]

**Output:** 3

**Explanation:**

Alternating groups:

**Constraints:**

* `3 <= colors.length <= 100`
* `0 <= colors[i] <= 1`

---

## Solution & Editorial
# Intuition
Since the array represents a circular arrangement, every element at index `i` has a left neighbor at `(i - 1 + n) % n` and a right neighbor at `(i + 1) % n`. An alternating group of size 3 is formed if the middle element `colors[i]` is different from both its immediate neighbors.

# Approach
1. Iterate through each index `i` from `0` to `n-1`.
2. For each `i`, identify the left neighbor index `l` and right neighbor index `r` using modular arithmetic to handle the circular wrap-around.
3. Check if `colors[i] != colors[l]` and `colors[i] != colors[r]`. If both conditions are true, increment the counter `ans`.

### Visual Trace (Example 2: colors = [0, 1, 0, 0, 1])
| i | colors[i] | l (left) | r (right) | colors[l] | colors[r] | Alternating? |
|---|---|---|---|---|---|---|
| 0 | 0 | 4 | 1 | 1 | 1 | Yes (1,0,1) |
| 1 | 1 | 0 | 2 | 0 | 0 | Yes (0,1,0) |
| 2 | 0 | 1 | 3 | 1 | 0 | No (1,0,0) |
| 3 | 0 | 2 | 4 | 0 | 1 | Yes (0,0,1) |
| 4 | 1 | 3 | 0 | 0 | 0 | No (0,1,0) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the `colors` array. We perform a single pass over the array with constant-time operations per element.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            int l = 0;
            int r = 0;
            if(i == 0){
                l = n-1;
                r = i+1;
            }else if(i == n-1){
                l = i-1;
                r = 0;
            }else{
                l = i-1;
                r = i+1;
            }
            if(colors[i] != colors[l] && colors[i] != colors[r]){
                ans++;
            }
        }
        return ans;
    }
};
```

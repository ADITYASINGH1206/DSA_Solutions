# [3964. Minimum Lights to Illuminate a Road](https://leetcode.com/problems/minimum-lights-to-illuminate-a-road/)
**Difficulty:** `Medium` | **Tags:** `array`, `prefix-sum`

---

## Problem Description
You are given an integer array `lights` of length `n`, representing positions 0 through `n - 1` on a road.

For each position `i`:

* If `lights[i] = v`, where `v > 0`, there is a working bulb at position `i` that **illuminates** every position from `max(0, i - v)` to `min(n - 1, i + v)`, inclusive.
* If `lights[i] = 0`, there is no working bulb at position `i`.

A position is **visible** if it is illuminated by **at least** one working bulb.

You may install **additional** bulbs at **any** positions. Each additional bulb installed at position `j` **illuminates** positions from `max(0, j - 1)` to `min(n - 1, j + 1)`, inclusive.

Return the minimum number of additional bulbs required to make **every** position on the road visible.

**Example 1:**

**Input:** lights = [0,0,0,0]

**Output:** 2

**Explanation:**

One optimal placement is:

* Install an additional bulb at position 1, illuminating positions `[0, 1, 2]`.
* Install an additional bulb at position 3, illuminating positions `[2, 3]`.

Therefore, the minimum number of additional bulbs required is 2.

**Example 2:**

**Input:** lights = [0,0,0,2,0]

**Output:** 1

**Explanation:**

* Since `lights[3] = 2`, the working bulb at position 3 illuminates positions `[1, 2, 3, 4]`.
* Installing an additional bulb at position 1 illuminates positions `[0, 1, 2]`, making every position visible.
* Therefore, the minimum number of additional bulbs required is 1.

**Constraints:**

* `1 <= n == lights.length <= 105`
* `0 <= lights[i] <= n`

---

## Solution & Editorial
# Intuition
To determine which parts of the road are unlit, we can use a difference array to efficiently mark the coverage of existing bulbs. Once we identify the unlit segments, we can greedily place additional bulbs to cover the maximum possible range (3 units: `[j-1, j+1]`) starting from the first unlit position.

# Approach
1. **Mark Coverage**: Use a `diff` array of size `n+1` to record the range `[max(0, i - lights[i]), min(n - 1, i + lights[i])]` for every bulb. Applying prefix sums on `diff` allows us to identify all indices `i` where `cur == 0` (unlit).
2. **Greedy Placement**: Iterate through the road. When an unlit position `i` is encountered, increment the answer and skip the next 3 positions (since a bulb at `i+1` covers `[i, i+1, i+2]`).

### Visual Trace (Example 1: [0,0,0,0])
- `diff` array after processing: `[0,0,0,0,0]` (all 0s).
- `dark` array: `[T, T, T, T]`.
- Iteration:
  - `i=0`: `dark[0]` is true. `ans=1`, `i` becomes `0+3=3`.
  - `i=3`: `dark[3]` is true. `ans=2`, `i` becomes `3+3=6`.
- Result: 2.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the road. We perform one pass to build the difference array, one pass for prefix sums, and one pass to count additional bulbs.
- Space complexity: $$O(N)$$ to store the `diff` and `dark` arrays.

# Code
```cpp
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            if (lights[i] > 0) {
                int left = max(0, i - lights[i]);
                int right = min(n - 1, i + lights[i]);
                
                diff[left]++;
                diff[right + 1]--;
            }
        }
        vector<bool> dark(n, false);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += diff[i];
            if (cur == 0) {
                dark[i] = true;
            }
        }
        int ans = 0;
        int i = 0;
        
        while (i < n) {
            if (dark[i]) {
                ans++;
                i += 3; 
            } else {
                i++;
            }
        }
        
        return ans;
    }
};
```

# [2833. Furthest Point From Origin](https://leetcode.com/problems/furthest-point-from-origin/)
**Difficulty:** `Easy` | **Tags:** `string`, `counting`

---

## Problem Description
You are given a string `moves` of length `n` consisting only of characters `'L'`, `'R'`, and `'_'`. The string represents your movement on a number line starting from the origin `0`.

In the `ith` move, you can choose one of the following directions:

* move to the left if `moves[i] = 'L'` or `moves[i] = '_'`
* move to the right if `moves[i] = 'R'` or `moves[i] = '_'`

Return *the **distance from the origin** of the **furthest** point you can get to after* `n` *moves*.

**Example 1:**

```
Input: moves = "L_RL__R"
Output: 3
Explanation: The furthest point we can reach from the origin 0 is point -3 through the following sequence of moves "LLRLLLR".
```

**Example 2:**

```
Input: moves = "_R__LL_"
Output: 5
Explanation: The furthest point we can reach from the origin 0 is point -5 through the following sequence of moves "LRLLLLL".
```

**Example 3:**

```
Input: moves = "_______"
Output: 7
Explanation: The furthest point we can reach from the origin 0 is point 7 through the following sequence of moves "RRRRRRR".
```

**Constraints:**

* `1 <= moves.length == n <= 50`
* `moves` consists only of characters `'L'`, `'R'` and `'_'`.

---

## Solution & Editorial
# Intuition
To maximize the distance from the origin, we should treat all wildcard characters ('_') as the direction that is already dominant (either 'L' or 'R'). By assigning every '_' to the direction that currently has a higher count, we maximize the absolute displacement from zero.

# Approach
1. Count the occurrences of 'L', 'R', and '_' in the input string `moves` using three counters: `l_count`, `r_count`, and `u_count`.
2. The net displacement from fixed moves is `abs(l_count - r_count)`.
3. Since each '_' can be chosen as either 'L' or 'R', we add the total count of '_' (`u_count`) to the absolute difference calculated in step 2. This effectively forces all wildcards to contribute to the direction that is already further from the origin.

### Visual Trace (Example 1: "L_RL__R")
| Step | Char | l_count | r_count | u_count |
| :--- | :--- | :--- | :--- | :--- |
| Init | - | 0 | 0 | 0 |
| 1 | L | 1 | 0 | 0 |
| 2 | _ | 1 | 0 | 1 |
| 3 | R | 1 | 1 | 1 |
| 4 | L | 2 | 1 | 1 |
| 5 | _ | 2 | 1 | 2 |
| 6 | _ | 2 | 1 | 3 |
| 7 | R | 2 | 2 | 3 |

Final Calculation: `abs(2 - 2) + 3 = 3`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single pass over the input.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for integer counters.

# Code
```cpp
class Solution {
public:
    int furthestDistanceFromOrigin(std::string moves) {
        int ans = 0;
        int l_count = 0, r_count = 0, u_count = 0;
        
        for (char c : moves) {
            if (c == 'L') l_count++;
            else if (c == 'R') r_count++;
            else u_count++;
        }
        
        ans = abs(l_count - r_count) + u_count;
        return ans;
    }
};
```

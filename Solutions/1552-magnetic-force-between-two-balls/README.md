# [1552. Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/)
**Difficulty:** `Medium` | **Tags:** `array`, `binary-search`, `sorting`

---

## Problem Description
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has `n` empty baskets, the `ith` basket is at `position[i]`, Morty has `m` balls and needs to distribute the balls into the baskets such that the **minimum magnetic force** between any two balls is **maximum**.

Rick stated that magnetic force between two different balls at positions `x` and `y` is `|x - y|`.

Given the integer array `position` and the integer `m`. Return *the required force*.

**Example 1:**

```
Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
```

**Example 2:**

```
Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
```

**Constraints:**

* `n == position.length`
* `2 <= n <= 105`
* `1 <= position[i] <= 109`
* All integers in `position` are **distinct**.
* `2 <= m <= position.length`

---

## Solution & Editorial
# Intuition
The problem asks us to maximize the minimum distance between any two balls. This structure—maximizing a minimum value—is a classic indicator that we can use binary search on the answer. If we can place $m$ balls with a minimum distance of $d$, we can certainly do so for any distance less than $d$. This monotonicity allows us to binary search for the largest valid $d$.

# Approach
1. **Sort**: First, sort the `position` array to easily calculate distances between adjacent baskets.
2. **Binary Search Range**: The minimum possible distance is 1, and the maximum possible distance is `position.back() - position.front()`.
3. **Greedy Check**: Define a helper function `count(d)` that checks if it is possible to place $m$ balls such that every pair is at least $d$ apart. We greedily place the first ball at `position[0]` and then place subsequent balls at the first available basket that is at least $d$ distance from the last placed ball.
4. **Binary Search Logic**: 
   - If `count(mid) >= m`, the distance `mid` is feasible, so we try a larger distance (`l = mid`).
   - Otherwise, `mid` is too large, so we reduce the search space (`r = mid - 1`).

### Visual Trace (Example 1: position = [1, 2, 3, 4, 7], m = 3)
- Sorted: `[1, 2, 3, 4, 7]`
- Range: `[0, 6]`
- Iteration 1: `mid = 3`. `count(3)`: Place at 1, then 4, then 7. Count = 3. Since $3 \ge 3$, `l = 3`.
- Iteration 2: `mid = 4`. `count(4)`: Place at 1, then 7. Count = 2. Since $2 < 3$, `r = 3`.
- Result: 3.

# Complexity
- Time complexity: $$O(N \log N + N \log D)$$, where $N$ is the number of baskets and $D$ is the range of positions ($10^9$). Sorting takes $$O(N \log N)$$, and the binary search performs $$O(\log D)$$ iterations, each calling a linear scan of the array.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation).

# Code
```cpp
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = position.back() - position.front();
        while (l < r) {
            int mid = r - (r - l) / 2;
            if (count(position, mid) >= m)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
    int count(vector<int>& position, int d) {
        int ans = 1, cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= d) {
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
};
```

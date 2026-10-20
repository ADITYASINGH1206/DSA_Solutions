# [3296. Minimum Number of Seconds to Make Mountain Height Zero](https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `binary-search`, `greedy`, `heap-priority-queue`

---

## Problem Description
You are given an integer `mountainHeight` denoting the height of a mountain.

You are also given an integer array `workerTimes` representing the work time of workers in **seconds**.

Each worker may reduce the mountain's height by any **non-negative integer** amount. If worker `i` reduces the height by `x`, then:

* reducing the first unit of height takes `workerTimes[i]` seconds,
* reducing the second unit takes `workerTimes[i] * 2` seconds,
* ...
* reducing the `x`-th unit takes `workerTimes[i] * x` seconds.

The total time spent by worker `i` is the sum of the times required for all `x` units they reduce. As all workers operate simultaneously, the total time required is the **maximum** time spent by any worker.

Return an integer representing the **minimum** number of seconds required for the workers to make the height of the mountain 0.

**Example 1:**

**Input:** mountainHeight = 4, workerTimes = [2,1,1]

**Output:** 3

**Explanation:**

One way the height of the mountain can be reduced to 0 is:

* Worker 0 reduces the height by 1, taking `workerTimes[0] = 2` seconds.
* Worker 1 reduces the height by 2, taking `workerTimes[1] + workerTimes[1] * 2 = 3` seconds.
* Worker 2 reduces the height by 1, taking `workerTimes[2] = 1` second.

Since they work simultaneously, the minimum time needed is `max(2, 3, 1) = 3` seconds.

**Example 2:**

**Input:** mountainHeight = 10, workerTimes = [3,2,2,4]

**Output:** 12

**Explanation:**

* Worker 0 reduces the height by 2, taking `workerTimes[0] + workerTimes[0] * 2 = 9` seconds.
* Worker 1 reduces the height by 3, taking `workerTimes[1] + workerTimes[1] * 2 + workerTimes[1] * 3 = 12` seconds.
* Worker 2 reduces the height by 3, taking `workerTimes[2] + workerTimes[2] * 2 + workerTimes[2] * 3 = 12` seconds.
* Worker 3 reduces the height by 2, taking `workerTimes[3] + workerTimes[3] * 2 = 12` seconds.

The number of seconds needed is `max(9, 12, 12, 12) = 12` seconds.

**Example 3:**

**Input:** mountainHeight = 5, workerTimes = [1]

**Output:** 15

**Explanation:**

There is only one worker in this example, so the answer is `workerTimes[0] + workerTimes[0] * 2 + workerTimes[0] * 3 + workerTimes[0] * 4 + workerTimes[0] * 5 = 15`.

**Constraints:**

* `1 <= mountainHeight <= 105`
* `1 <= workerTimes.length <= 104`
* `1 <= workerTimes[i] <= 106`

---

## Solution & Editorial
# Intuition
The problem asks for the minimum time to reduce a mountain of height `mountainHeight` to zero. Since the total height reduced by all workers is monotonically non-decreasing with respect to time, we can binary search for the minimum time `t` such that the sum of heights reduced by all workers is at least `mountainHeight`.

# Approach
1. **Binary Search Range**: The lower bound `l` is 1. The upper bound `r` is set to `1e16`, which is sufficient given the constraints (max `mountainHeight` is $10^5$, max `workerTimes` is $10^6$).
2. **Check Function**: For a given time `t`, a worker with `workerTimes[i]` can reduce height `x` if the sum of their work times $\sum_{j=1}^{x} (workerTimes[i] \cdot j) \le t$ holds. This simplifies to $workerTimes[i] \cdot \frac{x(x+1)}{2} \le t$. Solving for $x$ using the quadratic formula $x^2 + x - \frac{2t}{workerTimes[i]} \le 0$, we get $x \le \frac{-1 + \sqrt{1 + 8t/workerTimes[i]}}{2}$.
3. **Binary Search Logic**: If the total height reduced by all workers at time `mid` is $\ge mountainHeight$, we try a smaller time (`r = mid`); otherwise, we increase the time (`l = mid + 1`).

### Visual Trace (Example 1: mountainHeight=4, workerTimes=[2,1,1])
- `check(2)`: 
  - Worker 0: $2 \cdot x(x+1)/2 \le 2 \implies x=1$
  - Worker 1: $1 \cdot x(x+1)/2 \le 2 \implies x=1$
  - Worker 2: $1 \cdot x(x+1)/2 \le 2 \implies x=1$
  - Total $h = 1+1+1 = 3 < 4$. (Too small)
- `check(3)`: 
  - Worker 0: $2 \cdot x(x+1)/2 \le 3 \implies x=1$
  - Worker 1: $1 \cdot x(x+1)/2 \le 3 \implies x=2$
  - Worker 2: $1 \cdot x(x+1)/2 \le 3 \implies x=1$
  - Total $h = 1+2+1 = 4 \ge 4$. (Valid)

# Complexity
- Time complexity: $$O(W \cdot \log(T))$$ where $$W$$ is the number of workers and $$T$$ is the search range ($10^{16}$). The check function iterates over all workers, and binary search performs logarithmic steps.
- Space complexity: $$O(1)$$ as we only use a few variables for calculation.

# Code
```cpp
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using ll = long long;
        ll l = 1, r = 1e16;
        auto check = [&](ll t) -> bool {
            ll h = 0;
            for (int& wt : workerTimes) {
                h += (long long) (sqrt(t * 2.0 / wt + 0.25) - 0.5);
            }
            return h >= mountainHeight;
        };
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

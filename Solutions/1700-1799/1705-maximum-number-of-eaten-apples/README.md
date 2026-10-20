# [1705. Maximum Number of Eaten Apples](https://leetcode.com/problems/maximum-number-of-eaten-apples/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `heap-priority-queue`

---

## Problem Description
There is a special kind of apple tree that grows apples every day for `n` days. On the `ith` day, the tree grows `apples[i]` apples that will rot after `days[i]` days, that is on day `i + days[i]` the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by `apples[i] == 0` and `days[i] == 0`.

You decided to eat **at most** one apple a day (to keep the doctors away). Note that you can keep eating after the first `n` days.

Given two integer arrays `days` and `apples` of length `n`, return *the maximum number of apples you can eat.*

**Example 1:**

```
Input: apples = [1,2,3,5,2], days = [3,2,1,4,2]
Output: 7
Explanation: You can eat 7 apples:
- On the first day, you eat an apple that grew on the first day.
- On the second day, you eat an apple that grew on the second day.
- On the third day, you eat an apple that grew on the second day. After this day, the apples that grew on the third day rot.
- On the fourth to the seventh days, you eat apples that grew on the fourth day.
```

**Example 2:**

```
Input: apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
Output: 5
Explanation: You can eat 5 apples:
- On the first to the third day you eat apples that grew on the first day.
- Do nothing on the fouth and fifth days.
- On the sixth and seventh days you eat apples that grew on the sixth day.
```

**Constraints:**

* `n == apples.length == days.length`
* `1 <= n <= 2 * 104`
* `0 <= apples[i], days[i] <= 2 * 104`
* `days[i] = 0` if and only if `apples[i] = 0`.

---

## Solution & Editorial
# Intuition
To maximize the number of apples eaten, we must always prioritize eating the apples that are closest to rotting. This is a classic greedy problem where a min-priority queue allows us to efficiently track the expiration dates of available apple batches.

# Approach
1. Use a min-priority queue `pq` to store pairs of `{expiry_day, count}`, where `expiry_day` is the day the apples rot and `count` is the number of remaining apples.
2. Iterate through each day starting from `day = 0`. Continue the loop as long as there are new apples to grow (`day < n`) or there are still edible apples in the `pq`.
3. On each day, if new apples grow, push them into the `pq` with their calculated expiration date (`day + days[day]`).
4. Remove all batches from the `pq` that have already expired (`expiry_day <= day`).
5. If the `pq` is not empty, consume one apple from the batch with the earliest expiration date. Decrement the count and push the batch back into the `pq` if apples remain.

### Visual Trace (Example 1: apples=[1,2,3,5,2], days=[3,2,1,4,2])
| Day | New Apples | PQ (expiry, count) | Eaten |
|---|---|---|---|
| 0 | 1 (exp 3) | {(3, 1)} | 1 |
| 1 | 2 (exp 3) | {(3, 2)} | 2 |
| 2 | 3 (exp 3) | {(3, 1)} | 3 |
| 3 | 5 (exp 7) | {(7, 5)} | 4 |
| 4 | - | {(7, 4)} | 5 |
| 5 | - | {(7, 3)} | 6 |
| 6 | - | {(7, 2)} | 7 |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of days. Each day we perform at most one push and one pop operation on the priority queue, and each heap operation takes $$O(\log N)$$.
- Space complexity: $$O(N)$$, as the priority queue can store up to $$N$$ distinct batches of apples in the worst case.

# Code
```cpp
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        int n = apples.size();
        int day = 0;
        int eaten = 0;

        while (day < n || !pq.empty()) {
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }

            while (!pq.empty() && pq.top().first <= day) {
                pq.pop();
            }
            if (!pq.empty()) {
                auto p = pq.top();
                pq.pop();

                p.second--;
                eaten++;

                if (p.second > 0)
                    pq.push(p);
            }

            day++;
        }

        return eaten;
    }
};
```

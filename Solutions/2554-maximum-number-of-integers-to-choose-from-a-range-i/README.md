# [2554. Maximum Number of Integers to Choose From a Range I](https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `binary-search`, `greedy`, `sorting`

---

## Problem Description
You are given an integer array `banned` and two integers `n` and `maxSum`. You are choosing some number of integers following the below rules:

* The chosen integers have to be in the range `[1, n]`.
* Each integer can be chosen **at most once**.
* The chosen integers should not be in the array `banned`.
* The sum of the chosen integers should not exceed `maxSum`.

Return *the **maximum** number of integers you can choose following the mentioned rules*.

**Example 1:**

```
Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
```

**Example 2:**

```
Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.
```

**Example 3:**

```
Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
```

**Constraints:**

* `1 <= banned.length <= 104`
* `1 <= banned[i], n <= 104`
* `1 <= maxSum <= 109`

---

## Solution & Editorial
# Intuition
To maximize the number of integers chosen, we should always pick the smallest available integers first. By greedily selecting integers starting from 1 up to $n$, we minimize the impact on the `maxSum` constraint, allowing us to fit the largest possible count of numbers.

# Approach
1. Store all elements of the `banned` array in an `unordered_map` (or a hash set) for $O(1)$ average-time lookup.
2. Iterate through integers $i$ from $1$ to $n$.
3. For each $i$, check if it exists in the `banned` map. If it does, skip it.
4. If it is not banned, add $i$ to a running `sum`. If `sum` exceeds `maxSum`, stop the process immediately.
5. Otherwise, increment a counter `cnt` and continue.

### Visual Trace (Example 1: banned=[1,6,5], n=5, maxSum=6)
| i | Banned? | sum | cnt | Action |
|---|---|---|---|---|
| 1 | Yes | 0 | 0 | Skip |
| 2 | No | 2 | 1 | Add |
| 3 | No | 5 | 2 | Add |
| 4 | No | 9 | 2 | Stop (9 > 6) |

# Complexity
- Time complexity: $$O(N + M)$$, where $N$ is the range limit and $M$ is the size of the `banned` array. We iterate $N$ times and perform $O(1)$ lookups, with an initial $O(M)$ pass to populate the hash map.
- Space complexity: $$O(M)$$, required to store the `banned` elements in the `unordered_map`.

# Code
```cpp
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int a=banned.size();
        unordered_map<int,int> x;
        for(int i=0;i<a;i++){
            x[banned[i]]=1;
        }
        int sum=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(x[i]!=0) continue;
            sum+=i;
            if(sum>maxSum) break;
            cnt++;
        }
        return cnt;
    }
};
```

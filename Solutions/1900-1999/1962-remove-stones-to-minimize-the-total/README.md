# [1962. Remove Stones to Minimize the Total](https://leetcode.com/problems/remove-stones-to-minimize-the-total/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `heap-priority-queue`

---

## Problem Description
You are given a **0-indexed** integer array `piles`, where `piles[i]` represents the number of stones in the `ith` pile, and an integer `k`. You should apply the following operation **exactly** `k` times:

* Choose any `piles[i]` and **remove** `floor(piles[i] / 2)` stones from it.

**Notice** that you can apply the operation on the **same** pile more than once.

Return *the **minimum** possible total number of stones remaining after applying the* `k` *operations*.

`floor(x)` is the **largest** integer that is **smaller** than or **equal** to `x` (i.e., rounds `x` down).

**Example 1:**

```
Input: piles = [5,4,9], k = 2
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,5].
- Apply the operation on pile 0. The resulting piles are [3,4,5].
The total number of stones in [3,4,5] is 12.
```

**Example 2:**

```
Input: piles = [4,3,6,7], k = 3
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [4,3,3,7].
- Apply the operation on pile 3. The resulting piles are [4,3,3,4].
- Apply the operation on pile 0. The resulting piles are [2,3,3,4].
The total number of stones in [2,3,3,4] is 12.
```

**Constraints:**

* `1 <= piles.length <= 105`
* `1 <= piles[i] <= 104`
* `1 <= k <= 105`

---

## Solution & Editorial
# Intuition
To minimize the total number of stones, we must greedily reduce the largest pile available at each step. Since removing floor(piles[i] / 2) stones is equivalent to replacing the pile with ceil(piles[i] / 2) stones, we always want to target the current maximum to achieve the largest possible reduction in the total sum.

# Approach
1. Use a max-priority queue to store all pile sizes. This allows us to access and modify the largest pile in logarithmic time.
2. Calculate the initial total sum of all stones.
3. Perform the operation exactly `k` times:
   - Extract the largest pile `a` from the heap.
   - Calculate the reduction: `a / 2`.
   - Subtract this reduction from the total sum.
   - Push the remaining stones `a - floor(a/2)` back into the heap. Note that `a - floor(a/2)` is mathematically equivalent to `ceil(a/2)`, which can be computed as `(a + 1) / 2` using integer division.

### Visual Trace (Example 1: piles = [5, 4, 9], k = 2)
| Step | Heap (Max) | Operation | Sum |
| :--- | :--- | :--- | :--- |
| Init | [9, 5, 4] | - | 18 |
| 1 | [5, 5, 4] | Pop 9, Push 5 | 18 - 4 = 14 |
| 2 | [5, 4, 3] | Pop 5, Push 3 | 14 - 2 = 12 |

# Complexity
- Time complexity: $$O(N \log N + K \log N)$$, where $$N$$ is the number of piles. Building the heap takes $$O(N)$$, and performing $$K$$ operations, each involving a heap pop and push, takes $$O(K \log N)$$.
- Space complexity: $$O(N)$$ to store the pile sizes in the priority queue.

# Code
```cpp
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        int n=piles.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            sum+=piles[i];
            pq.push(piles[i]);
        }
        while(k--){
            int a = pq.top();
            pq.pop();
            sum-=a/2;
            pq.push((a+1)/2);
        }
        return sum;
    }
};
```

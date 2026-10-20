# [2558. Take Gifts From the Richest Pile](https://leetcode.com/problems/take-gifts-from-the-richest-pile/)
**Difficulty:** `Easy` | **Tags:** `array`, `heap-priority-queue`, `simulation`

---

## Problem Description
You are given an integer array `gifts` denoting the number of gifts in various piles. Every second, you do the following:

* Choose the pile with the maximum number of gifts.
* If there is more than one pile with the maximum number of gifts, choose any.
* Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.

Return *the number of gifts remaining after* `k` *seconds.*

**Example 1:**

```
Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation: 
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
```

**Example 2:**

```
Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation: 
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile. 
That is, you can't take any pile with you. 
So, the total gifts remaining are 4.
```

**Constraints:**

* `1 <= gifts.length <= 103`
* `1 <= gifts[i] <= 109`
* `1 <= k <= 103`

---

## Solution & Editorial
# Intuition
To efficiently retrieve and update the pile with the maximum number of gifts, a Max-Heap (priority queue) is the optimal data structure. Since we need to perform this operation $k$ times, using a heap allows us to extract the maximum element and re-insert the updated value in logarithmic time.

# Approach
1. Initialize a `std::priority_queue` with all elements from the `gifts` vector. This takes $O(N)$ time using the heap constructor.
2. Perform $k$ iterations. In each iteration:
   - Extract the top element (the maximum pile) using `pq.top()`.
   - Remove it using `pq.pop()`.
   - Calculate the floor of its square root using `std::sqrt`.
   - Push the new value back into the heap using `pq.push()`.
3. After $k$ seconds, sum all elements remaining in the priority queue to get the final result.

### Visual Trace (Example 1: gifts = [25, 64, 9, 4, 100], k = 4)
| Iteration | Max Pile | New Value | Heap State (Sorted) |
| :--- | :--- | :--- | :--- |
| Start | - | - | [100, 64, 25, 9, 4] |
| 1 | 100 | 10 | [64, 25, 10, 9, 4] |
| 2 | 64 | 8 | [25, 10, 9, 8, 4] |
| 3 | 25 | 5 | [10, 9, 8, 5, 4] |
| 4 | 10 | 3 | [9, 8, 5, 4, 3] |

# Complexity
- Time complexity: $$O(N + K \log N)$$, where $N$ is the number of piles and $K$ is the number of seconds. Building the heap takes $O(N)$, and each of the $K$ operations involves a pop and push, both taking $O(\log N)$.
- Space complexity: $$O(N)$$ to store the gifts in the priority queue.

# Code
```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        for(int i = 0;i<k;i++){
            sort(gifts.rbegin(),gifts.rend());
            gifts[0] = floor(sqrt(gifts[0]));
        }
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans += gifts[i];
        }
        return ans;
    }
};
```

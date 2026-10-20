# [1753. Maximum Score From Removing Stones](https://leetcode.com/problems/maximum-score-from-removing-stones/)
**Difficulty:** `Medium` | **Tags:** `math`, `greedy`, `heap-priority-queue`

---

## Problem Description
You are playing a solitaire game with **three piles** of stones of sizes `a`​​​​​​, `b`,​​​​​​ and `c`​​​​​​ respectively. Each turn you choose two **different non-empty** piles, take one stone from each, and add `1` point to your score. The game stops when there are **fewer than two non-empty** piles (meaning there are no more available moves).

Given three integers `a`​​​​​, `b`,​​​​​ and `c`​​​​​, return *the* ***maximum*** ***score** you can get.*

**Example 1:**

```
Input: a = 2, b = 4, c = 6
Output: 6
Explanation: The starting state is (2, 4, 6). One optimal set of moves is:
- Take from 1st and 3rd piles, state is now (1, 4, 5)
- Take from 1st and 3rd piles, state is now (0, 4, 4)
- Take from 2nd and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 6 points.
```

**Example 2:**

```
Input: a = 4, b = 4, c = 6
Output: 7
Explanation: The starting state is (4, 4, 6). One optimal set of moves is:
- Take from 1st and 2nd piles, state is now (3, 3, 6)
- Take from 1st and 3rd piles, state is now (2, 3, 5)
- Take from 1st and 3rd piles, state is now (1, 3, 4)
- Take from 1st and 3rd piles, state is now (0, 3, 3)
- Take from 2nd and 3rd piles, state is now (0, 2, 2)
- Take from 2nd and 3rd piles, state is now (0, 1, 1)
- Take from 2nd and 3rd piles, state is now (0, 0, 0)
There are fewer than two non-empty piles, so the game ends. Total: 7 points.
```

**Example 3:**

```
Input: a = 1, b = 8, c = 8
Output: 8
Explanation: One optimal set of moves is to take from the 2nd and 3rd piles for 8 turns until they are empty.
After that, there are fewer than two non-empty piles, so the game ends.
```

**Constraints:**

* `1 <= a, b, c <= 105`

---

## Solution & Editorial
# Intuition
To maximize the score, we must always pick the two largest piles available. This greedy strategy ensures that we reduce the largest piles as much as possible, preventing any single pile from becoming so large that it cannot be fully paired with the others.

# Approach
1. Use a `std::priority_queue` to maintain the sizes of the three piles. This allows us to efficiently extract the two largest piles at any given step.
2. While the priority queue contains at least two piles:
   - Extract the largest pile (`x`) and the second-largest pile (`y`).
   - Decrement both by 1.
   - If the resulting size is greater than 0, push them back into the priority queue.
   - Increment the `ans` counter.
3. The loop terminates when fewer than two piles remain, as no more moves are possible.

### Visual Trace (Example 1: a=2, b=4, c=6)
| Iteration | PQ State (Sorted) | Action | Score |
| :--- | :--- | :--- | :--- |
| Start | [6, 4, 2] | - | 0 |
| 1 | [5, 3, 2] | Pop 6, 4; Push 5, 3 | 1 |
| 2 | [4, 4, 1] | Pop 5, 3; Push 4, 2 | 2 |
| 3 | [3, 3, 1] | Pop 4, 4; Push 3, 3 | 3 |
| 4 | [2, 2, 1] | Pop 3, 3; Push 2, 2 | 4 |
| 5 | [1, 1, 1] | Pop 2, 2; Push 1, 1 | 5 |
| 6 | [0, 0, 0] | Pop 1, 1; Push 0, 0 | 6 |

# Complexity
- Time complexity: $$O(N \log 3)$$, where $$N = a+b+c$$. Since the number of piles is constant (3), the heap operations are effectively $$O(1)$$, making the total time complexity linear relative to the sum of stones.
- Space complexity: $$O(1)$$, as the priority queue stores at most 3 integers at any time.

# Code
```cpp
class Solution {
public:
    int maximumScore(int a, int b, int c) 
    {
        int ans = 0;
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(!pq.empty() && pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop(); 
            if(x-1!=0) pq.push(x-1);
            if(y-1!=0) pq.push(y-1);
            ans++;
        }
        return ans;
    }
};
```

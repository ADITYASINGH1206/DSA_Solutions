# [1823. Find the Winner of the Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `recursion`, `queue`, `simulation`

---

## Problem Description
There are `n` friends that are playing a game. The friends are sitting in a circle and are numbered from `1` to `n` in **clockwise order**. More formally, moving clockwise from the `ith` friend brings you to the `(i+1)th` friend for `1 <= i < n`, and moving clockwise from the `nth` friend brings you to the `1st` friend.

The rules of the game are as follows:

1. **Start** at the `1st` friend.
2. Count the next `k` friends in the clockwise direction **including** the friend you started at. The counting wraps around the circle and may count some friends more than once.
3. The last friend you counted leaves the circle and loses the game.
4. If there is still more than one friend in the circle, go back to step `2` **starting** from the friend **immediately clockwise** of the friend who just lost and repeat.
5. Else, the last friend in the circle wins the game.

Given the number of friends, `n`, and an integer `k`, return *the winner of the game*.

**Example 1:**

```
Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
```

**Example 2:**

```
Input: n = 6, k = 5
Output: 1
Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.
```

**Constraints:**

* `1 <= k <= n <= 500`

**Follow up:**

Could you solve this problem in linear time with constant space?

---

## Solution & Editorial
# Intuition
The problem describes the classic Josephus problem. Since we need to simulate the removal of friends in a circular order, a queue is the most natural data structure to represent the circle. By rotating the queue, we can effectively simulate the counting process and remove the element that lands on the k-th position.

# Approach
1. Initialize a queue and push all integers from 1 to `n` into it.
2. While the queue size is greater than 1, perform the following:
   - Rotate the queue `k-1` times by moving the front element to the back. This effectively skips the first `k-1` friends.
   - Remove the element at the front of the queue, which represents the friend who loses the game.
3. Once the queue size reaches 1, the remaining element is the winner.

### Visual Trace (n=5, k=2)
| Step | Queue (Front to Back) | Action | Removed |
| :--- | :--- | :--- | :--- |
| 1 | [1, 2, 3, 4, 5] | Rotate 1 time | - |
| 2 | [2, 3, 4, 5, 1] | Pop front | 2 |
| 3 | [3, 4, 5, 1] | Rotate 1 time | - |
| 4 | [4, 5, 1, 3] | Pop front | 4 |
| 5 | [5, 1, 3] | Rotate 1 time | - |
| 6 | [1, 3, 5] | Pop front | 1 |
| 7 | [3, 5] | Rotate 1 time | - |
| 8 | [5, 3] | Pop front | 5 |
| 9 | [3] | Winner | - |

# Complexity
- Time complexity: $$O(N \cdot K)$$. We perform $$N-1$$ removals. For each removal, we perform $$K-1$$ rotations, where each rotation is an $$O(1)$$ queue operation.
- Space complexity: $$O(N)$$. We store $$N$$ integers in the queue.

# Code
```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        while(q.size()>1)
        {
            int temp=k-1;
            while(temp--)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};
```

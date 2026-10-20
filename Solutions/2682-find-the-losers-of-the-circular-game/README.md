# [2682. Find the Losers of the Circular Game](https://leetcode.com/problems/find-the-losers-of-the-circular-game/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `simulation`

---

## Problem Description
There are `n` friends that are playing a game. The friends are sitting in a circle and are numbered from `1` to `n` in **clockwise order**. More formally, moving clockwise from the `ith` friend brings you to the `(i+1)th` friend for `1 <= i < n`, and moving clockwise from the `nth` friend brings you to the `1st` friend.

The rules of the game are as follows:

`1st` friend receives the ball.

* After that, `1st` friend passes it to the friend who is `k` steps away from them in the **clockwise** direction.
* After that, the friend who receives the ball should pass it to the friend who is `2 * k` steps away from them in the **clockwise** direction.
* After that, the friend who receives the ball should pass it to the friend who is `3 * k` steps away from them in the **clockwise** direction, and so on and so forth.

In other words, on the `ith` turn, the friend holding the ball should pass it to the friend who is `i * k` steps away from them in the **clockwise** direction.

The game is finished when some friend receives the ball for the second time.

The **losers** of the game are friends who did not receive the ball in the entire game.

Given the number of friends, `n`, and an integer `k`, return *the array answer, which contains the losers of the game in the **ascending** order*.

**Example 1:**

```
Input: n = 5, k = 2
Output: [4,5]
Explanation: The game goes as follows:
1) Start at 1st friend and pass the ball to the friend who is 2 steps away from them - 3rd friend.
2) 3rd friend passes the ball to the friend who is 4 steps away from them - 2nd friend.
3) 2nd friend passes the ball to the friend who is 6 steps away from them  - 3rd friend.
4) The game ends as 3rd friend receives the ball for the second time.
```

**Example 2:**

```
Input: n = 4, k = 4
Output: [2,3,4]
Explanation: The game goes as follows:
1) Start at the 1st friend and pass the ball to the friend who is 4 steps away from them - 1st friend.
2) The game ends as 1st friend receives the ball for the second time.
```

**Constraints:**

* `1 <= k <= n <= 50`

---

## Solution & Editorial
# Intuition
The problem asks us to track which friends receive a ball in a circular game where the jump distance increases linearly with each turn. Since the game ends as soon as a friend receives the ball for the second time, we can use a boolean array to keep track of visited friends and simulate the process directly.

# Approach
1. Initialize a boolean vector `received` of size `n` to `false` to track which friends have held the ball.
2. Maintain a `curr` pointer (starting at 0, representing the 1st friend) and a `step` counter (starting at 1).
3. In a loop, mark `received[curr]` as `true`. Calculate the next position using the formula `(curr + step * k) % n`. Increment `step` and continue until the current friend has already been marked `true`.
4. After the loop terminates, iterate through the `received` array. Any index `i` that remains `false` corresponds to a loser (friend `i + 1`).

### Visual Trace (n=5, k=2)
| Turn | Current Friend (curr) | Step | Next Position (curr + step*k) % n |
| :--- | :--- | :--- | :--- |
| 1 | 0 (1st) | 1 | (0 + 1*2) % 5 = 2 (3rd) |
| 2 | 2 (3rd) | 2 | (2 + 2*2) % 5 = 1 (2nd) |
| 3 | 1 (2nd) | 3 | (1 + 3*2) % 5 = 2 (3rd) |
| End | 2 (3rd) | - | Already visited! |

# Complexity
- Time complexity: $$O(n)$$. In the worst case, we visit each of the $$n$$ friends exactly once before the game ends.
- Space complexity: $$O(n)$$ to store the `received` status for each of the $$n$$ friends.

# Code
```cpp
class Solution {
public:
    std::vector<int> circularGameLosers(int n, int k) {
        vector<bool> received(n, false);
        
        int curr = 0;
        int step = 1; 
        
        while (!received[curr]) {
            received[curr] = true;             
            curr = (curr + step * k) % n;      
            step++;                            
        }
        

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!received[i]) {
                ans.push_back(i + 1);
            }
        }
        
        return ans;
    }
};
```

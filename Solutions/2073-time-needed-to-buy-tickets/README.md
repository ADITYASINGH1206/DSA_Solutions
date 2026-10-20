# [2073. Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets/)
**Difficulty:** `Easy` | **Tags:** `array`, `queue`, `simulation`

---

## Problem Description
There are `n` people in a line queuing to buy tickets, where the `0th` person is at the **front** of the line and the `(n - 1)th` person is at the **back** of the line.

You are given a **0-indexed** integer array `tickets` of length `n` where the number of tickets that the `ith` person would like to buy is `tickets[i]`.

Each person takes **exactly 1 second** to buy a ticket. A person can only buy **1 ticket at a time** and has to go back to **the end** of the line (which happens **instantaneously**) in order to buy more tickets. If a person does not have any tickets left to buy, the person will **leave** the line.

Return the **time taken** for the person **initially** at position **k**(0-indexed) to finish buying tickets.

**Example 1:**

**Input:** tickets = [2,3,2], k = 2

**Output:** 6

**Explanation:**

* The queue starts as [2,3,2], where the kth person is underlined.
* After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
* Continuing this process, the queue becomes [2,1,2] at 2 seconds.
* Continuing this process, the queue becomes [1,2,1] at 3 seconds.
* Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
* Continuing this process, the queue becomes [1,1] at 5 seconds.
* Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.

**Example 2:**

**Input:** tickets = [5,1,1,1], k = 0

**Output:** 8

**Explanation:**

* The queue starts as [5,1,1,1], where the kth person is underlined.
* After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
* Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
* Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. The kth person has bought all their tickets, so return 8.

**Constraints:**

* `n == tickets.length`
* `1 <= n <= 100`
* `1 <= tickets[i] <= 100`
* `0 <= k < n`

---

## Solution & Editorial
# Intuition
The problem asks us to simulate a queue where people buy tickets one by one. Since the constraints are small ($n \le 100$, $tickets[i] \le 100$), a direct simulation of the queue process is efficient enough to pass within time limits. We simply iterate through the line repeatedly, decrementing the ticket count for each person until the person at index `k` reaches zero tickets.

# Approach
1. Initialize `ans` to 0 to track the total time elapsed.
2. Use a `while` loop that continues as long as `tickets[k] > 0`.
3. Inside, iterate through the `tickets` array using a `for` loop from index `0` to `n-1`.
4. For each person `i`, if `tickets[i] > 0`:
   - Increment `ans` by 1 (representing 1 second passed).
   - Decrement `tickets[i]` by 1.
   - Check if the current person is the target person (`i == k`) and if they have finished their tickets (`tickets[i] == 0`). If both are true, return `ans` immediately.

### Visual Trace (Example 1: tickets = [2, 3, 2], k = 2)
| Iteration | Queue State | Time (ans) | Target (k=2) Tickets |
|-----------|-------------|------------|----------------------|
| Start     | [2, 3, 2]   | 0          | 2                    |
| Pass 1    | [1, 2, 1]   | 3          | 1                    |
| Pass 2    | [0, 1, 0]   | 6          | 0 (Return 6)         |

# Complexity
- Time complexity: $$O(N \cdot M)$$, where $$N$$ is the number of people and $$M$$ is the maximum number of tickets any person wants. In the worst case, we iterate through the array until the target person finishes.
- Space complexity: $$O(1)$$, as we modify the input array in-place and use only a few integer variables.

# Code
```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int kth = tickets[k];
        int ans = 0;
        int size = tickets.size();
        while(tickets[k]){
            for(int i =0;i<tickets.size();i++){
                if(tickets[i] !=0){
                    ans++;
                    tickets[i] = tickets[i]-1;
                    if(i == k && tickets[i] == 0) return ans;
                }
            }
        }

        return ans;
    }
};
```

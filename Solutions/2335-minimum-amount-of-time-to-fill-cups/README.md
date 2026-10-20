# [2335. Minimum Amount of Time to Fill Cups](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `sorting`, `heap-priority-queue`

---

## Problem Description
You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up `2` cups with **different** types of water, or `1` cup of any type of water.

You are given a **0-indexed** integer array `amount` of length `3` where `amount[0]`, `amount[1]`, and `amount[2]` denote the number of cold, warm, and hot water cups you need to fill respectively. Return *the **minimum** number of seconds needed to fill up all the cups*.

**Example 1:**

```
Input: amount = [1,4,2]
Output: 4
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup and a warm cup.
Second 2: Fill up a warm cup and a hot cup.
Second 3: Fill up a warm cup and a hot cup.
Second 4: Fill up a warm cup.
It can be proven that 4 is the minimum number of seconds needed.
```

**Example 2:**

```
Input: amount = [5,4,4]
Output: 7
Explanation: One way to fill up the cups is:
Second 1: Fill up a cold cup, and a hot cup.
Second 2: Fill up a cold cup, and a warm cup.
Second 3: Fill up a cold cup, and a warm cup.
Second 4: Fill up a warm cup, and a hot cup.
Second 5: Fill up a cold cup, and a hot cup.
Second 6: Fill up a cold cup, and a warm cup.
Second 7: Fill up a hot cup.
```

**Example 3:**

```
Input: amount = [5,0,0]
Output: 5
Explanation: Every second, we fill up a cold cup.
```

**Constraints:**

* `amount.length == 3`
* `0 <= amount[i] <= 100`

---

## Solution & Editorial
# Intuition
To minimize the time required to fill all cups, we should always prioritize filling the two types of cups that currently have the highest remaining counts. By reducing the two largest counts simultaneously, we maximize the efficiency of each second, effectively balancing the load across the three types of water.

# Approach
1. Use a `priority_queue` to store the non-zero cup counts. This allows us to efficiently extract the two largest values at any given time.
2. In each iteration of a `while` loop, extract the largest count (`top1`) and the second-largest count (`top2`) if available.
3. Decrement both counts by 1 (representing one second of filling two different cups).
4. If the decremented values are still greater than 0, push them back into the `priority_queue`.
5. Increment the `ans` counter for each iteration until the queue is empty.

### Visual Trace (Example 1: amount = [1, 4, 2])
| Second | PQ State (Sorted) | Action | Remaining | Ans |
| :--- | :--- | :--- | :--- | :--- |
| 0 | [4, 2, 1] | - | - | 0 |
| 1 | [3, 1, 1] | Pop 4, 2; Push 3, 1 | [3, 1, 1] | 1 |
| 2 | [2, 0, 1] -> [2, 1] | Pop 3, 1; Push 2, 0 | [2, 1] | 2 |
| 3 | [1, 0] | Pop 2, 1; Push 1, 0 | [1] | 3 |
| 4 | [] | Pop 1; Push 0 | [] | 4 |

# Complexity
- Time complexity: $$O(S \log 3)$$, where $$S$$ is the total number of cups. Since the number of cup types is fixed at 3, the heap operations are effectively $$O(1)$$, making the complexity proportional to the total number of cups.
- Space complexity: $$O(1)$$, as the priority queue stores at most 3 elements regardless of the input values.

# Code
```cpp
class Solution {
public:
    int fillCups(vector<int>& amount) {
        int n = amount.size();
        int ans = 0;
        priority_queue<int> pq;
        if(amount[0]>0)pq.push(amount[0]);
        if(amount[1]>0)pq.push(amount[1]);
        if(amount[2]>0)pq.push(amount[2]);
        while(!pq.empty()){
            int top1 = pq.top();
            pq.pop();
            int top2 = 0;
            if(!pq.empty()){
                top2 = pq.top();
                pq.pop();
            }
            if(--top1>0)pq.push(top1);
            if(--top2>0)pq.push(top2);
            ans++;

        }
        return ans;
    }
};
```

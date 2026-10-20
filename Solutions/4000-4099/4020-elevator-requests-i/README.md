# [4020. Elevator Requests I](https://leetcode.com/problems/elevator-requests-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `simulation`

---

## Problem Description
You are given an integer `n` denoting the number of floors in a building, where the floors are numbered from 0 to `n - 1`.

You are also given an integer array `requests`, where `requests` represents the sequence of floor requests.

An elevator starts at floor 0 and follows these rules:

* The elevator moves one floor per second.
* The elevator serves requests in the given order.
* If the elevator is already on the requested floor, no movement is needed.
* After serving a request, the elevator immediately starts moving toward the next request.

Return the **total time** in seconds required to serve all requests.

**Example 1:**

**Input:** n = 5, requests = [2,1,4,3]

**Output:** 7

**Explanation:**

* `requests[0] = 2`: Moving from floor 0 to floor 2 takes 2 seconds.
* `requests[1] = 1`: Moving from floor 2 to floor 1 takes 1 second.
* `requests[2] = 4`: Moving from floor 1 to floor 4 takes 3 seconds.
* `requests[3] = 3`: Moving from floor 4 to floor 3 takes 1 second.

The total time required is `2 + 1 + 3 + 1 = 7` seconds.

**Example 2:**

**Input:** n = 3, requests = [2,0,0]

**Output:** 4

**Explanation:**

* `requests[0] = 2`: Moving from floor 0 to floor 2 takes 2 seconds.
* `requests[1] = 0`: Moving from floor 2 to floor 0 takes 2 seconds.
* `requests[2] = 0`: No movement is needed.

The total time required is `2 + 2 + 0 = 4` seconds.

**Constraints:**

* `1 <= n <= 100`
* `1 <= requests.length <= 100`
* `0 <= requests[i] <= n - 1`

---

## Solution & Editorial
# Intuition
The problem asks us to calculate the total distance traveled by an elevator starting at floor 0, moving sequentially through a list of requested floors. Since the elevator moves one floor per second, the time taken to travel between any two floors is simply the absolute difference between their floor numbers.

# Approach
1. Initialize a variable `ans` to 0 to track the total time and `cur` to 0 to represent the elevator's current floor.
2. Iterate through each floor in the `requests` array.
3. For each request, calculate the absolute difference between the `cur` floor and the target floor `requests[i]` using `abs(cur - requests[i])`.
4. Add this difference to `ans` and update `cur` to the current target floor.
5. Return `ans` after processing all requests.

### Visual Trace (Example 1: n=5, requests=[2, 1, 4, 3])
| Step | Current Floor (`cur`) | Target | Distance (`abs`) | Total Time (`ans`) |
| :--- | :--- | :--- | :--- | :--- |
| Start | 0 | - | - | 0 |
| 1 | 0 | 2 | 2 | 2 |
| 2 | 2 | 1 | 1 | 3 |
| 3 | 1 | 4 | 3 | 6 |
| 4 | 4 | 3 | 1 | 7 |

# Complexity
- Time complexity: $$O(K)$$, where $$K$$ is the number of requests. We perform a single pass over the `requests` array.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for variables `ans`, `sz`, and `cur`.

# Code
```cpp
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0;
        int sz = requests.size();
        int cur = 0;
        for(int i = 0;i<sz;i++){
            ans += abs(cur-requests[i]);
            cur = requests[i];
        }

        return ans;
    }
};
```

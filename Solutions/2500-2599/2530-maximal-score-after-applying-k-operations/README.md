# [2530. Maximal Score After Applying K Operations](https://leetcode.com/problems/maximal-score-after-applying-k-operations/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `heap-priority-queue`

---

## Problem Description
You are given a **0-indexed** integer array `nums` and an integer `k`. You have a **starting score** of `0`.

In one **operation**:

1. choose an index `i` such that `0 <= i < nums.length`,
2. increase your **score** by `nums[i]`, and
3. replace `nums[i]` with `ceil(nums[i] / 3)`.

Return *the maximum possible **score** you can attain after applying **exactly*** `k` *operations*.

The ceiling function `ceil(val)` is the least integer greater than or equal to `val`.

**Example 1:**

```
Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
```

**Example 2:**

```
Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,2,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.
```

**Constraints:**

* `1 <= nums.length, k <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
To maximize the total score, we must always pick the largest available element in the array at each step. Since the operation reduces the chosen element significantly (dividing by 3), the greedy choice of picking the current maximum is optimal because it yields the highest immediate gain and keeps the array values balanced for future operations.

# Approach
1. Use a `std::priority_queue` to maintain the elements of `nums` in descending order. This allows us to extract the maximum element in $O(\log N)$ time.
2. Initialize a `long long` variable `ans` to store the total score.
3. Perform exactly `k` operations:
   - Extract the top element `top` from the priority queue.
   - Add `top` to `ans`.
   - Calculate the new value: `ceil(top / 3)`. In integer arithmetic, this is `(top + 2) / 3` or `top % 3 == 0 ? top / 3 : top / 3 + 1`.
   - Push the new value back into the priority queue.

### Visual Trace (Example 2: nums = [1, 10, 3, 3, 3], k = 3)
| Operation | PQ (Sorted) | Top | Score (ans) | New Value | PQ after push |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | [10, 3, 3, 3, 1] | 10 | 10 | 4 | [4, 3, 3, 3, 1] |
| 2 | [4, 3, 3, 3, 1] | 4 | 14 | 2 | [3, 3, 2, 1, 1] |
| 3 | [3, 3, 2, 1, 1] | 3 | 17 | 1 | [3, 2, 1, 1, 1] |

# Complexity
- Time complexity: $$O(N + K \log N)$$, where $N$ is the size of the array. Building the heap takes $O(N)$, and we perform $K$ operations, each involving a pop and push in the heap, taking $O(\log N)$ per operation.
- Space complexity: $$O(N)$$ to store the elements in the priority queue.

# Code
```cpp
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        priority_queue<int> pq;
        for(int i =0;i<n;i++){
            pq.push(nums[i]);
        }
        for(int i = 0;i<k;i++){
            int top = pq.top();
            pq.pop();
            ans += top;
            if(top%3==0) top = top/3;
            else top = top/3 +1;
            pq.push(top);
        }

        return ans;
    }
};
```

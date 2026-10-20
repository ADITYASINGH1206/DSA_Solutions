# [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
**Difficulty:** `Hard` | **Tags:** `array`, `queue`, `sliding-window`, `heap-priority-queue`, `monotonic-queue`, `range-minimum-maximum-query`

---

## Problem Description
You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the max sliding window*.

**Example 1:**

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**Example 2:**

```
Input: nums = [1], k = 1
Output: [1]
```

**Constraints:**

* `1 <= nums.length <= 105`
* `-104 <= nums[i] <= 104`
* `1 <= k <= nums.length`

---

## Solution & Editorial
# Intuition
The problem requires us to efficiently find the maximum value in a sliding window of fixed size $k$ as it moves across the array. A naive approach of scanning each window takes $$O(N \cdot K)$$ time, which is too slow for $$N = 10^5$$. By maintaining a monotonic decreasing double-ended queue (`deque`), we can keep track of potential maximum candidates in linear time by removing elements that fall out of the window or are smaller than the incoming element.

# Approach
1. Initialize a `deque<int>` named `dq` to store indices of the `nums` array rather than the values themselves. This helps easily check and remove elements that fall outside the current window bounds.
2. Iterate through each element in `nums` using index `i`:
   - Check if the front of the deque `dq.front()` is outside the current window (i.e., less than or equal to `i - k`). If so, pop it from the front.
   - Maintain the monotonic decreasing property of the deque by removing elements from the back (`dq.pop_back()`) as long as the element at the back `nums[dq.back()]` is less than or equal to the current element `nums[i]`.
   - Push the current index `i` into the back of the deque.
   - Once the first valid window is formed (i.e., `i >= k - 1`), record the maximum element, which is always located at `nums[dq.front()]`, into the result vector `ans`.
3. Return `ans` after processing all elements.

### Visual Walkthrough for Example 1
`nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3`

| i | nums[i] | Deque (Indices) | Deque (Values) | Window | Max | Remarks |
|---|---|---|---|---|---|---|
| 0 | 1 | `[0]` | `[1]` | `[1]` | - | Push index 0 |
| 1 | 3 | `[1]` | `[3]` | `[1, 3]` | - | Pop 0 (smaller than 3), push 1 |
| 2 | -1 | `[1, 2]` | `[3, -1]` | `[1, 3, -1]` | `3` | Push index 2, window complete |
| 3 | -3 | `[1, 2, 3]` | `[3, -1, -3]` | `[3, -1, -3]` | `3` | Push index 3 |
| 4 | 5 | `[4]` | `[5]` | `[-1, -3, 5]` | `5` | Pop 1, 2, 3 (all <= 5), push 4 |
| 5 | 3 | `[4, 5]` | `[5, 3]` | `[-3, 5, 3]` | `5` | Push index 5 |
| 6 | 6 | `[6]` | `[6]` | `[5, 3, 6]` | `6` | Pop 4, 5 (all <= 6), push 6 |
| 7 | 7 | `[7]` | `[7]` | `[3, 6, 7]` | `7` | Pop 6 (<= 7), push 7 |

# Complexity
- Time complexity: $$O(N)$$. Each index is pushed into and popped from the deque at most once. Thus, the amortized time complexity per element is $$O(1)$$.
- Space complexity: $$O(K)$$. In the worst case, the deque stores at most $k$ indices corresponding to the window size.

# Code
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i=0;i<n;i++) {
            if (!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] <= nums[i]) 
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
```

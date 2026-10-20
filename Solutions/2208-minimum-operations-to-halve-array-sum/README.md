# [2208. Minimum Operations to Halve Array Sum](https://leetcode.com/problems/minimum-operations-to-halve-array-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `heap-priority-queue`

---

## Problem Description
You are given an array `nums` of positive integers. In one operation, you can choose **any** number from `nums` and reduce it to **exactly** half the number. (Note that you may choose this reduced number in future operations.)

Return *the **minimum** number of operations to reduce the sum of* `nums` *by **at least** half.*

**Example 1:**

```
Input: nums = [5,19,8,1]
Output: 3
Explanation: The initial sum of nums is equal to 5 + 19 + 8 + 1 = 33.
The following is one of the ways to reduce the sum by at least half:
Pick the number 19 and reduce it to 9.5.
Pick the number 9.5 and reduce it to 4.75.
Pick the number 8 and reduce it to 4.
The final array is [5, 4.75, 4, 1] with a total sum of 5 + 4.75 + 4 + 1 = 14.75. 
The sum of nums has been reduced by 33 - 14.75 = 18.25, which is at least half of the initial sum, 18.25 >= 33/2 = 16.5.
Overall, 3 operations were used so we return 3.
It can be shown that we cannot reduce the sum by at least half in less than 3 operations.
```

**Example 2:**

```
Input: nums = [3,8,20]
Output: 3
Explanation: The initial sum of nums is equal to 3 + 8 + 20 = 31.
The following is one of the ways to reduce the sum by at least half:
Pick the number 20 and reduce it to 10.
Pick the number 10 and reduce it to 5.
Pick the number 3 and reduce it to 1.5.
The final array is [1.5, 8, 5] with a total sum of 1.5 + 8 + 5 = 14.5. 
The sum of nums has been reduced by 31 - 14.5 = 16.5, which is at least half of the initial sum, 16.5 >= 31/2 = 15.5.
Overall, 3 operations were used so we return 3.
It can be shown that we cannot reduce the sum by at least half in less than 3 operations.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 107`

---

## Solution & Editorial
# Intuition
To minimize the number of operations, we must always reduce the largest available number in the array. This greedy strategy ensures that each operation provides the maximum possible reduction to the total sum, reaching the target threshold in the fewest steps.

# Approach
1. Calculate the initial `sum` of all elements in `nums` and define the target reduction threshold as `sum / 2.0`.
2. Use a `std::priority_queue<double>` to store all elements, allowing us to efficiently extract the current maximum value in $O(\log N)$ time.
3. While the current `sum` is greater than the target threshold:
   - Extract the largest element `t` from the priority queue.
   - Calculate its halved value `s = t / 2.0`.
   - Update the total `sum` by subtracting the reduction amount (`t - s`).
   - Push the new value `s` back into the priority queue.
   - Increment the operation counter `c`.

### Visual Trace (Example 1: [5, 19, 8, 1])
- Initial Sum: 33. Target: 16.5.
- PQ: [19, 8, 5, 1]
- Op 1: Pop 19, push 9.5. Sum: 33 - 9.5 = 23.5. PQ: [9.5, 8, 5, 1]
- Op 2: Pop 9.5, push 4.75. Sum: 23.5 - 4.75 = 18.75. PQ: [8, 5, 4.75, 1]
- Op 3: Pop 8, push 4. Sum: 18.75 - 4 = 14.75. PQ: [5, 4.75, 4, 1]
- 14.75 <= 16.5, terminate. Result: 3.

# Complexity
- Time complexity: $$O(N \log N + K \log N)$$, where $N$ is the number of elements and $K$ is the number of operations. Building the heap takes $O(N)$, and each of the $K$ operations involves a heap pop and push, each taking $O(\log N)$.
- Space complexity: $$O(N)$$ to store the elements in the priority queue.

# Code
```cpp
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(),nums.end());
        double sum=0;
        int c=0;
        for(int i:nums)
        sum+=i;
        double a=sum/2;
        while(sum>a){
            double t=pq.top();
            pq.pop();
            double s=t/2;
            pq.push(s);
            sum=sum+s-t;
            c++;
        }
        return c;
    }
};
```

# [2895. Minimum Processing Time](https://leetcode.com/problems/minimum-processing-time/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You have a certain number of processors, each having 4 cores. The number of tasks to be executed is four times the number of processors. Each task must be assigned to a unique core, and each core can only be used once.

You are given an array `processorTime` representing the time each processor becomes available and an array `tasks` representing how long each task takes to complete. Return the *minimum* time needed to complete all tasks.

**Example 1:**

**Input:** processorTime = [8,10], tasks = [2,2,3,1,8,7,4,5]

**Output:** 16

**Explanation:**

Assign the tasks at indices 4, 5, 6, 7 to the first processor which becomes available at `time = 8`, and the tasks at indices 0, 1, 2, 3 to the second processor which becomes available at `time = 10`.

The time taken by the first processor to finish the execution of all tasks is `max(8 + 8, 8 + 7, 8 + 4, 8 + 5) = 16`.

The time taken by the second processor to finish the execution of all tasks is `max(10 + 2, 10 + 2, 10 + 3, 10 + 1) = 13`.

**Example 2:**

**Input:** processorTime = [10,20], tasks = [2,3,1,2,5,8,4,3]

**Output:** 23

**Explanation:**

Assign the tasks at indices 1, 4, 5, 6 to the first processor and the others to the second processor.

The time taken by the first processor to finish the execution of all tasks is `max(10 + 3, 10 + 5, 10 + 8, 10 + 4) = 18`.

The time taken by the second processor to finish the execution of all tasks is `max(20 + 2, 20 + 1, 20 + 2, 20 + 3) = 23`.

**Constraints:**

* `1 <= n == processorTime.length <= 25000`
* `1 <= tasks.length <= 105`
* `0 <= processorTime[i] <= 109`
* `1 <= tasks[i] <= 109`
* `tasks.length == 4 * n`

---

## Solution & Editorial
# Intuition
To minimize the overall completion time, we must pair the largest tasks with the processors that become available earliest. Since each processor handles 4 tasks, the completion time for a specific processor is determined by its availability time plus the duration of the longest task assigned to it. By sorting processors in ascending order and tasks in descending order, we ensure that the largest tasks are "absorbed" by the earliest available processors, effectively balancing the load.

# Approach
1. Sort `processorTime` in ascending order. This allows us to iterate through processors from the earliest available to the latest.
2. Sort `tasks` in descending order. This allows us to pick the largest remaining tasks first.
3. Iterate through the `processorTime` array. For each processor at index `i`, assign the four largest available tasks. Since the tasks are sorted descending, the largest task for the current processor will always be at index `4 * i`.
4. Calculate the completion time for each processor as `processorTime[i] + tasks[4 * i]` and track the maximum value found.

### Visual Trace (Example 1)
`processorTime` = [8, 10], `tasks` = [2, 2, 3, 1, 8, 7, 4, 5]
- Sorted `processorTime`: [8, 10]
- Sorted `tasks` (desc): [8, 7, 5, 4, 3, 2, 2, 1]

| Iteration (i) | Processor Time | Task (4*i) | Completion Time | Max (ans) |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 8 | 8 | 8 + 8 = 16 | 16 |
| 1 | 10 | 3 | 10 + 3 = 13 | 16 |

# Complexity
- Time complexity: $$O(N \log N + M \log M)$$, where $$N$$ is the number of processors and $$M$$ is the number of tasks. Sorting both arrays dominates the runtime.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation of `std::sort`).

# Code
```cpp
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.rbegin(),tasks.rend());
        int n = processorTime.size();
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            ans = max(ans,processorTime[i]+tasks[4*i]);
        }

        return ans;
    }
};
```

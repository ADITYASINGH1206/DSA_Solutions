# [1792. Maximum Average Pass Ratio](https://leetcode.com/problems/maximum-average-pass-ratio/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `heap-priority-queue`

---

## Problem Description
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array `classes`, where `classes[i] = [passi, totali]`. You know beforehand that in the `ith` class, there are `totali` total students, but only `passi` number of students will pass the exam.

You are also given an integer `extraStudents`. There are another `extraStudents` brilliant students that are **guaranteed** to pass the exam of any class they are assigned to. You want to assign each of the `extraStudents` students to a class in a way that **maximizes** the **average** pass ratio across **all** the classes.

The **pass ratio** of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The **average pass ratio** is the sum of pass ratios of all the classes divided by the number of the classes.

Return *the **maximum** possible average pass ratio after assigning the* `extraStudents` *students.* Answers within `10-5` of the actual answer will be accepted.

**Example 1:**

```
Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
```

**Example 2:**

```
Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485
```

**Constraints:**

* `1 <= classes.length <= 105`
* `classes[i].length == 2`
* `1 <= passi <= totali <= 105`
* `1 <= extraStudents <= 105`

---

## Solution & Editorial
# Intuition
To maximize the average pass ratio, we must maximize the sum of individual pass ratios. Since each extra student increases the ratio of a specific class, we should always assign the next student to the class that yields the largest *increase* (gain) in its pass ratio. This is a classic greedy problem solvable with a max-priority queue.

# Approach
1. Define a `profit` function that calculates the gain: `(pass + 1) / (total + 1) - pass / total`. This represents the marginal improvement of adding one student to a class.
2. Initialize a max-priority queue storing pairs of `{gain, index}`. Push all initial classes into the heap.
3. For each of the `extraStudents`, extract the class with the highest `gain`, update its `pass` and `total` counts, recalculate its new `gain`, and push it back into the heap.
4. After all students are assigned, compute the sum of `pass / total` for all classes and divide by the number of classes.

### Visual Trace (Example 1: classes = [[1,2],[3,5],[2,2]], extra = 2)
| Iteration | Heap Top (Gain, Index) | Action | New State |
| :--- | :--- | :--- | :--- |
| Initial | (0.166, 0) | - | [[1,2],[3,5],[2,2]] |
| 1 | (0.166, 0) | Add to class 0 | [[2,3],[3,5],[2,2]] |
| 2 | (0.083, 0) | Add to class 0 | [[3,4],[3,5],[2,2]] |

# Complexity
- Time complexity: $$O(N \log N + K \log N)$$, where $$N$$ is the number of classes and $$K$$ is the number of extra students. Building the heap takes $$O(N \log N)$$, and each of the $$K$$ extra students involves a heap pop and push operation, each taking $$O(\log N)$$.
- Space complexity: $$O(N)$$ to store the priority queue containing all classes.

# Code
```cpp
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++) {
            pq.push({profit(classes[i][0], classes[i][1]), i});
        }
        
        for (int i = 0; i < extraStudents; i++) {
            auto [gain, idx] = pq.top();
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            pq.push({profit(classes[idx][0], classes[idx][1]), idx});
        }
        
        double sum = 0;
        for (auto& c : classes) {
            sum += (double)c[0] / c[1];
        }
        
        return sum / classes.size();
    }
};
```

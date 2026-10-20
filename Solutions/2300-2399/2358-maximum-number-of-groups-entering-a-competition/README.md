# [2358. Maximum Number of Groups Entering a Competition](https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `binary-search`, `greedy`

---

## Problem Description
You are given a positive integer array `grades` which represents the grades of students in a university. You would like to enter **all** these students into a competition in **ordered** non-empty groups, such that the ordering meets the following conditions:

* The sum of the grades of students in the `ith` group is **less than** the sum of the grades of students in the `(i + 1)th` group, for all groups (except the last).
* The total number of students in the `ith` group is **less than** the total number of students in the `(i + 1)th` group, for all groups (except the last).

Return *the **maximum** number of groups that can be formed*.

**Example 1:**

```
Input: grades = [10,6,12,7,3,5]
Output: 3
Explanation: The following is a possible way to form 3 groups of students:
- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. Student count: 3
It can be shown that it is not possible to form more than 3 groups.
```

**Example 2:**

```
Input: grades = [8,8]
Output: 1
Explanation: We can only form 1 group, since forming 2 groups would lead to an equal number of students in both groups.
```

**Constraints:**

* `1 <= grades.length <= 105`
* `1 <= grades[i] <= 105`

---

## Solution & Editorial
# Intuition
To maximize the number of groups, we should make each group as small as possible. Since the number of students in each group must be strictly increasing, the smallest possible sequence of group sizes is 1, 2, 3, ..., k. The sum of these sizes must be less than or equal to the total number of students, $n$. Because the grades are positive, we can always arrange the students to satisfy the sum condition if the count condition is met.

# Approach
1. We aim to find the largest integer $k$ such that the sum of the first $k$ natural numbers is less than or equal to $n$ (where $n$ is the length of `grades`).
2. The sum of the first $k$ integers is given by $\frac{k(k+1)}{2}$. We solve for $k$ in $\frac{k(k+1)}{2} \le n$.
3. In the code, we maintain a running `total` of students used and a counter `k` representing the current group size. In each iteration, we increment `k` and check if `total + k <= n`. If it is, we add `k` to `total` and increment our group count.

### Visual Trace (Example 1: n = 6)
| Iteration | k (next group size) | total (used students) | Condition (total + k <= 6) | Result |
|-----------|---------------------|-----------------------|----------------------------|--------|
| 1         | 1                   | 1                     | 1 <= 6 (True)              | k=1    |
| 2         | 2                   | 3                     | 3 <= 6 (True)              | k=2    |
| 3         | 3                   | 6                     | 6 <= 6 (True)              | k=3    |
| 4         | 4                   | 10                    | 10 <= 6 (False)            | Stop   |

# Complexity
- Time complexity: $$O(\sqrt{N})$$ — The loop runs until $\frac{k(k+1)}{2} \approx N$, which implies $k \approx \sqrt{2N}$.
- Space complexity: $$O(1)$$ — We only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int k = 0, total = 0, n = grades.size();
        while (total + k + 1 <= n)
            total += ++k;
        return k;
    }
};
```

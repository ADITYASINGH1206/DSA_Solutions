# [2037. Minimum Number of Moves to Seat Everyone](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `sorting`, `counting-sort`

---

## Problem Description
There are `n` **availabe** seats and `n` students **standing** in a room. You are given an array `seats` of length `n`, where `seats[i]` is the position of the `ith` seat. You are also given the array `students` of length `n`, where `students[j]` is the position of the `jth` student.

You may perform the following move any number of times:

* Increase or decrease the position of the `ith` student by `1` (i.e., moving the `ith` student from position `x` to `x + 1` or `x - 1`)

Return *the **minimum number of moves** required to move each student to a seat* *such that no two students are in the same seat.*

Note that there may be **multiple** seats or students in the **same** position at the beginning.

**Example 1:**

```
Input: seats = [3,1,5], students = [2,7,4]
Output: 4
Explanation: The students are moved as follows:
- The first student is moved from position 2 to position 1 using 1 move.
- The second student is moved from position 7 to position 5 using 2 moves.
- The third student is moved from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
```

**Example 2:**

```
Input: seats = [4,1,5,9], students = [1,3,2,6]
Output: 7
Explanation: The students are moved as follows:
- The first student is not moved.
- The second student is moved from position 3 to position 4 using 1 move.
- The third student is moved from position 2 to position 5 using 3 moves.
- The fourth student is moved from position 6 to position 9 using 3 moves.
In total, 0 + 1 + 3 + 3 = 7 moves were used.
```

**Example 3:**

```
Input: seats = [2,2,6,6], students = [1,3,2,6]
Output: 4
Explanation: Note that there are two seats at position 2 and two seats at position 6.
The students are moved as follows:
- The first student is moved from position 1 to position 2 using 1 move.
- The second student is moved from position 3 to position 6 using 3 moves.
- The third student is not moved.
- The fourth student is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.
```

**Constraints:**

* `n == seats.length == students.length`
* `1 <= n <= 100`
* `1 <= seats[i], students[j] <= 100`

---

## Solution & Editorial
# Intuition
To minimize the total distance moved by all students, we should pair the student at the smallest position with the seat at the smallest position, the second smallest student with the second smallest seat, and so on. This greedy strategy works because the absolute difference function is convex, and sorting both arrays ensures that the crossing of paths is minimized.

# Approach
1. Sort both the `seats` and `students` arrays in non-decreasing order. This aligns the smallest available seat with the leftmost student.
2. Initialize a variable `ans` to 0 to accumulate the total moves.
3. Iterate through the sorted arrays using an index `i` from 0 to `n-1`.
4. For each index, calculate the absolute difference `abs(seats[i] - students[i])` and add it to `ans`.
5. Return `ans`.

### Visual Trace (Example 1: seats = [3,1,5], students = [2,7,4])
- Sorted `seats`: [1, 3, 5]
- Sorted `students`: [2, 4, 7]

| Iteration | Seat | Student | Diff | Total (ans) |
|-----------|------|---------|------|-------------|
| 0         | 1    | 2       | 1    | 1           |
| 1         | 3    | 4       | 1    | 2           |
| 2         | 5    | 7       | 2    | 4           |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of seats/students, due to the sorting of both arrays. The subsequent linear pass takes $$O(N)$$.
- Space complexity: $$O(1)$$ or $$O(\log N)$$ depending on the implementation of `std::sort` (stack space for recursion), as we perform the operations in-place.

# Code
```cpp
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i < seats.size(); ++i) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};
```

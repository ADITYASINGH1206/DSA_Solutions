# [1700. Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/)
**Difficulty:** `Easy` | **Tags:** `array`, `stack`, `queue`, `simulation`

---

## Problem Description
The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers `0` and `1` respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a **stack**. At each step:

* If the student at the front of the queue **prefers** the sandwich on the top of the stack, they will **take it** and leave the queue.
* Otherwise, they will **leave it** and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays `students` and `sandwiches` where `sandwiches[i]` is the type of the `i​​​​​​th` sandwich in the stack (`i = 0` is the top of the stack) and `students[j]` is the preference of the `j​​​​​​th` student in the initial queue (`j = 0` is the front of the queue). Return *the number of students that are unable to eat.*

**Example 1:**

```
Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0 
Explanation:
- Front student leaves the top sandwich and returns to the end of the line making students = [1,0,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,0,1,1].
- Front student takes the top sandwich and leaves the line making students = [0,1,1] and sandwiches = [1,0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [1,1,0].
- Front student takes the top sandwich and leaves the line making students = [1,0] and sandwiches = [0,1].
- Front student leaves the top sandwich and returns to the end of the line making students = [0,1].
- Front student takes the top sandwich and leaves the line making students = [1] and sandwiches = [1].
- Front student takes the top sandwich and leaves the line making students = [] and sandwiches = [].
Hence all students are able to eat.
```

**Example 2:**

```
Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3
```

**Constraints:**

* `1 <= students.length, sandwiches.length <= 100`
* `students.length == sandwiches.length`
* `sandwiches[i]` is `0` or `1`.
* `students[i]` is `0` or `1`.

---

## Solution & Editorial
# Intuition
Since the students can cycle through the queue indefinitely until they find a sandwich they like, the order of students in the queue does not actually matter. What matters is the total count of students who prefer circular (0) sandwiches versus square (1) sandwiches. We can simply consume the stack of sandwiches one by one as long as there is at least one student remaining who prefers that specific type.

# Approach
1. Count the number of students who prefer circular sandwiches (0) and square sandwiches (1) using a frequency array `counts`.
2. Iterate through the `sandwiches` array. For each sandwich `s`:
   - Check if there are any students left who prefer this type (`counts[s] > 0`).
   - If yes, decrement the count of that student type and decrement the total number of students remaining (`ans`).
   - If no, it means no remaining student wants the current sandwich, so we stop and return the remaining count.

### Visual Trace (Example 1: students = [1,1,0,0], sandwiches = [0,1,0,1])
- Initial: `counts = {0: 2, 1: 2}`, `ans = 4`
- Sandwich `0`: `counts[0] > 0` (2 > 0). `counts[0]` becomes 1, `ans` becomes 3.
- Sandwich `1`: `counts[1] > 0` (2 > 0). `counts[1]` becomes 1, `ans` becomes 2.
- Sandwich `0`: `counts[0] > 0` (1 > 0). `counts[0]` becomes 0, `ans` becomes 1.
- Sandwich `1`: `counts[1] > 0` (1 > 0). `counts[1]` becomes 0, `ans` becomes 0.
- Result: 0.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of students. We iterate through the students once to count preferences and through the sandwiches once.
- Space complexity: $$O(1)$$, as the `counts` vector is of fixed size 2 regardless of input size.

# Code
```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2, 0);
        for (int student : students)
            counts[student]++;

        int ans = sandwiches.size();
        for (int s : sandwiches) {
            if (counts[s] == 0)
                break;
            if (ans == 0)
                break;
            counts[s]--;
            ans--;
        }

        return ans;
    }
};
```

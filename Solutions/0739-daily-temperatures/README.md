# [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `monotonic-stack`

---

## Problem Description
Given an array of integers `temperatures` represents the daily temperatures, return *an array* `answer` *such that* `answer[i]` *is the number of days you have to wait after the* `ith` *day to get a warmer temperature*. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

**Example 1:**

```
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
```

**Example 2:**

```
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
```

**Example 3:**

```
Input: temperatures = [30,60,90]
Output: [1,1,0]
```

**Constraints:**

* `1 <= temperatures.length <= 105`
* `30 <= temperatures[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem requires us to find the distance to the next strictly greater element for each index in an array. By processing the elements from right to left using a monotonic decreasing stack, we can efficiently maintain indices of temperatures that are potential warmer future days without repeatedly scanning ahead.

# Approach
1. Initialize an integer `n` as the size of the `temperatures` array and an `ans` vector of size `n` filled with zeros. Also, declare a stack `stk` to store indices of temperatures.
2. Iterate backwards from `i = n - 1` down to `0`.
3. While the stack is not empty and the current temperature `temperatures[i]` is greater than or equal to the temperature at the index stored at the top of the stack (`temperatures[stk.top()]`), pop elements from the stack. This removes days that are colder or equal, as they can never be the next warmer day for `i` or any preceding day.
4. After pruning the stack, if `stk` is not empty, the next warmer day's index is `stk.top()`, so set `ans[i] = stk.top() - i`. If the stack is empty, no warmer day exists to the right, so `ans[i] = 0`.
5. Push the current index `i` onto the stack and continue the loop.
6. Return the `ans` vector.

### Visual Trace (Example 1: temperatures = [73, 74, 75, 71, 69, 72, 76, 73])
- `i = 7`, `temp = 73`: Stack empty -> `ans[7] = 0`, Push 7. Stack: `[7]`
- `i = 6`, `temp = 76`: 76 >= 73 (pop 7). Stack empty -> `ans[6] = 0`, Push 6. Stack: `[6]`
- `i = 5`, `temp = 72`: 72 < 76. Top is 6 -> `ans[5] = 6 - 5 = 1`, Push 5. Stack: `[6, 5]`
- `i = 4`, `temp = 69`: 69 < 72. Top is 5 -> `ans[4] = 5 - 4 = 1`, Push 4. Stack: `[6, 5, 4]`
- `i = 3`, `temp = 71`: 71 >= 69 (pop 4). 71 < 72. Top is 5 -> `ans[3] = 5 - 3 = 2`, Push 3. Stack: `[6, 5, 3]`
- `i = 2`, `temp = 75`: 75 >= 71 (pop 3), 75 >= 72 (pop 5), 75 < 76. Top is 6 -> `ans[2] = 6 - 2 = 4`, Push 2. Stack: `[6, 2]`
- `i = 1`, `temp = 74`: 74 < 75. Top is 2 -> `ans[1] = 2 - 1 = 1`, Push 1. Stack: `[6, 2, 1]`
- `i = 0`, `temp = 73`: 73 < 74. Top is 1 -> `ans[0] = 1 - 0 = 1`, Push 0. Stack: `[6, 2, 1, 0]`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in `temperatures`. Each index is pushed onto the stack exactly once and popped at most once, making the total number of stack operations linear.
- Space complexity: $$O(N)$$ for the output vector `ans` and the auxiliary stack `stk` which can store at most $$N$$ indices in the worst-case scenario (strictly decreasing temperatures).

# Code
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> stk;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()]){
                stk.pop();
            }
            if(!stk.empty()) ans[i] = stk.top()- i;
            else ans[i] = 0;
            stk.push(i);
        }
        return ans;
    }
};
```

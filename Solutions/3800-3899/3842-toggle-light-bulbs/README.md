# [3842. Toggle Light Bulbs](https://leetcode.com/problems/toggle-light-bulbs/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`, `simulation`

---

## Problem Description
You are given an array `bulbs` of integers between 1 and 100.

There are 100 light bulbs numbered from 1 to 100. All of them are switched off initially.

For each element `bulbs[i]` in the array `bulbs`:

* If the `bulbs[i]th` light bulb is currently off, switch it on.
* Otherwise, switch it off.

Return the list of integers denoting the light bulbs that are on in the end, **sorted** in **ascending** order. If no bulb is on, return an empty list.

**Example 1:**

**Input:** bulbs = [10,30,20,10]

**Output:** [20,30]

**Explanation:**

* The `bulbs[0] = 10th` light bulb is currently off. We switch it on.
* The `bulbs[1] = 30th` light bulb is currently off. We switch it on.
* The `bulbs[2] = 20th` light bulb is currently off. We switch it on.
* The `bulbs[3] = 10th` light bulb is currently on. We switch it off.
* In the end, the 20th and the 30th light bulbs are on.

**Example 2:**

**Input:** bulbs = [100,100]

**Output:** []

**Explanation:**

* The `bulbs[0] = 100th` light bulb is currently off. We switch it on.
* The `bulbs[1] = 100th` light bulb is currently on. We switch it off.
* In the end, no light bulb is on.

**Constraints:**

* `1 <= bulbs.length <= 100`
* `1 <= bulbs[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem asks us to track the state of 100 light bulbs based on a sequence of toggle operations. Since the number of bulbs is small and fixed (1 to 100), we can use a boolean array to represent the state of each bulb, where `true` indicates the bulb is on and `false` indicates it is off.

# Approach
1. Initialize a boolean array `isOn` of size 101 with all values set to `false`.
2. Iterate through the input `bulbs` array. For each bulb index `b`, toggle its state using the NOT operator: `isOn[b] = !isOn[b]`.
3. After processing all toggles, iterate from 1 to 100. If `isOn[i]` is `true`, add the index `i` to the `result` vector.

### Visual Trace (Example 1: [10, 30, 20, 10])
| Step | Operation | isOn[10] | isOn[20] | isOn[30] | Others |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | F | F | F | F |
| 1 | Toggle 10 | T | F | F | F |
| 2 | Toggle 30 | T | F | T | F |
| 3 | Toggle 20 | T | T | T | F |
| 4 | Toggle 10 | F | T | T | F |

Final state: `isOn[20]` and `isOn[30]` are true. Result: `[20, 30]`.

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the number of operations in `bulbs` and $$M$$ is the number of bulbs (100). We iterate through the input once and then iterate through the fixed-size bulb array.
- Space complexity: $$O(M)$$, where $$M=100$$, to store the state of the bulbs in the boolean array.

# Code
```cpp
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        bool isOn[101] = {false}; 
        for (int b : bulbs) {
            isOn[b] = !isOn[b];
        }
        
        vector<int> result;
        for (int i = 1; i <= 100; ++i) {
            if (isOn[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
```

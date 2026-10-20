# [1051. Height Checker](https://leetcode.com/problems/height-checker/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`, `counting-sort`, `bubble-sort`

---

## Problem Description
A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in **non-decreasing order** by height. Let this ordering be represented by the integer array `expected` where `expected[i]` is the expected height of the `ith` student in line.

You are given an integer array `heights` representing the **current order** that the students are standing in. Each `heights[i]` is the height of the `ith` student in line (**0-indexed**).

Return *the **number of indices** where* `heights[i] != expected[i]`.

**Example 1:**

```
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
```

**Example 2:**

```
Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
```

**Example 3:**

```
Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
```

**Constraints:**

* `1 <= heights.length <= 100`
* `1 <= heights[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem requires us to compare the current standing order of students against their sorted non-decreasing order and count how many positions differ. Since we need the sorted arrangement, we can simply duplicate the original array, sort the copy, and perform a linear scan to count discrepancies.

# Approach
1. Copy the input vector `heights` into a new vector `expected` to preserve the original student arrangement.
2. Sort the `expected` vector in non-decreasing order using `std::sort`.
3. Initialize a counter `ans` to 0.
4. Iterate through each index `i` from `0` to `heights.size() - 1` and increment `ans` if `heights[i] != expected[i]`.
5. Return `ans` as the final mismatch count.

### Visual Trace Walkthrough (Example 1)
Input: `heights = [1, 1, 4, 2, 1, 3]`
- `expected = [1, 1, 4, 2, 1, 3]`
- After sorting: `expected = [1, 1, 1, 2, 3, 4]`

| Index `i` | `heights[i]` | `expected[i]` | Match? | `ans` |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 1 | 1 | Yes | 0 |
| 1 | 1 | 1 | Yes | 0 |
| 2 | 4 | 1 | No | 1 |
| 3 | 2 | 2 | Yes | 1 |
| 4 | 1 | 3 | No | 2 |
| 5 | 3 | 4 | No | 3 |

Final Output: `3`

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of elements in `heights`. Copying the array takes $$O(N)$$ time, sorting takes $$O(N \log N)$$ time, and the final linear scan takes $$O(N)$$ time.
- Space complexity: $$O(N)$$ auxiliary space required to store the duplicate `expected` vector.

# Code
```cpp
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            ans += heights[i] != expected[i];
        }
        return ans;
    }
};
```

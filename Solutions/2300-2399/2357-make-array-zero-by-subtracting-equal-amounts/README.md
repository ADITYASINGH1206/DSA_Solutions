# [2357. Make Array Zero by Subtracting Equal Amounts](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `greedy`, `sorting`, `heap-priority-queue`, `simulation`

---

## Problem Description
You are given a non-negative integer array `nums`. In one operation, you must:

* Choose a positive integer `x` such that `x` is less than or equal to the **smallest non-zero** element in `nums`.
* Subtract `x` from every **positive** element in `nums`.

Return *the **minimum** number of operations to make every element in* `nums` *equal to* `0`.

**Example 1:**

```
Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
```

**Example 2:**

```
Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
Each operation effectively reduces the smallest non-zero value in the array to zero. Since we subtract the same value $x$ from all positive elements, every unique positive integer in the array will eventually be reduced to zero in its own distinct step. Therefore, the problem reduces to counting the number of unique positive integers present in the input array.

# Approach
1. Insert all elements of the input vector `nums` into an `unordered_set<int>`. This automatically filters out duplicates and keeps only unique values.
2. The number of operations required is equal to the number of unique positive integers in the set.
3. If the set contains `0`, we subtract 1 from the total size of the set, as `0` does not require an operation.

### Visual Trace (Example 1: [1, 5, 0, 3, 5])
| Step | Action | State | Result |
| :--- | :--- | :--- | :--- |
| 1 | Insert into set | {0, 1, 3, 5} | Size = 4 |
| 2 | Check for 0 | 0 exists | Count = 4 - 1 = 3 |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the input array. We iterate through the array once to populate the hash set, and set operations (insertion/lookup) are $O(1)$ on average.
- Space complexity: $$O(N)$$, as in the worst case (all elements unique and non-zero), the hash set will store $N$ elements.

# Code
```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() - s.count(0);
    }
};
```

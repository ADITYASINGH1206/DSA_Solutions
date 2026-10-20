# [3074. Apple Redistribution into Boxes](https://leetcode.com/problems/apple-redistribution-into-boxes/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given an array `apple` of size `n` and an array `capacity` of size `m`.

There are `n` packs where the `ith` pack contains `apple[i]` apples. There are `m` boxes as well, and the `ith` box has a capacity of `capacity[i]` apples.

Return *the **minimum** number of boxes you need to select to redistribute these* `n` *packs of apples into boxes*.

**Note** that, apples from the same pack can be distributed into different boxes.

**Example 1:**

```
Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
```

**Example 2:**

```
Input: apple = [5,5,5], capacity = [2,4,2,7]
Output: 4
Explanation: We will need to use all the boxes.
```

**Constraints:**

* `1 <= n == apple.length <= 50`
* `1 <= m == capacity.length <= 50`
* `1 <= apple[i], capacity[i] <= 50`
* The input is generated such that it's possible to redistribute packs of apples into boxes.

---

## Solution & Editorial
# Intuition
To minimize the number of boxes used, we must prioritize boxes with the largest capacities. By filling the largest available boxes first, we satisfy the total apple requirement using the fewest number of containers.

# Approach
1. Calculate the `total` number of apples by summing all elements in the `apple` vector.
2. Sort the `capacity` vector in descending order to ensure we always pick the largest available box.
3. Iterate through the sorted `capacity` array, subtracting the capacity of each box from `total` until `total` becomes less than or equal to zero.
4. Maintain a counter `ans` to track how many boxes were used.

### Visual Trace (Example 1: apple = [1,3,2], capacity = [4,3,1,5,2])
- `total` = 1 + 3 + 2 = 6
- Sorted `capacity` = [5, 4, 3, 2, 1]

| Iteration | Box Capacity | Remaining `total` | `ans` |
|-----------|--------------|-------------------|-------|
| 1         | 5            | 6 - 5 = 1         | 1     |
| 2         | 4            | 1 - 4 = -3        | 2     |

- Loop terminates as `total` <= 0. Return `ans` = 2.

# Complexity
- Time complexity: $$O(M \log M)$$, where $$M$$ is the number of boxes. This is dominated by the sorting of the `capacity` array. The summation of apples takes $$O(N)$$, and the greedy selection loop takes $$O(M)$$.
- Space complexity: $$O(1)$$ (or $$O(\log M)$$ depending on the sorting implementation's stack usage), as we perform the operation in-place on the input vector or use minimal auxiliary variables.

# Code
```cpp
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.rbegin(),capacity.rend());
        int ans = 0;
        int n = apple.size();
        int m = capacity.size();
        while(total>0){
            total -= capacity[ans++];
        }

        return ans;
    }
};
```

# [2913. Subarrays Distinct Element Sum of Squares I](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `binary-indexed-tree`, `segment-tree`

---

## Problem Description
You are given a **0-indexed** integer array `nums`.

The **distinct count** of a subarray of `nums` is defined as:

* Let `nums[i..j]` be a subarray of `nums` consisting of all the indices from `i` to `j` such that `0 <= i <= j < nums.length`. Then the number of distinct values in `nums[i..j]` is called the distinct count of `nums[i..j]`.

Return *the sum of the **squares** of **distinct counts** of all subarrays of* `nums`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
```

**Example 2:**

```
Input: nums = [1,1]
Output: 3
Explanation: Three possible subarrays are:
[1]: 1 distinct value
[1]: 1 distinct value
[1,1]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
Since the constraints are small ($N \le 100$), we can iterate through all possible subarrays and count the distinct elements in each. The sum of squares of these counts will yield the final result.

# Approach
1. Use a nested loop structure: the outer loop `i` marks the start of the subarray, and the inner loop `j` marks the end.
2. For each starting position `i`, initialize a boolean array `dis` of size 101 (since $nums[i] \le 100$) to track unique elements encountered in the current subarray.
3. Maintain a `count` variable that increments only when a new element (not seen in the current `dis` set) is encountered.
4. For every subarray `nums[i..j]`, add `count * count` to the running total `ans`.

### Visual Trace (nums = [1, 2, 1])
| i | j | Subarray | Distinct Count | ans (running) |
|---|---|---|---|---|
| 0 | 0 | [1] | 1 | 1 |
| 0 | 1 | [1, 2] | 2 | 1 + 4 = 5 |
| 0 | 2 | [1, 2, 1] | 2 | 5 + 4 = 9 |
| 1 | 1 | [2] | 1 | 9 + 1 = 10 |
| 1 | 2 | [2, 1] | 2 | 10 + 4 = 14 |
| 2 | 2 | [1] | 1 | 14 + 1 = 15 |

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the length of the array. We iterate through all $N(N+1)/2$ subarrays, performing constant time operations for each.
- Space complexity: $$O(1)$$ (or $O(K)$ where $K=100$ is the range of values) as the boolean array size is fixed regardless of input size.

# Code
```cpp
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            vector<bool> dis(101,false);
            int count = 0;
            for(int j = i;j<n;j++){
                if(!dis[nums[j]]){
                    count++;
                    dis[nums[j]] = true;
                }
                ans += count*count;
            }
        }
        return ans;
    }
};
```

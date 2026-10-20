# [3289. The Two Sneaky Numbers of Digitville](https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `math`

---

## Problem Description
In the town of Digitville, there was a list of numbers called `nums` containing integers from `0` to `n - 1`. Each number was supposed to appear **exactly once** in the list, however, **two** mischievous numbers sneaked in an *additional time*, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an array of size **two** containing the two numbers (in *any order*), so peace can return to Digitville.

**Example 1:**

**Input:** nums = [0,1,1,0]

**Output:** [0,1]

**Explanation:**

The numbers 0 and 1 each appear twice in the array.

**Example 2:**

**Input:** nums = [0,3,2,1,3,2]

**Output:** [2,3]

**Explanation:**

The numbers 2 and 3 each appear twice in the array.

**Example 3:**

**Input:** nums = [7,1,5,4,3,4,6,0,9,5,8,2]

**Output:** [4,5]

**Explanation:**

The numbers 4 and 5 each appear twice in the array.

**Constraints:**

* `2 <= n <= 100`
* `nums.length == n + 2`
* `0 <= nums[i] < n`
* The input is generated such that `nums` contains **exactly** two repeated elements.

---

## Solution & Editorial
# Intuition
Since the constraints are small (n <= 100) and the values are bounded by [0, n-1], we can track the occurrence of each number using a frequency array. A number is identified as "sneaky" the moment its count reaches two.

# Approach
1. Initialize a frequency array `freq` of size 100 (covering the maximum possible value of n) with zeros.
2. Iterate through the input vector `nums`.
3. For each element `x`, increment `freq[x]`.
4. If `freq[x]` becomes exactly 2, append `x` to the result vector `ans`.
5. Return `ans` once the iteration is complete.

### Visual Trace (Example 1: nums = [0, 1, 1, 0])
| Iteration | Current `x` | `freq` state (indices 0, 1) | `ans` |
|-----------|-------------|-----------------------------|-------|
| 1         | 0           | [1, 0]                      | []    |
| 2         | 1           | [1, 1]                      | []    |
| 3         | 1           | [1, 2]                      | [1]   |
| 4         | 0           | [2, 2]                      | [1, 0]|

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input array. We perform a single pass over the input.
- Space complexity: $$O(1)$$, as the frequency array has a fixed size of 100, which is independent of the input size $$N$$.

# Code
```cpp
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int>freq(100,0);
        for(int x:nums){
            if(++freq[x] == 2){
                ans.push_back(x);
            }
        }
        return ans;

    }
};
```

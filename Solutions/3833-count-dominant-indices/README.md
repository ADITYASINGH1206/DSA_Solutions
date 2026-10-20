# [3833. Count Dominant Indices](https://leetcode.com/problems/count-dominant-indices/)
**Difficulty:** `Easy` | **Tags:** `array`, `enumeration`

---

## Problem Description
You are given an integer array `nums` of length `n`.

An element at index `i` is called **dominant** if: `nums[i] > average(nums[i + 1], nums[i + 2], ..., nums[n - 1])`

Your task is to count the number of indices `i` that are **dominant**.

The **average** of a set of numbers is the value obtained by adding all the numbers together and dividing the sum by the total number of numbers.

**Note**: The **rightmost** element of any array is **not** **dominant**.

**Example 1:**

**Input:** nums = [5,4,3]

**Output:** 2

**Explanation:**

* At index `i = 0`, the value 5 is dominant as `5 > average(4, 3) = 3.5`.
* At index `i = 1`, the value 4 is dominant over the subarray `[3]`.
* Index `i = 2` is not dominant as there are no elements to its right. Thus, the answer is 2.

**Example 2:**

**Input:** nums = [4,1,2]

**Output:** 1

**Explanation:**

* At index `i = 0`, the value 4 is dominant over the subarray `[1, 2]`.
* At index `i = 1`, the value 1 is not dominant.
* Index `i = 2` is not dominant as there are no elements to its right. Thus, the answer is 1.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`​​​​​​​

---

## Solution & Editorial
# Intuition
To determine if an element at index `i` is dominant, we need to compare `nums[i]` against the average of all elements to its right. Instead of recalculating the sum of the suffix for every index (which would be $O(N^2)$), we can maintain a running suffix sum and count of elements to the right as we iterate backwards from the second-to-last element.

# Approach
1. Initialize `sum` with the value of the last element and `count` as 1 (representing the number of elements to the right of the current index).
2. Iterate backwards from `i = n - 2` down to `0`.
3. For each index `i`, check if `nums[i] > sum / count`. To avoid floating-point division, rewrite this as `nums[i] * count > sum`.
4. If the condition holds, increment the `ans` counter.
5. Update `sum` by adding `nums[i]` and increment `count` to include the current element for the next iteration.

### Visual Trace (nums = [5, 4, 3])
| i | nums[i] | sum (before) | count (before) | Condition (nums[i] * count > sum) | Result |
|---|---|---|---|---|---|
| 1 | 4 | 3 | 1 | 4 * 1 > 3 (True) | ans = 1 |
| 0 | 5 | 7 | 2 | 5 * 2 > 7 (True) | ans = 2 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass from right to left.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;

        int ans = 0;
        int sum = nums[n-1];
        int count = 1;
        
        for(int i =n-2;i>=0;i--){
            if(nums[i] * count >  sum){
                ans++;
            }
            sum+= nums[i];
            count++;
        }
        return ans;
        
    }
};
```

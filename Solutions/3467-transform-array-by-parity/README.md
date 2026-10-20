# [3467. Transform Array by Parity](https://leetcode.com/problems/transform-array-by-parity/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`, `counting`

---

## Problem Description
You are given an integer array `nums`. Transform `nums` by performing the following operations in the **exact** order specified:

1. Replace each even number with 0.
2. Replace each odd numbers with 1.
3. Sort the modified array in **non-decreasing** order.

Return the resulting array after performing these operations.

**Example 1:**

**Input:** nums = [4,3,2,1]

**Output:** [0,0,1,1]

**Explanation:**

* Replace the even numbers (4 and 2) with 0 and the odd numbers (3 and 1) with 1. Now, `nums = [0, 1, 0, 1]`.
* After sorting `nums` in non-descending order, `nums = [0, 0, 1, 1]`.

**Example 2:**

**Input:** nums = [1,5,1,4,2]

**Output:** [0,0,1,1,1]

**Explanation:**

* Replace the even numbers (4 and 2) with 0 and the odd numbers (1, 5 and 1) with 1. Now, `nums = [1, 1, 1, 0, 0]`.
* After sorting `nums` in non-descending order, `nums = [0, 0, 1, 1, 1]`.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
Since the transformation maps every number to either 0 (if even) or 1 (if odd), the resulting array will only contain 0s and 1s. Sorting a binary array is equivalent to counting the occurrences of 0s and 1s and placing all 0s before all 1s.

# Approach
1. Iterate through the input `nums` to count the number of even integers. Each even integer corresponds to a 0 in the final array.
2. Create a result vector `ans` and fill it with the count of 0s.
3. Fill the remainder of the `ans` vector with 1s, representing the odd integers.
4. This effectively sorts the array in non-decreasing order without needing an explicit $O(N \log N)$ sorting algorithm.

### Visual Trace (Example 1: [4, 3, 2, 1])
| Step | Action | State of `ans` |
| :--- | :--- | :--- |
| 1 | Process 4 (even) | [0] |
| 2 | Process 3 (odd) | [0] |
| 3 | Process 2 (even) | [0, 0] |
| 4 | Process 1 (odd) | [0, 0] |
| 5 | Fill remaining with 1s | [0, 0, 1, 1] |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of the input array. We iterate through the array once to identify even numbers and then fill the result vector.
- Space complexity: $$O(N)$$ to store the resulting transformed array.

# Code
```cpp
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int>ans;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans.push_back(0);
            }
        }
        for(int i =ans.size();i<nums.size();i++){
            ans.push_back(1);
        }
        return ans;
    }
};
```

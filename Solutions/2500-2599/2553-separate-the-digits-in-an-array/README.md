# [2553. Separate the Digits in an Array](https://leetcode.com/problems/separate-the-digits-in-an-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `simulation`

---

## Problem Description
Given an array of positive integers `nums`, return *an array* `answer` *that consists of the digits of each integer in* `nums` *after separating them in **the same order** they appear in* `nums`.

To separate the digits of an integer is to get all the digits it has in the same order.

* For example, for the integer `10921`, the separation of its digits is `[1,0,9,2,1]`.

**Example 1:**

```
Input: nums = [13,25,83,77]
Output: [1,3,2,5,8,3,7,7]
Explanation: 
- The separation of 13 is [1,3].
- The separation of 25 is [2,5].
- The separation of 83 is [8,3].
- The separation of 77 is [7,7].
answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations in the same order.
```

**Example 2:**

```
Input: nums = [7,1,3,9]
Output: [7,1,3,9]
Explanation: The separation of each integer in nums is itself.
answer = [7,1,3,9].
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To separate the digits of each integer while maintaining their original order, we can treat each integer as a sequence of characters. By converting each integer to its string representation, we can easily iterate through its individual digits and append them to our result array.

# Approach
1. Initialize an empty vector `ans` to store the final sequence of digits.
2. Iterate through each integer `num` in the input vector `nums`.
3. Convert the current integer `num` to a string using `to_string(num)`.
4. Iterate through each character `c` in the resulting string. Convert the character back to its integer value by subtracting the ASCII value of '0' (`c - '0'`) and append it to `ans`.
5. Return the `ans` vector.

### Visual Trace (Example 1: nums = [13, 25])
| Step | num | String | Digits Added | ans (State) |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 13 | "13" | 1, 3 | [1, 3] |
| 2 | 25 | "25" | 2, 5 | [1, 3, 2, 5] |

# Complexity
- Time complexity: $$O(N \cdot D)$$, where $$N$$ is the number of elements in `nums` and $$D$$ is the average number of digits per integer (at most 6 for $10^5$). We iterate through each number and then through each of its digits.
- Space complexity: $$O(N \cdot D)$$, as we store all digits in the `ans` vector.

# Code
```cpp
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            string temp = to_string(num);
            for(char c: temp){
                ans.push_back(c-'0');
            }
        }
        return ans;
    }
};
```

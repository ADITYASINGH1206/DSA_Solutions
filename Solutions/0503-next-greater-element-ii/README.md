# [503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `monotonic-stack`

---

## Problem Description
Given a circular integer array `nums` (i.e., the next element of `nums[nums.length - 1]` is `nums[0]`), return *the **next greater number** for every element in* `nums`.

The **next greater number** of a number `x` is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return `-1` for this number.

**Example 1:**

```
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
```

**Example 2:**

```
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
```

**Constraints:**

* `1 <= nums.length <= 104`
* `-109 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
The problem asks us to find the next greater element in a circular array. Since the array is circular, any element can look ahead to the right and wrap around to the beginning. We can handle this circularity by conceptually duplicating the array or by iterating twice from right to left using a monotonic stack to maintain potential next greater elements.

# Approach
1. Initialize a stack `stk` to store array elements in a monotonically decreasing order from top to bottom, and a result vector `ans` of size `n` initialized to zero.
2. First pass: iterate from right to left ($i = n - 1$ down to $0$). Pop elements from `stk` that are less than or equal to `nums[i]`, then push `nums[i]` onto `stk`. This seeds the stack with the largest elements from the right tail of the array so that the subsequent pass can correctly resolve the circular lookahead.
3. Second pass: iterate again from right to left ($i = n - 1$ down to $0$). Pop elements from `stk` smaller than or equal to `nums[i]`. If the stack is not empty, the top element is the next greater element for `nums[i]`, so assign `ans[i] = stk.top()`; otherwise, assign `ans[i] = -1`. Then push `nums[i]` onto `stk`.
4. Return the computed `ans` vector.

### Visual Trace Walkthrough (Example 1: nums = [1, 2, 1])
- **Pass 1 (Seeding Stack)**:
  - $i = 2$, nums[2] = 1: Stack: [1]
  - $i = 1$, nums[1] = 2: Pop 1, Push 2. Stack: [2]
  - $i = 0$, nums[0] = 1: Push 1. Stack: [2, 1]
- **Pass 2 (Query & Update)**:
  - $i = 2$, nums[2] = 1: Top is 2 ($\le 1$ is false). ans[2] = 2. Push 1. Stack: [2, 1]
  - $i = 1$, nums[1] = 2: Pop 1. Top is 2 ($2 \le 2$ is true -> pop 2). Stack empty. ans[1] = -1. Push 2. Stack: [2]
  - $i = 0$, nums[0] = 1: Top is 2 ($2 \le 1$ is false). ans[0] = 2. Push 1. Stack: [2, 1]
- **Result**: `[2, -1, 2]`

# Complexity
- Time complexity: $$O(N)$$ — Each element is pushed and popped from the stack at most twice across the two passes, resulting in linear time complexity with respect to the array size $$N$$.
- Space complexity: $$O(N)$$ — The stack and the answer vector each consume up to $$O(N)$$ auxiliary space in the worst case.

# Code
```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> stk;
        int n = nums.size();
        vector<int> ans(n);
        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            stk.push(nums[i]);
        }
        for(int i = n-1;i>-1;i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top();
            }else{
                ans[i] = -1;
            }
            stk.push(nums[i]);
        }
        return ans;
    }
};
```

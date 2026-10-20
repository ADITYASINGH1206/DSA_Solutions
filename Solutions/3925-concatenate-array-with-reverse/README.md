# [3925. Concatenate Array With Reverse](https://leetcode.com/problems/concatenate-array-with-reverse/)
**Difficulty:** `Easy` | **Tags:** `array`, `simulation`

---

## Problem Description
You are given an integer array `nums` of length `n`.

Construct a new array `ans` of length `2 * n` such that the first `n` elements are the same as `nums`, and the next `n` elements are the elements of `nums` in reverse order.

Formally, for `0 <= i <= n - 1`:

* `ans[i] = nums[i]`
* `ans[i + n] = nums[n - i - 1]`

Return an integer array `ans`.

**Example 1:**

**Input:** nums = [1,2,3]

**Output:** [1,2,3,3,2,1]

**Explanation:**

The first `n` elements of `ans` are the same as `nums`.

For the next `n = 3` elements, each element is taken from `nums` in reverse order:

* `ans[3] = nums[2] = 3`
* `ans[4] = nums[1] = 2`
* `ans[5] = nums[0] = 1`

Thus, `ans = [1, 2, 3, 3, 2, 1]`.

**Example 2:**

**Input:** nums = [1]

**Output:** [1,1]

**Explanation:**

The array remains the same when reversed. Thus, `ans = [1, 1]`.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem requires constructing an array of size $2n$ by concatenating the original array with its reverse. Since we know the exact size and the mapping for each index, a single pass simulation is the most efficient and direct approach.

# Approach
1. Initialize a result vector `ans` of size $2n$ with default values.
2. Iterate through the input array `nums` using an index `i` from $0$ to $n-1$.
3. Assign `ans[i] = nums[i]` to fill the first half.
4. Assign `ans[n + i] = nums[n - i - 1]` to fill the second half with the reversed elements.

### Visual Trace (Example 1: nums = [1, 2, 3])
| i | nums[i] | ans[i] | ans[n+i] | nums[n-i-1] |
|---|---|---|---|---|
| 0 | 1 | 1 | 3 | 3 |
| 1 | 2 | 2 | 2 | 2 |
| 2 | 3 | 3 | 1 | 1 |

# Complexity
- Time complexity: $$O(n)$$, where $n$ is the length of the input array. We iterate exactly $n$ times to populate the $2n$ elements.
- Space complexity: $$O(n)$$, as we allocate a new vector of size $2n$ to store the result.

# Code
```cpp
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n,0);

        for(int i = 0 ;i<n;i++){
            ans[i]= nums[i];
            ans[n+i] = nums[n-i-1];
        }
        return ans;
            
    }
};
```

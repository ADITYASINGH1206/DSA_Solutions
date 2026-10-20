# [1470. Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given the array `nums` consisting of `2n` elements in the form `[x1,x2,...,xn,y1,y2,...,yn]`.

*Return the array in the form* `[x1,y1,x2,y2,...,xn,yn]`.

**Example 1:**

```

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
```

**Example 2:**

```

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
```

**Example 3:**

```

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
```

**Constraints:**

* `1 <= n <= 500`
* `nums.length == 2n`
* `1 <= nums[i] <= 10^3`

---

## Solution & Editorial
# Intuition
The problem asks to interleave two halves of an array: $[x_1, x_2, ..., x_n]$ and $[y_1, y_2, ..., y_n]$ into the format $[x_1, y_1, x_2, y_2, ..., x_n, y_n]$. The core observation is that the $i$-th pair in the result consists of the element at index $i$ and the element at index $i+n$ from the original array.

# Approach
1. Initialize an empty result vector `ans` to store the shuffled elements.
2. Use two pointers (indices): `left` starting at $0$ (the beginning of the $x$ sequence) and `right` starting at $n$ (the beginning of the $y$ sequence).
3. Iterate $n$ times using a loop variable `i`.
4. In each iteration:
   - Append `nums[left]` to `ans` to place the next $x$ element.
   - Append `nums[right]` to `ans` to place the next $y$ element.
   - Increment both `left` and `right` to move to the next elements in their respective halves.
5. Return the populated `ans` vector.

### Visual Trace (Example 1)
Input: `nums = [2, 5, 1, 3, 4, 7]`, `n = 3`

| Iteration | `left` | `right` | `nums[left]` | `nums[right]` | `ans` (State) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Initial | 0 | 3 | - | - | [] |
| 1 | 1 | 4 | 2 | 3 | [2, 3] |
| 2 | 2 | 5 | 5 | 4 | [2, 3, 5, 4] |
| 3 | 3 | 6 | 1 | 7 | [2, 3, 5, 4, 1, 7] |

# Complexity
- Time complexity: $$O(n)$$
We perform a single pass through the first half of the array (exactly $n$ iterations). Each iteration involves constant-time vector insertions and pointer increments.

- Space complexity: $$O(n)$$
We allocate a new vector `ans` of size $2n$ to store the result. No other auxiliary data structures are used.

# Code
```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int left =0;
        int right = n;
        for(int i=0;i<n;i++){
            ans.push_back(nums[left]);
            ans.push_back(nums[right]);
            left++;
            right++;
        }
        return ans;
    }
};
```

# [1486. XOR Operation in an Array](https://leetcode.com/problems/xor-operation-in-an-array/)
**Difficulty:** `Easy` | **Tags:** `math`, `bit-manipulation`

---

## Problem Description
You are given an integer `n` and an integer `start`.

Define an array `nums` where `nums[i] = start + 2 * i` (**0-indexed**) and `n == nums.length`.

Return *the bitwise XOR of all elements of* `nums`.

**Example 1:**

```
Input: n = 5, start = 0
Output: 8
Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
Where "^" corresponds to bitwise XOR operator.
```

**Example 2:**

```
Input: n = 4, start = 3
Output: 8
Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.
```

**Constraints:**

* `1 <= n <= 1000`
* `0 <= start <= 1000`
* `n == nums.length`

---

## Solution & Editorial
# Intuition
The problem requires calculating the bitwise XOR sum of an arithmetic progression where each term is defined by the formula $nums[i] = start + 2 \times i$. Given the constraints ($n \le 1000$), a direct simulation using a loop to generate the sequence and accumulate the XOR result is highly efficient and straightforward.

# Approach
1. Initialize a vector `arr` of size `n` to store the generated sequence.
2. Initialize an integer `ans` to 0 to store the cumulative XOR result.
3. Iterate through the range $[0, n-1]$ using a loop variable `i`.
4. In each iteration, calculate the value of the $i$-th element as `start + 2 * i` and store it in `arr[i]`.
5. Update `ans` by performing a bitwise XOR operation between the current `ans` and the newly calculated `arr[i]`.
6. After the loop completes, return the final value of `ans`.

### Visual Trace (Example 1: n = 5, start = 0)
| i | Formula: `0 + 2 * i` | `arr[i]` | `ans` (Running XOR) |
|---|---|---|---|
| 0 | 0 + 0 | 0 | 0 |
| 1 | 0 + 2 | 2 | 0 ^ 2 = 2 |
| 2 | 0 + 4 | 4 | 2 ^ 4 = 6 |
| 3 | 0 + 6 | 6 | 6 ^ 6 = 0 |
| 4 | 0 + 8 | 8 | 0 ^ 8 = 8 |
**Final Result: 8**

# Complexity
- Time complexity: $$O(n)$$
We perform a single pass through a loop that runs exactly $n$ times. Each operation inside the loop (multiplication, addition, XOR, and array assignment) takes constant time $$O(1)$$.

- Space complexity: $$O(n)$$
We allocate a vector `arr` of size $n$ to store the integers. While the XOR sum could be calculated in $$O(1)$$ space without the vector, the current implementation uses linear auxiliary space.

# Code
```cpp
class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr(n,start);
        int ans = 0;
        for(int i = 0;i<n;i++){
            arr[i] = start + 2*i;
            ans ^= arr[i];
        }
        return ans;
        
    }
};
```

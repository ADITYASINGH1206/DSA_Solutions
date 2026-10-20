# [922. Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`, `sorting`

---

## Problem Description
Given an array of integers `nums`, half of the integers in `nums` are **odd**, and the other half are **even**.

Sort the array so that whenever `nums[i]` is odd, `i` is **odd**, and whenever `nums[i]` is even, `i` is **even**.

Return *any answer array that satisfies this condition*.

**Example 1:**

```
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
```

**Example 2:**

```
Input: nums = [2,3]
Output: [2,3]
```

**Constraints:**

* `2 <= nums.length <= 2 * 104`
* `nums.length` is even.
* Half of the integers in `nums` are even.
* `0 <= nums[i] <= 1000`

**Follow Up:** Could you solve it in-place?

---

## Solution & Editorial
# Intuition
The problem requires us to rearrange the array such that every even index holds an even number and every odd index holds an odd number. Since there are an equal number of even and odd integers, we can use a two-pointer approach to scan the array simultaneously from the beginning using two independent tracks: one for even indices (`i` starting at `0`) and one for odd indices (`j` starting at `1`).

# Approach
1. Initialize pointer `i = 0` for even indices and pointer `j = 1` for odd indices, along with `n = nums.size()`.
2. Run a `while` loop as long as both `i < n` and `j < n` are satisfied.
3. If `nums[i]` is already even (`nums[i] % 2 == 0`), increment `i` by `2` to check the next even position.
4. If `nums[j]` is already odd (`nums[j] % 2 == 1`), increment `j` by `2` to check the next odd position.
5. If both pointers encounter mispositioned elements (`nums[i]` is odd and `nums[j]` is even), `swap(nums[i], nums[j])` and advance both `i` and `j` by `2`.
6. Return the modified `nums` array.

### Visual Walkthrough (Example 1: `nums = [4, 2, 5, 7]`)
| Iteration | `i` | `j` | `nums[i]` | `nums[j]` | Action | State of `nums` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 1 | 4 (Even) | 2 (Even) | `i` is correct, `i += 2` | `[4, 2, 5, 7]` |
| 2 | 2 | 1 | 5 (Odd) | 2 (Even) | `j` is correct, `j += 2` | `[4, 2, 5, 7]` |
| 3 | 2 | 3 | 5 (Odd) | 7 (Odd) | `j` is correct, `j += 2` | `[4, 2, 5, 7]` |
| Loop Ends | 4 | 5 | Out of bounds | Out of bounds | Termination | `[4, 2, 5, 7]` |

### Corner Cases Handled
- Arrays of minimum size (`n = 2`).
- Arrays where elements are already correctly placed.

# Complexity
- Time complexity: $$O(N)$$ — Each index is visited at most once by either pointer `i` or pointer `j`. Thus, the while loop executes linearly with respect to the number of elements.
- Space complexity: $$O(1)$$ — The sorting is done completely in-place without allocating any auxiliary data structures.

# Code
```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1; 
        int n = nums.size();
        while (i < n && j < n) {
            if(nums[i] % 2 == 0) 
                i+=2;
            else if (nums[j] % 2 == 1) 
                j+=2;
            else {
                (swap(nums[i], nums[j]));
                i+=2, 
                j+=2;
            }
        }
        return nums;
    }
};
```

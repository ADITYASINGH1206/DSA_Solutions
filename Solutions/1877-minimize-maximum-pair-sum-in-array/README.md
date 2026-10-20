# [1877. Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `greedy`, `sorting`

---

## Problem Description
The **pair sum** of a pair `(a,b)` is equal to `a + b`. The **maximum pair sum** is the largest **pair sum** in a list of pairs.

* For example, if we have pairs `(1,5)`, `(2,3)`, and `(4,4)`, the **maximum pair sum** would be `max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8`.

Given an array `nums` of **even** length `n`, pair up the elements of `nums` into `n / 2` pairs such that:

* Each element of `nums` is in **exactly one** pair, and
* The **maximum pair sum** is **minimized**.

Return *the minimized **maximum pair sum** after optimally pairing up the elements*.

**Example 1:**

```
Input: nums = [3,5,2,3]
Output: 7
Explanation: The elements can be paired up into pairs (3,3) and (5,2).
The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
```

**Example 2:**

```
Input: nums = [3,5,4,2,4,6]
Output: 8
Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
```

**Constraints:**

* `n == nums.length`
* `2 <= n <= 105`
* `n` is **even**.
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To minimize the maximum pair sum, we must balance the sums of all pairs. By pairing the smallest available element with the largest available element, we effectively "pull" the largest values down and "push" the smallest values up, keeping the overall maximum sum as low as possible.

# Approach
1. Sort the array `nums` in non-decreasing order. This allows us to easily identify the smallest and largest elements.
2. Initialize two pointers: `l` at the start (index 0) and `r` at the end (index `n - 1`) of the array.
3. Iterate while `l < r`:
   - Calculate the sum of `nums[l]` and `nums[r]`.
   - Update `ans` with the maximum of its current value and the new pair sum.
   - Increment `l` and decrement `r` to move to the next pair.
4. Return `ans`.

### Visual Trace (Example 1: nums = [3, 5, 2, 3])
1. Sorted: `[2, 3, 3, 5]`
2. Iteration 1: `l=0 (2), r=3 (5)`. Sum = 7. `ans = max(0, 7) = 7`.
3. Iteration 2: `l=1 (3), r=2 (3)`. Sum = 6. `ans = max(7, 6) = 7`.
4. Loop terminates. Result: 7.

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step. The subsequent two-pointer traversal takes $$O(N)$$ time.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack space), as we only use a few integer variables for pointers and the result.

# Code
```cpp
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            ans = max(ans,nums[l++]+nums[r--]);
        }
        return ans;
    }
};
```

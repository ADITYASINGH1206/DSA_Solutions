# [3936. Minimum Swaps to Move Zeros to End](https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/)
**Difficulty:** `Easy` | **Tags:** `array`, `two-pointers`

---

## Problem Description
You are given an integer array `nums`.

In one operation, you can choose any two **distinct** indices `i` and `j` and swap `nums[i]` and `nums[j]`.

Return an integer denoting the **minimum** number of operations required to move all 0s to the end of the array.

**Example 1:**

**Input:** nums = [0,1,0,3,12]

**Output:** 2

**Explanation:**

We perform the following swap operations:

* Swap `nums[0]` and `nums[3]`, giving `nums = [3, 1, 0, 0, 12]`.
* Swap `nums[2]` and `nums[4]`, giving `nums = [3, 1, 12, 0, 0]`.

Thus, the answer is 2.

**Example 2:**

**Input:** nums = [0,1,0,2]

**Output:** 1

**Explanation:**

We perform the following swap operations:

* Swap `nums[0]` and `nums[3]`, giving `nums = [2, 1, 0, 0]`.

Thus, the answer is 1.

**Example 3:**

**Input:** nums = [1,2,0]

**Output:** 0

**Explanation:**

The array already satisfies the condition. Therefore, no swap operations are needed.

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To move all zeros to the end of the array with the minimum number of swaps, we must recognize that the final state will have all non-zero elements in the first `N - count(zeros)` positions and all zeros in the last `count(zeros)` positions. Any non-zero element currently residing in the "zero zone" (the last `count(zeros)` indices) must be swapped out, and any zero currently in the "non-zero zone" (the first `N - count(zeros)` indices) must be swapped in. Since each swap can fix one misplaced non-zero element and one misplaced zero simultaneously, the minimum number of swaps is simply the count of non-zero elements currently occupying the target zero zone.

# Approach
1. Count the total number of zeros in the array, stored in `zero`.
2. If `zero` is 0 or equal to the array length `n`, no swaps are needed; return 0.
3. The target zone for zeros is the suffix of the array starting from index `n - zero` to `n - 1`.
4. Iterate through this suffix. For every element that is not 0, increment the `ans` counter, as this element must be swapped out.

### Visual Trace (Example 1: [0, 1, 0, 3, 12])
- `n = 5`, `zero = 2`
- Target zero zone: indices `[5-2, 4]` = `[3, 4]`
- Initial array: `[0, 1, 0, 3, 12]`
- Check index 3: `nums[3]` is 3 (non-zero), `ans` becomes 1.
- Check index 4: `nums[4]` is 12 (non-zero), `ans` becomes 2.
- Final `ans = 2`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform one pass to count zeros and one partial pass to count misplaced non-zeros.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zero = 0;
        int n = nums.size();
        
        for (int num : nums) {
            if (num == 0) {
                zero++;
            }
        }
        
        if (zero == 0 || zero == n) return 0;
        
        int ans = 0;
        for (int i = n - zero; i < n; i++) {
            if (nums[i] != 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
```

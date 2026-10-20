# [1887. Reduction Operations to Make the Array Elements Equal](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/)
**Difficulty:** `Medium` | **Tags:** `array`, `sorting`

---

## Problem Description
Given an integer array `nums`, your goal is to make all elements in `nums` equal. To complete one operation, follow these steps:

1. Find the **largest** value in `nums`. Let its index be `i` (**0-indexed**) and its value be `largest`. If there are multiple elements with the largest value, pick the smallest `i`.
2. Find the **next largest** value in `nums` **strictly smaller** than `largest`. Let its value be `nextLargest`.
3. Reduce `nums[i]` to `nextLargest`.

Return *the number of operations to make all elements in* `nums` *equal*.

**Example 1:**

```
Input: nums = [5,1,3]
Output: 3
Explanation: It takes 3 operations to make all elements in nums equal:
1. largest = 5 at index 0. nextLargest = 3. Reduce nums[0] to 3. nums = [3,1,3].
2. largest = 3 at index 0. nextLargest = 1. Reduce nums[0] to 1. nums = [1,1,3].
3. largest = 3 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1].
```

**Example 2:**

```
Input: nums = [1,1,1]
Output: 0
Explanation: All elements in nums are already equal.
```

**Example 3:**

```
Input: nums = [1,1,2,2,3]
Output: 4
Explanation: It takes 4 operations to make all elements in nums equal:
1. largest = 3 at index 4. nextLargest = 2. Reduce nums[4] to 2. nums = [1,1,2,2,2].
2. largest = 2 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1,2,2].
3. largest = 2 at index 3. nextLargest = 1. Reduce nums[3] to 1. nums = [1,1,1,1,2].
4. largest = 2 at index 4. nextLargest = 1. Reduce nums[4] to 1. nums = [1,1,1,1,1].
```

**Constraints:**

* `1 <= nums.length <= 5 * 104`
* `1 <= nums[i] <= 5 * 104`

---

## Solution & Editorial
# Intuition
To make all elements equal, we must reduce the largest elements to the next largest value repeatedly. Instead of simulating the process, we can observe that if we sort the array, the number of operations required for each distinct value depends on how many elements are greater than it. Specifically, every time we encounter a new, smaller distinct value while iterating backwards, all elements to the right of this position must be reduced to this new value.

# Approach
1. Sort the input array `nums` in non-decreasing order. This groups identical values together.
2. Iterate backwards from the end of the array (`n-1`) to the beginning.
3. Maintain a running total `ans` of operations. Whenever `nums[i]` is strictly greater than `nums[i-1]`, it means all elements from index `i` to `n-1` (which are currently equal to the previous 'largest') must be reduced to the value at `nums[i-1]`.
4. The number of such elements is `n - i`. Add this count to `ans`.

### Visual Trace (Example 3: [1, 1, 2, 2, 3])
Sorted: `[1, 1, 2, 2, 3]`, `n = 5`

| Index (i) | nums[i] | nums[i-1] | Change? | ans += (n-i) | Total ans |
|-----------|---------|-----------|---------|--------------|-----------|
| 4         | 3       | 2         | Yes     | 5 - 4 = 1    | 1         |
| 3         | 2       | 2         | No      | 0            | 1         |
| 2         | 2       | 1         | Yes     | 5 - 2 = 3    | 4         |
| 1         | 1       | 1         | No      | 0            | 4         |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step. The subsequent linear scan takes $$O(N)$$.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we perform the operations in-place without extra data structures.

# Code
```cpp
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = n-1;i>0;i--){
            if(nums[i-1] != nums[i]){
                ans += n - i;
            }
        }

        return ans;
    }
};
```

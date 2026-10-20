# [1827. Minimum Operations to Make the Array Increasing](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`

---

## Problem Description
You are given an integer array `nums` (**0-indexed**). In one operation, you can choose an element of the array and increment it by `1`.

* For example, if `nums = [1,2,3]`, you can choose to increment `nums[1]` to make `nums = [1,3,3]`.

Return *the **minimum** number of operations needed to make* `nums` ***strictly** **increasing**.*

An array `nums` is **strictly increasing** if `nums[i] < nums[i+1]` for all `0 <= i < nums.length - 1`. An array of length `1` is trivially strictly increasing.

**Example 1:**

```

Input: nums = [1,1,1]
Output: 3
Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].
```

**Example 2:**

```

Input: nums = [1,5,2,4,1]
Output: 14
```

**Example 3:**

```

Input: nums = [8]
Output: 0
```

**Constraints:**

* `1 <= nums.length <= 5000`
* `1 <= nums[i] <= 104`

---

## Solution & Editorial
# Intuition
To make an array strictly increasing with the minimum number of operations, we must ensure that for every index `i > 0`, `nums[i]` is at least `nums[i-1] + 1`. Since we can only increment elements, if `nums[i]` is already greater than `nums[i-1]`, we do nothing. If it is not, we must increment `nums[i]` until it reaches exactly `nums[i-1] + 1` to minimize the cost.

# Approach
1. Initialize a counter `ans` to 0 to track the total operations.
2. Iterate through the array starting from the second element (`i = 1`).
3. Compare the current element `nums[i]` with the previous element `nums[i-1]`.
4. If `nums[i] <= nums[i-1]`, calculate the target value `temp = nums[i-1] + 1`.
5. The number of operations required for this specific index is `temp - nums[i]`. Add this to `ans` and update `nums[i]` to `temp`.
6. Continue until the end of the array.

### Visual Trace (Example 1: nums = [1, 1, 1])
| Index (i) | nums[i-1] | nums[i] | Condition (nums[i] <= nums[i-1]) | Target (nums[i-1]+1) | Operations | Array State |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | 1 | True | 2 | 1 | [1, 2, 1] |
| 2 | 2 | 1 | True | 3 | 2 | [1, 2, 3] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass through the array, and each operation inside the loop is constant time.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i] <= nums[i-1]){
                int temp = nums[i-1]+1;
                ans += abs(nums[i]-temp);
                nums[i] = temp;
            }
        }
        return ans;
    }
};
```

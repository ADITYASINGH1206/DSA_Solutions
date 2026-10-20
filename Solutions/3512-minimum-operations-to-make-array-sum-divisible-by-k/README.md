# [3512. Minimum Operations to Make Array Sum Divisible by K](https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given an integer array `nums` and an integer `k`. You can perform the following operation any number of times:

* Select an index `i` and replace `nums[i]` with `nums[i] - 1`.

Return the **minimum** number of operations required to make the sum of the array divisible by `k`.

**Example 1:**

**Input:** nums = [3,9,7], k = 5

**Output:** 4

**Explanation:**

* Perform 4 operations on `nums[1] = 9`. Now, `nums = [3, 5, 7]`.
* The sum is 15, which is divisible by 5.

**Example 2:**

**Input:** nums = [4,1,3], k = 4

**Output:** 0

**Explanation:**

* The sum is 8, which is already divisible by 4. Hence, no operations are needed.

**Example 3:**

**Input:** nums = [3,2], k = 6

**Output:** 5

**Explanation:**

* Perform 3 operations on `nums[0] = 3` and 2 operations on `nums[1] = 2`. Now, `nums = [0, 0]`.
* The sum is 0, which is divisible by 6.

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`
* `1 <= k <= 100`

---

## Solution & Editorial
# Intuition
To make the sum of an array divisible by $k$, we need the total sum $S$ to satisfy $S \equiv 0 \pmod k$. Since we can only decrease elements (replace $nums[i]$ with $nums[i] - 1$), each operation reduces the total sum by exactly 1. Therefore, the minimum number of operations required is simply the remainder of the total sum when divided by $k$.

# Approach
1. Calculate the total sum of all elements in the array `nums`.
2. Compute the remainder of this sum when divided by $k$ using the modulo operator (`sum % k`).
3. This remainder represents the exact amount we need to subtract from the total sum to reach the nearest multiple of $k$ that is less than or equal to the current sum.

### Visual Trace (Example 1: nums = [3, 9, 7], k = 5)
| Step | Action | Value |
| :--- | :--- | :--- |
| 1 | Calculate sum | 3 + 9 + 7 = 19 |
| 2 | Calculate remainder | 19 % 5 = 4 |
| 3 | Result | 4 |

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the number of elements in `nums`, as we iterate through the array once to calculate the sum.
- Space complexity: $$O(1)$$, as we only use a single integer variable to accumulate the sum.

# Code
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0,sum =0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return ans = sum % k;
    }
};
```

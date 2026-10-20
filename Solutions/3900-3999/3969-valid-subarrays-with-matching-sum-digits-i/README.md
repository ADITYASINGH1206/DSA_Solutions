# [3969. Valid Subarrays With Matching Sum Digits I](https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `sliding-window`, `enumeration`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` and an integer digit `x`.

A **subarray** `nums[l..r]` is considered **valid** if the sum of its elements satisfies both of the following conditions:

* The first digit of the sum is equal to `x`.
* The last digit of the sum is equal to `x`.

Return the number of valid subarrays.

**Example 1:**

**Input:** nums = [1,100,1], x = 1

**Output:** 4

**Explanation:**

The valid subarrays are:

* `nums[0..0]`: `sum = 1`
* `nums[0..1]`: `sum = 1 + 100 = 101`
* `nums[1..2]`: `sum = 100 + 1 = 101`
* `nums[2..2]`: `sum = 1`

Thus, the answer is 4.

**Example 2:**

**Input:** nums = [1], x = 2

**Output:** 0

**Explanation:**

The only subarray is `nums[0..0]` with a sum of 1, which does not satisfy the conditions.

Thus, the answer is 0.

**Constraints:**

* `1 <= nums.length <= 1500`
* `1 <= nums[i] <= 109`
* `1 <= x <= 9`

---

## Solution & Editorial
# Intuition
Since the constraints on the array length are relatively small ($N \le 1500$), an $O(N^2)$ approach is efficient enough to pass within the time limits. The problem asks us to evaluate every possible subarray, calculate its sum, and verify if the first and last digits match the target digit $x$.

# Approach
1. Iterate through all possible starting indices $i$ from $0$ to $n-1$.
2. For each $i$, maintain a running `sum` and iterate through all ending indices $j$ from $i$ to $n-1$.
3. Update the `sum` by adding `nums[j]` at each step.
4. For every subarray `nums[i..j]`, invoke the `check` function:
   - Extract the last digit using `sum % 10`.
   - Extract the first digit by repeatedly dividing `sum` by 10 until it is less than 10.
   - Compare both extracted digits with $x$.
5. Increment the `ans` counter if both conditions are met.

### Visual Trace (Example 1: nums = [1, 100, 1], x = 1)
| i | j | Subarray | Sum | First Digit | Last Digit | Valid? |
|---|---|---|---|---|---|---|
| 0 | 0 | [1] | 1 | 1 | 1 | Yes |
| 0 | 1 | [1, 100] | 101 | 1 | 1 | Yes |
| 0 | 2 | [1, 100, 1] | 102 | 1 | 2 | No |
| 1 | 1 | [100] | 100 | 1 | 0 | No |
| 1 | 2 | [100, 1] | 101 | 1 | 1 | Yes |
| 2 | 2 | [1] | 1 | 1 | 1 | Yes |

# Complexity
- Time complexity: $$O(N^2 \cdot \log_{10}(\text{max\_sum}))$$ — We iterate through all $O(N^2)$ subarrays. For each, we perform a digit extraction which takes logarithmic time relative to the sum value.
- Space complexity: $$O(1)$$ — We only use a few integer variables for tracking the sum and indices, requiring constant extra space.

# Code
```cpp
class Solution {
public:
    bool check(long long sum,int x){
        int last = sum%10;
        long long first = sum;
        while(first>9){
            first /=10;
        }

        return ((first==x) && (last == x));
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long long sum = 0;
            for(int j =i;j<n;j++){
                sum += nums[j];
                if(check(sum,x)) ans++;
            }
        }
        return ans;
    }
};
```

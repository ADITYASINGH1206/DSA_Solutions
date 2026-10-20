# [3896. Minimum Operations to Transform Array into Alternating Prime](https://leetcode.com/problems/minimum-operations-to-transform-array-into-alternating-prime/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `two-pointers`, `binary-search`, `sorting`, `number-theory`

---

## Problem Description
You are given an integer array `nums`.

An array is considered **alternating prime** if:

* Elements at **even** indices (0-based) are **prime** numbers.
* Elements at **odd** indices are **non-prime** numbers.

In one operation, you may **increment** any element by 1.

Return the **minimum** number of operations required to transform `nums` into an **alternating prime** array.

A **prime** number is a natural number greater than 1 with only two factors, 1 and itself.

**Example 1:**

**Input:** nums = [1,2,3,4]

**Output:** 3

**Explanation:**

* The element at index 0 must be prime. Increment `nums[0] = 1` to 2, using 1 operation.
* The element at index 1 must be non-prime. Increment `nums[1] = 2` to 4, using 2 operations.
* The element at index 2 is already prime.
* The element at index 3 is already non-prime.

Total operations = `1 + 2 = 3`.

**Example 2:**

**Input:** nums = [5,6,7,8]

**Output:** 0

**Explanation:**

* The elements at indices 0 and 2 are already prime.
* The elements at indices 1 and 3 are already non-prime.

No operations are needed.

**Example 3:**

**Input:** nums = [4,4]

**Output:** 1

**Explanation:**

* The element at index 0 must be prime. Increment `nums[0] = 4` to 5, using 1 operation.
* The element at index 1 is already non-prime.

Total operations = 1.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To transform the array into an alternating prime sequence, we must satisfy two independent conditions for each index: even indices must contain prime numbers, and odd indices must contain non-prime numbers. Since we can only increment elements, the optimal strategy for each index is to find the smallest integer greater than or equal to the current value that satisfies the respective primality condition.

# Approach
1. Define a helper function `primecheck(n)` to determine if a number is prime using trial division up to `sqrt(n)`.
2. For even indices, find the smallest prime `target >= nums[i]` using a `while` loop that increments the value until `primecheck` returns true.
3. For odd indices, find the smallest non-prime `target >= nums[i]` using a `while` loop that increments the value until `primecheck` returns false.
4. Accumulate the difference `target - nums[i]` into a running total `ans`.

### Visual Trace (Example 1: nums = [1, 2, 3, 4])
| Index | Value | Target Type | Target Calculation | Operations |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 1 | Prime | 1 -> 2 (Prime) | 1 |
| 1 | 2 | Non-Prime | 2 -> 3 (Prime) -> 4 (Non-Prime) | 2 |
| 2 | 3 | Prime | 3 (Prime) | 0 |
| 3 | 4 | Non-Prime | 4 (Non-Prime) | 0 |
| **Total** | | | | **3** |

# Complexity
- Time complexity: $$O(N \cdot \sqrt{M})$$, where $$N$$ is the length of the array and $$M$$ is the maximum value in the array. For each element, we perform trial division up to the next prime/non-prime, which is bounded by the gap between primes.
- Space complexity: $$O(1)$$, as we only use a few integer variables for calculation.

# Code
```cpp
class Solution {
public:
    bool primecheck(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        
    
        return true;
    }
    int prime(int n) {
        if (n <= 2) return 2;
        int curr = n;
        while (!primecheck(curr)) {
            curr++;
        }
        return curr;
    }

    int nprime(int n) {
        if (n <= 1) return n; 
        int curr = n;
        while (primecheck(curr)) {
            curr++;
        }
        return curr;
    }


    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                int target = prime(nums[i]);
                ans += (target - nums[i]);
            } else {
                int target = nprime(nums[i]);
                ans += (target - nums[i]);
            }
        }
        
        return ans;
    }
};
```

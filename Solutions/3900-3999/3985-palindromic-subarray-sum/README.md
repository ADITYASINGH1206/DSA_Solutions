# [3985. Palindromic Subarray Sum](https://leetcode.com/problems/palindromic-subarray-sum/)
**Difficulty:** `Hard` | **Tags:** `array`, `binary-search`, `hash-function`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums`.

Return the maximum possible sum of a subarray of `nums` that is a palindrome.

**Example 1:**

**Input:** nums = [10,10]

**Output:** 20

**Explanation:**

The whole array `[10,10]` is a palindrome. Therefore, the maximum sum is `10 + 10 = 20`.

**Example 2:**

**Input:** nums = [1,2,3,2,1,5,6]

**Output:** 9

**Explanation:**

The contiguous subarray `[1,2,3,2,1]` is a palindrome. Its sum is `1 + 2 + 3 + 2 + 1 = 9` and it is the maximum sum.

**Example 3:**

**Input:** nums = [7,1,2,1,7,3,4,3,4]

**Output:** 18

**Explanation:**

The contiguous subarray `[7,1,2,1,7]` is a palindrome. Its sum is `7 + 1 + 2 + 1 + 7 = 18` and it is the maximum sum.

**Example 4:**

**Input:** nums = [1,2,3,4,5]

**Output:** 5

**Explanation:**

No subarray with length greater than 1 is a palindrome. The largest element in the array is 5. Therefore, the answer is 5.

**Example 5:**

**Input:** nums = [1000]

**Output:** 1000

**Explanation:**

The subarray with only one element is a palindrome. Therefore, the answer is 1000.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 10​​​​​​​9`

---

## Solution & Editorial
# Intuition
To find the maximum sum of a palindromic subarray, we must efficiently identify all palindromic substrings and calculate their sums. Since a naive expansion takes $O(N^2)$, we leverage Manacher's Algorithm, which finds the radius of the longest palindrome centered at every position in $O(N)$ time. By transforming the array and using prefix sums, we can evaluate the sum of any identified palindrome in $O(1)$ time.

# Approach
1. **Preprocessing**: Transform the input array `nums` into a new array `T` of size $2N+1$ by inserting a sentinel value (`INT_MAX`) between elements. This allows us to treat odd and even length palindromes uniformly.
2. **Prefix Sums**: Precompute a `pref` array where `pref[i]` stores the sum of `nums[0...i-1]`. This enables $O(1)$ range sum queries.
3. **Manacher's Algorithm**: Iterate through `T` maintaining the center `C` and right boundary `R` of the rightmost palindrome found so far. For each index `i`, calculate the palindrome radius `rad` using previously computed values in `P`.
4. **Sum Calculation**: Whenever a palindrome is expanded, map the boundaries back to the original `nums` indices using `(i - rad) / 2` and `(i + rad - 1) / 2`. Use the `pref` array to calculate the sum and update `max_sum`.

### Visual Trace (Example: [1, 2, 1])
| Index | T | P (Radius) | Palindrome Range | Sum |
| :--- | :--- | :--- | :--- | :--- |
| 0 | INF | 0 | [0, 0] | 1 |
| 1 | 1 | 1 | [0, 0] | 1 |
| 2 | INF | 0 | [0, 1] | 3 |
| 3 | 2 | 3 | [0, 2] | 4 |

# Complexity
- Time complexity: $$O(N)$$ — Manacher's algorithm visits each element a constant number of times. Prefix sum construction and range queries are $O(N)$ and $O(1)$ respectively.
- Space complexity: $$O(N)$$ — We store the transformed array `T`, the radius array `P`, and the prefix sum array `pref`, all of which are linear in size relative to the input.

# Code
```cpp
class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        int n_T = 2 * n + 1;
        vector<int> T(n_T);
        for (int i = 0; i < n; ++i) {
            T[2 * i] = INT_MAX;
            T[2 * i + 1] = nums[i];
        }
        T[2 * n] = INT_MAX;
        
        vector<int> P(n_T, 0);
        int C = 0, R = -1;
        long long max_sum = LLONG_MIN;

        for (int i = 0; i < n_T; ++i) {
            int rad = (i < R) ? min(R - i, P[2 * C - i]) : 0;

            if (i + rad > R) {
                int L_nums = (i - rad) / 2;
                int R_nums = (i + rad - 1) / 2;
                if (L_nums <= R_nums) {
                    max_sum = max(max_sum, pref[R_nums + 1] - pref[L_nums]);
                }
            }

            while (i - rad - 1 >= 0 && i + rad + 1 < n_T && T[i - rad - 1] == T[i + rad + 1]) {
                rad++;
                if (i + rad > R) {
                    int L_nums = (i - rad) / 2;
                    int R_nums = (i + rad - 1) / 2;
                    if (L_nums <= R_nums) {
                        max_sum = max(max_sum, pref[R_nums + 1] - pref[L_nums]);
                    }
                }
            }
            
            P[i] = rad;
            if (i + rad > R) {
                C = i;
                R = i + rad;
            }
        }
        
        return max_sum;
    }
};
```

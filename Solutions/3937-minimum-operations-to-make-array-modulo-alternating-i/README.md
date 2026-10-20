# [3937. Minimum Operations to Make Array Modulo Alternating I](https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `enumeration`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

In one operation, you can **increase** or **decrease** any element of `nums` by 1.

An array is called **modulo alternating** if there exist two **distinct** integers `x` and `y` (`0 <= x, y < k`) such that:

* For every **even** index `i`, `nums[i] % k == x`
* For every **odd** index `i`, `nums[i] % k == y`

Return the **minimum** number of operations required to make `nums` **modulo alternating**.

**Example 1:**

**Input:** nums = [1,4,2,8], k = 3

**Output:** 2

**Explanation:**

* Let's choose `x = 1` for even indices and `y = 2` for odd indices.
* Perform the following operations:
  + Increment `nums[1] = 4` by 1, giving `nums = [1, 5, 2, 8]`.
  + Decrement `nums[2] = 2` by 1, giving `nums = [1, 5, 1, 8]`.
* Now, for even indices, `nums[i] % k = 1`, and for odd indices, `nums[i] % k = 2`.
* Thus, the total number of operations required is 2.

**Example 2:**

**Input:** nums = [1,1,1], k = 3

**Output:** 1

**Explanation:**

* Incrementing `nums[1]` by 1 gives `nums = [1, 2, 1]`, which satisfies the condition with `x = 1` and `y = 2`.
* Thus, the total number of operations required is 1.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 109`
* `2 <= k <= 100`

---

## Solution & Editorial
# Intuition
Since the constraints on $k$ are small ($k \le 100$), we can exhaustively test every possible pair of remainders $(x, y)$ for even and odd indices. For any given remainder $r = nums[i] \pmod k$, the cost to change it to a target remainder $t$ is $\min(|r - t|, k - |r - t|)$.

# Approach
1. Iterate through all possible remainders $x$ and $y$ in the range $[0, k-1]$.
2. Skip the iteration if $x == y$, as the problem requires distinct integers.
3. For each pair $(x, y)$, calculate the total operations required to transform all even-indexed elements to have remainder $x$ and all odd-indexed elements to have remainder $y$.
4. The cost for a single element $nums[i]$ to reach target $t$ is $\min(|(nums[i] \pmod k) - t|, k - |(nums[i] \pmod k) - t|)$.
5. Track the minimum total cost across all valid $(x, y)$ pairs.

### Visual Trace (Example 1: nums=[1,4,2,8], k=3)
| Pair (x, y) | Even Indices (1, 2) | Odd Indices (4, 8) | Cost Calculation | Total |
| :--- | :--- | :--- | :--- | :--- |
| (1, 2) | 1%3=1, 2%3=2 | 4%3=1, 8%3=2 | |1-1| + |2-2| + |1-2| + |2-2| | 1+0+1+0 = 2 |

# Complexity
- Time complexity: $$O(k^2 \cdot N)$$, where $N$ is the length of the array and $k$ is the modulo. We iterate through $k^2$ pairs and for each, we traverse the array of size $N$.
- Space complexity: $$O(1)$$, as we only use a few variables to track the minimum operations.

# Code
```cpp
class Solution {
public:
    long long minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = LLONG_MAX; 
        
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue; 
                long long current_ops = 0;
                for (int i = 0; i < n; i++) {
                    int r = nums[i] % k;
                    if (i % 2 == 0) {
                        int dist = abs(r - x);
                        current_ops += min(dist, k - dist);
                    } else {
                        int dist = abs(r - y);
                        current_ops += min(dist, k - dist);
                    }
                }
                
                if (current_ops < ans) {
                    ans = current_ops;
                }
            }
        }
        
        return ans;
    }
};
```

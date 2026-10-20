# [4076. Longest Resilient Subarray II](https://leetcode.com/problems/longest-resilient-subarray-ii/)
**Difficulty:** `Medium` | **Tags:** `Algorithm`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

A subarray is **resilient** if, for **every** position in it, deleting the element at that position leaves the **remaining** elements with a **sum divisible** by `k`.

For a subarray of length 1, the remaining sum is 0, which is divisible by `k`.

Return the length of the **longest resilient subarray**.

**Example 1:**

**Input:** nums = [2,4,6,3], k = 2

**Output:** 3

**Explanation:**

The subarray `[2, 4, 6]` sums to 12. Deleting 2, 4, or 6 leaves a sum of 10, 8, or 6, respectively, each of which is divisible by 2. Therefore, the answer is 3.

**Example 2:**

**Input:** nums = [1,4,7,1], k = 3

**Output:** 4

**Explanation:**

The subarray `[1, 4, 7, 1]` sums to 13. Deleting the first 1, the 4, the 7, or the last 1 leaves a sum of 12, 9, 6, or 12, respectively, each of which is divisible by 3. Therefore, the answer is 4.

**Example 3:**

**Input:** nums = [5,5,4,8], k = 4

**Output:** 2

**Explanation:**

The subarray `[5, 5]` is not resilient, since deleting either 5 leaves a sum of 5, which is not divisible by 4.

The subarray `[4, 8]` sums to 12. Deleting 4 or 8 leaves a sum of 8 or 4, respectively, each of which is divisible by 4. Therefore, the answer is 2.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`
* `1 <= k <= 105`

---

## Solution & Editorial
# Intuition
A subarray is resilient if for every element $x$ in the subarray, $(Sum - x) \equiv 0 \pmod k$. This is equivalent to $Sum \equiv x \pmod k$ for all $x$ in the subarray. This implies that all elements in a resilient subarray must have the same remainder modulo $k$. If all elements have the same remainder $m$, then the condition simplifies to $Sum \equiv m \pmod k$. If the subarray has length $L$, then $L \cdot m \equiv m \pmod k$, which means $(L-1) \cdot m \equiv 0 \pmod k$. This condition is satisfied if $(L-1)$ is a multiple of $k / \gcd(m, k)$.

# Approach
1. Identify contiguous segments of the array where all elements share the same remainder $m = nums[i] \pmod k$.
2. For each segment of length `len`, we need to find the largest $L \le len$ such that $(L-1) \cdot m \equiv 0 \pmod k$.
3. Let $g = \gcd(m, k)$. The condition $(L-1) \cdot m \equiv 0 \pmod k$ is equivalent to $(L-1) \cdot (m/g) \equiv 0 \pmod{k/g}$. Since $\gcd(m/g, k/g) = 1$, this requires $(L-1)$ to be a multiple of $k/g$.
4. Thus, $L-1 = c \cdot (k/g)$ for some integer $c$. The largest such $L \le len$ is $L = \lfloor \frac{len-1}{k/g} \rfloor \cdot (k/g) + 1$.

### Visual Trace (Example 1: nums=[2,4,6,3], k=2)
- $i=0, m=2\%2=0$. Segment [2,4,6] has $len=3$. $g=\gcd(0,2)=2$. $step=2/2=1$. $L = \lfloor(3-1)/1\rfloor \cdot 1 + 1 = 3$.
- $i=3, m=3\%2=1$. Segment [3] has $len=1$. $g=\gcd(1,2)=1$. $step=2/1=2$. $L = \lfloor(1-1)/2\rfloor \cdot 2 + 1 = 1$.
- Max $L = 3$.

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the length of the array, as we iterate through the array once.
- Space complexity: $$O(1)$$ as we only use a few variables for tracking state.

# Code
```cpp
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        int n = nums.size();
        
        int i = 0;
        while (i < n) {
            int start = i;
            long long m = nums[i] % k;
            while (i < n && nums[i] % k == m) {
                i++;
            }
            
            int len = i - start;
            long long g = gcd(m, (long long)k);
            long long step = k / g;
            
            int c = (len - 1) / step;
            int L = c * step + 1;
            
            if (L > ans) {
                ans = L;
            }
        }
        
        return ans;
    }
};
```

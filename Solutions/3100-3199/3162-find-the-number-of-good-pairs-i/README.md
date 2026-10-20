# [3162. Find the Number of Good Pairs I](https://leetcode.com/problems/find-the-number-of-good-pairs-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given 2 integer arrays `nums1` and `nums2` of lengths `n` and `m` respectively. You are also given a **positive** integer `k`.

A pair `(i, j)` is called **good** if `nums1[i]` is divisible by `nums2[j] * k` (`0 <= i <= n - 1`, `0 <= j <= m - 1`).

Return the total number of **good** pairs.

**Example 1:**

**Input:** nums1 = [1,3,4], nums2 = [1,3,4], k = 1

**Output:** 5

**Explanation:**

The 5 good pairs are `(0, 0)`, `(1, 0)`, `(1, 1)`, `(2, 0)`, and `(2, 2)`.

**Example 2:**

**Input:** nums1 = [1,2,4,12], nums2 = [2,4], k = 3

**Output:** 2

**Explanation:**

The 2 good pairs are `(3, 0)` and `(3, 1)`.

**Constraints:**

* `1 <= n, m <= 50`
* `1 <= nums1[i], nums2[j] <= 50`
* `1 <= k <= 50`

---

## Solution & Editorial
# Intuition
The problem asks us to count pairs $(i, j)$ such that `nums1[i]` is divisible by `nums2[j] * k`. Given the small constraints ($n, m \le 50$), a direct brute-force approach checking every possible pair is optimal and well within the time limits.

# Approach
1. Initialize a counter `ans` to 0.
2. Iterate through each element `nums1[i]` in the first array using a nested loop structure.
3. For each `nums1[i]`, iterate through each element `nums2[j]` in the second array.
4. Check the condition `nums1[i] % (nums2[j] * k) == 0`. If true, increment `ans`.
5. Return `ans` after both loops complete.

### Visual Trace (Example 1: nums1=[1,3,4], nums2=[1,3,4], k=1)
| i | nums1[i] | j | nums2[j]*k | Divisible? | ans |
|---|---|---|---|---|---|
| 0 | 1 | 0 | 1 | Yes | 1 |
| 1 | 3 | 0 | 1 | Yes | 2 |
| 1 | 3 | 1 | 3 | Yes | 3 |
| 2 | 4 | 0 | 1 | Yes | 4 |
| 2 | 4 | 2 | 4 | Yes | 5 |

# Complexity
- Time complexity: $$O(n \times m)$$, where $n$ and $m$ are the lengths of `nums1` and `nums2` respectively. We perform a constant time check for every pair.
- Space complexity: $$O(1)$$, as we only use a single integer variable to store the count.

# Code
```cpp
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i] % (nums2[j]*k) == 0) ans++;
            }
        }
        return ans;
    }
};
```

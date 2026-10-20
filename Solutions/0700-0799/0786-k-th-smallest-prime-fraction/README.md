# [786. K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `binary-search`, `sorting`, `heap-priority-queue`

---

## Problem Description
You are given a sorted integer array `arr` containing `1` and **prime** numbers, where all the integers of `arr` are unique. You are also given an integer `k`.

For every `i` and `j` where `0 <= i < j < arr.length`, we consider the fraction `arr[i] / arr[j]`.

Return *the* `kth` *smallest fraction considered*. Return your answer as an array of integers of size `2`, where `answer[0] == arr[i]` and `answer[1] == arr[j]`.

**Example 1:**

```
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
```

**Example 2:**

```
Input: arr = [1,7], k = 1
Output: [1,7]
```

**Constraints:**

* `2 <= arr.length <= 1000`
* `1 <= arr[i] <= 3 * 104`
* `arr[0] == 1`
* `arr[i]` is a **prime** number for `i > 0`.
* All the numbers of `arr` are **unique** and sorted in **strictly increasing** order.
* `1 <= k <= arr.length * (arr.length - 1) / 2`

**Follow up:** Can you solve the problem with better than `O(n2)` complexity?

---

## Solution & Editorial
# Intuition
The problem asks for the $k$-th smallest fraction among all pairs $(arr[i], arr[j])$ with $i < j$. Since the total number of fractions is up to $\frac{N(N-1)}{2}$ (where $N \le 1000$), an $O(N^2)$ brute-force check of all pairs is too slow. However, the value of fractions lies within the real interval $[0, 1]$. We can perform binary search on this real value range to find the exact threshold fraction that has $k$ fractions smaller than or equal to it.

# Approach
1. Initialize `left = 0` and `right = 1` as the search boundaries for the fraction value. Set up a binary search loop that runs while `left <= right`.
2. In each iteration, calculate the midpoint `mid = left + (right - left) / 2`. For this `mid`, count how many fractions $\frac{arr[i]}{arr[j]} \le mid$ exist, which can be rearranged as $arr[i] \le arr[j] \times mid$.
3. Use a two-pointer technique for each numerator index `i` to advance `j` as long as $arr[i] \ge arr[j] \times mid$. The number of elements from `j` to `n - 1` gives the count of fractions for the current `i` that are less than or equal to `mid`. Simultaneously, track the maximum fraction found that is $\le mid$ to capture the exact fraction when `total == k`.
4. If `total == k`, store the corresponding fraction elements and terminate. If `total > k`, update `right = mid`; otherwise, update `left = mid`.

### Example 1 Walkthrough (`arr = [1, 2, 3, 5], k = 3`)
- Initial `left = 0`, `right = 1`
- First mid approx `0.5`:
  - For `i = 0` (`arr[0] = 1`), `j` advances while $1 \ge arr[j] \times 0.5$. Valid denominators are `2, 3, 5` (all `j` from 1 to 3), adding `3` fractions.
  - Total count exceeds $k = 3$, so `right` is adjusted to `0.5`.
- Subsequent binary search steps narrow down the range until `total == k` yields `[2, 5]`.

# Complexity
- Time complexity: $$O(N \log M)$$, where $$N$$ is the size of `arr` and $$M$$ is the precision range of the binary search (fixed number of iterations, around 30-40 steps). Counting fractions takes $$O(N)$$ per iteration.
- Space complexity: $$O(1)$$ auxiliary space, as only a few variables are maintained.

# Code
```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1, mid;
        vector<int> res;

        while (left <= right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] >= arr[j] * mid) {
                    ++j;
                }
                
                total += n - j;

                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j;
                }
            }

            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }

            if (total > k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return res;
    }
};
```

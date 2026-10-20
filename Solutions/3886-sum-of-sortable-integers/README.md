# [3886. Sum of Sortable Integers](https://leetcode.com/problems/sum-of-sortable-integers/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `sorting`, `enumeration`

---

## Problem Description
You are given an integer array `nums` of length `n`.

An integer `k` is called **sortable** if `k` **divides** `n` and you can sort `nums` in **non-decreasing** order by sequentially performing the following operations:

* Partition `nums` into **consecutive subarrays** of length `k`.
* **Cyclically rotate each subarray independently** any number of times to the left or to the right.

Return an integer denoting the sum of all possible sortable integers `k`.

**Example 1:**

**Input:** nums = [3,1,2]

**Output:** 3

**Explanation:**​​​​​​​

* For `n = 3`, possible divisors are 1 and 3.
* For `k = 1`: each subarray has one element. No rotation can sort the array.
* For `k = 3`: the single subarray `[3, 1, 2]` can be rotated once to produce `[1, 2, 3]`, which is sorted.
* Only `k = 3` is sortable. Hence, the answer is 3.

**Example 2:**

**Input:** nums = [7,6,5]

**Output:** 0

**Explanation:**

* For `n = 3`, possible divisors are 1 and 3.
* For `k = 1`: each subarray has one element. No rotation can sort the array.
* For `k = 3`: the single subarray `[7, 6, 5]` cannot be rotated into non-decreasing order.
* No `k` is sortable. Hence, the answer is 0.

**Example 3:**

**Input:** nums = [5,8]

**Output:** 3

**Explanation:**​​​​​​​

* For `n = 2`, possible divisors are 1 and 2.
* Since `[5, 8]` is already sorted, every divisor is sortable. Hence, the answer is `1 + 2 = 3`.

**Constraints:**

* `1 <= n == nums.length <= 105`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
An integer $k$ is sortable if we can partition the array into blocks of size $k$ and rotate each block such that the entire array becomes sorted. Since the final sorted state is unique (the sorted version of the input array), each block of size $k$ must match the corresponding segment of the sorted array after some cyclic rotation.

# Approach
1. First, generate the target sorted array `sorted` to know exactly what each block of size $k$ should look like.
2. Find all divisors $k$ of $n$. For each $k$, we must verify if every block of size $k$ in `nums` can be rotated to match the corresponding block in `sorted`.
3. A block can be rotated to match a target if and only if it is a cyclic shift of the target. A key property of a cyclic shift is that it can have at most one index $j$ where $nums[j] > nums[j+1]$ (considering the wrap-around). If it has zero such points, it is already sorted. If it has one, that point must be the rotation pivot.
4. For each block, we check the number of descents. If `desc > 1`, the block cannot be rotated to match the sorted segment. If `desc == 1`, we determine the rotation offset `r` and verify the elements match the target.

### Visual Trace (Example 1: nums = [3, 1, 2], n = 3)
- Sorted: [1, 2, 3]
- Divisors: 1, 3
- k=1: Block [3] vs [1]. No match.
- k=3: Block [3, 1, 2]. Descents: (3>1) at index 0. Pivot `r = 1`. Rotated: [1, 2, 3]. Matches sorted. Valid.

# Complexity
- Time complexity: $$O(N \log N + D \cdot N)$$, where $N$ is the array size and $D$ is the number of divisors. Sorting takes $$O(N \log N)$$, and checking each divisor takes $$O(N)$$.
- Space complexity: $$O(N)$$ to store the sorted version of the array.

# Code
```cpp
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<int> divs;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i != n / i) divs.push_back(n / i);
            }
        }
        int ans = 0;
        for (int k : divs) {
            bool ok = true;
            for (int s = 0; s < n && ok; s += k) {
                int desc = 0, pos = -1;
                for (int j = 0; j < k; ++j) {
                    int a = nums[s + j];
                    int b = nums[s + (j + 1) % k];
                    if (a > b) {
                        ++desc;
                        pos = j;
                        if (desc > 1) break;
                    }
                }
                if (desc > 1) {
                    ok = false;
                    break;
                }
                int r = (desc == 0) ? 0 : (pos + 1) % k;
                for (int j = 0; j < k; ++j) {
                    if (nums[s + (r + j) % k] != sorted[s + j]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) ans += k;
        }
        return ans;
    }
};
```

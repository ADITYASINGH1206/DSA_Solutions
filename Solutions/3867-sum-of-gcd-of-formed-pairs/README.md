# [3867. Sum of GCD of Formed Pairs](https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `two-pointers`, `sorting`, `simulation`, `number-theory`

---

## Problem Description
You are given an integer array `nums` of length `n`.

Construct an array `prefixGcd` where for each index `i`:

* Let `mxi = max(nums[0], nums[1], ..., nums[i])`.
* `prefixGcd[i] = gcd(nums[i], mxi)`.

After constructing `prefixGcd`:

* Sort `prefixGcd` in **non-decreasing** order.
* Form pairs by taking the **smallest unpaired** element and the **largest unpaired** element.
* Repeat this process until no more pairs can be formed.
* For each formed pair, **compute** the `gcd` of the two elements.
* If `n` is odd, the **middle** element in the `prefixGcd` array remains **unpaired** and should be ignored.

Return an integer denoting the **sum of the GCD** values of all formed pairs.

The term `gcd(a, b)` denotes the **greatest common divisor** of `a` and `b`.

**Example 1:**

**Input:** nums = [2,6,4]

**Output:** 2

**Explanation:**

Construct `prefixGcd`:

| `i` | `nums[i]` | `mxi` | `prefixGcd[i]` |
| --- | --- | --- | --- |
| 0 | 2 | 2 | 2 |
| 1 | 6 | 6 | 6 |
| 2 | 4 | 6 | 2 |

`prefixGcd = [2, 6, 2]`. After sorting, it forms `[2, 2, 6]`.

Pair the smallest and largest elements: `gcd(2, 6) = 2`. The remaining middle element 2 is ignored. Thus, the sum is 2.

**Example 2:**

**Input:** nums = [3,6,2,8]

**Output:** 5

**Explanation:**

Construct `prefixGcd`:

| `i` | `nums[i]` | `mxi` | `prefixGcd[i]` |
| --- | --- | --- | --- |
| 0 | 3 | 3 | 3 |
| 1 | 6 | 6 | 6 |
| 2 | 2 | 6 | 2 |
| 3 | 8 | 8 | 8 |

`prefixGcd = [3, 6, 2, 8]`. After sorting, it forms `[2, 3, 6, 8]`.

Form pairs: `gcd(2, 8) = 2` and `gcd(3, 6) = 3`. Thus, the sum is `2 + 3 = 5`.

**Constraints:**

* `1 <= n == nums.length <= 105`
* `1 <= nums[i] <= 10​​​​​​​9`

---

## Solution & Editorial
# Intuition
The problem requires a two-stage transformation: first, computing a prefix-based GCD array, and second, pairing elements from the sorted version of this array. The core observation is that the prefix maximum `mxi` is non-decreasing, which allows us to compute the `prefixGcd` array in a single linear pass. Once sorted, the pairing strategy is a standard greedy approach using two pointers.

# Approach
1. **Prefix GCD Construction**: Initialize `maxi` to track the running maximum. Iterate through `nums`, updating `maxi = max(maxi, nums[i])` and calculating `prefixGcd[i] = gcd(nums[i], maxi)`.
2. **Sorting**: Sort the `prefixGcd` array in non-decreasing order to facilitate the pairing process.
3. **Greedy Pairing**: Use two pointers, `l` at the start (0) and `r` at the end (`n-1`). While `l < r`, add `gcd(prefixGcd[l], prefixGcd[r])` to the total sum and move the pointers inward (`l++`, `r--`).

### Visual Trace (Example 1: nums = [2, 6, 4])
| Step | i | nums[i] | maxi | prefixGcd[i] |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 2 | 2 | 2 |
| 2 | 1 | 6 | 6 | 6 |
| 3 | 2 | 4 | 6 | 2 |

- `prefixGcd` = [2, 6, 2] -> Sorted: [2, 2, 6]
- Pair (2, 6): `gcd(2, 6) = 2`. Sum = 2.

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step. The prefix GCD construction and the two-pointer traversal are both $$O(N)$$.
- Space complexity: $$O(N)$$ to store the `prefixGcd` array.

# Code
```cpp
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int maxi = -1;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;
        int l = 0;
        int r = n - 1;

        while (l < r) {
            ans += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }

        return ans;
    }
};
```

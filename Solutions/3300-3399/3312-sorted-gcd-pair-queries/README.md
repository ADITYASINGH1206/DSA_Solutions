# [3312. Sorted GCD Pair Queries](https://leetcode.com/problems/sorted-gcd-pair-queries/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `math`, `binary-search`, `combinatorics`, `counting`, `number-theory`, `prefix-sum`, `euclidean-algorithm`, `greatest-common-divisor`

---

## Problem Description
You are given an integer array `nums` of length `n` and an integer array `queries`.

Let `gcdPairs` denote an array obtained by calculating the GCD of all possible pairs `(nums[i], nums[j])`, where `0 <= i < j < n`, and then sorting these values in **ascending** order.

For each query `queries[i]`, you need to find the element at index `queries[i]` in `gcdPairs`.

Return an integer array `answer`, where `answer[i]` is the value at `gcdPairs[queries[i]]` for each query.

The term `gcd(a, b)` denotes the **greatest common divisor** of `a` and `b`.

**Example 1:**

**Input:** nums = [2,3,4], queries = [0,2,2]

**Output:** [1,2,2]

**Explanation:**

`gcdPairs = [gcd(nums[0], nums[1]), gcd(nums[0], nums[2]), gcd(nums[1], nums[2])] = [1, 2, 1]`.

After sorting in ascending order, `gcdPairs = [1, 1, 2]`.

So, the answer is `[gcdPairs[queries[0]], gcdPairs[queries[1]], gcdPairs[queries[2]]] = [1, 2, 2]`.

**Example 2:**

**Input:** nums = [4,4,2,1], queries = [5,3,1,0]

**Output:** [4,2,1,1]

**Explanation:**

`gcdPairs` sorted in ascending order is `[1, 1, 1, 2, 2, 4]`.

**Example 3:**

**Input:** nums = [2,2], queries = [0,0]

**Output:** [2,2]

**Explanation:**

`gcdPairs = [2]`.

**Constraints:**

* `2 <= n == nums.length <= 105`
* `1 <= nums[i] <= 5 * 104`
* `1 <= queries.length <= 105`
* `0 <= queries[i] < n * (n - 1) / 2`

---

## Solution & Editorial
# Intuition
To solve this problem efficiently, we avoid calculating all $O(N^2)$ pairs directly. Instead, we count how many pairs have a GCD equal to $g$ for every possible $g$ in the range $[1, \max(nums)]$. By using the principle of inclusion-exclusion, we can derive the exact count of pairs for each GCD value and then use prefix sums to answer queries via binary search.

# Approach
1. **Frequency Count**: Count the occurrences of each number in `nums` using a frequency array `freq` of size $M = \max(nums) + 1$.
2. **Inclusion-Exclusion**: For a fixed $g$, let $cnt$ be the number of elements in `nums` that are multiples of $g$. The total number of pairs $(nums[i], nums[j])$ where both are multiples of $g$ is $\frac{cnt(cnt-1)}{2}$. This value includes pairs whose GCD is $g, 2g, 3g, \dots$. We calculate the exact number of pairs with GCD exactly $g$ by subtracting the counts of pairs with GCD $2g, 3g, \dots$ from the total.
3. **Prefix Sums**: Construct a prefix sum array `pref` where `pref[g]` stores the total number of pairs with GCD $\le g$.
4. **Query Processing**: For each query $q$, use `std::lower_bound` on the `pref` array to find the smallest $g$ such that `pref[g] > q`.

### Visual Trace (Example 1: nums=[2,3,4])
- `freq`: [0, 0, 1, 1, 1] (indices 0-4)
- `exact` calculation (from $g=4$ down to 1):
  - $g=4$: $cnt=1$, $exact[4] = 0$
  - $g=3$: $cnt=1$, $exact[3] = 0$
  - $g=2$: $cnt=2$ (2, 4), $pairs = 1$, $exact[2] = 1 - exact[4] = 1$
  - $g=1$: $cnt=3$ (2, 3, 4), $pairs = 3$, $exact[1] = 3 - (exact[2] + exact[3] + exact[4]) = 3 - (1 + 0 + 0) = 2$
- `pref`: [0, 2, 3, 3, 3]
- Query 0: `lower_bound` finds index 1. Query 2: `lower_bound` finds index 2.

# Complexity
- Time complexity: $$O(M \log M + Q \log M)$$, where $M = \max(nums)$ and $Q$ is the number of queries. The nested loops for inclusion-exclusion run in $O(M/1 + M/2 + \dots + M/M) = O(M \log M)$.
- Space complexity: $$O(M)$$ to store the frequency, exact counts, and prefix sum arrays.

# Code
```cpp
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxE = *max_element(nums.begin(), nums.end());

        vector<long long> freq(maxE + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        vector<long long> exact(maxE + 1, 0);

        for (int gcd = maxE; gcd >= 1; gcd--) {
            long long cnt = 0;

            for (int times = gcd; times <= maxE; times += gcd) {
                cnt += freq[times];
            }

            exact[gcd] = cnt * (cnt - 1) / 2;

            for (int times = 2 * gcd; times <= maxE; times += gcd) {
                exact[gcd] -= exact[times];
            }
        }

        vector<long long> pref(maxE + 1, 0);
        for (int gcd = 1; gcd <= maxE; gcd++) {
            pref[gcd] = pref[gcd - 1] + exact[gcd];
        }

        vector<int> result;
        for (long long q : queries) {
            int gcd = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            result.push_back(gcd);
        }

        return result;
    }
};
```

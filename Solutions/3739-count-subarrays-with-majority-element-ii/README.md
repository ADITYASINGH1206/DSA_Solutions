# [3739. Count Subarrays With Majority Element II](https://leetcode.com/problems/count-subarrays-with-majority-element-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `divide-and-conquer`, `segment-tree`, `merge-sort`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` and an integer `target`.

Return the number of **subarrays** of `nums` in which `target` is the **majority element**.

The **majority element** of a subarray is the element that appears **strictly more than half** of the times in that subarray.

**Example 1:**

**Input:** nums = [1,2,2,3], target = 2

**Output:** 5

**Explanation:**

Valid subarrays with `target = 2` as the majority element:

* `nums[1..1] = [2]`
* `nums[2..2] = [2]`
* `nums[1..2] = [2,2]`
* `nums[0..2] = [1,2,2]`
* `nums[1..3] = [2,2,3]`

So there are 5 such subarrays.

**Example 2:**

**Input:** nums = [1,1,1,1], target = 1

**Output:** 10

**Explanation:**

**​​​​​​​**All 10 subarrays have 1 as the majority element.

**Example 3:**

**Input:** nums = [1,2,3], target = 4

**Output:** 0

**Explanation:**

`target = 4` does not appear in `nums` at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.

**Constraints:**

* `1 <= nums.length <= 10​​​​​​​5`
* `1 <= nums[i] <= 10​​​​​​​9`
* `1 <= target <= 109`

---

## Solution & Editorial
# Intuition
To determine if `target` is the majority element in a subarray, we need the count of `target` to be strictly greater than the count of all other elements combined. By transforming the array into a sequence where `target` is represented as `+1` and all other elements as `-1`, the condition "majority element" becomes equivalent to finding subarrays with a sum strictly greater than 0.

# Approach
1. Transform the problem: Let `val = 1` if `nums[i] == target`, else `val = -1`. A subarray `nums[i..j]` has `target` as the majority if the sum of transformed values in that range is `> 0`.
2. Let `P[k]` be the prefix sum of the transformed array up to index `k`. The condition for `nums[i..j]` is `P[j] - P[i-1] > 0`, or `P[j] > P[i-1]`.
3. We iterate through the array, maintaining the current prefix sum `pref`. For each index, we need to count how many previous prefix sums were strictly less than the current `pref`.
4. We use a frequency array `freq` to store the occurrences of prefix sums encountered so far. Since prefix sums range from `-N` to `N`, we offset the index by `N` to keep it non-negative.
5. As we iterate, we update the count of valid subarrays by adding the number of previously seen prefix sums smaller than the current one.

### Visual Trace (nums = [1, 2, 2, 3], target = 2)
| Index | Num | Val | Pref | Freq Map (offset 4) | Less (Count of P < Pref) | Ans |
|---|---|---|---|---|---|---|
| - | - | - | 4 | {4:1} | 0 | 0 |
| 0 | 1 | -1 | 3 | {3:1, 4:1} | 0 | 0 |
| 1 | 2 | 1 | 4 | {3:1, 4:2} | 1 | 1 |
| 2 | 2 | 1 | 5 | {3:1, 4:2, 5:1} | 3 | 4 |
| 3 | 3 | -1 | 4 | {3:1, 4:3, 5:1} | 1 | 5 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass over the input array, and each update/lookup in the frequency array is $$O(1)$$.
- Space complexity: $$O(N)$$, required for the frequency array of size $$2N+1$$.

# Code
```cpp
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int size = nums.size(), pref = size;

        vector<int> freq(2 * size + 1);
        freq[size] = 1;

        long long less = 0, ans = 0;

        for (int num : nums) {
            if (num == target)
                less += freq[pref++];
            else
                less -= freq[--pref];

            ++freq[pref];
            ans += less;
        }

        return ans;
    }
};
```

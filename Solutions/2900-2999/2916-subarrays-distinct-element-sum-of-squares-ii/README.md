# [2916. Subarrays Distinct Element Sum of Squares II](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `binary-indexed-tree`, `segment-tree`

---

## Problem Description
You are given a **0-indexed** integer array `nums`.

The **distinct count** of a subarray of `nums` is defined as:

* Let `nums[i..j]` be a subarray of `nums` consisting of all the indices from `i` to `j` such that `0 <= i <= j < nums.length`. Then the number of distinct values in `nums[i..j]` is called the distinct count of `nums[i..j]`.

Return *the sum of the **squares** of **distinct counts** of all subarrays of* `nums`.

Since the answer may be very large, return it **modulo** `109 + 7`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**

```
Input: nums = [1,2,1]
Output: 15
Explanation: Six possible subarrays are:
[1]: 1 distinct value
[2]: 1 distinct value
[1]: 1 distinct value
[1,2]: 2 distinct values
[2,1]: 2 distinct values
[1,2,1]: 2 distinct values
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 + 22 + 22 + 22 = 15.
```

**Example 2:**

```
Input: nums = [2,2]
Output: 3
Explanation: Three possible subarrays are:
[2]: 1 distinct value
[2]: 1 distinct value
[2,2]: 1 distinct value
The sum of the squares of the distinct counts in all subarrays is equal to 12 + 12 + 12 = 3.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To compute the sum of squares of distinct counts for all subarrays, we observe that as we iterate through the array with index `i`, the distinct count of subarrays ending at `i` changes. Specifically, for a subarray `nums[j..i]`, if `nums[i]` has appeared previously at index `prev`, the distinct count for all subarrays starting from `prev + 1` to `i` increases by 1. We need to maintain the sum of squares of these counts efficiently as we slide the right boundary `i`.

# Approach
1. We use a Segment Tree where each node stores the sum of counts (`sum`) and the sum of squares of counts (`sqsum`) for the current range of starting positions `j`.
2. When moving from `i` to `i+1`, if `nums[i+1]` was last seen at `prev`, the distinct count for all subarrays starting in the range `[prev + 1, i + 1]` increases by 1. 
3. The update rule for the square sum is: if a range of counts $c$ is updated to $c+1$, the new square sum becomes $\sum (c+1)^2 = \sum (c^2 + 2c + 1) = \sum c^2 + 2\sum c + \text{length}$.
4. We use lazy propagation in the segment tree to apply this update in $O(\log N)$ time.

### Visual Trace (nums = [1, 2, 1])
| i | nums[i] | prev | Range Updated | sqsum (Total)
|---|---|---|---|---|
| 0 | 1 | -1 | [0, 0] | 1^2 = 1
| 1 | 2 | -1 | [0, 1] | 1^2 + 2^2 = 5
| 2 | 1 | 0 | [1, 2] | 5 + (2^2 + 2^2) = 15

# Complexity
- Time complexity: $$O(N \log N)$$ — We iterate through the array once, and each update operation on the segment tree takes $$O(\log N)$$.
- Space complexity: $$O(N)$$ — The segment tree requires $$O(N)$$ space to store nodes, and the hash map stores at most $$N$$ distinct elements.

# Code
```cpp
class Solution {
public:
    typedef long long ll;
    static const int MOD = 1e9 + 7;
    struct Node {
        ll sum = 0;
        ll sqsum = 0;
        ll lazy = 0;
    };
    vector<Node> seg;
    void apply(int i, int l, int r, ll val) {
        ll len = r - l + 1;
        seg[i].sqsum += 2LL * val * seg[i].sum + len * val * val;
        seg[i].sum += len * val;
        seg[i].lazy += val;
    }
    void updateRange(int start, int end,int i, int l, int r, ll val) {
        if (seg[i].lazy != 0) {
            if (l != r) {
                apply(2 * i + 1, l, (l + r) / 2, seg[i].lazy);
                apply(2 * i + 2, (l + r) / 2 + 1, r, seg[i].lazy);
            }
            seg[i].lazy = 0;
        }

        if (l > end || r < start || l > r) return;
        if (l >= start && r <= end) {
            apply(i, l, r, val);
            return;
        }
        int mid = (l + r) / 2;
        updateRange(start, end, 2 * i + 1, l, mid, val);
        updateRange(start, end, 2 * i + 2, mid + 1, r, val);
        seg[i].sum = seg[2 * i + 1].sum + seg[2 * i + 2].sum;
        seg[i].sqsum = seg[2 * i + 1].sqsum + seg[2 * i + 2].sqsum;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n);
        unordered_map<int, int> last;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = -1;
            if (last.count(nums[i])) prev = last[nums[i]];
            updateRange(prev + 1, i, 0, 0, n - 1, 1);
            ans = (ans + seg[0].sqsum) % MOD;
            last[nums[i]] = i;
        }
        return (int)ans;
    }
};
```

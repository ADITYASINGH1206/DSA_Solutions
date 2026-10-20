# [4035. Maximum Valid Split Positions I](https://leetcode.com/problems/maximum-valid-split-positions-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `enumeration`, `number-theory`

---

## Problem Description
You are given an integer array `nums`.

You may remove **at most one** element from `nums`. Let `arr` be the array of remaining elements in their original order, and let `m` be its length.

A **split position** `i` of `arr` is **valid** if:

* `0 <= i < m - 1`, and
* `gcd(arr[0..i]) == gcd(arr[i + 1..m - 1])`.

An array of length 1 has no valid split positions.

The **score** of `arr` is the number of valid split positions in it.

Return the **maximum possible score** of `arr`.

Here, `gcd(a)` denotes the **greatest common divisor** of all elements in the array `a`.

**Example 1:**

**Input:** nums = [10,30,15,10]

**Output:** 2

**Explanation:**

One optimal solution is to remove `nums[2] = 15`. Then `arr = [10, 30, 10]`.

The split positions are:

| Split Position `i` | `gcd(arr[0..i])` | `gcd(arr[i + 1..m - 1])` |
| --- | --- | --- |
| 0 | 10 | 10 |
| 1 | 10 | 10 |

All split positions are valid. Thus, the answer is 2.

**Example 2:**

**Input:** nums = [2,10,14]

**Output:** 1

**Explanation:**

One optimal solution is to not remove any element. Then `arr = [2, 10, 14]`.

The split positions are:

| Split Position `i` | `gcd(arr[0..i])` | `gcd(arr[i + 1..m - 1])` |
| --- | --- | --- |
| 0 | 2 | 2 |
| 1 | 2 | 14 |

Only the split position at index 0 is valid. Thus, the answer is 1.

**Example 3:**

**Input:** nums = [2,4]

**Output:** 0

**Explanation:**

The only remaining array that has a split position is `arr = [2, 4]`.

The split positions are:

| Split Position `i` | `gcd(arr[0..i])` | `gcd(arr[i + 1..m - 1])` |
| --- | --- | --- |
| 0 | 2 | 4 |

There are no valid split positions. Thus, the answer is 0.

**Constraints:**

* `2 <= nums.length <= 1000`
* `1 <= nums[i] <= 109`​​​​​​​

---

## Solution & Editorial
# Intuition
To find the maximum number of valid split positions after removing at most one element, we observe that the constraints ($N \le 1000$) allow for an $O(N^2)$ approach. By iterating through every possible element to remove (or removing none), we can construct the resulting array and efficiently calculate the GCD of all prefix and suffix subarrays to determine the number of valid split positions.

# Approach
1. Iterate through every index `skip` from `-1` to `n-1`. `skip = -1` represents the case where no element is removed.
2. For each `skip`, construct the temporary array `arr` by excluding `nums[skip]`.
3. Precompute `left[i]` as the GCD of `arr[0...i]` and `right[i]` as the GCD of `arr[i...m-1]` using prefix and suffix passes.
4. A split position `i` is valid if `left[i] == right[i+1]`. Count these occurrences.
5. Track the maximum count across all `skip` iterations.

### Visual Trace (Example 1: [10, 30, 15, 10])
Removing index 2 (value 15) results in `arr = [10, 30, 10]`:
| Index | `arr[i]` | `left[i]` | `right[i]` |
|-------|----------|-----------|------------|
| 0     | 10       | 10        | 10         |
| 1     | 30       | 10        | 10         |
| 2     | 10       | 10        | 10         |

- Split at 0: `left[0]` (10) == `right[1]` (10) -> Valid
- Split at 1: `left[1]` (10) == `right[2]` (10) -> Valid
- Total Score: 2

# Complexity
- Time complexity: $$O(N^2 \log M)$$ where $$N$$ is the length of `nums` and $$M$$ is the maximum value in `nums`. We iterate $$N$$ times, and for each iteration, we perform linear scans and GCD operations ($$\log M$$).
- Space complexity: $$O(N)$$ to store the temporary array `arr` and the `left`/`right` GCD arrays.

# Code
```cpp
class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int skip = -1; skip < n; skip++) {

            vector<int> arr;
            arr.reserve(n);
            for (int i = 0; i < n; ++i) {
                if (i != skip) {
                    arr.push_back(nums[i]);
                }
            }
            int m = arr.size();
            if (m <= 1) continue; 

            vector<int> left(m), right(m);
            
            left[0] = arr[0];
            for (int i = 1; i < m; ++i) {
                left[i] = gcd(left[i - 1], arr[i]);
            }
            
            right[m - 1] = arr[m - 1];
            for (int i = m - 2; i >= 0; --i) {
                right[i] = gcd(right[i + 1], arr[i]);
            }
            int score = 0;
            for (int i = 0; i < m - 1; ++i) {
                if (left[i] == right[i + 1]) {
                    score++;
                }
            }
            ans = max(ans, score);
        }
        
        return ans;
    }
};
```

# [1608. Special Array With X Elements Greater Than or Equal X](https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/)
**Difficulty:** `Easy` | **Tags:** `array`, `binary-search`, `sorting`

---

## Problem Description
You are given an array `nums` of non-negative integers. `nums` is considered **special** if there exists a number `x` such that there are **exactly** `x` numbers in `nums` that are **greater than or equal to** `x`.

Notice that `x` **does not** have to be an element in `nums`.

Return `x` *if the array is **special**, otherwise, return* `-1`. It can be proven that if `nums` is special, the value for `x` is **unique**.

**Example 1:**

```
Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
```

**Example 2:**

```
Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.
```

**Example 3:**

```
Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks for a value $x$ such that exactly $x$ elements in the array are $\ge x$. Since the number of elements $\ge x$ is monotonically non-increasing as $x$ increases, we can binary search for the optimal $x$ in the range $[0, N]$, where $N$ is the size of the array.

# Approach
1. Sort the array `nums` to facilitate potential optimizations, though the core logic relies on checking the count of elements $\ge x$ for a given candidate $x$.
2. Define the search space for $x$ as $[0, N]$.
3. In each iteration of the binary search, calculate `mid` as the candidate $x$.
4. Use a helper function `count` to determine how many elements in `nums` are $\ge mid$.
5. If `count == mid`, we found the special value $x$.
6. If `count > mid`, the current $x$ is too small, so we search the right half (`start = mid + 1`).
7. If `count < mid`, the current $x$ is too large, so we search the left half (`end = mid - 1`).

### Visual Trace (Example 3: nums = [0, 4, 3, 0, 4])
Sorted: `[0, 0, 3, 4, 4]`, $N=5$. Search range $[0, 5]$.

| Iteration | Start | End | Mid | Count(mid) | Action |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 5 | 2 | 3 | Count > Mid, Start = 3 |
| 2 | 3 | 5 | 4 | 2 | Count < Mid, End = 3 |
| 3 | 3 | 3 | 3 | 3 | Found! Return 3 |

# Complexity
- Time complexity: $$O(N \log N)$$ due to sorting the array initially, followed by $O(\log N)$ iterations of binary search, each performing an $O(N)$ linear scan.
- Space complexity: $$O(1)$$ auxiliary space (ignoring the space required for sorting, which depends on the implementation).

# Code
```cpp
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int start = 0;
        int end = nums.size();

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int ans = count(nums, mid);

            if (ans == mid) return mid;
            else if (ans > mid) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }
    int count(vector<int>& nums, int target) {
        int ans = 0;
        for (int num : nums) {
            if (num >= target) ans++;
        }
        return ans;
    }
};
```

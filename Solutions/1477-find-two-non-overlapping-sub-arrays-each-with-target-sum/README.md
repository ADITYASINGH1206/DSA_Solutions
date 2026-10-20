# [1477. Find Two Non-overlapping Sub-arrays Each With Target Sum](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `binary-search`, `dynamic-programming`, `sliding-window`

---

## Problem Description
You are given an array of integers `arr` and an integer `target`.

You have to find **two non-overlapping sub-arrays** of `arr` each with a sum equal `target`. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is **minimum**.

Return *the minimum sum of the lengths* of the two required sub-arrays, or return `-1` if you cannot find such two sub-arrays.

**Example 1:**

```
Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
```

**Example 2:**

```
Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.
```

**Example 3:**

```
Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.
```

**Constraints:**

* `1 <= arr.length <= 105`
* `1 <= arr[i] <= 1000`
* `1 <= target <= 108`

---

## Solution & Editorial
# Intuition
The problem asks for two non-overlapping subarrays with a specific sum whose combined length is minimal. Since all elements are positive, we can use a sliding window to efficiently find all subarrays that sum to `target`. To ensure the subarrays are non-overlapping, we maintain a prefix minimum length array `dp`, where `dp[i]` stores the length of the shortest subarray found so far that ends at or before index `i`.

# Approach
1. Initialize a `dp` array of size `n` with a value `INF` (e.g., `n + 1`). `dp[i]` will represent the minimum length of a subarray with sum `target` in the range `arr[0...i]`.
2. Use a sliding window defined by `left` and `right` pointers to maintain a running `sum` of elements.
3. Iterate through the array with the `right` pointer:
   - Add `arr[right]` to `sum`.
   - While `sum > target`, subtract `arr[left]` and increment `left`.
   - If `sum == target`:
     - The current subarray length is `len = right - left + 1`.
     - If `left > 0` and `dp[left - 1]` is not `INF`, it means there is a valid subarray ending before the current one starts. Update the global minimum `ans = min(ans, len + dp[left - 1])`.
     - Update `dp[right] = len`.
4. After processing the window at each `right`, update `dp[right] = min(dp[right], dp[right - 1])` to ensure `dp[right]` always stores the minimum length found in the prefix `0...right`.
5. If `ans` remains `INF`, return `-1`; otherwise, return `ans`.

### Visual Trace: Example 1
`arr = [3, 2, 2, 4, 3]`, `target = 3`

| right | sum | left | Subarray | len | dp[right] | ans |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 3 | 0 | [3] | 1 | 1 | INF |
| 1 | 2 | 0 | - | - | 1 | INF |
| 2 | 2 | 1 | - | - | 1 | INF |
| 3 | 4 | 3 | - | - | 1 | INF |
| 4 | 3 | 4 | [3] | 1 | 1 | 2 (1 + dp[3]) |

Final `ans = 2`.

# Complexity
- Time complexity: $$O(N)$$
Each element is visited at most twice (once by `right` and once by `left`). All operations inside the loop are $$O(1)$$.

- Space complexity: $$O(N)$$
We use an auxiliary array `dp` of size $N$ to store the minimum lengths of valid subarrays found in prefixes.

# Code
```cpp
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        int INF = n + 1;

        vector<int> dp(n, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {

                int len = right - left + 1;

                if (left > 0 && dp[left - 1] != INF) {
                    ans = min(ans, len + dp[left - 1]);
                }

                dp[right] = len;
            }

            if (right > 0) {
                dp[right] = min(dp[right], dp[right - 1]);
            }
        }

        return ans == INF ? -1 : ans;
    }
};
```

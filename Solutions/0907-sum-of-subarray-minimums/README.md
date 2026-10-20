# [907. Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `stack`, `monotonic-stack`

---

## Problem Description
Given an array of integers arr, find the sum of `min(b)`, where `b` ranges over every (contiguous) subarray of `arr`. Since the answer may be large, return the answer **modulo** `109 + 7`.

**Example 1:**

```
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
```

**Example 2:**

```
Input: arr = [11,81,94,43,3]
Output: 444
```

**Constraints:**

* `1 <= arr.length <= 3 * 104`
* `1 <= arr[i] <= 3 * 104`

---

## Solution & Editorial
# Intuition
To find the sum of minimums of all contiguous subarrays, we can shift our perspective from counting subarrays to determining the contribution of each individual element `arr[i]` as the minimum element. An element `arr[i]` will serve as the minimum for any subarray that starts anywhere between its previous smaller element and ends anywhere before its next smaller element.

# Approach
1. For every index `i`, we define `left[i]` as the number of elements in the maximal contiguous subarray ending at `i` where `arr[i]` is the minimum (using strict inequality on one side and non-strict inequality on the other to prevent double counting duplicates).
2. Similarly, we define `right[i]` as the number of elements in the maximal contiguous subarray starting at `i` where `arr[i]` is the minimum.
3. We utilize two monotonic stacks `s1` and `s2` to compute `left` and `right` arrays in linear time. Stack `s1` finds the previous lesser-or-equal element, while stack `s2` finds the next strictly lesser element.
4. Finally, the total contribution of `arr[i]` is calculated as `arr[i] * left[i] * right[i]`. We accumulate these contributions modulo $10^9 + 7$.

### Visual Trace Walkthrough
For `arr = [3, 1, 2, 4]`:
- `i = 0`: `arr[0] = 3`, `left[0] = 1`, `right[0] = 1` -> contribution = `3 * 1 * 1 = 3`
- `i = 1`: `arr[1] = 1`, `left[1] = 2`, `right[1] = 3` -> contribution = `1 * 2 * 3 = 6`
- `i = 2`: `arr[2] = 2`, `left[2] = 1`, `right[2] = 2` -> contribution = `2 * 1 * 2 = 4`
- `i = 3`: `arr[3] = 4`, `left[3] = 1`, `right[3] = 1` -> contribution = `4 * 1 * 1 = 4`
- Total sum = `3 + 6 + 4 + 4 = 17`.

# Complexity
- Time complexity: $$O(N)$$ — Each index is pushed and popped from the monotonic stacks at most once. The final accumulation loop runs in linear time.
- Space complexity: $$O(N)$$ — Auxiliary memory is used for the `left` and `right` vectors, and two stacks of size up to $N$.

# Code
```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        
        vector<int> left(n);
        vector<int> right(n);
        
        stack<int> s1; 
        stack<int> s2; 
        
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] >= arr[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && arr[s2.top()] > arr[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long contribution = (long long)arr[i] * left[i] * right[i];
            ans = (ans + contribution) % MOD;
        }
        
        return ans;
    }
};
```

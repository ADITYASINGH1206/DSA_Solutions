# [3897. Maximum Value of Concatenated Binary Segments](https://leetcode.com/problems/maximum-value-of-concatenated-binary-segments/)
**Difficulty:** `Hard` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given two integer arrays `nums1` and `nums0`, each of size `n`.

* `nums1[i]` represents the number of `'1'`s in the `ith` segment.
* `nums0[i]` represents the number of `'0'`s in the `ith` segment.

For each index `i`, construct a binary segment consisting of:

* `nums1[i]` occurrences of `'1'` followed by
* `nums0[i]` occurrences of `'0'`.

You may **rearrange** the order of these **segments** in any way. After rearranging, **concatenate** all segments to form a single binary string.

Return the **maximum** possible integer value of the concatenated binary string.

Since the result can be very large, return the answer **modulo** `109 + 7`.

**Example 1:**

**Input:** nums1 = [1,2], nums0 = [1,0]

**Output:** 14

**Explanation:**

* At index 0, `nums1[0] = 1` and `nums0[0] = 1`, so the segment formed is `"10"`.
* At index 1, `nums1[1] = 2` and `nums0[1] = 0`, so the segment formed is `"11"`.
* Reordering the segments as `"11"` followed by `"10"` produces the binary string `"1110"`.
* The binary number `"1110"` has value 14 which is the maximum possible value.

**Example 2:**

**Input:** nums1 = [3,1], nums0 = [0,3]

**Output:** 120

**Explanation:**

* At index 0, `nums1[0] = 3` and `nums0[0] = 0`, so the segment formed is `"111"`.
* At index 1, `nums1[1] = 1` and `nums0[1] = 3`, so the segment formed is `"1000"`.
* Reordering the segments as `"111"` followed by `"1000"` produces the binary string `"1111000"`.
* The binary number `"1111000"` has value 120 which is the maximum possible value.

**Constraints:**

* `1 <= n == nums1.length == nums0.length <= 105`
* `0 <= nums1[i], nums0[i] <= 104`
* `nums1[i] + nums0[i] > 0`
* The total sum of all elements in `nums1` and `nums0` does not exceed 2 \* 105.

---

## Solution & Editorial
# Intuition
To maximize the value of a concatenated binary string, we must determine the optimal relative order of any two segments $A$ and $B$. Given two segments, we should place $A$ before $B$ if the concatenated string $A+B$ represents a larger binary value than $B+A$. This is a classic greedy sorting problem where the comparison function `a + b > b + a` defines a strict weak ordering, ensuring the globally optimal concatenation.

# Approach
1. Construct each segment as a string consisting of `nums1[i]` ones followed by `nums0[i]` zeros.
2. Sort the collection of segments using a custom comparator: `a + b > b + a`. This ensures that for any two segments, we choose the order that yields the lexicographically larger binary string.
3. Iterate through the sorted segments and compute the final value modulo $10^9 + 7$. Since the total length is at most $2 \times 10^5$, we process the bits sequentially using the property: `new_val = (old_val * 2 + bit) % MOD`.

### Visual Trace (Example 1: nums1=[1,2], nums0=[1,0])
- Segments: `S0 = "10"`, `S1 = "11"`
- Compare `S0+S1` ("1011") vs `S1+S0` ("1110").
- Since "1110" > "1011", order is `[S1, S0]`.
- Concatenate: "11" + "10" = "1110".
- Value: $1 \to 3 \to 7 \to 14$.

# Complexity
- Time complexity: $$O(L \log N)$$, where $L$ is the total number of bits (sum of `nums1` and `nums0`) and $N$ is the number of segments. The sorting takes $O(N \log N)$ comparisons, each taking $O(L/N)$ time on average.
- Space complexity: $$O(L)$$, required to store the concatenated segments as strings.

# Code
```cpp
class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<string> segments;
        for(int i = 0; i < n; i++) {
            string temp = string(nums1[i], '1') + string(nums0[i], '0');
            segments.push_back(temp);
        }
        
        sort(segments.begin(), segments.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        long long MOD = 1e9 + 7;
        long long ans = 0;
        
        for (string seg : segments) {
            for (char c : seg) {
                ans = (ans * 2 + (c - '0')) % MOD;
            }
        }
        
        return ans;
    }
};
```

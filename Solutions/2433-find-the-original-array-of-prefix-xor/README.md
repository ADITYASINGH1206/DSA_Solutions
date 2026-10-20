# [2433. Find The Original Array of Prefix Xor](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/)
**Difficulty:** `Medium` | **Tags:** `array`, `bit-manipulation`

---

## Problem Description
You are given an **integer** array `pref` of size `n`. Find and return *the array* `arr` *of size* `n` *that satisfies*:

* `pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]`.

Note that `^` denotes the **bitwise-xor** operation.

It can be proven that the answer is **unique**.

**Example 1:**

```
Input: pref = [5,2,0,3,1]
Output: [5,7,2,3,2]
Explanation: From the array [5,7,2,3,2] we have the following:
- pref[0] = 5.
- pref[1] = 5 ^ 7 = 2.
- pref[2] = 5 ^ 7 ^ 2 = 0.
- pref[3] = 5 ^ 7 ^ 2 ^ 3 = 3.
- pref[4] = 5 ^ 7 ^ 2 ^ 3 ^ 2 = 1.
```

**Example 2:**

```
Input: pref = [13]
Output: [13]
Explanation: We have pref[0] = arr[0] = 13.
```

**Constraints:**

* `1 <= pref.length <= 105`
* `0 <= pref[i] <= 106`

---

## Solution & Editorial
# Intuition
The problem defines `pref[i]` as the XOR sum of elements from `arr[0]` to `arr[i]`. By definition, `pref[i] = pref[i-1] ^ arr[i]` for `i > 0`. Using the property of XOR where `a ^ b = c` implies `a ^ c = b`, we can derive `arr[i] = pref[i] ^ pref[i-1]`.

# Approach
1. Initialize a result vector `ans` of size `n`.
2. Set `ans[0] = pref[0]` because `pref[0] = arr[0]`.
3. For each index `i` from `1` to `n-1`, calculate `ans[i]` as `pref[i] ^ pref[i-1]`.
4. Return the `ans` vector.

### Visual Trace (Example 1: pref = [5, 2, 0, 3, 1])
| i | pref[i] | pref[i-1] | Calculation (pref[i] ^ pref[i-1]) | ans[i] |
|---|---|---|---|---|
| 0 | 5 | - | Initial | 5 |
| 1 | 2 | 5 | 2 ^ 5 | 7 |
| 2 | 0 | 2 | 0 ^ 2 | 2 |
| 3 | 3 | 0 | 3 ^ 0 | 3 |
| 4 | 1 | 3 | 1 ^ 3 | 2 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input array, as we iterate through the array exactly once.
- Space complexity: $$O(N)$$ to store the resulting array `ans`.

# Code
```cpp
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans = {pref[0]};
        for (int i = 1; i < n; ++i) {
            ans.push_back(pref[i - 1] ^ pref[i]);
        }
        return ans;
    }
};
```

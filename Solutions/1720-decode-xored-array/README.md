# [1720. Decode XORed Array](https://leetcode.com/problems/decode-xored-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `bit-manipulation`

---

## Problem Description
There is a **hidden** integer array `arr` that consists of `n` non-negative integers.

It was encoded into another integer array `encoded` of length `n - 1`, such that `encoded[i] = arr[i] XOR arr[i + 1]`. For example, if `arr = [1,0,2,1]`, then `encoded = [1,2,3]`.

You are given the `encoded` array. You are also given an integer `first`, that is the first element of `arr`, i.e. `arr[0]`.

Return *the original array* `arr`. It can be proved that the answer exists and is unique.

**Example 1:**

```
Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
```

**Example 2:**

```
Input: encoded = [6,2,7,3], first = 4
Output: [4,2,0,7,4]
```

**Constraints:**

* `2 <= n <= 104`
* `encoded.length == n - 1`
* `0 <= encoded[i] <= 105`
* `0 <= first <= 105`

---

## Solution & Editorial
# Intuition
The problem defines the relationship `encoded[i] = arr[i] ^ arr[i + 1]`. By applying the property of XOR where `a ^ b = c` implies `a ^ c = b`, we can derive the next element in the original array using the previous element and the current encoded value.

# Approach
1. Initialize a result vector `ans` with the given `first` element.
2. Iterate through each element `x` in the `encoded` array.
3. For each `x`, calculate the next element by XORing the last element added to `ans` (i.e., `ans.back()`) with `x`.
4. Append this result to `ans`.

### Visual Trace (Example 1: encoded = [1, 2, 3], first = 1)
| Iteration | `x` (encoded[i]) | `ans.back()` | `ans.back() ^ x` | `ans` (Result) |
|-----------|------------------|--------------|------------------|----------------|
| Initial   | -                | -            | -                | [1]            |
| 1         | 1                | 1            | 1 ^ 1 = 0        | [1, 0]         |
| 2         | 2                | 0            | 0 ^ 2 = 2        | [1, 0, 2]      |
| 3         | 3                | 2            | 2 ^ 3 = 1        | [1, 0, 2, 1]   |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the `encoded` array. We perform a single pass over the input.
- Space complexity: $$O(N)$$ to store the resulting array of size $$N+1$$.

# Code
```cpp
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for (int x : encoded) {
            ans.push_back(ans.back() ^ x);
        }
        return ans;
    }
};
```

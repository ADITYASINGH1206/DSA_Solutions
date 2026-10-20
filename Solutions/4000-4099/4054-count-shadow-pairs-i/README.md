# [4054. Count Shadow Pairs I](https://leetcode.com/problems/count-shadow-pairs-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `monotonic-stack`

---

## Problem Description
You are given an integer array `nums` of length `n`.

A pair of indices `(i, j)` is called a **shadow pair** if all of the following conditions are satisfied:

* `0 <= i < j < n`
* `nums[i] < nums[j]`
* There **does not exist** an index `k` such that `i < k < j` and `nums[k] < nums[i] < nums[j]`.

Return the total number of **shadow pairs**.

**Example 1:**

**Input:** nums = [3,1,4,1,5]

**Output:** 3

**Explanation:**

| `(i, j)` | `nums[i]` | `nums[j]` | Shadow Pair |
| --- | --- | --- | --- |
| (1, 2) | 1 | 4 | No index `k` exists such that `1 < k < 2` |
| (1, 4) | 1 | 5 | `nums[2] = 4` and `nums[3] = 1` are not smaller than 1 |
| (3, 4) | 1 | 5 | No index `k` exists such that `3 < k < 4` |

Thus, the answer is 3.

**Example 2:**

**Input:** nums = [6,7,6,6,7]

**Output:** 4

**Explanation:**

| `(i, j)` | `nums[i]` | `nums[j]` | Shadow Pair |
| --- | --- | --- | --- |
| (0, 1) | 6 | 7 | No index `k` exists such that `0 < k < 1` |
| (0, 4) | 6 | 7 | `nums[1] = 7`, `nums[2] = 6`, and `nums[3] = 6` are not smaller than 6 |
| (2, 4) | 6 | 7 | `nums[3] = 6` is not smaller than 6 |
| (3, 4) | 6 | 7 | No index `k` exists such that `3 < k < 4` |

Thus, the answer is 4.

**Example 3:**

**Input:** nums = [1,2,3,4]

**Output:** 6

**Explanation:**

| `(i, j)` | `nums[i]` | `nums[j]` | Shadow Pair |
| --- | --- | --- | --- |
| (0, 1) | 1 | 2 | No index `k` exists such that `0 < k < 1` |
| (0, 2) | 1 | 3 | `nums[1] = 2` is not smaller than 1 |
| (0, 3) | 1 | 4 | `nums[1] = 2` and `nums[2] = 3` are not smaller than 1 |
| (1, 2) | 2 | 3 | No index `k` exists such that `1 < k < 2` |
| (1, 3) | 2 | 4 | `nums[2] = 3` is not smaller than 2 |
| (2, 3) | 3 | 4 | No index `k` exists such that `2 < k < 3` |

Thus, the answer is 6.

**Constraints:**

* `3 <= n == nums.length <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
The condition for a shadow pair $(i, j)$ is that $nums[i] < nums[j]$ and no $k$ exists in $(i, j)$ such that $nums[k] < nums[i]$. This implies that for a fixed $i$, any $j > i$ is a valid shadow pair if $nums[j] > nums[i]$ and all elements between $i$ and $j$ are $\ge nums[i]$. This effectively means $j$ must be within the range $[i+1, next\_smaller[i] - 1]$, where $next\_smaller[i]$ is the index of the first element to the right of $i$ that is strictly smaller than $nums[i]$.

# Approach
1. Use a **monotonic stack** to precompute `next_smaller[i]` for every index $i$. This array stores the index of the first element to the right that is smaller than $nums[i]$.
2. Store the indices of each unique value in a hash map `pos` to allow efficient range queries.
3. For each index $i$, the potential candidates for $j$ are in the range $(i, next\_smaller[i])$. Within this range, any $j$ such that $nums[j] > nums[i]$ satisfies the condition. 
4. Instead of counting $nums[j] > nums[i]$ directly, we count the total elements in $(i, next\_smaller[i])$ and subtract those where $nums[j] == nums[i]$.
5. Use `std::upper_bound` on the sorted index lists in `pos` to count occurrences of $nums[i]$ in the range $(i, next\_smaller[i])$.

### Visual Trace (nums = [3, 1, 4, 1, 5])
- `next_smaller`: [1, 5, 3, 5, 5]
- $i=0, nums[0]=3$: range $(0, 1)$, no $j$ exists.
- $i=1, nums[1]=1$: range $(1, 5)$, indices are {2, 3, 4}. Values are {4, 1, 5}. $nums[j] > 1$ for $j=2, 4$. Count = 2.
- $i=2, nums[2]=4$: range $(2, 3)$, no $j$ exists.
- $i=3, nums[3]=1$: range $(3, 5)$, index is {4}. Value is {5}. $nums[j] > 1$ for $j=4$. Count = 1.
- Total = 3.

# Complexity
- Time complexity: $$O(N \log N)$$. The monotonic stack takes $$O(N)$$. The loop runs $N$ times, and each `upper_bound` operation takes $$O(\log N)$$.
- Space complexity: $$O(N)$$ to store the `next_smaller` array, the stack, and the hash map of indices.

# Code
```cpp
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_smaller(n, n);
        vector<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                next_smaller[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int right_bound = next_smaller[i] - 1; 
            
            if (right_bound > i) {
                auto& indices = pos[nums[i]];
                int count_equal = upper_bound(indices.begin(), indices.end(), right_bound) - 
                                  upper_bound(indices.begin(), indices.end(), i);
                ans += (right_bound - i) - count_equal;
            }
        }
        
        return ans;
    }
};
```

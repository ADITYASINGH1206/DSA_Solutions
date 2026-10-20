# [1512. Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `math`, `counting`

---

## Problem Description
Given an array of integers `nums`, return *the number of **good pairs***.

A pair `(i, j)` is called *good* if `nums[i] == nums[j]` and `i` < `j`.

**Example 1:**

```
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
```

**Example 2:**

```
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
```

**Example 3:**

```
Input: nums = [1,2,3]
Output: 0
```

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem asks us to count pairs $(i, j)$ such that $i < j$ and $nums[i] == nums[j]$. A direct way to solve this is to iterate through all possible pairs. By starting the inner loop at the current index of the outer loop, we capture both the identity pairs (where $i=j$) and the valid good pairs (where $i < j$). Subtracting the total number of elements at the end effectively removes the identity pairs, leaving the count of good pairs.

# Approach
1. Initialize a counter `ans` to 0.
2. Use an outer loop with index `i` from 0 to `nums.size() - 1` to pick the first element of a potential pair.
3. Use an inner loop with index `j` starting from `i` to `nums.size() - 1` to pick the second element.
4. If `nums[i] == nums[j]`, increment `ans`. Note that when `i == j`, the condition is always true, so we count each element once as its own pair.
5. After both loops finish, `ans` contains the number of pairs $(i, j)$ where $i \le j$ and $nums[i] == nums[j]$.
6. Return `ans - nums.size()` to exclude the $n$ cases where $i = j$.

### Visual Trace (Example 1: `nums = [1, 2, 3, 1, 1, 3]`)
| i | j | nums[i] | nums[j] | Match? | ans (running) |
|---|---|---|---|---|---|
| 0 | 0 | 1 | 1 | Yes | 1 |
| 0 | 3 | 1 | 1 | Yes | 2 |
| 0 | 4 | 1 | 1 | Yes | 3 |
| 1 | 1 | 2 | 2 | Yes | 4 |
| 2 | 2 | 3 | 3 | Yes | 5 |
| 2 | 5 | 3 | 3 | Yes | 6 |
| 3 | 3 | 1 | 1 | Yes | 7 |
| 3 | 4 | 1 | 1 | Yes | 8 |
| 4 | 4 | 1 | 1 | Yes | 9 |
| 5 | 5 | 3 | 3 | Yes | 10 |

**Final Calculation:** `ans` (10) - `nums.size()` (6) = **4**.

# Complexity
- Time complexity: $$O(N^2)$$
We use a nested loop structure. The outer loop runs $N$ times, and the inner loop runs an average of $N/2$ times. This results in $\frac{N(N+1)}{2}$ comparisons, which simplifies to $$O(N^2)$$. Given $N \le 100$, this is well within the time limit.

- Space complexity: $$O(1)$$
We only use a single integer variable `ans` to store the count, regardless of the input size.

# Code
```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    ans++;
                }
            }
        }
        return ans-nums.size();
    }
};
```

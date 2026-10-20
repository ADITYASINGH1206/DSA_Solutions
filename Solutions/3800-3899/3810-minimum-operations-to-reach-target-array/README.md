# [3810. Minimum Operations to Reach Target Array](https://leetcode.com/problems/minimum-operations-to-reach-target-array/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `greedy`

---

## Problem Description
You are given two integer arrays `nums` and `target`, each of length `n`, where `nums[i]` is the current value at index `i` and `target[i]` is the desired value at index `i`.

You may perform the following operation any number of times (including zero):

* Choose an integer value `x`
* Find all **maximal contiguous segments** where `nums[i] == x` (a segment is **maximal** if it cannot be extended to the left or right while keeping all values equal to `x`)
* For each such segment `[l, r]`, update **simultaneously**:
  + `nums[l] = target[l], nums[l + 1] = target[l + 1], ..., nums[r] = target[r]`

Return the **minimum** number of operations required to make `nums` equal to `target`.

**Example 1:**

**Input:** nums = [1,2,3], target = [2,1,3]

**Output:** 2

**Explanation:**​​​​​​​

* Choose `x = 1`: maximal segment `[0, 0]` updated -> nums becomes `[2, 2, 3]`
* Choose `x = 2`: maximal segment `[0, 1]` updated (`nums[0]` stays 2, `nums[1]` becomes 1) -> `nums` becomes `[2, 1, 3]`
* Thus, 2 operations are required to convert `nums` to `target`.​​​​​​​​​​​​​​

**Example 2:**

**Input:** nums = [4,1,4], target = [5,1,4]

**Output:** 1

**Explanation:**

* Choose `x = 4`: maximal segments `[0, 0]` and `[2, 2]` updated (`nums[2]` stays 4) -> `nums` becomes `[5, 1, 4]`
* Thus, 1 operation is required to convert `nums` to `target`.

**Example 3:**

**Input:** nums = [7,3,7], target = [5,5,9]

**Output:** 2

**Explanation:**

* Choose `x = 7`: maximal segments `[0, 0]` and `[2, 2]` updated -> `nums` becomes `[5, 3, 9]`
* Choose `x = 3`: maximal segment `[1, 1]` updated -> `nums` becomes `[5, 5, 9]`
* Thus, 2 operations are required to convert `nums` to `target`.

**Constraints:**

* `1 <= n == nums.length == target.length <= 105`
* `1 <= nums[i], target[i] <= 105`

---

## Solution & Editorial
# Intuition
The problem asks for the minimum number of operations to transform `nums` into `target`. An operation involves choosing a value `x` and updating all maximal contiguous segments where `nums[i] == x` to their corresponding `target[i]` values. The key observation is that each distinct value `x` present in `nums` at positions where `nums[i] != target[i]` must be processed at least once. Because an operation on `x` updates all occurrences of `x` simultaneously, we only need to count the number of unique values `x` that currently mismatch their target.

# Approach
1. Iterate through the arrays `nums` and `target` simultaneously.
2. Identify all indices `i` where `nums[i] != target[i]`.
3. For every such index, add the current value `nums[i]` to a hash set (`unordered_set`).
4. The size of this set represents the minimum number of operations required, as each unique value `x` that needs to be changed must be targeted by an operation.

### Visual Trace (Example 1: nums=[1,2,3], target=[2,1,3])
| Index | nums[i] | target[i] | Mismatch? | Set State |
|-------|---------|-----------|-----------|-----------|
| 0     | 1       | 2         | Yes       | {1}       |
| 1     | 2       | 1         | Yes       | {1, 2}    |
| 2     | 3       | 3         | No        | {1, 2}    |

Result: Set size = 2.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the arrays. We perform a single pass over the input arrays and constant-time insertions into the hash set.
- Space complexity: $$O(N)$$, as in the worst case, all elements in `nums` could be distinct and mismatched, requiring storage in the `unordered_set`.

# Code
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> s;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != target[i]) s.insert(nums[i]);
        }
        return s.size();
    }
};
```

# [4074. Maximum Product Pair With Target Sum](https://leetcode.com/problems/maximum-product-pair-with-target-sum/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
You are given an integer array `nums` and an integer `target`.

A pair of **distinct** indices `(i, j)` is **valid** if:

* `nums[i] + nums[j] == target`
* `nums[i] > nums[j]`

Return a **valid** pair `[i, j]` whose **product** `nums[i] * nums[j]` is **maximum** among all valid pairs. If no valid pair exists, return `[-1, -1]`.

If multiple valid pairs achieve the **maximum** product, you may return **any** of them.

**Example 1:**

**Input:** nums = [1,2,3,4], target = 5

**Output:** [2,1]

**Explanation:**

There are 2 valid pairs:

| No. | `(i, j)` | `nums[i]` | `nums[j]` | Sum | Product |
| --- | --- | --- | --- | --- | --- |
| 1 | (3, 0) | 4 | 1 | 5 | 4 |
| 2 | (2, 1) | 3 | 2 | 5 | 6 |

Both pairs sum to 5 and satisfy `nums[i] > nums[j]`. The second pair has the larger product, `3 * 2 = 6`, so the answer is `[2, 1]`.

**Example 2:**

**Input:** nums = [-3,-1,4,2], target = 1

**Output:** [3,1]

**Explanation:**

There are 2 valid pairs:

| No. | `(i, j)` | `nums[i]` | `nums[j]` | Sum | Product |
| --- | --- | --- | --- | --- | --- |
| 1 | (2, 0) | 4 | -3 | 1 | -12 |
| 2 | (3, 1) | 2 | -1 | 1 | -2 |

Since `-2 > -12`, the pair at indices `(3, 1)` is chosen and the answer is `[3, 1]`.

**Example 3:**

**Input:** nums = [3,3,5], target = 6

**Output:** [-1,-1]

**Explanation:**

**​​​​​​​**No valid pair exists, since `nums[0]` and `nums[1]` sum to 6 but are equal.

**Constraints:**

* `2 <= nums.length <= 100`
* `-100 <= nums[i], target <= 100`​​​​​​​

---

## Solution & Editorial
# Intuition
To find a pair of indices $(i, j)$ such that $nums[i] + nums[j] = target$ and $nums[i] > nums[j]$, we can leverage a hash map to store the indices of elements we have already encountered. As we iterate through the array, we check if the complement ($target - nums[i]$) exists in the map, which allows us to identify valid pairs in a single pass.

# Approach
1. Initialize an `unordered_map<int, int> mp` to store the value-to-index mapping of elements processed so far.
2. Maintain `max_prod` initialized to `INT_MIN` and `ans` initialized to `{-1, -1}`.
3. Iterate through the array using index `i`. For each `nums[i]`, calculate `comp = target - nums[i]`.
4. If `comp` exists in `mp` and `nums[i] != comp` (ensuring distinct values to satisfy the $nums[i] > nums[j]$ condition implicitly), calculate the product `nums[i] * comp`.
5. If the product is greater than `max_prod`, update `max_prod` and store the indices in `ans`, ensuring the index corresponding to the larger value is placed first.
6. Update `mp` with the current `nums[i]` and its index `i`.

### Visual Trace (Example 1: nums = [1, 2, 3, 4], target = 5)
| i | nums[i] | comp | mp (before) | Valid? | Product | max_prod | ans |
|---|---|---|---|---|---|---|---|
| 0 | 1 | 4 | {} | No | - | INT_MIN | [-1, -1] |
| 1 | 2 | 3 | {1:0} | No | - | INT_MIN | [-1, -1] |
| 2 | 3 | 2 | {1:0, 2:1} | Yes (3>2) | 6 | 6 | [2, 1] |
| 3 | 4 | 1 | {1:0, 2:1, 3:2} | Yes (4>1) | 4 | 6 | [2, 1] |

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the length of the array. We perform a single pass through the array, and hash map operations (insertion and lookup) are $O(1)$ on average.
- Space complexity: $$O(N)$$ to store the elements in the hash map in the worst case where all elements are distinct.

# Code
```cpp
class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int max_prod = INT_MIN;
        vector<int> ans = {-1, -1};
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            
            if (mp.count(comp) && nums[i] != comp) {
                int j = mp[comp];
                
                int i_larger = (nums[i] > comp) ? i : j;
                int i_smaller = (nums[i] > comp) ? j : i;
                
                int prod = nums[i] * comp;
                if (prod > max_prod) {
                    max_prod = prod;
                    ans = {i_larger, i_smaller};
                }
            }
            mp[nums[i]] = i; 
        }
        
        return ans;
    }
};
```

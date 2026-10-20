# [2149. Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `simulation`

---

## Problem Description
You are given a **0-indexed** integer array `nums` of **even** length consisting of an **equal** number of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

1. Every **consecutive pair** of integers have **opposite signs**.
2. For all integers with the same sign, the **order** in which they were present in `nums` is **preserved**.
3. The rearranged array begins with a positive integer.

Return *the modified array after rearranging the elements to satisfy the aforementioned conditions*.

**Example 1:**

```
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.
```

**Example 2:**

```
Input: nums = [-1,1]
Output: [1,-1]
Explanation:
1 is the only positive integer and -1 the only negative integer in nums.
So nums is rearranged to [1,-1].
```

**Constraints:**

* `2 <= nums.length <= 2 * 105`
* `nums.length` is **even**
* `1 <= |nums[i]| <= 105`
* `nums` consists of **equal** number of positive and negative integers.

It is not required to do the modifications in-place.

---

## Solution & Editorial
# Intuition
Since the problem requires preserving the relative order of positive and negative integers while alternating them, we can observe that positive numbers will always occupy even indices (0, 2, 4, ...) and negative numbers will always occupy odd indices (1, 3, 5, ...). By maintaining two separate pointers for these indices, we can construct the result in a single pass.

# Approach
1. Initialize a result vector `ans` of the same size as `nums`.
2. Use two pointers: `pos` starting at 0 (for positive numbers) and `neg` starting at 1 (for negative numbers).
3. Iterate through the input `nums` once. If the current element is positive, place it at `ans[pos]` and increment `pos` by 2. If negative, place it at `ans[neg]` and increment `neg` by 2.

### Visual Trace (Example 1: [3, 1, -2, -5, 2, -4])
| Index | Value | Action | `pos` | `neg` | `ans` state |
|---|---|---|---|---|---|
| 0 | 3 | Positive | 2 | 1 | [3, 0, 0, 0, 0, 0] |
| 1 | 1 | Positive | 4 | 1 | [3, 0, 1, 0, 0, 0] |
| 2 | -2 | Negative | 4 | 3 | [3, -2, 1, 0, 0, 0] |
| 3 | -5 | Negative | 4 | 5 | [3, -2, 1, -5, 0, 0] |
| 4 | 2 | Positive | 6 | 5 | [3, -2, 1, -5, 2, 0] |
| 5 | -4 | Negative | 6 | 7 | [3, -2, 1, -5, 2, -4] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array, as we iterate through the input exactly once.
- Space complexity: $$O(N)$$ to store the result array.

# Code
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int pos = 0;
        int neg =1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<0){
                ans[neg] = nums[i];
                neg+=2;
            }
            else{
                ans[pos] = nums[i];
                pos+=2;
            }
        }
        return ans;
    }
};
```

# [75. Sort Colors](https://leetcode.com/problems/sort-colors/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `sorting`, `quicksort`, `bubble-sort`

---

## Problem Description
You are given an array `nums` with `n` objects colored red, white, or blue, sort them **[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**

**Input:** nums = [2,0,2,1,1,0]

**Output:** [0,0,1,1,2,2]

**Explanation:**

The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.

**Example 2:**

**Input:** nums = [2,0,1]

**Output:** [0,1,2]

**Explanation:**

The array has one each of 0, 1, and 2, arranged in-place in the order 0, 1, 2.

**Constraints:**

* `n == nums.length`
* `1 <= n <= 300`
* `nums[i]` is either 0, 1, or 2.

**Follow up:** Could you come up with a one-pass algorithm using only constant extra space?

---

## Solution & Editorial
# Intuition
The problem requires sorting an array consisting of only three unique elements: `0`, `1`, and `2`. Since the domain of values is extremely restricted, we can determine the exact frequency of each value in a first pass and then overwrite the array with the correct counts in a second pass.

# Approach
1. Initialize three integer counters `zero`, `ones`, and `twos` to zero.
2. Iterate through the array `nums` using a for loop. If `nums[i] == 0`, increment `zero`; if `nums[i] == 1`, increment `ones`; otherwise, increment `twos`.
3. In the second pass, iterate through `nums` again. Sequentially overwrite elements by decrementing `zero` until exhausted, then decrementing `ones`, and finally filling the remainder with `2`.

### Visual Walkthrough for Example 1 (`nums = [2, 0, 2, 1, 1, 0]`)|
- **Pass 1 (Counting):**
  - `nums[0] = 2` -> `twos = 1`
  - `nums[1] = 0` -> `zero = 1`
  - `nums[2] = 2` -> `twos = 2`
  - `nums[3] = 1` -> `ones = 1`
  - `nums[4] = 1` -> `ones = 2`
  - `nums[5] = 0` -> `zero = 2`
  - Final counts: `zero = 2`, `ones = 2`, `twos = 2`

- **Pass 2 (Reconstruction):**
  - Indices `0` to `1`: filled with `0` (since `zero` drops from 2 to 0).
  - Indices `2` to `3`: filled with `1` (since `ones` drops from 2 to 0).
  - Indices `4` to `5`: filled with `2` (since `twos` drops from 2 to 0).
  - Result: `[0, 0, 1, 1, 2, 2]`

# Complexity
- Time complexity: $$O(N)$$ — We perform exactly two linear scans over the array of size $$N$$, resulting in $$2N$$ total operations.
- Space complexity: $$O(1)$$ — Only a constant amount of extra memory is used for the three counter variables.

# Code
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int ones = 0;
        int twos = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0){
                zero++;
            }
            else if(nums[i] ==1 ){
                ones++;
            }else{
                twos++;
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(zero){
                nums[i] =0;
                zero--;
            }else if(ones){
                nums[i] = 1;
                ones--;
            }else{
                nums[i] = 2;

            }
        }
    }
};
```

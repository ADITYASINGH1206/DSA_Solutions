# [3731. Find Missing Elements](https://leetcode.com/problems/find-missing-elements/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`

---

## Problem Description
You are given an integer array `nums` consisting of **unique** integers.

Originally, `nums` contained **every integer** within a certain range. However, some integers might have gone **missing** from the array.

The **smallest** and **largest** integers of the original range are still present in `nums`.

Return a **sorted** list of all the missing integers in this range. If no integers are missing, return an **empty** list.

**Example 1:**

**Input:** nums = [1,4,2,5]

**Output:** [3]

**Explanation:**

The smallest integer is 1 and the largest is 5, so the full range should be `[1,2,3,4,5]`. Among these, only 3 is missing.

**Example 2:**

**Input:** nums = [7,8,6,9]

**Output:** []

**Explanation:**

The smallest integer is 6 and the largest is 9, so the full range is `[6,7,8,9]`. All integers are already present, so no integer is missing.

**Example 3:**

**Input:** nums = [5,1]

**Output:** [2,3,4]

**Explanation:**

The smallest integer is 1 and the largest is 5, so the full range should be `[1,2,3,4,5]`. The missing integers are 2, 3, and 4.

**Constraints:**

* `2 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
Since the problem guarantees that the smallest and largest integers of the original range are present in the input, the range is strictly defined by the minimum and maximum values in the array. We can identify missing elements by tracking the presence of each integer within this range using a frequency array.

# Approach
1. Find the `mini` and `maxi` values in the input `nums` using `std::min_element` and `std::max_element`.
2. Initialize a frequency array `freq` of size 101 (covering the constraint range 1-100) to keep track of existing numbers.
3. Iterate through `nums` to populate the `freq` array.
4. Iterate from `mini` to `maxi`. If `freq[i]` is 0, the integer `i` is missing from the range and is added to the result vector `ans`.

### Visual Trace (Example 1: nums = [1, 4, 2, 5])
- `mini` = 1, `maxi` = 5
- `freq` array updated: `freq[1]=1, freq[4]=1, freq[2]=1, freq[5]=1`
- Loop `i` from 1 to 5:
  - `i=1`: `freq[1]` is 1 (present)
  - `i=2`: `freq[2]` is 1 (present)
  - `i=3`: `freq[3]` is 0 (missing) -> `ans = [3]`
  - `i=4`: `freq[4]` is 1 (present)
  - `i=5`: `freq[5]` is 1 (present)

# Complexity
- Time complexity: $$O(N + R)$$, where $$N$$ is the length of `nums` and $$R$$ is the range size (max - min). We iterate through the array once and then through the range once.
- Space complexity: $$O(R)$$, where $$R$$ is the fixed size of the frequency array (101 in this case).

# Code
```cpp
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> freq(101,0);
        vector<int> ans;
        for(auto num : nums){
            freq[num]++;
        }
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        for(int i = mini;i<=maxi;i++){
            if(!freq[i]) ans.push_back(i);
        }
        return ans;
    }
};
```

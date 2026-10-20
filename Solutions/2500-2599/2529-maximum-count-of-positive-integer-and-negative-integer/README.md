# [2529. Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/)
**Difficulty:** `Easy` | **Tags:** `array`, `binary-search`, `counting`

---

## Problem Description
Given an array `nums` sorted in **non-decreasing** order, return *the maximum between the number of positive integers and the number of negative integers.*

* In other words, if the number of positive integers in `nums` is `pos` and the number of negative integers is `neg`, then return the maximum of `pos` and `neg`.

**Note** that `0` is neither positive nor negative.

**Example 1:**

```
Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
```

**Example 2:**

```
Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
```

**Example 3:**

```
Input: nums = [5,20,66,1314]
Output: 4
Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.
```

**Constraints:**

* `1 <= nums.length <= 2000`
* `-2000 <= nums[i] <= 2000`
* `nums` is sorted in a **non-decreasing order**.

**Follow up:** Can you solve the problem in `O(log(n))` time complexity?

---

## Solution & Editorial
# Intuition
Since the input array `nums` is sorted in non-decreasing order, we can leverage binary search to find the boundaries of negative and positive integers efficiently. The problem asks for the maximum of two counts, which can be determined by finding the index of the last negative number and the index of the first positive number.

# Approach
1. **Find Negative Count**: Use binary search to find the rightmost index where `nums[mid] < 0`. Since the array is 0-indexed, if the last negative number is at index `i`, there are `i + 1` negative numbers.
2. **Find Positive Count**: Use binary search to find the leftmost index where `nums[mid] > 0`. If this index is `posStart`, then the number of positive integers is `n - posStart`.
3. **Result**: Return the maximum of the two calculated counts.

### Visual Trace (Example 2: `[-3, -2, -1, 0, 0, 1, 2]`)
- **Negative Search**:
  - `l=0, r=6, mid=3`: `nums[3]=0` (not < 0), `r=2`
  - `l=0, r=2, mid=1`: `nums[1]=-2` (< 0), `negCount=2, l=2`
  - `l=2, r=2, mid=2`: `nums[2]=-1` (< 0), `negCount=3, l=3`
  - Loop ends, `negCount = 3`.
- **Positive Search**:
  - `l=0, r=6, mid=3`: `nums[3]=0` (not > 0), `l=4`
  - `l=4, r=6, mid=5`: `nums[5]=1` (> 0), `posStart=5, r=4`
  - `l=4, r=4, mid=4`: `nums[4]=0` (not > 0), `l=5`
  - Loop ends, `posStart = 5`.
- **Final**: `posCount = 7 - 5 = 2`. `max(3, 2) = 3`.

# Complexity
- Time complexity: $$O(\log N)$$ where $$N$$ is the length of the array, as we perform two independent binary searches.
- Space complexity: $$O(1)$$ as we only use a few integer variables for pointers and counters.

# Code
```cpp
class Solution {
public:
    int maximumCount(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int negCount = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < 0) {
                negCount = mid + 1; 
                l = mid + 1;        
            } else {
                r = mid - 1;        
            }
        }
        
        l = 0, r = n - 1;
        int posStart = n; 
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > 0) {
                posStart = mid;     
                r = mid - 1;        
            } else {
                l = mid + 1;        
            }
        }
        
        int posCount = n - posStart;
        ans = max(negCount, posCount);
        return ans;
    }
};
```

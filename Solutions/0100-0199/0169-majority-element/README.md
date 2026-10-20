# [169. Majority Element](https://leetcode.com/problems/majority-element/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `divide-and-conquer`, `sorting`, `counting`, `boyer-moore-majority-vote-algorithm`

---

## Problem Description
Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

**Example 1:**

```
Input: nums = [3,2,3]
Output: 3
```

**Example 2:**

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 5 * 104`
* `-109 <= nums[i] <= 109`
* The input is generated such that a majority element will exist in the array.

**Follow-up:** Could you solve the problem in linear time and in `O(1)` space?

---

## Solution & Editorial
# Intuition
The problem asks us to find the element that appears strictly more than \(\lfloor n / 2 \rfloor\) times in an array. Since this majority element occupies more than half of the array, its occurrences will outvote all other elements combined. This structural property allows us to use the Boyer-Moore Majority Vote Algorithm to track a candidate and a running vote balance in linear time and constant space.

# Approach
1. Initialize `count = 0` to track the vote balance and `ans = 0` to store the current candidate for the majority element.
2. Iterate through each element `x` in the `nums` vector.
3. If `count == 0`, assign the current element `x` to `ans` and set `count = 1`.
4. If `x == ans`, increment `count` because we found another instance of our candidate.
5. If `x != ans`, decrement `count` because a competing element has appeared.
6. After iterating through all elements, return `ans`, which is guaranteed to hold the majority element.

### Visual Trace Walkthrough (Example 1: nums = [3, 2, 3])

| Iteration | Element `x` | `count` Before | `ans` Before | Action | `count` After | `ans` After |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 3 | 0 | 0 | `count == 0` -> Set candidate | 1 | 3 |
| 2 | 2 | 1 | 3 | `x != ans` -> Decrement | 0 | 3 |
| 3 | 3 | 0 | 3 | `count == 0` -> Set candidate | 1 | 3 |

Result returned: `3`.

# Complexity
- Time complexity: \(O(n)\) where \(n\) is the number of elements in `nums`. We perform a single pass over the array with constant time operations per element.
- Space complexity: \(O(1)\) since we only use two scalar integer variables (`count` and `ans`) for tracking state, requiring no auxiliary storage.

# Code
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int ans=0;
        for(int x: nums){
           if(count == 0){
                ans = x;
                count =1;
            }
            else{
                if(x == ans){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return ans;
    }
};
```

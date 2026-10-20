# [2206. Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `bit-manipulation`, `counting`

---

## Problem Description
You are given an integer array `nums` consisting of `2 * n` integers.

You need to divide `nums` into `n` pairs such that:

* Each element belongs to **exactly one** pair.
* The elements present in a pair are **equal**.

Return `true` *if nums can be divided into* `n` *pairs, otherwise return* `false`.

**Example 1:**

```
Input: nums = [3,2,3,2,2,2]
Output: true
Explanation: 
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: false
Explanation: 
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.
```

**Constraints:**

* `nums.length == 2 * n`
* `1 <= n <= 500`
* `1 <= nums[i] <= 500`

---

## Solution & Editorial
# Intuition
To divide an array of size $2n$ into $n$ pairs of equal elements, every distinct number in the array must appear an even number of times. If any number appears an odd number of times, it is impossible to form complete pairs for that specific value.

# Approach
1. Initialize a frequency array `frequencies` of size 501 (since constraints state $1 \le nums[i] \le 500$) with zeros.
2. Iterate through the input `nums` and increment the count for each number in the `frequencies` array.
3. Iterate through the `frequencies` array from index 1 to 500. If any count is odd (`frequencies[i] % 2 != 0`), return `false` immediately.
4. If all counts are even, return `true`.

### Visual Trace (Example 1: nums = [3, 2, 3, 2, 2, 2])
| Step | Action | frequencies[2] | frequencies[3] | Others |
| :--- | :--- | :--- | :--- | :--- |
| 0 | Init | 0 | 0 | 0 |
| 1 | Process 3 | 0 | 1 | 0 |
| 2 | Process 2 | 1 | 1 | 0 |
| 3 | Process 3 | 1 | 2 | 0 |
| 4 | Process 2 | 2 | 2 | 0 |
| 5 | Process 2 | 3 | 2 | 0 |
| 6 | Process 2 | 4 | 2 | 0 |
| Final | Check parity | 4%2=0 (Even) | 2%2=0 (Even) | 0 (Even) |

# Complexity
- Time complexity: $$O(N + K)$$, where $N$ is the length of the input array and $K$ is the range of values (500). We iterate through the array once and then through the fixed-size frequency array.
- Space complexity: $$O(K)$$, where $K=501$ is the size of the frequency array used to store counts.

# Code
```cpp
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int frequencies[501] = {0};
        
        for (int num : nums) {
            frequencies[num]++;
        }
        
        for (int i = 1; i <= 500; i++) {
            if (frequencies[i] % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};
```

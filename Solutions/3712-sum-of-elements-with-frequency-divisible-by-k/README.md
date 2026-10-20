# [3712. Sum of Elements With Frequency Divisible by K](https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
You are given an integer array `nums` and an integer `k`.

Return an integer denoting the **sum** of all elements in `nums` whose **frequency** is divisible by `k`, or 0 if there are no such elements.

**Note:** An element is included in the sum **exactly** as many times as it appears in the array if its total frequency is divisible by `k`.

**Example 1:**

**Input:** nums = [1,2,2,3,3,3,3,4], k = 2

**Output:** 16

**Explanation:**

* The number 1 appears once (odd frequency).
* The number 2 appears twice (even frequency).
* The number 3 appears four times (even frequency).
* The number 4 appears once (odd frequency).

So, the total sum is `2 + 2 + 3 + 3 + 3 + 3 = 16`.

**Example 2:**

**Input:** nums = [1,2,3,4,5], k = 2

**Output:** 0

**Explanation:**

There are no elements that appear an even number of times, so the total sum is 0.

**Example 3:**

**Input:** nums = [4,4,4,1,2,3], k = 3

**Output:** 12

**Explanation:**

* The number 1 appears once.
* The number 2 appears once.
* The number 3 appears once.
* The number 4 appears three times.

So, the total sum is `4 + 4 + 4 = 12`.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* `1 <= k <= 100`

---

## Solution & Editorial
# Intuition
To solve this problem, we need to determine the frequency of each element in the array and check if that frequency is divisible by $k$. Since the constraints on the values in `nums` are small (up to 100), we can use a frequency array to count occurrences efficiently.

# Approach
1. Initialize a frequency array `freq` of size 101 with zeros to store the count of each number (since $1 \le nums[i] \le 100$).
2. Iterate through the input `nums` and increment the corresponding index in `freq` for each element.
3. Iterate through the `freq` array from 1 to 100. For each index `i` where `freq[i]` is greater than 0, check if `freq[i] % k == 0`.
4. If the condition holds, add `i * freq[i]` to the running total `ans`.

### Visual Trace (Example 1: nums = [1,2,2,3,3,3,3,4], k = 2)
| Number | Frequency | Divisible by 2? | Contribution |
| :--- | :--- | :--- | :--- |
| 1 | 1 | No | 0 |
| 2 | 2 | Yes | 2 * 2 = 4 |
| 3 | 4 | Yes | 3 * 4 = 12 |
| 4 | 1 | No | 0 |
| **Total** | | | **16** |

# Complexity
- Time complexity: $$O(N + M)$$, where $N$ is the length of `nums` and $M$ is the range of values (100). We iterate through `nums` once and then iterate through the fixed-size frequency array.
- Space complexity: $$O(M)$$, where $M=101$ is the size of the frequency array used to store counts.

# Code
```cpp
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> freq(101,0);
        for(int num:nums){
            freq[num]++;
        }
        for(int i = 1 ;i<101;i++){
            if(freq[i] != 0 && freq[i]%k ==0) ans+= i*freq[i];
        }
        return ans;

    }
};
```

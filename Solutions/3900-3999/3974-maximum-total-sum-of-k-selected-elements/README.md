# [3974. Maximum Total Sum of K Selected Elements](https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/)
**Difficulty:** `Medium` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are given an integer array `nums` and two integers `k` and `mul`.

Select **exactly** `k` elements from `nums`. Process these elements one by one in any order you choose.

For each selected element, **independently** choose one of the following:

* **Add** the element's value to the total sum, or
* **Multiply** the element by the **current** value of `mul` and **add** the result to the total sum.

After processing each selected element, `mul` **decreases** by 1, regardless of which option was chosen. The current value of `mul` may become 0 or negative.

Return an integer denoting the **maximum** possible total sum.

**Example 1:**

**Input:** nums = [6,1,2,9], k = 3, mul = 2

**Output:** 26

**Explanation:**

One optimal way:

* One optimal selection is `nums[3] = 9`, `nums[0] = 6`, and `nums[2] = 2`.
* Process `nums[3] = 9` first: choose multiplication, so it contributes `9 * 2 = 18`. Now, `mul` becomes 1.
* Process `nums[0] = 6` next: choose multiplication, so it contributes `6 * 1 = 6`. Now, `mul` becomes 0.
* Process `nums[2] = 2` last: choose addition, so it contributes 2.
* The total sum is `18 + 6 + 2 = 26`.

**Example 2:**

**Input:** nums = [3,7,5,2], k = 2, mul = 4

**Output:** 43

**Explanation:**

One optimal way:

* One optimal selection is `nums[1] = 7` and `nums[2] = 5`.
* Process `nums[1] = 7` first: choose multiplication, so it contributes `7 * 4 = 28`. Now, `mul` becomes 3.
* Process `nums[2] = 5` next: choose multiplication, so it contributes `5 * 3 = 15`.
* The total sum is `28 + 15 = 43`.

**Example 3:**

**Input:** nums = [4,4], k = 1, mul = 1

**Output:** 4

**Explanation:**

One optimal way:

* One optimal selection is `nums[0] = 4`.
* Process `nums[0] = 4`: choose multiplication, so it contributes `4 * 1 = 4`.
* The total sum is 4.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`
* `1 <= k <= nums.length`
* `1 <= mul <= 105`

---

## Solution & Editorial
# Intuition
To maximize the total sum, we must prioritize multiplying the largest available numbers by the largest available multipliers. Since the multiplier `mul` decreases by 1 after each step, we should greedily pick the largest elements from the array and apply the current `mul` if it is positive; otherwise, we simply add the element to the total sum.

# Approach
1. Sort the input array `nums` in non-decreasing order to easily access the largest elements from the end.
2. Iterate `k` times. In each iteration:
   - Extract the largest element using `nums.back()` and remove it from the array.
   - If the current `mul` is greater than 0, multiply the element by `mul`, add it to the total sum, and decrement `mul`.
   - If `mul` is 0 or less, simply add the element to the total sum.
3. Return the accumulated total sum.

### Visual Trace (Example 1: nums=[6,1,2,9], k=3, mul=2)
| Iteration | Current `mul` | Selected Element | Operation | Contribution | Total Sum |
|-----------|---------------|------------------|-----------|--------------|-----------|
| 1         | 2             | 9                | 9 * 2     | 18           | 18        |
| 2         | 1             | 6                | 6 * 1     | 6            | 24        |
| 3         | 0             | 2                | 2 + 0     | 2            | 26        |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the length of `nums`. The dominant operation is sorting the array.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation, typically $$O(\log N)$$ or $$O(N)$$).

# Code
```cpp
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        while(k >0){
            long long element = nums[nums.size()-1];
            k--;
            nums.pop_back();
            if(mul>0){
                ans += element*mul;
                mul--;
            }
            else{
                ans += element;
            }
        }
        return ans;
    }
};
```

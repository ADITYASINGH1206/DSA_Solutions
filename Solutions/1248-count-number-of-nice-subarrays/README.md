# [1248. Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `math`, `sliding-window`, `prefix-sum`

---

## Problem Description
Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are `k` odd numbers on it.

Return *the number of **nice** sub-arrays*.

**Example 1:**

```
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```

**Example 2:**

```
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
```

**Example 3:**

```
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
```

**Constraints:**

* `1 <= nums.length <= 50000`
* `1 <= nums[i] <= 10^5`
* `1 <= k <= nums.length`

---

## Solution & Editorial
# Intuition
The problem asks us to count the number of continuous subarrays that contain exactly `k` odd numbers. Finding subarrays with an exact count can be difficult directly using a single sliding window because the window size does not monotonically restrict the number of odd elements. However, we can express the count of subarrays with *exactly* `k` odd numbers as the difference between the number of subarrays with *at most* `k` odd numbers and the number of subarrays with *at most* `k - 1` odd numbers: $$\text{Exact}(k) = \text{AtMost}(k) - \text{AtMost}(k - 1)$$.

# Approach
1. Implement a helper function `atmost(nums, goal)` that computes the total number of subarrays containing at most `goal` odd numbers using a sliding window technique.
2. In `atmost`, maintain two pointers `l` and `r` representing the left and right boundaries of the window, a running count of odd numbers `sum`, and a counter `cnt` for valid subarrays.
3. Iterate `r` from `0` to `nums.size() - 1`. For each element `nums[r]`, add `nums[r] % 2` to `sum`.
4. If `sum > goal`, increment `l` while subtracting `nums[l] % 2` from `sum` until `sum <= goal` is restored.
5. For each valid position of `r`, add the number of valid ending subarrays ending at `r`, which is given by `r - l + 1`, to `cnt`.
6. Finally, in `numberOfSubarrays`, return `atmost(nums, k) - atmost(nums, k - 1)`.

### Visual Dry Run (Example 1: nums = [1, 1, 2, 1, 1], k = 3)
Evaluating `atmost(nums, 3)`:
- r=0, num=1: sum=1, window=[1], cnt += 1 (1)
- r=1, num=1: sum=2, window=[1,1], cnt += 2 (3)
- r=2, num=2: sum=2, window=[1,1,2], cnt += 3 (6)
- r=3, num=1: sum=3, window=[1,1,2,1], cnt += 4 (10)
- r=4, num=1: sum=4 -> sum > 3, shrink l=0->1, sum=3, window=[1,2,1,1], cnt += 4 (14)
Total for atmost(3) = 14.

Evaluating `atmost(nums, 2)`:
- Total for atmost(2) = 12.
Result = 14 - 12 = 2.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. Both `l` and `r` traverse the array at most once in the `atmost` function, resulting in linear time complexity.
- Space complexity: $$O(1)$$, as only a few scalar variables are used for pointers and counters, requiring constant auxiliary space.

# Code
```cpp
class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        int l=0,r=0,sum=0,cnt=0;
        if(goal<0) return 0;
        while(r<nums.size())
        {
            sum+=(nums[r]%2);
            while(sum>goal)
            {
                sum=sum-(nums[l]%2);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
    return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};
```

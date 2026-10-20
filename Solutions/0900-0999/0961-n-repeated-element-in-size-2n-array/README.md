# [961. N-Repeated Element in Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `pigeonhole-principle`

---

## Problem Description
You are given an integer array `nums` with the following properties:

* `nums.length == 2 * n`.
* `nums` contains `n + 1` **unique** values, `n` of which occur **exactly once** in the array.
* Exactly one element of `nums` is repeated `n` times.

Return *the element that is repeated* `n` *times*.

**Example 1:**

```
Input: nums = [1,2,3,3]
Output: 3
```

**Example 2:**

```
Input: nums = [2,1,2,5,3,2]
Output: 2
```

**Example 3:**

```
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
```

**Constraints:**

* `2 <= n <= 5000`
* `nums.length == 2 * n`
* `0 <= nums[i] <= 104`
* `nums` contains `n + 1` **unique** elements and one of them is repeated exactly `n` times.

---

## Solution & Editorial
# Intuition
The problem states that an array of size $2n$ contains $n+1$ unique values, where one specific element is repeated $n$ times. By sorting the array, identical elements are brought adjacent to each other. We can then sweep through the sorted array and count consecutive occurrences to identify the element that appears $n$ times.

# Approach
1. Sort the vector `nums` in ascending order using `sort(nums.begin(), nums.end())` so that identical elements are grouped together.
2. Initialize `count = 0`, `n = nums.size()`, and `ans = 0` to track the frequency of the current candidate element.
3. Iterate through each `num` in `nums`. If `num` matches `ans`, increment `count`. Otherwise, update `ans` to `num` and reset `count` to $1$.
4. Terminate the loop early as soon as `count` reaches `n / 2` (since the repeated element appears $n$ times in a total array length of $2n$, its frequency in the sorted array will be $n$, which is half the array size).
5. Return `ans`.

### Visual Trace Walkthrough (Example 1: `nums = [1, 2, 3, 3]`, $n = 4$)
- Initial array: `[1, 2, 3, 3]`, target frequency threshold: $4 / 2 = 2$.
- Iteration 1 (`num = 1`): `ans` becomes `1`, `count = 1`.
- Iteration 2 (`num = 2`): `ans` differs from `2`, `ans` becomes `2`, `count = 1`.
- Iteration 3 (`num = 3`): `ans` differs from `3`, `ans` becomes `3`, `count = 1`.
- Iteration 4 (`num = 3`): `num == ans`, `count` increments to `2`.
- `count == n / 2` condition met (`2 == 2`), loop breaks.
- Return `3`.

# Complexity
- Time complexity: $$O(N \log N)$$ — dominated by the sorting step of the $2n$ elements.
- Space complexity: $$O(1)$$ — only a few primitive variables (`count`, `ans`, `n`) are used, ignoring standard sorting stack auxiliary space.

# Code
```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int n = nums.size();
        int ans = 0;
        for(int num:nums){
            if(count == (n/2)) break;
            if(num == ans){
                count++;
            }else{
                ans = num;
                count = 1;
            }
        }
        return ans;
    }
};
```

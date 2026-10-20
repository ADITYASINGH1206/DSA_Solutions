# [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `binary-search`

---

## Problem Description
You are given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**.

Find **two** numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return the indices of the two numbers `index1` and `index2` as an integer array `[index1, index2]` of length 2.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

**Example 1:**

```
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
```

**Example 2:**

```
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
```

**Example 3:**

```
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
```

**Constraints:**

* `2 <= numbers.length <= 3 * 104`
* `-1000 <= numbers[i] <= 1000`
* `numbers` is sorted in **non-decreasing order**.
* `-1000 <= target <= 1000`
* The tests are generated such that there is **exactly one solution**.

---

## Solution & Editorial
# Intuition
Since the array is already sorted in non-decreasing order, we can efficiently find the two numbers that sum up to the target by deploying a two-pointer approach. By placing one pointer at the beginning and the other at the end, we can dynamically adjust our search space in linear time without requiring any additional hash map storage.

# Approach
1. Initialize two pointers: `low` at the beginning of the array (`0`) and `high` at the end of the array (`n - 1`).
2. Enter a `while` loop that continues as long as `low <= high`.
3. Compute the sum of the elements at `numbers[low]` and `numbers[high]`.
4. If the sum exceeds the `target`, decrement `high` to reduce the sum because the array is sorted.
5. If the sum is less than the `target`, increment `low` to increase the sum.
6. If the sum matches the `target`, store `low + 1` and `high + 1` (since the problem uses 1-based indexing) in the answer vector and return it immediately.

### Visual Trace Walkthrough (Example 1: numbers = [2, 7, 11, 15], target = 9)

| Iteration | low | high | numbers[low] | numbers[high] | Sum | Action |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 3 | 2 | 15 | 17 | Sum > 9, decrement high |
| 2 | 0 | 2 | 2 | 11 | 13 | Sum > 9, decrement high |
| 3 | 0 | 1 | 2 | 7 | 9 | Sum == 9, return [1, 2] |

# Complexity
- Time complexity: $$O(N)$$ — Each element is visited at most once by either the `low` or `high` pointer, where $$N$$ is the number of elements in `numbers`.
- Space complexity: $$O(1)$$ — Only a few primitive integer variables are used for pointers and indices, achieving constant extra space.

# Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans = {-1,-1};
        int n = numbers.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            if(numbers[low]+numbers[high] > target){
                high = high-1;
            }
            else if(numbers[low] + numbers[high] < target){
                low = low +1;
            }else{
                ans[0] = low+1;
                ans[1] = high+1;
                return ans;
            }
        }

        return ans;
    }
};
```

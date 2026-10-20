# [1502. Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
A sequence of numbers is called an **arithmetic progression** if the difference between any two consecutive elements is the same.

Given an array of numbers `arr`, return `true` *if the array can be rearranged to form an **arithmetic progression**. Otherwise, return* `false`.

**Example 1:**

```
Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
```

**Example 2:**

```
Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
```

**Constraints:**

* `2 <= arr.length <= 1000`
* `-106 <= arr[i] <= 106`

---

## Solution & Editorial
# Intuition
An arithmetic progression is defined by a constant difference between consecutive terms. If we sort the array, any valid arithmetic progression must appear in monotonic order (either strictly increasing or decreasing). By sorting, we reduce the problem to checking if the difference between every adjacent pair is identical.

# Approach
1. Sort the input array `arr` in non-decreasing order using `std::sort`.
2. Calculate the initial difference `dif` between the first two elements: `arr[1] - arr[0]`.
3. Iterate through the sorted array starting from index 2. For each index `i`, verify if `arr[i] - arr[i-1]` equals `dif`.
4. If any pair fails this check, return `false`. If the loop completes, return `true`.

### Visual Trace (Example 1: [3, 5, 1])
1. Initial: `[3, 5, 1]`
2. Sort: `[1, 3, 5]`
3. `dif = arr[1] - arr[0] = 3 - 1 = 2`
4. Loop `i=2`: `arr[2] - arr[1] = 5 - 3 = 2`. `2 == 2` is true.
5. Return `true`.

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step, where $$N$$ is the length of the array. The subsequent linear scan takes $$O(N)$$.
- Space complexity: $$O(1)$$ or $$O(\log N)$$ depending on the implementation of `std::sort` (stack space for recursion), as we sort the array in-place.

# Code
```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int dif = arr[1]-arr[0];
        int n = arr.size();
        for(int i = 2;i<n;i++){
            if(dif != arr[i]-arr[i-1]) return false;
        }
        return true;
    }
};
```

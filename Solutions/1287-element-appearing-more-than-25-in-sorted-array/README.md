# [1287. Element Appearing More Than 25% In Sorted Array](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
Given an integer array **sorted** in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

**Example 1:**

```
Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
```

**Example 2:**

```
Input: arr = [1,1]
Output: 1
```

**Constraints:**

* `1 <= arr.length <= 104`
* `0 <= arr[i] <= 105`

---

## Solution & Editorial
# Intuition
Since the array is already sorted in non-decreasing order, identical elements appear contiguously. We can track the current element and its consecutive frequency in a single linear scan. The moment its frequency strictly exceeds 25% of the total array length ($n / 4$), we immediately return it.

# Approach
1. Initialize `n` as the size of the array `arr`, `ans` as the first element `arr[0]`, and `count` as `0`.
2. Iterate through each element `arr[i]` using a standard `for` loop.
3. If `arr[i]` matches `ans`, increment `count`. Otherwise, reset `count` to `1` and update `ans` to the new element `arr[i]`.
4. Check if `count` exceeds `n / 4`. If it does, return `ans` immediately.

### Visual Walkthrough (Example 1: `arr = [1,2,2,6,6,6,6,7,10]`, `n = 9`, `n/4 = 2`)

| i | arr[i] | ans | count | count > 2 | Action | 
|---|---|---|---|---|---|
| 0 | 1 | 1 | 1 | False | Match `ans`, increment count |
| 1 | 2 | 2 | 1 | False | Mismatch, update `ans = 2`, `count = 1` |
| 2 | 2 | 2 | 2 | False | Match `ans`, increment count |
| 3 | 6 | 6 | 1 | False | Mismatch, update `ans = 6`, `count = 1` |
| 4 | 6 | 6 | 2 | False | Match `ans`, increment count |
| 5 | 6 | 6 | 3 | True | Match `ans`, increment count. `3 > 2`, returns `6` |

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the array of size $$N$$ at most once, performing constant time operations at each step.
- Space complexity: $$O(1)$$ — We only use a few scalar integer variables (`n`, `ans`, `count`, `i`), requiring no additional auxiliary data structures.

# Code
```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int ans= arr[0];
        int count = 0;
        for(int i =0;i<arr.size();i++){
            if(arr[i] == ans){
                count++;
            }else{
                count =1;
                ans=arr[i];
            }
            if(count>(n/4)){
                return ans;
            }
        }
        return ans;
    }
};
```

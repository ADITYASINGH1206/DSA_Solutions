# [1588. Sum of All Odd Length Subarrays](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `prefix-sum`

---

## Problem Description
Given an array of positive integers `arr`, return *the sum of all possible **odd-length subarrays** of* `arr`.

A **subarray** is a contiguous subsequence of the array.

**Example 1:**

```
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
```

**Example 2:**

```
Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
```

**Example 3:**

```
Input: arr = [10,11,12]
Output: 66
```

**Constraints:**

* `1 <= arr.length <= 100`
* `1 <= arr[i] <= 1000`

**Follow up:**

Could you solve this problem in O(n) time complexity?

---

## Solution & Editorial
# Intuition
To find the sum of all odd-length subarrays, we can iterate through every possible subarray defined by its start index `i` and end index `j`. By checking the length of each subarray, we can identify those with an odd length and accumulate their sums.

# Approach
1. Initialize a variable `ans` to 0 to store the cumulative sum.
2. Use a nested loop structure: the outer loop `i` iterates from 0 to `n-1` (start index), and the inner loop `j` iterates from `i` to `n-1` (end index).
3. Calculate the length of the current subarray as `len = j - i + 1`.
4. If `len` is odd (`len % 2 != 0`), use `std::accumulate` to sum the elements from `arr[i]` to `arr[j]` and add this to `ans`.
5. Return `ans` after all iterations complete.

### Visual Trace (Example 1: [1, 4, 2])
| i | j | Subarray | Length | Odd? | Sum | ans |
|---|---|----------|--------|------|-----|-----|
| 0 | 0 | [1]      | 1      | Yes  | 1   | 1   |
| 0 | 1 | [1, 4]   | 2      | No   | -   | 1   |
| 0 | 2 | [1, 4, 2]| 3      | Yes  | 7   | 8   |
| 1 | 1 | [4]      | 1      | Yes  | 4   | 12  |
| 1 | 2 | [4, 2]   | 2      | No   | -   | 12  |
| 2 | 2 | [2]      | 1      | Yes  | 2   | 14  |

# Complexity
- Time complexity: $$O(N^3)$$. We have two nested loops to define the subarray ($$O(N^2)$$) and an `accumulate` operation inside that takes $$O(N)$$, resulting in $$O(N^3)$$.
- Space complexity: $$O(1)$$. We only use a few integer variables for indexing and accumulation, requiring constant extra space.

# Code
```cpp
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if((j-i+1)%2!=0){
                    ans += accumulate(arr.begin()+i,arr.begin()+j+1,0);
                }
            }
        }
        return ans;

    }
};
```

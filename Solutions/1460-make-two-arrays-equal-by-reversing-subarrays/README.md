# [1460. Make Two Arrays Equal by Reversing Subarrays](https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`

---

## Problem Description
You are given two integer arrays of equal length `target` and `arr`. In one step, you can select any **non-empty subarray** of `arr` and reverse it. You are allowed to make any number of steps.

Return `true` *if you can make* `arr` *equal to* `target`*or* `false` *otherwise*.

**Example 1:**

```
Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
2- Reverse subarray [4,2], arr becomes [1,2,4,3]
3- Reverse subarray [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
```

**Example 2:**

```
Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
```

**Example 3:**

```
Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr does not have value 9 and it can never be converted to target.
```

**Constraints:**

* `target.length == arr.length`
* `1 <= target.length <= 1000`
* `1 <= target[i] <= 1000`
* `1 <= arr[i] <= 1000`

---

## Solution & Editorial
# Intuition
Since we can reverse any subarray of any length, we can effectively perform a bubble-sort-like swap operation to move any element to any position. Consequently, the relative order of elements in `arr` does not matter; only the frequency of each element matters. If `target` and `arr` contain the exact same elements with the same multiplicities, we can always transform `arr` into `target`.

# Approach
1. Initialize a frequency array `freq` of size 1001 (since constraints state values are between 1 and 1000) with zeros.
2. Iterate through the `target` array and increment the count for each value in `freq`.
3. Iterate through the `arr` array. For each element, check if its corresponding count in `freq` is greater than 0. If it is, decrement the count. If it is 0, it means `arr` contains an element not present in `target` (or more occurrences than `target`), so return `false`.
4. If the loop completes, return `true`.

### Visual Trace (Example 1: target=[1,2,3,4], arr=[2,4,1,3])
| Step | Action | freq state (indices 1-4) |
| :--- | :--- | :--- |
| Init | - | [0,0,0,0] |
| Count target | Process 1,2,3,4 | [1,1,1,1] |
| Check arr[0]=2 | freq[2]-- | [1,0,1,1] |
| Check arr[1]=4 | freq[4]-- | [1,0,1,0] |
| Check arr[2]=1 | freq[1]-- | [0,0,1,0] |
| Check arr[3]=3 | freq[3]-- | [0,0,0,0] |
| Result | Return true | - |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the arrays. We perform two linear passes over the input arrays.
- Space complexity: $$O(K)$$, where $$K=1001$$. We use a fixed-size frequency array regardless of the input size $$N$$.

# Code
```cpp
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001,0);
        int n = target.size();
        for(int i = 0;i<n;i++){
            freq[target[i]]++;
        }

        for(int i =0;i<n;i++){
            if(freq[arr[i]] ==0) return false;
            freq[arr[i]]--;
        }

        return true;
    }
};
```

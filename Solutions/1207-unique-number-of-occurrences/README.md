# [1207. Unique Number of Occurrences](https://leetcode.com/problems/unique-number-of-occurrences/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
Given an array of integers `arr`, return `true` *if the number of occurrences of each value in the array is **unique** or* `false` *otherwise*.

**Example 1:**

```
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
```

**Example 2:**

```
Input: arr = [1,2]
Output: false
```

**Example 3:**

```
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
```

**Constraints:**

* `1 <= arr.length <= 1000`
* `-1000 <= arr[i] <= 1000`

---

## Solution & Editorial
# Intuition
To determine if the frequency of each unique element in the array is distinct, we can group identical elements together by sorting the array. Once sorted, contiguous identical elements allow us to easily compute their respective frequencies and store them in a secondary list. Finally, sorting this frequency list lets us check for any duplicate counts adjacent to one another.

# Approach
1. Sort the input vector `arr` in ascending order so that all identical elements become contiguous.
2. Iterate through the sorted `arr` using an index `i`. For each distinct group starting at index `i`, count its frequency (`count`) by scanning ahead until a different value is encountered.
3. Push the computed `count` into an auxiliary vector `ans` and advance `i` by `count` to move to the next unique element group.
4. Sort the `ans` vector containing the frequencies.
5. Iterate through the sorted `ans` vector from index `0` to `n-2`. If any adjacent elements are equal (`ans[i] == ans[i+1]`), return `false` because duplicate frequencies exist. If no duplicates are found, return `true`.

### Visual Trace Walkthrough (Example 1: `arr = [1, 2, 2, 1, 1, 3]`)
- **Step 1 (Sorting `arr`):** `arr` becomes `[1, 1, 1, 2, 2, 3]`
- **Step 2 (Frequency Extraction):**
  - `i = 0`: Value `1` repeats `3` times. `ans` becomes `[3]`. `i` becomes `3`.
  - `i = 3`: Value `2` repeats `2` times. `ans` becomes `[3, 2]`. `i` becomes `5`.
  - `i = 5`: Value `3` repeats `1` time. `ans` becomes `[3, 2, 1]`. `i` becomes `6`.
- **Step 3 (Sorting `ans`):** `ans` becomes `[1, 2, 3]`
- **Step 4 (Duplicate Check):** Adjacent elements are `1, 2` and `2, 3`. No duplicates found. Returns `true`.

# Complexity
- Time complexity: $$O(N \log N)$$ — Dominated by sorting the input array of size $$N$$ and subsequently sorting the frequency vector of size at most $$N$$.
- Space complexity: $$O(N)$$ — Auxiliary storage required for the `ans` vector which stores at most $$N$$ frequency counts.

# Code
```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int i = 0;
        sort(arr.begin(),arr.end());
        while(i<n){
            int count = 1;
            for(int j =i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            ans.push_back(count);
            i = i+count;
        }
        n = ans.size();
        sort(ans.begin(),ans.end());
        for(int i = 0;i<n-1;i++){
            if(ans[i]==ans[i+1]){
                return false;
            }
        }
        return true;   
    }
};
```

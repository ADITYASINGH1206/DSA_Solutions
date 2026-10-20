# [1200. Minimum Absolute Difference](https://leetcode.com/problems/minimum-absolute-difference/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`

---

## Problem Description
Given an array of **distinct** integers `arr`, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair `[a, b]` follows

* `a, b` are from `arr`
* `a < b`
* `b - a` equals to the minimum absolute difference of any two elements in `arr`

**Example 1:**

```
Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
```

**Example 2:**

```
Input: arr = [1,3,6,10,15]
Output: [[1,3]]
```

**Example 3:**

```
Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
```

**Constraints:**

* `2 <= arr.length <= 105`
* `-106 <= arr[i] <= 106`

---

## Solution & Editorial
# Intuition
The minimum absolute difference between any two elements in an array will always occur between two adjacent elements after the array is sorted. By sorting the array first, we can find the minimum absolute difference and collect all matching pairs in two straightforward linear scans.

# Approach
1. Sort the input vector `arr` in ascending order using `std::sort`.
2. Initialize `mi` to the difference between the first two elements `arr[1] - arr[0]`.
3. Iterate through the sorted array from index `1` to `arr.size() - 1` to update `mi` with the minimum absolute difference between any adjacent pair.
4. Perform a second pass from index `1` to `arr.size() - 1`. If the absolute difference between `arr[i]` and `arr[i-1]` equals `mi`, construct the pair `{arr[i-1], arr[i]}` and append it to the result vector `ans`.
5. Return `ans`.

### Visual Trace Walkthrough (Example 1: arr = [4, 2, 1, 3])
- **Sorted `arr`**: `[1, 2, 3, 4]`
- **Pass 1 (Find Min Diff `mi`)**:
  - `i = 1`: `arr[1] - arr[0] = 2 - 1 = 1` -> `mi = 1`
  - `i = 2`: `arr[2] - arr[1] = 3 - 2 = 1` -> `mi = min(1, 1) = 1`
  - `i = 3`: `arr[3] - arr[2] = 4 - 3 = 1` -> `mi = min(1, 1) = 1`
- **Pass 2 (Collect Pairs)**:
  - `i = 1`: `abs(2 - 1) == 1` -> push `{1, 2}`
  - `i = 2`: `abs(3 - 2) == 1` -> push `{2, 3}`
  - `i = 3`: `abs(4 - 3) == 1` -> push `{3, 4}`
- **Result**: `[[1, 2], [2, 3], [3, 4]]`

# Complexity
- Time complexity: $$O(N \log N)$$ — dominated by the `std::sort` operation over `N` elements. Both subsequent linear passes take $$O(N)$$ time.
- Space complexity: $$O(1)$$ auxiliary space (excluding the output vector `ans`), as sorting is done in-place or uses standard sorting stack space.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int mi =arr[1]-arr[0];
        for(int i=1;i<arr.size();i++){
            mi = min(mi,abs(arr[i-1]-arr[i]));
        }
        for(int i =1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1]) ==mi){
                vector<int> el = {arr[i-1],arr[i]};
                ans.push_back(el);
            }
        }
        return ans;
    }
};
```

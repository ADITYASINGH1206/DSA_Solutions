# [2610. Convert an Array Into a 2D Array With Conditions](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given an integer array `nums`. You need to create a 2D array from `nums` satisfying the following conditions:

* The 2D array should contain **only** the elements of the array `nums`.
* Each row in the 2D array contains **distinct** integers.
* The number of rows in the 2D array should be **minimal**.

Return *the resulting array*. If there are multiple answers, return any of them.

**Note** that the 2D array can have a different number of elements on each row.

**Example 1:**

```
Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
Explanation: We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: [[4,3,2,1]]
Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
```

**Constraints:**

* `1 <= nums.length <= 200`
* `1 <= nums[i] <= nums.length`

---

## Solution & Editorial
# Intuition
To minimize the number of rows in the 2D array, we must observe that the number of rows is strictly determined by the frequency of the most common element in `nums`. If an element appears $k$ times, it must occupy at least $k$ distinct rows to satisfy the condition that each row contains only distinct integers.

# Approach
1. Use a frequency array `cnt` of size $n+1$ to store the occurrences of each integer in `nums`.
2. Iterate through each unique number $x$ from $1$ to $n$. If $x$ appears $v$ times, it must be placed in the first $v$ rows of the result matrix.
3. For each occurrence $j$ (from $0$ to $v-1$), check if the result matrix `ans` has a row at index $j$. If not, append a new empty row.
4. Push the value $x$ into `ans[j]`.

### Visual Trace (Example 1: nums = [1,3,4,1,2,3,1])
- Frequency map: `cnt[1]=3, cnt[2]=1, cnt[3]=2, cnt[4]=1`
- Processing $x=1$ ($v=3$): `ans` becomes `[[1], [1], [1]]`
- Processing $x=2$ ($v=1$): `ans` becomes `[[1, 2], [1], [1]]`
- Processing $x=3$ ($v=2$): `ans` becomes `[[1, 2, 3], [1, 3], [1]]`
- Processing $x=4$ ($v=1$): `ans` becomes `[[1, 2, 3, 4], [1, 3], [1]]`

# Complexity
- Time complexity: $$O(N)$$, where $N$ is the length of `nums`. We iterate through the array once to count frequencies and then iterate through the frequency counts, which in total perform $N$ insertions into the result matrix.
- Space complexity: $$O(N)$$, required for the frequency array and the output matrix which stores all $N$ elements.

# Code
```cpp
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> cnt(n + 1);
        for (int& x : nums) {
            ++cnt[x];
        }
        for (int x = 1; x <= n; ++x) {
            int v = cnt[x];
            for (int j = 0; j < v; ++j) {
                if (ans.size() <= j) {
                    ans.push_back({});
                }
                ans[j].push_back(x);
            }
        }
        return ans;
    }
};
```

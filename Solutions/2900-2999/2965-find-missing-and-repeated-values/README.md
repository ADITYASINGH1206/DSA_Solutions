# [2965. Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `math`, `matrix`

---

## Problem Description
You are given a **0-indexed** 2D integer matrix `grid` of size `n * n` with values in the range `[1, n2]`. Each integer appears **exactly once** except `a` which appears **twice** and `b` which is **missing**. The task is to find the repeating and missing numbers `a` and `b`.

Return *a **0-indexed** integer array* `ans` *of size* `2` *where* `ans[0]` *equals to* `a` *and* `ans[1]` *equals to* `b`*.*

**Example 1:**

```
Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
```

**Example 2:**

```
Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
```

**Constraints:**

* `2 <= n == grid.length == grid[i].length <= 50`
* `1 <= grid[i][j] <= n * n`
* For all `x` that `1 <= x <= n * n` there is exactly one `x` that is not equal to any of the grid members.
* For all `x` that `1 <= x <= n * n` there is exactly one `x` that is equal to exactly two of the grid members.
* For all `x` that `1 <= x <= n * n` except two of them there is exactly one pair of `i, j` that `0 <= i, j <= n - 1` and `grid[i][j] == x`.

---

## Solution & Editorial
# Intuition
Since the grid contains integers in the range [1, n^2] and we are guaranteed that exactly one number is repeated and one is missing, we can utilize a frequency array to track the occurrences of each number. By iterating through the grid once, we can identify the repeating number, and a subsequent pass over the frequency array reveals the missing number.

# Approach
1. Initialize a frequency vector `freq` of size `n*n + 1` with zeros to store the count of each number encountered.
2. Iterate through every cell in the `grid`. For each value `x`, increment `freq[x]`.
3. If `freq[x]` becomes 2, we have found the repeating number `a`, so store it in `ans[0]`.
4. After traversing the grid, iterate through the `freq` array from index 1 to `n*n`. The index `i` where `freq[i] == 0` is the missing number `b`, which we store in `ans[1]`.

### Visual Trace (Example 1: grid = [[1,3],[2,2]])
- `n = 2`, `n*n = 4`. `freq` size = 5.
- Process (0,0): `x=1`, `freq[1]=1`
- Process (0,1): `x=3`, `freq[3]=1`
- Process (1,0): `x=2`, `freq[2]=1`
- Process (1,1): `x=2`, `freq[2]=2` -> `ans[0] = 2`
- Final `freq`: `[0, 1, 2, 1, 0]`
- Scan `freq`: `freq[4] == 0` -> `ans[1] = 4`
- Return `[2, 4]`

# Complexity
- Time complexity: $$O(n^2)$$ where $$n$$ is the dimension of the grid. We visit each of the $$n^2$$ cells exactly once and then perform a linear scan over the frequency array of size $$n^2+1$$.
- Space complexity: $$O(n^2)$$ to store the frequency counts for all possible values in the range $$[1, n^2]$$.

# Code
```cpp
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n+1,0);
        vector<int> ans(2,0);
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                int x = grid[i][j];
                freq[x]++;
                if(freq[x] == 2) ans[0] =x;
            }
        }
        for(int i =0;i<freq.size();i++){
            if(freq[i] == 0) ans[1] = i;
        }
        return ans;

    }
};
```

# [47. Permutations II](https://leetcode.com/problems/permutations-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `backtracking`, `sorting`

---

## Problem Description
Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**Example 2:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Constraints:**

* `1 <= nums.length <= 8`
* `-10 <= nums[i] <= 10`

---

## Solution & Editorial
# Intuition
The problem asks us to generate all unique permutations of an array containing duplicate elements. By sorting the input array initially and conditionally skipping duplicate swaps at each recursion level, we can effectively avoid generating duplicate permutations without relying on auxiliary hash sets.

# Approach
1. Sort the input vector `num` in non-decreasing order so that identical elements are grouped together.
2. Define a recursive function `recursion(vector<int> num, int i, int j, vector<vector<int>> &res)` that attempts to build permutations by fixing an element at index `i` through swapping with every candidate index `k` from `i` to `j-1`.
3. To handle duplicates, skip any index `k` where `i != k` and `num[i] == num[k]`. This prevents swapping the exact same value into the same position multiple times in the same recursive branch.
4. When `i == j - 1`, the current permutation is fully formed; push `num` into the result container `res` and return.

### Visual Trace Walkthrough (Example 1: `nums = [1, 1, 2]`)
- Initial sort: `[1, 1, 2]`
- `recursion(num, 0, 3)`:
  - `k = 0`: `num[0] == num[0]` -> Swap `num[0]` with `num[0]` (`[1, 1, 2]`) -> `recursion(num, 1, 3)`:
    - `k = 1`: Swap `num[1]` with `num[1]` (`[1, 1, 2]`) -> `recursion(num, 2, 3)` -> Base case reached: adds `[1, 1, 2]` to `res`.
    - `k = 2`: Swap `num[1]` with `num[2]` (`[1, 2, 1]`) -> `recursion(num, 2, 3)` -> Base case reached: adds `[1, 2, 1]` to `res`.
  - `k = 1`: `i != k` (0 != 1) and `num[0] == num[1]` (1 == 1) -> **Skipped** to prevent duplicate branch.
  - `k = 2`: `num[0] != num[2]` (1 != 2) -> Swap `num[0]` with `num[2]` (`[2, 1, 1]`) -> `recursion(num, 1, 3)`:
    - `k = 1`: Swap `num[1]` with `num[1]` (`[2, 1, 1]`) -> `recursion(num, 2, 3)` -> Base case reached: adds `[2, 1, 1]` to `res`.
    - `k = 2`: `num[1] == num[2]` -> **Skipped**.

# Complexity
- Time complexity: $$O(N \cdot N!)$$ where $$N$$ is the number of elements in `nums`. In the worst case, there are $$N!$$ unique permutations, and copying each permutation of length $$N$$ into the result vector takes $$O(N)$$ time.
- Space complexity: $$O(N! \cdot N)$$ to store all the unique permutations in the result vector `res`, plus $$O(N)$$ for the maximum recursion stack depth.

# Code
```cpp
class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
```

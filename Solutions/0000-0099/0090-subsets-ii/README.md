# [90. Subsets II](https://leetcode.com/problems/subsets-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `backtracking`, `bit-manipulation`

---

## Problem Description
Given an integer array `nums` that may contain duplicates, return *all possible* *subsets* *(the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**Example 1:**

```
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```

**Example 2:**

```
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

* `1 <= nums.length <= 10`
* `-10 <= nums[i] <= 10`

---

## Solution & Editorial
# Intuition
The problem asks us to find all unique subsets of an array that contains duplicate elements. By sorting the array initially, identical elements are brought adjacent to each other. This allows us to cleanly handle duplicate subsets by making a binary decision at each index: either include the current element or skip all consecutive occurrences of it.

# Approach
1. First, sort the `nums` array so that duplicates are adjacent, enabling efficient duplicate detection.
2. Define a recursive helper function `backtrack(i, nums, subset, ans)` where `i` represents the current index in `nums`, `subset` stores the current combination, and `ans` accumulates all valid unique subsets.
3. Base Case: When index `i` reaches `nums.size()`, push the current `subset` into `ans` and return.
4. Choice 1 (Include): Include `nums[i]` into `subset`, and recurse to `i + 1`. After returning, backtrack by popping `nums[i]` from `subset`.
5. Choice 2 (Exclude & Skip Duplicates): Advance index `i` past all subsequent identical elements using a `while` loop (`nums[i] == nums[i + 1]`), then recurse to the next distinct element at `i + 1`.

### Visual Trace (Example 1: nums = [1, 2, 2])

```text
Initial: sorted nums = [1, 2, 2]

backtrack(0, [1,2,2], [], ans)
├── Include nums[0]=1 -> subset=[1]
│   └── backtrack(1, [1,2,2], [1], ans)
│       ├── Include nums[1]=2 -> subset=[1, 2]
│       │   └── backtrack(2, [1,2,2], [1,2], ans)
│       │       ├── Include nums[2]=2 -> subset=[1,2,2] -> ans.push
│       │       └── Exclude nums[2]=2 -> subset=[1,2] -> ans.push
│       └── Exclude nums[1]=2 (skips adjacent 2) -> subset=[1] -> ans.push
└── Exclude nums[0]=1 -> subset=[]
    └── backtrack(1, [1,2,2], [], ans)
        ├── Include nums[1]=2 -> subset=[2]
        │   └── backtrack(2, [1,2,2], [2], ans)
        │       ├── Include nums[2]=2 -> subset=[2,2] -> ans.push
        │       └── Exclude nums[2]=2 -> subset=[2] -> ans.push
        └── Exclude nums[1]=2 (skips adjacent 2) -> subset=[] -> ans.push
```

# Complexity
- Time complexity: $$O(N \log N + 2^N)$$, where $$N$$ is the number of elements in `nums`. Sorting takes $$O(N \log N)$$ time, and generating all subsets takes $$O(2^N)$$ time in the worst case where all elements are distinct.
- Space complexity: $$O(N)$$ auxiliary space for the recursion call stack and the `subset` vector during traversal, excluding the space required to store the output `ans` vector.

# Code
```cpp
class Solution {
public:

    void backtrack(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(i + 1, nums, subset, ans);
        subset.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        backtrack(i + 1, nums, subset, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, subset, ans);
        return ans;        
    }
   
};
```

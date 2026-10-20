# [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `backtracking`

---

## Problem Description
Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

**Example 1:**

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**Example 2:**

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
```

**Constraints:**

* `1 <= candidates.length <= 100`
* `1 <= candidates[i] <= 50`
* `1 <= target <= 30`

---

## Solution & Editorial
# Intuition
The problem asks us to find all unique combinations of numbers in `candidates` that sum up to `target`, where each number can be used at most once. Sorting the input array allows us to easily skip duplicate combinations at the same recursion level and prune branches where the current candidate exceeds the remaining target.

# Approach
1. First, sort the `candidates` array in non-decreasing order. Sorting groups identical values together, which is essential for duplicate avoidance.
2. Define a recursive `backtrack` function taking the remaining `target`, current starting index `idx`, reference to `candidates`, reference to `ans` vector, and the current combination vector `cur`.
3. Base Cases: If `target < 0`, return immediately. If `target == 0`, a valid combination is found, so push `cur` into `ans` and return.
4. Iterate through the candidates starting from `idx` up to `candidates.size() - 1`:
   - To avoid duplicate combinations, skip identical adjacent elements at the same tree depth by checking `if (i > idx && candidates[i] == candidates[i - 1]) continue;`.
   - Because the array is sorted, if `candidates[i] > target`, break out of the loop immediately since all subsequent candidates will also be too large.
   - Otherwise, append `candidates[i]` to `cur`, recurse with `target - candidates[i]` and `i + 1` (since each element can be used only once), and then backtrack by popping the element from `cur`.

### Visual Walkthrough for Example 1
`candidates = [10, 1, 2, 7, 6, 1, 5]`, sorted: `[1, 1, 2, 5, 6, 7, 10]`, `target = 8`

| Step | `idx` | `target` | `cur` (Path) | Action / State |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 8 | `[1]` | Include first `1`, recurse to `idx = 1` |
| 2 | 1 | 7 | `[1, 1]` | Include second `1`, recurse to `idx = 2` |
| 3 | 2 | 5 | `[1, 1, 2]` | Include `2`, recurse to `idx = 3` |
| 4 | 3 | 3 | `[1, 1, 2, 5]` | `5 > 3`, break loop |
| 5 | 2 | 6 | `[1, 2]` | Backtrack, include `2` at `idx = 2`, recurse |
| ... | ... | ... | ... | Generates valid sets like `[1, 1, 6]`, `[1, 2, 5]`, `[1, 7]`, `[2, 6]` |

# Complexity
- Time complexity: $$O(2^N)$$ — In the worst-case, each element can either be included or excluded. Sorting takes $$O(N \log N)$$, but the exponential subset generation dominates.
- Space complexity: $$O(N)$$ — The maximum depth of the recursion call stack is bounded by the number of elements $$N$$, alongside auxiliary space for the current path `cur`.

# Code
```cpp
class Solution {
public:
    void backtrack(int target,int idx,vector<int>& candidates,vector<vector<int>>& ans,vector<int>& cur){
        if(target <0) return;
        if(target == 0){
            ans.push_back(cur);
            return;
        }

        for(int i = idx;i<candidates.size();i++){
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            cur.push_back(candidates[i]);
            backtrack(target-candidates[i],i+1,candidates,ans,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(target,0,candidates,ans,cur);
        return ans;
    }
};
```

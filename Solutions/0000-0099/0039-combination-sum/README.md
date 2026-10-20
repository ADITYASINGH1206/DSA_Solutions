# [39. Combination Sum](https://leetcode.com/problems/combination-sum/)
**Difficulty:** `Medium` | **Tags:** `array`, `backtracking`

---

## Problem Description
Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all **unique combinations** of* `candidates` *where the chosen numbers sum to* `target`*.* You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

**Example 1:**

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

**Example 2:**

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

**Example 3:**

```
Input: candidates = [2], target = 1
Output: []
```

**Constraints:**

* `1 <= candidates.length <= 30`
* `2 <= candidates[i] <= 40`
* All elements of `candidates` are **distinct**.
* `1 <= target <= 40`

---

## Solution & Editorial
# Intuition
The problem requires us to find all unique combinations of candidate numbers that sum up to a given target, where each number can be chosen an unlimited number of times. This naturally maps to a subset-sum problem solved via Depth-First Search (DFS) backtracking. By passing a starting index to each recursive call, we avoid generating duplicate permutations and enforce combination uniqueness.

# Approach
1. Define a helper function `backtrack` that accepts `candidates`, remaining `target`, the result collection `ans`, the current combination path `cur`, and the current iteration index `start`.
2. Base Cases: If `target < 0`, the current path exceeds the target, so we immediately terminate the branch. If `target == 0`, we have found a valid combination, so we append `cur` to `ans` and return.
3. Recursive Step: Iterate from `index = start` to `candidates.size() - 1`. For each candidate, append it to `cur`, recursively call `backtrack` with `target - candidates[i]` and the same index `i` (allowing repeated selections), and then backtrack by popping the element from `cur`.
4. Corner Cases: If all candidates are greater than `target`, the loop immediately terminates and returns an empty list.

### Visual Walkthrough (Example 1: candidates = [2, 3, 6, 7], target = 7)
```
backtrack(start=0, target=7, cur=[])
 ├── choose 2 -> backtrack(start=0, target=5, cur=[2])
 │    ├── choose 2 -> backtrack(start=0, target=3, cur=[2, 2])
 │    │    ├── choose 2 -> backtrack(start=0, target=1, cur=[2, 2, 2]) -> target < 0 (return)
 │    │    ├── choose 3 -> backtrack(start=1, target=-2, cur=[2, 2, 3]) -> target < 0 (return)
 │    │    └── ...
 │    ├── choose 3 -> backtrack(start=1, target=2, cur=[2, 3])
 │    │    ├── choose 3 -> backtrack(start=1, target=-1, cur=[2, 3, 3]) -> target < 0 (return)
 │    │    └── ...
 │    └── ...
 └── choose 7 -> backtrack(start=3, target=0, cur=[7]) -> MATCH! ans.push_back([7])
```

# Complexity
- Time complexity: $$O(2^{\frac{target}{\min(candidates)}})$$
  In the worst-case scenario, the maximum depth of the recursion tree is $\frac{target}{\min(candidates)}$, and at each node, we branch up to $N$ choices. However, the constraints limit the total number of valid combinations to less than 150, making actual runtime extremely optimal ($0$ ms).
- Space complexity: $$O(\frac{target}{\min(candidates)})$$
  The auxiliary space is dominated by the recursion stack and the vector `cur`, which grow proportionally to the maximum possible depth of a valid combination path.

# Code
```cpp
class Solution {
public:

    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& cur, int start) {
        if (target < 0) return; 
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], ans, cur, i);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> cur;
        backtrack(candidates, target, ans, cur, 0); 
        return ans;
    }
};
```

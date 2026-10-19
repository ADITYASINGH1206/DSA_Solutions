# [55. Jump Game](https://leetcode.com/problems/jump-game/)
**Difficulty:** `Medium` | **Tags:** `array`, `dynamic-programming`, `greedy`

---

## Problem Description
You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.

Return `true` *if you can reach the last index, or* `false` *otherwise*.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```

**Constraints:**

* `1 <= nums.length <= 104`
* `0 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
The problem asks whether we can reach the last index of the array starting from index 0, where each element denotes the maximum jump length from that position. We can model this as a graph traversal problem where each index is a node and valid jumps are directed edges. Using Depth-First Search with Memoization avoids redundant computations of already visited index states.

# Approach
1. Define a helper function `recurse(nums, index, memo)` that returns a boolean indicating whether the last index can be reached from `index`.
2. Base Case: If `index >= nums.size() - 1`, we have reached or passed the last index, so return `true`.
3. Memoization Check: If `memo[index]` is not `-1`, return its cached result (`1` for true, `0` for false).
4. Compute the maximum reachable index `furthestJump = min((int)nums.size() - 1, index + power)` where `power = nums[index]`.
5. Iterate backward from `furthestJump` down to `index + 1`. Exploring larger jumps first often leads to quicker success paths.
6. If any recursive call returns `true`, cache `memo[index] = 1` and return `true`.
7. If all paths from this index fail, cache `memo[index] = 0` and return `false`.

### Visual Trace Walkthrough (Example 1: nums = [2,3,1,1,4])
- Start at `index = 0`, `nums[0] = 2`, `furthestJump = min(4, 2) = 2`.
- Try `nextIndex = 2`: `recurse(nums, 2, memo)`
  - At `index = 2`, `nums[2] = 1`, `furthestJump = 3`.
  - Try `nextIndex = 3`: `recurse(nums, 3, memo)`
    - At `index = 3`, `nums[3] = 1`, `furthestJump = 4`.
    - Try `nextIndex = 4`: reaches end (`index >= nums.size() - 1`), returns `true`.
  - `memo[3] = 1`, returns `true`.
- `memo[2] = 1`, returns `true`.
- `memo[0] = 1`, returns `true`.

# Complexity
- Time complexity: $$O(N^2)$$ — In the worst-case scenario, each index may try jumping to all subsequent indices within its jump length, but memoization ensures each state is computed at most once.
- Space complexity: $$O(N)$$ — The auxiliary space is dominated by the recursion call stack and the `memo` vector of size $$N$$.

# Code
```cpp
//Memo
class Solution {
public:
    bool recurse(vector<int>& nums, int index, vector<int>& memo) {
        if (index >= nums.size() - 1) return true;

        if (memo[index] != -1) {
            return memo[index] == 1;
        }

        int power = nums[index];
        int furthestJump = min((int)nums.size() - 1, index + power);

        for (int nextIndex = furthestJump; nextIndex > index; nextIndex--) {
            if (recurse(nums, nextIndex, memo)) {
                memo[index] = 1;
                return true;
            }
        }
        
        memo[index] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        // Initialize memo array with -1 (unvisited)
        vector<int> memo(nums.size(), -1);
        return recurse(nums, 0, memo);
    }
};
//Recursive
// class Solution {
// public:
//     bool recurse(vector<int>& nums,int index){
//         if(index>=nums.size()-1) return true;

//         int power = nums[index];


//         return false;
//     }
//     bool canJump(vector<int>& nums) {
//         return recurse(nums,0);
//     }
// };
```

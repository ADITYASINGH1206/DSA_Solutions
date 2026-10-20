# [2974. Minimum Number Game](https://leetcode.com/problems/minimum-number-game/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`, `heap-priority-queue`, `simulation`

---

## Problem Description
You are given a **0-indexed** integer array `nums` of **even** length and there is also an empty array `arr`. Alice and Bob decided to play a game where in every round Alice and Bob will do one move. The rules of the game are as follows:

* Every round, first Alice will remove the **minimum** element from `nums`, and then Bob does the same.
* Now, first Bob will append the removed element in the array `arr`, and then Alice does the same.
* The game continues until `nums` becomes empty.

Return *the resulting array* `arr`.

**Example 1:**

```
Input: nums = [5,4,2,3]
Output: [3,2,5,4]
Explanation: In round one, first Alice removes 2 and then Bob removes 3. Then in arr firstly Bob appends 3 and then Alice appends 2. So arr = [3,2].
At the begining of round two, nums = [5,4]. Now, first Alice removes 4 and then Bob removes 5. Then both append in arr which becomes [3,2,5,4].
```

**Example 2:**

```
Input: nums = [2,5]
Output: [5,2]
Explanation: In round one, first Alice removes 2 and then Bob removes 5. Then in arr firstly Bob appends and then Alice appends. So arr = [5,2].
```

**Constraints:**

* `2 <= nums.length <= 100`
* `1 <= nums[i] <= 100`
* `nums.length % 2 == 0`

---

## Solution & Editorial
# Intuition
The game requires Alice and Bob to repeatedly pick the two smallest elements from the array. Since the game continues until the array is empty, we are essentially processing the elements in non-decreasing order of their values. By sorting the array initially, we can easily access these pairs in sequence.

# Approach
1. Sort the input array `nums` in non-decreasing order. This ensures that for any index `i` (where `i` is even), `nums[i]` and `nums[i+1]` are the two smallest remaining elements.
2. Iterate through the array with a step of 2. In each iteration, swap `nums[i]` and `nums[i+1]`.
3. Because Bob appends his element (the larger of the pair) first, and Alice appends hers (the smaller of the pair) second, the sequence `[smaller, larger]` becomes `[larger, smaller]` in the final array.

### Visual Trace (Example 1: nums = [5, 4, 2, 3])
1. **Initial Sort**: `[2, 3, 4, 5]`
2. **Iteration 1 (i=0)**: Swap `nums[0]` (2) and `nums[1]` (3) -> `[3, 2, 4, 5]`
3. **Iteration 2 (i=2)**: Swap `nums[2]` (4) and `nums[3]` (5) -> `[3, 2, 5, 4]`
4. **Result**: `[3, 2, 5, 4]`

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step, where $$N$$ is the length of the input array. The subsequent linear scan takes $$O(N)$$.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we perform the swaps in-place without auxiliary data structures.

# Code
```cpp
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=2){
            swap(nums[i],nums[i+1]);
        }
        return nums;
    }
};
```

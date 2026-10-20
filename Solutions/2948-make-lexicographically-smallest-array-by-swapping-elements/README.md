# [2948. Make Lexicographically Smallest Array by Swapping Elements](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/)
**Difficulty:** `Medium` | **Tags:** `array`, `union-find`, `sorting`

---

## Problem Description
You are given a **0-indexed** array of **positive** integers `nums` and a **positive** integer `limit`.

In one operation, you can choose any two indices `i` and `j` and swap `nums[i]` and `nums[j]` **if** `|nums[i] - nums[j]| <= limit`.

Return *the **lexicographically smallest array** that can be obtained by performing the operation any number of times*.

An array `a` is lexicographically smaller than an array `b` if in the first position where `a` and `b` differ, array `a` has an element that is less than the corresponding element in `b`. For example, the array `[2,10,3]` is lexicographically smaller than the array `[10,2,3]` because they differ at index `0` and `2 < 10`.

**Example 1:**

```
Input: nums = [1,5,3,9,8], limit = 2
Output: [1,3,5,8,9]
Explanation: Apply the operation 2 times:
- Swap nums[1] with nums[2]. The array becomes [1,3,5,9,8]
- Swap nums[3] with nums[4]. The array becomes [1,3,5,8,9]
We cannot obtain a lexicographically smaller array by applying any more operations.
Note that it may be possible to get the same result by doing different operations.
```

**Example 2:**

```
Input: nums = [1,7,6,18,2,1], limit = 3
Output: [1,6,7,18,1,2]
Explanation: Apply the operation 3 times:
- Swap nums[1] with nums[2]. The array becomes [1,6,7,18,2,1]
- Swap nums[0] with nums[4]. The array becomes [2,6,7,18,1,1]
- Swap nums[0] with nums[5]. The array becomes [1,6,7,18,1,2]
We cannot obtain a lexicographically smaller array by applying any more operations.
```

**Example 3:**

```
Input: nums = [1,7,28,19,10], limit = 3
Output: [1,7,28,19,10]
Explanation: [1,7,28,19,10] is the lexicographically smallest array we can obtain because we cannot apply the operation on any two indices.
```

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 109`
* `1 <= limit <= 109`

---

## Solution & Editorial
# Intuition
The core observation is that the swap condition `|nums[i] - nums[j]| <= limit` defines an equivalence relation. If we sort the array, any two adjacent elements with a difference less than or equal to `limit` belong to the same "connected component" of swappable elements. Within each component, we can rearrange the elements into any order we desire, so the lexicographically smallest result is achieved by placing the smallest available elements of each component into the original positions belonging to that component.

# Approach
1. Create a sorted copy of the input array `sorted`.
2. Partition the `sorted` array into groups where each group contains elements that can be swapped with each other (i.e., the difference between consecutive elements in the sorted array is $\le$ `limit`).
3. Use a hash map `map` to store the mapping from each value to its corresponding group ID.
4. Maintain an index pointer `idx` for each group to track which element from the sorted group should be placed next.
5. Iterate through the original array `A`. For each element, identify its group ID using `map`, pick the smallest available element from that group, and update `A[i]`.

### Visual Trace (Example 1: nums = [1,5,3,9,8], limit = 2)
- Sorted: [1, 3, 5, 8, 9]
- Groups: G0: [1, 3, 5], G1: [8, 9]
- Map: {1:0, 3:0, 5:0, 8:1, 9:1}
- Original indices for G0: {0, 1, 2}, for G1: {3, 4}
- Result construction:
  - i=0 (val 1): G0, next is 1 -> [1, ...]
  - i=1 (val 5): G0, next is 3 -> [1, 3, ...]
  - i=2 (val 3): G0, next is 5 -> [1, 3, 5, ...]
  - i=3 (val 9): G1, next is 8 -> [1, 3, 5, 8, ...]
  - i=4 (val 8): G1, next is 9 -> [1, 3, 5, 8, 9]

# Complexity
- Time complexity: $$O(N \log N)$$ due to the initial sorting of the array. The subsequent grouping and reconstruction take $$O(N)$$ time.
- Space complexity: $$O(N)$$ to store the sorted array, the groups, and the hash map.

# Code
```cpp
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& A, int limit) {
        vector<int> sorted = A;
        ranges::sort(sorted);
        vector<vector<int>> grps;
        unordered_map<int, int> map;
        int id = -1;

        for (int i = 0; i < sorted.size(); i++) {
            if (i == 0 || sorted[i] - sorted[i - 1] > limit) {
                grps.push_back({});
                id++;
            }
            grps[id].push_back(sorted[i]);
            map[sorted[i]] = id;
        }

        vector<int> idx(grps.size(), 0);

        for (int i = 0; i < A.size(); i++) {
            int cur = map[A[i]];
            A[i] = grps[cur][idx[cur]];
            idx[cur]++;
        }

        return A;
    }
};
```

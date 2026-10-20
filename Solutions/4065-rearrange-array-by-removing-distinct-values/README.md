# [4065. Rearrange Array by Removing Distinct Values](https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `sorting`, `heap-priority-queue`, `simulation`, `counting`, `ordered-set`

---

## Problem Description
You are given an integer array `nums`.

You start with an **empty** array `ans`. Repeat the following operation until `nums` is **empty**:

* Identify **all** **distinct** values currently present in `nums`.
* Remove **one** occurrence of every **distinct** value currently in `nums`, and append those values to `ans` in **ascending** order.

Return the array `ans`.

**Example 1:**

**Input:** nums = [3,1,3,2,1,3]

**Output:** [1,2,3,1,3,3]

**Explanation:**

| Operation | Appended to `ans` | `nums` after | `ans` after |
| --- | --- | --- | --- |
| 1 | 1, 2, 3 | `[3, 1, 3]` | `[1, 2, 3]` |
| 2 | 1, 3 | `[3]` | `[1, 2, 3, 1, 3]` |
| 3 | 3 | `[]` | `[1, 2, 3, 1, 3, 3]` |

`nums` is now empty, so the answer is `[1, 2, 3, 1, 3, 3]`.

**Example 2:**

**Input:** nums = [7,7,4,4,4]

**Output:** [4,7,4,7,4]

**Explanation:**

| Operation | Appended to `ans` | `nums` after | `ans` after |
| --- | --- | --- | --- |
| 1 | 4, 7 | `[7, 4, 4]` | `[4, 7]` |
| 2 | 4, 7 | `[4]` | `[4, 7, 4, 7]` |
| 3 | 4 | `[]` | `[4, 7, 4, 7, 4]` |

`nums` is now empty, so the answer is `[4, 7, 4, 7, 4]`.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
The problem requires us to repeatedly extract one occurrence of every unique element currently in the array and append them in ascending order. Since we need to process unique elements in sorted order and track their remaining counts, a frequency map combined with a priority queue (or sorted structure) is ideal to manage the elements efficiently.

# Approach
1. Count the frequency of each number in `nums` using an `unordered_map<int, int> mp`.
2. Push all unique elements and their counts into a `priority_queue` (min-heap) to ensure we always extract the smallest available distinct values first.
3. In each iteration of the `while` loop, extract all elements from the `priority_queue`. Since it is a min-heap, elements are naturally retrieved in ascending order.
4. For each extracted element, decrement its count. If the count remains greater than zero, store it in a temporary vector `next_round`.
5. After the inner loop finishes (processing one full pass of distinct elements), push all elements from `next_round` back into the `priority_queue` to prepare for the next iteration.
6. Repeat until the `priority_queue` is empty.

### Visual Trace (Example 1: [3, 1, 3, 2, 1, 3])
- **Initial State**: `mp = {1:2, 2:1, 3:3}`. `pq = {(1,2), (2,1), (3,3)}`
- **Iteration 1**:
  - Pop (1,2), (2,1), (3,3). `ans = [1, 2, 3]`
  - `next_round = {(1,1), (3,2)}`
  - `pq` becomes `{(1,1), (3,2)}`
- **Iteration 2**:
  - Pop (1,1), (3,2). `ans = [1, 2, 3, 1, 3]`
  - `next_round = {(3,1)}`
  - `pq` becomes `{(3,1)}`
- **Iteration 3**:
  - Pop (3,1). `ans = [1, 2, 3, 1, 3, 3]`
  - `next_round = {}`
  - `pq` empty. Terminate.

# Complexity
- Time complexity: $$O(N \log K)$$, where $$N$$ is the total number of elements and $$K$$ is the number of distinct elements. Each element is pushed and popped from the priority queue at most once per its frequency, but effectively we process each unique element across multiple rounds.
- Space complexity: $$O(N)$$, required for the frequency map and the priority queue to store the input elements.

# Code
```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num : nums) {
            mp[num]++;
        }
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first; 
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        
        for(auto [key, value] : mp) {
            pq.push({key, value});
        }
        
        vector<int> ans;
        
        while(!pq.empty()) {
            vector<pair<int,int>> next_round;
            while(!pq.empty()) {
                auto [key, value] = pq.top();
                pq.pop();
                ans.push_back(key);
                value--;
                if(value > 0) {
                    next_round.push_back({key, value});
                }
            }
            for(auto& p : next_round) {
                pq.push(p);
            }
        }
        
        return ans;
    }
};
```

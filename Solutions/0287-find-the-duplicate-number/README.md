# [287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)
**Difficulty:** `Medium` | **Tags:** `array`, `two-pointers`, `binary-search`, `bit-manipulation`, `pigeonhole-principle`, `floyds-cycle-finding-algorithm`

---

## Problem Description
Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`, return *this repeated number*.

You must solve the problem **without** modifying the array `nums` and using only constant extra space.

**Example 1:**

```
Input: nums = [1,3,4,2,2]
Output: 2
```

**Example 2:**

```
Input: nums = [3,1,3,4,2]
Output: 3
```

**Example 3:**

```
Input: nums = [3,3,3,3,3]
Output: 3
```

**Constraints:**

* `1 <= n <= 105`
* `nums.length == n + 1`
* `1 <= nums[i] <= n`
* All the integers in `nums` appear only **once** except for **precisely one integer** which appears **two or more** times.

**Follow up:**

* How can we prove that at least one duplicate number must exist in `nums`?
* Can you solve the problem in linear runtime complexity?

---

## Solution & Editorial
# Intuition
The problem asks us to find a duplicate number in an array of size $n+1$ containing integers from $1$ to $n$. Since the values act as pointers (indices) mapping into the array itself, we can treat the problem identically to finding the entrance of a cycle in a linked list. This allows us to use Floyd's Tortoise and Hare (Cycle-Finding) algorithm to locate the duplicate in linear time and constant space without modifying the array.

# Approach
1. Initialize two pointers, `slow` and `fast`, both starting at `nums[0]`.
2. **Phase 1 (Detect Cycle):** Move `slow` forward by one step (`slow = nums[slow]`) and `fast` forward by two steps (`fast = nums[nums[fast]]`) until they intersect. This guarantees that they meet inside the cycle.
3. **Phase 2 (Find Entrance):** Reset the `slow` pointer back to `nums[0]`. Then, advance both `slow` and `fast` one step at a time (`slow = nums[slow]`, `fast = nums[fast]`) until they meet again. The meeting point is the start of the cycle, which corresponds to the duplicate number.

### Visual Walkthrough (Example 1: `nums = [1, 3, 4, 2, 2]`, `n = 4`)
Treating values as pointers (`i -> nums[i]`):
- `0 -> 1`
- `1 -> 3`
- `3 -> 2`
- `2 -> 4`
- `4 -> 2` (Cycle: `2 -> 4 -> 2`)

| Step | `slow` | `fast` | Action / Explanation |
|---|---|---|---|
| Start | `nums[0] = 1` | `nums[0] = 1` | Both pointers initialized |
| Iter 1 | `nums[1] = 3` | `nums[nums[1]] = nums[3] = 2` | `slow` moves 1 step, `fast` moves 2 steps |
| Iter 2 | `nums[3] = 2` | `nums[nums[2]] = nums[4] = 2` | `slow` moves to 2, `fast` moves to 2. `slow == fast` (Intersection) |
| Reset | `nums[0] = 1` | `2` | `slow` reset to `nums[0]`, `fast` stays at 2 |
| Phase 2.1 | `nums[1] = 3` | `nums[2] = 4` | Both move 1 step |
| Phase 2.2 | `nums[3] = 2` | `nums[4] = 2` | `slow == fast` (Meeting point = 2). Return `slow` |

# Complexity
- Time complexity: $$O(N)$$ — Phase 1 traverses the cycle in at most $N$ steps, and Phase 2 takes at most $N$ steps from the start to the cycle entrance.
- Space complexity: $$O(1)$$ — Only two integer pointers (`slow` and `fast`) are used regardless of input size $N$.

# Code
```cpp
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];               
            fast = nums[nums[fast]];       
        } while (slow != fast);
        
        slow = nums[0];                      
        
        while (slow != fast) {
            slow = nums[slow];               
            fast = nums[fast];              
        }
        
        return slow;
    }
};
```

# [4038. Count Integers Appearing in a Single Block](https://leetcode.com/problems/count-integers-appearing-in-a-single-block/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
You are given an integer array `nums`.

An integer `x` is **special** if all occurrences of `x` in `nums` appear in a single **contiguous** block.

Return the number of **distinct** special integers in `nums`.

**Example 1:**

**Input:** nums = [1,2,2,1]

**Output:** 1

**Explanation:**

* 1 appears at indices 0 and 3, forming two separate blocks, so it is not special.
* 2 appears in a single contiguous block at indices `[1, 2]`, so it is special.

Therefore, there is one special integer.

**Example 2:**

**Input:** nums = [3,3,1,2,2,1]

**Output:** 2

**Explanation:**

* 3 appears in a single contiguous block at indices `[0, 1]`, so it is special.
* 1 appears at indices 2 and 5, forming two separate blocks, so it is not special.
* 2 appears in a single contiguous block at indices `[3, 4]`, so it is special.

Therefore, there are two special integers.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
An integer is "special" if it appears in exactly one contiguous block. If we iterate through the array and count how many times the value changes from one element to the next, we can track the number of distinct blocks for each integer. If an integer appears in more than one block, its total block count will be greater than 1.

# Approach
1. Initialize an `unordered_map<int, int> mp` to store the number of contiguous blocks encountered for each integer.
2. Start by marking the first element `nums[0]` as having one block (`mp[nums[0]] = 1`).
3. Iterate through the array starting from index 1. Whenever `nums[i]` differs from `nums[i-1]`, it signifies the start of a new block for the value `nums[i]`. Increment the count for `nums[i]` in the map.
4. After the loop, iterate through the map. Any integer with a count of exactly 1 is special.

### Visual Trace (Example 1: [1, 2, 2, 1])
| Index | Value | Change? | Map State |
| :--- | :--- | :--- | :--- |
| 0 | 1 | Initial | {1: 1} |
| 1 | 2 | Yes | {1: 1, 2: 1} |
| 2 | 2 | No | {1: 1, 2: 1} |
| 3 | 1 | Yes | {1: 2, 2: 1} |

Result: Only key '2' has a value of 1. Count = 1.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass to populate the map and a second pass over the map entries (at most 100 distinct integers).
- Space complexity: $$O(K)$$, where $$K$$ is the number of distinct integers in the array (at most 100).

# Code
```cpp
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp;

        int n = nums.size();

        mp[nums[0]] = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]){
                mp[nums[i]]++;
            }
        }

        int cnt = 0;

        for(auto &p : mp){
            if(p.second == 1){
                cnt++;
            }
        }

        return cnt;
    }
};
```

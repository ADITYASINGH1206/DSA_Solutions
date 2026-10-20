# [4048. Count Values With Equally Spaced Occurrences I](https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given an integer array `nums`.

An integer `x` is called **special** if:

* `x` appears **exactly three** times in `nums`.
* **All** three occurrences of `x` are **equally spaced** in `nums`. In other words, if all occurrences of `x` are at indices `i1 < i2 < i3`, then `i2 - i1 = i3 - i2`.

Return the number of **distinct** special integers in `nums`.

**Example 1:**

**Input:** nums = [1,8,1,5,1,5,8,5]

**Output:** 2

**Explanation:**

* 1 is special because it occurs exactly three times at equally spaced indices 0, 2, and 4.
* 5 is special because it occurs exactly three times at equally spaced indices 3, 5, and 7.
* 8 is not special because it occurs only twice.

Therefore, the answer is 2.

**Example 2:**

**Input:** nums = [8,8,8,8]

**Output:** 0

**Explanation:**

8 is not special because it does not occur exactly three times. Therefore, the answer is 0.

**Example 3:**

**Input:** nums = [8,6,6,8,8]

**Output:** 0

**Explanation:**

8 occurs at indices 0, 3, and 4, which are not equally spaced. 6 occurs only twice. Therefore, no integer is special.

**Constraints:**

* `3 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To determine if an integer is "special," we need to track the exact indices of every occurrence of each number in the array. Since we only care about numbers that appear exactly three times and satisfy a specific arithmetic progression property, a hash map mapping each integer to a list of its indices is the most efficient approach.

# Approach
1. Initialize an `unordered_map<int, vector<int>>` named `indices` to store the list of indices for every unique integer in `nums`.
2. Iterate through the input `nums` once, appending the current index `i` to the vector associated with `nums[i]` in the map.
3. Iterate through the map. For each entry, check if the size of the index vector is exactly 3.
4. If the size is 3, verify the equally spaced condition: `idxs[1] - idxs[0] == idxs[2] - idxs[1]`.
5. Increment a counter `ans` if the condition holds.

### Visual Trace (Example 1: nums = [1,8,1,5,1,5,8,5])
| Integer | Indices | Count | Special? |
| :--- | :--- | :--- | :--- |
| 1 | [0, 2, 4] | 3 | Yes (2-0 == 4-2) |
| 8 | [1, 6] | 2 | No |
| 5 | [3, 5, 7] | 3 | Yes (5-3 == 7-5) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. We perform one pass to populate the map and one pass over the map entries (at most $$N$$ entries).
- Space complexity: $$O(N)$$, as we store each index of the input array exactly once in the hash map.

# Code
```cpp
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]].push_back(i);
        }
        
        int ans = 0;
        for (auto [val, idxs] : indices) {
            if (idxs.size() == 3) {
                if (idxs[1] - idxs[0] == idxs[2] - idxs[1]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
```

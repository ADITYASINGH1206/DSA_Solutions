# [4049. Count Values With Equally Spaced Occurrences II](https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-ii/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`

---

## Problem Description
You are given an integer array `nums`.

An integer `x` is called **special** if:

* `x` appears **at least three** times in `nums`.
* **All** occurrences of `x` are **equally spaced** in `nums`. In other words, if all occurrences of `x` are at indices `i1 < i2 < ... < im`, then `i2 - i1 = i3 - i2 = ... = im - im-1`.

Return the number of **distinct** special integers in `nums`.

**Example 1:**

**Input:** nums = [1,8,1,5,1,5,8,5]

**Output:** 2

**Explanation:**

* 1 is special because it occurs at equally spaced indices 0, 2, and 4.
* 5 is special because it occurs at equally spaced indices 3, 5, and 7.
* 8 is not special because it occurs only twice.

Therefore, the answer is 2.

**Example 2:**

**Input:** nums = [8,8,8,8]

**Output:** 1

**Explanation:**

8 is special because it occurs at equally spaced indices 0, 1, 2, and 3. Therefore, the answer is 1.

**Example 3:**

**Input:** nums = [8,6,6,8,8]

**Output:** 0

**Explanation:**

8 occurs at indices 0, 3, and 4, which are not equally spaced. 6 occurs only twice. Therefore, no integer is special.

**Constraints:**

* `3 <= nums.length <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
To determine if an integer is "special," we need to verify two conditions: it must appear at least three times, and the difference between consecutive indices of its occurrences must be constant. Since we need to track indices for every unique value in the input, a hash map mapping each integer to a list of its indices is the most efficient approach.

# Approach
1. Use an `unordered_map<int, vector<int>>` to store the indices of every occurrence of each integer in `nums`.
2. Iterate through the input array once, populating the map. Each key represents a unique integer, and the associated vector contains its indices in increasing order.
3. Iterate through the map. For each entry:
   - Check if the size of the index vector is at least 3. If not, skip it.
   - Calculate the initial difference `diff = idxs[1] - idxs[0]`.
   - Iterate through the remaining indices starting from index 2. If any `idxs[i] - idxs[i-1]` does not equal `diff`, the integer is not special.
   - If all differences match, increment the answer counter.

### Visual Trace (Example 1: nums = [1,8,1,5,1,5,8,5])
| Value | Indices | Size | Special? | Logic |
| :--- | :--- | :--- | :--- | :--- |
| 1 | [0, 2, 4] | 3 | Yes | 2-0=2, 4-2=2 (Match) |
| 8 | [1, 6] | 2 | No | Size < 3 |
| 5 | [3, 5, 7] | 3 | Yes | 5-3=2, 7-5=2 (Match) |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. We traverse the array once to build the map and then iterate over the map entries, visiting each index exactly once.
- Space complexity: $$O(N)$$, as we store every index of the input array exactly once in the hash map.

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
            if (idxs.size() < 3) continue;
            
            bool special = true;
            int diff = idxs[1] - idxs[0];
            
            for (int i = 2; i < idxs.size(); i++) {
                if (idxs[i] - idxs[i-1] != diff) {
                    special = false;
                    break;
                }
            }
            
            if (special) ans++;
        }
        
        return ans;
    }
};
```

# [3843. First Element with Unique Frequency](https://leetcode.com/problems/first-element-with-unique-frequency/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
You are given an integer array `nums`.

Return an integer denoting the **first** element (scanning from left to right) in `nums` whose **frequency** is **unique**. That is, no other integer appears the same number of times in `nums`. If there is no such element, return -1.

**Example 1:**

**Input:** nums = [20,10,30,30]

**Output:** 30

**Explanation:**

* 20 appears once.
* 10 appears once.
* 30 appears twice.
* The frequency of 30 is unique because no other integer appears exactly twice.

**Example 2:**

**Input:** nums = [20,20,10,30,30,30]

**Output:** 20

**Explanation:**

* 20 appears twice.
* 10 appears once.
* 30 appears 3 times.
* The frequency of 20, 10, and 30 are unique. The first element that has unique frequency is 20.

**Example 3:**

**Input:** nums = [10,10,20,20]

**Output:** -1

**Explanation:**

* 10 appears twice.
* 20 appears twice.
* No element has a unique frequency.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To identify the first element with a unique frequency, we must first determine the frequency of every element in the array. Once we have these counts, we need a secondary mechanism to verify if a specific frequency is shared by any other element in the collection.

# Approach
1. **Frequency Mapping**: Use an `unordered_map<int, int> mp` to store the count of each integer present in `nums`. Iterate through `nums` once to populate this map.
2. **Frequency-of-Frequency Mapping**: Use a second `unordered_map<int, int> freq` to count how many distinct integers share the same frequency. Iterate through the `mp` map and increment `freq[count]` for every element's frequency.
3. **Final Scan**: Iterate through the original `nums` array again. For each element, look up its frequency in `mp`. If the count of that frequency in `freq` is exactly 1, it means this frequency is unique, and we return the current element immediately.
4. **Fallback**: If the loop completes without finding such an element, return -1.

### Visual Trace (Example 1: [20, 10, 30, 30])
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Count elements | `mp = {20:1, 10:1, 30:2}` |
| 2 | Count frequencies | `freq = {1:2, 2:1}` |
| 3 | Check 20 | `mp[20]=1`, `freq[1]=2` (Not unique) |
| 4 | Check 10 | `mp[10]=1`, `freq[1]=2` (Not unique) |
| 5 | Check 30 | `mp[30]=2`, `freq[2]=1` (Unique!) |
| 6 | Return | 30 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform three linear passes: one to count elements, one to count frequencies, and one to check for the unique frequency condition.
- Space complexity: $$O(N)$$, as we store at most $$N$$ distinct elements in the `mp` map and at most $$N$$ distinct frequencies in the `freq` map.

# Code
```cpp
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        unordered_map<int, int> freq;
        for (auto const& pair : mp) {
            int frequency = pair.second;
            freq[frequency]++;
        }

        for (int num : nums) {
            int frequency = mp[num];
            if (freq[frequency] == 1) {
                return num;
            }
        }

        return -1;
    }
};
```

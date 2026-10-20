# [2404. Most Frequent Even Element](https://leetcode.com/problems/most-frequent-even-element/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `counting`

---

## Problem Description
Given an integer array `nums`, return *the most frequent even element*.

If there is a tie, return the **smallest** one. If there is no such element, return `-1`.

**Example 1:**

```
Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.
```

**Example 2:**

```
Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.
```

**Example 3:**

```
Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.
```

**Constraints:**

* `1 <= nums.length <= 2000`
* `0 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To find the most frequent even element, we need to filter out odd numbers and track the occurrence count of each even number. Since we need to return the smallest element in case of a frequency tie, using a `std::map` is ideal because it stores keys in ascending order, allowing us to process elements from smallest to largest.

# Approach
1. Initialize a `std::map<int, int> freq` to store the frequency of each even number encountered in `nums`.
2. Iterate through the input array `nums`. If an element `x` is even (`x % 2 == 0`), increment its count in the `freq` map.
3. Initialize `ans = -1` and `maxFreq = 0` to track the result.
4. Iterate through the `freq` map. Since `std::map` is sorted by key, we naturally encounter even numbers in increasing order. If the current `count` is strictly greater than `maxFreq`, update `ans` to the current `number` and `maxFreq` to `count`.
5. Return `ans`.

### Visual Trace (Example 1: [0, 1, 2, 2, 4, 4, 1])
| Step | Element | Even? | Map State (freq) | ans | maxFreq |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | - | {} | -1 | 0 |
| 1 | 0 | Yes | {0: 1} | 0 | 1 |
| 2 | 1 | No | {0: 1} | 0 | 1 |
| 3 | 2 | Yes | {0: 1, 2: 1} | 0 | 1 |
| 4 | 2 | Yes | {0: 1, 2: 2} | 2 | 2 |
| 5 | 4 | Yes | {0: 1, 2: 2, 4: 1} | 2 | 2 |
| 6 | 4 | Yes | {0: 1, 2: 2, 4: 2} | 2 | 2 |
| 7 | 1 | No | {0: 1, 2: 2, 4: 2} | 2 | 2 |

# Complexity
- Time complexity: $$O(N \log K)$$, where $$N$$ is the length of `nums` and $$K$$ is the number of unique even elements. Each insertion into the map takes $$O(\log K)$$, and we iterate over the map once.
- Space complexity: $$O(K)$$, where $$K$$ is the number of unique even elements stored in the map.

# Code
```cpp
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> freq; 
        for(int x: nums){
            if(x % 2 == 0){
                freq[x]++;
            }
        }

        int ans = -1;
        int maxFreq = 0;
        for(auto it : freq){
            int number = it.first;
            int count = it.second;

            if(count > maxFreq){
                ans = number;
                maxFreq = count;
            }

        }
        return ans;
    }
};
```

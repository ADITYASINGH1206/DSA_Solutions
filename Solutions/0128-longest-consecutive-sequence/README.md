# [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `union-find`

---

## Problem Description
Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in `O(n)` time.

**Example 1:**

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

**Example 2:**

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

**Example 3:**

```
Input: nums = [1,0,1,2]
Output: 3
```

**Constraints:**

* `0 <= nums.length <= 105`
* `-109 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
The problem asks us to find the length of the longest consecutive sequence of integers in an unsorted array in linear time $$O(N)$$. Since sorting takes $$O(N 
2$$ or $$O(N 	o 	ext{log } N)$$ time, we can instead utilize an `unordered_set` to achieve $$O(1)$$ average time lookups. By only starting sequence counts from numbers that are the absolute beginning of a consecutive chain (i.e., `num - 1` does not exist in the set), we ensure each number is part of an inner counting loop at most once, guaranteeing linear overall time complexity.

# Approach
1. Insert all elements from `nums` into an `unordered_set<int> st` to remove duplicates and enable $$O(1)$$ average-time lookups. Initialize `longest = 0` to track the maximum sequence length found.
2. Iterate through each unique element `num` in `st`. For each `num`, check whether `num - 1` exists in `st`. 
3. If `num - 1` does not exist, `num` is the start of a consecutive sequence. Initialize `current = num` and `count = 1`.
4. Use a `while` loop to check if `current + 1` exists in `st`. If it does, increment `current` and `count`.
5. Update `longest = max(longest, count)` after the sequence terminates. Return `longest` after checking all sequence starters.

### Visual Walkthrough (Example 1: `nums = [100, 4, 200, 1, 3, 2]`)
- `st = {100, 4, 200, 1, 3, 2}`
- `num = 100`: `99` not in set $\rightarrow$ `current = 100`, `count = 1`, `101` not in set $\rightarrow$ `longest = max(0, 1) = 1`
- `num = 4`: `3` in set, so skip.
- `num = 200`: `199` not in set $\rightarrow$ `current = 200`, `count = 1`, `201` not in set $\rightarrow$ `longest = max(1, 1) = 1`
- `num = 1`: `0` not in set $\rightarrow$ `current = 1`, `count = 1`. Inner loop finds `2`, `3`, `4` consecutively $\rightarrow$ `current = 4`, `count = 4`. `longest = max(1, 4) = 4`
- `num = 3`: `2` in set, skip.
- `num = 2`: `1` in set, skip.
- Final Result: `4`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in `nums`. Inserting elements into the hash set takes $$O(N)$$ time. The outer loop iterates over each unique number once, and the inner `while` loop only executes when `num` is the start of a sequence. Every number is visited a constant number of times across all inner loop traversals, resulting in $$O(N)$$ total time.
- Space complexity: $$O(N)$$ for storing the elements inside the `unordered_set` auxiliary data structure.

# Code
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int longest = 0;

        for(int num : st){
            if(st.find(num-1) == st.end()){
                int current = num;
                int count = 1;
                while(st.find(current+1) != st.end()){
                    current++;
                    count++;
                }

                longest = max(longest,count);
            }
        }

        return longest;
    }
};
```

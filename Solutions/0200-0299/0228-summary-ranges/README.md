# [228. Summary Ranges](https://leetcode.com/problems/summary-ranges/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
You are given a **sorted unique** integer array `nums`.

A **range** `[a,b]` is the set of all integers from `a` to `b` (inclusive).

Return *the **smallest sorted** list of ranges that **cover all the numbers in the array exactly***. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.

Each range `[a,b]` in the list should be output as:

* `"a->b"` if `a != b`
* `"a"` if `a == b`

**Example 1:**

```
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
```

**Example 2:**

```
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
```

**Constraints:**

* `0 <= nums.length <= 20`
* `-231 <= nums[i] <= 231 - 1`
* All the values of `nums` are **unique**.
* `nums` is sorted in ascending order.

---

## Solution & Editorial
# Intuition
The problem asks us to group a sorted unique array of integers into continuous ranges. Since the array is already sorted in ascending order, consecutive elements will increase by exactly 1. We can scan the array in a single pass, tracking the start of the current range and closing the range whenever the sequence breaks or we reach the end of the array.

# Approach
1. Initialize an empty string vector `ans` to store the resulting ranges and get the size `n` of `nums`. Handle the edge case where `n == 0` by immediately returning `ans`.
2. Keep track of the start of the current sequence using an integer variable `start`, initialized to `nums[0]`.
3. Iterate through the array using index `i` from `0` to `n - 1`.
4. At each element, check if the current sequence has ended. A range ends when `i == n - 1` (last element) or `nums[i + 1] != nums[i] + 1` (the next element is not consecutive).
5. When a range ends, check if `start != nums[i]`. If true, format and push `"start->nums[i]"` to `ans`. Otherwise, push `"start"`.
6. If `i != n - 1`, update `start` to `nums[i + 1]` to begin the next range.
7. Return `ans` once the loop completes.

### Visual Trace Walkthrough for Example 1 (`nums = [0, 1, 2, 4, 5, 7]`)

| `i` | `nums[i]` | `nums[i+1]` condition | Range Ends? | `start` | Action / `ans` Push | Updated `start` |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | `1 == 0 + 1` | No | 0 | - | - |
| 1 | 1 | `2 == 1 + 1` | No | 0 | - | - |
| 2 | 2 | `4 != 2 + 1` | Yes | 0 | Push `"0->2"` | 4 |
| 3 | 4 | `5 == 4 + 1` | No | 4 | - | - |
| 4 | 5 | `7 != 5 + 1` | Yes | 4 | Push `"4->5"` | 7 |
| 5 | 7 | `i == n - 1` | Yes | 7 | Push `"7"` | 7 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of elements in `nums`. We traverse the array exactly once, performing constant-time comparisons and string formatting operations.
- Space complexity: $$O(1)$$ auxiliary space, excluding the output vector `ans` which is required to store the result.

# Code
```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
    
        if (n == 0)
        return ans;
        int start = nums[0];

        for (int i = 0; i < n; i++) {
            if (i == n - 1 || nums[i + 1] != nums[i] + 1) {
                if (start != nums[i]) {
                    ans.push_back(to_string(start) + "->" + to_string(nums[i]));
                } 
                else {
                    ans.push_back(to_string(start));
                }
                if (i != n - 1) {
                    start = nums[i + 1];
                }
            }
        }
        return ans;
    }
};
```

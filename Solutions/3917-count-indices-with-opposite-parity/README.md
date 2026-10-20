# [3917. Count Indices With Opposite Parity](https://leetcode.com/problems/count-indices-with-opposite-parity/)
**Difficulty:** `Easy` | **Tags:** `array`

---

## Problem Description
You are given an integer array `nums` of length `n`.

The **score** of an index `i` is defined as the number of indices `j` such that:

* `i < j < n`, and
* `nums[i]` and `nums[j]` have different parity (one is even and the other is odd).

Return an integer array `answer` of length `n`, where `answer[i]` is the score of index `i`.

**Example 1:**

**Input:** nums = [1,2,3,4]

**Output:** [2,1,1,0]

**Explanation:**

* `nums[0] = 1`, which is odd. Thus, the indices `j = 1` and `j = 3` satisfy the conditions, so the score of index 0 is 2.
* `nums[1] = 2`, which is even. Thus, the index `j = 2` satisfies the conditions, so the score of index 1 is 1.
* `nums[2] = 3`, which is odd. Thus, the index `j = 3` satisfies the conditions, so the score of index 2 is 1.
* `nums[3] = 4`, which is even. Thus, no index satisfies the conditions, so the score of index 3 is 0.

Thus, the `answer = [2, 1, 1, 0]`.

**Example 2:**

**Input:** nums = [1]

**Output:** [0]

**Explanation:**

There is only one element in `nums`. Thus, the score of index 0 is 0.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 100`

---

## Solution & Editorial
# Intuition
To determine the number of elements with opposite parity appearing after index `i`, we don't need to re-scan the array for every index. By iterating backwards from the end of the array, we can maintain a running count of how many even and odd numbers we have encountered so far. This allows us to compute the score for each index in constant time.

# Approach
1. Initialize two counters, `odd` and `even`, to zero. These track the number of odd and even integers encountered to the right of the current index.
2. Iterate through the input array `nums` from right to left (index `n-1` down to `0`).
3. For each index `i`:
   - If `nums[i]` is even, the number of elements with opposite parity to its right is exactly the current count of `odd` numbers. Increment the `even` counter.
   - If `nums[i]` is odd, the number of elements with opposite parity to its right is exactly the current count of `even` numbers. Increment the `odd` counter.
4. Store the result in `answer[i]` and return the array.

### Visual Trace (Example 1: [1, 2, 3, 4])
| Index | Value | Parity | `odd` | `even` | `answer[i]` |
|-------|-------|--------|-------|--------|-------------|
| 3     | 4     | Even   | 0     | 0      | 0           |
| 2     | 3     | Odd    | 0     | 1      | 1           |
| 1     | 2     | Even   | 1     | 1      | 1           |
| 0     | 1     | Odd    | 1     | 2      | 2           |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. We perform a single pass over the input array.
- Space complexity: $$O(N)$$ to store the result array, or $$O(1)$$ auxiliary space if we exclude the output storage.

# Code
```cpp
class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int odd = 0;
        int even = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) { 
                answer[i] = odd;
                even++;
            } else {                
                answer[i] = even;
                odd++;
            }
        }
        
        return answer;
    }
};
```

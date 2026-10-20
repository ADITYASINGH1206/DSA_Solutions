# [3719. Longest Balanced Subarray I](https://leetcode.com/problems/longest-balanced-subarray-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `divide-and-conquer`, `segment-tree`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums`.

A **subarray** is called **balanced** if the number of **distinct even** numbers in the subarray is equal to the number of **distinct odd** numbers.

Return the length of the **longest** balanced subarray.

**Example 1:**

**Input:** nums = [2,5,4,3]

**Output:** 4

**Explanation:**

* The longest balanced subarray is `[2, 5, 4, 3]`.
* It has 2 distinct even numbers `[2, 4]` and 2 distinct odd numbers `[5, 3]`. Thus, the answer is 4.

**Example 2:**

**Input:** nums = [3,2,2,5,4]

**Output:** 5

**Explanation:**

* The longest balanced subarray is `[3, 2, 2, 5, 4]`.
* It has 2 distinct even numbers `[2, 4]` and 2 distinct odd numbers `[3, 5]`. Thus, the answer is 5.

**Example 3:**

**Input:** nums = [1,2,3,2]

**Output:** 3

**Explanation:**

* The longest balanced subarray is `[2, 3, 2]`.
* It has 1 distinct even number `[2]` and 1 distinct odd number `[3]`. Thus, the answer is 3.

**Constraints:**

* `1 <= nums.length <= 1500`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To determine if a subarray is balanced, we need to track the count of distinct even and odd numbers within that range. Since the constraints are $N \le 1500$, an $O(N^2)$ approach is efficient enough to pass within the time limits.

# Approach
1. Iterate through every possible starting index `i` of the subarray.
2. For each `i`, maintain a hash map (`count`) to track numbers already encountered in the current window to identify distinct elements.
3. Maintain two counters, `even` and `odd`, representing the number of distinct even and odd integers found so far in the subarray starting at `i` and ending at `j`.
4. As we expand the window by incrementing `j`, check if `nums[j]` is new using the hash map. If it is, increment the corresponding `even` or `odd` counter.
5. If `even == odd` and both are greater than 0, update the global maximum length `ans` with the current window size `j - i + 1`.

### Visual Trace (Example 3: nums = [1, 2, 3, 2])
| i | j | nums[j] | Distinct Even | Distinct Odd | Balanced? | Max Len |
|---|---|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 1 | No | 0 |
| 0 | 1 | 2 | 1 | 1 | Yes | 2 |
| 0 | 2 | 3 | 1 | 2 | No | 2 |
| 0 | 3 | 2 | 1 | 2 | No | 2 |
| 1 | 1 | 2 | 1 | 0 | No | 2 |
| 1 | 2 | 3 | 1 | 1 | Yes | 3 |
| 1 | 3 | 2 | 1 | 1 | Yes | 3 |

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the length of the array. We use nested loops to iterate over all possible subarrays, and hash map operations are $O(1)$ on average.
- Space complexity: $$O(N)$$ to store the distinct elements in the hash map for each starting position `i`.

# Code
```cpp
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int even = 0;
            int odd = 0;
            unordered_map<int,int> count;
            for(int j=i;j<n;j++){
                if(!count.contains(nums[j])){
                    if(nums[j] %2 == 0){
                        even++;
                    }else{
                        odd++;
                    }
                }
                if(even == odd && even != 0){
                    ans = max(ans,j-i+1);
                }
                count[nums[j]]++;

            }
        }
        return ans;
    }
};
```

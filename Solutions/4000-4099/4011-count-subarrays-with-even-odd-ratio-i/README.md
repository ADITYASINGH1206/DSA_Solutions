# [4011. Count Subarrays With Even Odd Ratio I](https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `divide-and-conquer`, `binary-indexed-tree`, `segment-tree`, `merge-sort`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums` and two integers `a` and `b`.

For a subarray, let:

* `x` be the number of even elements.
* `y` be the number of odd elements.

The ratio of even to odd elements in a subarray is defined as `x / y`, where ratios are compared by their exact rational values.

A subarray is considered **valid** if:

* `y > 0`, and
* `x / y <= a / b`.

Return the number of valid subarrays in `nums`.

**Example 1:**

**Input:** nums = [1,2,1,2], a = 3, b = 2

**Output:** 7

**Explanation:**

The following are the valid subarrays:

| Subarray | Values | Even Count | Odd Count | Ratio |
| --- | --- | --- | --- | --- |
| `nums[0..0]` | `[1]` | 0 | 1 | `0 / 1` |
| `nums[0..1]` | `[1, 2]` | 1 | 1 | `1 / 1` |
| `nums[0..2]` | `[1, 2, 1]` | 1 | 2 | `1 / 2` |
| `nums[0..3]` | `[1, 2, 1, 2]` | 2 | 2 | `2 / 2` |
| `nums[1..2]` | `[2, 1]` | 1 | 1 | `1 / 1` |
| `nums[2..2]` | `[1]` | 0 | 1 | `0 / 1` |
| `nums[2..3]` | `[1, 2]` | 1 | 1 | `1 / 1` |

Thus, the number of valid subarrays is 7.

**Example 2:**

**Input:** nums = [2,2,1], a = 2, b = 1

**Output:** 3

**Explanation:**

The following are the valid subarrays:

| Subarray | Values | Even Count | Odd Count | Ratio |
| --- | --- | --- | --- | --- |
| `nums[0..2]` | `[2, 2, 1]` | 2 | 1 | `2 / 1` |
| `nums[1..2]` | `[2, 1]` | 1 | 1 | `1 / 1` |
| `nums[2..2]` | `[1]` | 0 | 1 | `0 / 1` |

Thus, the number of valid subarrays is 3.

**Example 3:**

**Input:** nums = [2,2,2], a = 1, b = 1

**Output:** 0

**Explanation:**

Every subarray contains 0 odd numbers, so no subarray is valid.

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`
* `1 <= a, b <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks us to count subarrays where the ratio of even numbers ($x$) to odd numbers ($y$) satisfies $x/y \le a/b$. Since the constraints on the array length are small ($N \le 1000$), an $O(N^2)$ approach is perfectly efficient to explore all possible subarrays.

# Approach
1. Iterate through every possible starting index `i` from $0$ to $n-1$.
2. For each `i`, maintain a running count of even numbers (`even`) and odd numbers (`odd`) as we extend the subarray to index `j` (where $j$ ranges from $i$ to $n-1$).
3. For each subarray `nums[i..j]`, check the condition: `odd > 0` and `even * b <= odd * a`. The multiplication `even * b <= odd * a` is mathematically equivalent to $x/y \le a/b$ while avoiding floating-point precision issues.
4. Increment the answer counter whenever the condition is met.

### Visual Trace (Example 1: nums=[1, 2, 1, 2], a=3, b=2)
| i | j | Subarray | Even | Odd | Condition (even*2 <= odd*3) | Valid |
|---|---|---|---|---|---|---|
| 0 | 0 | [1] | 0 | 1 | 0 <= 3 | Yes |
| 0 | 1 | [1, 2] | 1 | 1 | 2 <= 3 | Yes |
| 0 | 2 | [1, 2, 1] | 1 | 2 | 2 <= 6 | Yes |
| 0 | 3 | [1, 2, 1, 2] | 2 | 2 | 4 <= 6 | Yes |

# Complexity
- Time complexity: $$O(N^2)$$ where $N$ is the length of the array. We use nested loops to iterate over all possible subarrays, performing constant-time arithmetic operations inside the inner loop.
- Space complexity: $$O(1)$$ as we only use a few integer variables to track counts and the result, regardless of input size.

# Code
```cpp
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ans =0;
        for(int i =0;i<n;i++){
            int odd = 0 ,even =0;
            for(int j =i;j<n;j++){
                if(nums[j]%2==0){
                    even++;
                }else{
                    odd++;
                }
                if(odd && even*b<=odd*a){
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

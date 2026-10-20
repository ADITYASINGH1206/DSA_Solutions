# [3020. Find the Maximum Number of Elements in Subset](https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `enumeration`

---

## Problem Description
You are given an array of **positive** integers `nums`.

You need to select a subset of `nums` which satisfies the following condition:

* You can place the selected elements in a **0-indexed** array such that it follows the pattern: `[x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x]` (**Note** that `k` can be any **non-negative** power of `2`). For example, `[2, 4, 16, 4, 2]` and `[3, 9, 3]` follow the pattern while `[2, 4, 8, 4, 2]` does not.

Return *the **maximum** number of elements in a subset that satisfies these conditions.*

**Example 1:**

```
Input: nums = [5,4,1,2,2]
Output: 3
Explanation: We can select the subset {4,2,2}, which can be placed in the array as [2,4,2] which follows the pattern and 22 == 4. Hence the answer is 3.
```

**Example 2:**

```
Input: nums = [1,3,2,4]
Output: 1
Explanation: We can select the subset {1}, which can be placed in the array as [1] which follows the pattern. Hence the answer is 1. Note that we could have also selected the subsets {2}, {3}, or {4}, there may be multiple subsets which provide the same answer.
```

**Constraints:**

* `2 <= nums.length <= 105`
* `1 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
The problem asks for the longest sequence of the form $[x, x^2, x^4, \dots, x^k, \dots, x^4, x^2, x]$. This structure implies that for any $x > 1$, we can form a chain by repeatedly squaring $x$ as long as the frequency of the current value is at least 2. Once we reach a value $x^k$ that has a frequency of 1, that value must be the peak of our sequence. The special case is $x=1$, which can be included as many times as it appears, provided the total count is odd.

# Approach
1. **Frequency Map**: Count occurrences of each number in `nums` using an `unordered_map`.
2. **Handle 1s**: The number 1 is unique because $1^2 = 1$. If we have $c$ ones, we can form a sequence of length $c$ if $c$ is odd, or $c-1$ if $c$ is even. This is calculated as `(freq[1] - 1) | 1`.
3. **Iterate Bases**: For every other number $x > 1$, treat it as the potential start of a chain. To avoid redundant calculations, skip $x$ if it is a perfect square of another number already present in the map with frequency $> 1$.
4. **Chain Building**: For each valid base $x$, repeatedly square it as long as the frequency is $\ge 2$. Increment the count by 2 for each step. Finally, add 1 if the resulting peak $x^k$ exists in the map.

### Visual Trace (Example 1: [5, 4, 1, 2, 2])
- `freq`: {5:1, 4:1, 1:1, 2:2}
- `res` (for 1s): (1-1)|1 = 1
- Process 2: `freq[2]=2` (>=2), `freq[4]=1` (peak). Chain: [2, 4, 2]. Length: 2 + 1 = 3.
- Process 4: `sqrt(4)=2`, `freq[2]=2 > 1`, skip.
- Process 5: `freq[5]=1`. Chain: [5]. Length: 1.
- Max result: 3.

# Complexity
- Time complexity: $$O(N + M \log(\log(\max(nums))))$$ where $N$ is the number of elements and $M$ is the number of unique elements. The squaring process grows exponentially, reaching $10^9$ in very few steps.
- Space complexity: $$O(N)$$ to store the frequency map.

# Code
```cpp
class Solution {
    static constexpr int MAX_BASE = 31622;

public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto& n : nums)
            freq[n]++;

        int res = (freq[1] - 1) | 1;
        freq.erase(1);

        for (auto& f : freq) {
            int n = 0, x = f.first;

            int sq = sqrt(x);
            if (sq * sq == x && freq.count(sq) && freq[sq] > 1)
                continue;

            while (x <= MAX_BASE && freq.count(x) && freq[x] > 1) {
                n += 2;
                x *= x;
            }

            res = fmax(res, n + ((freq.count(x) << 1) - 1));
        }

        return res;
    }
};
```

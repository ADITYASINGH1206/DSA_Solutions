# [386. Lexicographical Numbers](https://leetcode.com/problems/lexicographical-numbers/)
**Difficulty:** `Medium` | **Tags:** `depth-first-search`, `trie`

---

## Problem Description
Given an integer `n`, return all the numbers in the range `[1, n]` sorted in lexicographical order.

You must write an algorithm that runs in `O(n)` time and uses `O(1)` extra space.

**Example 1:**

```
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
```

**Example 2:**

```
Input: n = 2
Output: [1,2]
```

**Constraints:**

* `1 <= n <= 5 * 104`

---

## Solution & Editorial
# Intuition
The problem requires generating numbers from $1$ to $n$ in lexicographical order in linear time and constant auxiliary space. Instead of using recursive Depth-First Search or converting numbers to strings for sorting, we can maintain the current number via state transitions that simulate a pre-order traversal of a decimal trie iteratively.

# Approach
1. Initialize a result vector `ans` and set our starting number `count = 1`.
2. Run a loop `i` from $0$ to $n - 1$ to generate all $n$ numbers.
3. At each iteration, append the current `count` to `ans`.
4. To determine the next lexicographical number:
   - If multiplying `count` by $10$ does not exceed $n$ (`count * 10 <= n`), we go deeper into the decimal tree by setting `count *= 10`.
   - Otherwise, we must move to the next sibling or backtrack to higher levels. If `count >= n`, we divide by $10$ to return to the parent node. We then increment `count` (`count++`).
   - While `count` ends in a trailing zero (`count % 10 == 0`), we repeatedly divide by $10$ to normalize back after a boundary rollover.

### Visual Trace Walkthrough (for `n = 13`)
| Iteration `i` | Current `count` before push | Action / Next State Transition | `ans` state |
| :--- | :--- | :--- | :--- |
| 0 | 1 | `1 * 10 <= 13` $ightarrow$ `count *= 10` | `[1]` |
| 1 | 10 | `10 * 10 > 13`, `10 < 13` $ightarrow$ `count++` | `[1, 10]` |
| 2 | 11 | `11 * 10 > 13`, `11 < 13` $ightarrow$ `count++` | `[1, 10, 11]` |
| 3 | 12 | `12 * 10 > 13`, `12 < 13` $ightarrow$ `count++` | `[1, 10, 11, 12]` |
| 4 | 13 | `13 * 10 > 13`, `13 >= 13` $ightarrow$ `count /= 10` (1), `count++` (2), `while(2 % 10 == 0)` false | `[1, 10, 11, 12, 13]` |
| 5 | 2 | `2 * 10 <= 13` $ightarrow$ `count *= 10` (20, but wait: `2 * 10 <= 13` is false since 20 > 13)... | `[1, 10, 11, 12, 13, 2]` |

# Complexity
- Time complexity: $$O(n)$$ — Each of the $n$ numbers is visited exactly once. The inner while-loop for backtracking executes a bounded number of times proportional to the number of digits in $n$, amortizing to $O(1)$ per iteration.
- Space complexity: $$O(1)$$ auxiliary space (excluding the output vector `ans`), as only a few primitive integer variables are maintained.

# Code
```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int count = 1;
        for (int i = 0; i < n; i++) {
            ans.push_back(count);
            if (count * 10 <= n) {
                count *= 10;  
            } else {
                if (count >= n) count /= 10;  
                count++;
                while (count % 10 == 0) count /= 10;
            }
        }
        return ans;
    }
};
```

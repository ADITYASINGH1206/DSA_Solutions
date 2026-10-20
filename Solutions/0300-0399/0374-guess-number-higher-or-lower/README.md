# [374. Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/)
**Difficulty:** `Easy` | **Tags:** `binary-search`, `interactive`

---

## Problem Description
We are playing the Guess Game. The game is as follows:

I pick a number from `1` to `n`. You have to guess which number I picked (the number I picked stays the same throughout the game).

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API `int guess(int num)`, which returns three possible results:

* `-1`: Your guess is higher than the number I picked (i.e. `num > pick`).
* `1`: Your guess is lower than the number I picked (i.e. `num < pick`).
* `0`: your guess is equal to the number I picked (i.e. `num == pick`).

Return *the number that I picked*.

**Example 1:**

```
Input: n = 10, pick = 6
Output: 6
```

**Example 2:**

```
Input: n = 1, pick = 1
Output: 1
```

**Example 3:**

```
Input: n = 2, pick = 1
Output: 1
```

**Constraints:**

* `1 <= n <= 231 - 1`
* `1 <= pick <= n`

---

## Solution & Editorial
# Intuition
The problem asks us to find a hidden number within a sorted range `[1, n]` using an interactive API `guess(num)` that provides feedback on whether our guess is too high, too low, or correct. Since the search space is sorted and monotonic, we can apply standard binary search to halve the search range at each step.

# Approach
1. Initialize two pointers, `low = 1` and `high = n`, representing the current search bounds.
2. Enter a `while` loop that continues as long as `low <= high`.
3. Compute the midpoint safely to prevent integer overflow using `int mid = low + (high - low) / 2;`.
4. Call the API `int result = guess(mid);` to obtain feedback.
5. If `result == 0`, `mid` is the correct pick, so return `mid` immediately.
6. If `result == 1`, the picked number is higher than our guess, so update the lower bound to `low = mid + 1`.
7. If `result == -1`, the picked number is lower than our guess, so update the upper bound to `high = mid - 1`.
8. If the loop terminates without finding the answer (though guaranteed to exist within constraints), return `-1`.

### Visual Trace (Example 1: n = 10, pick = 6)

| Iteration | low | high | mid | guess(mid) | Action |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | 10 | 5 | 1 | `low = mid + 1` (6) |
| 2 | 6 | 10 | 8 | -1 | `high = mid - 1` (7) |
| 3 | 6 | 7 | 6 | 0 | Return `6` |

# Complexity
- Time complexity: $$O(\log n)$$ — The search space is halved in each iteration of the binary search, requiring at most $$\log_2(n)$$ queries.
- Space complexity: $$O(1)$$ — Only a few integer variables (`low`, `high`, `mid`, `result`) are used, requiring constant auxiliary memory.

# Code
```cpp
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1 , high = n;
        while(low<=high){
            int mid = low+ (high-low)/2;
            int result = guess(mid);
            if(result==0){
                return mid;
            }else if(result == 1){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
};
```

# [1534. Count Good Triplets](https://leetcode.com/problems/count-good-triplets/)
**Difficulty:** `Easy` | **Tags:** `array`, `enumeration`

---

## Problem Description
Given an array of integers `arr`, and three integers `a`, `b` and `c`. You need to find the number of good triplets.

A triplet `(arr[i], arr[j], arr[k])` is **good** if the following conditions are true:

* `0 <= i < j < k < arr.length`
* `|arr[i] - arr[j]| <= a`
* `|arr[j] - arr[k]| <= b`
* `|arr[i] - arr[k]| <= c`

Where `|x|` denotes the absolute value of `x`.

Return *the number of good triplets*.

**Example 1:**

```

Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
Output: 4
Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
```

**Example 2:**

```

Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
Output: 0
Explanation: No triplet satisfies all conditions.
```

**Constraints:**

* `3 <= arr.length <= 100`
* `0 <= arr[i] <= 1000`
* `0 <= a, b, c <= 1000`

---

## Solution & Editorial
# Intuition
Since the constraints on the array length are small ($N \le 100$), an $O(N^3)$ approach is perfectly acceptable and efficient. The problem asks us to count triplets $(i, j, k)$ that satisfy three specific absolute difference conditions. We can achieve this by exhaustively checking every possible combination of indices.

# Approach
1. Initialize a counter `ans` to 0.
2. Use three nested loops to iterate through all possible index triplets $(i, j, k)$ such that $0 \le i < j < k < n$.
3. For each triplet, evaluate the three conditions:
   - `abs(arr[i] - arr[j]) <= a`
   - `abs(arr[j] - arr[k]) <= b`
   - `abs(arr[i] - arr[k]) <= c`
4. If all conditions are true, increment `ans`.

### Visual Trace (Example 1: arr = [3, 0, 1, 1, 9, 7], a=7, b=2, c=3)
| i | j | k | arr[i], arr[j], arr[k] | Cond 1 (<=7) | Cond 2 (<=2) | Cond 3 (<=3) | Valid? |
|---|---|---|-----------------------|--------------|--------------|--------------|--------|
| 0 | 1 | 2 | 3, 0, 1               | |3-0|=3 (T)  | |0-1|=1 (T)  | |3-1|=2 (T)  | Yes    |
| 0 | 1 | 3 | 3, 0, 1               | |3-0|=3 (T)  | |0-1|=1 (T)  | |3-1|=2 (T)  | Yes    |
| 0 | 2 | 3 | 3, 1, 1               | |3-1|=2 (T)  | |1-1|=0 (T)  | |3-1|=2 (T)  | Yes    |
| 1 | 2 | 3 | 0, 1, 1               | |0-1|=1 (T)  | |1-1|=0 (T)  | |0-1|=1 (T)  | Yes    |

# Complexity
- Time complexity: $$O(N^3)$$ where $N$ is the length of the array. We iterate through all triplets, resulting in $\frac{N(N-1)(N-2)}{6}$ iterations.
- Space complexity: $$O(1)$$ as we only use a few integer variables for counting and indexing.

# Code
```cpp
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    ans += abs(arr[i] - arr[j]) <= a &&
                           abs(arr[j] - arr[k]) <= b &&
                           abs(arr[i] - arr[k]) <= c;
                }
            }
        }
        return ans;
    }
};
```

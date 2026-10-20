# [2515. Shortest Distance to Target String in a Circular Array](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
You are given a **0-indexed** **circular** string array `words` and a string `target`. A **circular array** means that the array's end connects to the array's beginning.

* Formally, the next element of `words[i]` is `words[(i + 1) % n]` and the previous element of `words[i]` is `words[(i - 1 + n) % n]`, where `n` is the length of `words`.

Starting from `startIndex`, you can move to either the next word or the previous word with `1` step at a time.

Return *the **shortest** distance needed to reach the string* `target`. If the string `target` does not exist in `words`, return `-1`.

**Example 1:**

```
Input: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
Output: 1
Explanation: We start from index 1 and can reach "hello" by
- moving 3 units to the right to reach index 4.
- moving 2 units to the left to reach index 4.
- moving 4 units to the right to reach index 0.
- moving 1 unit to the left to reach index 0.
The shortest distance to reach "hello" is 1.
```

**Example 2:**

```
Input: words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
Output: 1
Explanation: We start from index 0 and can reach "leetcode" by
- moving 2 units to the right to reach index 2.
- moving 1 unit to the left to reach index 2.
The shortest distance to reach "leetcode" is 1.
```

**Example 3:**

```
Input: words = ["i","eat","leetcode"], target = "ate", startIndex = 0
Output: -1
Explanation: Since "ate" does not exist in words, we return -1.
```

**Constraints:**

* `1 <= words.length <= 100`
* `1 <= words[i].length <= 100`
* `words[i]` and `target` consist of only lowercase English letters.
* `0 <= startIndex < words.length`

---

## Solution & Editorial
# Intuition
Since the array is circular, the distance between any two indices `i` and `startIndex` is not just the absolute difference `|i - startIndex|`. Instead, it is the minimum of moving clockwise or counter-clockwise, which is `min(|i - startIndex|, n - |i - startIndex|)`.

# Approach
1. Initialize `ans` to a value larger than any possible distance (e.g., `n`).
2. Iterate through every index `i` in the `words` array.
3. If `words[i]` matches the `target` string:
    - Calculate the direct distance `t = abs(i - startIndex)`.
    - The circular distance is `min(t, n - t)`.
    - Update `ans` with the minimum of its current value and the calculated circular distance.
4. If `ans` remains unchanged (still `n`), it means the target was never found; return `-1`. Otherwise, return `ans`.

### Visual Trace (Example 1: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1)
| Index (i) | Word | Match? | Direct (t) | Circular (min(t, 5-t)) | ans |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | "hello" | Yes | |1-0| = 1 | min(1, 4) = 1 | 1 |
| 1 | "i" | No | - | - | 1 |
| 2 | "am" | No | - | - | 1 |
| 3 | "leetcode" | No | - | - | 1 |
| 4 | "hello" | Yes | |1-4| = 3 | min(3, 2) = 2 | 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of words in the array. We perform a single linear pass over the input array.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n;
        for (int i = 0; i < n; ++i) {
            auto w = words[i];
            if (w == target) {
                int t = abs(i - startIndex);
                ans = min(ans, min(t, n - t));
            }
        }
        return ans == n ? -1 : ans;
    }
};
```

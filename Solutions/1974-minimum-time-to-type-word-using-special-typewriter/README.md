# [1974. Minimum Time to Type Word Using Special Typewriter](https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/)
**Difficulty:** `Easy` | **Tags:** `string`, `greedy`

---

## Problem Description
There is a special typewriter with lowercase English letters `'a'` to `'z'` arranged in a **circle** with a **pointer**. A character can **only** be typed if the pointer is pointing to that character. The pointer is **initially** pointing to the character `'a'`.

Each second, you may perform one of the following operations:

* Move the pointer one character **counterclockwise** or **clockwise**.
* Type the character the pointer is **currently** on.

Given a string `word`, return the **minimum** number of seconds to type out the characters in `word`.

**Example 1:**

```
Input: word = "abc"
Output: 5
Explanation: 
The characters are printed as follows:
- Type the character 'a' in 1 second since the pointer is initially on 'a'.
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer clockwise to 'c' in 1 second.
- Type the character 'c' in 1 second.
```

**Example 2:**

```
Input: word = "bza"
Output: 7
Explanation:
The characters are printed as follows:
- Move the pointer clockwise to 'b' in 1 second.
- Type the character 'b' in 1 second.
- Move the pointer counterclockwise to 'z' in 2 seconds.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'a' in 1 second.
- Type the character 'a' in 1 second.
```

**Example 3:**

```
Input: word = "zjpc"
Output: 34
Explanation:
The characters are printed as follows:
- Move the pointer counterclockwise to 'z' in 1 second.
- Type the character 'z' in 1 second.
- Move the pointer clockwise to 'j' in 10 seconds.
- Type the character 'j' in 1 second.
- Move the pointer clockwise to 'p' in 6 seconds.
- Type the character 'p' in 1 second.
- Move the pointer counterclockwise to 'c' in 13 seconds.
- Type the character 'c' in 1 second.
```

**Constraints:**

* `1 <= word.length <= 100`
* `word` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
Since the typewriter is circular, the distance between any two characters `a` and `b` can be traversed in two directions: clockwise or counterclockwise. To minimize the time, we simply choose the shorter path between the current pointer position and the target character for each letter in the word.

# Approach
1. Initialize `cur` to 0 (representing 'a') and `ans` to 0.
2. Iterate through each character in `word`:
   - Calculate the `target` index (0-25).
   - Find the absolute difference `diff` between `cur` and `target`.
   - The minimum distance is `min(diff, 26 - diff)` because the circle has 26 characters.
   - Add the minimum distance plus 1 (for the typing action) to `ans`.
   - Update `cur` to `target`.

### Visual Trace (Example: "bza")
| Step | Target | Current | Diff | Min Move | Ans (Cumulative) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | 0 ('a') | - | - | 0 |
| 1 | 1 ('b') | 0 | 1 | min(1, 25) = 1 | 1 + 1 = 2 |
| 2 | 25 ('z') | 1 | 24 | min(24, 2) = 2 | 2 + 2 + 1 = 5 |
| 3 | 0 ('a') | 25 | 25 | min(25, 1) = 1 | 5 + 1 + 1 = 7 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we iterate through the word exactly once.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        int ans = 0;
        int cur = 0; 
        for(int i = 0; i < n; i++){
            int target = word[i] - 'a';
            int diff = abs(cur - target);
            int min_move = min(diff, 26 - diff);
            ans += min_move + 1;
            cur = target;
        }
        
        return ans;
    }
};
```

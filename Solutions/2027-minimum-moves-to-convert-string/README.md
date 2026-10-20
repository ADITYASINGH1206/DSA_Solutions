# [2027. Minimum Moves to Convert String](https://leetcode.com/problems/minimum-moves-to-convert-string/)
**Difficulty:** `Easy` | **Tags:** `string`, `greedy`

---

## Problem Description
You are given a string `s` consisting of `n` characters which are either `'X'` or `'O'`.

A **move** is defined as selecting **three** **consecutive characters** of `s` and converting them to `'O'`. Note that if a move is applied to the character `'O'`, it will stay the **same**.

Return *the **minimum** number of moves required so that all the characters of* `s` *are converted to* `'O'`.

**Example 1:**

```
Input: s = "XXX"
Output: 1
Explanation: XXX -> OOO
We select all the 3 characters and convert them in one move.
```

**Example 2:**

```
Input: s = "XXOX"
Output: 2
Explanation: XXOX -> OOOX -> OOOO
We select the first 3 characters in the first move, and convert them to 'O'.
Then we select the last 3 characters and convert them so that the final string contains all 'O's.
```

**Example 3:**

```
Input: s = "OOOO"
Output: 0
Explanation: There are no 'X's in s to convert.
```

**Constraints:**

* `3 <= s.length <= 1000`
* `s[i]` is either `'X'` or `'O'`.

---

## Solution & Editorial
# Intuition
Since a move covers three consecutive characters, whenever we encounter an 'X', we must perform a move to convert it to 'O'. To minimize the total moves, we should always cover the current 'X' and the next two characters, effectively skipping the next two positions regardless of their content.

# Approach
1. Initialize a pointer `i` at 0 and a `count` of moves at 0.
2. Iterate through the string `s` using `i`:
   - If `s[i]` is 'O', it is already converted, so simply increment `i` to check the next character.
   - If `s[i]` is 'X', we must perform a move. Increment `count` and advance `i` by 3, effectively "covering" the current index and the two subsequent indices.
3. Return `count` once `i` reaches the end of the string.

### Visual Trace (Example: s = "XXOX")
| Iteration | i | s[i] | Action | count | Next i |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 'X' | Move | 1 | 3 |
| 2 | 3 | 'X' | Move | 2 | 6 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We traverse the string at most once.
- Space complexity: $$O(1)$$, as we only use a few integer variables for tracking state.

# Code
```cpp
class Solution {
public:
int minimumMoves(string s) {
	int i = 0, n = s.length(), count = 0;
	while (i < n) {
		if (s[i] == 'O')  
			i++;
		else
			count++, i += 3; 
	}
	return count;
}
};
```

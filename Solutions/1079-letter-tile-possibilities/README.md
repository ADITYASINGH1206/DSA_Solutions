# [1079. Letter Tile Possibilities](https://leetcode.com/problems/letter-tile-possibilities/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `backtracking`, `counting`

---

## Problem Description
You have `n`  `tiles`, where each tile has one letter `tiles[i]` printed on it.

Return *the number of possible non-empty sequences of letters* you can make using the letters printed on those `tiles`.

**Example 1:**

```
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
```

**Example 2:**

```
Input: tiles = "AAABBC"
Output: 188
```

**Example 3:**

```
Input: tiles = "V"
Output: 1
```

**Constraints:**

* `1 <= tiles.length <= 7`
* `tiles` consists of uppercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks us to find the total number of unique non-empty sequences that can be formed using a given set of letter tiles. Since duplicate tiles exist, generating permutations naively would result in duplicate sequences. To avoid duplicate generation, we can sort the input string and enforce a skipping rule during backtracking: if a tile is identical to the previous tile and the previous tile was not used in the current branch of recursion, we skip the current tile.

# Approach
1. **Sort the Tiles:** Sort the string `tiles` lexicographically. This brings identical characters together, which is essential for duplicate pruning.
2. **Backtracking Function:** Define a recursive helper function `backtrack(string& tiles, vector<bool>& used)` that counts valid sequences.
3. **Loop through Tiles:** Iterate over each tile from index `0` to `tiles.size() - 1`.
4. **Pruning Conditions:** 
   - If `used[i]` is true, the tile is already part of the current sequence. Skip it.
   - If `tiles[i] == tiles[i - 1]` and `used[i - 1]` is false, the previous identical tile was skipped at this level of the recursion tree. To avoid duplicate permutations, skip `tiles[i]`.
5. **Recursive Step:** Mark `used[i] = true`, increment our sequence count by 1 (representing the current valid sequence formed), and recursively call `backtrack` to extend the sequence. Backtrack by resetting `used[i] = false`.

### Visual Trace Walkthrough for Example 1: `tiles = "AAB"`

| Step | Action | `used` State | Sequence Formed | Count Added | Cumulative Count |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | Pick index 0 (`'A'`) | `[T, F, F]` | "A" | +1 | 1 |
| 2 | Pick index 1 (`'A'`) | `[T, T, F]` | "AA" | +1 | 2 |
| 3 | Pick index 2 (`'B'`) | `[T, T, T]` | "AAB" | +1 | 3 |
| 4 | Backtrack, Pick index 2 (`'B'`) from root | `[F, F, T]` | "B" | +1 | 4 |
| 5 | Pick index 0 (`'A'`) | `[T, F, T]` | "BA" | +1 | 5 |
| 6 | Pick index 1 (`'A'`) | `[T, T, T]` | "BAA" | +1 | 6 |

# Complexity
- Time complexity: $$O(N 	imes N!)$$, where $$N$$ is the length of the `tiles` string. In the worst case, we explore all permutations of subsets of tiles, bounded by $$O(N!)$$.
- Space complexity: $$O(N)$$ due to the recursion stack depth and the `used` boolean array of size $$N$$.

# Code
```cpp
class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size(), false);
        return backtrack(tiles, used);
    }

    int backtrack(string& tiles, vector<bool>& used) {
        int count = 0;
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i] || (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            count += 1 + backtrack(tiles, used);
            used[i] = false;
        }
        return count;
    }
};
```

# [2976. Minimum Cost to Convert String I](https://leetcode.com/problems/minimum-cost-to-convert-string-i/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `graph`, `shortest-path`

---

## Problem Description
You are given two **0-indexed** strings `source` and `target`, both of length `n` and consisting of **lowercase** English letters. You are also given two **0-indexed** character arrays `original` and `changed`, and an integer array `cost`, where `cost[i]` represents the cost of changing the character `original[i]` to the character `changed[i]`.

You start with the string `source`. In one operation, you can pick a character `x` from the string and change it to the character `y` at a cost of `z` **if** there exists **any** index `j` such that `cost[j] == z`, `original[j] == x`, and `changed[j] == y`.

Return *the **minimum** cost to convert the string* `source` *to the string* `target` *using **any** number of operations. If it is impossible to convert* `source` *to* `target`, *return* `-1`.

**Note** that there may exist indices `i`, `j` such that `original[j] == original[i]` and `changed[j] == changed[i]`.

**Example 1:**

```
Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.
```

**Example 2:**

```
Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.
```

**Example 3:**

```
Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.
```

**Constraints:**

* `1 <= source.length == target.length <= 105`
* `source`, `target` consist of lowercase English letters.
* `1 <= cost.length == original.length == changed.length <= 2000`
* `original[i]`, `changed[i]` are lowercase English letters.
* `1 <= cost[i] <= 106`
* `original[i] != changed[i]`

---

## Solution & Editorial
# Intuition
Since we need to find the minimum cost to transform characters and there are only 26 possible lowercase English letters, this problem can be modeled as a shortest path problem on a directed graph where nodes are characters 'a'-'z'. Because the number of nodes is very small (26), the Floyd-Warshall algorithm is the optimal choice to precompute the minimum cost between all pairs of characters.

# Approach
1. **Graph Initialization**: Create a 2D adjacency matrix `g[26][26]` initialized with a large value (`inf`) representing infinity, setting `g[i][i] = 0` for all characters.
2. **Edge Weighting**: Populate the matrix with the given `original`, `changed`, and `cost` arrays. If multiple edges exist between the same two characters, store only the minimum cost using `min(g[x][y], z)`.
3. **Floyd-Warshall**: Run the triple-nested loop to compute the all-pairs shortest paths. After this, `g[i][j]` will contain the absolute minimum cost to transform character `i` to character `j`.
4. **Summation**: Iterate through the `source` and `target` strings. For each index `i`, if `source[i] != target[i]`, add the precomputed cost `g[source[i]][target[i]]` to the total. If any required transformation is impossible (`g[x][y] >= inf`), return -1.

### Visual Trace (Example 1 subset)
Given `original=['a','b'], changed=['b','c'], cost=[2,5]`:
| State | g['a']['b'] | g['b']['c'] | g['a']['c'] |
| :--- | :--- | :--- | :--- |
| Init | inf | inf | inf |
| After Edges | 2 | 5 | inf |
| After FW | 2 | 5 | 7 |

# Complexity
- **Time complexity**: $$O(N + \Sigma^3)$$, where $$N$$ is the length of the string and $$\Sigma=26$$ is the alphabet size. The graph construction takes $$O(E)$$, Floyd-Warshall takes $$O(\Sigma^3)$$, and the final string traversal takes $$O(N)$$.
- **Space complexity**: $$O(\Sigma^2)$$ to store the adjacency matrix of size 26x26.

# Code
```cpp
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int inf = 1 << 29;
        int g[26][26];
        for (int i = 0; i < 26; ++i) {
            fill(begin(g[i]), end(g[i]), inf);
            g[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            int z = cost[i];
            g[x][y] = min(g[x][y], z);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        long long ans = 0;
        int n = source.length();
        for (int i = 0; i < n; ++i) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if (x != y) {
                if (g[x][y] >= inf) {
                    return -1;
                }
                ans += g[x][y];
            }
        }
        return ans;
    }
};
```

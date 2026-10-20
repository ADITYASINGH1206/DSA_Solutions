# [2977. Minimum Cost to Convert String II](https://leetcode.com/problems/minimum-cost-to-convert-string-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `string`, `dynamic-programming`, `graph`, `trie`, `shortest-path`

---

## Problem Description
You are given two **0-indexed** strings `source` and `target`, both of length `n` and consisting of **lowercase** English characters. You are also given two **0-indexed** string arrays `original` and `changed`, and an integer array `cost`, where `cost[i]` represents the cost of converting the string `original[i]` to the string `changed[i]`.

You start with the string `source`. In one operation, you can pick a **substring** `x` from the string, and change it to `y` at a cost of `z` **if** there exists **any** index `j` such that `cost[j] == z`, `original[j] == x`, and `changed[j] == y`. You are allowed to do **any** number of operations, but any pair of operations must satisfy **either** of these two conditions:

* The substrings picked in the operations are `source[a..b]` and `source[c..d]` with either `b < c` **or** `d < a`. In other words, the indices picked in both operations are **disjoint**.
* The substrings picked in the operations are `source[a..b]` and `source[c..d]` with `a == c` **and** `b == d`. In other words, the indices picked in both operations are **identical**.

Return *the **minimum** cost to convert the string* `source` *to the string* `target` *using **any** number of operations*. *If it is impossible to convert* `source` *to* `target`, *return* `-1`.

**Note** that there may exist indices `i`, `j` such that `original[j] == original[i]` and `changed[j] == changed[i]`.

**Example 1:**

```
Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert "abcd" to "acbe", do the following operations:
- Change substring source[1..1] from "b" to "c" at a cost of 5.
- Change substring source[2..2] from "c" to "e" at a cost of 1.
- Change substring source[2..2] from "e" to "b" at a cost of 2.
- Change substring source[3..3] from "d" to "e" at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28. 
It can be shown that this is the minimum possible cost.
```

**Example 2:**

```
Input: source = "abcdefgh", target = "acdeeghh", original = ["bcd","fgh","thh"], changed = ["cde","thh","ghh"], cost = [1,3,5]
Output: 9
Explanation: To convert "abcdefgh" to "acdeeghh", do the following operations:
- Change substring source[1..3] from "bcd" to "cde" at a cost of 1.
- Change substring source[5..7] from "fgh" to "thh" at a cost of 3. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation.
- Change substring source[5..7] from "thh" to "ghh" at a cost of 5. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation, and identical with indices picked in the second operation.
The total cost incurred is 1 + 3 + 5 = 9.
It can be shown that this is the minimum possible cost.
```

**Example 3:**

```
Input: source = "abcdefgh", target = "addddddd", original = ["bcd","defgh"], changed = ["ddd","ddddd"], cost = [100,1578]
Output: -1
Explanation: It is impossible to convert "abcdefgh" to "addddddd".
If you select substring source[1..3] as the first operation to change "abcdefgh" to "adddefgh", you cannot select substring source[3..7] as the second operation because it has a common index, 3, with the first operation.
If you select substring source[3..7] as the first operation to change "abcdefgh" to "abcddddd", you cannot select substring source[1..3] as the second operation because it has a common index, 3, with the first operation.
```

**Constraints:**

* `1 <= source.length == target.length <= 1000`
* `source`, `target` consist only of lowercase English characters.
* `1 <= cost.length == original.length == changed.length <= 100`
* `1 <= original[i].length == changed[i].length <= source.length`
* `original[i]`, `changed[i]` consist only of lowercase English characters.
* `original[i] != changed[i]`
* `1 <= cost[i] <= 106`

---

## Solution & Editorial
# Intuition
To solve this problem, we must find the minimum cost to transform substrings of `source` into corresponding substrings of `target`. Since we can perform multiple transformations, this is essentially a shortest-path problem on a graph where nodes are unique strings from `original` and `changed`. We use the Floyd-Warshall algorithm to precompute all-pairs shortest paths between these strings, then apply dynamic programming to determine the optimal sequence of transformations across the entire string.

# Approach
1. **Graph Construction**: Map every unique string in `original` and `changed` to a unique integer ID using a Trie. Initialize an adjacency matrix `g` where `g[u][v]` stores the minimum cost to transform string `u` to string `v`.
2. **All-Pairs Shortest Path**: Run the Floyd-Warshall algorithm on the graph to compute the minimum cost to transform any string `u` to any string `v` through intermediate transformations.
3. **Dynamic Programming**: Define `dfs(i)` as the minimum cost to convert `source[i..n-1]` to `target[i..n-1]`. 
   - If `source[i] == target[i]`, we can skip the character: `res = dfs(i + 1)`.
   - For every possible substring starting at `i`, check if the substring `source[i..j]` can be transformed into `target[i..j]` using the precomputed costs in `g`. If possible, `res = min(res, cost(source[i..j] -> target[i..j]) + dfs(j + 1))`.

### Visual Trace (Example 1)
`source` = "abcd", `target` = "acbe"
- `dfs(0)`: `s[0]=='a'`, `t[0]=='a'`. Try skipping: `dfs(1)`.
- `dfs(1)`: `s[1]=='b'`, `t[1]=='c'`. Try transformation "b" -> "c" (cost 5) + `dfs(2)`.
- `dfs(2)`: `s[2]=='c'`, `t[2]=='b'`. Try transformation "c" -> "e" (cost 1) + "e" -> "b" (cost 2) + `dfs(3)`.
- `dfs(3)`: `s[3]=='d'`, `t[3]=='e'`. Try transformation "d" -> "e" (cost 20) + `dfs(4)`.
- `dfs(4)`: Returns 0. Total = 5 + 1 + 2 + 20 = 28.

# Complexity
- Time complexity: $$O(N \cdot L + M^3)$$, where $$N$$ is the length of the string, $$L$$ is the max length of a transformation string, and $$M$$ is the number of unique strings. Floyd-Warshall takes $$O(M^3)$$, and the DP takes $$O(N \cdot L)$$.
- Space complexity: $$O(M^2 + N)$$, where $$M^2$$ is the adjacency matrix and $$N$$ is the DP memoization array.

# Code
```cpp
class Node {
public:
    Node* children[26];
    int v = -1;
    Node() {
        fill(children, children + 26, nullptr);
    }
};

class Solution {
private:
    const long long inf = 1LL << 60;
    Node* root = new Node();
    int idx;

    vector<vector<long long>> g;
    string s;
    string t;
    vector<long long> f;

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int m = cost.size();
        g = vector<vector<long long>>(m << 1, vector<long long>(m << 1, inf));
        s = source;
        t = target;

        for (int i = 0; i < g.size(); ++i) {
            g[i][i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            int x = insert(original[i]);
            int y = insert(changed[i]);
            g[x][y] = min(g[x][y], static_cast<long long>(cost[i]));
        }

        for (int k = 0; k < idx; ++k) {
            for (int i = 0; i < idx; ++i) {
                if (g[i][k] >= inf) {
                    continue;
                }
                for (int j = 0; j < idx; ++j) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        f = vector<long long>(s.length(), -1);
        long long ans = dfs(0);
        return ans >= inf ? -1 : ans;
    }

private:
    int insert(const string& w) {
        Node* node = root;
        for (char c : w) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }
            node = node->children[i];
        }
        if (node->v < 0) {
            node->v = idx++;
        }
        return node->v;
    }

    long long dfs(int i) {
        if (i >= s.length()) {
            return 0;
        }
        if (f[i] != -1) {
            return f[i];
        }
        long long res = (s[i] == t[i]) ? dfs(i + 1) : inf;
        Node* p = root;
        Node* q = root;
        for (int j = i; j < s.length(); ++j) {
            p = p->children[s[j] - 'a'];
            q = q->children[t[j] - 'a'];
            if (p == nullptr || q == nullptr) {
                break;
            }
            if (p->v < 0 || q->v < 0) {
                continue;
            }
            long long temp = g[p->v][q->v];
            if (temp < inf) {
                res = min(res, temp + dfs(j + 1));
            }
        }
        return f[i] = res;
    }
};
```

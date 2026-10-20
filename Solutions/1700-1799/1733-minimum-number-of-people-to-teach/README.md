# [1733. Minimum Number of People to Teach](https://leetcode.com/problems/minimum-number-of-people-to-teach/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `greedy`

---

## Problem Description
On a social network consisting of `m` users and some friendships between users, two users can communicate with each other if they know a common language.

You are given an integer `n`, an array `languages`, and an array `friendships` where:

* There are `n` languages numbered `1` through `n`,
* `languages[i]` is the set of languages the `i​​​​​​th`​​​​ user knows, and
* `friendships[i] = [u​​​​​​i​​​, v​​​​​​i]` denotes a friendship between the users `u​​​​​​​​​​​i`​​​​​ and `vi`.

You can choose **one** language and teach it to some users so that all friends can communicate with each other. Return *the* ***minimum*** *number of users you need to teach.*

Note that friendships are not transitive, meaning if `x` is a friend of `y` and `y` is a friend of `z`, this doesn't guarantee that `x` is a friend of `z`.

**Example 1:**

```
Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
Output: 1
Explanation: You can either teach user 1 the second language or user 2 the first language.
```

**Example 2:**

```
Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
Output: 2
Explanation: Teach the third language to users 1 and 3, yielding two users to teach.
```

**Constraints:**

* `2 <= n <= 500`
* `languages.length == m`
* `1 <= m <= 500`
* `1 <= languages[i].length <= n`
* `1 <= languages[i][j] <= n`
* `1 <= u​​​​​​i < v​​​​​​i <= languages.length`
* `1 <= friendships.length <= 500`
* All tuples `(u​​​​​i, v​​​​​​i)` are unique
* `languages[i]` contains only unique values

---

## Solution & Editorial
# Intuition
The problem asks for the minimum number of users to teach a single language such that all friendships are "connected" (i.e., each pair of friends shares at least one language). Since we only need to teach one language, we can identify all pairs of friends who currently cannot communicate and collect the set of unique users involved in these broken friendships. We then iterate through every possible language (1 to n) and calculate how many of these users would need to be taught that specific language.

# Approach
1. **Identify Broken Friendships**: Iterate through the `friendships` array. For each pair `(u, v)`, check if they share any common language. If they do not, add both `u` and `v` to a set `need` to track unique users who must be taught a new language.
2. **Evaluate Languages**: For each language `i` from 1 to `n`:
   - Count how many users in the `need` set do not already know language `i`.
   - This count represents the number of people we would need to teach language `i` to satisfy all currently broken friendships.
3. **Minimize**: Track the minimum count across all possible languages.

### Visual Trace (Example 1)
`n=2`, `languages=[[1],[2],[1,2]]`, `friendships=[[1,2],[1,3],[2,3]]`
- Pair (1,2): Knows {1} and {2}. No common. `need = {0, 1}` (0-indexed).
- Pair (1,3): Knows {1} and {1,2}. Common {1}. OK.
- Pair (2,3): Knows {2} and {1,2}. Common {2}. OK.
- `need` set is {0, 1}.
- Language 1: User 0 knows it, User 1 doesn't. Teach 1 person.
- Language 2: User 0 doesn't, User 1 knows it. Teach 1 person.
- Result: 1.

# Complexity
- Time complexity: $$O(F \cdot L^2 + N \cdot M \cdot L)$$, where $$F$$ is the number of friendships, $$L$$ is the average number of languages per user, $$N$$ is the number of languages, and $$M$$ is the number of users. Given constraints ($$N, M, F \le 500$$), this is well within limits.
- Space complexity: $$O(M + L)$$, primarily for the `need` set storing unique users and the language lookups.

# Code
```cpp
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> need;
        for(const auto& p : friendships) {
            auto u = p[0] - 1, v = p[1] - 1;
            bool ok = false;
            for(const auto x : languages[u]) {
                for(const auto y : languages[v]) {
                    if (x == y) { ok = true; break; }
                }
            }
            if (!ok) { need.insert(u); need.insert(v); }
        }
        
        int ans = languages.size() + 1;
        for(int i = 1; i <= n; ++i) {
            int cans = 0;
            for(auto v : need) {
                bool found = false;
                for(auto c : languages[v]) {
                    if (c == i) { found = true; break; }
                }
                if (!found) ++cans;
            }
            ans = min(ans, cans);
        }
        return ans;
    }
};
```

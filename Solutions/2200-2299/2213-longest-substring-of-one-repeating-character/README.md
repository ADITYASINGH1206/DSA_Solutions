# [2213. Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character/)
**Difficulty:** `Hard` | **Tags:** `array`, `string`, `segment-tree`, `ordered-set`

---

## Problem Description
You are given a **0-indexed** string `s`. You are also given a **0-indexed** string `queryCharacters` of length `k` and a **0-indexed** array of integer **indices** `queryIndices` of length `k`, both of which are used to describe `k` queries.

The `ith` query updates the character in `s` at index `queryIndices[i]` to the character `queryCharacters[i]`.

Return *an array* `lengths` *of length* `k` *where* `lengths[i]` *is the **length** of the **longest substring** of* `s` *consisting of **only one repeating** character **after** the* `ith` *query* *is performed.*

**Example 1:**

```
Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation: 
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc". 
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].
```

**Example 2:**

```
Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
Output: [2,3]
Explanation:
- 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
- 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
Thus, we return [2,3].
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of lowercase English letters.
* `k == queryCharacters.length == queryIndices.length`
* `1 <= k <= 105`
* `queryCharacters` consists of lowercase English letters.
* `0 <= queryIndices[i] < s.length`

---

## Solution & Editorial
# Intuition
To efficiently track the longest substring of repeating characters under point updates, we need a data structure that supports logarithmic updates and range queries. A Segment Tree is ideal here, as each node can store metadata about its range, allowing us to merge results from children in constant time.

# Approach
1. **Node Structure**: Each node in the segment tree stores:
   - `leftChar`, `rightChar`: Boundary characters of the range.
   - `length`: Total length of the range.
   - `prefix`, `suffix`: Length of the repeating character sequence starting at the left or ending at the right.
   - `best`: The maximum repeating substring length within this range.
2. **Merge Logic**: When merging two nodes (left and right):
   - The new `prefix` is `left.prefix` unless the entire left child consists of one character and `left.rightChar == right.leftChar`, in which case we add `right.prefix`.
   - The new `suffix` is `right.suffix` unless the entire right child consists of one character and `right.leftChar == left.rightChar`, in which case we add `left.suffix`.
   - The new `best` is `max(left.best, right.best)`. If the boundary characters match, we also consider `left.suffix + right.prefix`.
3. **Updates**: For each query, we perform a standard point update in $O(\log N)$ time and retrieve `tree[1].best`.

### Visual Trace (Example 1: s="babacc")
Initial state (simplified):
- Node [0,1] ("ba"): {L:'b', R:'a', len:2, pre:1, suf:1, best:1}
- Node [2,3] ("ba"): {L:'b', R:'a', len:2, pre:1, suf:1, best:1}
- Merge [0,1] and [2,3]: Boundary 'a'=='b' is false. `best` = max(1, 1) = 1.

# Complexity
- Time complexity: $$O(N + K \log N)$$, where $$N$$ is the length of string $$s$$ and $$K$$ is the number of queries. Building the tree takes $$O(N)$$, and each of the $$K$$ updates takes $$O(\log N)$$.
- Space complexity: $$O(N)$$, required to store the segment tree nodes (typically $$4N$$ nodes).

# Code
```cpp
class Solution {
private:
    struct Node {char leftChar; char rightChar; int length; int prefix; int suffix; int best;
};

    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;

        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;
        res.length = left.length + right.length;

        res.prefix = left.prefix;

        if (
            left.rightChar == right.leftChar &&
            left.prefix == left.length
        ) {
            res.prefix = left.length + right.prefix;
        }

        res.suffix = right.suffix;

        if (
            left.rightChar == right.leftChar &&
            right.suffix == right.length
        ) {
            res.suffix = right.length + left.suffix;
        }

        res.best = max(left.best, right.best);

        if (left.rightChar == right.leftChar) {
            res.best = max(
                res.best,
                left.suffix + right.prefix
            );
        }

        return res;
    }

    void build( int node, int start, int end, const string& s
    ) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1, 1};
            return;
        }

        int mid = (start + end) / 2;

        build(node * 2, start, mid, s);
        build(node * 2 + 1, mid + 1, end, s);

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update( int node, int start, int end, int index, char ch ) {
        if (start == end) {
            tree[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = (start + end) / 2;

        if (index <= mid) {
            update(node * 2, start, mid, index, ch);
        } else {
            update(node * 2 + 1, mid + 1, end, index, ch);
        }

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

public:
    vector<int> longestRepeating( string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
        vector<int> answer;

        for (int i = 0; i < queryIndices.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            answer.push_back(tree[1].best);
        }

        return answer;
    }
};
```

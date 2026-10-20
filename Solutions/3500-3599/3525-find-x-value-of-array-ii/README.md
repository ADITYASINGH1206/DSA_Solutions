# [3525. Find X Value of Array II](https://leetcode.com/problems/find-x-value-of-array-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `segment-tree`

---

## Problem Description
You are given an array of **positive** integers `nums` and a **positive** integer `k`. You are also given a 2D array `queries`, where `queries[i] = [indexi, valuei, starti, xi]`.

You are allowed to perform an operation **once** on `nums`, where you can remove any **suffix** from `nums` such that `nums` remains **non-empty**.

The **x-value** of `nums` **for a given** `x` is defined as the number of ways to perform this operation so that the **product** of the remaining elements leaves a *remainder* of `x` **modulo** `k`.

For each query in `queries` you need to determine the **x-value** of `nums` for `xi` after performing the following actions:

* Update `nums[indexi]` to `valuei`. Only this step persists for the rest of the queries.
* **Remove** the prefix `nums[0..(starti - 1)]` (where `nums[0..(-1)]` will be used to represent the **empty** prefix).

Return an array `result` of size `queries.length` where `result[i]` is the answer for the `ith` query.

A **prefix** of an array is a subarray that starts from the beginning of the array and extends to any point within it.

A **suffix** of an array is a subarray that starts at any point within the array and extends to the end of the array.

**Note** that the prefix and suffix to be chosen for the operation can be **empty**.

**Note** that x-value has a *different* definition in this version.

**Example 1:**

**Input:** nums = [1,2,3,4,5], k = 3, queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]

**Output:** [2,2,2]

**Explanation:**

* For query 0, `nums` becomes `[1, 2, 2, 4, 5]`, and the empty prefix **must** be removed. The possible operations are:
  + Remove the suffix `[2, 4, 5]`. `nums` becomes `[1, 2]`.
  + Remove the empty suffix. `nums` becomes `[1, 2, 2, 4, 5]` with a product 80, which gives remainder 2 when divided by 3.
* For query 1, `nums` becomes `[1, 2, 2, 3, 5]`, and the prefix `[1, 2, 2]` **must** be removed. The possible operations are:
  + Remove the empty suffix. `nums` becomes `[3, 5]`.
  + Remove the suffix `[5]`. `nums` becomes `[3]`.
* For query 2, `nums` becomes `[1, 2, 2, 3, 5]`, and the empty prefix **must** be removed. The possible operations are:
  + Remove the suffix `[2, 2, 3, 5]`. `nums` becomes `[1]`.
  + Remove the suffix `[3, 5]`. `nums` becomes `[1, 2, 2]`.

**Example 2:**

**Input:** nums = [1,2,4,8,16,32], k = 4, queries = [[0,2,0,2],[0,2,0,1]]

**Output:** [1,0]

**Explanation:**

* For query 0, `nums` becomes `[2, 2, 4, 8, 16, 32]`. The only possible operation is:
  + Remove the suffix `[2, 4, 8, 16, 32]`.
* For query 1, `nums` becomes `[2, 2, 4, 8, 16, 32]`. There is no possible way to perform the operation.

**Example 3:**

**Input:** nums = [1,1,2,1,1], k = 2, queries = [[2,1,0,1]]

**Output:** [5]

**Constraints:**

* `1 <= nums[i] <= 109`
* `1 <= nums.length <= 105`
* `1 <= k <= 5`
* `1 <= queries.length <= 2 * 104`
* `queries[i] == [indexi, valuei, starti, xi]`
* `0 <= indexi <= nums.length - 1`
* `1 <= valuei <= 109`
* `0 <= starti <= nums.length - 1`
* `0 <= xi <= k - 1`

---

## Solution & Editorial
# Intuition
The problem asks us to calculate the number of ways to remove a suffix such that the product of the remaining prefix (starting from `start_i`) modulo `k` equals `x_i`. Since `k` is very small (up to 5), we can maintain the product of segments and the frequency of all possible remainders modulo `k` within those segments using a Segment Tree.

# Approach
1. **Segment Tree Node**: Each node stores the `prod` (product of the range modulo `k`) and an array `freq` of size `k`, where `freq[r]` is the number of prefixes of this range whose product modulo `k` is `r`.
2. **Merge Logic**: To merge two nodes `L` and `R`:
   - The new `prod` is `(L.prod * R.prod) % k`.
   - The new `freq` is the sum of `L.freq` and the shifted frequencies of `R`. Specifically, for each remainder `r` in `R.freq`, the new remainder becomes `(L.prod * r) % k`.
3. **Query Handling**: For each query, update the value at `index_i` in the segment tree, then query the range `[start_i, n-1]`. The answer is `res.freq[x_i]`.

### Visual Trace (Example 1, Query 0)
`nums = [1, 2, 2, 4, 5], k = 3`. Query: `idx=2, val=2, start=0, x=2`.
- After update: `[1, 2, 2, 4, 5]`.
- Range `[0, 4]` products: `1, 2, 4(1), 16(1), 80(2)`.
- Remainders: `1, 2, 1, 1, 2`.
- Frequencies: `{0:0, 1:3, 2:2}`. `freq[2]` is 2.

# Complexity
- Time complexity: $$O(Q \cdot K \cdot \log N)$$, where $$Q$$ is the number of queries, $$N$$ is the array size, and $$K$$ is the modulus. The merge operation takes $$O(K)$$, and each query/update takes $$O(\log N)$$.
- Space complexity: $$O(N \cdot K)$$ to store the segment tree nodes, where each node holds an array of size $$K$$.

# Code
```cpp
class Solution {
public:
    struct Node {
        int prod;
        array<int, 5> freq;
        Node() : prod(1) { freq.fill(0); }
    };
    
    int k;
    vector<Node> tree;
    vector<int> nums;
    
    Node merge(const Node& L, const Node& R) {
        Node res;
        res.prod = (1LL * L.prod * R.prod) % k;
        res.freq = L.freq;
        for (int r = 0; r < k; ++r) {
            if (R.freq[r]) {
                int nr = (1LL * L.prod * r) % k;
                res.freq[nr] += R.freq[r];
            }
        }
        return res;
    }
    
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v].prod = nums[tl] % k;
            tree[v].freq[tree[v].prod] = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
    
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v].prod = val % k;
            tree[v].freq.fill(0);
            tree[v].freq[tree[v].prod] = 1;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(v * 2, tl, tm, pos, val);
        else update(v * 2 + 1, tm + 1, tr, pos, val);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
    
    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return Node();
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return merge(query(v * 2, tl, tm, l, min(r, tm)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        this->nums = nums;
        int n = nums.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1);
        vector<int> ans;
        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, idx, val);
            Node res = query(1, 0, n - 1, start, n - 1);
            ans.push_back(res.freq[x]);
        }
        return ans;
    }
};
```

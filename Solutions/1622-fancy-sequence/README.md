# [1622. Fancy Sequence](https://leetcode.com/problems/fancy-sequence/)
**Difficulty:** `Hard` | **Tags:** `math`, `design`, `segment-tree`, `number-theory`, `fermats-little-theorem`

---

## Problem Description
Write an API that generates fancy sequences using the `append`, `addAll`, and `multAll` operations.

Implement the `Fancy` class:

* `Fancy()` Initializes the object with an empty sequence.
* `void append(val)` Appends an integer `val` to the end of the sequence.
* `void addAll(inc)` Increments all existing values in the sequence by an integer `inc`.
* `void multAll(m)` Multiplies all existing values in the sequence by an integer `m`.
* `int getIndex(idx)` Gets the current value at index `idx` (0-indexed) of the sequence **modulo** `109 + 7`. If the index is greater or equal than the length of the sequence, return `-1`.

**Example 1:**

```
Input
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
Output
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

Explanation
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
```

**Constraints:**

* `1 <= val, inc, m <= 100`
* `0 <= idx <= 105`
* At most `105` calls total will be made to `append`, `addAll`, `multAll`, and `getIndex`.

---

## Solution & Editorial
# Intuition
To handle range updates (add/multiply) and point queries efficiently, we can model the sequence as a dynamic array managed by a Segment Tree. Since we need to perform global operations (applying to all elements currently in the sequence), a Segment Tree with lazy propagation allows us to maintain the state of the sequence under linear transformations $f(x) = ax + b$ in logarithmic time.

# Approach
1. **Data Structure**: We use a dynamic Segment Tree where each node stores the current sum of its range (`v`), a lazy multiplier (`mul`), and a lazy adder (`add`).
2. **Operations**:
   - `append(val)`: We treat this as a point update at index `n+1`, setting the value to `val`.
   - `addAll(inc)`: We apply the transformation $v = v + inc$ to the range $[1, n]$.
   - `multAll(m)`: We apply the transformation $v = v \times m$ to the range $[1, n]$.
   - `getIndex(idx)`: We perform a point query at `idx + 1`.
3. **Lazy Propagation**: When applying a transformation $f(x) = m \cdot x + a$ to a node, we update its `mul` and `add` tags. Specifically, if a node already has tags $(m_1, a_1)$ and we apply $(m_2, a_2)$, the new tags become $(m_1 \cdot m_2, a_1 \cdot m_2 + a_2)$.

### Visual Trace (Example 1)
| Operation | Sequence | State (m, a) |
| :--- | :--- | :--- |
| append(2) | [2] | (1, 0) |
| addAll(3) | [5] | (1, 3) |
| append(7) | [5, 7] | (1, 3) |
| multAll(2) | [10, 14] | (2, 6) |

# Complexity
- Time complexity: $$O(\log N)$$ per operation, where $N$ is the maximum number of elements ($10^5$). Each update or query traverses the height of the tree.
- Space complexity: $$O(N)$$ to store the nodes of the Segment Tree.

# Code
```cpp
const int MOD = 1e9 + 7;

class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    long long v;
    long long add;
    long long mul;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
        mul = 1;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 1e5 + 1);
    }

    void modifyAdd(int l, int r, int inc) {
        modifyAdd(l, r, inc, root);
    }

    void modifyAdd(int l, int r, int inc, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = (node->v + (node->r - node->l + 1) * inc) % MOD;
            node->add = (node->add + inc) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modifyAdd(l, r, inc, node->left);
        if (r > node->mid) modifyAdd(l, r, inc, node->right);
        pushup(node);
    }

    void modifyMul(int l, int r, int m) {
        modifyMul(l, r, m, root);
    }

    void modifyMul(int l, int r, int m, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = (node->v * m) % MOD;
            node->add = (node->add * m) % MOD;
            node->mul = (node->mul * m) % MOD;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modifyMul(l, r, m, node->left);
        if (r > node->mid) modifyMul(l, r, m, node->right);
        pushup(node);
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node* node) {
        if (l > r) return 0;
        if (node->l >= l && node->r <= r) return node->v;
        pushdown(node);
        int v = 0;
        if (l <= node->mid) v = (v + query(l, r, node->left)) % MOD;
        if (r > node->mid) v = (v + query(l, r, node->right)) % MOD;
        return v;
    }

    void pushup(Node* node) {
        node->v = (node->left->v + node->right->v) % MOD;
    }

    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add || node->mul != 1) {
            long add = node->add, mul = node->mul;
            Node* left = node->left;
            Node* right = node->right;
            left->v = (left->v * mul + (left->r - left->l + 1) * add) % MOD;
            right->v = (right->v * mul + (right->r - right->l + 1) * add) % MOD;
            left->add = (left->add * mul + add) % MOD;
            right->add = (right->add * mul + add) % MOD;
            left->mul = (left->mul * mul) % MOD;
            right->mul = (right->mul * mul) % MOD;
            node->add = 0;
            node->mul = 1;
        }
    }
};

class Fancy {
public:
    int n;
    SegmentTree* tree;

    Fancy() {
        n = 0;
        tree = new SegmentTree();
    }

    void append(int val) {
        ++n;
        tree->modifyAdd(n, n, val);
    }

    void addAll(int inc) {
        tree->modifyAdd(1, n, inc);
    }

    void multAll(int m) {
        tree->modifyMul(1, n, m);
    }

    int getIndex(int idx) {
        return idx >= n ? -1 : tree->query(idx + 1, idx + 1);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
```

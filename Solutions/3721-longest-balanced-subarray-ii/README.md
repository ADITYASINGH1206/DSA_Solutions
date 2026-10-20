# [3721. Longest Balanced Subarray II](https://leetcode.com/problems/longest-balanced-subarray-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `hash-table`, `divide-and-conquer`, `segment-tree`, `prefix-sum`

---

## Problem Description
You are given an integer array `nums`.

A **subarray** is called **balanced** if the number of **distinct even** numbers in the subarray is equal to the number of **distinct odd** numbers.

Return the length of the **longest** balanced subarray.

**Example 1:**

**Input:** nums = [2,5,4,3]

**Output:** 4

**Explanation:**

* The longest balanced subarray is `[2, 5, 4, 3]`.
* It has 2 distinct even numbers `[2, 4]` and 2 distinct odd numbers `[5, 3]`. Thus, the answer is 4.

**Example 2:**

**Input:** nums = [3,2,2,5,4]

**Output:** 5

**Explanation:**

* The longest balanced subarray is `[3, 2, 2, 5, 4]`.
* It has 2 distinct even numbers `[2, 4]` and 2 distinct odd numbers `[3, 5]`. Thus, the answer is 5.

**Example 3:**

**Input:** nums = [1,2,3,2]

**Output:** 3

**Explanation:**

* The longest balanced subarray is `[2, 3, 2]`.
* It has 1 distinct even number `[2]` and 1 distinct odd number `[3]`. Thus, the answer is 3.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`

---

## Solution & Editorial
# Intuition
To determine if a subarray is balanced, we need the count of distinct even numbers to equal the count of distinct odd numbers. By assigning +1 to even numbers and -1 to odd numbers, a subarray is balanced if the net sum of these values is 0. Since we only care about *distinct* numbers, we track the last seen position of each number to ensure that when a number repeats, we only increment/decrement the balance for the current occurrence and neutralize the effect of the previous one.

# Approach
1. We maintain a segment tree where each leaf `i` stores the current balance of the subarray `nums[i...j]` ending at index `j`.
2. As we iterate `j` from `0` to `n-1`, we update the range `[last_pos[nums[j]] + 1, j]` by adding `+1` if `nums[j]` is even, or `-1` if it is odd.
3. The segment tree supports range updates (lazy propagation) and range queries to find the smallest index `i` such that the balance at `i` is `0`.
4. If such an `i` exists, the subarray `nums[i...j]` is balanced, and we update `max_len = max(max_len, j - i + 1)`.

### Visual Trace (Example: [2, 5, 4])
| j | nums[j] | Range Update | Balance Array (indices 0..2) | First 0 Index | Max Len |
|---|---|---|---|---|---|
| 0 | 2 | [0, 0] +1 | [1, 0, 0] | -1 | 0 |
| 1 | 5 | [0, 1] -1 | [0, -1, 0] | 0 | 1 |
| 2 | 4 | [1, 2] +1 | [0, 0, 0] | 0 | 3 |

# Complexity
- Time complexity: $$O(N \log N)$$. We iterate through the array once ($N$ steps). In each step, we perform a segment tree update and a search, both taking $$O(\log N)$$ time.
- Space complexity: $$O(N)$$. The segment tree requires $$O(N)$$ space, and the `last_pos` map stores at most $N$ distinct elements.

# Code
```cpp
class Solution {
    struct Node {
        int min_val;
        int max_val;
        int lazy;
    };

    vector<Node> tree;
    int n;


    void push(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            if (start != end) {
                tree[2 * node].min_val += tree[node].lazy;
                tree[2 * node].max_val += tree[node].lazy;
                tree[2 * node].lazy += tree[node].lazy;

                tree[2 * node + 1].min_val += tree[node].lazy;
                tree[2 * node + 1].max_val += tree[node].lazy;
                tree[2 * node + 1].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, int val) {
        if (start > end || start > r || end < l) return;

        if (start >= l && end <= r) {
            tree[node].min_val += val;
            tree[node].max_val += val;
            tree[node].lazy += val;
            return;
        }

        push(node, start, end);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
        tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
    }

    int findFirstZero(int node, int start, int end, int limit) {
        if (start > limit) return -1;
        
        push(node, start, end);


        if (tree[node].min_val > 0 || tree[node].max_val < 0) return -1;


        if (start == end) {
            return (tree[node].min_val == 0) ? start : -1;
        }

        int mid = (start + end) / 2;
        
        int res = findFirstZero(2 * node, start, mid, limit);
        if (res != -1) return res;

        return findFirstZero(2 * node + 1, mid + 1, end, limit);
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, {0, 0, 0});
        map<int, int> last_pos;
        int max_len = 0;
        for (int j = 0; j < n; ++j) {
            int val = nums[j];
            int prev = -1;
            
            if (last_pos.count(val)) {
                prev = last_pos[val];
            }

            int change = (val % 2 == 0) ? 1 : -1;
            update(1, 0, n - 1, prev + 1, j, change);

            int i = findFirstZero(1, 0, n - 1, j);

            if (i != -1) {
                max_len = max(max_len, j - i + 1);
            }

            last_pos[val] = j;
        }

        return max_len;
    }
};
```

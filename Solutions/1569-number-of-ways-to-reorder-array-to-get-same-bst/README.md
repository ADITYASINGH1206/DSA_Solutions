# [1569. Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)
**Difficulty:** `Hard` | **Tags:** `array`, `math`, `divide-and-conquer`, `dynamic-programming`, `tree`, `union-find`, `binary-search-tree`, `memoization`, `combinatorics`, `binary-tree`, `fermats-little-theorem`

---

## Problem Description
Given an array `nums` that represents a permutation of integers from `1` to `n`. We are going to construct a binary search tree (BST) by inserting the elements of `nums` in order into an initially empty BST. Find the number of different ways to reorder `nums` so that the constructed BST is identical to that formed from the original array `nums`.

* For example, given `nums = [2,1,3]`, we will have 2 as the root, 1 as a left child, and 3 as a right child. The array `[2,3,1]` also yields the same BST but `[3,2,1]` yields a different BST.

Return *the number of ways to reorder* `nums` *such that the BST formed is identical to the original BST formed from* `nums`.

Since the answer may be very large, **return it modulo** `109 + 7`.

**Example 1:**

```
Input: nums = [2,1,3]
Output: 1
Explanation: We can reorder nums to be [2,3,1] which will yield the same BST. There are no other ways to reorder nums which will yield the same BST.
```

**Example 2:**

```
Input: nums = [3,4,5,1,2]
Output: 5
Explanation: The following 5 arrays will yield the same BST: 
[3,1,2,4,5]
[3,1,4,2,5]
[3,1,4,5,2]
[3,4,1,2,5]
[3,4,1,5,2]
```

**Example 3:**

```
Input: nums = [1,2,3]
Output: 0
Explanation: There are no other orderings of nums that will yield the same BST.
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `1 <= nums[i] <= nums.length`
* All integers in `nums` are **distinct**.

---

## Solution & Editorial
# Intuition
To construct the same Binary Search Tree (BST), the root must remain the same. Once the root is fixed, the remaining elements are partitioned into a left subtree (all elements smaller than the root) and a right subtree (all elements larger than the root). The relative order of elements within the left subtree must be preserved, and similarly for the right subtree. However, we can interleave the sequences of the left and right subtrees in any way that maintains their internal relative order.

# Approach
1. **Precompute Combinations**: Use Pascal's Triangle to precompute binomial coefficients `C(n, k)` modulo 10^9 + 7. This allows O(1) retrieval of the number of ways to interleave two sequences of lengths `L` and `R`, which is `C(L+R, L)`.
2. **Divide and Conquer**: Define a recursive function `dfs(nums)`:
   - Base case: If the size of `nums` is <= 2, there is only 1 way to arrange them.
   - Recursive step: Identify the root (first element). Partition the remaining elements into `left` and `right` vectors.
   - Calculate `left_ways = dfs(left)` and `right_ways = dfs(right)`.
   - The total ways for the current subtree is `C(left.size() + right.size(), left.size()) * left_ways * right_ways`.
3. **Final Result**: The problem asks for the number of *reorderings* excluding the original array, so subtract 1 from the final result.

### Visual Trace (Example: [2, 1, 3])
- `dfs([2, 1, 3])`:
  - Root = 2. Left = [1], Right = [3].
  - `dfs([1])` = 1, `dfs([3])` = 1.
  - Interleaving: `C(1+1, 1) = 2`.
  - Result: `2 * 1 * 1 = 2`.
- Final: `2 - 1 = 1`.

# Complexity
- Time complexity: $$O(N^2)$$ where $$N$$ is the number of elements. Precomputing the combination table takes $$O(N^2)$$. The recursion visits each node, and partitioning takes $$O(N)$$ per level, resulting in $$O(N^2)$$ total.
- Space complexity: $$O(N^2)$$ to store the combination table and the recursion stack depth of $$O(N)$$ in the worst case (skewed tree).

# Code
```cpp
class Solution {
private:
    long long mod = 1e9 + 7;
    vector<vector<long long>> table;
    void precomputeCombinations(int n) {
        table.assign(n + 1, vector<long long>(n + 1, 1));
        for (int i = 1; i <= n; ++i) {
            table[i][0] = 1;
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
    }

    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        int l_size = left.size();
        int r_size = right.size();

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);
        long long interleaving_ways = table[l_size + r_size][l_size];

        return (((interleaving_ways * left_ways) % mod) * right_ways) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precomputeCombinations(n);
        return (dfs(nums) - 1 + mod) % mod;
    }
};
```

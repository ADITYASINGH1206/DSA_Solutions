# [3857. Minimum Cost to Split into Ones](https://leetcode.com/problems/minimum-cost-to-split-into-ones/)
**Difficulty:** `Medium` | **Tags:** `math`, `dynamic-programming`

---

## Problem Description
You are given an integer `n`.

In one operation, you may split an integer `x` into two positive integers `a` and `b` such that `a + b = x`.

The cost of this operation is `a * b`.

Return an integer denoting the **minimum** total cost required to split the integer `n` into `n` ones.

**Example 1:**

**Input:** n = 3

**Output:** 3

**Explanation:**

One optimal set of operations is:

| `x` | `a` | `b` | `a + b` | `a * b` | Cost |
| --- | --- | --- | --- | --- | --- |
| 3 | 1 | 2 | 3 | 2 | 2 |
| 2 | 1 | 1 | 2 | 1 | 1 |

Thus, the minimum total cost is `2 + 1 = 3`.

**Example 2:**

**Input:** n = 4

**Output:** 6

**Explanation:**

One optimal set of operations is:

| `x` | `a` | `b` | `a + b` | `a * b` | Cost |
| --- | --- | --- | --- | --- | --- |
| 4 | 2 | 2 | 4 | 4 | 4 |
| 2 | 1 | 1 | 2 | 1 | 1 |
| 2 | 1 | 1 | 2 | 1 | 1 |

Thus, the minimum total cost is `4 + 1 + 1 = 6`.

**Constraints:**

* `1 <= n <= 500`

---

## Solution & Editorial
# Intuition
To split an integer $n$ into $n$ ones, we perform a sequence of operations. Each operation splits an integer $x$ into $a$ and $b$ ($a+b=x$) with a cost of $a \times b$. We want to minimize the total cost. Notice that the total cost is actually invariant regardless of the order of splits. 

# Approach
1. Consider the process as building the number $n$ from $n$ ones. Every time we merge two groups of size $a$ and $b$, the cost incurred is $a \times b$. 
2. The total sum of all elements is always $n$. If we have $n$ ones, the sum of products of all pairs is equivalent to the sum of $i \times j$ for all $1 \le i < j \le n$. 
3. Mathematically, the sum of all pairs $(i, j)$ where $1 \le i < j \le n$ is given by the formula $\frac{n(n-1)}{2}$.
4. This can be verified: for $n=3$, $\frac{3 \times 2}{2} = 3$. For $n=4$, $\frac{4 \times 3}{2} = 6$. The formula holds for all $n$.

# Complexity
- Time complexity: $$O(1)$$ — The result is computed using a constant-time arithmetic formula.
- Space complexity: $$O(1)$$ — No auxiliary space is required.

# Code
```cpp
class Solution {
public:
    int minCost(int n) {

        return (n*(n-1))/2;
    }
};
```

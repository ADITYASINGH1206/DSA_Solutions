# [3700. Number of ZigZag Arrays II](https://leetcode.com/problems/number-of-zigzag-arrays-ii/)
**Difficulty:** `Hard` | **Tags:** `math`, `dynamic-programming`

---

## Problem Description
You are given three integers `n`, `l`, and `r`.

A **ZigZag** array of length `n` is defined as follows:

* Each element lies in the range `[l, r]`.
* No **two** adjacent elements are equal.
* No **three** consecutive elements form a **strictly increasing** or **strictly decreasing** sequence.

Return the total number of valid **ZigZag** arrays.

Since the answer may be large, return it **modulo** `109 + 7`.

A **sequence** is said to be **strictly increasing** if each element is strictly greater than its previous one (if exists).

A **sequence** is said to be **strictly decreasing** if each element is strictly smaller than its previous one (if exists).

**Example 1:**

**Input:** n = 3, l = 4, r = 5

**Output:** 2

**Explanation:**

There are only 2 valid ZigZag arrays of length `n = 3` using values in the range `[4, 5]`:

* `[4, 5, 4]`
* `[5, 4, 5]`

**Example 2:**

**Input:** n = 3, l = 1, r = 3

**Output:** 10

**Explanation:**

​​​​​​​There are 10 valid ZigZag arrays of length `n = 3` using values in the range `[1, 3]`:

* `[1, 2, 1]`, `[1, 3, 1]`, `[1, 3, 2]`
* `[2, 1, 2]`, `[2, 1, 3]`, `[2, 3, 1]`, `[2, 3, 2]`
* `[3, 1, 2]`, `[3, 1, 3]`, `[3, 2, 3]`

All arrays meet the ZigZag conditions.

**Constraints:**

* `3 <= n <= 109`
* `1 <= l < r <= 75`​​​​​​​

---

## Solution & Editorial
# Intuition
The problem asks for the number of sequences of length $n$ where no two adjacent elements are equal and no three consecutive elements are monotonic. This implies that if we have a sequence $a_{i-1}, a_i, a_{i+1}$, the relationship must alternate: if $a_{i-1} < a_i$, then $a_i > a_{i+1}$, and if $a_{i-1} > a_i$, then $a_i < a_{i+1}$. This structure allows us to model the state as a transition between pairs of values $(a_{i-1}, a_i)$, which can be solved efficiently using matrix exponentiation given the large constraint on $n$.

# Approach
1. Let $m = r - l + 1$. We define the state by the current value $x$ and the direction of the previous step. We map the range $[l, r]$ to indices $[0, m-1]$.
2. A state can be represented as $(x, \text{dir})$, where $x \in [0, m-1]$ and $\text{dir} \in \{0, 1\}$. $\text{dir}=0$ means the last step was increasing ($a_{i-1} < a_i$), and $\text{dir}=1$ means the last step was decreasing ($a_{i-1} > a_i$).
3. The transition matrix $T$ of size $2m \times 2m$ is constructed:
   - If the last step was increasing ($a_{i-1} < a_i$), the next step must be decreasing ($a_i > a_{i+1}$).
   - If the last step was decreasing ($a_{i-1} > a_i$), the next step must be increasing ($a_i < a_{i+1}$).
4. We use binary exponentiation to compute $T^{n-1}$ in $O((2m)^3 \log n)$ time.
5. The total count is the sum of all entries in the resulting matrix after applying the initial state vector.

# Complexity
- Time complexity: $$O(m^3 \log n)$$, where $m = r - l + 1$. Since $m \le 75$, $m^3 \approx 4.2 \times 10^5$, which is well within limits for $O(m^3 \log n)$.
- Space complexity: $$O(m^2)$$ to store the transition and result matrices.

# Code
```cpp
class Solution {
public:
    static const long long MOD = 1000000007LL;

    vector<vector<long long>> multiply(
        const vector<vector<long long>>& A,
        const vector<vector<long long>>& B
    ) {
        int sz = A.size();

        vector<vector<long long>> C(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < sz; k++) {
                if (A[i][k] == 0) continue;

                long long cur = A[i][k];

                for (int j = 0; j < sz; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        vector<vector<long long>> T(sz, vector<long long>(sz, 0));

        for (int x = 0; x < m; x++) {

            for (int y = x + 1; y < m; y++) {
                T[x][m + y] = 1;
            }

            for (int y = 0; y < x; y++) {
                T[m + x][y] = 1;
            }
        }

        vector<vector<long long>> result(sz, vector<long long>(sz, 0));
        for (int i = 0; i < sz; i++) {
            result[i][i] = 1;
        }

        long long power = n - 1;

        while (power > 0) {
            if (power & 1) {
                result = multiply(result, T);
            }

            T = multiply(T, T);
            power >>= 1;
        }

        vector<long long> initial(sz, 1);

        long long answer = 0;

        for (int i = 0; i < sz; i++) {
            long long rowSum = 0;

            for (int j = 0; j < sz; j++) {
                rowSum = (rowSum + result[i][j]) % MOD;
            }

            answer = (answer + rowSum) % MOD;
        }

        return (int)answer;
    }
};
```

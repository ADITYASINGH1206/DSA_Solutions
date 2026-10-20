# [119. Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/)
**Difficulty:** `Easy` | **Tags:** `array`, `dynamic-programming`

---

## Problem Description
Given an integer `rowIndex`, return the `rowIndexth` (**0-indexed**) row of the **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

**Example 1:**

```
Input: rowIndex = 3
Output: [1,3,3,1]
```

**Example 2:**

```
Input: rowIndex = 0
Output: [1]
```

**Example 3:**

```
Input: rowIndex = 1
Output: [1,1]
```

**Constraints:**

* `0 <= rowIndex <= 33`

**Follow up:** Could you optimize your algorithm to use only `O(rowIndex)` extra space?

---

## Solution & Editorial
# Intuition
The $k$-th row of Pascal's triangle consists of the binomial coefficients $\binom{k}{i}$ for $0 \le i \le k$. Instead of generating the entire triangle row-by-row, we can compute each element of the target row directly in $O(1)$ time relative to its position by using the relation between consecutive binomial coefficients: $\binom{n}{i} = \binom{n}{i-1} \times \frac{n - i + 1}{i}$.

# Approach
1. Initialize a vector `ans` to store the resulting row and push `1` as the first element since $\binom{k}{0} = 1$.
2. If `rowIndex` is `0`, immediately return `ans`.
3. Iterate `i` from $1$ to `rowIndex - 1`. For each iteration, update `val` using the recurrence relation `val = val * (rowIndex - i + 1) / i` and append it to `ans`.
4. Push `1` as the final element of the row ($\binom{k}{k} = 1$) and return `ans`.

### Visual Trace Walkthrough (Example 1: rowIndex = 3)
- Initial: `ans = [1]`, `val = 1`
- i = 1: `val = 1 * (3 - 1 + 1) / 1 = 3`. `ans = [1, 3]`
- i = 2: `val = 3 * (3 - 2 + 1) / 2 = 3`. `ans = [1, 3, 3]`
- Loop ends. Push terminal `1`. `ans = [1, 3, 3, 1]`

# Complexity
- Time complexity: $$O(k)$$ where $$k$$ is `rowIndex`. We run a single loop from 1 to `rowIndex - 1`, performing a constant number of arithmetic operations per iteration.
- Space complexity: $$O(k)$$ auxiliary space required to store the resulting vector of size `rowIndex + 1`.

# Code
```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long val=1;
        ans.push_back(val);
        if(rowIndex == 0){
            return ans;
        }
        for(int i=1;i<rowIndex;i++){
            val = val*(rowIndex-i+1);
            val = val /(i);
            ans.push_back(val);
        }
        ans.push_back(1);
        return ans;
    }
};
```

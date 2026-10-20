# [1672. Richest Customer Wealth](https://leetcode.com/problems/richest-customer-wealth/)
**Difficulty:** `Easy` | **Tags:** `array`, `matrix`

---

## Problem Description
You are given an `m x n` integer grid `accounts` where `accounts[i][j]` is the amount of money the `i​​​​​​​​​​​th​​​​` customer has in the `j​​​​​​​​​​​th`​​​​ bank. Return *the **wealth** that the richest customer has.*

A customer's **wealth** is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum **wealth**.

**Example 1:**

```
Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
```

**Example 2:**

```
Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation: 
1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.
```

**Example 3:**

```
Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17
```

**Constraints:**

* `m == accounts.length`
* `n == accounts[i].length`
* `1 <= m, n <= 50`
* `1 <= accounts[i][j] <= 100`

---

## Solution & Editorial
# Intuition
To find the richest customer, we must calculate the total wealth for each individual customer by summing the values in their respective rows of the `accounts` matrix. By maintaining a running maximum of these sums, we can identify the highest wealth in a single pass.

# Approach
1. Initialize a variable `ans` to 0 to store the maximum wealth found so far.
2. Iterate through each row `i` of the `accounts` matrix, representing each customer.
3. For each customer, initialize a local variable `sum` to 0.
4. Iterate through each column `j` of the current row, adding `accounts[i][j]` to `sum`.
5. After calculating the total for the customer, update `ans` using `max(ans, sum)`.
6. Return `ans` after processing all customers.

### Visual Trace (Example 1: `[[1,2,3],[3,2,1]]`)
| Iteration (i) | Row Values | Current Sum | Max Wealth (ans) |
| :--- | :--- | :--- | :--- |
| 0 | [1, 2, 3] | 6 | 6 |
| 1 | [3, 2, 1] | 6 | 6 |

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ is the number of customers and $$N$$ is the number of banks. We visit every element in the matrix exactly once.
- Space complexity: $$O(1)$$, as we only use a constant amount of extra space for the `ans` and `sum` variables.

# Code
```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(int i = 0 ; i <accounts.size();i++){
            int sum = 0;
            for(int j = 0 ; j<accounts[i].size();j++){
                sum+=accounts[i][j];
            }
            ans=max(ans,sum);
        }
        return ans;    
    }
};
```

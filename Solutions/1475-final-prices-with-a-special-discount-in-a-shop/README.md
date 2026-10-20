# [1475. Final Prices With a Special Discount in a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/)
**Difficulty:** `Easy` | **Tags:** `array`, `stack`, `monotonic-stack`

---

## Problem Description
You are given an integer array `prices` where `prices[i]` is the price of the `ith` item in a shop.

There is a special discount for items in the shop. If you buy the `ith` item, then you will receive a discount equivalent to `prices[j]` where `j` is the minimum index such that `j > i` and `prices[j] <= prices[i]`. Otherwise, you will not receive any discount at all.

Return an integer array `answer` where `answer[i]` is the final price you will pay for the `ith` item of the shop, considering the special discount.

**Example 1:**

```
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
```

**Example 2:**

```
Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.
```

**Example 3:**

```
Input: prices = [10,1,1,6]
Output: [9,0,1,6]
```

**Constraints:**

* `1 <= prices.length <= 500`
* `1 <= prices[i] <= 1000`

---

## Solution & Editorial
# Intuition
To find the first smaller or equal element to the right for each index, we need a way to track indices whose discount hasn't been found yet. A monotonic stack is ideal here because it maintains a sequence of indices whose corresponding prices are in non-decreasing order, allowing us to efficiently resolve discounts as soon as a smaller price appears.

# Approach
1. Initialize an empty stack `st` to store indices of prices that are waiting for a discount.
2. Iterate through the `prices` array using index `i` from `0` to `n-1`.
3. For each `prices[i]`, check if the current price is less than or equal to the price at the index stored at the top of the stack (`prices[st.top()]`).
4. If true, `prices[i]` is the discount for `prices[st.top()]`. Subtract `prices[i]` from `prices[st.top()]` and pop the index from the stack. Repeat this while the condition holds.
5. Push the current index `i` onto the stack.
6. After the loop, any indices remaining in the stack have no discount, so their values remain unchanged.

### Visual Trace (Example 1: [8, 4, 6, 2, 3])
| i | prices[i] | Stack (indices) | Action |
|---|---|---|---|
| 0 | 8 | [0] | Push 0 |
| 1 | 4 | [1] | 4 <= 8: prices[0] -= 4, pop 0; Push 1 |
| 2 | 6 | [1, 2] | 6 > 4: Push 2 |
| 3 | 2 | [3] | 2 <= 6: prices[2] -= 2, pop 2; 2 <= 4: prices[1] -= 2, pop 1; Push 3 |
| 4 | 3 | [3, 4] | 3 > 2: Push 4 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the array. Each index is pushed onto and popped from the stack exactly once.
- Space complexity: $$O(N)$$ in the worst case (e.g., a strictly increasing array) where all indices are stored in the stack.

# Code
```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st; 
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        
        return prices;
    }
};
```

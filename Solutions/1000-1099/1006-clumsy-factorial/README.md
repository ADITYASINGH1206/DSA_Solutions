# [1006. Clumsy Factorial](https://leetcode.com/problems/clumsy-factorial/)
**Difficulty:** `Medium` | **Tags:** `math`, `stack`, `simulation`

---

## Problem Description
The **factorial** of a positive integer `n` is the product of all positive integers less than or equal to `n`.

* For example, `factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1`.

We make a **clumsy factorial** using the integers in decreasing order by swapping out the multiply operations for a fixed rotation of operations with multiply `'*'`, divide `'/'`, add `'+'`, and subtract `'-'` in this order.

* For example, `clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1`.

However, these operations are still applied using the usual order of operations of arithmetic. We do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.

Additionally, the division that we use is floor division such that `10 * 9 / 8 = 90 / 8 = 11`.

Given an integer `n`, return *the clumsy factorial of* `n`.

**Example 1:**

```
Input: n = 4
Output: 7
Explanation: 7 = 4 * 3 / 2 + 1
```

**Example 2:**

```
Input: n = 10
Output: 12
Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
```

**Constraints:**

* `1 <= n <= 104`

---

## Solution & Editorial
# Intuition
The problem asks us to evaluate an expression formed by numbers from `n` down to `1` using operators `*`, `/`, `+`, and `-` in a repeating 4-step cycle, respecting standard operator precedence (multiplication and division first, then addition and subtraction). Since operator precedence requires handling higher-precedence operations before additions and subtractions, we can utilize a stack data structure to accumulate partial products/divisions and defer additions and subtractions.

# Approach
1. Initialize a stack `stk` and push the first number `n` onto it. Keep track of the current operation index `op` starting at `0` (where `0` represents `*`, `1` represents `/`, `2` represents `+`, and `3` represents `-`).
2. Iterate through integers from `n - 1` down to `1`. For each integer `i`, apply the operation corresponding to `op`:
   - If `op == 0` (`*`), pop the top of the stack, multiply it by `i`, and push the result back.
   - If `op == 1` (`/`), pop the top of the stack, integer-divide it by `i`, and push the result back.
   - If `op == 2` (`+`), simply push `i` onto the stack.
   - If `op == 3` (`-`), push `-i` onto the stack (converting subtraction into addition of a negative number).
3. Advance the operator index using `op = (op + 1) % 4`.
4. After processing all numbers, sum up all values remaining in the stack to obtain the final answer.

### Visual Walkthrough for Example 1: `n = 4`
- Initial: `stk = [4]`, `op = 0`
- `i = 3`: `op = 0` (`*`). Pop `4`, compute `4 * 3 = 12`. `stk = [12]`, `op` becomes `1`.
- `i = 2`: `op = 1` (`/`). Pop `12`, compute `12 / 2 = 6`. `stk = [6]`, `op` becomes `2`.
- `i = 1`: `op = 2` (`+`). Push `1`. `stk = [6, 1]`, `op` becomes `3`.
- Loop ends. Sum stack elements: `6 + 1 = 7`.
- Return `7`.

# Complexity
- Time complexity: $$O(N)$$ — We iterate from `n - 1` down to `1`, performing constant-time stack push/pop operations at each step. Summing the stack takes $$O(N)$$ time in the worst case.
- Space complexity: $$O(N)$$ — The stack stores up to $$N$$ elements in the worst case when multiple addition and subtraction operations push positive and negative terms.

# Code
```cpp
class Solution {
public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n);
        
        int op = 0; 
        
        for(int i = n - 1; i > 0; i--){
            if(op == 0){
                int top = stk.top();
                stk.pop();
                stk.push(top * i);
            }
            else if(op == 1){
                int top = stk.top();
                stk.pop();
                stk.push(top / i);
            }
            else if(op == 2){
                stk.push(i);
            }
            else if(op == 3){

                stk.push(-i);
            }
            
            op = (op + 1) % 4; 
        }

        int ans = 0;
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};
```

# [2011. Final Value of Variable After Performing Operations](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`, `simulation`

---

## Problem Description
There is a programming language with only **four** operations and **one** variable `X`:

* `++X` and `X++` **increments** the value of the variable `X` by `1`.
* `--X` and `X--` **decrements** the value of the variable `X` by `1`.

Initially, the value of `X` is `0`.

Given an array of strings `operations` containing a list of operations, return *the **final** value of* `X` *after performing all the operations*.

**Example 1:**

```
Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
```

**Example 2:**

```
Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
```

**Example 3:**

```
Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
```

**Constraints:**

* `1 <= operations.length <= 100`
* `operations[i]` will be either `"++X"`, `"X++"`, `"--X"`, or `"X--"`.

---

## Solution & Editorial
# Intuition
The problem asks us to track a single variable `X` starting at 0, modified by four specific string operations. Since every operation either increments or decrements `X` by exactly 1, we only need to identify the sign of the operation to update the state.

# Approach
1. Initialize an integer `x` to 0.
2. Iterate through the `operations` vector. For each string `s`:
   - Check the middle character of the string (index 1). If it is '+', the operation is either "++X" or "X++", both of which increment `x`.
   - Otherwise, the operation is either "--X" or "X--", both of which decrement `x`.
3. Return the final value of `x`.

### Visual Trace (Example 1: ["--X", "X++", "X++"])
| Iteration | Operation | Middle Char | Action | Result (x) |
| :--- | :--- | :--- | :--- | :--- |
| Initial | - | - | - | 0 |
| 1 | "--X" | '-' | x -= 1 | -1 |
| 2 | "X++" | '+' | x += 1 | 0 |
| 3 | "X++" | '+' | x += 1 | 1 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of operations, as we perform a single pass over the input array.
- Space complexity: $$O(1)$$, as we only use a single integer variable to track the state regardless of the input size.

# Code
```cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(int i=0;i < operations.size() ;  i++){
            if((operations[i] =="++X")|| (operations[i] =="X++")){
                x+=1;
            }
            else{
                x-=1;
            }
        }
        return x;
        
    }
};
```

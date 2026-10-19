# [150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `stack`

---

## Problem Description
You are given an array of strings `tokens` that represents an arithmetic expression in a [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Evaluate the expression. Return *an integer that represents the value of the expression*.

**Note** that:

* The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
* Each operand may be an integer or another expression.
* The division between two integers always **truncates toward zero**.
* There will not be any division by zero.
* The input represents a valid arithmetic expression in a reverse polish notation.
* The answer and all the intermediate calculations can be represented in a **32-bit** integer.

**Example 1:**

```
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

**Example 2:**

```
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```

**Example 3:**

```
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

**Constraints:**

* `1 <= tokens.length <= 104`
* `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.

---

## Solution & Editorial
# Intuition
Reverse Polish Notation (RPN) evaluates arithmetic expressions where operators follow their operands. This naturally lends itself to a Last-In, First-Out (LIFO) evaluation paradigm using a stack. When an operand is encountered, it is pushed onto the stack. When an operator is encountered, the top two operands are popped, the operation is applied, and the result is pushed back.

# Approach
1. Initialize a `stack<int> stk` to store numeric operands as we parse through the `tokens` array.
2. Iterate through each string in `tokens` using a standard `for` loop.
3. If `tokens[i]` is an operator (`+`, `-`, `*`, `/`), pop the top element as `a` (the right operand) and the next element as `b` (the left operand). Perform the respective operation (`b + a`, `b - a`, `b * a`, `b / a`) and push the result back onto `stk`.
4. If `tokens[i]` is a number, convert it to an integer using `stoi(tokens[i])` and push it onto `stk`.
5. After iterating through all tokens, the final remaining element in `stk` is the evaluated result.

### Visual Trace Walkthrough
Example 1: `tokens = ["2", "1", "+", "3", "*"]`

| Index | Token | Action | Stack State (Bottom to Top) |
| :---: | :---: | :--- | :--- |
| 0 | "2" | Push operand 2 | `[2]` |
| 1 | "1" | Push operand 1 | `[2, 1]` |
| 2 | "+" | Pop `a = 1`, `b = 2`, compute `2 + 1 = 3`, push | `[3]` |
| 3 | "3" | Push operand 3 | `[3, 3]` |
| 4 | "*" | Pop `a = 3`, `b = 3`, compute `3 * 3 = 9`, push | `[9]` |

Final output: `stk.top()` which is `9`.

# Complexity
- Time complexity: $$O(N)$$ — We iterate through the `tokens` array of size $N$ exactly once. Each stack operation (`push`, `pop`, `top`) and string-to-integer conversion takes $O(1)$ amortized time per token.
- Space complexity: $$O(N)$$ — In the worst-case scenario (e.g., all tokens are operands), the stack stores up to $N$ elements.

# Code
```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> stk;
        int n = tokens.size();
        for(int i =0;i<n;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int c = 0;
                if(tokens[i] == "+") c = b+a;
                else if(tokens[i] == "*") c = b*a;
                else if(tokens[i] == "-") c = b-a;
                else if(tokens[i] == "/") c = b/a;
                stk.push(c);
            }
            else{
                int temp = stoi(tokens[i]);
                stk.push(temp);
            }
        }
        return stk.top();
    }
};
```

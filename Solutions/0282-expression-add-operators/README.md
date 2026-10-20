# [282. Expression Add Operators](https://leetcode.com/problems/expression-add-operators/)
**Difficulty:** `Hard` | **Tags:** `math`, `string`, `backtracking`

---

## Problem Description
Given a string `num` that contains only digits and an integer `target`, return ***all possibilities** to insert the binary operators* `'+'`*,* `'-'`*, and/or* `'*'` *between the digits of* `num` *so that the resultant expression evaluates to the* `target` *value*.

Note that operands in the returned expressions **should not** contain leading zeros.

**Note** that a number can contain multiple digits.

**Example 1:**

```
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
```

**Example 2:**

```
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
```

**Example 3:**

```
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
```

**Constraints:**

* `1 <= num.length <= 10`
* `num` consists of only digits.
* `-231 <= target <= 231 - 1`

---

## Solution & Editorial
# Intuition
To generate all valid expressions that evaluate to the target, we need to explore all possible placements of operators (`+`, `-`, `*`) between the digits. Since multiplication takes precedence over addition and subtraction, keeping track of the previously evaluated operand allows us to dynamically reverse its contribution when a multiplication operator is applied.

# Approach
1. Use a recursive backtracking function `backtrack(i, cur, num, ans, target, total, prev)` where `i` represents the current starting index of the digit string, `cur` is the expression constructed so far, `total` is the current evaluation result, and `prev` is the value of the last operand used to handle operator precedence.
2. Iterate through all possible substring lengths starting from index `i` to form the current operand `currStr` and its numeric value `currNum` using `stoll()` to prevent integer overflow.
3. Prevent numbers with leading zeros by breaking the loop if `j > i` and `num[i] == '0'`.
4. If `i == 0`, initialize the expression without any preceding operator. Otherwise, recursively branch into three possibilities:
   - Addition: `total + currNum`, with `prev = currNum`.
   - Subtraction: `total - currNum`, with `prev = -currNum`.
   - Multiplication: `total - prev + (prev * currNum)`, with `prev = prev * currNum` to correctly apply operator precedence.
5. When `i == num.size()`, check if `total == target`. If so, add `cur` to the answer list `ans`.

### Visual Walkthrough for `num = "123"`, `target = 6`
- Start at `i = 0`, choose operand `"1"`: `total = 1`, `prev = 1`, `cur = "1"`
  - Next at `i = 1`, choose operand `"2"`: 
    - Add branch: `total = 1 + 2 = 3`, `prev = 2`, `cur = "1+2"`
      - Next at `i = 2`, choose operand `"3"`: 
        - Add branch: `total = 3 + 3 = 6`, `prev = 3`, `cur = "1+2+3"` -> Matches target `6`, push to `ans`.
    - Multiply branch: `total = 1 - 1 + (1 * 2) = 2`, `prev = 2`, `cur = "1*2"`
      - Next at `i = 2`, choose operand `"3"`: 
        - Multiply branch: `total = 2 - 2 + (2 * 3) = 6`, `prev = 6`, `cur = "1*2*3"` -> Matches target `6`, push to `ans`.

# Complexity
- Time complexity: $$O(4^n)$$ — In the worst case, at each digit index, we can either choose not to split or to split with one of three operators, yielding up to 4 branching choices per step across the string of length $$n$$.
- Space complexity: $$O(n)$$ — The recursion stack depth goes up to $$n$$, and the temporary string copies constructed during backtracking take proportional auxiliary space.

# Code
```cpp
class Solution {
public:
    void backtrack(int i, string cur, string& num, vector<string>& ans, int target, long long total, long long prev){
        if(i == num.size()){
            if(total == target) ans.push_back(cur);
            return;
        }

        for (int j = i; j < num.size(); j++) {
            if (j > i && num[i] == '0') break;
            string currStr = num.substr(i, j - i + 1);
            long long currNum = stoll(currStr);
            if (i == 0) {
                backtrack(j + 1, currStr, num, ans, target, currNum, currNum);
            } else {
                backtrack(j + 1, cur + "+" + currStr, num, ans, target, total + currNum, currNum);
                backtrack(j + 1, cur + "-" + currStr, num, ans, target, total - currNum, -currNum);
                backtrack(j + 1, cur + "*" + currStr, num, ans, target, total - prev + (prev * currNum), prev * currNum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if(num.empty()) return ans;
        backtrack(0, "", num, ans, target, 0, 0);
        return ans;
    }
};
```

# [2726. Calculator with Method Chaining](https://leetcode.com/problems/calculator-with-method-chaining/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Design a `Calculator` class. The class should provide the mathematical operations of addition, subtraction, multiplication, division, and exponentiation. It should also allow consecutive operations to be performed using method chaining. The `Calculator` class constructor should accept a number which serves as the initial value of `result`.

Your `Calculator` class should have the following methods:

* `add` - This method adds the given number `value` to the `result` and returns the updated `Calculator`.
* `subtract` - This method subtracts the given number `value` from the `result` and returns the updated `Calculator`.
* `multiply` - This method multiplies the `result`  by the given number `value` and returns the updated `Calculator`.
* `divide` - This method divides the `result` by the given number `value` and returns the updated `Calculator`. If the passed value is `0`, an error `"Division by zero is not allowed"` should be thrown.
* `power` - This method raises the `result` to the power of the given number `value` and returns the updated `Calculator`.
* `getResult` - This method returns the `result`.

Solutions within `10-5` of the actual result are considered correct.

**Example 1:**

```
Input: 
actions = ["Calculator", "add", "subtract", "getResult"], 
values = [10, 5, 7]
Output: 8
Explanation: 
new Calculator(10).add(5).subtract(7).getResult() // 10 + 5 - 7 = 8
```

**Example 2:**

```
Input: 
actions = ["Calculator", "multiply", "power", "getResult"], 
values = [2, 5, 2]
Output: 100
Explanation: 
new Calculator(2).multiply(5).power(2).getResult() // (2 * 5) ^ 2 = 100
```

**Example 3:**

```
Input: 
actions = ["Calculator", "divide", "getResult"], 
values = [20, 0]
Output: "Division by zero is not allowed"
Explanation: 
new Calculator(20).divide(0).getResult() // 20 / 0 

The error should be thrown because we cannot divide by zero.
```

**Constraints:**

* `actions` is a valid JSON array of strings
* `values` is a valid JSON array of numbers
* `2 <= actions.length <= 2 * 104`
* `1 <= values.length <= 2 * 104 - 1`
* `actions[i]` is one of "Calculator", "add", "subtract", "multiply", "divide", "power", and "getResult"
* First action is always "Calculator"
* Last action is always "getResult"

---

## Solution & Editorial
# Intuition
The problem requires implementing a class that supports method chaining, a common design pattern where each operation returns the instance of the class itself. By maintaining an internal state variable `result`, we can perform sequential arithmetic operations while ensuring the object remains available for further calls.

# Approach
1. **State Management**: Use a private member variable `result` (type `double`) to store the current value of the calculator.
2. **Method Chaining**: Each arithmetic method (`add`, `subtract`, `multiply`, `divide`, `power`) performs the operation on `result` and returns `*this` (a reference to the current instance).
3. **Error Handling**: In the `divide` method, explicitly check if the input `value` is `0`. If so, throw an exception with the required message "Division by zero is not allowed".
4. **Exponentiation**: Utilize the `std::pow` function from the `<cmath>` library to handle the `power` operation.

### Visual Trace (Example 1: `new Calculator(10).add(5).subtract(7)`)
| Step | Operation | `result` | Return Value |
| :--- | :--- | :--- | :--- |
| 1 | Constructor(10) | 10 | `Calculator` instance |
| 2 | add(5) | 15 | `Calculator` instance |
| 3 | subtract(7) | 8 | `Calculator` instance |
| 4 | getResult() | 8 | 8 |

# Complexity
- Time complexity: $$O(1)$$ per operation. Each arithmetic operation and the return of the object reference are constant time operations.
- Space complexity: $$O(1)$$. We only store a single `double` value regardless of the number of operations performed.

# Code
```cpp
class Calculator {
    private x: number;

    constructor(value: number) {
        this.x = value;
    }

    add(value: number): Calculator {
        this.x += value;
        return this;
    }

    subtract(value: number): Calculator {
        this.x -= value;
        return this;
    }

    multiply(value: number): Calculator {
        this.x *= value;
        return this;
    }

    divide(value: number): Calculator {
        if (value === 0) {
            throw new Error('Division by zero is not allowed');
        }
        this.x /= value;
        return this;
    }

    power(value: number): Calculator {
        this.x **= value;
        return this;
    }

    getResult(): number {
        return this.x;
    }
}
```

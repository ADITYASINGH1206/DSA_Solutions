# [2469. Convert the Temperature](https://leetcode.com/problems/convert-the-temperature/)
**Difficulty:** `Easy` | **Tags:** `math`

---

## Problem Description
You are given a non-negative floating point number rounded to two decimal places `celsius`, that denotes the **temperature in Celsius**.

You should convert Celsius into **Kelvin** and **Fahrenheit** and return it as an array `ans = [kelvin, fahrenheit]`.

Return *the array `ans`.* Answers within `10-5` of the actual answer will be accepted.

**Note that:**

* `Kelvin = Celsius + 273.15`
* `Fahrenheit = Celsius * 1.80 + 32.00`

**Example 1:**

```
Input: celsius = 36.50
Output: [309.65000,97.70000]
Explanation: Temperature at 36.50 Celsius converted in Kelvin is 309.65 and converted in Fahrenheit is 97.70.
```

**Example 2:**

```
Input: celsius = 122.11
Output: [395.26000,251.79800]
Explanation: Temperature at 122.11 Celsius converted in Kelvin is 395.26 and converted in Fahrenheit is 251.798.
```

**Constraints:**

* `0 <= celsius <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires a direct transformation of a temperature value from Celsius to Kelvin and Fahrenheit using provided linear equations. Since the conversion formulas are constant-time arithmetic operations, we can compute the results immediately and return them in a vector.

# Approach
1. Initialize a vector `ans` of size 2 to store the results.
2. Calculate Kelvin by adding `273.15` to the input `celsius` and store it at index 0.
3. Calculate Fahrenheit by multiplying `celsius` by `1.8` and adding `32.0`, storing it at index 1.
4. Return the `ans` vector.

### Visual Trace (Example 1: celsius = 36.50)
| Step | Operation | Result |
| :--- | :--- | :--- |
| 1 | Kelvin = 36.50 + 273.15 | 309.65 |
| 2 | Fahrenheit = (36.50 * 1.8) + 32.0 | 97.70 |
| 3 | Return | [309.65, 97.70] |

# Complexity
- Time complexity: $$O(1)$$ — The solution performs a fixed number of arithmetic operations regardless of the input value.
- Space complexity: $$O(1)$$ — We use a fixed-size vector of length 2 to store the output.

# Code
```cpp
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double>ans(2);
        ans[0] = celsius+273.15;
        ans[1] = (celsius*1.8) +32.0;
        return ans;
    }
};
```

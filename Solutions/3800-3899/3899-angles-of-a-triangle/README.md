# [3899. Angles of a Triangle](https://leetcode.com/problems/angles-of-a-triangle/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `geometry`

---

## Problem Description
You are given a positive integer array `sides` of length 3.

Determine if there exists a triangle with **positive** area whose three side lengths are given by the elements of `sides`.

If such a triangle exists, return an array of three floating-point numbers representing its internal angles (in **degrees**), **sorted** in **non-decreasing** order. Otherwise, return an empty array.

Answers within `10-5` of the actual answer will be accepted.

**Example 1:**

**Input:** sides = [3,4,5]

**Output:** [36.86990,53.13010,90.00000]

**Explanation:**

You can form a right-angled triangle with side lengths 3, 4, and 5. The internal angles of this triangle are approximately 36.869897646, 53.130102354, and 90 degrees respectively.

**Example 2:**

**Input:** sides = [2,4,2]

**Output:** []

**Explanation:**

You cannot form a triangle with positive area using side lengths 2, 4, and 2.

**Constraints:**

* `sides.length == 3`
* `1 <= sides[i] <= 1000`

---

## Solution & Editorial
# Intuition
To determine if three side lengths can form a triangle with positive area, we must satisfy the Triangle Inequality Theorem: the sum of any two sides must be strictly greater than the third side. If this holds, we can calculate the internal angles using the Law of Cosines, which relates the sides of a triangle to the cosine of one of its angles.

# Approach
1. **Validation**: Check if `a + b > c`, `a + c > b`, and `b + c > a`. If any condition fails, the sides cannot form a triangle with positive area, so return an empty vector.
2. **Law of Cosines**: For a triangle with sides $a, b, c$ and corresponding opposite angles $A, B, C$, the Law of Cosines states:
   - $\cos(A) = \frac{b^2 + c^2 - a^2}{2bc}$
   - $\cos(B) = \frac{a^2 + c^2 - b^2}{2ac}$
   - $\cos(C) = \frac{a^2 + b^2 - c^2}{2ab}$
3. **Conversion**: Use `acos()` to find the angle in radians, then multiply by $\frac{180}{\pi}$ to convert to degrees.
4. **Sorting**: Store the three angles in a vector and sort them in non-decreasing order as required.

### Visual Trace (Example 1: [3, 4, 5])
| Step | Calculation | Result (Degrees) |
| :--- | :--- | :--- |
| Angle A | $\arccos((4^2+5^2-3^2)/(2*4*5))$ | 36.8699 |
| Angle B | $\arccos((3^2+5^2-4^2)/(2*3*5))$ | 53.1301 |
| Angle C | $\arccos((3^2+4^2-5^2)/(2*3*4))$ | 90.0000 |

# Complexity
- Time complexity: $$O(1)$$ — The operations involve a constant number of arithmetic calculations and a sort of exactly three elements.
- Space complexity: $$O(1)$$ — We use a fixed-size vector of length 3 to store the results.

# Code
```cpp
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans;
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        
        if (a + b <= c || a + c <= b || b + c <= a) {
            return ans;
        }
        
        double aa = acos((b*b + c*c - a*a)/(2.0*b*c))*180.0/M_PI;
        double bb = acos((a*a + c*c - b*b)/(2.0*a*c))*180.0/M_PI;
        double cc = acos((a*a + b*b - c*c)/(2.0*a*b))*180.0/M_PI;
        
        ans.push_back(aa);
        ans.push_back(bb);
        ans.push_back(cc);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
```

# [2695. Array Wrapper](https://leetcode.com/problems/array-wrapper/)
**Difficulty:** `Easy` | **Tags:** `Algorithm`

---

## Problem Description
Create a class `ArrayWrapper` that accepts an array of integers in its constructor. This class should have two features:

* When two instances of this class are added together with the `+` operator, the resulting value is the sum of all the elements in both arrays.
* When the `String()` function is called on the instance, it will return a comma separated string surrounded by brackets. For example, `[1,2,3]`.

**Example 1:**

```
Input: nums = [[1,2],[3,4]], operation = "Add"
Output: 10
Explanation:
const obj1 = new ArrayWrapper([1,2]);
const obj2 = new ArrayWrapper([3,4]);
obj1 + obj2; // 10
```

**Example 2:**

```
Input: nums = [[23,98,42,70]], operation = "String"
Output: "[23,98,42,70]"
Explanation:
const obj = new ArrayWrapper([23,98,42,70]);
String(obj); // "[23,98,42,70]"
```

**Example 3:**

```
Input: nums = [[],[]], operation = "Add"
Output: 0
Explanation:
const obj1 = new ArrayWrapper([]);
const obj2 = new ArrayWrapper([]);
obj1 + obj2; // 0
```

**Constraints:**

* `0 <= nums.length <= 1000`
* `0 <= nums[i] <= 1000`
* `Note: nums is the array passed to the constructor`

---

## Solution & Editorial
# Intuition
To mimic the behavior of the JavaScript `ArrayWrapper` class in C++, we utilize operator overloading. The `+` operator functionality is achieved by overloading the `operator+` to return the sum of the internal values, while the `String()` conversion is handled by overloading the stream insertion operator `<<` or providing a conversion method.

# Approach
1. Store the input vector `nums` as a private member variable.
2. Pre-calculate the sum of the array elements during construction to ensure $O(1)$ access during addition operations.
3. Implement `operator+` to return the sum of the pre-calculated values of two `ArrayWrapper` instances.
4. Implement a `toString()` method that constructs the required string format `[a,b,c]` by iterating through the stored vector.

### Visual Trace (Example 1: nums = [1, 2])
| Step | Action | State |
| :--- | :--- | :--- |
| 1 | Constructor | `nums` = {1, 2}, `sum` = 3 |
| 2 | `obj1 + obj2` | `obj1.sum` (3) + `obj2.sum` (7) = 10 |
| 3 | `toString()` | "[" + "1" + "," + "2" + "]" = "[1,2]" |

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the number of elements in the array, required to calculate the sum and build the string representation.
- Space complexity: $$O(N)$$ to store the input array within the class instance.

# Code
```cpp
class ArrayWrapper {
    private nums: number[];
    private s: number;

    constructor(nums: number[]) {
        this.nums = nums;
        this.s = nums.reduce((a, b) => a + b, 0);
    }

    valueOf() {
        return this.s;
    }

    toString() {
        return `[${this.nums}]`;
    }
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */
```

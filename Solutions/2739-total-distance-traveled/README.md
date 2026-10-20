# [2739. Total Distance Traveled](https://leetcode.com/problems/total-distance-traveled/)
**Difficulty:** `Easy` | **Tags:** `math`, `simulation`

---

## Problem Description
A truck has two fuel tanks. You are given two integers, `mainTank` representing the fuel present in the main tank in liters and `additionalTank` representing the fuel present in the additional tank in liters.

The truck has a mileage of `10` km per liter. Whenever `5` liters of fuel get used up in the main tank, if the additional tank has at least `1` liters of fuel, `1` liters of fuel will be transferred from the additional tank to the main tank.

Return *the maximum distance which can be traveled.*

**Note:** Injection from the additional tank is not continuous. It happens suddenly and immediately for every 5 liters consumed.

**Example 1:**

```
Input: mainTank = 5, additionalTank = 10
Output: 60
Explanation: 
After spending 5 litre of fuel, fuel remaining is (5 - 5 + 1) = 1 litre and distance traveled is 50km.
After spending another 1 litre of fuel, no fuel gets injected in the main tank and the main tank becomes empty.
Total distance traveled is 60km.
```

**Example 2:**

```
Input: mainTank = 1, additionalTank = 2
Output: 10
Explanation: 
After spending 1 litre of fuel, the main tank becomes empty.
Total distance traveled is 10km.
```

**Constraints:**

* `1 <= mainTank, additionalTank <= 100`

---

## Solution & Editorial
# Intuition
The problem describes a discrete process where fuel is consumed in chunks of 5 liters. Since the constraints are small (up to 100), we can directly simulate the fuel consumption process until the main tank can no longer trigger a refill from the additional tank.

# Approach
1. Initialize `ans` to 0 to track the total distance.
2. Use a `while` loop that continues as long as `mainTank` has at least 5 liters and `additionalTank` has at least 1 liter.
3. In each iteration:
   - Add 50 km to `ans` (5 liters * 10 km/liter).
   - Subtract 5 liters from `mainTank`.
   - Decrement `additionalTank` by 1.
   - Add 1 liter back to `mainTank` (the injection).
4. After the loop terminates, add the remaining fuel in `mainTank` multiplied by 10 to `ans`.

### Visual Trace (Example 1: mainTank=5, additionalTank=10)
| Iteration | mainTank (start) | additionalTank (start) | ans (added) | mainTank (end) | additionalTank (end) |
|-----------|------------------|------------------------|-------------|----------------|----------------------|
| 1         | 5                | 10                     | 50          | 1              | 9                    |
| Loop ends | 1                | 9                      | 10          | 0              | 9                    |
| **Total** | -                | -                      | **60**      | -              | -                    |

# Complexity
- Time complexity: $$O(\frac{mainTank}{5})$$ because we consume 5 liters of the main tank in each iteration of the loop.
- Space complexity: $$O(1)$$ as we only use a few integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while(mainTank >= 5 && additionalTank >0){
            ans += 50;
            mainTank -= 5;
            additionalTank--;
            mainTank +=1;
        }
        ans += mainTank*10;
        return ans;
    }
};
```

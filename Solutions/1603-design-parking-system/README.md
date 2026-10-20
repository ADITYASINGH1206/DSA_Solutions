# [1603. Design Parking System](https://leetcode.com/problems/design-parking-system/)
**Difficulty:** `Easy` | **Tags:** `design`, `simulation`, `counting`

---

## Problem Description
Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each size.

Implement the `ParkingSystem` class:

* `ParkingSystem(int big, int medium, int small)` Initializes object of the `ParkingSystem` class. The number of slots for each parking space are given as part of the constructor.
* `bool addCar(int carType)` Checks whether there is a parking space of `carType` for the car that wants to get into the parking lot. `carType` can be of three kinds: big, medium, or small, which are represented by `1`, `2`, and `3` respectively. **A car can only park in a parking space of its** `carType`. If there is no space available, return `false`, else park the car in that size space and return `true`.

**Example 1:**

```
Input
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
Output
[null, true, true, false, false]

Explanation
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
parkingSystem.addCar(3); // return false because there is no available slot for a small car
parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.
```

**Constraints:**

* `0 <= big, medium, small <= 1000`
* `carType` is `1`, `2`, or `3`
* At most `1000` calls will be made to `addCar`

---

## Solution & Editorial
# Intuition
The problem requires maintaining a count of available slots for three distinct categories. Since the number of slots is fixed at initialization and only decrements upon successful parking, we can use three integer member variables to track the remaining capacity for each type.

# Approach
1. Initialize three member variables `b`, `m`, and `s` in the constructor to store the capacity for big, medium, and small cars respectively.
2. In the `addCar` method, check the `carType` parameter:
   - If `carType == 1` (big), verify if `b > 0`. If true, decrement `b` and return `true`.
   - If `carType == 2` (medium), verify if `m > 0`. If true, decrement `m` and return `true`.
   - If `carType == 3` (small), verify if `s > 0`. If true, decrement `s` and return `true`.
3. If the condition for the specific `carType` is not met (i.e., count is 0), return `false`.

### Visual Trace (Example 1: [1, 1, 0])
| Call | carType | b | m | s | Result |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Init | - | 1 | 1 | 0 | - |
| addCar(1) | 1 | 0 | 1 | 0 | true |
| addCar(2) | 2 | 0 | 0 | 0 | true |
| addCar(3) | 3 | 0 | 0 | 0 | false |
| addCar(1) | 1 | 0 | 0 | 0 | false |

# Complexity
- Time complexity: $$O(1)$$. Each call to `addCar` performs a constant number of comparisons and arithmetic operations.
- Space complexity: $$O(1)$$. We only store three integer variables regardless of the input size.

# Code
```cpp
class ParkingSystem {
public:
    int b= 0,m=0,s=0;
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && b>0){
            b--;
            return true;
        }
        else if(carType == 2 && m>0){
            m--;
            return true;
        }
        else if(carType == 3 && s>0){
            s--;
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
```

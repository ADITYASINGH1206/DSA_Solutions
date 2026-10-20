# [1710. Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`, `sorting`

---

## Problem Description
You are assigned to put some amount of boxes onto **one truck**. You are given a 2D array `boxTypes`, where `boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]`:

* `numberOfBoxesi` is the number of boxes of type `i`.
* `numberOfUnitsPerBoxi`is the number of units in each box of the type `i`.

You are also given an integer `truckSize`, which is the **maximum** number of **boxes** that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed `truckSize`.

Return *the **maximum** total number of **units** that can be put on the truck.*

**Example 1:**

```
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
```

**Example 2:**

```
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
```

**Constraints:**

* `1 <= boxTypes.length <= 1000`
* `1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000`
* `1 <= truckSize <= 106`

---

## Solution & Editorial
# Intuition
To maximize the total number of units on the truck, we should prioritize boxes that contain the highest number of units per box. This is a classic greedy problem where sorting the box types by their unit density allows us to fill the truck optimally.

# Approach
1. Sort the `boxTypes` array in descending order based on the number of units per box (`boxTypes[i][1]`).
2. Iterate through the sorted array. For each box type, take as many boxes as possible until either the current type is exhausted or the `truckSize` limit is reached.
3. Maintain a running total `ans` of units added. Decrement `truckSize` for every box added.
4. If `truckSize` reaches zero, terminate early and return `ans`.

### Visual Trace (Example 1: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4)
| Step | Action | Remaining truckSize | ans |
| :--- | :--- | :--- | :--- |
| 0 | Initial | 4 | 0 |
| 1 | Take 1 box (3 units) | 3 | 3 |
| 2 | Take 2 boxes (2 units each) | 1 | 7 |
| 3 | Take 1 box (1 unit) | 0 | 8 |
| 4 | Return | 0 | 8 |

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of box types. The dominant factor is sorting the `boxTypes` array. The subsequent iteration is $$O(N + K)$$ where $$K$$ is the total number of boxes, but since we process boxes in bulk, it effectively simplifies to $$O(N)$$.
- Space complexity: $$O(1)$$ (ignoring the space required for sorting, which depends on the implementation of `std::sort`).

# Code
```cpp
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int ans = 0;
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1];
        });
        int i = 0;
        while(i<n){
            while(boxTypes[i][0]>0){
                ans+= boxTypes[i][1];
                boxTypes[i][0]--;
                truckSize--;
                if(truckSize == 0) return ans;
            }
            i++;

        }
        return ans;
    }
};
```

# [3477. Fruits Into Baskets II](https://leetcode.com/problems/fruits-into-baskets-ii/)
**Difficulty:** `Easy` | **Tags:** `array`, `binary-search`, `segment-tree`, `simulation`, `ordered-set`

---

## Problem Description
You are given two arrays of integers, `fruits` and `baskets`, each of length `n`, where `fruits[i]` represents the **quantity** of the `ith` type of fruit, and `baskets[j]` represents the **capacity** of the `jth` basket.

From left to right, place the fruits according to these rules:

* Each fruit type must be placed in the **leftmost available basket** with a capacity **greater than or equal** to the quantity of that fruit type.
* Each basket can hold **only one** type of fruit.
* If a fruit type **cannot be placed** in any basket, it remains **unplaced**.

Return the number of fruit types that remain unplaced after all possible allocations are made.

**Example 1:**

**Input:** fruits = [4,2,5], baskets = [3,5,4]

**Output:** 1

**Explanation:**

* `fruits[0] = 4` is placed in `baskets[1] = 5`.
* `fruits[1] = 2` is placed in `baskets[0] = 3`.
* `fruits[2] = 5` cannot be placed in `baskets[2] = 4`.

Since one fruit type remains unplaced, we return 1.

**Example 2:**

**Input:** fruits = [3,6,1], baskets = [6,4,7]

**Output:** 0

**Explanation:**

* `fruits[0] = 3` is placed in `baskets[0] = 6`.
* `fruits[1] = 6` cannot be placed in `baskets[1] = 4` (insufficient capacity) but can be placed in the next available basket, `baskets[2] = 7`.
* `fruits[2] = 1` is placed in `baskets[1] = 4`.

Since all fruits are successfully placed, we return 0.

**Constraints:**

* `n == fruits.length == baskets.length`
* `1 <= n <= 100`
* `1 <= fruits[i], baskets[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires us to process each fruit type sequentially and find the leftmost available basket that satisfies the capacity constraint. Since the constraints are small ($N \le 100$), a direct simulation using nested loops is efficient and optimal for this scale.

# Approach
1. Initialize a counter `ans` to `n`, representing the total number of fruits initially unplaced.
2. Iterate through each fruit in the `fruits` array using index `i`.
3. For each fruit, perform a nested search through the `baskets` array using index `j` from left to right.
4. If `fruits[i] <= baskets[j]`, the basket is suitable. Mark it as used by setting `baskets[j] = 0` (since capacities are positive, 0 effectively removes it from future consideration), decrement `ans`, and break the inner loop to move to the next fruit.
5. Return the final value of `ans`.

### Visual Trace (Example 1: fruits = [4, 2, 5], baskets = [3, 5, 4])
| Fruit | Capacity | Basket Search | Action | Baskets State |
| :--- | :--- | :--- | :--- | :--- |
| 4 | 4 | [3, 5, 4] | Found at index 1 | [3, 0, 4] |
| 2 | 2 | [3, 0, 4] | Found at index 0 | [0, 0, 4] |
| 5 | 5 | [0, 0, 4] | None found | [0, 0, 4] |

# Complexity
- Time complexity: $$O(N^2)$$, where $$N$$ is the number of fruits/baskets. We iterate through each fruit and potentially scan all baskets.
- Space complexity: $$O(1)$$, as we perform the simulation in-place without using extra data structures.

# Code
```cpp
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int n=fruits.size();
        int ans=n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (fruits[i]<=baskets[j]){
                    ans--;
                    baskets[j]=0;
                    break;
                }
            }
        }
        return ans;
    }
};
```

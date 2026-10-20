# [1217. Minimum Cost to Move Chips to The Same Position](https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`, `greedy`

---

## Problem Description
We have `n` chips, where the position of the `ith` chip is `position[i]`.

We need to move all the chips to **the same position**. In one step, we can change the position of the `ith` chip from `position[i]` to:

* `position[i] + 2` or `position[i] - 2` with `cost = 0`.
* `position[i] + 1` or `position[i] - 1` with `cost = 1`.

Return *the minimum cost* needed to move all the chips to the same position.

**Example 1:**

```
Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
```

**Example 2:**

```
Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.
```

**Example 3:**

```
Input: position = [1,1000000000]
Output: 1
```

**Constraints:**

* `1 <= position.length <= 100`
* `1 <= position[i] <= 10^9`

---

## Solution & Editorial
# Intuition
The problem asks for the minimum cost to move all chips to the same position. Moving a chip by an even distance ($\pm 2$) costs `0`, while moving a chip by an odd distance ($\pm 1$) costs `1`. This means all chips at even positions can be gathered together at any target even position with zero cost. Similarly, all chips at odd positions can be gathered together at any target odd position with zero cost. Thus, the problem reduces to moving either all odd-positioned chips to an even position or all even-positioned chips to an odd position, incurring a cost of `1` for each chip moved.

# Approach
1. Check if the size of the `position` vector `n` is `1`. If so, return `0` because no moves are needed.
2. Initialize two counter variables, `evens = 0` and `odds = 0`, to keep track of the number of chips at even and odd positions respectively.
3. Iterate through each element in the `position` vector using a standard for loop. If `position[i]` is even (`position[i] % 2 == 0`), increment `evens`; otherwise, increment `odds`.
4. If either `odds == 0` or `evens == 0`, all chips are already on the same parity and can be gathered with `0` cost, so return `0`.
5. Otherwise, return the minimum of `evens` and `odds`, representing the cost of moving the smaller group to the parity of the larger group.

### Visual Trace Walkthrough (Example 1)
Input: `position = [1, 2, 3]`
- `n = 3`
- `i = 0`, `position[0] = 1`: odd -> `odds = 1`, `evens = 0`
- `i = 1`, `position[1] = 2`: even -> `odds = 1`, `evens = 1`
- `i = 2`, `position[2] = 3`: odd -> `odds = 2`, `evens = 1`
- Final counts: `odds = 2`, `evens = 1`
- Return `min(2, 1) = 1`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in the `position` array. We iterate through the array once to count the parity frequencies.
- Space complexity: $$O(1)$$ auxiliary space since we only use two integer variables (`odds` and `evens`) for tracking counts.

# Code
```cpp
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        if(n==1) return 0;
        int evens = 0;
        int odds = 0;
        for(int i = 0;i<n;i++){
            if(position[i]%2 ==0) evens++;
            else odds++;
        }
        if(odds == 0 || evens == 0) return 0;
        return min(evens,odds);
    }
};
```

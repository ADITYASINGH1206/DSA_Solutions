# [1769. Minimum Number of Operations to Move All Balls to Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `prefix-sum`

---

## Problem Description
You have `n` boxes. You are given a binary string `boxes` of length `n`, where `boxes[i]` is `'0'` if the `ith` box is **empty**, and `'1'` if it contains **one** ball.

In one operation, you can move **one** ball from a box to an adjacent box. Box `i` is adjacent to box `j` if `abs(i - j) == 1`. Note that after doing so, there may be more than one ball in some boxes.

Return an array `answer` of size `n`, where `answer[i]` is the **minimum** number of operations needed to move all the balls to the `ith` box.

Each `answer[i]` is calculated considering the **initial** state of the boxes.

**Example 1:**

```
Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
```

**Example 2:**

```
Input: boxes = "001011"
Output: [11,8,5,4,3,4]
```

**Constraints:**

* `n == boxes.length`
* `1 <= n <= 2000`
* `boxes[i]` is either `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
To find the minimum number of operations to move all balls to a specific box `i`, we must calculate the distance from every box `j` containing a ball to box `i`. Since each operation moves a ball to an adjacent box, the cost to move a ball from `j` to `i` is exactly `abs(i - j)`.

# Approach
1. Initialize an empty result vector `ans`.
2. Iterate through each index `i` from `0` to `n-1` to represent the target box.
3. For each target box `i`, iterate through all indices `j` from `0` to `n-1` to find boxes containing balls.
4. If `boxes[j] == '1'`, add the distance `abs(i - j)` to a running sum `count`.
5. After checking all `j` for a fixed `i`, push `count` into `ans`.

### Visual Trace (Example 1: "110")
| Target `i` | `j=0` ('1') | `j=1` ('1') | `j=2` ('0') | Total `count` |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 |
| 2 | 2 | 1 | 0 | 3 |

# Complexity
- Time complexity: $$O(N^2)$$, where $$N$$ is the length of the string. We use a nested loop structure where the outer loop runs $$N$$ times and the inner loop runs $$N$$ times.
- Space complexity: $$O(N)$$ to store the result vector of size $$N$.

# Code
```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for(int i =0;i<boxes.size();i++){
            int count=0;
            for(int j =0;j<boxes.size();j++){
                if(i!=j && boxes[j] =='1'){
                    count+= abs(i-j);
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
```

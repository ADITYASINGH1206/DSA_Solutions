# [2125. Number of Laser Beams in a Bank](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/)
**Difficulty:** `Medium` | **Tags:** `array`, `math`, `string`, `matrix`

---

## Problem Description
Anti-theft security devices are activated inside a bank. You are given a **0-indexed** binary string array `bank` representing the floor plan of the bank, which is an `m x n` 2D matrix. `bank[i]` represents the `ith` row, consisting of `'0'`s and `'1'`s. `'0'` means the cell is empty, while`'1'` means the cell has a security device.

There is **one** laser beam between any **two** security devices **if both** conditions are met:

* The two devices are located on two **different rows**: `r1` and `r2`, where `r1 < r2`.
* For **each** row `i` where `r1 < i < r2`, there are **no security devices** in the `ith` row.

Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return *the total number of laser beams in the bank*.

**Example 1:**

```
Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd row.
This is because the 2nd row contains security devices, which breaks the second condition.
```

**Example 2:**

```
Input: bank = ["000","111","000"]
Output: 0
Explanation: There does not exist two devices located on two different rows.
```

**Constraints:**

* `m == bank.length`
* `n == bank[i].length`
* `1 <= m, n <= 500`
* `bank[i][j]` is either `'0'` or `'1'`.

---

## Solution & Editorial
# Intuition
The problem states that laser beams only exist between security devices in adjacent rows that contain at least one device. Rows with zero devices are ignored, effectively acting as transparent gaps. Therefore, the total number of beams is the sum of the products of device counts in every pair of consecutive non-empty rows.

# Approach
1. Iterate through each row of the `bank` matrix. For each row, count the number of security devices (`'1'`).
2. Store these counts in a vector `laser` only if the count is greater than zero, effectively filtering out rows that do not contribute to beam formation.
3. Iterate through the `laser` vector. For every adjacent pair of counts `laser[i-1]` and `laser[i]`, the number of beams formed between these two rows is the product of their device counts.
4. Accumulate these products into `ans` and return the result.

### Visual Trace (Example 1)
`bank = ["011001", "000000", "010100", "001000"]`

| Row Index | Row String | Device Count | `laser` Vector State |
|-----------|------------|--------------|----------------------|
| 0 | "011001" | 3 | [3] |
| 1 | "000000" | 0 | [3] |
| 2 | "010100" | 2 | [3, 2] |
| 3 | "001000" | 1 | [3, 2, 1] |

**Calculation:**
- Pair (3, 2): 3 * 2 = 6 beams
- Pair (2, 1): 2 * 1 = 2 beams
- Total: 6 + 2 = 8

# Complexity
- Time complexity: $$O(M \times N)$$, where $$M$$ is the number of rows and $$N$$ is the number of columns. We traverse every cell in the matrix exactly once to count the devices.
- Space complexity: $$O(M)$$, as we store the device counts for each row in the `laser` vector, which in the worst case (every row has at least one device) contains $$M$$ elements.

# Code
```cpp
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>laser;
        int ans=0;
        for(int i=0;i<bank.size();i++){
            string row = bank[i];
            int count = 0;
            for(int j=0;j<row.size();j++){
                if(row[j]=='1'){
                    count++;
                }
            }
            if(count >0){
                laser.push_back(count);
            }
            
        }
        for(int i =1;i<laser.size();i++){
            ans+=laser[i]*laser[i-1];
        }
        return ans;
    }
};
```

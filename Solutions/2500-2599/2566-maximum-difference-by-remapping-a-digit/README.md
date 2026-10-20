# [2566. Maximum Difference by Remapping a Digit](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/)
**Difficulty:** `Easy` | **Tags:** `math`, `greedy`

---

## Problem Description
You are given an integer `num`. You know that Bob will sneakily **remap** one of the `10` possible digits (`0` to `9`) to another digit.

Return *the difference between the maximum and minimum values Bob can make by remapping **exactly** **one** digit in* `num`.

**Notes:**

* When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of `d1` in `num` with `d2`.
* Bob can remap a digit to itself, in which case `num` does not change.
* Bob can remap different digits for obtaining minimum and maximum values respectively.
* The resulting number after remapping can contain leading zeroes.

**Example 1:**

```
Input: num = 11891
Output: 99009
Explanation: 
To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
```

**Example 2:**

```
Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.
```

**Constraints:**

* `1 <= num <= 108`

---

## Solution & Editorial
# Intuition
To maximize the number, we should replace the first non-'9' digit encountered from the left with '9'. To minimize the number, we should replace the first digit encountered from the left with '0'. Since we must replace all occurrences of the chosen digit, these greedy choices ensure the most significant positions are optimized.

# Approach
1. Convert the integer `num` to a string to easily access and modify individual digits.
2. **Maximum Value**: Iterate through the string. Find the first digit that is not '9'. Replace all occurrences of this digit with '9'. If all digits are '9', the number remains unchanged.
3. **Minimum Value**: Iterate through the string. Find the first digit (which will be the leftmost digit, `mini[0]`) and replace all occurrences of this digit with '0'.
4. Convert both modified strings back to integers and return their difference.

### Visual Trace (num = 11891)
| Step | Operation | Resulting String |
| :--- | :--- | :--- |
| Initial | - | "11891" |
| Max | Replace '1' with '9' | "99899" |
| Min | Replace '1' with '0' | "00890" |
| Diff | 99899 - 890 | 99009 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of digits in `num`. We perform a constant number of passes over the string (at most 2 passes for each transformation).
- Space complexity: $$O(N)$$ to store the string representation of the number.

# Code
```cpp
class Solution {
public:
    int minMaxDifference(int num) {
        string maxi = to_string(num);
        int n = maxi.size();
        char maxi_char = maxi[0];
        for(int i =0;i<n;i++){
            if(maxi[i] != '9'){
                maxi_char = maxi[i]; 
                break;
            }
        }
        for(int i =0;i<n;i++){
            if(maxi[i] == maxi_char) maxi[i] = '9';
        }
        string mini = to_string(num);
        char mini_char = mini[0];
        for(int i =0;i<n;i++){
            if(mini[i] != '0') {
                mini_char = mini[i]; 
                break;
            }
        }
        for(int i =0;i<n;i++){
            if(mini[i] == mini_char) mini[i] = '0';
        }

        int ans = stoi(maxi)-stoi(mini);
        return ans;
    }
};
```

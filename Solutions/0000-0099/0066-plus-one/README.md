# [66. Plus One](https://leetcode.com/problems/plus-one/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given a **large integer** represented as an integer array `digits`, where each `digits[i]` is the `ith` digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`'s.

Increment the large integer by one and return *the resulting array of digits*.

**Example 1:**

```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
```

**Example 2:**

```
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
```

**Example 3:**

```
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
```

**Constraints:**

* `1 <= digits.length <= 100`
* `0 <= digits[i] <= 9`
* `digits` does not contain any leading `0`'s.

---

## Solution & Editorial
# Intuition
When incrementing a large integer represented as an array of digits, addition starts from the least significant digit (the end of the array). If a digit is less than 9, adding 1 completes the operation immediately. If the digit is 9, it rolls over to 0 and generates a carry that propagates to the preceding digits.

# Approach
1. Iterate backward through the `digits` vector starting from the last element `i = digits.size() - 1` down to `0`.
2. On the last element, add 1 directly to `digits[i]` via `sum`. If `carry` is active from a previous iteration, include it.
3. If `sum >= 10`, calculate the new `carry` and update `digits[i]` to `sum % 10`. Otherwise, assign `sum` directly to `digits[i]` and terminate early if `carry == 0` since no further propagation is required.
4. After the loop finishes, if `carry` remains non-zero (e.g., all original digits were 9 such as `[9, 9]`), insert `carry` at the beginning of the vector using `digits.insert(digits.begin(), carry)`.

### Visual Walkthrough (Example 3: `digits = [9]`)
- `i = 0`: `digits[0] = 9`. Last element condition adds 1 $ightarrow$ `sum = 10`. `sum >= 10` is true $ightarrow$ `carry = 10 % 9 = 1` (Note: `carry = sum / 10` is standard, but `sum % 9` evaluates to 1 when `sum = 10`), `digits[0] = 0`. Loop breaks.
- Post-loop: `carry = 1 != 0` $ightarrow$ `digits.insert(digits.begin(), 1)` $ightarrow$ `digits = [1, 0]`.

# Complexity
- Time complexity: $$O(N)$$ in the worst-case scenario where all digits are 9 and a carry propagates through all $$N$$ elements. In the best/average case, it runs in $$O(1)$$ time due to early termination.
- Space complexity: $$O(1)$$ auxiliary space, excluding the space needed for the output vector. Inserting at the beginning in the worst case takes $$O(N)$$ time to shift elements, which is optimal for array resizing.

# Code
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry =0,sum=0;
        for(int i=digits.size()-1;i>=0;i--){
            if(carry != 0){
                sum = digits[i] +carry;
                carry =0;
            }
            if(i==digits.size()-1){
                sum = digits[i]+1;
            }
            if(sum >=10){
                carry = sum%9;
                digits[i] = sum%10;
            }
            else{
                digits[i] = sum;
            }
            if(carry ==0){
                break;
            }
            
        }
        if(carry!=0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
```

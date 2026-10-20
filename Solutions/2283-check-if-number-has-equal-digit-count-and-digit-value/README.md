# [2283. Check if Number Has Equal Digit Count and Digit Value](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `counting`

---

## Problem Description
You are given a **0-indexed** string `num` of length `n` consisting of digits.

Return `true` *if for **every** index* `i` *in the range* `0 <= i < n`*, the digit* `i` *occurs* `num[i]` *times in* `num`*, otherwise return* `false`.

**Example 1:**

```
Input: num = "1210"
Output: true
Explanation:
num[0] = '1'. The digit 0 occurs once in num.
num[1] = '2'. The digit 1 occurs twice in num.
num[2] = '1'. The digit 2 occurs once in num.
num[3] = '0'. The digit 3 occurs zero times in num.
The condition holds true for every index in "1210", so return true.
```

**Example 2:**

```
Input: num = "030"
Output: false
Explanation:
num[0] = '0'. The digit 0 should occur zero times, but actually occurs twice in num.
num[1] = '3'. The digit 1 should occur three times, but actually occurs zero times in num.
num[2] = '0'. The digit 2 occurs zero times in num.
The indices 0 and 1 both violate the condition, so return false.
```

**Constraints:**

* `n == num.length`
* `1 <= n <= 10`
* `num` consists of digits.

---

## Solution & Editorial
# Intuition
The problem requires verifying if each digit `i` appears exactly `num[i]` times in the string. Since the input length is small (up to 10), we can pre-calculate the frequency of every digit present in the string and then compare these counts against the values specified at each index.

# Approach
1. Initialize a frequency array `freq` of size 10 to store the count of each digit (0-9) found in `num`.
2. Iterate through the string `num` once to populate `freq`, where `freq[ch - '0']` increments for every character `ch`.
3. Iterate through the string again using index `i` from `0` to `n-1`. For each index, compare `freq[i]` with the integer value of `num[i]`.
4. If any `freq[i]` does not match `num[i] - '0'`, return `false`. If the loop completes, return `true`.

### Visual Trace (Example 1: "1210")
| Index | Digit | Freq Array (0-9) |
|-------|-------|------------------|
| Start | -     | [0,0,0,0,0,0,0,0,0,0] |
| 0     | '1'   | [0,1,0,0,0,0,0,0,0,0] |
| 1     | '2'   | [0,1,1,0,0,0,0,0,0,0] |
| 2     | '1'   | [0,2,1,0,0,0,0,0,0,0] |
| 3     | '0'   | [1,2,1,0,0,0,0,0,0,0] |

Verification:
- i=0: freq[0]=1, num[0]='1' (Match)
- i=1: freq[1]=2, num[1]='2' (Match)
- i=2: freq[2]=1, num[2]='1' (Match)
- i=3: freq[3]=0, num[3]='0' (Match)

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform two linear passes over the input.
- Space complexity: $$O(1)$$, as the frequency array is fixed at size 10 regardless of input size.

# Code
```cpp
class Solution {
public:
    bool digitCount(string num) {
        vector<int>freq(10,0);
        for(char ch :num){
            freq[ch-'0']++;
        }
        for(int i = 0 ;i<num.size();i++){
            if(freq[i]!=num[i]-'0'){
                return false;
            }
        }
        return true;
    }
};
```

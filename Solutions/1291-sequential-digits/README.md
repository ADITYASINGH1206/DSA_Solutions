# [1291. Sequential Digits](https://leetcode.com/problems/sequential-digits/)
**Difficulty:** `Medium` | **Tags:** `enumeration`

---

## Problem Description
An integer has *sequential digits* if and only if each digit in the number is one more than the previous digit.

Return a **sorted** list of all the integers in the range `[low, high]` inclusive that have sequential digits.

**Example 1:**

```
Input: low = 100, high = 300
Output: [123,234]
```

**Example 2:**

```
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
```

**Constraints:**

* `10 <= low <= high <= 10^9`

---

## Solution & Editorial
# Intuition
The problem asks us to find all integers with sequential digits within a given range `[low, high]`. Since the maximum possible value is $10^9$, the maximum length of any sequential number is 9. We can construct a master string containing all digits in order (`"123456789"`) and generate all possible sequential numbers by taking substrings of length varying from the length of `low` to the length of `high`.

# Approach
1. Initialize an empty vector `ans` to store the valid sequential numbers.
2. Define a master string `s = "123456789"` which contains all single-digit sequential increments.
3. Convert `low` and `high` to string representations `l` and `h` to determine the minimum length `l.size()` and maximum length `h.size()` for our generated numbers.
4. Iterate through all possible substring lengths `i` from `l.size()` to `h.size()`.
5. For each length `i`, iterate through all possible starting indices `j` from `0` to `9 - i` to extract the substring `n = s.substr(j, i)`.
6. Convert the substring `n` to an integer `num`. If `num` falls inclusively within the range `[low, high]`, append it to `ans`.
7. Return the sorted vector `ans`.

### Visual Trace (Example 1: low = 100, high = 300)
- `l = "100"` (size 3), `h = "300"` (size 3)
- Outer loop length `i = 3`:
  - `j = 0`: substring `"123"`, `num = 123` ($123 ∈ [100, 300]$) -> `ans = [123]`
  - `j = 1`: substring `"234"`, `num = 234` ($234 ∈ [100, 300]$) -> `ans = [123, 234]`
  - `j = 2`: substring `"345"`, `num = 345` ($345 
otin [100, 300]$)
- Final Output: `[123, 234]`

# Complexity
- Time complexity: $$O(1)$$
  The total number of possible sequential digits of length up to 9 is strictly bounded and constant ($rac{9 	imes 10}{2} = 45$ total substrings). Substring extraction, conversion via `stoi`, and bounds checks execute in a fixed number of operations.
- Space complexity: $$O(1)$$
  Auxiliary space is limited to a few string variables and the output vector `ans`, which contains at most 45 elements.

# Code
```cpp
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string s = "123456789";
        string l = to_string(low);
        string h = to_string(high);

        for(int i = l.size(); i <= h.size(); i++) {
            for(int j = 0; j <= 9 - i; j++) {
                string n = s.substr(j, i);
                int num = stoi(n);
                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};
```

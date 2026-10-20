# [179. Largest Number](https://leetcode.com/problems/largest-number/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `greedy`, `sorting`

---

## Problem Description
Given a list of non-negative integers `nums`, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

**Example 1:**

```
Input: nums = [10,2]
Output: "210"
```

**Example 2:**

```
Input: nums = [3,30,34,5,9]
Output: "9534330"
```

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 109`

---

## Solution & Editorial
# Intuition
The problem asks us to arrange a given list of non-negative integers such that when concatenated, they form the largest possible number. Standard lexicographical sorting fails because digit placement depends on relative prefixes and lengths (e.g., comparing "3" and "30", "330" is larger than "303"). By defining a custom comparator that evaluates both concatenation orders ($a+b$ vs $b+a$), we can sort the string representations correctly using a greedy approach.

# Approach
1. Convert every integer in the `nums` vector into its string representation and store them in a `vector<string> str` using `to_string`.
2. Sort the `str` vector using a custom lambda comparator `[](string a, string b) { return a + b > b + a; }`. This ensures that if concatenating `a` then `b` yields a numerically larger value than `b` then `a`, `a` will be placed before `b`.
3. Handle the edge case where the largest number after sorting is "0" (e.g., `nums = [0, 0]`). If `str[0] == "0"`, immediately return "0" to prevent returning "00".
4. Iterate through the sorted `str` vector, concatenate all strings into an accumulator string `ans`, and return it.

### Visual Trace Walkthrough
For `nums = [3, 30, 34, 5, 9]`:
- Step 1: `str` becomes `["3", "30", "34", "5", "9"]`.
- Step 2: Sorting with comparator `a + b > b + a`:
  - Compare "3" and "30": "330" > "303" $ightarrow$ "3" comes before "30".
  - Compare "34" and "5": "345" < "534" $ightarrow$ "5" comes before "34".
  - Final sorted order: `["9", "5", "34", "3", "30"]`.
- Step 3: `str[0]` is not "0".
- Step 4: Concatenating yields `"9534330"`.

# Complexity
- Time complexity: $$O(N \log N \cdot K)$$ where $$N$$ is the number of elements in `nums` and $$K$$ is the maximum number of digits in an integer. The sorting step takes $$O(N \log N)$$ comparisons, and each comparison performs string concatenation of length up to $$2K$$.
- Space complexity: $$O(N \cdot K)$$ to store the string representations of all $$N$$ integers in the auxiliary `str` vector and the final result string.

# Code
```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for (auto it : nums) {
            str.push_back(to_string(it));
        }

        sort(str.begin(), str.end(), [](string a , string b){
            return a+b > b+a ;
        });

        if (str[0] == "0") return "0";

        string ans = "";
        for (auto &s : str) {
            ans += s;
        }

        return ans;
    }
};
```

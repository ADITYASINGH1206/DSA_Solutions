# [4036. Lexicographically Largest String After Pair Transformations](https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/)
**Difficulty:** `Medium` | **Tags:** `array`, `string`, `greedy`, `bit-manipulation`

---

## Problem Description
You are given an integer array `nums`.

For each integer `x` in `nums`, start with a string consisting of exactly `x` lowercase `'a'` characters.

You may perform the following operation any number of times (including zero):

* Choose two **adjacent equal** letters and replace them with the next letter in the alphabet.

For example, `"aa"` can be replaced with `"b"`, and `"bb"` can be replaced with `"c"`. The pair `"zz"` cannot be replaced.

For each `x`, determine the **lexicographically largest** string that can be obtained.

Return an array of strings where the `ith` string is the answer for `nums[i]`.

A string `a` is **lexicographically larger** than a string `b` if, at the first position where they differ, `a` contains a letter that appears later in the alphabet than the corresponding letter in `b`. If the first `min(a.length, b.length)` characters are equal, the longer string is lexicographically larger.

**Example 1:**

**Input:** nums = [2,5,7]

**Output:** ["b","ca","cba"]

**Explanation:**

* `nums[0] = 2`: `"aa"` → `"b"`.
* `nums[1] = 5`: `"aaaaa"` → `"baaa"` → `"bba"` → `"ca"`.
* `nums[2] = 7`: `"aaaaaaa"` → `"baaaaa"` → `"bbaaa"` → `"bbba"` → `"cba"`.
* Therefore, `ans = ["b", "ca", "cba"]`.

**Example 2:**

**Input:** nums = [3,9,1]

**Output:** ["ba","da","a"]

**Explanation:**

* `nums[0] = 3`: `"aaa"` → `"ba"`.
* `nums[1] = 9`: `"aaaaaaaaa"` → `"baaaaaaa"` → `"bbaaaaa"` → `"bbbaaa"` → `"bbbba"` → `"cbba"` → `"cca"` → `"da"`.
* `nums[2] = 1`: No transformation can be applied, so the result is `"a"`.
* Therefore, `ans = ["ba", "da", "a"]`.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 108`

---

## Solution & Editorial
# Intuition
The operation allows us to combine two identical characters into the next character in the alphabet (e.g., 'a' + 'a' = 'b'). This is mathematically equivalent to binary addition: two units of value $2^k$ combine to form one unit of value $2^{k+1}$. To obtain the lexicographically largest string, we must prioritize placing larger characters at the beginning of the string.

# Approach
1. For each number $x$, we decompose it into its binary representation. Each bit at position $i$ (where $0 \le i < 25$) represents the presence of the character corresponding to `'a' + i`.
2. Since we want the lexicographically largest string, we iterate from the highest possible character ('z' or lower, depending on $x$) down to 'a'.
3. Any remaining value after the 25th bit (representing $2^{25}$) is treated as multiple occurrences of the character 'z'.

### Visual Trace (nums = [5])
- $5$ in binary is $101_2$ ($1 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0$).
- `counts[0] = 1` ('a'), `counts[1] = 0`, `counts[2] = 1` ('c').
- Result: Construct string by appending `counts[2]` 'c's, then `counts[1]` 'b's, then `counts[0]` 'a's.
- Output: "ca".

# Complexity
- Time complexity: $$O(N \cdot \log(\max(nums)))$$, where $N$ is the number of elements in `nums`. Each number is processed in logarithmic time relative to its value.
- Space complexity: $$O(\log(\max(nums)))$$ to store the character counts and the resulting string for each element.

# Code
```cpp
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        
        for (int x : nums) {
            vector<int> counts(26, 0);
            for (int i = 0; i < 25; ++i) {
                counts[i] = x % 2; 
                x = x / 2;         
            }
            counts[25] = x; 
            
            
            string s = "";
            for (int i = 25; i >= 0; --i) {
                if (counts[i] > 0) {
                    s.append(counts[i], (char)('a' + i));
                }
            }
            
            ans.push_back(s);
        }
        
        return ans;
    }
};
```

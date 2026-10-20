# [3518. Smallest Palindromic Rearrangement II](https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/)
**Difficulty:** `Hard` | **Tags:** `hash-table`, `math`, `string`, `combinatorics`, `counting`

---

## Problem Description
You are given a **palindromic** string `s` and an integer `k`.

Return the **k-th** **lexicographically smallest** palindromic permutation of `s`. If there are fewer than `k` distinct palindromic permutations, return an empty string.

**Note:** Different rearrangements that yield the same palindromic string are considered identical and are counted once.

**Example 1:**

**Input:** s = "abba", k = 2

**Output:** "baab"

**Explanation:**

* The two distinct palindromic rearrangements of `"abba"` are `"abba"` and `"baab"`.
* Lexicographically, `"abba"` comes before `"baab"`. Since `k = 2`, the output is `"baab"`.

**Example 2:**

**Input:** s = "aa", k = 2

**Output:** ""

**Explanation:**

* There is only one palindromic rearrangement: `"aa"`.
* The output is an empty string since `k = 2` exceeds the number of possible rearrangements.

**Example 3:**

**Input:** s = "bacab", k = 1

**Output:** "abcba"

**Explanation:**

* The two distinct palindromic rearrangements of `"bacab"` are `"abcba"` and `"bacab"`.
* Lexicographically, `"abcba"` comes before `"bacab"`. Since `k = 1`, the output is `"abcba"`.

**Constraints:**

* `1 <= s.length <= 104`
* `s` consists of lowercase English letters.
* `s` is guaranteed to be palindromic.
* `1 <= k <= 106`

---

## Solution & Editorial
# Intuition
To find the k-th lexicographically smallest palindromic permutation, we observe that a palindrome is uniquely determined by its first half and its middle character. Since the total character counts are fixed, we can determine the first half character-by-character from left to right, greedily picking the smallest available character that allows for at least `k` permutations of the remaining characters.

# Approach
1. **Frequency Analysis**: Count occurrences of each character. Since the string is a palindrome, characters with odd counts must form the middle section. Divide even counts by 2 to determine the available characters for the first half.
2. **Combinatorial Counting**: Define a function `get_ways` to calculate the number of distinct permutations of the remaining characters in the first half using the multinomial coefficient formula: $N! / (n_1! * n_2! * ... * n_{26}!)$. We cap the calculation at `k` to prevent overflow.
3. **Greedy Construction**: Iterate through each position of the first half. For each position, try appending characters 'a' through 'z'. If picking a character leaves enough permutations to cover the current `k`, fix that character and move to the next position. Otherwise, subtract the number of permutations possible with that character from `k` and try the next character.

### Visual Trace (Example 1: s = "abba", k = 2)
- `freq`: {a:2, b:2}, `half`: {a:1, b:1}, `mid`: "", `m`: 2
- Position 0: 
  - Try 'a': `half`={a:0, b:1}, `ways` = 1!/1! = 1. Since 1 < 2, `k` becomes 2-1=1, backtrack `half`={a:1, b:1}.
  - Try 'b': `half`={a:1, b:0}, `ways` = 1!/1! = 1. Since 1 >= 1, pick 'b'. `first_half` = "b".
- Position 1: 
  - Try 'a': `half`={a:0, b:0}, `ways` = 1. Since 1 >= 1, pick 'a'. `first_half` = "ba".
- Result: "ba" + "" + reverse("ba") = "baab".

# Complexity
- Time complexity: $$O(M \cdot 26 \cdot 26)$$, where $$M$$ is half the length of the string. We iterate through $$M$$ positions, and for each, we check up to 26 characters, each involving a combinatorial calculation over 26 character counts.
- Space complexity: $$O(1)$$, as the frequency arrays and auxiliary storage are bounded by the constant alphabet size (26).

# Code
```cpp
class Solution {
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        vector<int> half(26, 0);
        string mid = "";
        int m = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid += (char)(i + 'a');
            }
            half[i] = freq[i] / 2;
            m += half[i];
        }
        
        auto get_ways = [&](const vector<int>& f, long long target_k) {
            long long ways = 1;
            int curr_len = 0;
            for (int count : f) {
                if (count > 0) {
                    curr_len += count;
                    long long n = curr_len;
                    long long r = count;
                    
                    if (r > n - r) r = n - r;
                    long long cur_nCr = 1;
                    
                    for (int i = 1; i <= r; ++i) {
                        cur_nCr = cur_nCr * (n - i + 1) / i;
                        if (cur_nCr > target_k) {
                            cur_nCr = target_k + 1;
                            break;
                        }
                    }
                    ways *= cur_nCr;
                    if (ways > target_k) return target_k + 1;
                }
            }
            return ways;
        };
        
        if (get_ways(half, k) < k) {
            return "";
        }
        
        string first_half = "";
        for (int i = 0; i < m; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half[c] > 0) {
                    half[c]--;
                    long long ways = get_ways(half, k);
                    
                    if (ways >= k) {
                        first_half += (char)(c + 'a');
                        break; 
                    } else {
                        k -= ways;
                        half[c]++;
                    }
                }
            }
        }
        
        string res = first_half + mid;
        for (int i = m - 1; i >= 0; --i) {
            res += first_half[i];
        }
        return res;
    }
};
```

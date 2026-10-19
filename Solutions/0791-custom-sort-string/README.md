# [791. Custom Sort String](https://leetcode.com/problems/custom-sort-string/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `sorting`

---

## Problem Description
You are given two strings `order` and `s`. All the characters of `order` are **unique** and were sorted in some custom order previously.

Permute the characters of `s` so that they match the order that `order` was sorted. More specifically, if a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.

Return *any permutation of* `s` *that satisfies this property*.

**Example 1:**

**Input:**   order = "cba", s = "abcd"

**Output:**   "cbad"

**Explanation:**  `"a"`, `"b"`, `"c"` appear in order, so the order of `"a"`, `"b"`, `"c"` should be `"c"`, `"b"`, and `"a"`.

Since `"d"` does not appear in `order`, it can be at any position in the returned string. `"dcba"`, `"cdba"`, `"cbda"` are also valid outputs.

**Example 2:**

**Input:**   order = "bcafg", s = "abcd"

**Output:**   "bcad"

**Explanation:**  The characters `"b"`, `"c"`, and `"a"` from `order` dictate the order for the characters in `s`. The character `"d"` in `s` does not appear in `order`, so its position is flexible.

Following the order of appearance in `order`, `"b"`, `"c"`, and `"a"` from `s` should be arranged as `"b"`, `"c"`, `"a"`. `"d"` can be placed at any position since it's not in order. The output `"bcad"` correctly follows this rule. Other arrangements like `"dbca"` or `"bcda"` would also be valid, as long as `"b"`, `"c"`, `"a"` maintain their order.

**Constraints:**

* `1 <= order.length <= 26`
* `1 <= s.length <= 200`
* `order` and `s` consist of lowercase English letters.
* All the characters of `order` are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks us to sort a string `s` based on the relative priority given in another string `order`. By counting the frequency of each character in `s` using a hash map, we can first construct the result string by appending characters in the exact sequence specified by `order`, and then append any remaining characters that were not present in `order` at the end.

# Approach
1. Initialize an unordered map `mp` to store the frequency of every character in string `s`.
2. Create an empty result string `ans`.
3. Iterate through each character `c` in `order`. If `c` exists in `mp` (frequency > 0), append it to `ans` as many times as its frequency, and decrement its count in `mp` to zero.
4. Iterate through each character `c` in the original string `s`. If `mp[c]` is still greater than 0, it means this character was not present in `order`. Append it to `ans` and decrement its count.
5. Return `ans`.

### Visual Walkthrough (Example 1)

Input: `order = "cba"`, `s = "abcd"`

1. **Frequency Counting (`mp`)**: `{'a': 1, 'b': 1, 'c': 1, 'd': 1}`
2. **Processing `order`**: 
   - `c`: `mp['c']` is 1. Append `'c'` 1 time. `ans = "c"`, `mp['c'] = 0`.
   - `b`: `mp['b']` is 1. Append `'b'` 1 time. `ans = "cb"`, `mp['b'] = 0`.
   - `a`: `mp['a']` is 1. Append `'a'` 1 time. `ans = "cba"`, `mp['a'] = 0`.
3. **Processing remaining characters in `s` (`"abcd"`)**:
   - `'a'`: `mp['a']` is 0.
   - `'b'`: `mp['b']` is 0.
   - `'c'`: `mp['c']` is 0.
   - `'d'`: `mp['d']` is 1. Append `'d'`. `ans = "cbad"`, `mp['d'] = 0`.
4. **Final Output**: `"cbad"`

# Complexity
- Time complexity: $$O(N + M)$$ where $$N$$ is the length of `s` and $$M$$ is the length of `order`. Building the frequency map takes $$O(N)$$ time, iterating through `order` takes up to $$O(M)$$ time, and appending remaining elements takes $$O(N)$$ time.
- Space complexity: $$O(N)$$ for the frequency hash map and the result string storing the characters.

# Code
```cpp
class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();
        int m = order.size();
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        string ans = "";
        for(char c: order){
            if(mp[c]){
                while(mp[c]>0){
                    ans += c;
                    mp[c]--;
                }
            }
        }
        for(char c: s){
            if(mp[c]){
                ans+= c;
                mp[c]--;
            }
        }


        return ans;
    }
};
```

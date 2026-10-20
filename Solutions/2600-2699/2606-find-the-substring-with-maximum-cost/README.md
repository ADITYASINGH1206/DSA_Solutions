# [2606. Find the Substring With Maximum Cost](https://leetcode.com/problems/find-the-substring-with-maximum-cost/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `string`, `dynamic-programming`

---

## Problem Description
You are given a string `s`, a string `chars` of **distinct** characters and an integer array `vals` of the same length as `chars`.

The **cost of the substring** is the sum of the values of each character in the substring. The cost of an empty string is considered `0`.

The **value of the character** is defined in the following way:

* If the character is not in the string `chars`, then its value is its corresponding position **(1-indexed)** in the alphabet.
  + For example, the value of `'a'` is `1`, the value of `'b'` is `2`, and so on. The value of `'z'` is `26`.
* Otherwise, assuming `i` is the index where the character occurs in the string `chars`, then its value is `vals[i]`.

Return *the maximum cost among all substrings of the string* `s`.

**Example 1:**

```
Input: s = "adaa", chars = "d", vals = [-1000]
Output: 2
Explanation: The value of the characters "a" and "d" is 1 and -1000 respectively.
The substring with the maximum cost is "aa" and its cost is 1 + 1 = 2.
It can be proven that 2 is the maximum cost.
```

**Example 2:**

```
Input: s = "abc", chars = "abc", vals = [-1,-1,-1]
Output: 0
Explanation: The value of the characters "a", "b" and "c" is -1, -1, and -1 respectively.
The substring with the maximum cost is the empty substring "" and its cost is 0.
It can be proven that 0 is the maximum cost.
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` consist of lowercase English letters.
* `1 <= chars.length <= 26`
* `chars` consist of **distinct** lowercase English letters.
* `vals.length == chars.length`
* `-1000 <= vals[i] <= 1000`

---

## Solution & Editorial
# Intuition
The problem asks for the maximum cost of a substring, where character costs are either predefined or based on their alphabetical index. Since we want to maximize the sum of a contiguous segment, this is a classic application of Kadane's Algorithm. We can pre-calculate the value of each character and then perform a single pass to find the maximum subarray sum.

# Approach
1. **Value Mapping**: Create an array `val` of size 26. Initialize it with default values (1 to 26 for 'a' to 'z'). Iterate through `chars` and `vals` to override the default values with the custom costs provided.
2. **Kadane's Algorithm**: Initialize `cost` (current running sum) and `ans` (global maximum). Since an empty substring has a cost of 0, initialize `ans` to 0.
3. **Iteration**: For each character in `s`, update the running `cost` using `max(current_char_value, current_char_value + previous_cost)`. This effectively decides whether to start a new substring at the current character or extend the existing one.
4. **Update Maximum**: Keep track of the maximum `cost` encountered in `ans`.

### Visual Trace (s = "adaa", chars = "d", vals = [-1000])
- `val` map: 'a'=1, 'b'=2, ..., 'd'=-1000, ...
- Iteration 1 ('a'): `cost` = 1, `ans` = 1
- Iteration 2 ('d'): `cost` = max(-1000, -1000 + 1) = -999, `ans` = 1
- Iteration 3 ('a'): `cost` = max(1, 1 + -999) = 1, `ans` = 1
- Iteration 4 ('a'): `cost` = max(1, 1 + 1) = 2, `ans` = 2

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ is the length of string `s` and $$M$$ is the length of `chars`. We iterate through `chars` once to build the map and `s` once to compute the maximum cost.
- Space complexity: $$O(1)$$, as the `val` array is of constant size 26 regardless of input size.

# Code
```cpp
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int>val(26,0);
        for(int i =0;i<26;i++){
            val[i]=i+1;
        }
        for(int i =0;i<chars.size();i++){
            char ch= chars[i];
            val[ch-'a']=vals[i];
        }
        int cost = val[s[0]-'a'];
        int ans = max(cost,0);
        for(int i =1;i<s.size();i++){
            int ch = s[i]-'a';
            cost=max(val[ch],val[ch]+cost);
            ans=max(ans,cost);
        }
        return ans;
    }
};
```

# [2451. Odd String Difference](https://leetcode.com/problems/odd-string-difference/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`

---

## Problem Description
You are given an array of equal-length strings `words`. Assume that the length of each string is `n`.

Each string `words[i]` can be converted into a **difference integer array** `difference[i]` of length `n - 1` where `difference[i][j] = words[i][j+1] - words[i][j]` where `0 <= j <= n - 2`. Note that the difference between two letters is the difference between their **positions** in the alphabet i.e. the position of `'a'` is `0`, `'b'` is `1`, and `'z'` is `25`.

* For example, for the string `"acb"`, the difference integer array is `[2 - 0, 1 - 2] = [2, -1]`.

All the strings in words have the same difference integer array, **except one**. You should find that string.

Return *the string in* `words` *that has different **difference integer array**.*

**Example 1:**

```
Input: words = ["adc","wzy","abc"]
Output: "abc"
Explanation: 
- The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
- The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
- The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1]. 
The odd array out is [1, 1], so we return the corresponding string, "abc".
```

**Example 2:**

```
Input: words = ["aaa","bob","ccc","ddd"]
Output: "bob"
Explanation: All the integer arrays are [0, 0] except for "bob", which corresponds to [13, -13].
```

**Constraints:**

* `3 <= words.length <= 100`
* `n == words[i].length`
* `2 <= n <= 20`
* `words[i]` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To identify the "odd" string, we must transform each string into its unique difference representation. Since all strings except one share the same difference pattern, grouping these patterns allows us to isolate the outlier.

# Approach
1. Iterate through each string in the `words` array.
2. For each string, compute a `difference` vector of size `n-1`, where each element is `words[i][j+1] - words[i][j]`.
3. Use a `std::map<vector<int>, vector<string>>` to group strings by their calculated difference vectors.
4. After processing all strings, iterate through the map. The key associated with a vector of size 1 is the unique difference pattern, and the corresponding string is our answer.

### Visual Trace (Example 1: words = ["adc", "wzy", "abc"])
| String | Difference Calculation | Vector | Map State |
| :--- | :--- | :--- | :--- |
| "adc" | ['d'-'a', 'c'-'d'] | [3, -1] | {[3, -1]: ["adc"]} |
| "wzy" | ['z'-'w', 'y'-'z'] | [3, -1] | {[3, -1]: ["adc", "wzy"]} |
| "abc" | ['b'-'a', 'c'-'b'] | [1, 1] | {[3, -1]: ["adc", "wzy"], [1, 1]: ["abc"]} |

Result: The map entry with size 1 is `[1, 1]`, returning "abc".

# Complexity
- Time complexity: $$O(N \cdot M)$$, where $$N$$ is the number of strings and $$M$$ is the length of each string. We iterate through each string once and compute differences in linear time relative to string length.
- Space complexity: $$O(N \cdot M)$$, required to store the difference vectors and the strings in the map.

# Code
```cpp
class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>,vector<string>> eq;
        
        for (string w : words)
        {
            vector<int> diff;
            for (int i = 1; i < w.size(); ++i)
                diff.push_back(w[i]-w[i-1]);
            eq[diff].push_back(w);
        }
        
        for (auto&[_, ws] : eq)
            if (ws.size() == 1)
                return ws[0];
        
        return words[0]; 
    }
};
```

# [2053. Kth Distinct String in an Array](https://leetcode.com/problems/kth-distinct-string-in-an-array/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`, `counting`

---

## Problem Description
A **distinct string** is a string that is present only **once** in an array.

Given an array of strings `arr`, and an integer `k`, return *the* `kth` ***distinct string** present in* `arr`. If there are **fewer** than `k` distinct strings, return *an **empty string*** `""`.

Note that the strings are considered in the **order in which they appear** in the array.

**Example 1:**

```
Input: arr = ["d","b","c","b","c","a"], k = 2
Output: "a"
Explanation:
The only distinct strings in arr are "d" and "a".
"d" appears 1st, so it is the 1st distinct string.
"a" appears 2nd, so it is the 2nd distinct string.
Since k == 2, "a" is returned.
```

**Example 2:**

```
Input: arr = ["aaa","aa","a"], k = 1
Output: "aaa"
Explanation:
All strings in arr are distinct, so the 1st string "aaa" is returned.
```

**Example 3:**

```
Input: arr = ["a","b","a"], k = 3
Output: ""
Explanation:
The only distinct string is "b". Since there are fewer than 3 distinct strings, we return an empty string "".
```

**Constraints:**

* `1 <= k <= arr.length <= 1000`
* `1 <= arr[i].length <= 5`
* `arr[i]` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To identify the k-th distinct string, we must first determine the frequency of every string in the array. Since we need to preserve the original relative order of appearance, a two-pass approach using a hash map is optimal.

# Approach
1. **Frequency Counting**: Iterate through the input array `arr` and populate an `unordered_map<string, int> mp` to store the count of each string. This allows $O(1)$ average time complexity for lookups.
2. **Filtering and Selection**: Iterate through the original array `arr` a second time. For each string `s`, check if `mp[s] == 1`. If it is, increment a counter `c`.
3. **Termination**: When `c` reaches `k`, the current string `s` is the k-th distinct string. Return it immediately. If the loop completes without `c` reaching `k`, return an empty string `""`.

### Visual Trace (Example 1: arr = ["d","b","c","b","c","a"], k = 2)
| Step | Action | Map State | Counter `c` |
| :--- | :--- | :--- | :--- |
| 1 | Count frequencies | {d:1, b:2, c:2, a:1} | 0 |
| 2 | Check "d" (count 1) | - | 1 |
| 3 | Check "b" (count 2) | - | 1 |
| 4 | Check "c" (count 2) | - | 1 |
| 5 | Check "b" (count 2) | - | 1 |
| 6 | Check "c" (count 2) | - | 1 |
| 7 | Check "a" (count 1) | - | 2 (Return "a") |

# Complexity
- Time complexity: $$O(N \cdot L)$$, where $$N$$ is the number of strings and $$L$$ is the maximum length of a string. We traverse the array twice, and string hashing/comparison takes $$O(L)$$.
- Space complexity: $$O(N \cdot L)$$ to store the frequency map containing up to $$N$$ unique strings of length $$L$$.

# Code
```cpp
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        int n = arr.size();
        for(string s: arr){
            mp[s]++;
        }
        int c= 0;
        for(string s : arr){
            if(mp[s] == 1){
                c++;
                if(c == k) return s;
            }
        }
        return "";
    }
};
```

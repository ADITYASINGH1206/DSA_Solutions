# [2716. Minimize String Length](https://leetcode.com/problems/minimize-string-length/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`

---

## Problem Description
Given a string `s`, you have two types of operation:

1. Choose an index `i` in the string, and let `c` be the character in position `i`. **Delete** the **closest occurrence** of `c` to the **left** of `i` (if exists).
2. Choose an index `i` in the string, and let `c` be the character in position `i`. **Delete** the **closest occurrence** of `c` to the **right** of `i` (if exists).

Your task is to **minimize** the length of `s` by performing the above operations zero or more times.

Return an integer denoting the length of the **minimized** string.

**Example 1:**

**Input:** s = "aaabc"

**Output:** 3

**Explanation:**

1. Operation 2: we choose `i = 1` so `c` is 'a', then we remove `s[2]` as it is closest 'a' character to the right of `s[1]`.  
   `s` becomes "aabc" after this.
2. Operation 1: we choose `i = 1` so `c` is 'a', then we remove `s[0]` as it is closest 'a' character to the left of `s[1]`.  
   `s` becomes "abc" after this.

**Example 2:**

**Input:** s = "cbbd"

**Output:** 3

**Explanation:**

1. Operation 1: we choose `i = 2` so `c` is 'b', then we remove `s[1]` as it is closest 'b' character to the left of `s[1]`.  
   `s` becomes "cbd" after this.

**Example 3:**

**Input:** s = "baadccab"

**Output:** 4

**Explanation:**

1. Operation 1: we choose `i = 6` so `c` is 'a', then we remove `s[2]` as it is closest 'a' character to the left of `s[6]`.  
   `s` becomes "badccab" after this.
2. Operation 2: we choose `i = 0` so `c` is 'b', then we remove `s[6]` as it is closest 'b' character to the right of `s[0]`.  
   `s` becomes "badcca" fter this.
3. Operation 2: we choose `i = 3` so `c` is 'c', then we remove `s[4]` as it is closest 'c' character to the right of `s[3]`.  
   `s` becomes "badca" after this.
4. Operation 1: we choose `i = 4` so `c` is 'a', then we remove `s[1]` as it is closest 'a' character to the left of `s[4]`.  
   `s` becomes "bdca" after this.

**Constraints:**

* `1 <= s.length <= 100`
* `s` contains only lowercase English letters

---

## Solution & Editorial
# Intuition
The problem allows us to delete any character if there exists another occurrence of the same character elsewhere in the string. By repeatedly applying these operations, we can reduce any group of identical characters down to a single instance. Thus, the minimum length of the string is simply the count of unique characters present in the input.

# Approach
1. The core observation is that for any character `c` appearing `k` times, we can perform `k-1` operations to remove all but one instance of `c`.
2. We can use an `unordered_map` (or a `std::set`) to track the frequency of each character in the string.
3. The total number of characters to remove is the sum of `(frequency - 1)` for all characters with frequency > 1.
4. Alternatively, and more simply, the final length is just the number of unique characters in the string.

### Visual Trace (Example 1: "aaabc")
| Step | String | Unique Characters | Count |
| :--- | :--- | :--- | :--- |
| Initial | "aaabc" | {a, b, c} | 3 |
| Op 1 | "aabc" | {a, b, c} | 3 |
| Op 2 | "abc" | {a, b, c} | 3 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We iterate through the string once to populate the frequency map and then iterate over the map (which has a maximum size of 26).
- Space complexity: $$O(1)$$, as the map stores at most 26 unique lowercase English letters, which is constant space regardless of input size.

# Code
```cpp
class Solution {
public:
    int minimizedStringLength(string s) {
        int ans = 0;
        int n = s.size();
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        for(auto [key,value] : mp){
            if(value > 1){
                ans += value-1;
            }
        }
        ans = n-ans;
        return ans;
    }
};
```

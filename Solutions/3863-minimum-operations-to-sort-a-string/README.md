# [3863. Minimum Operations to Sort a String](https://leetcode.com/problems/minimum-operations-to-sort-a-string/)
**Difficulty:** `Medium` | **Tags:** `string`

---

## Problem Description
You are given a string `s` consisting of lowercase English letters.

In one operation, you can select any **substring** of `s` that is **not** the entire string and **sort** it in **non-descending alphabetical** order.

Return the **minimum** number of operations required to make `s` sorted in **non-descending** order. If it is not possible, return -1.

**Example 1:**

**Input:** s = "dog"

**Output:** 1

**Explanation:**​​​​​​​

* Sort substring `"og"` to `"go"`.
* Now, `s = "dgo"`, which is sorted in ascending order. Thus, the answer is 1.

**Example 2:**

**Input:** s = "card"

**Output:** 2

**Explanation:**

* Sort substring `"car"` to `"acr"`, so `s = "acrd"`.
* Sort substring `"rd"` to `"dr"`, making `s = "acdr"`, which is sorted in ascending order. Thus, the answer is 2.

**Example 3:**

**Input:** s = "gf"

**Output:** -1

**Explanation:**

* It is impossible to sort `s` under the given constraints. Thus, the answer is -1.

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists of only lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks for the minimum operations to sort a string by sorting proper substrings. Since we can sort any substring except the entire string, we can effectively move characters around. The core observation is that if the string is already sorted, 0 operations are needed. If we can fix the string in one operation, it implies we can reach a sorted state by sorting either the prefix (excluding the last character) or the suffix (excluding the first character). If that's not possible, we check if two operations suffice, or if the configuration is impossible (like "gf").

# Approach
1. **Check Sorted**: If `is_sorted` returns true, return 0.
2. **Impossible Case**: If the string length is 2 and it's not sorted (e.g., "gf"), it's impossible to sort because any operation would require sorting a substring of length 1, which does nothing. Return -1.
3. **One Operation**: If the first character is the minimum or the last character is the maximum, we can sort the remaining suffix or prefix respectively to achieve a sorted state. Return 1.
4. **Three Operations**: If the string starts with the global maximum and ends with the global minimum, and these are the only occurrences, we need 3 operations to "swap" them into place.
5. **Two Operations**: In all other cases, 2 operations are sufficient to bring the string into a sorted state.

### Visual Trace (Example: "card")
- `s = "card"`, `min='a'`, `max='r'`
- `s[0] ('c') != 'a'` and `s[3] ('d') != 'r'`. Not 1 operation.
- Not the special 3-operation case.
- Return 2.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string, due to `is_sorted`, `min_element`, `max_element`, and `count` operations which all traverse the string linearly.
- Space complexity: $$O(1)$$ as we only use a few integer and character variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        if (n <= 2) {
            return -1;
        }
        
        char min_char = *min_element(s.begin(), s.end());
        char max_char = *max_element(s.begin(), s.end());
        
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        
        int max_count = count(s.begin(), s.end(), max_char);
        int min_count = count(s.begin(), s.end(), min_char);
        
        if (s[0] == max_char && max_count == 1 && 
            s[n - 1] == min_char && min_count == 1) {
            return 3;
        }
        
        return 2;
    }
};
```

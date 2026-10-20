# [2182. Construct String With Repeat Limit](https://leetcode.com/problems/construct-string-with-repeat-limit/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `greedy`, `heap-priority-queue`, `counting`

---

## Problem Description
You are given a string `s` and an integer `repeatLimit`. Construct a new string `repeatLimitedString` using the characters of `s` such that no letter appears **more than** `repeatLimit` times **in a row**. You do **not** have to use all characters from `s`.

Return *the **lexicographically largest*** `repeatLimitedString` *possible*.

A string `a` is **lexicographically larger** than a string `b` if in the first position where `a` and `b` differ, string `a` has a letter that appears later in the alphabet than the corresponding letter in `b`. If the first `min(a.length, b.length)` characters do not differ, then the longer string is the lexicographically larger one.

**Example 1:**

```
Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
```

**Example 2:**

```
Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
```

**Constraints:**

* `1 <= repeatLimit <= s.length <= 105`
* `s` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To construct the lexicographically largest string, we must prioritize appending the largest available characters as early as possible. When we hit the `repeatLimit` for the current largest character, we must break the sequence by inserting a single instance of the next largest available character before returning to the primary character.

# Approach
1. Count character frequencies using a `vector<int>` of size 26.
2. Push all characters with non-zero frequency into a max-priority queue storing pairs of `{char, count}`.
3. In each iteration, extract the largest character `ch` from the priority queue.
4. Append `min(repeatLimit, count)` instances of `ch` to the result string.
5. If `count` remains after appending, we need a "bridge" character to break the sequence. Extract the next largest character `nextCh` from the priority queue, append it once, and decrement its count.
6. Push both characters back into the priority queue if they still have remaining counts.
7. If no bridge character exists when the current character exceeds the limit, terminate the process.

### Visual Trace (s = "cczazcc", repeatLimit = 3)
| Iteration | PQ Top | Action | Result | Remaining PQ |
| :--- | :--- | :--- | :--- | :--- |
| 1 | {z, 2} | Append 'zz' | "zz" | {c, 4}, {a, 1} |
| 2 | {c, 4} | Append 'ccc', then 'a' | "zzccca" | {c, 1}, {a, 0} |
| 3 | {c, 1} | Append 'c' | "zzcccac" | {} |

# Complexity
- Time complexity: $$O(N + A \log A)$$, where $$N$$ is the length of the string and $$A$$ is the alphabet size (26). We iterate through the string once to count frequencies, and the priority queue operations are bounded by the constant alphabet size.
- Space complexity: $$O(A)$$, as the frequency array and priority queue store at most 26 unique characters.

# Code
```cpp
class Solution {
public:
    string repeatLimitedString(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({'a' + i, freq[i]});
        }
        
        string result;
        while (!pq.empty()) {
            auto [ch, count] = pq.top(); 
            pq.pop();
            int used = min(k, count);
            result.append(used, ch);
            count -= used;

            if (count > 0) {
                if (pq.empty()) break;
                auto [nextCh, nextCount] = pq.top(); pq.pop();
                result += nextCh;
                nextCount--;

                if (nextCount > 0) pq.push({nextCh, nextCount});
                pq.push({ch, count});
            }
        }
        return result;
    }
};
```

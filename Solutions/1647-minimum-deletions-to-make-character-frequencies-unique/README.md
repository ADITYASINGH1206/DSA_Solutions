# [1647. Minimum Deletions to Make Character Frequencies Unique](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `greedy`, `sorting`

---

## Problem Description
A string `s` is called **good** if there are no two different characters in `s` that have the same **frequency**.

Given a string `s`, return *the **minimum** number of characters you need to delete to make* `s` ***good**.*

The **frequency** of a character in a string is the number of times it appears in the string. For example, in the string `"aab"`, the **frequency** of `'a'` is `2`, while the **frequency** of `'b'` is `1`.

**Example 1:**

```
Input: s = "aab"
Output: 0
Explanation: s is already good.
```

**Example 2:**

```
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
```

**Example 3:**

```
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` contains only lowercase English letters.

---

## Solution & Editorial
# Intuition
To make a string "good," every character must have a unique frequency. Since we want to minimize deletions, we should greedily reduce the frequency of characters that collide with existing frequencies until we reach a unique value or zero.

# Approach
1. Count the frequency of each character in the string `s` using an array `cnt` of size 26.
2. Use an `unordered_set<int> used` to keep track of frequencies that are already "taken" by other characters.
3. Iterate through the `cnt` array. For each character frequency `cnt[i] > 0`:
   - If `cnt[i]` is already in `used`, decrement `cnt[i]` and increment the result `res` (representing one deletion).
   - Repeat this until `cnt[i]` becomes 0 or `cnt[i]` is a unique value not present in `used`.
   - Once a unique frequency is found, insert it into `used`.

### Visual Trace (Example: "aaabbbcc")
- Initial Frequencies: `a:3, b:3, c:2`
- `used` set: `{}`
- Process 'a' (freq 3): 3 is not in `used`. `used` = `{3}`.
- Process 'b' (freq 3): 3 is in `used`. Decrement to 2. 2 is not in `used`. `used` = `{3, 2}`. `res` = 1.
- Process 'c' (freq 2): 2 is in `used`. Decrement to 1. 1 is not in `used`. `used` = `{3, 2, 1}`. `res` = 2.
- Final result: 2.

# Complexity
- Time complexity: $$O(N + K^2)$$, where $$N$$ is the length of the string and $$K=26$$ is the alphabet size. Counting takes $$O(N)$$, and the nested loop runs at most $$O(K^2)$$ times because each frequency is decremented until unique.
- Space complexity: $$O(K)$$, as the `cnt` array and `used` set store at most 26 elements.

# Code
```cpp
class Solution {
public:
    int minDeletions(string s) {
        int cnt[26] = {}, res = 0;
        unordered_set<int> used;
        for (char ch : s)
            ++cnt[ch - 'a'];
        for (int i = 0; i < 26; ++i)
            for (; cnt[i] > 0 && !used.insert(cnt[i]).second; --cnt[i])
                ++res;
        return res;
    }
};
```

# [3720. Lexicographically Smallest Permutation Greater Than Target](https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `greedy`, `counting`, `enumeration`

---

## Problem Description
You are given two strings `s` and `target`, both having length `n`, consisting of lowercase English letters.

Return the **lexicographically smallest permutation** of `s` that is **strictly** greater than `target`. If no permutation of `s` is lexicographically strictly greater than `target`, return an empty string.

A string `a` is **lexicographically strictly greater** than a string `b` (of the same length) if in the first position where `a` and `b` differ, string `a` has a letter that appears later in the alphabet than the corresponding letter in `b`.

**Example 1:**

**Input:** s = "abc", target = "bba"

**Output:** "bca"

**Explanation:**

* The permutations of `s` (in lexicographical order) are `"abc"`, `"acb"`, `"bac"`, `"bca"`, `"cab"`, and `"cba"`.
* The lexicographically smallest permutation that is strictly greater than `target` is `"bca"`.

**Example 2:**

**Input:** s = "leet", target = "code"

**Output:** "eelt"

**Explanation:**

* The permutations of `s` (in lexicographical order) are `"eelt"`, `"eetl"`, `"elet"`, `"elte"`, `"etel"`, `"etle"`, `"leet"`, `"lete"`, `"ltee"`, `"teel"`, `"tele"`, and `"tlee"`.
* The lexicographically smallest permutation that is strictly greater than `target` is `"eelt"`.

**Example 3:**

**Input:** s = "baba", target = "bbaa"

**Output:** ""

**Explanation:**

* The permutations of `s` (in lexicographical order) are `"aabb"`, `"abab"`, `"abba"`, `"baab"`, `"baba"`, and `"bbaa"`.
* None of them is lexicographically strictly greater than `target`. Therefore, the answer is `""`.

**Constraints:**

* `1 <= s.length == target.length <= 300`
* `s` and `target` consist of only lowercase English letters.

---

## Solution & Editorial
# Intuition
To find the lexicographically smallest permutation of `s` that is strictly greater than `target`, we need to find the longest common prefix between the result and `target`. By iterating backwards from the last index, we can identify the first position `i` where we can place a character larger than `target[i]` while ensuring the remaining characters can form a valid suffix.

# Approach
1. Count the frequency of each character in `s` and subtract the counts of characters in `target` to track available characters for the suffix.
2. Iterate backwards from `i = n-1` to `0`. At each step, "release" `target[i]` back into the available pool.
3. Check if we can pick a character `next` from the available pool such that `next > target[i]`.
4. If such a character exists, we have found the pivot point. Append `next` to the prefix `target[0...i-1]` and fill the remaining positions with the remaining available characters in non-decreasing order to ensure the result is the smallest possible.
5. If no such pivot is found after checking all positions, return an empty string.

### Visual Trace (s="abc", target="bba")
- Initial `cnt`: {a:0, b:-1, c:0} (after subtracting target)
- i=2: `target[2]`='a'. `cnt` becomes {a:1, b:-1, c:0}. No `next > 'a'` available.
- i=1: `target[1]`='b'. `cnt` becomes {a:1, b:0, c:0}. `next`='c' > 'b'.
- Result: `target[0...0]` + 'c' + sorted remaining {'a', 'b'} = "bca".

# Complexity
- Time complexity: $$O(N + \Sigma)$$, where $$N$$ is the length of the string and $$\Sigma=26$$ is the alphabet size. We iterate through the string once and perform constant-time operations (size 26) at each step.
- Space complexity: $$O(1)$$, as we only use a fixed-size array of 26 integers to store character frequencies.

# Code
```cpp
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        for (char ch : target) {
            cnt[ch - 'a']--;
        }

        for (int i = target.size() - 1; i >= 0; i--) {
            int cur = target[i] - 'a';
            cnt[cur]++;

            bool ok = true;
            for (int c = 0; c < 26; c++) {
                if (cnt[c] < 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            int next = -1;
            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    next = c;
                    break;
                }
            }

            if (next == -1) continue;

            cnt[next]--;

            string ans = target.substr(0, i);
            ans += char('a' + next);

            for (int c = 0; c < 26; c++) {
                ans.append(cnt[c], char('a' + c));
            }

            return ans;
        }

        return "";
    }
};
```

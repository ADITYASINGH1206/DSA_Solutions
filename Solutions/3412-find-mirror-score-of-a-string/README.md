# [3412. Find Mirror Score of a String](https://leetcode.com/problems/find-mirror-score-of-a-string/)
**Difficulty:** `Medium` | **Tags:** `hash-table`, `string`, `stack`, `simulation`

---

## Problem Description
You are given a string `s`.

We define the **mirror** of a letter in the English alphabet as its corresponding letter when the alphabet is reversed. For example, the mirror of `'a'` is `'z'`, and the mirror of `'y'` is `'b'`.

Initially, all characters in the string `s` are **unmarked**.

You start with a score of 0, and you perform the following process on the string `s`:

* Iterate through the string from left to right.
* At each index `i`, find the closest **unmarked** index `j` such that `j < i` and `s[j]` is the mirror of `s[i]`. Then, **mark** both indices `i` and `j`, and add the value `i - j` to the total score.
* If no such index `j` exists for the index `i`, move on to the next index without making any changes.

Return the total score at the end of the process.

**Example 1:**

**Input:** s = "aczzx"

**Output:** 5

**Explanation:**

* `i = 0`. There is no index `j` that satisfies the conditions, so we skip.
* `i = 1`. There is no index `j` that satisfies the conditions, so we skip.
* `i = 2`. The closest index `j` that satisfies the conditions is `j = 0`, so we mark both indices 0 and 2, and then add `2 - 0 = 2` to the score.
* `i = 3`. There is no index `j` that satisfies the conditions, so we skip.
* `i = 4`. The closest index `j` that satisfies the conditions is `j = 1`, so we mark both indices 1 and 4, and then add `4 - 1 = 3` to the score.

**Example 2:**

**Input:** s = "abcdef"

**Output:** 0

**Explanation:**

For each index `i`, there is no index `j` that satisfies the conditions.

**Constraints:**

* `1 <= s.length <= 105`
* `s` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem requires finding the closest preceding index `j` for each index `i` such that `s[j]` is the mirror of `s[i]`. Since we want the *closest* index, a Last-In-First-Out (LIFO) structure is ideal. By maintaining a stack of indices for each character, we can efficiently retrieve the most recent occurrence of a character's mirror.

# Approach
1. Use an array of 26 stacks, `indices`, where `indices[c]` stores the indices of character `c` encountered so far.
2. Iterate through the string `s` with index `i`:
   - Calculate the `mirrorChar` index using the formula `25 - (s[i] - 'a')`.
   - Check if `indices[mirrorChar]` is non-empty. If it is, the top element `j` is the closest available mirror index. Pop `j` from the stack and add `i - j` to the total score.
   - If the stack is empty, push the current index `i` onto `indices[s[i] - 'a']` to wait for a future mirror match.

### Visual Trace (s = "aczzx")
| i | s[i] | mirror | Stack State (after) | Score |
|---|---|---|---|---|
| 0 | 'a' | 'z' | `indices['a'] = {0}` | 0 |
| 1 | 'c' | 'x' | `indices['a']={0}, indices['c']={1}` | 0 |
| 2 | 'z' | 'a' | `indices['a']={}, indices['c']={1}` | 2 |
| 3 | 'z' | 'a' | `indices['c']={1}, indices['z']={3}` | 2 |
| 4 | 'x' | 'c' | `indices['z']={3}, indices['c']={}` | 5 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We perform a single pass, and each index is pushed/popped from a stack at most once.
- Space complexity: $$O(N)$$, as in the worst case (e.g., "aaaaa"), we store all indices in the stacks.

# Code
```cpp
class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0;
        vector<stack<int>> indices(26);
        
        for(int i = 0; i < s.size(); i++){
            int currChar = s[i] - 'a';
            int mirrorChar = 25 - currChar;

            if(!indices[mirrorChar].empty()){
                int j = indices[mirrorChar].top();
                indices[mirrorChar].pop();
                ans += i - j;
            } else {
                indices[currChar].push(i);
            }
        }

        return ans;
    }
};
```

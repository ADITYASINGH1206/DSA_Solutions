# [3304. Find the K-th Character in String Game I](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/)
**Difficulty:** `Easy` | **Tags:** `math`, `bit-manipulation`, `recursion`, `simulation`

---

## Problem Description
Alice and Bob are playing a game. Initially, Alice has a string `word = "a"`.

You are given a **positive** integer `k`.

Now Bob will ask Alice to perform the following operation **forever**:

* Generate a new string by **changing** each character in `word` to its **next** character in the English alphabet, and **append** it to the *original* `word`.

For example, performing the operation on `"c"` generates `"cd"` and performing the operation on `"zb"` generates `"zbac"`.

Return the value of the `kth` character in `word`, after enough operations have been done for `word` to have **at least** `k` characters.

**Example 1:**

**Input:** k = 5

**Output:** "b"

**Explanation:**

Initially, `word = "a"`. We need to do the operation three times:

* Generated string is `"b"`, `word` becomes `"ab"`.
* Generated string is `"bc"`, `word` becomes `"abbc"`.
* Generated string is `"bccd"`, `word` becomes `"abbcbccd"`.

**Example 2:**

**Input:** k = 10

**Output:** "c"

**Constraints:**

* `1 <= k <= 500`

---

## Solution & Editorial
# Intuition
The problem describes a growth process where the string length doubles in each step. Since the constraint on $k$ is small ($k \le 500$), we can directly simulate the string construction process until its length is at least $k$.

# Approach
1. Initialize `ans` as the string "a".
2. While the length of `ans` is less than $k$, iterate through the existing characters in `ans`.
3. For each character, calculate the next character in the alphabet using `(char - 'a' + 1) % 26 + 'a'`.
4. Append the generated characters to `ans`.
5. Once the loop terminates, return the character at index `k-1`.

### Visual Trace (k=5)
| Iteration | `ans` (start) | Generated | `ans` (end) | Length |
| :--- | :--- | :--- | :--- | :--- |
| 0 | "a" | - | "a" | 1 |
| 1 | "a" | "b" | "ab" | 2 |
| 2 | "ab" | "bc" | "abbc" | 4 |
| 3 | "abbc" | "bccd" | "abbcbccd" | 8 |

# Complexity
- Time complexity: $$O(K)$$. The string length doubles each iteration, reaching $K$ in $O(\log K)$ steps. Each step processes the current string, leading to a total of $O(K)$ operations.
- Space complexity: $$O(K)$$ to store the string `ans` of length at least $K$.

# Code
```cpp
class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        while(ans.size() < k){
            string next = "";
            for(int i = 0;i<ans.size();i++){
                next += 'a' + ((ans[i]-'a' + 1)%26);
            }
            ans += next;
        }

        return ans[k-1];
    }
};
```

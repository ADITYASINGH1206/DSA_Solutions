# [1189. Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`, `counting`

---

## Problem Description
Given a string `text`, you want to use the characters of `text` to form as many instances of the word **"balloon"** as possible.

You can use each character in `text` **at most once**. Return the maximum number of instances that can be formed.

**Example 1:**

```
Input: text = "nlaebolko"
Output: 1
```

**Example 2:**

```
Input: text = "loonbalxballpoon"
Output: 2
```

**Example 3:**

```
Input: text = "leetcode"
Output: 0
```

**Constraints:**

* `1 <= text.length <= 104`
* `text` consists of lower case English letters only.

**Note:** This question is the same as  [2287: Rearrange Characters to Make Target String.](https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/)

---

## Solution & Editorial
# Intuition
To form as many instances of the word "balloon" as possible, we must count the frequency of each character available in the input string `text`. Since the word "balloon" contains repeated characters ('l' and 'o' appear twice), the maximum possible count of the word is constrained by how many full sets of required characters we can assemble.

# Approach
1. Initialize a frequency vector `count` of size 26 initialized to 0 to store the occurrence of each lowercase English letter.
2. Iterate through each character `ch` in `text` and increment its corresponding frequency index (`ch - 'a'`).
3. Determine the limiting frequency for the word "balloon" by taking the minimum of:
   - Frequency of 'b'
   - Frequency of 'a'
   - Frequency of 'l' divided by 2 (since each instance requires two 'l's)
   - Frequency of 'o' divided by 2 (since each instance requires two 'o's)
   - Frequency of 'n'
4. Return this minimum value as the maximum number of instances that can be formed.

### Visual Trace Walkthrough
For `text = "nlaebolko"`:
- Frequency counts: `b: 1`, `a: 1`, `l: 2`, `o: 2`, `n: 1`, `e: 1`, `k: 1`.
- Required divisors:
  - `count['b' - 'a']` = 1
  - `count['a' - 'a']` = 1
  - `count['l' - 'a'] / 2` = 2 / 2 = 1
  - `count['o' - 'a'] / 2` = 2 / 2 = 1
  - `count['n' - 'a']` = 1
- `min({1, 1, 1, 1, 1})` = 1

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the length of the string `text`. We iterate through the string once to populate the frequency array and perform a constant time minimum computation over fixed characters.
- Space complexity: $$O(1)$$ because the frequency vector `count` has a fixed size of 26, independent of the input string length.

# Code
```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
        for (char ch : text) {
            count[ch - 'a']++;
        }
        return min({
            count['b' - 'a'], 
            count['a' - 'a'], 
            count['l' - 'a'] / 2, 
            count['o' - 'a'] / 2, 
            count['n' - 'a']
        });
    }
};
```

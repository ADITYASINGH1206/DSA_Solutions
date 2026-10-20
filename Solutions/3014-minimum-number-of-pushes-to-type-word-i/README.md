# [3014. Minimum Number of Pushes to Type Word I](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`, `greedy`

---

## Problem Description
You are given a string `word` containing **distinct** lowercase English letters.

Telephone keypads have keys mapped with **distinct** collections of lowercase English letters, which can be used to form words by pushing them. For example, the key `2` is mapped with `["a","b","c"]`, we need to push the key one time to type `"a"`, two times to type `"b"`, and three times to type `"c"` *.*

It is allowed to remap the keys numbered `2` to `9` to **distinct** collections of letters. The keys can be remapped to **any** amount of letters, but each letter **must** be mapped to **exactly** one key. You need to find the **minimum** number of times the keys will be pushed to type the string `word`.

Return *the **minimum** number of pushes needed to type* `word` *after remapping the keys*.

An example mapping of letters to keys on a telephone keypad is given below. Note that `1`, `*`, `#`, and `0` do **not** map to any letters.

**Example 1:**

```
Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.
```

**Example 2:**

```
Input: word = "xycdefghij"
Output: 12
Explanation: The remapped keypad given in the image provides the minimum cost.
"x" -> one push on key 2
"y" -> two pushes on key 2
"c" -> one push on key 3
"d" -> two pushes on key 3
"e" -> one push on key 4
"f" -> one push on key 5
"g" -> one push on key 6
"h" -> one push on key 7
"i" -> one push on key 8
"j" -> one push on key 9
Total cost is 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12.
It can be shown that no other mapping can provide a lower cost.
```

**Constraints:**

* `1 <= word.length <= 26`
* `word` consists of lowercase English letters.
* All letters in `word` are distinct.

---

## Solution & Editorial
# Intuition
To minimize the total number of key presses, we must assign the most frequently used characters to the positions requiring the fewest presses. Since all characters in the input `word` are distinct, each character has an equal frequency of 1. Therefore, we greedily fill the keypad positions that require only 1 press first, then those requiring 2 presses, and so on.

# Approach
1. There are 8 available keys (2-9) on a standard telephone keypad.
2. We can assign 8 characters to the first position of each key (cost = 1 press each).
3. We can assign the next 8 characters to the second position of each key (cost = 2 presses each).
4. We continue this pattern for the third (cost = 3) and fourth (cost = 4) positions.
5. Iterate through the length of the string `n` and add the cost based on the index `i`:
   - If `i < 8`, add 1.
   - If `8 <= i < 16`, add 2.
   - If `16 <= i < 24`, add 3.
   - If `i >= 24`, add 4.

### Visual Trace (Example: word = "abcdefghi")
| Index (i) | Character | Cost | Total (ans) |
|-----------|-----------|------|-------------|
| 0-7       | a-h       | 1    | 8           |
| 8         | i         | 2    | 10          |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we iterate through the string once.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int minimumPushes(string word) {
        int n= word.size();
        int ans =0;
        for(int i=0;i<n;i++){
            if(i<8){
                ans++;
            }else if(i<16){
                ans+=2;
            }else if(i<24){
                ans+=3;
            }else{
                ans+=4;
            }
        }
        return ans;
    }
};
```

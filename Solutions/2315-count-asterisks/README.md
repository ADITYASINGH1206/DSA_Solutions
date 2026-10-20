# [2315. Count Asterisks](https://leetcode.com/problems/count-asterisks/)
**Difficulty:** `Easy` | **Tags:** `string`

---

## Problem Description
You are given a string `s`, where every **two** consecutive vertical bars `'|'` are grouped into a **pair**. In other words, the 1st and 2nd `'|'` make a pair, the 3rd and 4th `'|'` make a pair, and so forth.

Return *the number of* `'*'` *in* `s`*, **excluding** the* `'*'` *between each pair of* `'|'`.

**Note** that each `'|'` will belong to **exactly** one pair.

**Example 1:**

```
Input: s = "l|*e*et|c**o|*de|"
Output: 2
Explanation: The considered characters are underlined: "l|*e*et|c**o|*de|".
The characters between the first and second '|' are excluded from the answer.
Also, the characters between the third and fourth '|' are excluded from the answer.
There are 2 asterisks considered. Therefore, we return 2.
```

**Example 2:**

```
Input: s = "iamprogrammer"
Output: 0
Explanation: In this example, there are no asterisks in s. Therefore, we return 0.
```

**Example 3:**

```
Input: s = "yo|uar|e**|b|e***au|tifu|l"
Output: 5
Explanation: The considered characters are underlined: "yo|uar|e**|b|e***au|tifu|l". There are 5 asterisks considered. Therefore, we return 5.
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consists of lowercase English letters, vertical bars `'|'`, and asterisks `'*'`.
* `s` contains an **even** number of vertical bars `'|'`.

---

## Solution & Editorial
# Intuition
The problem requires us to count asterisks outside of vertical bar pairs. Since every two vertical bars form a closed pair, we can treat the state of being "inside" or "outside" a pair as a simple toggle based on the parity of the number of vertical bars encountered so far.

# Approach
1. Initialize a `counter` to track the number of vertical bars encountered and an `ans` variable to store the count of valid asterisks.
2. Iterate through each character `c` in the string `s`.
3. If `c` is a '|', increment the `counter`. This effectively toggles our state: even values of `counter` represent being "outside" a pair, while odd values represent being "inside".
4. If `c` is a '*' and the `counter` is even, it means we are currently outside any pair, so increment `ans`.

### Visual Trace (Example 1: "l|*e*et|c**o|*de|")
| Char | counter | State | ans |
| :--- | :--- | :--- | :--- |
| l | 0 | Outside | 0 |
| \| | 1 | Inside | 0 |
| * | 1 | Inside | 0 |
| e | 1 | Inside | 0 |
| * | 1 | Inside | 0 |
| e | 1 | Inside | 0 |
| t | 1 | Inside | 0 |
| \| | 2 | Outside | 0 |
| c | 2 | Outside | 1 |
| * | 2 | Outside | 2 |
| * | 2 | Outside | 2 |
| o | 2 | Outside | 2 |
| \| | 3 | Inside | 2 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string, as we perform a single linear scan.
- Space complexity: $$O(1)$$, as we only use two integer variables regardless of input size.

# Code
```cpp
class Solution {
public:
    int countAsterisks(string s) {
        int counter = 0;
        int ans =0;
        for(auto & c: s){
            if(c== '|') counter++;
            if(c == '*' && counter%2==0) ans++;
        }
        return ans;
    }
};
```

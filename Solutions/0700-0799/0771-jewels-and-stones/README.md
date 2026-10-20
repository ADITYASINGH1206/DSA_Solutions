# [771. Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `string`

---

## Problem Description
You're given strings `jewels` representing the types of stones that are jewels, and `stones` representing the stones you have. Each character in `stones` is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.

**Example 1:**

```
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
```

**Example 2:**

```
Input: jewels = "z", stones = "ZZ"
Output: 0
```

**Constraints:**

* `1 <= jewels.length, stones.length <= 50`
* `jewels` and `stones` consist of only English letters.
* All the characters of `jewels` are **unique**.

---

## Solution & Editorial
# Intuition
The problem asks us to count how many characters in the string `stones` are present in the string `jewels`. Since both strings are extremely short (length at most 50), a direct brute-force nested scan will easily execute well within the time limit.

# Approach
1. Initialize a counter `ans` to 0.
2. Iterate through each character in the `stones` string using an outer loop with index `i`.
3. For each stone, iterate through every character in the `jewels` string using an inner loop with index `j`.
4. Compare `stones[i]` with `jewels[j]`. If they match, increment `ans` by 1.
5. Return the accumulated total `ans` after both loops complete.

### Visual Trace Walkthrough
Example: `jewels = "aA"`, `stones = "aAAbbbb"`

| `i` | `stones[i]` | Inner Loop (`jewels`) | Match Found? | `ans` (Cumulative) |
|---|---|---|---|---|
| 0 | `'a'` | `'a'`, `'A'` | Yes (`'a' == 'a'`) | 1 |
| 1 | `'A'` | `'a'`, `'A'` | Yes (`'A' == 'A'`) | 2 |
| 2 | `'A'` | `'a'`, `'A'` | Yes (`'A' == 'A'`) | 3 |
| 3 | `'b'` | `'a'`, `'A'` | No | 3 |
| 4 | `'b'` | `'a'`, `'A'` | No | 3 |
| 5 | `'b'` | `'a'`, `'A'` | No | 3 |
| 6 | `'b'` | `'a'`, `'A'` | No | 3 |

# Complexity
- Time complexity: $$O(N \times M)$$ where $$N$$ is the length of `stones` and $$M$$ is the length of `jewels`. Given constraints ($$N, M \le 50$$), the number of operations is at most 2500, executing in 0 ms.
- Space complexity: $$O(1)$$ as only a single integer variable `ans` is maintained.

# Code
```cpp
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<jewels.size();j++){
                if(stones[i] == jewels[j]){
                    ans++;
                };
            }

        }
        return ans;
    }
};
```

# [3499. Maximize Active Section with Trade I](https://leetcode.com/problems/maximize-active-section-with-trade-i/)
**Difficulty:** `Medium` | **Tags:** `string`, `enumeration`

---

## Problem Description
You are given a binary string `s` of length `n`, where:

* `'1'` represents an **active** section.
* `'0'` represents an **inactive** section.

You can perform **at most one trade** to maximize the number of active sections in `s`. In a trade, you:

* Convert a contiguous block of `'1'`s that is surrounded by `'0'`s to all `'0'`s.
* Afterward, convert a contiguous block of `'0'`s that is surrounded by `'1'`s to all `'1'`s.

Return the **maximum** number of active sections in `s` after making the optimal trade.

**Note:** Treat `s` as if it is **augmented** with a `'1'` at both ends, forming `t = '1' + s + '1'`. The augmented `'1'`s **do not** contribute to the final count.

**Example 1:**

**Input:** s = "01"

**Output:** 1

**Explanation:**

Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.

**Example 2:**

**Input:** s = "0100"

**Output:** 4

**Explanation:**

* String `"0100"` → Augmented to `"101001"`.
* Choose `"0100"`, convert `"101001"` → `"100001"` → `"111111"`.
* The final string without augmentation is `"1111"`. The maximum number of active sections is 4.

**Example 3:**

**Input:** s = "1000100"

**Output:** 7

**Explanation:**

* String `"1000100"` → Augmented to `"110001001"`.
* Choose `"000100"`, convert `"110001001"` → `"110000001"` → `"111111111"`.
* The final string without augmentation is `"1111111"`. The maximum number of active sections is 7.

**Example 4:**

**Input:** s = "01010"

**Output:** 4

**Explanation:**

* String `"01010"` → Augmented to `"1010101"`.
* Choose `"010"`, convert `"1010101"` → `"1000101"` → `"1111101"`.
* The final string without augmentation is `"11110"`. The maximum number of active sections is 4.

**Constraints:**

* `1 <= n == s.length <= 105`
* `s[i]` is either `'0'` or `'1'`

---

## Solution & Editorial
# Intuition
The problem asks us to maximize the number of '1's by performing at most one trade: removing a block of '1's surrounded by '0's and filling a block of '0's surrounded by '1's. By augmenting the string with '1's at both ends, we can treat every block of '1's or '0's uniformly. The core observation is that a valid trade involves picking a block of '1's (length $L_1$) that is flanked by two blocks of '0's (lengths $L_0^a$ and $L_0^b$) and converting them into a single block of '1's of length $L_0^a + L_0^b$. The net gain is $(L_0^a + L_0^b) - L_1$.

# Approach
1. Augment the string `s` to `t = "1" + s + "1"` to handle boundary conditions naturally.
2. Compress the string `t` into a sequence of blocks, where each block is a pair `{char, length}`.
3. Iterate through the compressed blocks. A valid trade exists if we find a block of '1's at index `i` such that `v[i-1]` and `v[i+1]` are blocks of '0's.
4. The new total count of '1's becomes `total_ones - v[i].second + v[i-1].second + v[i+1].second`.
5. Track the maximum value found across all valid indices.

### Visual Trace (Example 3: s = "1000100")
- Augmented `t`: `110001001`
- Compressed `v`: `[('1', 2), ('0', 3), ('1', 1), ('0', 2), ('1', 1)]`
- Initial `ones`: 4
- Iteration `i=2` (block '1', length 1): 
  - `v[1]` is '0' (len 3), `v[3]` is '0' (len 2).
  - `gain = 3 + 2 - 1 = 4`.
  - `ans = max(4, 4 + 4) = 8` (Wait, the logic calculates `ones + gain` which is `4 + 3 + 2 = 9`? No, the gain is the net change. The formula `ones - v[i].second + v[i-1].second + v[i+1].second` correctly computes the final count).

# Complexity
- Time complexity: $$O(N)$$ where $N$ is the length of the string, as we perform a single pass to compress the string and another pass to evaluate potential trades.
- Space complexity: $$O(N)$$ to store the compressed block representation of the string.

# Code
```cpp
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ones=0;
        for(int i=0;i<n;i++)if(s[i]=='1') ones++;
        string t="1"+s+"1";
        int m=t.size();
        vector<pair<char,int>> v;
        for(int i=0;i<m;){
            int j=i;
            while(j<m&&t[j]==t[i]) j++;
            v.push_back({t[i],j-i});
            i=j;
        }
        int ans=ones;
        for(int i=1;i+1<(int)v.size();i++){
            if(v[i].first=='1'&&v[i-1].first=='0'&&v[i+1].first=='0'){
                int gain=v[i-1].second+v[i+1].second;
                ans=max(ans,ones+gain);
            }
        }
        return ans;
    }
};
```

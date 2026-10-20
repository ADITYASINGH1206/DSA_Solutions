# [3501. Maximize Active Section with Trade II](https://leetcode.com/problems/maximize-active-section-with-trade-ii/)
**Difficulty:** `Hard` | **Tags:** `array`, `string`, `binary-search`, `segment-tree`

---

## Problem Description
You are given a binary string `s` of length `n`, where:

* `'1'` represents an **active** section.
* `'0'` represents an **inactive** section.

You can perform **at most one trade** to maximize the number of active sections in `s`. In a trade, you:

* Convert a contiguous block of `'1'`s that is surrounded by `'0'`s to all `'0'`s.
* Afterward, convert a contiguous block of `'0'`s that is surrounded by `'1'`s to all `'1'`s.

Additionally, you are given a **2D array** `queries`, where `queries[i] = [li, ri]` represents a substring `s[li...ri]`.

For each query, determine the **maximum** possible number of active sections in `s` after making the optimal trade on the substring `s[li...ri]`.

Return an array `answer`, where `answer[i]` is the result for `queries[i]`.

**Note**

* For each query, treat `s[li...ri]` as if it is **augmented** with a `'1'` at both ends, forming `t = '1' + s[li...ri] + '1'`. The augmented `'1'`s **do not** contribute to the final count.
* The queries are independent of each other.

**Example 1:**

**Input:** s = "01", queries = [[0,1]]

**Output:** [1]

**Explanation:**

Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.

**Example 2:**

**Input:** s = "0100", queries = [[0,3],[0,2],[1,3],[2,3]]

**Output:** [4,3,1,1]

**Explanation:**

* Query `[0, 3]` → Substring `"0100"` → Augmented to `"101001"`  
  Choose `"0100"`, convert `"0100"` → `"0000"` → `"1111"`.  
  The final string without augmentation is `"1111"`. The maximum number of active sections is 4.
* Query `[0, 2]` → Substring `"010"` → Augmented to `"10101"`  
  Choose `"010"`, convert `"010"` → `"000"` → `"111"`.  
  The final string without augmentation is `"1110"`. The maximum number of active sections is 3.
* Query `[1, 3]` → Substring `"100"` → Augmented to `"11001"`  
  Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.
* Query `[2, 3]` → Substring `"00"` → Augmented to `"1001"`  
  Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.

**Example 3:**

**Input:** s = "1000100", queries = [[1,5],[0,6],[0,4]]

**Output:** [6,7,2]

**Explanation:**

* Query `[1, 5]` → Substring `"00010"` → Augmented to `"1000101"`  
  Choose `"00010"`, convert `"00010"` → `"00000"` → `"11111"`.  
  The final string without augmentation is `"1111110"`. The maximum number of active sections is 6.
* Query `[0, 6]` → Substring `"1000100"` → Augmented to `"110001001"`  
  Choose `"000100"`, convert `"000100"` → `"000000"` → `"111111"`.  
  The final string without augmentation is `"1111111"`. The maximum number of active sections is 7.
* Query `[0, 4]` → Substring `"10001"` → Augmented to `"1100011"`  
  Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 2.

**Example 4:**

**Input:** s = "01010", queries = [[0,3],[1,4],[1,3]]

**Output:** [4,4,2]

**Explanation:**

* Query `[0, 3]` → Substring `"0101"` → Augmented to `"101011"`  
  Choose `"010"`, convert `"010"` → `"000"` → `"111"`.  
  The final string without augmentation is `"11110"`. The maximum number of active sections is 4.
* Query `[1, 4]` → Substring `"1010"` → Augmented to `"110101"`  
  Choose `"010"`, convert `"010"` → `"000"` → `"111"`.  
  The final string without augmentation is `"01111"`. The maximum number of active sections is 4.
* Query `[1, 3]` → Substring `"101"` → Augmented to `"11011"`  
  Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 2.

**Constraints:**

* `1 <= n == s.length <= 105`
* `1 <= queries.length <= 105`
* `s[i]` is either `'0'` or `'1'`.
* `queries[i] = [li, ri]`
* `0 <= li <= ri < n`

---

## Solution & Editorial
# Intuition
The problem asks us to maximize active sections by performing at most one trade: converting a block of '1's surrounded by '0's into '0's, and a block of '0's surrounded by '1's into '1's. The net gain of such a trade is the sum of the lengths of the two adjacent '0' blocks that become '1's, minus the '1' block that becomes '0's. Since we want to maximize the total number of active sections, we essentially want to find the maximum possible gain within the query range [L, R].

# Approach
1. **Preprocessing**: We compress the string `s` into segments of identical characters. Each segment stores its type ('0' or '1'), start index, and end index.
2. **Gain Calculation**: For a block of '1's at index `i` (where `type[i] == 1`), the gain is `length(segment[i-1]) + length(segment[i+1]) - length(segment[i])`. However, the problem constraints imply we only care about the gain from the '0' blocks being converted. We precalculate the potential gain for every '1' block.
3. **Range Queries**: For a query [L, R], we identify the segments `segL` and `segR` that contain the boundaries. We check the gain for the '1' blocks immediately adjacent to the boundaries (handling partial segment lengths) and use a Sparse Table (RMQ) to query the maximum gain for all fully contained '1' blocks between `segL + 2` and `segR - 2`.

### Visual Trace (Example 2: s="0100", query=[0,3])
- Segments: `[(0,0,0), (1,1,1), (0,2,3)]`
- `total_ones` = 1
- Query [0,3] spans segments 0 to 2.
- Gain calculation considers segments between `segL` and `segR`.
- Result = `total_ones` + `max_gain`.

# Complexity
- Time complexity: $$O(N \log N + Q)$$, where $$N$$ is the number of segments (at most the length of string) and $$Q$$ is the number of queries. Sparse Table construction takes $$O(N \log N)$$, and each query is answered in $$O(1)$$.
- Space complexity: $$O(N \log N)$$ to store the Sparse Table.

```cpp []
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) if (c == '1') total_ones++;
        vector<int> type, start, end_idx;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            type.push_back(s[i] - '0');
            start.push_back(i);
            end_idx.push_back(j - 1);
            i = j;
        }
        int N = type.size();
        vector<int> pos_to_seg(n);
        for (int i = 0; i < N; i++) for (int j = start[i]; j <= end_idx[i]; j++) pos_to_seg[j] = i;
        vector<int> ans(N, 0);
        for (int i = 1; i < N - 1; i++) {
            if (type[i] == 1) ans[i] = (end_idx[i - 1] - start[i - 1] + 1) + (end_idx[i + 1] - start[i + 1] + 1);
        }
        vector<int> log_table(N + 1, 0);
        for (int i = 2; i <= N; i++) log_table[i] = log_table[i / 2] + 1;
        int K = log_table[N] + 1;
        vector<vector<int>> st(K, vector<int>(N, 0));
        for (int i = 0; i < N; i++) st[0][i] = ans[i];
        for (int j = 1; j < K; j++) for (int i = 0; i + (1 << j) <= N; i++) st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        auto queryRMQ = [&](int L_idx, int R_idx) {
            if (L_idx > R_idx) return 0;
            int j = log_table[R_idx - L_idx + 1];
            return max(st[j][L_idx], st[j][R_idx - (1 << j) + 1]);
        };
        auto eval = [&](int i, int L, int R, int segL, int segR) {
            if (i <= segL || i >= segR || type[i] == 0) return 0;
            int left_len = (i - 1 == segL) ? max(0, end_idx[i - 1] - L + 1) : (end_idx[i - 1] - start[i - 1] + 1);
            int right_len = (i + 1 == segR) ? max(0, R - start[i + 1] + 1) : (end_idx[i + 1] - start[i + 1] + 1);
            return left_len + right_len;
        };
        vector<int> res;
        for (const auto& q : queries) {
            int L = q[0], R = q[1], segL = pos_to_seg[L], segR = pos_to_seg[R];
            if (segR - segL < 2) { res.push_back(total_ones); continue; }
            int max_gain = max({eval(segL + 1, L, R, segL, segR), eval(segR - 1, L, R, segL, segR), (segL + 2 <= segR - 2) ? queryRMQ(segL + 2, segR - 2) : 0});
            res.push_back(total_ones + max_gain);
        }
        return res;
    }
};
```

# Code
```cpp
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }
        
        vector<int> type;
        vector<int> start;
        vector<int> end_idx;
        
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            type.push_back(s[i] - '0');
            start.push_back(i);
            end_idx.push_back(j - 1);
            i = j;
        }
        
        int N = type.size();
        
        vector<int> pos_to_seg(n);
        for (int i = 0; i < N; i++) {
            for (int j = start[i]; j <= end_idx[i]; j++) {
                pos_to_seg[j] = i; 
            }
        }
        
        vector<int> ans(N, 0);
        for (int i = 1; i < N - 1; i++) {
            if (type[i] == 1) {
                ans[i] = (end_idx[i - 1] - start[i - 1] + 1) + (end_idx[i + 1] - start[i + 1] + 1);
            }
        }
        
        vector<int> log_table(N + 1, 0);
        for (int i = 2; i <= N; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }
        
        int K = log_table[N] + 1;
        vector<vector<int>> st(K, vector<int>(N, 0));
        
        for (int i = 0; i < N; i++) {
            st[0][i] = ans[i];
        }
        
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= N; i++) {
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
        
        auto queryRMQ = [&](int L_idx, int R_idx) {
            if (L_idx > R_idx) return 0;
            int j = log_table[R_idx - L_idx + 1];
            return max(st[j][L_idx], st[j][R_idx - (1 << j) + 1]);
        };
        
        auto eval = [&](int i, int L, int R, int segL, int segR) {
            if (i <= segL || i >= segR) return 0;
            if (type[i] == 0) return 0;
            
            int left_len = 0;
            if (i - 1 == segL) left_len = max(0, end_idx[i - 1] - L + 1);
            else left_len = end_idx[i - 1] - start[i - 1] + 1;
            
            int right_len = 0;
            if (i + 1 == segR) right_len = max(0, R - start[i + 1] + 1);
            else right_len = end_idx[i + 1] - start[i + 1] + 1;
            
            return left_len + right_len;
        };
        
        vector<int> res;
        
        for (const auto& q : queries) {
            int L = q[0];
            int R = q[1];
            
            int segL = pos_to_seg[L];
            int segR = pos_to_seg[R];
            
            if (segR - segL < 2) {
                res.push_back(total_ones);
                continue;
            }
            
            int max_gain = 0;
            max_gain = max(max_gain, eval(segL + 1, L, R, segL, segR));
            max_gain = max(max_gain, eval(segR - 1, L, R, segL, segR));
            
            if (segL + 2 <= segR - 2) {
                max_gain = max(max_gain, queryRMQ(segL + 2, segR - 2));
            }
            
            res.push_back(total_ones + max_gain);
        }
        
        return res;
    }
};
```

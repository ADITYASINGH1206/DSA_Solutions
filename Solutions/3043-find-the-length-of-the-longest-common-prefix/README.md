# [3043. Find the Length of the Longest Common Prefix](https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `string`, `trie`

---

## Problem Description
You are given two arrays with **positive** integers `arr1` and `arr2`.

A **prefix** of a positive integer is an integer formed by one or more of its digits, starting from its **leftmost** digit. For example, `123` is a prefix of the integer `12345`, while `234` is **not**.

A **common prefix** of two integers `a` and `b` is an integer `c`, such that `c` is a prefix of both `a` and `b`. For example, `5655359` and `56554` have common prefixes `565` and `5655` while `1223` and `43456` **do not** have a common prefix.

You need to find the length of the **longest common prefix** between all pairs of integers `(x, y)` such that `x` belongs to `arr1` and `y` belongs to `arr2`.

Return *the length of the **longest** common prefix among all pairs*. *If no common prefix exists among them*, *return* `0`.

**Example 1:**

```
Input: arr1 = [1,10,100], arr2 = [1000]
Output: 3
Explanation: There are 3 pairs (arr1[i], arr2[j]):
- The longest common prefix of (1, 1000) is 1.
- The longest common prefix of (10, 1000) is 10.
- The longest common prefix of (100, 1000) is 100.
The longest common prefix is 100 with a length of 3.
```

**Example 2:**

```
Input: arr1 = [1,2,3], arr2 = [4,4,4]
Output: 0
Explanation: There exists no common prefix for any pair (arr1[i], arr2[j]), hence we return 0.
Note that common prefixes between elements of the same array do not count.
```

**Constraints:**

* `1 <= arr1.length, arr2.length <= 5 * 104`
* `1 <= arr1[i], arr2[i] <= 108`

---

## Solution & Editorial
# Intuition
To find the longest common prefix between any pair of integers from two arrays, we observe that every prefix of an integer is itself an integer. By decomposing every number in `arr1` into all its possible prefixes and storing them in a hash set, we can efficiently check if any prefix of a number in `arr2` exists in `arr1`.

# Approach
1. Initialize an `unordered_set<int>` named `s` to store all possible prefixes of every integer in `arr1`.
2. Iterate through each integer `x` in `arr1`. For each `x`, repeatedly divide by 10 to extract all prefixes (e.g., 123 -> 123, 12, 1) and insert them into `s`.
3. Initialize `ans = 0` to track the maximum length found.
4. Iterate through each integer `x` in `arr2`. For each `x`, check its prefixes starting from the longest (the number itself) down to the shortest.
5. If a prefix exists in `s`, calculate its length using `log10(x) + 1`, update `ans` with the maximum, and break the inner loop (since we want the longest prefix for this specific `x`).

### Visual Trace (Example 1: arr1 = [1, 10, 100], arr2 = [1000])
- **Step 1 (Populate Set):**
  - 1 -> {1}
  - 10 -> {10, 1}
  - 100 -> {100, 10, 1}
  - `s` = {1, 10, 100}
- **Step 2 (Query arr2):**
  - x = 1000: 
    - Check 1000 (not in `s`)
    - Check 100 (in `s`!): `ans = max(0, 3) = 3`

# Complexity
- Time complexity: $$O(N \cdot D + M \cdot D)$$, where $$N$$ and $$M$$ are the lengths of `arr1` and `arr2`, and $$D$$ is the maximum number of digits (at most 9 for $10^8$). Each number is processed in constant time relative to its digits.
- Space complexity: $$O(N \cdot D)$$ to store all prefixes of `arr1` in the hash set.

# Code
```cpp
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for (int x : arr1) {
            for (; x; x /= 10) {
                s.insert(x);
            }
        }
        int ans = 0;
        for (int x : arr2) {
            for (; x; x /= 10) {
                if (s.count(x)) {
                    ans = max(ans, (int) log10(x) + 1);
                    break;
                }
            }
        }
        return ans;
    }
};
```

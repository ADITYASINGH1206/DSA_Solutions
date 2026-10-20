# [2085. Count Common Words With One Occurrence](https://leetcode.com/problems/count-common-words-with-one-occurrence/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `string`, `counting`

---

## Problem Description
Given two string arrays `words1` and `words2`, return *the number of strings that appear **exactly once** in **each** of the two arrays.*

**Example 1:**

```
Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
Output: 2
Explanation:
- "leetcode" appears exactly once in each of the two arrays. We count this string.
- "amazing" appears exactly once in each of the two arrays. We count this string.
- "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
- "as" appears once in words1, but does not appear in words2. We do not count this string.
Thus, there are 2 strings that appear exactly once in each of the two arrays.
```

**Example 2:**

```
Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
Output: 0
Explanation: There are no strings that appear in each of the two arrays.
```

**Example 3:**

```
Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
Output: 1
Explanation: The only string that appears exactly once in each of the two arrays is "ab".
```

**Constraints:**

* `1 <= words1.length, words2.length <= 1000`
* `1 <= words1[i].length, words2[j].length <= 30`
* `words1[i]` and `words2[j]` consists only of lowercase English letters.

---

## Solution & Editorial
# Intuition
To identify strings that appear exactly once in both arrays, we need to track the frequency of every string in each array independently. A hash map (unordered_map) is the ideal data structure for this, as it allows for average O(1) insertion and lookup.

# Approach
1. Initialize two hash maps, `mp1` and `mp2`, to store the frequency counts of strings in `words1` and `words2` respectively.
2. Iterate through `words1` and populate `mp1` by incrementing the count for each string.
3. Iterate through `words2` and populate `mp2` by incrementing the count for each string.
4. Iterate through the entries of `mp1`. For each `word` with a frequency of exactly 1, check if the same `word` exists in `mp2` with a frequency of exactly 1.
5. Maintain a counter `ans` and increment it whenever both conditions are met.

### Visual Trace (Example 1)
`words1 = ["leetcode", "is", "amazing", "as", "is"]`
`words2 = ["amazing", "leetcode", "is"]`

| Word | mp1 count | mp2 count | Condition (c1==1 && c2==1) |
| :--- | :--- | :--- | :--- |
| leetcode | 1 | 1 | True (Count++) |
| is | 2 | 1 | False |
| amazing | 1 | 1 | True (Count++) |
| as | 1 | 0 | False |

# Complexity
- Time complexity: $$O(N + M)$$, where $$N$$ and $$M$$ are the lengths of `words1` and `words2`. We perform two linear passes to build the maps and one pass over the unique keys of `mp1`.
- Space complexity: $$O(N + M)$$ to store the frequency counts of all unique strings in both arrays within the hash maps.

# Code
```cpp
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        
        for (const string& s : words1) mp1[s]++;
        for (const string& s : words2) mp2[s]++;

        int ans = 0;

        for (auto const& [word, count] : mp1) {
            if (count == 1 && mp2[word] == 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
```

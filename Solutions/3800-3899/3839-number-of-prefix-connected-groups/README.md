# [3839. Number of Prefix Connected Groups](https://leetcode.com/problems/number-of-prefix-connected-groups/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `string`, `counting`

---

## Problem Description
You are given an array of strings `words` and an integer `k`.

Two words `a` and `b` at **distinct indices** are **prefix-connected** if `a[0..k-1] == b[0..k-1]`.

A **connected group** is a set of words such that each pair of words is prefix-connected.

Return the **number of connected groups** that contain **at least** two words, formed from the given words.

**Note:**

* Words with length less than `k` cannot join any group and are ignored.
* Duplicate strings are treated as separate words.

**Example 1:**

**Input:** words = ["apple","apply","banana","bandit"], k = 2

**Output:** 2

**Explanation:**

Words sharing the same first `k = 2` letters are grouped together:

* `words[0] = "apple"` and `words[1] = "apply"` share prefix `"ap"`.
* `words[2] = "banana"` and `words[3] = "bandit"` share prefix `"ba"`.

Thus, there are 2 connected groups, each containing at least two words.

**Example 2:**

**Input:** words = ["car","cat","cartoon"], k = 3

**Output:** 1

**Explanation:**

Words are evaluated for a prefix of length `k = 3`:

* `words[0] = "car"` and `words[2] = "cartoon"` share prefix `"car"`.
* `words[1] = "cat"` does not share a 3-length prefix with any other word.

Thus, there is 1 connected group.

**Example 3:**

**Input:** words = ["bat","dog","dog","doggy","bat"], k = 3

**Output:** 2

**Explanation:**

Words are evaluated for a prefix of length `k = 3`:

* `words[0] = "bat"` and `words[4] = "bat"` form a group.
* `words[1] = "dog"`, `words[2] = "dog"` and `words[3] = "doggy"` share prefix `"dog"`.

Thus, there are 2 connected groups, each containing at least two words.

**Constraints:**

* `1 <= words.length <= 5000`
* `1 <= words[i].length <= 100`
* `1 <= k <= 100`
* All strings in `words` consist of lowercase English letters.

---

## Solution & Editorial
# Intuition
The problem asks us to identify groups of words that share the same prefix of length `k`. Since a "connected group" is defined by this shared prefix, we can treat the prefix of length `k` as a unique identifier (key) for each group. By counting the occurrences of each valid prefix, we can easily determine which prefixes represent groups containing at least two words.

# Approach
1. Initialize an `unordered_map<string, int>` named `prefixCounts` to store the frequency of each prefix of length `k`.
2. Iterate through each `word` in the input `words` array:
   - Check if `word.length() >= k`. If it is shorter, ignore it as per the problem constraints.
   - Extract the prefix using `word.substr(0, k)`.
   - Increment the count for this prefix in `prefixCounts`.
3. After populating the map, iterate through the `prefixCounts` map. For every entry where the count is greater than or equal to 2, increment a `groupCount` variable.
4. Return `groupCount`.

### Visual Trace (Example 1: words = ["apple", "apply", "banana", "bandit"], k = 2)
| Word | Length >= 2? | Prefix | Map State (prefix: count) |
| :--- | :--- | :--- | :--- |
| apple | Yes | "ap" | {"ap": 1} |
| apply | Yes | "ap" | {"ap": 2} |
| banana | Yes | "ba" | {"ap": 2, "ba": 1} |
| bandit | Yes | "ba" | {"ap": 2, "ba": 2} |

Final count: Both "ap" and "ba" have counts >= 2. Result = 2.

# Complexity
- Time complexity: $$O(N \cdot K)$$, where $$N$$ is the number of words and $$K$$ is the length of the prefix. We iterate through each word once and perform a substring operation and map insertion, both taking $$O(K)$$ time.
- Space complexity: $$O(N \cdot K)$$, as we store up to $$N$$ prefixes of length $$K$$ in the hash map.

# Code
```cpp
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> prefixCounts;
        for(const string& word : words) {
            if(word.length() >= k) {
                string prefix = word.substr(0, k);
                prefixCounts[prefix]++;
            }
        }
        int groupCount = 0;
        for(auto it : prefixCounts) {
            if(it.second >= 2) {
                groupCount++;
            }
        }
        
        return groupCount;
    }
};
```

# [2900. Longest Unequal Adjacent Groups Subsequence I](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`, `dynamic-programming`, `greedy`

---

## Problem Description
You are given a string array `words` and a **binary** array `groups` both of length `n`.

A subsequence of `words` is **alternating** if for any two *consecutive* strings in the sequence, their corresponding elements at the *same* indices in `groups` are **different** (that is, there *cannot* be consecutive 0 or 1).

Your task is to select the **longest alternating** subsequence from `words`.

Return *the selected subsequence. If there are multiple answers, return **any** of them.*

**Note:** The elements in `words` are distinct.

**Example 1:**

**Input:** words = ["e","a","b"], groups = [0,0,1]

**Output:** ["e","b"]

**Explanation:** A subsequence that can be selected is `["e","b"]` because `groups[0] != groups[2]`. Another subsequence that can be selected is `["a","b"]` because `groups[1] != groups[2]`. It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is `2`.

**Example 2:**

**Input:** words = ["a","b","c","d"], groups = [1,0,1,1]

**Output:** ["a","b","c"]

**Explanation:** A subsequence that can be selected is `["a","b","c"]` because `groups[0] != groups[1]` and `groups[1] != groups[2]`. Another subsequence that can be selected is `["a","b","d"]` because `groups[0] != groups[1]` and `groups[1] != groups[3]`. It can be shown that the length of the longest subsequence of indices that satisfies the condition is `3`.

**Constraints:**

* `1 <= n == words.length == groups.length <= 100`
* `1 <= words[i].length <= 10`
* `groups[i]` is either `0` or `1.`
* `words` consists of **distinct** strings.
* `words[i]` consists of lowercase English letters.

---

## Solution & Editorial
# Intuition
To construct the longest alternating subsequence, we observe that we must pick elements such that the `groups` values alternate between 0 and 1. Since we want the longest possible sequence, we can greedily include any element that differs from the group of the previously selected element.

# Approach
1. Initialize a result vector `ans` and add the first word (`words[0]`) to it, as the first element is always part of the longest subsequence.
2. Maintain a pointer or reference to the group of the last added element. In this implementation, we compare the current element's group `groups[i]` with the previous element's group `groups[i-1]`.
3. Iterate through the `words` array starting from index 1. If `groups[i]` is different from `groups[i-1]`, it implies we have found a valid transition in our alternating sequence, so we append `words[i]` to `ans`.
4. This greedy strategy works because picking every valid transition ensures we capture the maximum number of alternating elements.

### Visual Trace (Example 2: words = ["a","b","c","d"], groups = [1,0,1,1])
| Index | Word | Group | Action | Result (ans) |
| :--- | :--- | :--- | :--- | :--- |
| 0 | "a" | 1 | Add (Initial) | ["a"] |
| 1 | "b" | 0 | 0 != 1 (Add) | ["a", "b"] |
| 2 | "c" | 1 | 1 != 0 (Add) | ["a", "b", "c"] |
| 3 | "d" | 1 | 1 == 1 (Skip) | ["a", "b", "c"] |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input arrays. We perform a single linear scan through the input.
- Space complexity: $$O(N)$$ in the worst case to store the resulting subsequence, where all elements might be included.

# Code
```cpp
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i = 1;i<n;i++){
            if(groups[i] != groups[i-1]){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
```

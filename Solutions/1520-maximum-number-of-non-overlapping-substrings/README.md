# [1520. Maximum Number of Non-Overlapping Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)
**Difficulty:** `Hard` | **Tags:** `hash-table`, `string`, `greedy`, `sorting`

---

## Problem Description
Given a string `s` of lowercase letters, you need to find the maximum number of **non-empty** substrings of `s` that meet the following conditions:

1. The substrings do not overlap, that is for any two substrings `s[i..j]` and `s[x..y]`, either `j < x` or `i > y` is true.
2. A substring that contains a certain character `c` must also contain all occurrences of `c`.

Find *the maximum number of substrings that meet the above conditions*. If there are multiple solutions with the same number of substrings, *return the one with minimum total length.* It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in **any** order.

**Example 1:**

```
Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
```

**Example 2:**

```
Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
```

**Constraints:**

* `1 <= s.length <= 105`
* `s` contains only lowercase English letters.

---

## Solution & Editorial
# Intuition
To satisfy the condition that a substring containing character 'c' must contain all occurrences of 'c', we first identify the range `[first[c], last[c]]` for every character present in the string. Any valid substring starting at `first[c]` must at least span to `last[c]`. If this range contains other characters, their ranges must also be fully included, potentially expanding the substring boundaries. This is a classic interval merging problem where we seek the smallest valid intervals to maximize the count.

# Approach
1. **Preprocessing**: Calculate the `first` and `last` occurrence indices for each character 'a'-'z'. Store the order of first appearances to process potential substrings greedily.
2. **Interval Expansion**: For each character, treat its range `[first[c], last[c]]` as a seed. Iterate through the string within this range; if any character encountered has an occurrence outside the current `[left, right]` boundary, expand the boundary to include that character's full range.
3. **Greedy Selection**: Maintain a `deque` of candidate intervals. If an interval is "valid" (i.e., the sum of character counts equals the length of the range `right - left + 1`), it is a minimal valid substring. Once a valid substring is found, clear the queue to ensure non-overlapping constraints.

### Visual Trace (Example: "abbaccd")
- `first`: {a:0, b:1, c:4, d:6}, `last`: {a:3, b:2, c:5, d:6}
- Processing 'a': Range [0, 3]. Contains 'b' (range [1, 2]). Total range [0, 3].
- Processing 'd': Range [6, 6]. Valid.
- Processing 'c': Range [4, 5]. Valid.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the string. We iterate through the string to find bounds and then process each character's range. The expansion logic ensures each character is visited a constant number of times.
- Space complexity: $$O(1)$$, as we only store arrays of size 26 for character bounds and counts, regardless of input size.

# Code
```cpp
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int count[26] = {};
        int first[26], last[26];

        fill(first, first + 26, -1);
        fill(last, last + 26, -1);

        vector<int> order;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (count[c] == 0) {
                first[c] = i;
                order.push_back(c);
            }

            count[c]++;
            last[c] = i;
        }

        vector<string> res;
        deque<array<int, 3>> queue;

        for (int c : order) {
            queue.push_front({first[c], last[c], count[c]});

            int left = INT_MAX;
            int right = INT_MIN;
            int total = 0;

            for (auto& item : queue) {
                total += item[2];
                left = min(left, item[0]);
                right = max(right, item[1]);

                if (total == right - left + 1) {
                    break;
                }
            }

            if (total == right - left + 1) {
                res.push_back(s.substr(left, right - left + 1));
                queue.clear();
            }
        }

        return res;
    }
};
```

# [506. Relative Ranks](https://leetcode.com/problems/relative-ranks/)
**Difficulty:** `Easy` | **Tags:** `array`, `sorting`, `heap-priority-queue`

---

## Problem Description
You are given an integer array `score` of size `n`, where `score[i]` is the score of the `ith` athlete in a competition. All the scores are guaranteed to be **unique**.

The athletes are **placed** based on their scores, where the `1st` place athlete has the highest score, the `2nd` place athlete has the `2nd` highest score, and so on. The placement of each athlete determines their rank:

* The `1st` place athlete's rank is `"Gold Medal"`.
* The `2nd` place athlete's rank is `"Silver Medal"`.
* The `3rd` place athlete's rank is `"Bronze Medal"`.
* For the `4th` place to the `nth` place athlete, their rank is their placement number (i.e., the `xth` place athlete's rank is `"x"`).

Return an array `answer` of size `n` where `answer[i]` is the **rank** of the `ith` athlete.

**Example 1:**

```
Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
```

**Example 2:**

```
Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
```

**Constraints:**

* `n == score.length`
* `1 <= n <= 104`
* `0 <= score[i] <= 106`
* All the values in `score` are **unique**.

---

## Solution & Editorial
# Intuition
The problem requires us to assign ranks to athletes based on their unique scores. Since ranks depend on the relative ordering of scores from highest to lowest, sorting the scores in descending order allows us to easily map each score to its corresponding rank ("Gold Medal", "Silver Medal", "Bronze Medal", or the numeric rank string).

# Approach
1. Copy the original `score` vector into `sortedScore` and sort it in descending order using `rbegin()` and `rend()`.
2. Initialize an `unordered_map<int, string>` named `rankMap` to associate each score with its rank.
3. Iterate through `sortedScore` from index `0` to `n - 1`. Map the first three elements to "Gold Medal", "Silver Medal", and "Bronze Medal" respectively, and map all subsequent elements to their 1-based rank string using `to_string(i + 1)`.
4. Construct the final answer vector `ans` by iterating through the original `score` array and looking up each athlete's rank in `rankMap`.
5. Return `ans`.

### Visual Walkthrough (Example 1)
Input: `score = [5, 4, 3, 2, 1]`
- `sortedScore` after descending sort: `[5, 4, 3, 2, 1]`
- `rankMap` mapping:
  - `i = 0` (score `5`): `"Gold Medal"`
  - `i = 1` (score `4`): `"Silver Medal"`
  - `i = 2` (score `3`): `"Bronze Medal"`
  - `i = 3` (score `2`): `"4"`
  - `i = 4` (score `1`): `"5"`
- Result generation using original `score`: `["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]`

# Complexity
- Time complexity: $$O(N \log N)$$ — Sorting the `sortedScore` array of size $$N$$ takes $$O(N \log N)$$ time. Populating and querying the hash map takes $$O(N)$$ average time.
- Space complexity: $$O(N)$$ — The auxiliary space is used by `sortedScore`, `rankMap`, and the `ans` vector, each scaling linearly with the number of elements $$N$$.

# Code
```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore = score;
        sort(sortedScore.rbegin(), sortedScore.rend());
        unordered_map<int, string> rankMap;
        
        for(int i = 0; i < sortedScore.size(); i++) {
            if (i == 0) {
                rankMap[sortedScore[i]] = "Gold Medal";
            } else if (i == 1) {
                rankMap[sortedScore[i]] = "Silver Medal";
            } else if (i == 2) {
                rankMap[sortedScore[i]] = "Bronze Medal";
            } else {
                rankMap[sortedScore[i]] = to_string(i + 1);
            }
        }
        vector<string> ans;
        for(int i = 0; i < score.size(); i++) {
            ans.push_back(rankMap[score[i]]);
        }
        
        return ans;
    }
};
```

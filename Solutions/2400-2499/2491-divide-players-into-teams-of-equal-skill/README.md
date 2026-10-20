# [2491. Divide Players Into Teams of Equal Skill](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/)
**Difficulty:** `Medium` | **Tags:** `array`, `hash-table`, `two-pointers`, `sorting`

---

## Problem Description
You are given a positive integer array `skill` of **even** length `n` where `skill[i]` denotes the skill of the `ith` player. Divide the players into `n / 2` teams of size `2` such that the total skill of each team is **equal**.

The **chemistry** of a team is equal to the **product** of the skills of the players on that team.

Return *the sum of the **chemistry** of all the teams, or return* `-1` *if there is no way to divide the players into teams such that the total skill of each team is equal.*

**Example 1:**

```
Input: skill = [3,2,5,1,3,4]
Output: 22
Explanation: 
Divide the players into the following teams: (1, 5), (2, 4), (3, 3), where each team has a total skill of 6.
The sum of the chemistry of all the teams is: 1 * 5 + 2 * 4 + 3 * 3 = 5 + 8 + 9 = 22.
```

**Example 2:**

```
Input: skill = [3,4]
Output: 12
Explanation: 
The two players form a team with a total skill of 7.
The chemistry of the team is 3 * 4 = 12.
```

**Example 3:**

```
Input: skill = [1,1,2,3]
Output: -1
Explanation: 
There is no way to divide the players into teams such that the total skill of each team is equal.
```

**Constraints:**

* `2 <= skill.length <= 105`
* `skill.length` is even.
* `1 <= skill[i] <= 1000`

---

## Solution & Editorial
# Intuition
To divide players into teams with equal total skill, the sum of all skills must be divisible by the number of teams ($n/2$). By sorting the skill array, we can pair the smallest skill with the largest skill to maintain a constant sum across all pairs. If any pair fails to match the target sum, a valid division is impossible.

# Approach
1. Sort the `skill` array in non-decreasing order.
2. Calculate the target sum using the first and last elements: `flag = skill[0] + skill[n-1]`.
3. Use two pointers, `i` at the start and `j` at the end, to iterate through the array.
4. In each step, check if `skill[i] + skill[j]` equals `flag`. If it does, add the product `skill[i] * skill[j]` to the total `ans`. If not, return `-1`.
5. Continue until `i >= j` and return the accumulated `ans`.

### Visual Trace (Example 1: [3, 2, 5, 1, 3, 4])
Sorted: `[1, 2, 3, 3, 4, 5]`. Target `flag = 1 + 5 = 6`.

| Iteration | i | j | skill[i] | skill[j] | sum | Chemistry | ans |
|-----------|---|---|----------|----------|-----|-----------|-----|
| 1         | 0 | 5 | 1        | 5        | 6   | 5         | 5   |
| 2         | 1 | 4 | 2        | 4        | 6   | 8         | 13  |
| 3         | 2 | 3 | 3        | 3        | 6   | 9         | 22  |

# Complexity
- Time complexity: $$O(N \log N)$$ due to the sorting step, where $$N$$ is the number of players. The two-pointer traversal is $$O(N)$$.
- Space complexity: $$O(1)$$ (or $$O(\log N)$$ depending on the sorting implementation's stack usage), as we only use a few integer variables.

# Code
```cpp
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long ans = 0;
        sort(skill.begin(), skill.end());

        int i = 0, j = n - 1;
        int flag = (skill[i] + skill[j]);

        while (i < j) {
            int sum = skill[i] + skill[j];

            if (flag == sum) {
                ans += skill[i] * skill[j];
            } else
                return -1;
            i++;
            j--;
        }
        return ans;
    }
};
```

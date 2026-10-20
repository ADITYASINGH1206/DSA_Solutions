# [1688. Count of Matches in Tournament](https://leetcode.com/problems/count-of-matches-in-tournament/)
**Difficulty:** `Easy` | **Tags:** `math`, `simulation`

---

## Problem Description
You are given an integer `n`, the number of teams in a tournament that has strange rules:

* If the current number of teams is **even**, each team gets paired with another team. A total of `n / 2` matches are played, and `n / 2` teams advance to the next round.
* If the current number of teams is **odd**, one team randomly advances in the tournament, and the rest gets paired. A total of `(n - 1) / 2` matches are played, and `(n - 1) / 2 + 1` teams advance to the next round.

Return *the number of matches played in the tournament until a winner is decided.*

**Example 1:**

```
Input: n = 7
Output: 6
Explanation: Details of the tournament: 
- 1st Round: Teams = 7, Matches = 3, and 4 teams advance.
- 2nd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 3rd Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 3 + 2 + 1 = 6.
```

**Example 2:**

```
Input: n = 14
Output: 13
Explanation: Details of the tournament:
- 1st Round: Teams = 14, Matches = 7, and 7 teams advance.
- 2nd Round: Teams = 7, Matches = 3, and 4 teams advance.
- 3rd Round: Teams = 4, Matches = 2, and 2 teams advance.
- 4th Round: Teams = 2, Matches = 1, and 1 team is declared the winner.
Total number of matches = 7 + 3 + 2 + 1 = 13.
```

**Constraints:**

* `1 <= n <= 200`

---

## Solution & Editorial
# Intuition
In a tournament where every match eliminates exactly one team, the total number of matches required to determine a single winner from $n$ teams is always $n - 1$. This is because each match results in one loser who is eliminated, and we must eliminate $n - 1$ teams to leave only one winner.

# Approach
1. We use a simulation approach to track the number of teams (`num`) and the total matches played (`ans`).
2. While `num > 1`, we check if the current number of teams is even or odd.
3. If even, we add `num / 2` to `ans` and update `num` to `num / 2`.
4. If odd, we add `(num - 1) / 2` to `ans` and update `num` to `(num - 1) / 2 + 1`.
5. The process terminates when `num == 1`.

### Visual Trace (n = 7)
| Round | Teams (num) | Matches (num/2) | Next Teams (num/2 + 1 if odd) | Total Matches (ans) |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 7 | 3 | 4 | 3 |
| 2 | 4 | 2 | 2 | 5 |
| 3 | 2 | 1 | 1 | 6 |

# Complexity
- Time complexity: $$O(\log n)$$ — In each round, the number of teams is roughly halved, leading to logarithmic iterations.
- Space complexity: $$O(1)$$ — We only use a few integer variables to maintain the state.

# Code
```cpp
class Solution {
public:
    void helper(int& num,int& ans){
        while(num != 1){
            if(num%2 ==0){
                ans += num/2;
                num = num/2;
            }else{
                ans += num/2;
                num = num/2 +1;
            }
        }
    }
    int numberOfMatches(int n) {
        int ans = 0;
        helper(n,ans);
        return ans;
    }
};
```

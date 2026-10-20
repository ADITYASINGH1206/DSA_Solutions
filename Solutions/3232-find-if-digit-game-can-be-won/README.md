# [3232. Find if Digit Game Can Be Won](https://leetcode.com/problems/find-if-digit-game-can-be-won/)
**Difficulty:** `Easy` | **Tags:** `array`, `math`

---

## Problem Description
You are given an array of **positive** integers `nums`.

Alice and Bob are playing a game. In the game, Alice can choose **either** all single-digit numbers or all double-digit numbers from `nums`, and the rest of the numbers are given to Bob. Alice wins if the sum of her numbers is **strictly greater** than the sum of Bob's numbers.

Return `true` if Alice can win this game, otherwise, return `false`.

**Example 1:**

**Input:** nums = [1,2,3,4,10]

**Output:** false

**Explanation:**

Alice cannot win by choosing either single-digit or double-digit numbers.

**Example 2:**

**Input:** nums = [1,2,3,4,5,14]

**Output:** true

**Explanation:**

Alice can win by choosing single-digit numbers which have a sum equal to 15.

**Example 3:**

**Input:** nums = [5,5,5,25]

**Output:** true

**Explanation:**

Alice can win by choosing double-digit numbers which have a sum equal to 25.

**Constraints:**

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 99`

---

## Solution & Editorial
# Intuition
Alice wins if she can choose a subset of numbers (either all single-digit or all double-digit) such that the sum of her chosen numbers is strictly greater than the sum of the remaining numbers. Since the total sum of the array is constant, this is equivalent to checking if the sum of single-digit numbers is not equal to the sum of double-digit numbers.

# Approach
1. Initialize two variables, `alice` (to store the sum of single-digit numbers) and `bob` (to store the sum of double-digit numbers).
2. Iterate through the `nums` array. For each number `num`:
   - If `num / 10 > 0` (meaning it is a double-digit number), add it to `bob`.
   - Otherwise, add it to `alice`.
3. After the loop, Alice wins if `alice != bob`. If `alice > bob`, she wins by choosing single-digit numbers. If `bob > alice`, she wins by choosing double-digit numbers (since the remaining sum for Bob would be `alice`, and `bob > alice`).

### Visual Trace (Example 2: [1, 2, 3, 4, 5, 14])
| Iteration | num | alice | bob |
|-----------|-----|-------|-----|
| 1         | 1   | 1     | 0   |
| 2         | 2   | 3     | 0   |
| 3         | 3   | 6     | 0   |
| 4         | 4   | 10    | 0   |
| 5         | 5   | 15    | 0   |
| 6         | 14  | 15    | 14  |

Result: 15 != 14, returns `true`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of the input array, as we iterate through the array exactly once.
- Space complexity: $$O(1)$$, as we only use two integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int alice = 0;
        int bob = 0;
        for(int num : nums){
            if(num/10) bob += num;
            else alice += num;
        }
        return alice != bob;
    }
};
```

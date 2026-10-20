# [2678. Number of Senior Citizens](https://leetcode.com/problems/number-of-senior-citizens/)
**Difficulty:** `Easy` | **Tags:** `array`, `string`

---

## Problem Description
You are given a **0-indexed** array of strings `details`. Each element of `details` provides information about a given passenger compressed into a string of length `15`. The system is such that:

* The first ten characters consist of the phone number of passengers.
* The next character denotes the gender of the person.
* The following two characters are used to indicate the age of the person.
* The last two characters determine the seat allotted to that person.

Return *the number of passengers who are **strictly** **more than 60 years old**.*

**Example 1:**

```
Input: details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
Output: 2
Explanation: The passengers at indices 0, 1, and 2 have ages 75, 92, and 40. Thus, there are 2 people who are over 60 years old.
```

**Example 2:**

```
Input: details = ["1313579440F2036","2921522980M5644"]
Output: 0
Explanation: None of the passengers are older than 60.
```

**Constraints:**

* `1 <= details.length <= 100`
* `details[i].length == 15`
* `details[i] consists of digits from '0' to '9'.`
* `details[i][10] is either 'M' or 'F' or 'O'.`
* The phone numbers and seat numbers of the passengers are distinct.

---

## Solution & Editorial
# Intuition
Each passenger's information is stored in a fixed-format string of length 15. Since the age is always located at indices 11 and 12, we can extract the age directly without complex parsing or regex, allowing for an efficient linear scan.

# Approach
1. Initialize a counter `ans` to 0.
2. Iterate through each string `pas` in the `details` vector.
3. Extract the age by converting the characters at `pas[11]` and `pas[12]` into an integer: `(pas[11] - '0') * 10 + (pas[12] - '0')`.
4. If the calculated `age` is strictly greater than 60, increment `ans`.
5. Return `ans` after processing all strings.

### Visual Trace (Example 1)
`details = ["...M7522", "...F9211", "...O4010"]`

| Index | String | Age (Indices 11, 12) | > 60? | `ans` |
| :--- | :--- | :--- | :--- | :--- |
| 0 | "...M7522" | 75 | Yes | 1 |
| 1 | "...F9211" | 92 | Yes | 2 |
| 2 | "...O4010" | 40 | No | 2 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of strings in `details`. We perform a constant number of operations for each string.
- Space complexity: $$O(1)$$, as we only use a few integer variables regardless of the input size.

# Code
```cpp
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string pas : details){
            int age = 0;
            age += (pas[11] - '0')*10;
            age += (pas[12] - '0');
            if(age > 60){
                ans++;
            }
        }
        return ans;
    }
};
```

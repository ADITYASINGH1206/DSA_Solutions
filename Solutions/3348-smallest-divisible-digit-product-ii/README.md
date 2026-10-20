# [3348. Smallest Divisible Digit Product II](https://leetcode.com/problems/smallest-divisible-digit-product-ii/)
**Difficulty:** `Hard` | **Tags:** `math`, `string`, `backtracking`, `greedy`, `number-theory`

---

## Problem Description
You are given a string `num` which represents a **positive** integer, and an integer `t`.

A number is called **zero-free** if *none* of its digits are 0.

Return a string representing the **smallest** **zero-free** number greater than or equal to `num` such that the **product of its digits** is divisible by `t`. If no such number exists, return `"-1"`.

**Example 1:**

**Input:** num = "1234", t = 256

**Output:** "1488"

**Explanation:**

The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.

**Example 2:**

**Input:** num = "12355", t = 50

**Output:** "12355"

**Explanation:**

12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.

**Example 3:**

**Input:** num = "11111", t = 26

**Output:** "-1"

**Explanation:**

No number greater than 11111 has the product of its digits divisible by 26.

**Constraints:**

* `2 <= num.length <= 2 * 105`
* `num` consists only of digits in the range `['0', '9']`.
* `num` does not contain leading zeros.
* `1 <= t <= 1014`

---

## Solution & Editorial
# Intuition
To find the smallest zero-free number greater than or equal to `num` whose digit product is divisible by `t`, we first decompose `t` into its prime factors (2, 3, 5, 7). If `t` contains any prime factor greater than 7, it is impossible to form such a number, and we return "-1". The problem then becomes a constrained search: we want to match the prefix of `num` as closely as possible while ensuring the remaining digits can satisfy the remaining prime factor requirements.

# Approach
1. **Prime Factorization**: Decompose `t` into counts of 2, 3, 5, and 7. If any prime factor > 7 remains, return "-1".
2. **Greedy Prefix Matching**: Iterate through `num` to find the longest prefix that is zero-free. Maintain the current required prime factors. If we encounter a '0', we must increment the prefix to break the zero constraint.
3. **Backtracking/Search**: If the current prefix doesn't satisfy the product requirement, we backtrack from the last digit of the prefix, incrementing it and checking if the remaining length is sufficient to accommodate the remaining prime factors using `getMinLength`.
4. **Suffix Construction**: Once a valid prefix is found, fill the remaining positions greedily with the largest possible digits (9, 8, etc.) to satisfy the prime requirements, filling any leftover spots with '1' to keep the number as small as possible.

### Visual Trace (Example 1: num="1234", t=256)
| Step | Prefix | Remaining Primes (2,3,5,7) | Action |
| :--- | :--- | :--- | :--- |
| 1 | "1" | (8, 0, 0, 0) | Match '1' |
| 2 | "12" | (7, 0, 0, 0) | Match '2' |
| 3 | "123" | (7, 0, 0, 0) | Match '3' |
| 4 | "1234" | (5, 0, 0, 0) | Match '4' |
| 5 | Backtrack | (8, 0, 0, 0) | Increment '4' to '8' |
| 6 | Result | (0, 0, 0, 0) | Fill '1488' |

# Complexity
- Time complexity: $$O(L \cdot \log(t))$$ where $$L$$ is the length of `num`. The backtracking depth is limited by the length of the string, and each step involves constant-time prime factor updates.
- Space complexity: $$O(L)$$ to store the result string and the prime factor counts.

# Code
```cpp
class Solution {
public:
    vector<int> primes = {2, 3, 5, 7};
    int maxPrime = 7;

    string smallestNumber(string num, long long t) {

        vector<int> primeCount(maxPrime + 1, 0);

        int numLength = num.length();
        int firstZeroIndexFromLeft = 0;

        for (int prime : primes) {
            while (t % prime == 0) {
                t /= prime;
                primeCount[prime]++;
            }
        }

        if (t != 1)
            return "-1";

        int minLength = getMinLength(primeCount);

        if (numLength < minLength) {
            string result(minLength, '0');
            return buildSuffix(primeCount, minLength, result);
        }

        string result(numLength + 1, '0');

        int i = 0;
        while (firstZeroIndexFromLeft < numLength) {

            result[++i] = num[firstZeroIndexFromLeft];

            if (result[i] == '0')
                break;

            logNum(primeCount, result[i], -1);
            firstZeroIndexFromLeft++;
        }

        if (getMinLength(primeCount) == 0) {

            if (firstZeroIndexFromLeft == numLength)
                return num;

            firstZeroIndexFromLeft++;

            for (int j = firstZeroIndexFromLeft; j < result.size(); j++)
                result[j] = '1';

            return result.substr(1, numLength);
        }

        int last = numLength - 1;

        for (int end = min(firstZeroIndexFromLeft, last); end >= 0; end--) {

            logNum(primeCount, result[end + 1], 1);

            while (++result[end + 1] <= '9') {

                logNum(primeCount, result[end + 1], -1);

                if (getMinLength(primeCount) <= last - end) {
                    return buildSuffix(primeCount, last - end, result);
                }

                logNum(primeCount, result[end + 1], 1);
            }
        }

        return buildSuffix(primeCount, result.length(), result);
    }

private:

    void logNum(vector<int>& primeCount, char num, int value) {

        if (num < '2')
            return;

        if (num == '9') {

            primeCount[3] += value * 2;

        } else if (num == '4') {

            primeCount[2] += value * 2;

        } else if (num == '8') {

            primeCount[2] += value * 3;

        } else if (num == '6') {

            primeCount[2] += value;
            primeCount[3] += value;

        } else {

            primeCount[num - '0'] += value;
        }
    }

    string buildSuffix(vector<int> primeCount,
                       int targetLength,
                       string result) {

        int index = result.length();

        while (primeCount[3] > 1) {
            primeCount[3] -= 2;
            result[--index] = '9';
        }

        while (primeCount[2] > 2) {
            primeCount[2] -= 3;
            result[--index] = '8';
        }

        while (primeCount[7]-- > 0)
            result[--index] = '7';

        if (primeCount[2] > 0 && primeCount[3] > 0) {

            result[--index] = '6';

            primeCount[2]--;
            primeCount[3]--;
        }

        while (primeCount[5]-- > 0)
            result[--index] = '5';

        while (primeCount[2] > 1) {

            primeCount[2] -= 2;
            result[--index] = '4';
        }

        while (primeCount[3] > 0) {

            primeCount[3]--;
            result[--index] = '3';
        }

        while (primeCount[2] > 0) {

            primeCount[2]--;
            result[--index] = '2';
        }

        while (index + targetLength != result.length())
            result[--index] = '1';

        if (targetLength == result.length())
            return result;

        return result.substr(1);
    }

    int getMinLength(vector<int>& primeCount) {

        int count2 = max(0, primeCount[2]);
        int count3 = max(0, primeCount[3]);

        int count23 = (count3 & 1) + (count2 % 3);

        return (count3 / 2)
                + (count2 / 3)
                + max(0, primeCount[7])
                + max(0, primeCount[5])
                + (count23 == 3 ? 2 : (count23 > 0 ? 1 : 0));
    }
};
```

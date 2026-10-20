# [412. Fizz Buzz](https://leetcode.com/problems/fizz-buzz/)
**Difficulty:** `Easy` | **Tags:** `math`, `string`, `simulation`

---

## Problem Description
Given an integer `n`, return *a string array* `answer` *(**1-indexed**) where*:

* `answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
* `answer[i] == "Fizz"` if `i` is divisible by `3`.
* `answer[i] == "Buzz"` if `i` is divisible by `5`.
* `answer[i] == i` (as a string) if none of the above conditions are true.

**Example 1:**

```
Input: n = 3
Output: ["1","2","Fizz"]
```

**Example 2:**

```
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
```

**Example 3:**

```
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
```

**Constraints:**

* `1 <= n <= 104`

---

## Solution & Editorial
# Intuition
The problem requires us to generate a sequence of strings from $1$ to $n$ based on divisibility rules for $3$ and $5$. We can directly simulate this process by iterating from $1$ to $n$, checking the modulo conditions at each step, and constructing the corresponding string response.

# Approach
1. Initialize a vector of strings named `ans` to store the result.
2. Iterate a loop variable `i` from $1$ to $n$ inclusive.
3. Inside the loop, check if `i` is divisible by both $3$ and $5$ using `i % 3 == 0 && i % 5 == 0`. If true, append `"FizzBuzz"` to `ans`.
4. Check if `i` is divisible by $3$ using `i % 3 == 0`. If true, append `"Fizz"`.
5. Check if `i` is divisible by $5$ using `i % 5 == 0`. If true, append `"Buzz"`.
6. If none of the conditions match, convert `i` to a string using `to_string(i)` and append it to `ans`.
7. Return the completed `ans` vector.

### Visual Walkthrough for $n = 5$

| `i` | `i % 3 == 0` | `i % 5 == 0` | Condition Met | Appended Value | `ans` state |
|---|---|---|---|---|---|
| 1 | False | False | None | `"1"` | `["1"]` |
| 2 | False | False | None | `"2"` | `["1", "2"]` |
| 3 | True | False | `i % 3 == 0` | `"Fizz"` | `["1", "2", "Fizz"]` |
| 4 | False | False | None | `"4"` | `["1", "2", "Fizz", "4"]` |
| 5 | False | True | `i % 5 == 0` | `"Buzz"` | `["1", "2", "Fizz", "4", "Buzz"]` |

# Complexity
- Time complexity: $$O(n)$$ — We iterate from $1$ to $n$ exactly once, performing constant time $$O(1)$$ arithmetic and conditional checks at each step.
- Space complexity: $$O(1)$$ auxiliary space — The output vector `ans` requires $$O(n)$$ space to store the result as requested by the problem signature, but auxiliary storage beyond the output array is $$O(1)$$.

# Code
```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i =1;i<=n;i++){
            if(i%3 ==0 && i%5==0){
                ans.push_back("FizzBuzz");
            }
            else if(i%3 ==0){
                ans.push_back("Fizz");
            }
            else if(i%5 ==0){
                ans.push_back("Buzz");
            }
            else{
                ans.push_back(to_string(i));
            } 
        }
        return ans;
    }
};
```

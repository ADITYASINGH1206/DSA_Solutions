# [860. Lemonade Change](https://leetcode.com/problems/lemonade-change/)
**Difficulty:** `Easy` | **Tags:** `array`, `greedy`

---

## Problem Description
At a lemonade stand, each lemonade costs `$5`. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a `$5`, `$10`, or `$20` bill. You must provide the correct change to each customer so that the net transaction is that the customer pays `$5`.

Note that you do not have any change in hand at first.

Given an integer array `bills` where `bills[i]` is the bill the `ith` customer pays, return `true` *if you can provide every customer with the correct change, or* `false` *otherwise*.

**Example 1:**

```
Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
```

**Example 2:**

```
Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
```

**Constraints:**

* `1 <= bills.length <= 105`
* `bills[i]` is either `5`, `10`, or `20`.

---

## Solution & Editorial
# Intuition
The problem requires us to verify if we can provide exact change for every customer sequentially. Since a lemonade costs $5 and customers pay with either $5, $10, or $20, we always want to preserve our smaller bills ($5) because they are more versatile for making change than $10 bills. This optimal substructure allows a greedy approach to always prioritize larger bills when giving $15 change ($20 bill).

# Approach
1. Maintain two integer counters, `fives` and `tens`, to track the current inventory of $5 and $10 bills respectively. We do not need to track $20 bills because they cannot be used as change for any other bill.
2. Iterate through each bill in the `bills` array using a standard `for` loop:
   - If `bills[i] == 5`, we increment `fives++`.
   - If `bills[i] == 10`, we need to give $5 back. We check if `fives > 0`. If so, we decrement `fives` and increment `tens`. Otherwise, we return `false`.
   - If `bills[i] == 20`, we need to give $15 back. Greedily, we prefer to give one $10 bill and one $5 bill first (since $10 bills can only be used for $20 change). If that combination is unavailable, we fall back to using three $5 bills (`fives >= 3`). If neither option is possible, we return `false`.
3. If the loop completes successfully for all customers, return `true`.

### Visual Trace Walkthrough (Example 1: `bills = [5, 5, 5, 10, 20]`)

| Index `i` | `bills[i]` | Action | `fives` | `tens` | Status |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 0 | 5 | `fives++` | 1 | 0 | Valid |
| 1 | 5 | `fives++` | 2 | 0 | Valid |
| 2 | 5 | `fives++` | 3 | 0 | Valid |
| 3 | 10 | `fives--`, `tens++` | 2 | 1 | Valid |
| 4 | 20 | `fives--`, `tens--` | 1 | 0 | Valid |

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of elements in the `bills` array. We make a single pass through the array with constant time $$O(1)$$ operations per customer.
- Space complexity: $$O(1)$$ auxiliary space since we only use two integer variables (`fives` and `tens`) regardless of input size.

# Code
```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0,tens = 0;
        int n = bills.size();
        for(int i = 0 ;i < n;i++){
            if(bills[i] == 5){
                fives++;
            }else if(bills[i] == 10){
                if(fives){
                    fives--;
                    tens++;
                }else{
                    return false;
                }
            }else{
                if(fives && tens){
                    fives--;
                    tens--;
                }else if(fives >= 3){
                    fives -= 3;
                }else {
                    return false;
                }
            }
        }





        return true;
    }
};
```

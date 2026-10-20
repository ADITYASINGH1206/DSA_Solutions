# [2094. Finding 3-Digit Even Numbers](https://leetcode.com/problems/finding-3-digit-even-numbers/)
**Difficulty:** `Easy` | **Tags:** `array`, `hash-table`, `recursion`, `sorting`, `enumeration`

---

## Problem Description
You are given an integer array `digits`, where each element is a digit. The array may contain duplicates.

You need to find **all** the **unique** integers that follow the given requirements:

* The integer consists of the **concatenation** of **three** elements from `digits` in **any** arbitrary order.
* The integer does not have **leading zeros**.
* The integer is **even**.

For example, if the given `digits` were `[1, 2, 3]`, integers `132` and `312` follow the requirements.

Return *a **sorted** array of the unique integers.*

**Example 1:**

```
Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.
```

**Example 2:**

```
Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882.
```

**Example 3:**

```
Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.
```

**Constraints:**

* `3 <= digits.length <= 100`
* `0 <= digits[i] <= 9`

---

## Solution & Editorial
# Intuition
Since we are only looking for 3-digit numbers, the search space is extremely small (100 to 999). Instead of generating permutations, we can iterate through all possible even 3-digit numbers and verify if each can be formed using the available digits.

# Approach
1. Count the frequency of each digit (0-9) present in the input `digits` array using a frequency array `count` of size 10.
2. Iterate through all even integers from 100 to 998.
3. For each integer `i`, extract its digits: `hundreds`, `tens`, and `ones`.
4. Temporarily decrement the frequency of these three digits in the `count` array.
5. If all three counts remain non-negative, the number `i` can be formed using the available digits. Add it to the `ans` vector.
6. Restore the `count` array by incrementing the frequencies back to their original state to prepare for the next iteration.

### Visual Trace (Example: digits = [2, 1, 3, 0])
- Initial `count`: {0:1, 1:1, 2:1, 3:1, others:0}
- Check 102: `ones=2`, `tens=0`, `hundreds=1`. All counts >= 0. Add 102.
- Check 104: `ones=4`. `count[4]` becomes -1. Skip.

# Complexity
- Time complexity: $$O(1)$$. We iterate through a fixed range of 450 numbers (100 to 998), and for each, we perform constant-time digit extraction and frequency checks.
- Space complexity: $$O(1)$$. The frequency array is of fixed size 10, and the output vector stores at most 450 integers.

# Code
```cpp
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for(int d : digits){
            count[d]++; 
        }
        vector<int> ans;
        for(int i = 100; i <= 998; i += 2){
            int ones = i % 10;
            int tens = (i / 10) % 10;
            int hundreds = i / 100;
            count[ones]--;
            count[tens]--;
            count[hundreds]--;
            if(count[ones] >= 0 && count[tens] >= 0 && count[hundreds] >= 0){
                ans.push_back(i);
            }
            count[ones]++;
            count[tens]++;
            count[hundreds]++;
        }
        
        return ans;
    }
};


// class Solution {
// public:
//     void recurse(int size, int num, vector<int>& digits, vector<bool>& visited, set<int>& uniqueAns) {
//         if(size == 3){
//             if(num % 2 == 0){
//                 uniqueAns.insert(num); 
//             }
//             return;
//         }

//         for(int i = 0; i < digits.size(); i++){
//             if(visited[i]) continue;
//             if(size == 0 && digits[i] == 0) continue;
//             visited[i] = true;
//             recurse(size + 1, num * 10 + digits[i], digits, visited, uniqueAns);
//             visited[i] = false;
//         }
//     }
    
//     vector<int> findEvenNumbers(vector<int>& digits) {
//         set<int> uniqueAns;
//         vector<bool> visited(digits.size(), false);
//         recurse(0, 0, digits, visited, uniqueAns);
//         return vector<int>(uniqueAns.begin(), uniqueAns.end());
//     }
// };
```

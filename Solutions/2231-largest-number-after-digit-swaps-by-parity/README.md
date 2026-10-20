# [2231. Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)
**Difficulty:** `Easy` | **Tags:** `sorting`, `heap-priority-queue`

---

## Problem Description
You are given a positive integer `num`. You may swap any two digits of `num` that have the same **parity** (i.e. both odd digits or both even digits).

Return *the **largest** possible value of* `num` *after **any** number of swaps.*

**Example 1:**

```
Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
```

**Example 2:**

```
Input: num = 65875
Output: 87655
Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
```

**Constraints:**

* `1 <= num <= 109`

---

## Solution & Editorial
# Intuition
Since we can swap any two digits of the same parity, we can effectively reorder all even digits among themselves and all odd digits among themselves. To maximize the resulting number, we should place the largest available digits of each parity into the most significant positions possible.

# Approach
1. Convert the integer `num` to a string to iterate through its digits. Use two max-priority queues: `pq1` for even digits and `pq2` for odd digits.
2. Extract all digits from `num` using modulo arithmetic and push them into the corresponding priority queue based on their parity.
3. Iterate through the original string representation of `num`. For each position, check the parity of the original digit at that index. If it was even, replace it with the largest available even digit from `pq1`; otherwise, replace it with the largest available odd digit from `pq2`.
4. Construct the resulting string and convert it back to an integer.

### Visual Trace (num = 1234)
- Initial digits: {1, 2, 3, 4}
- `pq1` (even): [4, 2], `pq2` (odd): [3, 1]
- Iteration:
  - Index 0 ('1', odd): Pop from `pq2` -> '3'. Result: "3"
  - Index 1 ('2', even): Pop from `pq1` -> '4'. Result: "34"
  - Index 2 ('3', odd): Pop from `pq2` -> '1'. Result: "341"
  - Index 3 ('4', even): Pop from `pq1` -> '2'. Result: "3412"

# Complexity
- Time complexity: $$O(N \log N)$$, where $$N$$ is the number of digits. We perform $$N$$ insertions and $$N$$ extractions from priority queues, each taking logarithmic time.
- Space complexity: $$O(N)$$, required to store the digits in the priority queues and the string representation of the number.

# Code
```cpp
class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>pq1;
        priority_queue<int>pq2;
        int n = num;
        while(n>0){
            int d = n%10;
            if(d%2==0) pq1.push(d);
            else pq2.push(d);
            n=n/10;
        }
        string s = to_string(num);
        string ans;
        for(int i=0;i<s.size();i++){
            if((s[i]-'0')%2==0) {
                ans+=char(pq1.top() + '0');;
                pq1.pop();
            }
            else{
                ans+=char(pq2.top() + '0');
                pq2.pop();
            }
        } 
        return stoi(ans);
    }
};
```

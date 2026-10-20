# [946. Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `simulation`

---

## Problem Description
Given two integer arrays `pushed` and `popped` each with distinct values, return `true` *if this could have been the result of a sequence of push and pop operations on an initially empty stack, or* `false` *otherwise.*

**Example 1:**

```
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```

**Example 2:**

```
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
```

**Constraints:**

* `1 <= pushed.length <= 1000`
* `0 <= pushed[i] <= 1000`
* All the elements of `pushed` are **unique**.
* `popped.length == pushed.length`
* `popped` is a permutation of `pushed`.

---

## Solution & Editorial
# Intuition
The problem asks whether a given sequence of `pushed` elements can yield a specific `popped` sequence through standard stack operations. Since each element is unique, the optimal strategy is greedy: we should always push elements from the `pushed` array until the top of our auxiliary stack matches the current target in the `popped` array. If we cannot match and have exhausted the `pushed` array, the sequence is invalid.

# Approach
1. Initialize an empty stack `stk` and two pointers `l` and `r` to track our progress in `pushed` and `popped` respectively.
2. Iterate while either pointer has not reached the end of their respective arrays ($l < n$ or $r < n$).
3. If `stk` is empty and we still have elements to push ($l < n$), push `pushed[l]` onto `stk` and increment `l`.
4. If the top of `stk` equals `popped[r]`, pop from `stk` and increment `r` to match the next element in the popped sequence.
5. Otherwise, if we can still push more elements ($l < n$), push `pushed[l]` and increment `l`. If we cannot push any more elements and the top does not match `popped[r]`, return `false`.
6. If the loop completes successfully without contradiction, return `true`.

### Visual Trace Walkthrough (Example 1)
`pushed = [1, 2, 3, 4, 5]`, `popped = [4, 5, 3, 2, 1]`

| Iteration | l | r | Stack (Bottom -> Top) | Action | Explanation |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 0 | 0 | [] | Push `pushed[0]` | Stack empty, push `1` ($l 	o 1$) |
| 2 | 1 | 0 | [1] | Push `pushed[1]` | Top ($1$) $
eq$ `popped[0]` ($4$), push `2` ($l 	o 2$) |
| 3 | 2 | 0 | [1, 2] | Push `pushed[2]` | Top ($2$) $
eq$ `popped[0]` ($4$), push `3` ($l 	o 3$) |
| 4 | 3 | 0 | [1, 2, 3] | Push `pushed[3]` | Top ($3$) $
eq$ `popped[0]` ($4$), push `4` ($l 	o 4$) |
| 5 | 4 | 0 | [1, 2, 3, 4] | Pop, $r 	o 1$ | Top ($4$) == `popped[0]` ($4$), pop `4` |
| 6 | 4 | 1 | [1, 2, 3, 5] | Push `pushed[4]` | Top ($3$) $
eq$ `popped[1]` ($5$), push `5` ($l 	o 5$) |
| 7 | 5 | 1 | [1, 2, 3] | Pop, $r 	o 2$ | Top ($5$) == `popped[1]` ($5$), pop `5` |
| 8 | 5 | 2 | [1, 2] | Pop, $r 	o 3$ | Top ($3$) == `popped[2]` ($3$), pop `3` |
| 9 | 5 | 3 | [1] | Pop, $r 	o 4$ | Top ($2$) == `popped[3]` ($2$), pop `2` |
| 10 | 5 | 4 | [] | Pop, $r 	o 5$ | Top ($1$) == `popped[4]` ($1$), pop `1` |

# Complexity
- Time complexity: $$O(N)$$ — Each element from `pushed` is pushed onto the stack exactly once and popped from the stack at most once, resulting in linear time complexity relative to array size $N$.
- Space complexity: $$O(N)$$ — In the worst-case scenario (e.g., all elements are pushed before any are popped), the auxiliary stack holds up to $N$ elements.

# Code
```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> stk;
        int l = 0;
        int r = 0;
        while(r<n || l<n){
            if(stk.empty() && l<n){
                stk.push(pushed[l]);
                l++;
            }
            if(!stk.empty()){
                if(stk.top() == popped[r]){
                    stk.pop();
                    r++;
                }
                else{
                    if(l<n){
                        stk.push(pushed[l]);
                        l++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
```

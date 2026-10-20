# [1441. Build an Array With Stack Operations](https://leetcode.com/problems/build-an-array-with-stack-operations/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `simulation`

---

## Problem Description
You are given an integer array `target` and an integer `n`.

You have an empty stack with the two following operations:

* **`"Push"`**: pushes an integer to the top of the stack.
* **`"Pop"`**: removes the integer on the top of the stack.

You also have a stream of the integers in the range `[1, n]`.

Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to `target`. You should follow the following rules:

* If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
* If the stack is not empty, pop the integer at the top of the stack.
* If, at any moment, the elements in the stack (from the bottom to the top) are equal to `target`, do not read new integers from the stream and do not do more operations on the stack.

Return *the stack operations needed to build* `target` following the mentioned rules. If there are multiple valid answers, return **any of them**.

**Example 1:**

```
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Pop the integer on the top of the stack. s = [1].
Read 3 from the stream and push it to the stack. s = [1,3].
```

**Example 2:**

```
Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Read 3 from the stream and push it to the stack. s = [1,2,3].
```

**Example 3:**

```
Input: target = [1,2], n = 4
Output: ["Push","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Since the stack (from the bottom to the top) is equal to target, we stop the stack operations.
The answers that read integer 3 from the stream are not accepted.
```

**Constraints:**

* `1 <= target.length <= 100`
* `1 <= n <= 100`
* `1 <= target[i] <= n`
* `target` is strictly increasing.

---

## Solution & Editorial
# Intuition
The problem asks us to simulate stack operations to match a given `target` array using a stream of integers from `1` to `n`. Since the `target` array is strictly increasing, we can iterate through the stream and decide for each number whether it belongs in the final stack. If a number from the stream is not the one we currently need for the `target`, we must push it and immediately pop it to move to the next number in the stream.

# Approach
1. We use a pointer `index` to track which element of `target` we are currently trying to match and a variable `cur` to represent the current number from the stream.
2. We initialize the process by pushing the first stream element `1` into a stack `stk` and recording the `"Push"` operation.
3. We enter a loop that continues until all elements in `target` are matched (`index < size`).
4. Inside the loop, we check if the current top of the stack matches `target[index]`:
   - If it does **not** match, it means the current number is a "skipped" number. We perform a `"Pop"`, increment `cur` to get the next stream value, push it, and record `"Push"`.
   - If it **does** match, we increment `index` to move to the next target element.
5. After matching an element, if there are still more elements to find in `target`, we increment `cur`, push the next stream value, and record `"Push"` to prepare for the next iteration.
6. The loop terminates early if `index` reaches the size of the `target` array, ensuring we don't process unnecessary numbers from the stream.

### Visual Trace (Example 1)
**Input:** `target = [1, 3]`, `n = 3`  
**Initial State:** `cur = 1`, `index = 0`, `stk = [1]`, `ans = ["Push"]`  

| Step | `stk.top()` | `target[index]` | Action | `stk` State | `ans` | `index` | `cur` |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | 1 | 1 | Match! | `[1]` | `["Push"]` | 1 | 1 |
| 2 | - | - | Prepare next | `[1, 2]` | `[..., "Push"]` | 1 | 2 |
| 3 | 2 | 3 | No Match | `[1]` (Pop 2) | `[..., "Pop"]` | 1 | 2 |
| 4 | - | - | Push next | `[1, 3]` | `[..., "Push"]` | 1 | 3 |
| 5 | 3 | 3 | Match! | `[1, 3]` | `[..., "Push"]` | 2 | 3 |
| 6 | - | - | `index == size` | **Exit** | - | 2 | 3 |

# Complexity
- Time complexity: $$O(N)$$
Each number from the stream (up to the last element in `target`) is pushed onto the stack exactly once and popped at most once. Since the maximum value in the stream we consider is $N$ (where $N = \text{target.back()}$), the complexity is linear relative to the values in the stream.

- Space complexity: $$O(N)$$
We use a stack to store elements (though only the top is strictly necessary) and a vector to store the sequence of operations. In the worst case, the number of operations is $2 \times (\text{target.back()} - \text{target.length}) + \text{target.length}$.

# Code
```cpp
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int size = target.size();
        stack<int> stk;
        vector<string> ans;
        int cur = 1;
        int index = 0;
        
        stk.push(1);
        ans.push_back("Push");
        
        while(index < size){
            while(stk.top() != target[index]){
                stk.pop();
                ans.push_back("Pop");
                cur++;
                stk.push(cur);
                ans.push_back("Push");
            }
            index++;
            if(index == size) break;
            cur++; 
            stk.push(cur);
            ans.push_back("Push");
        }

        return ans;
    }
};
```

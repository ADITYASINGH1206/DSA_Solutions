# [3834. Merge Adjacent Equal Elements](https://leetcode.com/problems/merge-adjacent-equal-elements/)
**Difficulty:** `Medium` | **Tags:** `array`, `stack`, `simulation`

---

## Problem Description
You are given an integer array `nums`.

You must **repeatedly** apply the following merge operation until no more changes can be made:

* If any **two adjacent elements are equal**, choose the **leftmost** such adjacent pair in the current array and replace them with a single element equal to their **sum**.

After each merge operation, the array size **decreases** by 1. Repeat the process on the updated array until no more changes can be made.

Return the final array after all possible merge operations.

**Example 1:**

**Input:** nums = [3,1,1,2]

**Output:** [3,4]

**Explanation:**

* The middle two elements are equal and merged into `1 + 1 = 2`, resulting in `[3, 2, 2]`.
* The last two elements are equal and merged into `2 + 2 = 4`, resulting in `[3, 4]`.
* No adjacent equal elements remain. Thus, the answer is `[3, 4]`.

**Example 2:**

**Input:** nums = [2,2,4]

**Output:** [8]

**Explanation:**

* The first two elements are equal and merged into `2 + 2 = 4`, resulting in `[4, 4]`.
* The first two elements are equal and merged into `4 + 4 = 8`, resulting in `[8]`.

**Example 3:**

**Input:** nums = [3,7,5]

**Output:** [3,7,5]

**Explanation:**

There are no adjacent equal elements in the array, so no operations are performed.

**Constraints:**

* `1 <= nums.length <= 105`
* `1 <= nums[i] <= 105`​​​​​​​

---

## Solution & Editorial
# Intuition
The problem requires us to repeatedly merge adjacent equal elements. Since a merge operation can create new adjacent equal pairs (e.g., [1, 1, 2] -> [2, 2] -> [4]), we need a data structure that allows efficient access to the most recently added elements. A stack is ideal here because it naturally maintains the "current" state of the array and allows us to check the last element against the new incoming element in constant time.

# Approach
1. Initialize an empty stack (represented by a `vector<long long>`).
2. Iterate through each element `i` in the input `nums`.
3. Push the current element onto the stack.
4. While the stack contains at least two elements and the top two elements are equal:
   - Pop the top two elements.
   - Calculate their sum (which is simply `2 * top_element`).
   - Push the sum back onto the stack.
5. This process ensures that we always resolve merges greedily from left to right as elements are processed.

### Visual Trace (Example 1: [3, 1, 1, 2])
| Step | Input | Stack State | Action |
| :--- | :--- | :--- | :--- |
| 1 | 3 | [3] | Push 3 |
| 2 | 1 | [3, 1] | Push 1 |
| 3 | 1 | [3, 2] | Merge 1+1=2, Push 2 |
| 4 | 2 | [3, 4] | Merge 2+2=4, Push 4 |

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the length of `nums`. Each element is pushed onto the stack exactly once and popped at most once.
- Space complexity: $$O(N)$$ to store the elements in the stack in the worst case (when no merges occur).

# Code
```cpp
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<int> copy = nums;
        vector<long long> ans;
        for(int i: copy){
            ans.push_back((long long)i);
            while(ans.size() >=2 && ans.back() == ans[ans.size()-2]){
                long long newval = 2*ans.back();   
                ans.pop_back();
                ans.pop_back();
                ans.push_back(newval);
            }
        }

        return ans;
    }
};
```

# [1019. Next Greater Node In Linked List](https://leetcode.com/problems/next-greater-node-in-linked-list/)
**Difficulty:** `Medium` | **Tags:** `array`, `linked-list`, `stack`, `monotonic-stack`

---

## Problem Description
You are given the `head` of a linked list with `n` nodes.

For each node in the list, find the value of the **next greater node**. That is, for each node, find the value of the first node that is next to it and has a **strictly larger** value than it.

Return an integer array `answer` where `answer[i]` is the value of the next greater node of the `ith` node (**1-indexed**). If the `ith` node does not have a next greater node, set `answer[i] = 0`.

**Example 1:**

```
Input: head = [2,1,5]
Output: [5,5,0]
```

**Example 2:**

```
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
```

**Constraints:**

* The number of nodes in the list is `n`.
* `1 <= n <= 104`
* `1 <= Node.val <= 109`

---

## Solution & Editorial
# Intuition
To efficiently find the next greater node for each element in a singly linked list, random access is required. Since linked lists only allow unidirectional traversal, we can first linearize the linked list values into an array, and then apply a Monotonic Stack from right to left to solve the classical Next Greater Element problem.

# Approach
1. Traverse the linked list using a pointer `temp` and store each node's value sequentially in a vector `nums`. This allows index-based random access.
2. Initialize an empty stack `stk` to maintain a monotonic decreasing sequence of values from right to left, and an `ans` vector.
3. Iterate backward through `nums` from index `n - 1` down to `0`:
   - While `stk` is not empty and the top element is less than or equal to the current element `nums[i]`, pop elements from `stk` because they cannot be the next greater element for any preceding nodes.
   - If `stk` is empty, push `0` to `ans` (indicating no greater element exists).
   - Otherwise, push `stk.top()` to `ans`.
   - Push the current element `nums[i]` onto `stk`.
4. Since we process elements from right to left, reverse the `ans` vector to align with the original left-to-right order of the linked list.
5. Return `ans`.

### Visual Walkthrough (Example 1: head = [2, 1, 5])
- **Step 1 (Linearization):** `nums = [2, 1, 5]`, `n = 3`
- **Step 2 (Backward Monotonic Stack Traversal):**
  - `i = 2`, `nums[2] = 5`: `stk` is empty $ightarrow$ `ans.push_back(0)`, push `5` to `stk`. (`stk` = `[5]`, `ans` = `[0]`)
  - `i = 1`, `nums[1] = 1`: `stk.top()` is `5` ($> 1$) $ightarrow$ `ans.push_back(5)`, push `1` to `stk`. (`stk` = `[5, 1]`, `ans` = `[0, 5]`)
  - `i = 0`, `nums[0] = 2`: `stk.top()` is `1` ($\le 2$) $ightarrow$ pop `1`. Next top is `5` ($> 2$) $ightarrow$ `ans.push_back(5)`, push `2` to `stk`. (`stk` = `[5, 2]`, `ans` = `[0, 5, 5]`)
- **Step 3 (Reversal):** Reverse `ans` `[0, 5, 5]` $ightarrow$ `[5, 5, 0]`.

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. Traversing the linked list takes $$O(N)$$ time, and each element is pushed and popped from the monotonic stack at most once, taking $$O(N)$$ time for the backward pass. Reversing the result array takes $$O(N)$$ time.
- Space complexity: $$O(N)$$ due to the storage needed for the `nums` array, the `ans` vector, and the monotonic stack `stk` of maximum size $$N$$.

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        vector<int> nums;
        stack<int> stk;
        ListNode* temp = head;
        
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            while(!stk.empty() && stk.top() <= nums[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans.push_back(0);
            } else {
                ans.push_back(stk.top());
            }
            stk.push(nums[i]);
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```

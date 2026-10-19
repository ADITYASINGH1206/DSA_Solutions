# [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)
**Difficulty:** `Hard` | **Tags:** `linked-list`, `recursion`

---

## Problem Description
Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return *the modified list*.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

**Example 1:**

```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

**Example 2:**

```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```

**Constraints:**

* The number of nodes in the list is `n`.
* `1 <= k <= n <= 5000`
* `0 <= Node.val <= 1000`

**Follow-up:** Can you solve the problem in `O(1)` extra memory space?

---

## Solution & Editorial
# Intuition
The problem requires us to reverse nodes in a singly-linked list in chunks of size `k`. If the remaining nodes at the end form a group of size strictly less than `k`, they must remain untouched. We can achieve this iteratively in $$O(1)$$ auxiliary space by carefully tracking the boundary pointers of each group: the start of the current group (`temp`), the `k`-th node marking the end of the group (`kthNode`), the node following the group (`nextNode`), and the tail of the previously processed group (`prevLast`).

# Approach
1. **Helper Functions**: 
   - `reverseLL(ListNode* head)`: Reverses a standard linked list segment and returns the new head (which was the former tail).
   - `getKthNode(ListNode* temp, int k)`: Advances `k - 1` times from `temp` to locate the `k`-th node. If fewer than `k` nodes remain, returns `nullptr`.
2. **Main Iteration (`reverseKGroup`)**:
   - Maintain `temp` pointing to the start of the current unreversed segment and `prevLast` pointing to the tail of the last successfully reversed segment.
   - For each group, use `getKthNode(temp, k)` to find `kthNode`.
   - If `kthNode == nullptr`, it means fewer than `k` nodes are left. Attach `prevLast->next = temp` to link the remaining unprocessed tail and terminate the loop.
   - If `kthNode` is found, isolate the group by storing `nextNode = kthNode->next` and setting `kthNode->next = nullptr`.
   - Reverse the isolated segment starting at `temp` using `reverseLL(temp)`.
   - Update the global `head` if this is the first group (`temp == head`), otherwise link `prevLast->next = kthNode`.
   - Update `prevLast = temp` (since `temp` is now the tail of the newly reversed group) and advance `temp = nextNode` for the next iteration.

### Visual Dry Run (Example 1: head = [1, 2, 3, 4, 5], k = 2)
- **Initial State**: `head = 1`, `temp = 1`, `prevLast = nullptr`
- **Iteration 1**:
  - `kthNode = getKthNode(1, 2)` -> node with value `2`.
  - `nextNode = 3`, disconnect segment by setting `2->next = nullptr`.
  - Reverse segment `[1, 2]` -> returns new head `2`, tail is `1`.
  - Since `temp == head`, `head` becomes `2`.
  - `prevLast = 1`, `temp = 3`.
  - List structure so far: `2 -> 1 -> 3 -> 4 -> 5` (group 1 reversed).
- **Iteration 2**:
  - `kthNode = getKthNode(3, 2)` -> node with value `4`.
  - `nextNode = 5`, disconnect segment by setting `4->next = nullptr`.
  - Reverse segment `[3, 4]` -> returns new head `4`, tail is `3`.
  - Link `prevLast->next` (`1->next`) to `4`.
  - `prevLast = 3`, `temp = 5`.
  - List structure: `2 -> 1 -> 4 -> 3 -> 5`.
- **Iteration 3**:
  - `kthNode = getKthNode(5, 2)` -> `nullptr` (fewer than `k` nodes remain).
  - Link `prevLast->next` (`3->next`) to `5` and break.
- **Final Output**: `2 -> 1 -> 4 -> 3 -> 5`.

# Complexity
- Time complexity: $$O(N)$$ — Each node is traversed a constant number of times (once to find the `k`-th node, and once during local reversal).
- Space complexity: $$O(1)$$ — Only a few pointer variables are used, operating in-place without recursion stack overhead.

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
    ListNode* reverseLL(ListNode* head) {
        if(head == NULL) return head;
        ListNode* temp = head;
        ListNode* front = head->next;
        ListNode* prev = NULL;
        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* temp,int k){
        k-=1;
        while(temp != NULL && k >0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp != NULL){
            ListNode* kthNode = getKthNode(temp,k);
            if(kthNode == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp == head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }
            prevLast =temp;
            temp = nextNode;
        }
        return head;

    }
};
```

# [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)
**Difficulty:** `Easy` | **Tags:** `hash-table`, `linked-list`, `two-pointers`

---

## Problem Description
Given the heads of two singly linked-lists `headA` and `headB`, return *the node at which the two lists intersect*. If the two linked lists have no intersection at all, return `null`.

For example, the following two linked lists begin to intersect at node `c1`:

The test cases are generated such that there are no cycles anywhere in the entire linked structure.

**Note** that the linked lists must **retain their original structure** after the function returns.

**Custom Judge:**

The inputs to the **judge** are given as follows (your program is **not** given these inputs):

* `intersectVal` - The value of the node where the intersection occurs. This is `0` if there is no intersected node.
* `listA` - The first linked list.
* `listB` - The second linked list.
* `skipA` - The number of nodes to skip ahead in `listA` (starting from the head) to get to the intersected node.
* `skipB` - The number of nodes to skip ahead in `listB` (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, `headA` and `headB` to your program. If you correctly return the intersected node, then your solution will be **accepted**.

**Example 1:**

```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.
```

**Example 2:**

```
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
```

**Example 3:**

```
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
```

**Constraints:**

* The number of nodes of `listA` is in the `m`.
* The number of nodes of `listB` is in the `n`.
* `1 <= m, n <= 3 * 104`
* `1 <= Node.val <= 105`
* `0 <= skipA <= m`
* `0 <= skipB <= n`
* `intersectVal` is `0` if `listA` and `listB` do not intersect.
* `intersectVal == listA[skipA] == listB[skipB]` if `listA` and `listB` intersect.

**Follow up:** Could you write a solution that runs in `O(m + n)` time and use only `O(1)` memory?

---

## Solution & Editorial
# Intuition
The problem asks us to find the intersection node of two singly linked lists in $$O(m + n)$$ time and $$O(1)$$ auxiliary space. The key observation is that if we traverse both lists using two pointers, switching to the head of the opposite list upon reaching the end, both pointers will travel a total distance equal to the length of list A plus the length of list B ($$m + n$$). Consequently, they will align either at the exact intersection node or at `nullptr` (if no intersection exists) at the same time.

# Approach
1. Check if either `headA` or `headB` is `nullptr`. If so, return `nullptr` immediately as no intersection can exist.
2. Initialize two pointer variables, `temp1` pointing to `headA` and `temp2` pointing to `headB`.
3. Run a `while` loop that continues as long as `temp1` is not equal to `temp2`.
4. Inside the loop, advance both `temp1` and `temp2` to their respective next nodes.
5. If `temp1` reaches the end of list A (`nullptr`), redirect it to `headB`. Similarly, if `temp2` reaches the end of list B (`nullptr`), redirect it to `headA`.
6. If at any point `temp1` equals `temp2`, the loop terminates and the intersection node (or `nullptr`) is returned.

### Visual Trace (Example 1)
List A: `[4, 1, 8, 4, 5]`, List B: `[5, 6, 1, 8, 4, 5]`, Intersection at node `8`.

| Step | `temp1` | `temp2` | Action |
| :--- | :--- | :--- | :--- |
| Start | `4` | `5` | `temp1 != temp2`, advance both |
| 1 | `1` | `6` | `temp1 != temp2`, advance both |
| 2 | `8` (A) | `1` | `temp1 != temp2`, advance both |
| 3 | `4` (A) | `8` (B) | `temp1 != temp2`, advance both |
| 4 | `5` (A) | `4` (B) | `temp1 != temp2`, advance both |
| 5 | `nullptr` | `5` (B) | `temp1` becomes `headB` (`5`), `temp2` advances |
| 6 | `5` (B) | `nullptr` | `temp1` advances, `temp2` becomes `headA` (`4`) |
| 7 | `6` | `1` | Advance both |
| 8 | `1` | `8` (A) | Advance both |
| 9 | `8` (B) | `4` (A) | Advance both |
| 10 | `8` (shared) | `8` (shared) | `temp1 == temp2`, loop exits, return `8`. |

# Complexity
- Time complexity: $$O(m + n)$$ — In the worst-case scenario, each pointer traverses its own list first and then the other list, visiting at most $$m + n$$ nodes before meeting.
- Space complexity: $$O(1)$$ — Only two pointer variables (`temp1` and `temp2`) are used, requiring constant extra memory regardless of input size.

# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == temp2) return temp1;
            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;
        }
        return temp1;
    }
};
```

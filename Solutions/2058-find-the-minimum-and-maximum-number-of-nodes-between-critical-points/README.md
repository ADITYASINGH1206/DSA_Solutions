# [2058. Find the Minimum and Maximum Number of Nodes Between Critical Points](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)
**Difficulty:** `Medium` | **Tags:** `linked-list`

---

## Problem Description
A **critical point** in a linked list is defined as **either** a **local maxima** or a **local minima**.

A node is a **local maxima** if the current node has a value **strictly greater** than the previous node and the next node.

A node is a **local minima** if the current node has a value **strictly smaller** than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists **both** a previous node and a next node.

Given a linked list `head`, return *an array of length 2 containing* `[minDistance, maxDistance]` *where* `minDistance` *is the **minimum distance** between **any two distinct** critical points and* `maxDistance` *is the **maximum distance** between **any two distinct** critical points. If there are **fewer** than two critical points, return* `[-1, -1]`.

**Example 1:**

```
Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
```

**Example 2:**

```
Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
```

**Example 3:**

```
Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
```

**Constraints:**

* The number of nodes in the list is in the range `[2, 105]`.
* `1 <= Node.val <= 105`

---

## Solution & Editorial
# Intuition
A critical point is defined by the relationship between a node and its immediate neighbors. By converting the linked list into a linear array, we can easily identify local extrema by checking if a node is strictly greater or smaller than both its predecessor and successor. Once all critical point indices are collected, the maximum distance is simply the difference between the last and first index, while the minimum distance is found by checking adjacent critical points.

# Approach
1. Traverse the linked list and store all node values in a `vector<int> nums` to allow O(1) random access.
2. Iterate from index `1` to `n-2`. For each index `i`, check if `nums[i]` is a local maximum (`nums[i] > nums[i-1] && nums[i] > nums[i+1]`) or a local minimum (`nums[i] < nums[i-1] && nums[i] < nums[i+1]`).
3. Store the indices of these critical points in a `vector<int> criticalPoints`.
4. If fewer than two critical points exist, return `[-1, -1]`.
5. Calculate `maxDistance` as `criticalPoints.back() - criticalPoints.front()`.
6. Calculate `minDistance` by iterating through `criticalPoints` and finding the minimum difference between adjacent elements.

### Visual Trace (Example 2: [5,3,1,2,5,1,2])
| Index | Value | Status | Critical Points List |
| :--- | :--- | :--- | :--- |
| 0 | 5 | - | [] |
| 1 | 3 | - | [] |
| 2 | 1 | Min | [2] |
| 3 | 2 | - | [2] |
| 4 | 5 | Max | [2, 4] |
| 5 | 1 | Min | [2, 4, 5] |
| 6 | 2 | - | [2, 4, 5] |

- `minDistance`: min(4-2, 5-4) = 1
- `maxDistance`: 5-2 = 3

# Complexity
- Time complexity: $$O(N)$$, where $$N$$ is the number of nodes in the linked list. We perform one pass to store values and one pass to identify critical points.
- Space complexity: $$O(N)$$ to store the node values and the indices of the critical points.

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1,-1};
        vector<int> criticalPoints;
        ListNode* temp = head;
        vector<int> nums;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int n = nums.size();
        if(n<4) return ans;
        for(int i = 1;i<n-1;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1]) criticalPoints.push_back(i);
            else if(nums[i]<nums[i-1] && nums[i]<nums[i+1])criticalPoints.push_back(i);
        }

        int cp = criticalPoints.size();
        if(cp<2) return ans;
        
        int mini = INT_MAX;
        for(int i = 1;i<cp;i++){
            int dif = criticalPoints[i] - criticalPoints[i-1];
            mini = min(dif,mini);
        }
        ans = {mini,criticalPoints[cp-1]-criticalPoints[0]};
        return ans;
    }
};
```

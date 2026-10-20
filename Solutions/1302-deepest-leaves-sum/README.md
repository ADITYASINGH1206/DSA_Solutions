# [1302. Deepest Leaves Sum](https://leetcode.com/problems/deepest-leaves-sum/)
**Difficulty:** `Medium` | **Tags:** `tree`, `depth-first-search`, `breadth-first-search`, `binary-tree`

---

## Problem Description
Given the `root` of a binary tree, return *the sum of values of its deepest leaves*.

**Example 1:**

```
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
```

**Example 2:**

```
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 104]`.
* `1 <= Node.val <= 100`

---

## Solution & Editorial
# Intuition
To find the sum of the deepest leaves in a binary tree, we need to process the tree level by level. By performing a level-order traversal using a queue, we can compute the sum of node values at each level. When the traversal completes, the sum stored will naturally be the sum of the very last level, which represents the deepest leaves.

# Approach
1. Check if the `root` is `NULL`. If it is, return `0` immediately.
2. Initialize a queue `q` of `TreeNode*` and push the `root` into it. Also initialize an integer `sum = 0` to track the sum of nodes at the current level.
3. While the queue `q` is not empty, record the current level size `n = q.size()`, and reset `sum = 0` for this new level.
4. Iterate `n` times to process all nodes at the current level:
   - Pop the front node `curr` from the queue.
   - Add `curr->val` to `sum`.
   - Push `curr->left` and `curr->right` into the queue if they are not `NULL`.
5. After the queue is fully exhausted, `sum` will hold the sum of the nodes from the final (deepest) level. Return `sum`.

### Visual Dry Run (Example 1)
Tree: `[1, 2, 3, 4, 5, null, 6, 7, null, null, null, null, 8]`

- **Level 1**: Queue has `[1]`. `n = 1`. `sum` becomes `1`. Children `2`, `3` pushed.
- **Level 2**: Queue has `[2, 3]`. `n = 2`. `sum` becomes `2 + 3 = 5`. Children `4`, `5`, `6` pushed.
- **Level 3**: Queue has `[4, 5, 6]`. `n = 3`. `sum` becomes `4 + 5 + 6 = 15`. Children `7`, `8` pushed.
- **Level 4**: Queue has `[7, 8]`. `n = 2`. `sum` becomes `7 + 8 = 15`. No children.

Final returned `sum`: `15`.

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the total number of nodes in the binary tree. Every node is pushed and popped from the queue exactly once.
- Space complexity: $$O(W)$$ where $$W$$ is the maximum width of the binary tree. In the worst-case scenario (a complete binary tree), the bottom level holds roughly $$N/2$$ nodes, requiring $$O(N)$$ auxiliary space for the queue.

# Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     int deepestLeavesSum(TreeNode* root) {
//         int maxH = 0;
//         int ans = 0;
//         maxH = height(root);
//         traverse(root,maxH,ans,1);
//         return ans;
        
//     }

//     int height(TreeNode* root){
//         if(root == NULL) return 0;

//         int lh = height(root->left);
//         int rh = height(root->right);

//         return 1 + max(lh,rh);
//     }

//     void traverse(TreeNode* root,int maxH,int& ans,int depth){
//         if(root == NULL) return;

//         traverse(root->left,maxH,ans,depth+1);
//         traverse(root->right,maxH,ans,depth+1);

//         if(depth == maxH){
//             ans += root->val;
//         }
//     }
// };

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(q.empty()==false){
            int n=q.size();
            sum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
        }
        return sum;
    }
};
```

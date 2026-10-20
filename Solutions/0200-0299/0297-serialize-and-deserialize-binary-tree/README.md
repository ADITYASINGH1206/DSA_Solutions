# [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
**Difficulty:** `Hard` | **Tags:** `string`, `tree`, `depth-first-search`, `breadth-first-search`, `design`, `binary-tree`

---

## Problem Description
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://support.leetcode.com/hc/en-us/articles/32442719377939-How-to-create-test-cases-on-LeetCode#h_01J5EGREAW3NAEJ14XC07GRW1A). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Example 1:**

```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 104]`.
* `-1000 <= Node.val <= 1000`

---

## Solution & Editorial
# Intuition
The problem requires converting a binary tree into a string representation and then reconstructing the exact tree from that string. A level-order traversal (Breadth-First Search) using a queue naturally captures nodes level by level. By representing null children with a special delimiter (such as `#`), we can completely preserve the tree topology during both serialization and deserialization.

# Approach
1. **Serialization (`serialize`)**: 
   - Handle the base case where `root` is null by returning an empty string.
   - Initialize a queue `q` and push the `root` into it.
   - While the queue is not empty, pop the front node `temp`. If `temp` is null, append `"#,"` to the serialization string `s`. Otherwise, append the stringified node value followed by a comma `','`.
   - If `temp` is not null, push both its `left` and `right` children into the queue (even if they are null, which ensures every child slot is accounted for).
   - Return the resulting string `s`.

2. **Deserialization (`deserialize`)**: 
   - If `data` is empty, return `NULL`.
   - Use a `stringstream` to parse the comma-separated tokens from the string. Extract the first token to construct the root node and push it into a queue `q`.
   - While `q` is not empty, pop the front node. Read the next two tokens from the stringstream corresponding to the left and right children.
   - If the token is `"#"`, set the corresponding child to `NULL`. Otherwise, create a new `TreeNode`, attach it to the parent node, and push the new child into the queue `q`.
   - Return the reconstructed `root` node.

### Visual Walkthrough (Example 1)
Tree: `[1, 2, 3, null, null, 4, 5]`

- **Serialization Queue Trace:**
  - Start: `q = [1]`, `s = ""`
  - Pop `1`: `s = "1,"`, Push `2, 3` into `q`
  - Pop `2`: `s = "1,2,"`, Push `null, null` into `q`
  - Pop `3`: `s = "1,2,3,"`, Push `4, 5` into `q`
  - Pop `null`: `s = "1,2,3,#,"`, no children pushed
  - Pop `null`: `s = "1,2,3,#,#,"`, no children pushed
  - Pop `4`: `s = "1,2,3,#,#,4,"`, Push `null, null`
  - Pop `5`: `s = "1,2,3,#,#,4,5,"`, Push `null, null`
  - Final String: `"1,2,3,#,#,4,5,#,#,#,#,"`

# Complexity
- Time complexity: $$O(N)$$ where $$N$$ is the number of nodes in the binary tree. Every node is visited, queued, and dequeued exactly once during both serialization and deserialization.
- Space complexity: $$O(N)$$ to store the resulting string, the stringstream, and the BFS queue, which at most holds roughly half the total nodes (the maximum width of a complete binary tree).

# Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s= "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp ==NULL) s.append("#,");
            else s.append(to_string(temp->val)+',');
            if(temp != NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
    
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;


    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```

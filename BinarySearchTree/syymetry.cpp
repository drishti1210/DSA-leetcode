//######################  Symmetric Tree #########################################
//--------------------------------------------------------------------------------
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:


// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:


// Input: root = [1,2,2,null,3,null,3]
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100





class Solution {
public:
    bool solve(TreeNode* p, TreeNode*q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val!=q->val)return false;
        return solve(p->left,q->right) && solve(p->right, q->left);
        }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
       return solve(root->left, root->right);
    }
};
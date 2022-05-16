class Solution {
public:
   bool solve(TreeNode* root,long long int l,long long int r){
        if(!root)return 1;
        if(root->val<=l || root->val>=r)return 0;
        
        return solve(root->left,l,root->val) && solve(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};
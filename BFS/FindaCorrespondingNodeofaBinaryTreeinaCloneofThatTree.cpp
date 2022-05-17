class Solution {
public:
    TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if(cloned==NULL){
        return cloned;
        
    }
        if (target->val == cloned->val){
            ans= cloned;
        }
         getTargetCopy(original , cloned->left, target);
        
         getTargetCopy(original, cloned->right, target);
        
        return ans;
    }
};
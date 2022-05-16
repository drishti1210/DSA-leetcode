class Solution {
public:
    TreeNode* makeBinaryTree(vector<int>& nums, int start,int end){
        if(start>end){
            return NULL;
        }
        
        int  mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        
       root->left =  makeBinaryTree(nums,start, mid-1);
        root->right = makeBinaryTree(nums, mid+1, end);
        
        return root;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       int n= nums.size();
      return makeBinaryTree(nums, 0, n-1);
    }
};



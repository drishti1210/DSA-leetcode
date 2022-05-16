
class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {
   
        if(root==NULL){
            return NULL;
        }
 
        if(root->val > key){
        
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            
            root->right = deleteNode(root->right,key);
        }
        else{
          
            if(!root->left && !root->right){
                return NULL;
            }
         
            else if(!root->left || !root->right){
                if(!root->left){
                    return root->right;
                }
                else{
                    return root->left;
                }
            }
            
            else{
               
                TreeNode* temp = root->left;
             
                while(temp->right){
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left,temp->val);
            }
        }
        return root;
    }
};

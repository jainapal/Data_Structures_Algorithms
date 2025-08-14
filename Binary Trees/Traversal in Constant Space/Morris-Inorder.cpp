vector<int> getInorder(TreeNode* root) {
    	vector<int> ans;
        while(root){
            //left part does not exist
            if(!root->left){
                ans.push_back(root->data);
                root = root -> right;
            }
            //left part exist
            else{
                TreeNode* curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr -> right;
                }
                //left part traversed
                if(curr->right != NULL){
                    curr->right = NULL;
                    ans.push_back(root->data);
                    root = root -> right;
                }
                else{ //left part not traversed
                    curr->right = root;
                    root = root -> left;
                }
            }
        }
        return ans;
    }
    TC = O(4N), SC = O(1)
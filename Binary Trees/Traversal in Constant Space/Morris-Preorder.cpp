vector<int> preorder(TreeNode* root){
	       vector<int> ans;
           while(root){
            //if left doesnot exist
            if(!root->left){
                ans.push_back(root->data);
                root = root->right;
            }
            //left part exist
            else{
                TreeNode* curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }
                //left part traversed
                if(curr->right == root){
                    curr->right = NULL;
                    root = root -> right;
                }
                else{ //left not traversed
                    ans.push_back(root->data);
                    curr->right = root;
                    root = root -> left;
                }
            }
        
           }
           return ans;
		}
        TC = O(4N), SC =O(1)
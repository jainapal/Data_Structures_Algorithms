//need to return subtree with root = val

//Recursive version 
TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->data == val) return root;
        if(root->data > val){
            return searchBST(root->left, val);
        }
        else return searchBST(root->right, val);
        
    }
    TC = O(n), SC = O(N)
    
//Uterative version
TreeNode* searchBST(TreeNode* root, int val) {
    	while(root != nullptr && root->data != val){
            root = (root->data > val) ? root->left : root->right;
        }
        return root;
    }
    TC = O(n), sc = o(1)
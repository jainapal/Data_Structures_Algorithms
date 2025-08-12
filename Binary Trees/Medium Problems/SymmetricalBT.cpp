bool symmetric(TreeNode* left , TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->data != right->data) return false;

        return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return symmetric(root->left, root->right);
    }
    TC = O(N), SC = O(H)
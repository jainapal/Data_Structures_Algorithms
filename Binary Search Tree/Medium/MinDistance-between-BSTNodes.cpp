void inorder(TreeNode* root, int &prev, int &ans){
        if(!root) return;
        //left side
        inorder(root->left, prev, ans);
        if(prev != INT_MIN) ans = min(ans, root->val - prev);
        //update before going to right
        prev = root->val;
        inorder(root->right, prev, ans);
    }
    int minDiffInBST(TreeNode* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;
        inorder(root, prev, ans);
        
        return ans;
    }
    TC = O(N), SC = O(N)
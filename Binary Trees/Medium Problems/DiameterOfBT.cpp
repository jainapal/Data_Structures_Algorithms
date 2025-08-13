int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        height(root, ans);
        return ans;
    }
    int height(TreeNode* node, int& diameter){
        if(node == nullptr) return 0;
        int left = height(node -> left, diameter);
        int right = height(node -> right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left , right);
    }
    TC = O(N), SC = O(H)
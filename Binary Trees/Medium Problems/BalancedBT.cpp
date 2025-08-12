int height(TreeNode *root, bool &valid) {
        if (!root) return 0;
        int left = height(root->left, valid);
        if (valid) {
            int right = height(root->right, valid);
            if (abs(left - right) > 1) valid = false;
            return 1 + max(left, right);
        }
        return -1;
    }
    bool isBalanced(TreeNode *root) {
        bool valid = true;
        height(root, valid);
        return valid;
    }
    TC = O(N), SC = O(N)
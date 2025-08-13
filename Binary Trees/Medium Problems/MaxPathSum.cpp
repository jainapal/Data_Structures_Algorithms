int solve(TreeNode* root, int &sum){
        if(root == NULL) return 0;
        int l = solve(root->left, sum);
        int r = solve(root->right, sum);
        int neche_milgya_ans = l + r + root->data;
        int koi_ek_accha = max(l,r) + root->data;
        int only_root_accha = root->data;
        sum = max({sum, neche_milgya_ans, koi_ek_accha, only_root_accha});

        return max(koi_ek_accha, only_root_accha);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        solve(root, maxsum);
        return maxsum;
    }
    TC = O(N), SC = O(H)
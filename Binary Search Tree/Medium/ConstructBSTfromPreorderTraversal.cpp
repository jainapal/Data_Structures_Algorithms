TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MIN ,INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int& i ,int lower, int upper){
      if(i >= preorder.size() || preorder[i] < lower || preorder[i] > upper) return NULL;

      TreeNode* root = new TreeNode(preorder[i++]);
      root->left = build(preorder, i, lower, root->data);
      root->right = build(preorder, i, root->data, upper);
      return root;
    }
    TC = O(N), SC = O(N)
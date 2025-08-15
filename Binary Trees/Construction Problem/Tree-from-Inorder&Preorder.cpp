int find(vector<int>& in, int start, int end, int element){
        for(int i = start; i <= end; i++){
            if(in[i] == element) return i;
        }
        return -1;
}
TreeNode* Tree(vector<int>& pre, vector<int>& in, int instart, int inend, int ind){
        if(instart > inend) return NULL;

        TreeNode* root = new TreeNode(pre[ind]);
        int pos = find(in, instart, inend, pre[ind]);

        root->left = Tree(pre, in, instart, pos - 1, ind + 1);
        root->right = Tree(pre, in, pos + 1, inend, ind+(pos-instart)+1);

        return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Tree(preorder, inorder, 0, inorder.size()-1, 0);
}

TC = O(N^2), SC = O(N);
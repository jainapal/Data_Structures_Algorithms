int find(vector<int>&in, int start, int end, int element){
        for(int i = start; i <= end; i++){
            if(in[i] == element) return i;
        }
        return -1;
    }
    TreeNode* Tree(vector<int>& in, vector<int>& post, int instart, int inend, int ind){
        if(instart > inend) return NULL;

        TreeNode* root = new TreeNode(post[ind]);
        int pos = find(in, instart, inend, post[ind]);
        root->right = Tree(in, post, pos + 1, inend, ind-1);
        root->left = Tree(in, post, instart, pos-1, ind-(inend-pos)-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return Tree(inorder, postorder, 0, n-1, n - 1);
    }
    TC = O(N^2), SC = O(N)
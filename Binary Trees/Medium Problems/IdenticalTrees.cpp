bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        if(p -> data != q -> data) return false;

        return isSameTree(p -> left, q -> left) && isSameTree(p -> right , q -> right);
    }
    TC = O(N), SC = O(H)
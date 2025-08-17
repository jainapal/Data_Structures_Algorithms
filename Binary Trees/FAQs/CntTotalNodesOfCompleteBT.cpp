void inorder(TreeNode* root, int& cnt){
        if(!root) return;
        cnt++; //for current node
        inorder(root->left, cnt);
        inorder(root->right, cnt);
    }
    int countNodes(TreeNode* root) { 
        if(!root) return 0;
        int cnt = 0;
        inorder(root, cnt);
        return cnt;
    }
    TC = O(N), SC = O(N)

------------------------------------------------------------------------------
int getLeftNodes(TreeNode* root){
        TreeNode* temp = root;
        int cnt = 0;
        while(temp){
            temp = temp -> left;
            cnt++;
        }
        return cnt;
    }
    int getRightNodes(TreeNode* root){
        TreeNode* temp = root;
        int cnt = 0;
        while(temp){
            temp = temp -> right;
            cnt++;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) { 
        // In perfect BT , total nodes = 2 ki power height - 1
        if(!root) return 0;
        int lh = getLeftNodes(root);
        int rh = getRightNodes(root);
        if(lh == rh) return pow(2, lh) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    Time Complexity: O(log N * log N) Calculating leftHeight and rightHeight each takes O(log N) time. 
    In the worst-case scenario, the recursive calls occur at most log N times, 
    leading to a total time complexity of O(log N * log N).

     Space Complexity:O(log N) The maximum depth of the recursion stack is equal to the 
     tree's height,which is log N for a complete binary tree.
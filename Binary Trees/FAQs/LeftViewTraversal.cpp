vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.front()->data);
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
    TC = O(N), SC = O(N)
--------------------------------------------------------------------
//RECURSION
void LView(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;
        if(level == ans.size()) ans.push_back(root->data);
        LView(root->left, level+1, ans);
        LView(root->right, level+1, ans);
    }
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        LView(root, 0, ans);
        return ans;
    }
    TC = O(N), SC =O(N)

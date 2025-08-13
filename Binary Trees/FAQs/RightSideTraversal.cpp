vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.front()->data);
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return ans;
    }
    TC = O(N), SC = O(N)
--------------------------------------------------------------------------
void Rview(TreeNode* root, int level, vector<int>& ans){
        if(!root) return ;
        if(ans.size() == level) ans.push_back(root->data);
        Rview(root->right, level + 1, ans);
        Rview(root->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        Rview(root, 0, ans);
        return ans;
    }
    TC = O(N), SC = O(N)
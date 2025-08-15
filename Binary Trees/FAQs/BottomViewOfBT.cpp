void find(TreeNode* root, int& l, int&r, int pos){
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, l, r, pos - 1);
        find(root->right, l, r, pos + 1);
    }
    vector <int> bottomView(TreeNode *root){
    	int l = 0, r = 0;
        find(root, l, r, 0);
        vector<int> ans(r -l + 1);
        vector<bool> vis(r - l + 1, 0);
        queue<TreeNode*> q;
        queue<int> ind;
        q.push(root);
        ind.push(-1*l);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            int pos = ind.front();
            ind.pop();

            ans[pos] = node->data;
            if(node->left){
                q.push(node->left);
                ind.push(pos - 1);
            }
            if(node->right){
                q.push(node->right);
                ind.push(pos + 1);
            }
        }
        return ans;
    }
-----------------------------------------------------------------------------
    //RECURSIVE 
    void find(TreeNode* root, int& l, int&r, int pos){
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, l, r, pos - 1);
        find(root->right, l, r, pos + 1);
    }
    void Bview(TreeNode* root, int pos,vector<int>& ans, vector<int>& level, int lev){
        if(!root) return;
        if(level[pos] <= lev){
            level[pos] = lev;
            ans[pos] = root->data;
        }
        Bview(root->left, pos - 1, ans, level, lev + 1);
        Bview(root->right, pos +1, ans, level, lev+1);
    }
    vector <int> bottomView(TreeNode *root){
    	int l = 0, r = 0;
        find(root, l , r, 0);
        vector<int> ans(r - l + 1);
        vector<int> level(r - l + 1, INT_MIN);
        Bview(root, -1*l, ans, level, 0);
        return ans;
    }
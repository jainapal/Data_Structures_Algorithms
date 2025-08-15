void find(TreeNode* root, int& l, int& r, int pos){
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, l, r, pos - 1);
        find(root->right, l, r, pos + 1);
    }
    vector<int> topView(TreeNode *root){
        int l = 0, r = 0;
        find(root, l, r, 0);
        vector<int> ans(r - l + 1);
        vector<bool> vis(r - l + 1, 0);
        queue<TreeNode*> q;
        queue<int> ind;
        q.push(root);
        ind.push(-1*l);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int pos = ind.front();
            ind.pop();

            if(!vis[pos]){
                vis[pos] = 1;
                ans[pos] = temp->data;
            }
            if(temp->left){
                q.push(temp->left);
                ind.push(pos - 1);
            }
            if(temp->right){
                q.push(temp->right);
                ind.push(pos + 1);
            }
        }
        return ans;
    }
-----------------------------------------------------------------------------------
    //RECURSIVE APPROACH
    void find(TreeNode* root, int& l, int& r, int pos){
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, l, r, pos - 1);
        find(root->right, l, r, pos + 1);
    }
    void Tview(TreeNode* root, int pos, vector<int>& ans, vector<int>& level,int lev){
        if(!root) return;

        if(level[pos] > lev){
            level[pos] = lev;
            ans[pos] = root->data;
        }
        Tview(root->left, pos-1, ans, level, lev+1);
        Tview(root->right, pos+1, ans, level, lev+1);
    }
    vector<int> topView(TreeNode *root){
        int l = 0, r = 0;
        find(root, l, r, 0);
        vector<int> ans(r - l + 1);
        vector<int> level(r - l + 1, INT_MAX);
        Tview(root, -1*l, ans, level, 0);
        
        return ans;
    }

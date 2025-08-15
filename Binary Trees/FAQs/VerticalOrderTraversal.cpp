void find(TreeNode* root, int& l, int& r, int pos){
        if(!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, l, r, pos -1);
        find(root->right, l, r, pos + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    	int l = 0, r = 0;
        find(root, l , r, 0);
        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);
        queue<TreeNode*> q;
        queue<int> ind;
        q.push(root);
        ind.push(0);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int pos = ind.front();
            ind.pop();
            if(pos >= 0){
                positive[pos].push_back(temp->data);
            }
            else negative[abs(pos)].push_back(temp->data);

            if(temp->left){
                q.push(temp->left);
                ind.push(pos -1);
            }
            if(temp->right){
                q.push(temp->right);
                ind.push(pos + 1);
            }
        }
        vector<vector<int>> ans;
        for(int i = negative.size() - 1; i > 0; i--){
            ans.push_back(negative[i]);
        }
        for(int i = 0; i < positive.size(); i++){
            ans.push_back(positive[i]);
        }

        return ans;
    }

    TC = O(N) + O(N) as we are traversing n elements in 2d grid and for find func also traversing n elements
    SC = O(N) + O(N) as 2d vector in total storing n elements and ques also storing n elements
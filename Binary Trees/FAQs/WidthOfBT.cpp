typedef unsigned long long ll; //instead of writing long long everywhere, we write it as ll
    long long int widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            ll l = q.front().second;
            ll r = q.back().second;
            ans = max(ans, r - l + 1);

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front().first;
                ll pos = q.front().second;
                q.pop();
                if(temp->left){
                    q.push({temp->left, 2*pos + 1});
                }
                if(temp->right){
                    q.push({temp->right, 2*pos + 2});
                }
            }
        }
        return ans;
    }
    TC = O(N), SC = O(N)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> s1;  // left - right
        stack<TreeNode*> s2;  // right - left
        s1.push(root);

        while (!s1.empty() || !s2.empty()) {
            vector<int> temp;
            if (!s1.empty()) {
                while (!s1.empty()) {
                    TreeNode* node = s1.top();
                    s1.pop();
                    temp.push_back(node->data);
                    if (node->left) s2.push(node->left);
                    if (node->right) s2.push(node->right);
                }
            }
            else{
                if(!s2.empty()){
                    while(!s2.empty()){
                        TreeNode* node = s2.top();
                        s2.pop();
                        temp.push_back(node->data);
                        if(node->right) s1.push(node->right);
                        if(node->left) s1.push(node->left);
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    TC = O(N), SC = O(N)
void leftSub(TreeNode* root, vector<int>& ans){
        if(!root || (!root->left && !root->right)) return;
        ans.push_back(root->data);
        if(root->left) leftSub(root->left, ans);
        else leftSub(root->right, ans);
    }
    void leaf(TreeNode* root, vector<int>& ans){
        if(!root) return;
        //leaf node
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        //left part
        leaf(root->left, ans);
        //right part
        leaf(root->right, ans);
    }
    void rightsub(TreeNode* root, vector<int>& ans){
        //base case
        if(!root || (!root->left && !root->right)) return;

        if(root->right){
            rightsub(root->right, ans);
        }
        else rightsub(root->left, ans);

        ans.push_back(root->data);
    }
    vector <int> boundary(TreeNode* root){
    	vector<int> ans;
        if(!root) return ans;
        //root element
        ans.push_back(root->data);
        //left boundary elements except leaf nodes
        leftSub(root->left, ans);
        //leaf nodes
        if(root->left || root->right){
            leaf(root, ans);
        }
        //right boundary in reverse order except leaf
        rightsub(root->right, ans);

        return ans;
    }
    TC = O(N), SC = O(N)
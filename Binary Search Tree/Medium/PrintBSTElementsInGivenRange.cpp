void func(Node* root, int low, int high, vector<int>& ans){
        if(!root) return;
        if(root->data > high){
            func(root->left, low, high, ans);
        }
        else if(root->data < low){
            func(root->right, low, high, ans);
        }
        else{
            func(root->left, low, high, ans);
            ans.push_back(root->data);
            func(root->right, low, high, ans);
        }
        
    }
    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;
        func(root, low, high, ans);
        return ans;
    }
    TC = O(N), SC = O(N)
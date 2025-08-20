void inorder(Node* root, vector<int> &ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);
        
        vector<int> ans;
        int i = 0, j = 0;
        while(i < v1.size() && j < v2.size()){
            if(v1[i] <= v2[j]){
                ans.push_back(v1[i]);
                i++;
            }
            else{
                ans.push_back(v2[j]);
                j++;
            }
        }
        
        while(i < v1.size()){
            ans.push_back(v1[i]);
            i++;
        }
        while(j < v2.size()){
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
    TC = O(N + M), SC = O(N + M)
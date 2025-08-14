vector<int> postOrder(Node* node) {
        vector<int> ans;
        while(node){
            if(!node->right){
                ans.push_back(node->data);
                node = node->left;
            }
            else{
                Node* curr = node->right;
                while(curr->left && curr->left != node){
                    curr = curr->left;
                }
                if(curr->left == node){
                    curr->left = NULL;
                    node = node->left;
                }
                else{
                    ans.push_back(node->data);
                    curr->left = node;
                    node = node->right;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    TC = O(4N), SC = O(1)
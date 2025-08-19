bool dead(Node* root, int lower, int upper){
        if(!root) return 0;
        //leaf node
        if(!root->left && !root->right){
            if(root->data - lower == 1 && upper - root->data == 1){
                return 1; //dead end
            }
            else return 0;
        }
        //check for root ka left and right
        return dead(root->left, lower, root->data) || dead(root->right, root->data, upper);
        
    }
    bool isDeadEnd(Node *root) {
        return dead(root, 0, INT_MAX);
    }
    TC = O(N), SC = O(N)
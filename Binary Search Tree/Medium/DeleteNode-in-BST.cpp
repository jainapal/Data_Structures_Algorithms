TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->data > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if(root->data < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        else{
            //leaf node 
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            //1 child 
            else if(!root->right){ //left child exist
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left){ //right child exist
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            //2 child
            else{
                //find greatest element from left
                TreeNode* child = root->left;
                TreeNode* parent = root;
                while(child->right){
                    parent = child;
                    child = child->right;
                }
                if(root != parent){
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else{
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
    TC = O(n), SC = O(n)
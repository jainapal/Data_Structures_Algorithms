Do inorder traversal and find nodes need to be swap by traversing array and 
then using that array do traverse tree and replace values with inorder values
TC =O(N), SC = O(N)

//using morris inorder
    void correctBST(Node* root) {
        Node* curr = NULL;
        Node* first = NULL, *second = NULL;
        Node* present = NULL, *last = NULL;
        
        while(root){
            //left does not exist
            if(!root->left){
                last = present;
                present = root;
                //check for required node
                if(last && last->data > present->data){
                    //first required node found
                    if(!first) first = last;
                    //second required node 
                    second = present;
                }
                root = root->right;
            }
            //left exist
            else{
                curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }
                //left not traversed
                if(curr->right == NULL){
                    curr->right = root;
                    root = root->left;
                }
                //left traversed
                else{
                    curr->right = NULL;
                    last = present;
                    present = root;
                    if(last && last->data > present->data){
                        if(!first) first = last;
                        second = present;
                    }
                    root = root->right;
                }
            }
        }
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
        return;
    }
    TC = O(N), SC =O(1)
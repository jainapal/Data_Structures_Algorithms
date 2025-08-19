vector<int> succPredBST(TreeNode* root,int key){
			vector<int> sortedlist;
            inorder(root,sortedlist);

            int predecessor = -1, successor = -1;

            for(int i = 0; i < sortedlist.size(); i++){
                if(sortedlist[i] < key){
                    predecessor = sortedlist[i];
                }
                else if(sortedlist[i] > key){
                    successor = sortedlist[i];
                    break;
                }
            }
            return {predecessor, successor};
		}
        void inorder(TreeNode* root, vector<int>& lst){
            if(!root) return;
            inorder(root->left,lst);
            lst.push_back(root->data);
            inorder(root->right,lst);

        }
        TC = O(N), SC = O(N)
----------------------------------------------------------------------------------

vector<int> succPredBST(TreeNode* root, int key) {
        int pred = -1, succ = -1;
        TreeNode* curr = root;
        //for predecessor
        while(curr){
            if(curr->data < key){
                pred = curr->data;
                curr = curr->right;
            }
            else curr = curr ->left;
        }

        curr = root;
        //for successor
        while(curr){
            if(curr->data > key){
                succ = curr->data;
                curr = curr->left;
            }
            else curr = curr->right;
        }

        return{pred, succ};
    }
    TC = O(N), SC = O(1)
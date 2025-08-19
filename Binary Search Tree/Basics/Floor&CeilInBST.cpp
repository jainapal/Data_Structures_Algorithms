vector<int> floorCeilOfBST(TreeNode* root,int key){
			int floor = -1, ceil = -1;
            TreeNode* temp = root;
            while(temp){
                if(temp->data == key){
                    floor = temp->data;
                    break;
                }
                else if(temp->data < key){
                    floor = temp->data;
                    temp = temp->right;
                }
                else temp = temp->left;
            }

            temp = root;
            while(temp){
                if(temp->data == key){
                    ceil = temp->data;
                    break;
                }
                else if(temp->data > key){
                    ceil = temp->data;
                    temp = temp->left;
                }
                else temp = temp->right;
            }
            return {floor, ceil};
		}
        TC = O(H), SC = O(1)
void inorder(TreeNode* root, vector<int>& ans){
            if(!root) return;
            inorder(root->left, ans);
            ans.push_back(root->data);
            inorder(root->right, ans);
        }
		bool isBST(TreeNode* root){
			vector<int> ans;
            inorder(root, ans);
            for(int i = 1; i < ans.size(); i++){
                if(ans[i] <= ans[i-1]) return false;
            }
            return true;
		}
        TC = O(N), SC = O(N)
-------------------------------------------------------------------
        bool BST(TreeNode* root, int &prev){
            if(!root) return true;
            bool left = BST(root->left, prev);
            if(left == false) return false;

            if(root->data <= prev) return false;
            prev = root->data;
            return BST(root->right, prev);
        }
		bool isBST(TreeNode* root){
			int prev = INT_MIN;
            return BST(root, prev);
		}
        TC =O(N), SC = O(N)
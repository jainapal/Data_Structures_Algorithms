vector<vector<int>> allRootToLeaf(TreeNode* root) {
            vector<vector<int>> ans;
			vector<int> path;
			dfs(root, path, ans);
			return ans;
		}
		void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& ans){
			if(node == NULL) return;
			path.push_back(node->data);

			if(node->left == NULL && node->right == NULL){
				ans.push_back(path);
			}
			else{
				dfs(node->left, path, ans);
				dfs(node->right, path, ans);
			}
			path.pop_back();
		}

        TC = O(N), SC = O(N)
        
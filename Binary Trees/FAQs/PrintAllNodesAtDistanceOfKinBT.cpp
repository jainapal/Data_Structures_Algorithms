class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void inorder(TreeNode* root){
        if(!root) return;

        if(root->left){
            parent[root->left] = root;
            inorder(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            inorder(root->right);
        }
    }
    void bfs(TreeNode* target, int k, vector<int>& ans){
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target->data);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            if(level == k) break;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !visited.count(curr->left->data)){
                    q.push(curr->left);
                    visited.insert(curr->left->data);
                }
                if(curr->right && !visited.count(curr->right->data)){
                    q.push(curr->right);
                    visited.insert(curr->right->data);
                }
                if(parent.count(curr) && !visited.count(parent[curr]->data)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->data);
                }
            }
            level++;
        }
        //for last level
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->data);
        }
    }
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
		vector<int> ans;
        inorder(root);
        bfs(target, k, ans);
        return ans;
    }
};

TC = O(N + N), SC = O(N)
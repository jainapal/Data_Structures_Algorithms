/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
        void func(TreeNode* node, vector<int>& ans){
            if(node == NULL) return;
            func(node->left, ans);
            func(node->right, ans);
            ans.push_back(node->data);
        }
		vector<int> postorder(TreeNode* root){
	        vector<int> ans;
            func(root, ans);
            return ans;
		}
};
TC = O(N), SC = O(N)

//Iterative Solution
class Solution{
	public:
		vector<int> postorder(TreeNode* root){
	        vector<int> ans;
            stack<TreeNode*> st;
            st.push(root);

            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();
                ans.push_back(node->data);
                if(node->left) st.push(node->left);
                if(node->right) st.push(node->right);
            }
            reverse(ans.begin(), ans.end());
            return ans;
		}
};
TC = O(N), SC = O(H)
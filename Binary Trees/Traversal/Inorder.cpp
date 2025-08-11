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
            ans.push_back(node->data);
            func(node->right, ans);
        }
		vector<int> inorder(TreeNode* root){
	        vector<int> ans;
            func(root, ans);
            return ans;
		}
};
TC = O(N), SC = O(N)

//Iterative Solution
class Solution{
	public:
		vector<int> inorder(TreeNode* root){
	        vector<int> ans;
            stack<TreeNode*> st;
            TreeNode* node = root;
            while(true){
                if(node != NULL){
                    st.push(node);
                    node = node->left;
                }
                else{
                    if(st.empty()) break;
                    node = st.top();
                    st.pop();
                    ans.push_back(node->data);
                    node = node->right;
                }
            }
            return ans;
		}
};
TC = O(N), SC = O(H)
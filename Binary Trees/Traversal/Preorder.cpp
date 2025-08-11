
 //Definition for a binary tree node.
 struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 };
 
//Recursive Solution
class Solution{
	public:
        void func(TreeNode* node, vector<int>& ans){
            if(node == NULL) return;
            ans.push_back(node->data);
            func(node->left, ans);
            func(node->right, ans);
        }
		vector<int> preorder(TreeNode* root){
	       vector<int> ans;
           func(root, ans);
           return ans;
		}
};

//Iterative solution
class Solution{
	public:
		vector<int> preorder(TreeNode* root){
	       vector<int> ans;
           if(root == NULL) return ans;
           stack<TreeNode*> st;
           st.push(root);

           while(!st.empty()){
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            //stack is lasst in first out so right first then left
            if(root->right != NULL) st.push(root->right);
            if(root->left != NULL) st.push(root->left);
           }
           
           return ans;
		}
};
TC = O(N), SC = O(N)
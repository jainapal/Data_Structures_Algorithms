class BSTIterator{
	public:
		BSTIterator(TreeNode* root){
			inorder(root);
            //initialise index to -1 before first element;
            index = -1;
		}
		
		bool hasNext(){
			return index + 1 < values.size();
		}
		
		int next(){
            return values[++index];
		}
    private:
        vector<int> values; //store inorder traversal

        int index; //to track current position
         void inorder(TreeNode* root){
            if(!root) return;
            inorder(root->left);
            values.push_back(root->data);
            inorder(root->right);
         }
};
TC = O(1) for next and hasnext but O(N) for inorder, SC = O(N)
------------------------------------------------------------------------------------------------
class BSTIterator{
	public:
		BSTIterator(TreeNode* root){
			pushleft(root);
		}
		
		bool hasNext(){
			return !st.empty();
		}
		
		int next(){
            TreeNode* temp = st.top();
            st.pop();
            if(temp->right) pushleft(temp->right);
            return temp->data;
		}
    private:
        stack<TreeNode*> st; //store values
         void pushleft(TreeNode* node){
            while(node){
                st.push(node);
                node = node -> left;
            }
         }
};
TC = O(1), SC = O(H)
void inorder(TreeNode* root, int &k, int &ans){
     if(!root) return;
     inorder(root->left, k, ans);
     k--;
     if(k == 0) ans = root->val;
     if(k < 0) return;
     inorder(root->right, k , ans);
 }
int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = -1;
    inorder(A, B, ans);
    return ans;
}
TC = O(N), SC = O(N)
-------------------------------------Kth Largest------------------------------------
void inorder(Node* root, int &k, int &ans){
      if(!root) return;
      inorder(root->right, k, ans);
      k--;
      if(k >= 0) ans = root->data;
      if(k <= 0) return;
      inorder(root->left, k, ans);
  }
    int kthLargest(Node *root, int k) {
        int ans = 0;
        inorder(root, k, ans);
        return ans;
        
    }
    TC = O(N), SC = O(N)

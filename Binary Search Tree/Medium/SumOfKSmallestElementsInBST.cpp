void inorder(Node* root, int &k, int &sum){
    if(!root) return;
        inorder(root->left, k, sum);
        if(k > 0) sum += root->data;
        k--;
        if(k <= 0) return;
        inorder(root->right, k, sum);
    
}
int sum(Node* root, int k) {
    int sum = 0;
    inorder(root, k, sum);
    return sum;
    
}
TC = O(N), SC = O(N)
-----------------------------------------------------------------------------------
class Solution {
  public:
    int count(Node* root){
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    bool CBT(Node* root, int ind, int n){
        if(!root) return true;
        if(ind >= n) return false;
        //left side and right side check
        return CBT(root->left, 2*ind + 1, n) && CBT(root->right, 2*ind + 2, n);
    }
    bool MaxHeap(Node* root){
        
        if(root->left){
            if(root->data < root->left->data) return false;
            //root->data is greater then check for left side
            if(!MaxHeap(root->left)) return false;
        }
        if(root->right){
            if(root->data < root->right->data) return false;
            
            return MaxHeap(root->right);
        }
        return true; //leaf node...no left, right exist
    }
    bool isHeap(Node* tree) {
        // count nodes in tree
        int cnt = count(tree);
        //complete binary tree or not
        if(!CBT(tree, 0, cnt)) return false;;
        //parent greater than child or not
        return MaxHeap(tree);
    }
};
TC = O(3N), SC = O(N)
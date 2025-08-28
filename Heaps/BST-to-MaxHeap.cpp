Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the 
condition that all the values in the left subtree of a node should be less than all the 
values in the right subtree of the node. This condition is applied on all the nodes 
in the so converted Max Heap.

class Solution {
  public:
    void inorder(Node* root, vector<int>& ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    void postorder(Node* root, vector<int>& ans, int &index){
        if(!root) return;
        postorder(root->left, ans, index);
        postorder(root->right, ans, index);
        root->data = ans[index];
        index++;
    }
    void convertToMaxHeapUtil(Node* root) {
        vector<int> ans;
        inorder(root, ans);
        
        int index = 0;
        postorder(root, ans, index);
    }
};

TC = O(N), SC =O(N)


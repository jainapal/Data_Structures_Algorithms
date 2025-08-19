#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left, *right;
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
    Node* insert(Node* root, int target){
        if(!root){
            Node* temp = new Node(target);
            return temp;
        }
        if(root->data > target){
            root->left = insert(root->left, target);
        }
        else{
            root->right = insert(root->right, target);
        }
        return root;
    }
    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

int main(){
    int arr[] = {3,7,4,1,6,8};
    Node* root = nullptr;
    for(int i = 0; i < 6; i++){
        root = insert(root, arr[i]);
    }
    inorder(root);
}

//TC = O(N^2), SC = O(N)